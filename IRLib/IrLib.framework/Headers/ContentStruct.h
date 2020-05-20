//
//  ContentStruct.h
//  IntelligenceRetail
//
//  Created by Vsevolod Didkovskiy on 09/08/2019.
//  Copyright © 2019 Intelligence Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ContentStruct : NSObject
@property NSString *title;
@property NSString *url;
@property NSString *filename;
@property long is_deleted;
@property long is_loaded;
@property long store_id;

@end

NS_ASSUME_NONNULL_END
