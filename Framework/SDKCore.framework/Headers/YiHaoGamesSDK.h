//
//  YiHaoGamesSDK.h
//  SDKCore
//
//  Created by 老同志 on 2021/8/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YHSDKPurchaseOrder.h"
#import "YHSDKBubbleView.h"
#import "YHSDKConfig.h"
#import "YHSDKReportInfo.h"

typedef enum YHSDKAntiAddictionResult {
    YHSDKAntiAddictionResultBlocked     = 0,//不能玩了
    YHSDKAntiAddictionResultPassed      = 1,//可以玩
    YHSDKAntiAddictionResultForceLogout = 2 //强制登出
}YHSDKAntiAddictionResult;

typedef enum YHSDKReportType {
    YHSDKReportTypePlaceHolder        = 0,
    YHSDKReportTypeCreateRole         = 1,//创建角色上报
    YHSDKReportTypeRoleLogin          = 2,//角色登陆成功上报
    YHSDKReportTypeRoleLogout         = 3 //角色成功登出上报
}YHSDKReportType;

//YHSDKPurchaseResultWYPay说明 需要配合checkPurchaseStatus接口完成流程
typedef enum YHSDKPurchaseResult {
    YHSDKPurchaseResultUnknown      = 0,//未知
    YHSDKPurchaseResultSuccess      = 1,//成功
    YHSDKPurchaseResultFailure      = 2,//失败
    YHSDKPurchaseResultPurchased    = 3,//已经购买过了
    YHSDKPurchaseResultNotAuth      = 4,//用户没授权内购
    YHSDKPurchaseResultWYPay        = 5,//见上方说明
    YHSDKPurchaseResultNAProducts   = 6,//拉取苹果商品信息失败
    YHSDKPurchaseResultNOProducts   = 7,//没有找到对应商品
    YHSDKPurchaseResultNeedRetry    = 8 //有订单没处理完，需要等待其处理完毕后重试购买
}YHSDKPurchaseResult;

typedef void (^YHSDKScreenCompleteBlock)(void);
typedef void (^YHSDKLoginCompleteBlock)(NSMutableDictionary * userData);
typedef void (^YHSDKUserCenterClosedBlock)(void);
typedef void (^YHSDKUserInfoUpdatedBlock)(NSMutableDictionary * userData);
typedef void (^YHSDKPurchaseResultBlock)(YHSDKPurchaseResult result,NSString *msg,YHSDKPurchaseOrder * order);
typedef void (^YHSDKPurchaseValidateResultBlock)(YHSDKPurchaseResult result,NSString *msg,YHSDKPurchaseOrder * order);
typedef void (^YHSDKAntiAddictionResultBlock)(YHSDKAntiAddictionResult result,NSString *account);
typedef void (^YHSDKPurchaseObserveBlock)(YHSDKPurchaseOrder * order);

@interface YiHaoGamesSDK : NSObject

+ (YiHaoGamesSDK *)sharedSDK;

// =====================================================================================
// =======================================系统配置=======================================
// =====================================================================================

/// 激活SDK
/// @param gameID  游戏id 咨询相关产品负责⼈
/// @param configs 待加载模块的配置
- (void)activationSDKWithGameID:(NSString *)gameID otherSDKConfig:(NSSet <YHSDKConfig *>*)configs;
 
/// 显示启动logo页面
/// @param time 持续时间,传入0为默认时间4秒
/// @param size logo大小 传入CGSizeZero显示默认大小
/// @param superview 你想在哪个view上显示
/// @param completeBlock 完成时回调,会覆盖上次传入的block
/// @param animate 是否动画
- (void)showStartScreen:(float)time logoSize:(CGSize)size superview:(UIView *)superview animate:(BOOL)animate complete:(YHSDKScreenCompleteBlock)completeBlock;

/// 创建一个悬浮窗
/// @param  superview  在哪个view上展示
/// @param  size  悬浮窗大小
/// @param  flag  是否开启自动算入safeArea,开启后刘海屏横屏模式下会算入safeArea的值,如果您传入的是uiwindow,建议启用
/// @param  removeOnLogout 当调用退出登录时,会自动移除掉
/// @return 悬浮窗对象
- (YHSDKBubbleView *)showBubbleViewOnSuperview:(UIView *)superview bubbleSize:(CGSize)size enableAutoCalSafeArea:(BOOL)flag removeOnLogout:(BOOL)removeOnLogout;

/// 禁用sdk支付模块api中的hud
@property (assign, nonatomic) BOOL disableSDKHUD;

/// 显示健康游戏忠告
/// @param time 持续时间,传入0为默认时间4秒
/// @param superview 你想在哪个view上显示
/// @param completeBlock 完成时回调,会覆盖上次传入的block
/// @param animate 是否动画
- (void)showAdviceScreen:(float)time superview:(UIView *)superview animate:(BOOL)animate complete:(YHSDKScreenCompleteBlock)completeBlock;

/// 上报信息,如角色成功登陆/登出/创建等，只传递当前类型您有且能与参数模型对应的数据，其余数据字段可不传
/// @param info 数据模型
/// @param type 上报类型
- (void)uploadPlayerInfo:(YHSDKReportInfo *)info type:(YHSDKReportType)type;


// =====================================================================================
// =======================================登录注册=======================================
// =====================================================================================

/// 展示登录view
/// @param superview  你想在哪个view上显示
/// @param completeBlock 登录成功返回json,回调后将会被置空
- (void)showLoginOnSuperview:(UIView *)superview complete:(YHSDKLoginCompleteBlock)completeBlock;

/// 展示用户中心
/// @param superview 你想在哪个view上显示
/// @param closedBlock 关闭回调,回调后将会被置空
/// @param updatedBlock  用户信息更新回调,如果回调给您的值为nil，则说明用户信息登出
- (void)showUserCenterOnSuperview:(UIView *)superview onClosed:(YHSDKUserCenterClosedBlock)closedBlock onUpdated:(YHSDKLoginCompleteBlock)updatedBlock;

/// 退出登录
- (void)logout;

/// 检测防沉迷状态
/// @param resultBlock 结果回调
- (void)listenAntiAddictionDetectionWithBlock:(YHSDKAntiAddictionResultBlock)resultBlock;

// =====================================================================================
// =========================================支付=========================================
// =====================================================================================

/// 创建支付
/// @param order 参数模型
/// @param completeBlock 结果回调
- (void)purchaseOrder:(YHSDKPurchaseOrder *)order complete:(YHSDKPurchaseResultBlock)completeBlock;

/// 检测支付是否完成
/// 例如，WY包含：已完成支付，支付遇到问题，等功能的按钮。
/// 用户点击已完成支付，iOS开发人员调用本方法检查是否完成支付
/// 如果在WY支付的流程，app至WY之前，需要开发人员在本身app中显示提示页面
/// @param order 待检测的参数模型,需要填写our_tradeNO字段值
/// @param resultBlock 结果回调
- (void)validatePurchaseOrderStatus:(YHSDKPurchaseOrder *)order result:(YHSDKPurchaseValidateResultBlock)resultBlock;

/// 若您使用了支付模块,请您在激活SDK后注册该回调,用于第一时间接收数据
/// 监听已通过验证的订单,可能存在一种已支付但尚未发货的订单,此时需要客户端手动验证该订单是否发货
/// 若未发货,需要进行发货操作
/// @param block 订单回调
- (void)observePurchasedOrder:(YHSDKPurchaseObserveBlock)block;
 
@end
