//
//  IRScreensBuilder.h
//  IrLib
//
//  Created by Alexander Shmakov on 01.06.2020.
//  Copyright © 2020 Intelligence Retail. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IrCore.h"

NS_ASSUME_NONNULL_BEGIN

@interface IRScreensBuilder : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithIrCore:(IrCore *)irCore;

- (UIViewController *)summaryReportsViewController;
- (UIViewController *)selectStoreViewController;
- (UIViewController *)anketViewControllerWithCloseVisitHandler:(void (^)(BOOL))closeVisitHandler;
- (UIViewController *)assortmentReportViewController;
- (UIViewController *)matrixViewController;
- (UIViewController *)cameraViewControllerWithIrCore:(IrCore *)irCore taskId:(NSString * _Nullable)taskId backTapHandler:(void(^)(void))backTapHandler;

@end

NS_ASSUME_NONNULL_END
