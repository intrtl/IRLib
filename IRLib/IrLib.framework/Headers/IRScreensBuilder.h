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

- (UIViewController *)summaryReportsViewControllerWithExternalVisitId:(NSString *)externalVisitId internalTaskId:(NSString * _Nullable)internalTaskId;
- (UIViewController *)summaryReportsViewController;
- (UIViewController *)selectStoreViewController;
- (UIViewController *)anketViewControllerWithCloseVisitHandler:(void (^)(BOOL))closeVisitHandler;
- (UIViewController *)assortmentReportViewController;
- (UIViewController *)matrixViewControllerForStoreId:(NSInteger)storeId shouldReloadDataAfterAppear:(BOOL)shouldReloadData;
- (UIViewController *)cameraViewControllerWithIrCore:(IrCore *)irCore taskId:(NSString * _Nullable)taskId backTapHandler:(void(^)(void))backTapHandler;
- (UIViewController *)storeDetailViewControllerWithIrCore:(IrCore *)irCore storeId:(NSInteger)storeId;
- (UIViewController *)taskDetailViewControllerWithIrCore:(IrCore *)irCore internalTaskId:(NSString * _Nullable)internalTaskId;

@end

NS_ASSUME_NONNULL_END
