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
```
4. Skip this step you haven't embedded the framework previously without Cocoapods.
Remove `IRLib.framework` from embedded libraries (xcode project settings -> 'General' tab), Embedded Frameworks and Link binary with libraries sections (xcode project settings -> 'Build Phases' tab). 

5. Run `pod install` via terminal in directory with your project.

6. To update version of previously installed framework run `pod update IRLib` via terminal in directory with your project.
