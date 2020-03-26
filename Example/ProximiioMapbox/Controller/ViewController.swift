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
    private var mapBoxHelper: ProximiioMapbox?
    
    private var inputs: [ProximiioInput] {
        if let inputs = Proximiio.sharedInstance()?.inputs() {
            return inputs as? [ProximiioInput] ?? []
        }
        return []
    }
    
    private var floors: [ProximiioFloor] {
        let floor = Proximiio.sharedInstance()?.currentFloor()
        if let floors = Proximiio.sharedInstance()?.floors() {
            let typed = floors as? [ProximiioFloor] ?? []
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
            let list = (self.mapBoxHelper?.database.pois ?? [])
                .filter({ feature -> Bool in
                    guard
                        let point = feature.coordinate,
                        let user = self.currentUserPosition
                        else { return false }
                    return user.toCLLocation().distance(from: point.toCLLocation()) < 2000.0 // filter within 2km aks 2000mt
                })
                .sorted { (first, second) -> Bool in
                    first.getTitle() < second.getTitle()
            }                .sorted { (first, second) -> Bool in
                first.level < second.level
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
        self.mapBoxHelper?.shakyHandsMode = true
        
        /// manage navigator
        self.mapBoxHelper?.navigation?.ttsEnable(enable: true)
        self.mapBoxHelper?.navigation?.ttsHeadingCorrection(enabled: true)
        self.mapBoxHelper?.navigation?.ttsDecisionAlert(enabled: true, metadataKeys: [])
        self.mapBoxHelper?.navigation?.ttsHazardAlert(enabled: true, metadataKeys: [])
        self.mapBoxHelper?.navigation?.ttsLandmarkAlert(enabled: true, metadataKeys: [])
        self.mapBoxHelper?.navigation?.ttsSegmentAlert(
            enterEnabled: true,
            exitEnabled: true,
            metadataKeys: [])
        self.mapBoxHelper?.navigation?.ttsReassuranceInstruction(enabled: true)
        self.mapBoxHelper?.navigation?.ttsReassuranceInstruction(distance: 10.0)
        self.mapBoxHelper?.navigation?.setUnitConversion(unitName: "meter", conversionCoefficiente: 1.0)
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
            mapBoxHelper = ProximiioMapbox(mapView: mapView, configuration: config)
            mapBoxHelper?.initialize { result in
                if result == .success {
                    self.mapBoxHelper?.mapNavigation = self
                    self.mapBoxHelper?.mapInteraction = self
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
        print(currentUserPosition)
    }
}

// MARK: ProximiioMapbox Navigation Delegate
extension ViewController: ProximiioMapboxNavigation {
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
    func change(floor: Int) {
        // triggered when floor has changed
        
        UserLocation.shared.floor = floor
        
        if let currentFloor = self.floors.first(where: { item -> Bool in
            item.level.intValue == floor }) {
            setFloor(floor: currentFloor)
        }
    }
    
    func onTap(feature: ProximiioGeoJSON) {
        // triggered if user taps on a POI
        
        /// define route rules
        let options = PIORouteOptions()
        /// define avoid rules
        options.avoidElevators = true
        options.avoidBarriers = true
        
        /// show route to a poi
        mapBoxHelper?.routeFindAndStart(to: feature, options: options)
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
                mapBoxHelper?.setLevel(level: floor)
                
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
        mapBoxHelper?.setLevel(level: floor.level.intValue)
    }
    
    private func didTapCompass() {
        mapBoxHelper?.followingUser = !(mapBoxHelper?.followingUser ?? false)
        
        /// force center to user position
        if mapBoxHelper?.followingUser ?? false {
            centerAtUser()
        }
    }
}
