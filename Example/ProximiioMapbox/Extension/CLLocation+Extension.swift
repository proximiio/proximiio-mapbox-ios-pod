//
//  CLLocation+Extension.swift
//  ProximiioMapbox_Example
//
//  Created by dev on 3/26/20.
//  Copyright © 2020 CocoaPods. All rights reserved.
//

import MapKit

// MARK: - Conversion
extension CLLocation {
    func toCLLocationCoordinate2D() -> CLLocationCoordinate2D {
        return self.coordinate
    }
}

// MARK: - Array Conversion
extension Array where Element == CLLocation {
    func toCLLocationCoordinate2DArray() -> [CLLocationCoordinate2D] {
        var items: [CLLocationCoordinate2D] = []
        self.forEach({ item in
            items.append(CLLocationCoordinate2D(latitude: item.coordinate.latitude, longitude: item.coordinate.longitude))
        })
        return items
    }

    func toJSONArrayOfAnchors() -> [[String: Double]] {
    var items: [[String: Double]] = []
        self.forEach { item in
            items.append(["lat": item.coordinate.latitude, "lng": item.coordinate.longitude])
        }
        return items
    }
}
