//
//  IrCore.h
//  IntelligenceRetail
//
//  Created by Vsevolod Didkovskiy on 27/07/2019.
//  Copyright © 2019 Intelligence Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "AiletFeatureToggle.h"

@class IRLibServicesBuilder;
@protocol IRDataManagerProtocol;
typedef void(^SetupCompletionHandler)(long);

NS_ASSUME_NONNULL_BEGIN

@interface IrCore : NSObject

@property (nonatomic, copy, nullable) void(^authErrorHandler)(void);
@property (nonatomic, copy, nullable) void(^showSyncStatsScreenHandler)(void);

FOUNDATION_EXPORT int const IR_ERROR_BUSY;
FOUNDATION_EXPORT int const IR_RESULT_OK;
FOUNDATION_EXPORT int const IR_RESULT_EMPTY;
FOUNDATION_EXPORT int const IR_RESULT_NEED_RETAKE;
FOUNDATION_EXPORT int const IR_RESULT_OFFLINE;
FOUNDATION_EXPORT int const IR_ERROR;
FOUNDATION_EXPORT int const IR_ERROR_NO_INET;
FOUNDATION_EXPORT int const IR_ERROR_TOKEN;
FOUNDATION_EXPORT int const IR_ERROR_STORE_CATALOG;
FOUNDATION_EXPORT int const IR_ERROR_CATALOGS;
FOUNDATION_EXPORT int const IR_ERROR_STORE_ID_INCORRECT;
FOUNDATION_EXPORT int const IR_ERROR_STORES_EMPTY;
FOUNDATION_EXPORT int const IR_ERROR_VISIT_ID_INCORRECT;
FOUNDATION_EXPORT int const IR_ERROR_AUTH;
FOUNDATION_EXPORT int const IR_ERROR_CRASH;
FOUNDATION_EXPORT int const IR_NULLED_CONTEXT;
FOUNDATION_EXPORT int const IR_RESULT_INPROGRESS;
FOUNDATION_EXPORT int const IR_ERROR_NOVISIT;
FOUNDATION_EXPORT int const IR_ERROR_ASSORTMENT;
FOUNDATION_EXPORT int const IR_ERROR_NOTRESPONSE;
FOUNDATION_EXPORT int const IR_ERROR_SERVER;
FOUNDATION_EXPORT int const IR_RESULT_SHOW_SERVICES;
FOUNDATION_EXPORT int const IR_RESULT_LOGIN_APP_SERVER;
/// Передан ИД портала, но не включен мультипортальный режим.
FOUNDATION_EXPORT int const IR_ERROR_NOT_MULTIPORTAL_MODE;
/// В базе отсутствует такой портал.
FOUNDATION_EXPORT int const IR_ERROR_PORTAL_INCORRECT;
/// Был передан пустой ИД портала в мультипортальном режиме.
FOUNDATION_EXPORT int const IR_ERROR_EMPTY_PORTAL;

FOUNDATION_EXPORT int const AILET_VISIT_ERROR_CANT_FINISH;
FOUNDATION_EXPORT int const AILET_VISIT_ERROR_LACK_OF_ASSORTMENT;

#pragma mark - Initialization

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)init:(BOOL)isSeparated
     servicesBuilder:(IRLibServicesBuilder *)servicesBuilder;

- (instancetype)init:(BOOL)isSeparated
        dataManager:(id<IRDataManagerProtocol>)dataManager
     servicesBuilder:(IRLibServicesBuilder *)servicesBuilder;

#pragma mark - Instance methods

-(void)showReportsViewController;

-(int)dbVersion;
-(void)initLocalNotification;
-(void)startBg;
-(void)resetBg;

// MARK: - Lib interaction methods

-(long)setupWithUsername:(NSString*)username
                password:(NSString*)password
              guestToken:(NSString *)guestToken
          externalUserId:(nullable NSString*)externalUserId
            notification:(NSString*)notificationName
             isForceInit:(BOOL)isForceInit
              crashLimit:(int)crashLimit
              domainName:(nullable NSString *)domainName
           isMultiportal:(BOOL)isMultiportal;

/// 
-(void)setupWithUsername:(NSString*)username
                password:(NSString*)password
              guestToken:(NSString *)guestToken
          externalUserId:(nullable NSString*)externalUserId
            notification:(NSString*)notificationName
             isForceInit:(BOOL)isForceInit
              crashLimit:(int)crashLimit
              domainName:(nullable NSString *)domainName
           isMultiportal:(BOOL)isMultiportal
              completion:(SetupCompletionHandler)completion;

- (long)setPortal:(NSString *)portalId;

- (long)startIn:(nonnull UIViewController *)presentingVC withExternalStoreId:(NSString *)externalStoreId externalVisitId:(NSString*)externalVisitId;
- (long)showSummaryReportIn:(UIViewController *)presentingVC externalVisitId:(NSString *)externalVisitId;

-(NSArray *)reports;
-(NSDictionary *)reportsWithExternalVisitId:(NSString *)externalVisitId internalTaskId:(NSString * _Nullable)internalTaskId;

-(long)sendUnsentDataIfNeeded;
-(BOOL)isNeedSyncData;
-(void)startLocalNotification;
-(NSString *)frameworkVersion;
-(BOOL)useInfinityBgState;
-(void)useInfinityBg:(BOOL)use;
-(void)doDebugCommand;
-(NSString*)getVersion;
-(void)startSendAndRecive;

#ifdef INTERNAL_USAGE
- (void)setDevAuthTo:(BOOL)isDevAuth;
#endif

@end

NS_ASSUME_NONNULL_END
