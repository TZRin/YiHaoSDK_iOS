//
//  YHYXBaseView.h
//  YHYX_GameFramework
//
//  Created by LS on 2020/12/22.
//  Copyright © 2020 LSYX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YHYXAtuoFillScreenUtils.h"
NS_ASSUME_NONNULL_BEGIN

@interface YHYXBaseView : UIView

@property (nonatomic ,strong) UIView *contentView;

- (void)initContentViewWithFrame:(CGRect)frame;

- (void)openKeyBoardManager:(CGFloat)content_bottom;

@end

NS_ASSUME_NONNULL_END
