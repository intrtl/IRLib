//
//  IrButton.h
//  IntelligenceRetail
//
//  Created by Vsevolod Didkovskiy on 29/07/2019.
//  Copyright © 2019 Intelligence Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IrButton : NSObject
@property bool isHidden;
@property bool isEnabled;
@property bool isSelected;
@property NSString *title;

@end

NS_ASSUME_NONNULL_END
