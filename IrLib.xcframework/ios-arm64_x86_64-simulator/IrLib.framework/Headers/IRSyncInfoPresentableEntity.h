//
//  IrSyncInfo.h
//  IrLib
//
//  Created by Vsevolod Didkovskiy on 04.02.2020.
//  Copyright © 2020 Intelligence Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, IRSyncError) {
    IRSyncErrorNone = 0,
    IRSyncErrorServer = 1,
    IRSyncErrorConnection = 2,
    IRSyncErrorUnknown = 3
};

@interface IRSyncInfoPresentableEntity : NSObject
/// Прогресс синхронизации
@property float progress;
/// Текущее действие
@property NSString *title;
/// Дата и время последней синхронизации
@property NSString *lastSyncTime;
/// Флаг отображающий была ли когда-либо сделана синхронизация
@property BOOL isEverHappened;
/// Ошибка при синхронизации
@property (assign, nonatomic) IRSyncError error;
/// Закончена ли загрузка справочников (началась отправка фото / визитов / сцен и тп)
@property BOOL isCatalogsDownloadFinish;
/// Общее количество готовых к отправке, отправленных и распознанных фото.
@property long totalPhotosCount;
/// Количество отправленных фото.
@property long sentPhotosCount;
/// Количество распознанных фото.
@property long recognizedPhotosCount;
/// Количество фото с ошибкой.
@property long errorPhotosCount;
/// Количество нераспозанных визитов.
@property long notRecognizedVisitsCount;
/// Количество распозанных визитов.
@property long recognizedVisitsCount;
/// Количество распозанных визитов.
@property long totalVisitsCount;

- (BOOL)isPhotoSendCompleted;
@end

NS_ASSUME_NONNULL_END
