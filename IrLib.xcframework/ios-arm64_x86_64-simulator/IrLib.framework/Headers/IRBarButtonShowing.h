//
//  IRMenuPresenting.h
//  IrLib
//
//  Created by Alexander Shmakov on 01.06.2020.
//  Copyright © 2020 Intelligence Retail. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol IRBarButtonShowing<NSObject>

- (void)addBarButton:(UIBarButtonItem *)barButton;

@end
