//
//  ViewController.swift
//  ProximiioMapbox
//
//  Created by x-oauth-basic on 05/02/2019.
//  Copyright (c) 2019 x-oauth-basic. All rights reserved.
//

import UIKit
import Mapbox
import Proximiio
import ProximiioMapbox
import SnapKit

class ViewController: UIViewController {
    
    private var mapView: MGLMapView?

    private var inputs: [ProximiioInput] {
        if let inputs = Proximiio.sharedInstance()?.inputs() {
            return inputs
        }
        return []
    }
    
    private var floors: [ProximiioFloor] {
        let floor = Proximiio.sharedInstance()?.currentFloor()
        if let floors = Proximiio.sharedInstance()?.floors() {
            let typed = floors
            if floor != nil {
                let filtered = typed.filter { (flr) -> Bool in
                    flr.placeId == floor?.placeId
                }
                return filtered.sorted { (floor, floor2) -> Bool in
                    floor2.level.intValue > floor.level.intValue
                }
            } else {
                return typed.sorted { (floor, floor2) -> Bool in
                    floor2.level.intValue > floor.level.intValue
                }
            }
        }
        return []
    }
    
    private var floor: ProximiioFloor? {
        if let floor = Proximiio.sharedInstance()?.currentFloor() {
            return floor
        }
        return nil
    }
    
    private var currentUserPosition: CLLocationCoordinate2D? {
        didSet {
            /// store here to easy share accross the app
            if let floor = Proximiio.sharedInstance()?.currentFloor()?.level?.intValue {
                UserLocation.shared.floor = floor
            }
            
            /// process only if we are far than previous
            var forceUpdateFeature = false
            if let current = currentUserPosition?.toCLLocation(),
               let last = UserLocation.shared.coordinate?.toCLLocation() {
                forceUpdateFeature = current.distance(from: last) > 1500
            }
            
            if UserLocation.shared.coordinate == nil {
                forceUpdateFeature = true
            }
            
            UserLocation.shared.coordinate = currentUserPosition
            
            guard
                forceUpdateFeature
            else { return }
            
            /// sort the list by title and level
            let list = ProximiioMapbox.shared.database.pois()
                .filter({ feature -> Bool in
                    guard
                        let point = feature.coordinate,
                        let user = self.currentUserPosition
                    else { return false }
                    return user.toCLLocation().distance(from: point.toCLLocation()) < 2000.0 // filter within 2km aks 2000mt
                })
                .sorted { (first, second) -> Bool in
                    first.getTitle() < second.getTitle()
                }
            
            DispatchQueue.main.async {
                UserLocation.shared.nearByPOI = list
            }
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        /// setup map
        setupMap()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        /// force disable idle
        UIApplication.shared.isIdleTimerDisabled = true
        
        /// force follow the path of current route
        ProximiioMapbox.shared.shakyHandsMode = true
        
        /// manage navigator
        ProximiioMapbox.shared.navigation?.ttsEnable(enable: true)
        ProximiioMapbox.shared.navigation?.ttsHeadingCorrection(enabled: true)
        ProximiioMapbox.shared.navigation?.ttsDecisionAlert(enabled: true, metadataKeys: [])
        ProximiioMapbox.shared.navigation?.ttsHazardAlert(enabled: true, metadataKeys: [])
        ProximiioMapbox.shared.navigation?.ttsLandmarkAlert(enabled: true, metadataKeys: [])
        ProximiioMapbox.shared.navigation?.ttsSegmentAlert(
            enterEnabled: true,
            exitEnabled: true,
            metadataKeys: [])
        ProximiioMapbox.shared.navigation?.ttsReassuranceInstruction(enabled: true)
        ProximiioMapbox.shared.navigation?.ttsReassuranceInstruction(distance: 10.0)
        ProximiioMapbox.shared.navigation?.setUnitConversion(conversion: .Default )

    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        /// force re-enable idle
        UIApplication.shared.isIdleTimerDisabled = false
    }
}


// MARK: - Map setup
extension ViewController {
    /// setup map and proximiio integration
    fileprivate func setupMap() {
        /// setup map
        let mapToken = Proximiio.sharedInstance()?.token() ?? ""
        Proximiio.sharedInstance()?.delegate = self
        
        let config = ProximiioMapboxConfiguration(token: mapToken)
        
        /// prepare map
        mapView = MGLMapView(frame: view.frame)
        
        /// set map delegate
        self.mapView?.delegate = self
        
        /// hide logo (if needed)
        self.mapView?.logoViewPosition = .bottomLeft
        self.mapView?.logoViewMargins = CGPoint(x: 20, y: 20)
        self.mapView?.attributionButtonPosition = .bottomRight
        
        // set base zoom
        self.mapView?.setZoomLevel(18, animated: false)
        
        /// setup ProximiioMapbox handler
        if let mapView = mapView {
            ProximiioMapbox.shared.setup(mapView: mapView, configuration: config)
            ProximiioMapbox.shared.initialize { result in
                if result == .success {
                    ProximiioMapbox.shared.mapNavigation = self
                    ProximiioMapbox.shared.mapInteraction = self
                }
            }
        }
        
        /// (optional) you can normally use storyboard and reference to your IBOutlet
        prepareMapUI()
    }
    
    /// (optional) code managment of the UI
    private func prepareMapUI() {
        
        /// add map
        guard let mapView = mapView else { return }
        view.addSubview(mapView)
        
        mapView.snp.makeConstraints({
            $0.top.equalToSuperview()
            $0.left.equalToSuperview()
            $0.right.equalToSuperview()
            $0.bottom.equalToSuperview()
        })
    }
}


// MARK: Mapbox Delegate
extension ViewController: MGLMapViewDelegate {
    func mapViewDidFinishLoadingMap(_ mapView: MGLMapView) {
        mapView.showsHeading = true
        mapView.isPitchEnabled = true
        mapView.allowsRotating = true
        mapView.showsUserLocation = true
        mapView.showsUserHeadingIndicator = true
        mapView.compassView.compassVisibility = .hidden
        
        // manual force center
        self.perform(#selector(ViewController.centerAtUser), with: nil, afterDelay: 0.7)
    }
    
    func mapView(_ mapView: MGLMapView, annotationCanShowCallout annotation: MGLAnnotation) -> Bool {
        return true
    }
}

// MARK: - Proximiio Delegate
extension ViewController: ProximiioDelegate {
    
    func onProximiioReady() {}
    
    func proximiioFloorChanged(_ floor: ProximiioFloor!) {
        /// optional if we want to stay in sync with current user position
        setFloor(floor: floor)
    }
    
    func proximiioPositionUpdated(_ location: ProximiioLocation!) {
        /// optional if we want to stay in sync with current user position
        currentUserPosition = location.coordinate
        //        print(currentUserPosition)
    }
}

// MARK: ProximiioMapbox Navigation Delegate
extension ViewController: ProximiioMapboxNavigation {
    func onHazardExit(_ hazard: ProximiioGeoJSON) {

    }

    func onSegmentExit(_ segment: ProximiioGeoJSON) {

    }

    func onDecisionExit(_ decision: ProximiioGeoJSON) {

    }

    func onLandmarkExit(_ landmarks: [ProximiioGeoJSON]) {

    }

    func onTTS() {

    }

    func onTTSDirection(text: String?) {

    }

    func onDecisionEntered(_ decision: ProximiioGeoJSON) {
    }
    
    func onLandmarkEntered(_ landmarks: [PIOLandmark]) {
    }
    
    func onRoute(route: PIORoute?) {
        // triggered if a route has been found
    }
    
    func routeEvent(eventType type: PIORouteUpdateType, text: String, additionalText: String?, data: PIORouteUpdateData?) {
        // triggered if a route event happen
    }
    
    func onHazardEntered(_ hazard: ProximiioGeoJSON) {
        // triggered if user is close to hazard
        title = "Hazard \(hazard.getTitle())"
    }
    
    func onSegmentEntered(_ segment: ProximiioGeoJSON) {
        // triggered if user has entered a new segment
        title = segment.getTitle()
    }
    
    func onPositionUpdate(_ position: CLLocationCoordinate2D) {
        // useful to have current user position
    }
    
    func onHeadingUpdate(_ heading: Double) {
        // useful to have current user heading
    }
}

// MARK: ProximiioMapbox Interaction Delegate
extension ViewController: ProximiioMapboxInteraction {
    func onFollowingUserUpdate(_ isFollowing: Bool) {

    }

    func change(floor: Int) {
        // triggered when floor has changed
        
        UserLocation.shared.floor = floor
        
        if let currentFloor = self.floors.first(where: { item -> Bool in
            item.level.intValue == floor }) {
            setFloor(floor: currentFloor)
        }
    }
    
    func onTap(feature: ProximiioGeoJSON?) {
        // triggered if user taps on a POI
        guard let feature = feature else { return }

        let configuration = PIORouteConfiguration(
            start: nil,
            destination: feature,
            waypointList: [],
            wayfindingOptions: PIOWayfindingOptions(avoidElevators: false, avoidBarriers: false, avoidEscalators: false, avoidNarrowPaths: false, avoidRamps: false, avoidRevolvingDoors: false, avoidStaircases: false, avoidTicketGates: false, pathFixDistance: 1.0)
        )
        
        /// show route to a poi
        ProximiioMapbox.shared.routeFindAndPreview(configuration: configuration) { route in
        }
    }
    
    func onRequestReRoute() {
        // triggered if a re-route is manually requested
    }
}


// MARK: - Map center to user
extension ViewController {
    @objc private func centerAtUser() {
        /// mapbox is so stupid, that need to set to none to be later set to proper value
        if let coordinate = self.mapView?.userLocation?.coordinate, coordinate.latitude != -180.0 {
            DispatchQueue.main.async {
                self.mapView?.setCenter(coordinate, zoomLevel: 20, animated: true)
            }
            
            // show proper level
            if let floor = UserLocation.shared.floor {
                ProximiioMapbox.shared.setLevel(level: floor)
                
                if let currentFloor = floors.first(where: { item -> Bool in
                    item.level.intValue == floor
                }) {
                    setFloor(floor: currentFloor)
                }
            }
        }
    }
    
    private func setFloor(floor: ProximiioFloor) {
        /// update map UI
        ProximiioMapbox.shared.setLevel(level: floor.level.intValue)
    }
    
    private func didTapCompass() {
        ProximiioMapbox.shared.followingUser = !(ProximiioMapbox.shared.followingUser)
        
        /// force center to user position
        if ProximiioMapbox.shared.followingUser {
            centerAtUser()
        }
    }
}
