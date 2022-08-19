//
//  IRUserInfoProvider.h
//  IrLib
//
//  Created by Alexander Shmakov on 29.05.2020.
//  Copyright © 2020 Intelligence Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IRUserInfoProvider <NSObject>

- (NSString *)userName;

@end

@interface DefaultIRUserInfoProvider : NSObject <IRUserInfoProvider>

@end
