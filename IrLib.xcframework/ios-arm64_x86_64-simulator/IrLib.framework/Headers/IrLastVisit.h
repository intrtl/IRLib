//
//  IrLastVisit.h
//  IntelligenceRetail
//
//  Created by Vsevolod Didkovskiy on 28/01/2019.
//  Copyright © 2019 Intelligence Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IrLastVisit : NSObject
@property NSString *id;
@property NSString *dt_start;
@property NSString *dt_end;
@property NSString *timestamp;
@property int result;

@end

NS_ASSUME_NONNULL_END
