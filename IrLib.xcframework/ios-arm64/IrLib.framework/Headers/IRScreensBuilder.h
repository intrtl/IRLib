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

- (UIViewController *)assortmentReportViewController;
- (UIViewController *)matrixViewControllerForStoreId:(NSInteger)storeId shouldReloadDataAfterAppear:(BOOL)shouldReloadData;
- (UIViewController *)lackOfAssortmentViewController;
- (id<WidgetsModuleInput>)widgetsController;
- (UIViewController *)storeDetailViewControllerWithIrCore:(IrCore *)irCore storeId:(NSInteger)storeId;
- (UIViewController *)taskDetailViewControllerWithIrCore:(IrCore *)irCore
                                                 visitId:(NSString *)visitId
                                                 storeId:(NSInteger)storeId
                                          internalTaskId:(NSString * _Nullable)internalTaskId;
- (UIViewController *)visitStatsViewControllerWithVisitId:(NSString *)visitId;

- (UIViewController *)reportFiltersViewControllerWithStoreId:(NSInteger)storeId
                                                     visitId:(nonnull NSString *)visitId
                                                      taskId:(nullable NSString *)taskId
                                            productGroupCode:(nullable NSString *)productGroupCode
                                            productGroupName:(nullable NSString *)productGroupName
                                           currentReportType:(nullable NSString *)currentReportType
                                                      output:(id<LegacyReportFiltersModuleOutput>)output;

@end

NS_ASSUME_NONNULL_END
