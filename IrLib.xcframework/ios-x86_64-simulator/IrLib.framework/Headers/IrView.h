//
//  IrView.h
//  IrLib
//
//  Created by Vsevolod Didkovskiy on 01/09/2017.
//  Copyright © 2017 Intelligence Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IrLastVisit.h"
#import "IrCore.h"

@interface IrView : NSObject

+(int)dbVersion;
+(void)initRealm;
+(void)initRealm:(BOOL)isSeparatedBase;
+(void)initLocalNotification;
+(void)startBg;
+(void)resetBg;
+(long)syncCatalogs;

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
notification:(NSString*)notificationName
isMultiportal:(BOOL)isMultiportal;

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
notification:(NSString*)notificationName
isForceInit:(BOOL)isForceInit
 crashLimit:(int)crashLimit
isMultiportal:(BOOL)isMultiportal;

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
notification:(NSString*)notificationName
isMultiportal:(BOOL)isMultiportal;

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
notification:(NSString*)notificationName
isForceInit:(BOOL)isForceInit
 crashLimit:(int)crashLimit
isMultiportal:(BOOL)isMultiportal;

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
    guestToken:(NSString *)guestToken
  notification:(NSString*)notificationName;

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
    guestToken:(NSString *)guestToken
  notification:(NSString*)notificationName
   isForceInit:(BOOL)isForceInit
    crashLimit:(int)crashLimit;

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
    guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
  notification:(NSString*)notificationName;

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
    guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
  notification:(NSString*)notificationName
   isForceInit:(BOOL)isForceInit
    crashLimit:(int)crashLimit;

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
notification:(NSString*)notificationName;

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
notification:(NSString*)notificationName
isForceInit:(BOOL)isForceInit
 crashLimit:(int)crashLimit;

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
notification:(NSString*)notificationName;

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
notification:(NSString*)notificationName
isForceInit:(BOOL)isForceInit
 crashLimit:(int)crashLimit;

+(long)start:(UIViewController*)view_
external_store_id:(NSString*)external_store_id
external_visit_id:(NSString*)external_visit_id;

+(long)start:(UIViewController*)view_
external_store_id:(NSString*)external_store_id
external_visit_id:(NSString*)external_visit_id
isForceStart:(BOOL)isForceStart;

+(long)showSummaryReport:(UIViewController*)view_
                visit_id:(NSString *)external_visit_id;
+(NSArray *)reports;
+(NSDictionary *)reports:(NSString *)external_visit_id;
+(NSDictionary *)reports:(NSString *)external_visit_id
                 isLogOn:(BOOL)isLogOn;
+(long)syncData;
+(long)assortmentCorrect:(NSDictionary*)corrections;
+(long)loadSamples;
+(long)loadSamples:(void (^)(bool isAllLoaded))callback;
+(NSDictionary *)notFound:(NSString *)external_visit_id;
+(void)resetDB;
+(NSString *) getLogs;
+(BOOL)isNeedSyncData;
+(long)getNotSentImagesCnt;
+(void)startLocalNotification;
+(IrLastVisit *)getLastVisit:(NSString *)external_store_id;
+(NSString *)frameworkVersion;
+(void)useInfinityBg:(BOOL)use;
+(void)initAnalytics;

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
  notification:(NSString*)notificationName
 isMultiportal:(BOOL)isMultiportal;

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
  notification:(NSString*)notificationName
   isForceInit:(BOOL)isForceInit
    crashLimit:(int)crashLimit
 isMultiportal:(BOOL)isMultiportal;

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
external_user_id:(NSString*)external_user_id_
  notification:(NSString*)notificationName
 isMultiportal:(BOOL)isMultiportal;

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
external_user_id:(NSString*)external_user_id_
  notification:(NSString*)notificationName
   isForceInit:(BOOL)isForceInit
    crashLimit:(int)crashLimit
 isMultiportal:(BOOL)isMultiportal;

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
notification:(NSString*)notificationName
isForceInit:(BOOL)isForceInit
 crashLimit:(int)crashLimit
 domainName:(nullable NSString *)domainName
isMultiportal:(BOOL)isMultiportal;

+ (long)setPortal:(nonnull NSString *)portalId;

+(void)doDebugCommand;
+(void)setIsDebug:(bool)value;
+(void)setAutoPhotosTestEnabled:(bool)value;
+(bool)getAutoPhotosTestEnabled;
+(bool)getIsDebug;
+(BOOL)useInfinityBgState;

@end
