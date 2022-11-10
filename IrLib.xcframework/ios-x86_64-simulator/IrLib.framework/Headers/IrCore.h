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
#import "IRSyncInfoPresentableEntity.h"
#import "IRUserDefinedSettings.h"
#import "IrLastVisit.h"
#import "TechSupportPresenter.h"
#import "AiletFeatureToggle.h"

@class SelectStoreTableViewController;
@class Api;
@class CatalogNetworkService;
@class IRLibServicesBuilder;
@protocol IRStoreService;
@protocol IRDataManagerProtocol;
@protocol SyncService;
@protocol CameraModuleOutput;

NS_ASSUME_NONNULL_BEGIN

@protocol IrCoreDelegate <NSObject>
@optional
-(void)showLogo:(UIImage *)logo;
-(void)showOnline;
-(void)showOffline;
-(void)updateContent;
-(void)showSettingsErrorAlert;
-(void)didUpdateSyncInfo;
-(void)didReceiveSyncInfoError:(IRSyncError)error;
@end

@interface IrCore : NSObject <TechSupportPresenter>

@property (strong, nonatomic) Api *api;

@property (nonatomic, copy, nullable) void(^updateAnketHandler)(void);
@property (nonatomic, copy, nullable) void(^authErrorHandler)(void);
@property (nonatomic, copy, nullable) void(^showSyncStatsScreenHandler)(void);

@property (weak, nonatomic) id<IrCoreDelegate> delegate;
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

FOUNDATION_EXPORT int const MODE_PANO_NONE;
FOUNDATION_EXPORT int const MODE_PANO_70;

#pragma mark - Initialization

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)init:(id)parent
        isSeparated:(bool)isSeparated
        storeService:(id<IRStoreService>)storeService
                api:(Api *)api
        syncService:(id<SyncService>)syncService
      catalogService:(CatalogNetworkService *)catalogService
     servicesBuilder:(IRLibServicesBuilder *)servicesBuilder;

- (instancetype)init:(id)parent
         isSeparated:(bool)isSeparated
        dataManager:(id<IRDataManagerProtocol>)dataManager
       storeService:(id<IRStoreService>)storeService
                api:(Api *)api
         syncService:(id<SyncService>)syncService
      catalogService:(CatalogNetworkService *)catalogService
     servicesBuilder:(IRLibServicesBuilder *)servicesBuilder;

#pragma mark - Instance methods

-(void)finishVisit;
-(void)initAndShowCameraViewControllerWithExternalVisitId:(nonnull NSString *)externalVisitId
                                          externalStoreId:(nonnull NSString *)externalStoreId
                                                   taskId:(nullable NSString *)taskId;
-(void)showCameraViewControllerWithExternalVisitId:(nonnull NSString *)externalVisitId
                                   externalStoreId:(nonnull NSString *)externalStoreId
                                            taskId:(nullable NSString *)taskId;
-(void)showCameraViewControllerWithParent:(id)parent
                          externalVisitId:(nonnull NSString *)externalVisitId
                          externalStoreId:(nonnull NSString *)externalStoreId
                                   taskId:(nullable NSString *)taskId;

-(void)showReportPhotoBrowseViewControllerWithParent:(nullable UIViewController *)parent
                                              taskId:(nullable NSString *)taskId;

- (BOOL)isAnketAvailable;
-(void)showReportsViewController;
-(void)showMatrixAssortmentViewController;
-(void)showMatrixAssortmentViewControllerWithParent:(id)parent;
-(void)showLackOfAssortmentViewController;
-(void)showFormsEditViewController;
-(void)closeVisit;
- (void)initAsLib;
-(void)initAsApp;
-(void)initTimers;
-(void)stopTimers;
- (void)stopSyncMonitoring;
-(void)reinitModel;
-(void)stopReportTimeTracking;
-(void)startReportTimeTracking;

-(void)loginOnAuthServer:(NSString *)login
                password:(NSString *)password
              guestToken:(NSString *)guestToken
      isShowDebugConsole:(bool)isShowDebugConsole
              externalId:(nullable NSString *)externalId
                 isDebug:(bool)isDebug
            withCallback:(void (^)(int errorCode, NSString *ip, NSString *ipName, NSArray *services))callback;

-(void)loginOnAppServer:(NSString *)ip
                 ipName:(NSString *)ipName
                  login:(NSString*)login
               password:(NSString*)password
           withCallback:(void (^)(int resultCode))callback;

-(void)setSettings:(IRUserDefinedSettings *)settings;
-(IRUserDefinedSettings *)getSettings;
-(bool)isTokenValid;
- (BOOL)shouldReauthorizeWithUserName:(NSString *)userName userPassword:(NSString *)userPassword externalUserId:(NSString * _Nullable)externalUserId;
-(bool)isDebug;
-(void)setIsDebug:(bool)value;
-(bool)getIsDebug;

//IrView --------------------------------
-(int)dbVersion;
-(void)setParent:(id)parent;
-(void)initLocalNotification;
-(void)startBg;
-(void)resetBg;
-(long)syncCatalogs;
-(long)initIr:(NSString*)user_name_
     password:(NSString*)user_password_
   guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
 notification:(NSString*)notificationName
  isForceInit:(BOOL)isForceInit
   crashLimit:(int)crashLimit
   domainName:(nullable NSString *)domainName
isMultiportal:(BOOL)isMultiportal;

-(long)initIr:(NSString*)user_name_
     password:(NSString*)user_password_
   guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
 notification:(NSString*)notificationName
  isForceInit:(BOOL)isForceInit
   crashLimit:(int)crashLimit
   domainName:(nullable NSString *)domainName;

- (long)setPortal:(NSString *)portalId;

-(long)start:(NSString*)external_store_id
external_visit_id:(NSString*)external_visit_id;
-(long)start:(NSString*)external_store_id
external_visit_id:(NSString*)external_visit_id
isForceStart:(BOOL)isForceStart;
-(long)showSummaryReport:(NSString *)external_visit_id;
-(NSArray *)reports;
-(NSDictionary *)reports:(NSString *)external_visit_id;
-(NSDictionary *)reports:(NSString *)external_visit_id internalTaskId:(NSString * _Nullable)internalTaskId;
-(NSDictionary *)reports:(NSString *)external_visit_id
                 isLogOn:(BOOL)isLogOn;
-(long)syncData;
-(long)assortmentCorrect:(NSDictionary*)corrections;
-(long)loadSamples;
-(long)loadSamples:(void (^)(bool isAllLoaded))callback;
-(NSDictionary *)notFound:(NSString *)external_visit_id;
-(void)resetDB;
-(NSString *) getLogs;
-(BOOL)isNeedSyncData;
-(long)getNotSentImagesCnt;
-(void)startLocalNotification;
-(IrLastVisit *)getLastVisit:(NSString *)external_store_id;
-(int)libVersion DEPRECATED_MSG_ATTRIBUTE("This is old version number. Use frameworkVersion instead.");
-(NSString *)frameworkVersion;
-(BOOL)useInfinityBgState;
-(void)useInfinityBg:(BOOL)use;
-(void)initAnalytics;
-(void)doDebugCommand;
-(void)doThenLogout;
- (NSString *)getServer;
- (NSString *)getServerName;
- (NSString *)getUserName;
- (NSInteger)getUserId;
-(NSString *)getStats;
-(NSString*)getVideoInstructionsUrl;
-(NSString *)getLanguage;
-(void)setInstructionsShowed;
-(NSString*)getVersion;
-(void)startSendAndRecive;
-(long)getCurrentStoreId;
-(void)destroy;
-(bool)getAutoPhotosTestEnabled;
-(void)setAutoPhotosTestEnabled:(bool)value;
-(void)fetchAppSettings;
-(void)fetchPlanIfNeeded;
-(IRSyncInfoPresentableEntity *)syncInfo;
- (void)startSync;
- (long)libSync:(long)result;
- (void)startForcePhotoSync;

- (BOOL)isInternetAvailable;
- (BOOL)isStartedFromDeeplink;
- (void)setStartedFromDeeplink;
- (nullable UIViewController *)configuredVisitStartControllerForExternalStoreId:(NSString *)external_store_id
                                                                externalVisitId:(NSString *)external_visit_id
                                                                         taskId:(NSString * _Nullable)taskId
                                                                   isForceStart:(BOOL)isForceStart
                                                                   cameraOutput:(id<CameraModuleOutput>)cameraOutput
                                                           backButtonTapHandler:(void(^_Nullable)(void))backButtonTapHandler
                                                                          error:(NSError **)error;
- (NSDictionary *)visitStatsForVisitWithExternalId:(NSString *)externalVisitId internalTaskId:(NSString * _Nullable)internalTaskId;
- (BOOL)shouldSyncManually;
- (void)showTechSupportScreen;
- (void)updateDeviceToken:(NSData *)deviceToken;
- (void)updateGetPhotoResultIntervals:(NSArray *)intervals;

- (void)restartSendPhotoSequenceWithUpdateHandler:(nullable void(^)(NSError * _Nullable))updateHandler;

- (void)downloadPreviousVisitWithExternalId:(NSString *)externalId error:(NSError **)error;

- (void)restartSendSceneAttributesSequenceWithUpdateHandler:(nullable void(^)(NSError * _Nullable))updateHandler;

- (void)logScreenTimeEventWithId:(NSString *)id name:(NSString *)name duration:(long)duration;

- (nullable UIViewController *)oosReportViewController;

- (UIViewController *)searchStoresViewController;

@end

NS_ASSUME_NONNULL_END
