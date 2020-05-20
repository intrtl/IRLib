Pod::Spec.new do |spec|
  spec.name         = "IRLib"
  spec.version      = "1.0.168"
  spec.summary      = "Framework for Intelligence Retail functionality integration"
  spec.static_framework = true;
  spec.description  = <<-DESC
                         Framework for Intelligence Retail functionality integration.
                   DESC
  spec.homepage     = "https://github.com/intrtl/IRLib"
  spec.license      = "MIT"
  spec.author             = { "Alexander Shmakov" => "alexander.shmakov@intrtl.com" }
  spec.platform     = :ios, "8.0"
  spec.source       = { :git => "https://github.com/intrtl/IRLib", :tag => "#{spec.version}" }
  spec.source_files = "IRLib/IrLib.framework/Headers/*.h"
  spec.public_header_files = "IRLib/IrLib.framework/Headers/*.h"
  spec.ios.vendored_frameworks = "IRLib/IrLib.framework"
  spec.frameworks = "CoreMotion", "UserNotifications"
  spec.dependency "Realm", "~> 4.3.0"
  spec.dependency "Charts", "~> 3.2.2"
  spec.dependency "OpenCV2", "~> 3.4.6"
  spec.dependency "AppCenter", "~> 1.2.0"
  spec.dependency "IrLibSwift", "~> 0.0.1"
end