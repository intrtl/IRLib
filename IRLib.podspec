Pod::Spec.new do |spec|
  spec.name         = "IRLib"
  spec.version      = "5.9.9" 
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
  spec.dependency "AppCenter", "~> 4.4.2"
  spec.dependency "OpenCV2", "~> 4.3.0"
  spec.dependency "BugfenderSDK", "1.13.2"
  spec.dependency "Amplitude", "~> 8.8.0"
  spec.dependency "IrLibSwift", "= #{spec.version}"
  spec.dependency "Realm", "10.50.1-xcframework"
  spec.dependency "RealmSwift", "10.50.1-xcframework"
end
