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

- (instancetype)initWithIrCore:(IrCore *)irCore servicesBuilder:(IRLibServicesBuilder *)servicesBuilder;

- (UIViewController *)summaryReportsViewControllerWithExternalVisitId:(NSString *)externalVisitId internalTaskId:(NSString * _Nullable)internalTaskId;
- (UIViewController *)summaryReportsViewController;
- (UIViewController *)selectStoreViewController;
- (UIViewController *)filtersViewController;

- (UIViewController *)anketViewControllerForVisitId:(NSString *)visitId
                                  closeVisitHandler:(void (^)(BOOL))closeVisitHandle;
- (UIViewController *)anketViewControllerInViewModeForVisitId:(NSString *)visitId;

- (UIViewController *)assortmentReportViewController;
- (UIViewController *)matrixViewControllerForStoreId:(NSInteger)storeId shouldReloadDataAfterAppear:(BOOL)shouldReloadData;
- (UIViewController *)lackOfAssortmentViewController;
- (UIViewController *)cameraViewControllerWithIrCore:(IrCore *)irCore taskId:(NSString * _Nullable)taskId backTapHandler:(void(^)(void))backTapHandler;
- (id<WidgetsModuleInput>)widgetsController;
- (UIViewController *)storeDetailViewControllerWithIrCore:(IrCore *)irCore storeId:(NSInteger)storeId;
- (UIViewController *)taskDetailViewControllerWithIrCore:(IrCore *)irCore internalTaskId:(NSString * _Nullable)internalTaskId;
- (UIViewController *)visitStatsViewControllerWithVisitId:(NSString *)visitId;

- (UIViewController *)reportFiltersViewControllerWithStoreId:(NSInteger)storeId
                                                     visitId:(nonnull NSString *)visitId
                                                      taskId:(nullable NSString *)taskId
                                            productGroupCode:(nullable NSString *)productGroupCode
                                            productGroupName:(nullable NSString *)productGroupName
                                           currentReportType:(nullable NSString *)currentReportType
                                                      output:(id<ReportFiltersModuleOutput>)output;

@end

NS_ASSUME_NONNULL_END
