//
//  CLLocationCoordinate2D+Extension.swift
//  ProximiioMapbox_Example
//
//  Created by dev on 3/26/20.
//  Copyright © 2020 CocoaPods. All rights reserved.
//

import MapKit

extension CLLocationCoordinate2D {
    func toCLLocation() -> CLLocation {
        return CLLocation(latitude: self.latitude, longitude: self.longitude)
    }

    static func zero() -> CLLocationCoordinate2D {
        return CLLocationCoordinate2D(latitude: 0, longitude: 0)
    }
}

extension Array where Element == CLLocationCoordinate2D {
    func toCLLocationArray() -> [CLLocation] {
        var items: [CLLocation] = []
        self.forEach({ item in
            items.append(CLLocation(latitude: item.latitude, longitude: item.longitude))
        })
        return items
    }
}
