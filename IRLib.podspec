Pod::Spec.new do |spec|
  spec.name         = "IRLib"
  spec.version      = "5.8.0-beta" 
  spec.summary      = "Framework for Ailet functionality integration"
  spec.static_framework = true;
  spec.description  = <<-DESC
                         Framework for Ailet functionality integration.
                   DESC
  spec.homepage     = "https://github.com/intrtl/IRLib.git"
  spec.license      = "MIT"
  spec.author       = { "Alexander Shmakov" => "alexander.shmakov@ailet.com" }
  spec.platform     = :ios, "12.0"
  spec.source       = { :git => "https://github.com/intrtl/IRLib.git", :tag => "#{spec.version}" }
  spec.ios.vendored_frameworks = "IrLib.xcframework"
  spec.frameworks = "CoreMotion", "UserNotifications"
  spec.dependency "OpenCV2", "~> 4.3.0"
  spec.dependency "AppCenter", "~> 4.4.2"
  spec.dependency "BugfenderSDK", "1.13.2"
  spec.dependency "Amplitude", "~> 8.8.0"
  spec.dependency "IrLibSwift", "5.8.0-beta"
  spec.dependency "RealmSwift", "10.47.0"
  spec.dependency "Realm", "10.47.0"
end
