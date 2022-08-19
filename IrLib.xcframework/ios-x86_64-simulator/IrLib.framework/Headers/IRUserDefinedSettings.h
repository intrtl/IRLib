//
//  IrSettings.h
//  IrLib
//
//  Created by Vsevolod Didkovskiy on 08/01/2019.
//  Copyright © 2019 Intelligence Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IrSettingsExtended.h"
#import "IrSettingsInterface.h"

NS_ASSUME_NONNULL_BEGIN

@interface IRUserDefinedSettings : NSObject
@property NSString *appServer;
@property NSString *userName;

@property IrSettingsExtended *extended;
@property IrSettingsInterface *interface;
@end

NS_ASSUME_NONNULL_END
