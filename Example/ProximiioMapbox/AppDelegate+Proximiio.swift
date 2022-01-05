//
//  AppDelegate+Proximiio.swift
//  ProximiioMapbox_Example
//
//  Created by dev on 3/26/20.
//  Copyright © 2020 CocoaPods. All rights reserved.
//

import Foundation
import Proximiio
import ProximiioMapbox
import Kingfisher

extension AppDelegate {
    func setupProximiio() {
        /// force check permission
        Proximiio.sharedInstance()?.requestPermissions(true)
        /// show the main application
        Proximiio.sharedInstance()?.auth(withToken: appToken, callback: { state in
            
            /// if boot up of proximiio went fine
            if state == kProximiioReady {
                

                /// and try sync features too
                Proximiio.sharedInstance()?.sync({ _ in

                    /// if all fine start extra stuffs
                    self.startProximiio()

                    /// show app
                    self.showApp()

                    /// preload images
                    self.preloadFeatureImages { _ in }
                })


            } else {
                self.startProximiio()
                
                /// show app
                self.showApp()
            }
            
        })
    }
    
    private func startProximiio() {
        /// startup proximiio
        Proximiio.sharedInstance()?.enable()
        Proximiio.sharedInstance()?.startUpdating()
        
        /// force mini buffer
        Proximiio.sharedInstance()?.setBufferSize(kProximiioBufferMini)
    }
    
    private func preloadFeatureImages(callback: @escaping ((Bool) -> Void)) {
        var completed = 0
        PIODatabase.sharedInstance().features().forEach { feature in
            feature.images.forEach {
                if let imgUrl = URL(string: $0) {
                    completed += 1
                    ImageDownloader
                        .default
                        .downloadImage(
                            with: imgUrl, options: []) { (result) in
                            completed -= 1
                            switch result {
                            case .success(let image):
                                if let url = image.url {
                                    ImageCache.default.store(image.image, forKey: url.absoluteString)
                                }
                            default: break
                            }
                            if completed == 0 {
                                callback(true)
                            }
                        }
                }
            }
        }
    }
}
