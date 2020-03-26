//
//  AppDelegate+Routing.swift
//  ProximiioMapbox_Example
//
//  Created by dev on 3/26/20.
//  Copyright © 2020 CocoaPods. All rights reserved.
//

import UIKit

// MARK: - App UI Routing
extension AppDelegate {
    
    /// route to the homepage
    func showApp() {
        let viewcontroller = ViewController()
        window?.rootViewController = viewcontroller
    }
    
    /// route to the splash page for loading purposes
    func showLoading() {
        let viewcontroller = SplashViewController()
        window?.rootViewController = viewcontroller
    }
}
