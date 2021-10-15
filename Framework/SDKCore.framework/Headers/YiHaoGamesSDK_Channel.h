//
//  YiHaoGamesSDK_Channel.h
//  SDKCore
//
//  Created by 老同志 on 2021/10/12.
//

#import <Foundation/Foundation.h>
#import <YHYXGameFramework/YHYXGameFramework.h>
#import "YHSDKPurchaseChannelOrder.h"

@interface YiHaoGamesSDK_Channel : NSObject

+ (YiHaoGamesSDK_Channel *_Nullable)sharedSDK;
 
// =====================================================================================
// ======================================一号游戏渠道=====================================
// =====================================================================================

/// 本聚合sdk的初始化
/// @param gameID 聚合sdk的gameid，请咨询项目负责人
/// @param channelID 聚合sdk的channelID，请咨询项目负责人
- (void)setupAggregateSDKWithGameID:(NSString *_Nonnull)gameID channelID:(NSString *_Nullable)channelID;

/// YHYX渠道的SDK初始化
/// @param configModel 配置model
/// @param gameDelegate 回调代理
- (void)YHYX_SetupWithConfig:(YHYXGameConfigModel *_Nullable)configModel gameDelegate:(nullable id<YHYXGameDelegate>)gameDelegate;

/// YHYX的登录，默认UI
/// 未登录时默认唤起登录UI，可通过YHYXGameConfigModel 配置
/// 已登录返回用户信息
/// 未登录:配置使用默认UI：唤起登录UI 、配置不使用默认UI：返回失败信息、需进行登录操作
/// @param complterHander 结果回调
- (void)YHYX_LoginViewComplterHander:(nullable void(^)(NSDictionary * _Nullable response))complterHander;

/// YHYX的一键登录，自定义UI
/// 取号完成一键登录
/// @param config 配置config
/// @param complterHander 结果回调
- (void)YHYX_SecretLoginWithConfig:(YHYXSecretLoginAuthCfg *_Nullable)config complterHander:(nullable void(^)(NSDictionary * _Nonnull response))complterHander;

/// YHYX的游客登录，自定义UI
/// @param complterHander 结果回调
- (void)YHYX_VisitorLoginViewComplterHander:(nullable void(^)(NSDictionary * _Nullable response))complterHander;

/// YHYX的手机号登录，自定义UI
/// @param phone 手机号(必填)
/// @param code 验证码(必填)
/// @param complterHander 结果回调
- (void)YHYX_ObtainPhoneLogin:(NSString * _Nonnull )phone code:(NSString *_Nonnull)code complterHander:(nullable void(^)(NSDictionary * _Nonnull response))complterHander;

/// YHYX的账号登录，自定义UI
/// @param account 账号(必填)
/// @param psd 密码(必填)
/// @param complterHander 结果回调
- (void)YHYX_ObtainAccountLogin:(NSString *_Nullable)account password:(NSString *_Nullable)psd complterHander:(nullable void(^)(NSDictionary * _Nonnull response))complterHander;

/// YHYX的苹果登录,仅支持iOS13以上
/// @param complterHander 结果回调
- (void)YHYX_AppleLogin:(nullable void(^)(NSDictionary * _Nonnull response))complterHander;

/// YHYX的微信登录
/// @param complterHander 结果回调
- (void)YHYX_WXLogin:(nullable void(^)(NSDictionary * _Nonnull response))complterHander;
 
/// YHYX的苹果内购（内购优先判断实名认证状态、未实名认证通过block返回code:-1010，认证中 code:159）
///  ！！！！！不能以SDK返回的状态作为支付的最终结果，支付的最终结果以服务端为准！！！！！
///  ！！！！！SDK的回调信息仅作为服务端订单查询参数的回调！！！！！！
/// productId                  // 商品id（必填）
/// orderFee                  // 订单金额（单位：分）（必填）
/// currencyType           // 币种（必填）
/// roleId                       // SDK提供的用户信息中的userGameId（必填、纯数字）
/// serverId                   // 游戏区服id（必填）
/// subject                     // 商品名称（必填）
/// gameOrderId           // 游戏订单id（必填）
/// extra                        // 透传参数
/// @param order 参数模型,通过[YHSDKPurchaseOrder new]创建
/// @param complterHander  结果回调
- (void)YHYX_FullWithDict:(YHSDKPurchaseChannelOrder *_Nonnull)order
           ComplterHander:(nullable void(^)(NSDictionary * _Nullable response))complterHander;

@end
