//
//  AppDelegate.swift
//  ProximiioMapbox
//
//  Created by x-oauth-basic on 05/02/2019.
//  Copyright (c) 2019 x-oauth-basic. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    var window: UIWindow?
    var appController: UIViewController?


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        // setup proximiio with auto-preload
        setupProximiio()
        
        /// setup the window for the app
        self.window = UIWindow(frame: UIScreen.main.bounds)

        /// show loading screen
        showLoading()
        
        self.window?.makeKeyAndVisible()
        
        return true
    }
}

