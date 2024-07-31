//
//  IrView.h
//  IrLib
//
//  Created by Vsevolod Didkovskiy on 01/09/2017.
//  Copyright © 2017 Intelligence Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Realm/Realm.h>

@class RLMObject;

__attribute__((deprecated("Use IRInteractManager from IrLibSwift instead of this class")))
@interface IrView : NSObject

+(int)dbVersion __attribute__((deprecated("Use IRInteractManager `frameworkVersion` method from IrLibSwift instead of this class")));
+(void)initLocalNotification;
+(void)startBg;
+(void)resetBg;

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
notification:(NSString*)notificationName
isMultiportal:(BOOL)isMultiportal
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
notification:(NSString*)notificationName
isForceInit:(BOOL)isForceInit
 crashLimit:(int)crashLimit
isMultiportal:(BOOL)isMultiportal
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
notification:(NSString*)notificationName
isMultiportal:(BOOL)isMultiportal
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));


+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
notification:(NSString*)notificationName
isForceInit:(BOOL)isForceInit
 crashLimit:(int)crashLimit
isMultiportal:(BOOL)isMultiportal
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
    guestToken:(NSString *)guestToken
  notification:(NSString*)notificationName
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
    guestToken:(NSString *)guestToken
  notification:(NSString*)notificationName
   isForceInit:(BOOL)isForceInit
    crashLimit:(int)crashLimit
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
    guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
  notification:(NSString*)notificationName
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));


+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
    guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
  notification:(NSString*)notificationName
   isForceInit:(BOOL)isForceInit
    crashLimit:(int)crashLimit
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
notification:(NSString*)notificationName
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
notification:(NSString*)notificationName
isForceInit:(BOOL)isForceInit
 crashLimit:(int)crashLimit
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
notification:(NSString*)notificationName
__attribute__((deprecated("Use IRInteractManager setup method from IrLibSwift instead of this class")));

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
notification:(NSString*)notificationName
isForceInit:(BOOL)isForceInit
 crashLimit:(int)crashLimit
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)start:(UIViewController*)view_
external_store_id:(NSString*)external_store_id
external_visit_id:(NSString*)external_visit_id
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)start:(UIViewController*)view_
external_store_id:(NSString*)external_store_id
external_visit_id:(NSString*)external_visit_id
isForceStart:(BOOL)isForceStart
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)showSummaryReport:(UIViewController*)view_
                visit_id:(NSString *)external_visit_id
__attribute__((deprecated("Use IRInteractManager `showSummaryReport` method from IrLibSwift instead of this class")));

+(NSArray *)reports
__attribute__((deprecated("Use IRInteractManager `reports` method from IrLibSwift instead of this class")));

+(NSDictionary *)reports:(NSString *)external_visit_id
__attribute__((deprecated("Use IRInteractManager `reportWithVisitId` method from IrLibSwift instead of this class")));

+(NSDictionary *)reports:(NSString *)external_visit_id
                 isLogOn:(BOOL)isLogOn
__attribute__((deprecated("Use IRInteractManager `reportWithVisitId` method from IrLibSwift instead of this class")));

+(long)syncData
__attribute__((deprecated("Use IRInteractManager `syncData` method from IrLibSwift instead of this class")));

+(BOOL)isNeedSyncData;
+(void)startLocalNotification;
+(NSString *)frameworkVersion;
+(void)useInfinityBg:(BOOL)use;
+(void)initAnalytics;

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
  notification:(NSString*)notificationName
 isMultiportal:(BOOL)isMultiportal
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
  notification:(NSString*)notificationName
   isForceInit:(BOOL)isForceInit
    crashLimit:(int)crashLimit
 isMultiportal:(BOOL)isMultiportal
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
external_user_id:(NSString*)external_user_id_
  notification:(NSString*)notificationName
 isMultiportal:(BOOL)isMultiportal
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)initLib:(NSString*)user_name_
      password:(NSString*)user_password_
external_user_id:(NSString*)external_user_id_
  notification:(NSString*)notificationName
   isForceInit:(BOOL)isForceInit
    crashLimit:(int)crashLimit
 isMultiportal:(BOOL)isMultiportal
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+(long)init:(NSString*)user_name_
   password:(NSString*)user_password_
 guestToken:(NSString *)guestToken
external_user_id:(NSString*)external_user_id_
notification:(NSString*)notificationName
isForceInit:(BOOL)isForceInit
 crashLimit:(int)crashLimit
 domainName:(nullable NSString *)domainName
isMultiportal:(BOOL)isMultiportal
__attribute__((deprecated("Use IRInteractManager `setup` method from IrLibSwift instead of this class")));

+ (long)setPortal:(nonnull NSString *)portalId
__attribute__((deprecated("Use IRInteractManager `updateActivePortal` method from IrLibSwift instead of this class")));

+(BOOL)useInfinityBgState;

#ifdef INTERNAL_USAGE
+(void)setDevAuthTo:(BOOL)isDevAuth;
#endif

@end
