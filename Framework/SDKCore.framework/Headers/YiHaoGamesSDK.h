//
//  YiHaoGamesSDK.h
//  SDKCore
//
//  Created by 老同志 on 2021/8/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void (^YHSDKStartScreenCompleteBlock)(void);
typedef void (^YHSDKLoginCompleteBlock)(id userData);
typedef void (^YHSDKUserCenterClosedBlock)(void);
typedef void (^YHSDKUserInfoUpdatedBlock)(id userData);

@interface YiHaoGamesSDK : NSObject

+ (YiHaoGamesSDK *)sharedSDK;

/// 显示启动logo闪屏
/// @param time 持续时间,传入0为默认时间4秒
/// @param size logo大小 传入CGSizeZero显示默认大小
/// @param superview 你想在哪个view上显示
/// @param completeBlock 完成时回调,覆盖注册
- (void)showStartScreen:(float)time logoSize:(CGSize)size superview:(UIView *)superview complete:(YHSDKStartScreenCompleteBlock)completeBlock;

/// 展示登录view
/// @param superview  你想在哪个view上显示
/// @param completeBlock 登录成功返回json,覆盖注册
- (void)showLoginOnSuperview:(UIView *)superview complete:(YHSDKLoginCompleteBlock)completeBlock;


/// 展示用户中心
/// @param superview 你想在哪个view上显示
/// @param closedBlock 关闭回调,覆盖注册
/// @param updatedBlock  用户信息更新回调,覆盖注册,如果回调值为nil，则说明用户登出
- (void)showUserCenterOnSuperview:(UIView *)superview onClosed:(YHSDKUserCenterClosedBlock)closedBlock onUpdated:(YHSDKLoginCompleteBlock)updatedBlock;


/// 清除本地用户数据,下次不再自动登录
- (void)clearLocalUserData;
  
@end
