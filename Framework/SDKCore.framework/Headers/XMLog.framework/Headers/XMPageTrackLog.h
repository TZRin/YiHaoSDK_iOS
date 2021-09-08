//
//  XMPageTrackLog.h
//  XMLog
//
//  Created by 大大东 on 2021/4/2.
//  Copyright © 2021 大大东. All rights reserved.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface XMPageTrackLog : NSObject

/// 手动统计页面时长
/// @param pageId    页面id
/// @param extraInfo 额外信息
/// @param enterTime 页面开始展示时间戳
/// @param leaveTime 页面结束展示时间戳
+ (void)pageTrackPageId:(NSString *)pageId extraInfo:(nullable NSString *)extraInfo
              enterTime:(NSTimeInterval)enterTime
              leaveTime:(NSTimeInterval)leaveTime;
@end



@interface UIView (Analytics)

// 必选字段 只有这个字段不为nil 才会统计
@property (nonatomic, copy) NSString *pageId;
// 可选字段
@property (nonatomic, copy, nullable) NSString *extraInfo;

// 需要手动使用这两个方法,进行统计 (当页面出现/消失时)
- (void)trackViewDidShow;
- (void)trackViewDidDismiss;

@end



@interface UIViewController (Analytics)

// 当此字段为YES时 此页面将不会进行自动统计（一般禁掉某个页面的统计 或者 需要手动统计）
@property (nonatomic, assign) BOOL unableAutoTrack;

// 必选字段 只有这个字段不为nil 才会统计 （此字段请在viewDidAppear之前设置）
@property (nonatomic, copy  ) NSString *pageId;
// 可选字段
@property (nonatomic, copy, nullable) NSString *extraInfo;

// 使用这两个方法 可以手动触发页面的 出现/消失 进行统计
- (void)mTrackViewDidAppear;
- (void)mTrackViewDidDisappear;

@end



NS_ASSUME_NONNULL_END
