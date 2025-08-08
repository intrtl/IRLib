Pod::Spec.new do |spec|
  spec.name         = "IRLib"
  spec.version      = "5.18.2" 
  spec.summary      = "Framework for IR functionality integration"
  spec.static_framework = true;
  spec.description  = <<-DESC
                         Framework for IR functionality integration.
                   DESC
  spec.homepage     = "https://github.com/intrtl/IRLib.git"
  spec.license      = "MIT"
  spec.author       = { "Intrtl" => "support@intrtl.com" }
  spec.platform     = :ios, "15.0"
  spec.source       = { :git => "https://github.com/intrtl/IRLib.git", :tag => "#{spec.version}" }
  spec.ios.vendored_frameworks = "IrLib.xcframework"
  spec.frameworks = "CoreMotion", "UserNotifications", "Combine"
  spec.dependency "IrLibSwift", "= #{spec.version}"
  spec.dependency "OpenCV2", "~> 4.3.0"
  spec.dependency "BugfenderSDK", "2.0.0"
  spec.dependency "Intercom", "15.2.3"
  spec.dependency "Realm", "10.54.3-xcframework"
  spec.dependency "RealmSwift", "10.54.3-xcframework"
  spec.dependency "FirebaseAnalytics", "11.5.0"
  spec.dependency "FirebaseMessaging", '11.5.0'
  spec.dependency "FirebaseCrashlytics", '11.5.0'
  spec.dependency "GoogleUtilities", '8.0.2'
  spec.dependency "GRDB.swift", "6.24.1"
end
