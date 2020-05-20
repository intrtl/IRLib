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
#import "IrButtonsState.h"
#import "IRSyncInfoPresentableEntity.h"
#import "IrSettings.h"
#import "IrLastVisit.h"
#import "ContentStruct.h"

@protocol IrCoreDelegate <NSObject>
@optional
-(void)updateMainMenuButtons;
-(void)showFormViewController;
-(void)showInstructions;
-(void)showHints;
-(void)showLogo:(UIImage *)logo;
-(void)showOnline;
-(void)showOffline;
-(void)showLogin;
-(void)updateContent;
-(void)showSettingsErrorAlert;
-(void)didUpdateSyncInfo;
-(void)didUpdateSyncInfoWithOfflineMessage:(NSString *)message;
@end

@interface IrCore : NSObject
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

FOUNDATION_EXPORT int const MODE_PANO_NONE;
FOUNDATION_EXPORT int const MODE_PANO_70;

-(id)init:(id)parent;
-(id)init:(id)parent isSeparated:(bool)isSeparated;
-(void)configure;
-(void)finishVisit;
-(void)updateMainButtons;
-(IrButtonsState *)getButtons;
-(void)initAndShowCameraViewController;
-(void)panoramaProcess;
-(void)showCameraViewController;
-(void)showCameraViewControllerWithParent:(id)parent;
-(void)showReportsViewController;
-(void)showMatrixAssortmentViewController;
-(void)showMatrixAssortmentViewControllerWithParent:(id)parent;
-(void)showLackOfAssortmentViewController;
-(void)showFormsViewController;
-(void)showFormsEditViewController;
-(void)showMatrixViewController;
-(void)closeVisit;
-(void)selectStore;
-(void)updateMatrix;
-(void)showCameraWaiting;
-(void)hideCameraWaiting;
- (void)initAsLib;
-(void)initAsApp;
-(void)initTimers;
-(void)stopTimers;
-(void)reinitModel;

-(void)loginOnAuthServer:(NSString *)login
                password:(NSString *)password
              guestToken:(NSString *)guestToken
      isShowDebugConsole:(bool)isShowDebugConsole
              externalId:(NSString *)externalId
                 isDebug:(bool)isDebug
            withCallback:(void (^)(int errorCode, NSString *ip, NSString *ipName, NSArray *services))callback;

-(void)loginOnAppServer:(NSString *)ip
                 ipName:(NSString *)ipName
                  login:(NSString*)login
               password:(NSString*)password
           withCallback:(void (^)(int resultCode))callback;

-(void)setSettings:(IrSettings *)settings;
-(IrSettings *)getSettings;
-(bool)isTokenValid;
-(bool)isShowInstructions;
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
   crashLimit:(int)crashLimit;

-(long)start:(NSString*)external_store_id
external_visit_id:(NSString*)external_visit_id;
-(long)start:(NSString*)external_store_id
external_visit_id:(NSString*)external_visit_id
isForceStart:(BOOL)isForceStart;
-(long)showSummaryReport:(NSString *)external_visit_id;
-(NSArray *)reports;
-(NSDictionary *)reports:(NSString *)external_visit_id;
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
-(int)makeCrash;
-(int)libVersion;
-(BOOL)useInfinityBgState;
-(void)useInfinityBg:(BOOL)use;
-(void)initAnalytics;
-(void)doDebugCommand;
-(void)doThenLogout;
-(NSString *)getServer;
-(NSString *)getServerName;
-(NSString *)getUserName;
-(NSString *)getStats;
-(bool)isCurrentVisitNotClosed;
-(bool)isNeedSendDataToServer;
-(long)getNotSendedPhototsCnt;
-(NSString*)getVideoInstructionsUrl;
-(NSString *)getLanguage;
-(void)setInstructionsShowed;
-(long)getPhotosInVisitCnt;
-(NSString*)getVersion;
-(void)startSendAndRecive;
-(NSMutableArray <ContentStruct *> *)getContent;
-(long)getCurrentStoreId;
-(void)loadContentWithCallback:(void (^)(bool res))callback;
-(bool)isHaveContent;
-(void)testCheckString;
-(void)destroy;
-(bool)getAutoPhotosTestEnabled;
-(void)setAutoPhotosTestEnabled:(bool)value;
-(void)closeIncorrectScenesAndResetAssortmentRequestCnt;
-(void)fetchPlanIfNeeded;
-(void)fetchVisitsHistory;
-(IRSyncInfoPresentableEntity *)syncInfo;
- (void)startSync;

@end
