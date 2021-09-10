//
//  YiHaoGamesSDK.h
//  SDKCore
//
//  Created by 老同志 on 2021/8/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YHSDKOrderModel.h"
#import "YHSDKBubbleView.h"
#import "YHSDKConfig.h"

//YHSDKPurchaseResultWebPay说明
//用户去网页支付去了,需要配合checkPurchaseStatus接口完成流程
typedef enum YHSDKPurchaseResult {
    YHSDKPurchaseResultUnknown      = 0,//未知
    YHSDKPurchaseResultSuccess      = 1,
    YHSDKPurchaseResultFailure      = 2,
    YHSDKPurchaseResultPurchased    = 3,
    YHSDKPurchaseResultNotAuth      = 4,//用户没授权内购
    YHSDKPurchaseResultWebPay       = 5,//见上方说明
    YHSDKPurchaseResultNAProducts   = 6,//拉取苹果商品信息失败
    YHSDKPurchaseResultNOProducts   = 7 //没有找到对应商品
}YHSDKPurchaseResult;

typedef void (^YHSDKStartScreenCompleteBlock)(void);
typedef void (^YHSDKLoginCompleteBlock)(id userData);
typedef void (^YHSDKUserCenterClosedBlock)(void);
typedef void (^YHSDKUserInfoUpdatedBlock)(id userData);
typedef void (^YHSDKPurchaseResultBlock)(YHSDKPurchaseResult result,NSString *msg,YHSDKOrderModel * orderInfoModel);

@interface YiHaoGamesSDK : NSObject

+ (YiHaoGamesSDK *)sharedSDK;

/// 激活SDK
/// @param gameID  游戏id 咨询相关产品负责⼈
/// @param configs 待加载模块的配置
- (void)activationSDKWithGameID:(NSString *)gameID otherSDKConfig:(NSSet <YHSDKConfig *>*)configs;
 
/// 显示启动logo闪屏
/// @param time 持续时间,传入0为默认时间4秒
/// @param size logo大小 传入CGSizeZero显示默认大小
/// @param superview 你想在哪个view上显示
/// @param completeBlock 完成时回调,会覆盖上次传入的block
- (void)showStartScreen:(float)time logoSize:(CGSize)size superview:(UIView *)superview complete:(YHSDKStartScreenCompleteBlock)completeBlock;

/// 获取悬浮窗
/// @param superview  在哪个view上展示
/// @param size  悬浮窗大小
/// @param flag  是否开启自动算入safeArea,开启后刘海屏横屏模式下会算入safeArea的值,如果您传入的是uiwindow,建议启用
- (YHSDKBubbleView *)showBubbleViewOnSuperview:(UIView *)superview bubbleSize:(CGSize)size enableAutoCalSafeArea:(BOOL)flag;

/// 展示登录view
/// @param superview  你想在哪个view上显示
/// @param completeBlock 登录成功返回json,会覆盖上次传入的block
- (void)showLoginOnSuperview:(UIView *)superview complete:(YHSDKLoginCompleteBlock)completeBlock;

/// 展示用户中心
/// @param superview 你想在哪个view上显示
/// @param closedBlock 关闭回调,会覆盖上次传入的block
/// @param updatedBlock  用户信息更新回调,会覆盖上次传入的block,如果回调给您的值为nil，则说明用户信息登出
- (void)showUserCenterOnSuperview:(UIView *)superview onClosed:(YHSDKUserCenterClosedBlock)closedBlock onUpdated:(YHSDKLoginCompleteBlock)updatedBlock;

/// 退出登录
- (void)logout;

/// 创建支付
/// @param model 参数模型
/// @param completeBlock 结果回调
- (void)purchaseWithModel:(YHSDKOrderModel *)model complete:(YHSDKPurchaseResultBlock)completeBlock;

/// 检测支付是否完成
/// 例如，包含：已完成支付，支付遇到问题，等功能的按钮。
/// 用户点击已完成支付，ios开发人员调用本函数检查是否完成支付
/// 如果在web支付的流程，app跳至浏览器之前，需要开发人员在本身app中显示提示页面
/// @param model 待检测的参数模型
/// @param resultBlock 结果回调
- (void)checkPurchaseStatusWithModel:(YHSDKOrderModel *)model result:(YHSDKPurchaseResultBlock)resultBlock;
 

@end
