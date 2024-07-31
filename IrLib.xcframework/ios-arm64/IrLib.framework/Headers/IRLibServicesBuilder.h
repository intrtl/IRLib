//
//  IRLibServicesBuilder.h
//  IrLib
//
//  Created by Alexander Shmakov on 13.07.2020.
//  Copyright © 2020 Intelligence Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AiletFeatureToggle.h"

@class IrCore;
NS_ASSUME_NONNULL_BEGIN

@interface IRLibServicesBuilder : NSObject

+ (instancetype)shared;

+ (IRStoredStateSettings *)swiftLibStoredStateSettings;
+ (IRDataManager *)swiftLibDataManager;

- (IrCore *)irCore;
- (IrCore *)irCoreWithSeparatedDB:(BOOL)isSeparated;

@end

NS_ASSUME_NONNULL_END
