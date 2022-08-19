//
//  IrSettingsExtended.h
//  IntelligenceRetail
//
//  Created by Vsevolod Didkovskiy on 31/07/2019.
//  Copyright © 2019 Intelligence Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IrSettingsExtended : NSObject
@property int showQualityInfo;
@property long setSceneType;
@property int showOnlyUserBrands;
@property int showReportPrepearingInfo;
@property int showShelvesLines;
@property int showPreviousPhotoInPanorama;
@property int compression;
@property int doubleCompression;
@property int maxPhotoHeight;
@property int maxPhotoWidth;
@property int maxResolution;
@property int maxVisits;
@property bool isInfinityBackground;
@property bool isAutoPhotoTestEnabled;

@end

NS_ASSUME_NONNULL_END
