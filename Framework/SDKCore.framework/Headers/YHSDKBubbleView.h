//
//  YHSDKBubbleView.h
//  SDKCore
//
//  Created by 老同志 on 2021/9/6.
//

#import <UIKit/UIKit.h>

#define YHSDKBubbleViewWidth 50.0f
#define YHSDKBubbleViewHeight 50.0f
#define YHSDKBubbleViewBottomSpace 70.0f
#define YHSDKBubbleViewRightSpace 0

typedef NS_OPTIONS(NSUInteger, YHSDKBubbleViewType) {
    YHSDKBubbleViewTypeNormal = 1 << 0,//仅悬浮
    YHSDKBubbleViewTypeSupportPortraitPan = 1 << 1,//支持竖屏滑动,暂不支持
    YHSDKBubbleViewTypeSupportLandscapePan = 1 << 2,//支持横屏滑动,暂不支持
    YHSDKBubbleViewTypeSupportPortraitSpringToBounds = 1 << 3, //支持竖屏弹至边框
    YHSDKBubbleViewTypeSupportLandscapeSpringToBounds = 1 << 4, //支持横屏弹至边框
};

@interface YHSDKBubbleView : UIView
 
@property (nonatomic, assign) YHSDKBubbleViewType floatType;

@property (nonatomic, copy) void(^clickAction)(void);

@property (assign, nonatomic) CGSize bubbleSize;

@property (assign, nonatomic) BOOL enableAutoCalSafeArea;

@property (assign, nonatomic) BOOL isHalfShow;
 
@end
