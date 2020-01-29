#
# Be sure to run `pod lib lint ProximiioMapbox.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ProximiioMapbox'
  s.version          = '0.2.5'
  s.summary          = 'Proximi.io Mapbox Indoor Support'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/proximiio/proximiio-mapbox-ios-pod'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'x-oauth-basic' => 'matej.drzik@quanto.sk' }
  s.source           = { :git => 'https://github.com/proximiio/proximiio-mapbox-ios-pod', :tag => s.version.to_s }

  s.ios.deployment_target = '12.0'

  s.dependency       'IndoorAtlas'
  s.dependency       'Proximiio'
  s.dependency       'Mapbox-iOS-SDK'
  s.dependency       'SwiftyJSON'
  s.dependency       'GRMustache.swift'
  s.dependency       'Speech'

  s.vendored_frameworks = 'ProximiioMapbox/ProximiioMapbox.framework'
  # s.resource_bundles = {
  #   'ProximiioMapbox' => ['ProximiioMapbox/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
