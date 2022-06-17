Pod::Spec.new do |spec|
  spec.name         = "IRLib"
  spec.version      = "4.5.1" 
  spec.summary      = "Framework for Ailet functionality integration"
  spec.static_framework = true;
  spec.description  = <<-DESC
                         Framework for Ailet functionality integration.
                   DESC
  spec.homepage     = "https://github.com/intrtl/IRLib.git"
  spec.license      = "MIT"
  spec.author             = { "Alexander Shmakov" => "alexander.shmakov@ailet.com" }
  spec.platform     = :ios, "10.0"
  spec.source       = { :git => "https://github.com/intrtl/IRLib.git", :tag => "#{spec.version}" }
  spec.source_files = "IRLib/IrLib.framework/Headers/*.h"
  spec.public_header_files = "IRLib/IrLib.framework/Headers/*.h"
  spec.ios.vendored_frameworks = "IRLib/IrLib.framework"
  spec.frameworks = "CoreMotion", "UserNotifications"
  spec.dependency "Realm", "~> 5.5.0"
  spec.dependency "OpenCV2", "~> 3.4.10"
  spec.dependency "AppCenter", "~> 1.2.0"
  spec.dependency "IrLibSwift", "4.5.1"
  spec.dependency "BugfenderSDK", "1.8.0"
  spec.dependency "Amplitude", "~> 8.8.0"
end