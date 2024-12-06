Pod::Spec.new do |spec|
  spec.name         = "IRLib"
  spec.version      = "5.13.4" 
  spec.summary      = "Framework for IR functionality integration"
  spec.static_framework = true;
  spec.description  = <<-DESC
                         Framework for IR functionality integration.
                   DESC
  spec.homepage     = "https://github.com/intrtl/IRLib.git"
  spec.license      = "MIT"
  spec.author       = { "Intrtl" => "support@intrtl.com" }
  spec.platform     = :ios, "14.0"
  spec.source       = { :git => "https://github.com/intrtl/IRLib.git", :tag => "#{spec.version}" }
  spec.ios.vendored_frameworks = "IrLib.xcframework"
  spec.frameworks = "CoreMotion", "UserNotifications", "Combine"
  spec.dependency "AppCenter", "~> 5.0.5"
  spec.dependency "OpenCV2", "~> 4.3.0"
  spec.dependency "BugfenderSDK", "2.0.0"
  spec.dependency "Amplitude", "~> 8.8.0"
  spec.dependency "IrLibSwift", "= #{spec.version}"
  spec.dependency "Realm", "10.54.1-xcframework"
  spec.dependency "RealmSwift", "10.54.1-xcframework"
end
