//
//  IrButtonsState.h
//  IntelligenceRetail
//
//  Created by Vsevolod Didkovskiy on 29/07/2019.
//  Copyright © 2019 Intelligence Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IrButton.h"

NS_ASSUME_NONNULL_BEGIN

@interface IrButtonsState : NSObject
@property IrButton *btStores;
@property IrButton *btTakePhoto;
@property IrButton *btFinishVisit;
@property IrButton *btEditForm;
@property IrButton *btMatrix;
@property IrButton *btSummaryReport;
@property IrButton *syncButton;
//@property IrButton *content;
//@property IrButton *contentTitle;

@end

NS_ASSUME_NONNULL_END
