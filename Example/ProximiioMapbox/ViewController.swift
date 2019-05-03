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

class ViewController: UIViewController, MGLMapViewDelegate {
    private final let TOKEN_PROXIMIIO = "INSERT-YOUR-TOKEN-HERE"
    private final let DEFAULT_COORDINATES = CLLocationCoordinate2DMake(25.336694717407227, 51.480995178223)

    @IBOutlet weak var mapView: MGLMapView!
    
    func mapView(_ mapView: MGLMapView, didFinishLoading style: MGLStyle) {
        mapView.setCenter(DEFAULT_COORDINATES, zoomLevel: 18, animated: true)
    }
    
    override func viewDidLoad() {
        Proximiio.sharedInstance()?.auth(withToken: TOKEN_PROXIMIIO, callback: { (state) in
            if (state == kProximiioReady) {
                Proximiio.sharedInstance()?.requestPermissions()
            }
        })
        
        ProximiioMapbox.shared.authorize(token: TOKEN_PROXIMIIO) { (authResult) in
            if (authResult == .success) {
                ProximiioMapbox.shared.addIndoorSupportTo(mapView: self.mapView)
            }
        }

        mapView.delegate = self
        mapView.styleURL = ProximiioMapbox.shared.styleURL
        
        super.viewDidLoad()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}

