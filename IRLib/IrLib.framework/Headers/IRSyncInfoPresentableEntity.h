//
//  IrSyncInfo.h
//  IrLib
//
//  Created by Vsevolod Didkovskiy on 04.02.2020.
//  Copyright © 2020 Intelligence Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IRSyncInfoPresentableEntity : NSObject
/// Прогресс синхронизации
@property float progress;
/// Текущее действие
@property NSString *title;
/// Дата и время последней синхронизации
@property NSString *lastSyncTime;
@end

NS_ASSUME_NONNULL_END
