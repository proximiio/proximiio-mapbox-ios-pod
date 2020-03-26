//
//  UserLocation.swift
//  ProximiioMapbox_Example
//
//  Created by dev on 3/26/20.
//  Copyright © 2020 CocoaPods. All rights reserved.
//

import Foundation
import CoreLocation
import Proximiio

class UserLocation {
    static let shared = UserLocation()
    
    var coordinate: CLLocationCoordinate2D?
    var floor: Int?
    
    /// store a quick cache of nearby pois to be used accross the app
    var nearByPOI = [ProximiioGeoJSON]()
}
