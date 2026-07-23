## Attention
This is a **legacy framework** that exists only for backward compatibility with clients that still use it. For a better experience, you should use the **[IrLibSwift](https://github.com/intrtl/IRLibSwift)** framework, which provides an asynchronous API for proper interaction. See the documentation [HERE](https://github.com/intrtl/AiletLibraryExamples/blob/master/iOS/IrLibSwiftAsyncAPI/README.md).

## Installation via [Cocoapods](https://cocoapods.org) ##

1. Add repo with Intelligence Retail specs and official Cocoapods specs into your project `Podfile` :

```
     source 'https://github.com/CocoaPods/Specs.git'
     source 'https://github.com/intrtl/specs'
```

2. Add  `use_frameworks!` param to your `Podfile`.

3. Add `IRLib` pod as a dependency to your projects targets:

```
  target 'YourTarget' do
    pod 'IRLib'
  end
  
 post_install do |installer|
 installer.pods_project.targets.each do |target|
  if target.name == "GRDB.swift"
   target.build_configurations.each do |config|
    config.build_settings['BUILD_LIBRARY_FOR_DISTRIBUTION'] = 'YES'
   end
  end
 end
end

```
4. Skip this step you haven't embedded the framework previously without Cocoapods.
Remove `IRLib.framework` from embedded libraries (xcode project settings -> 'General' tab), Embedded Frameworks and Link binary with libraries sections (xcode project settings -> 'Build Phases' tab). 

5. Run `pod install` via terminal in directory with your project.

6. To update version of previously installed framework run `pod update IRLib` via terminal in directory with your project.
