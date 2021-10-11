//
//  YHYXGameManager.h
//  YHYXGameFramework
//
//  Created by fankangpeng on 2021/5/8.
//

#import <Foundation/Foundation.h>



NS_ASSUME_NONNULL_BEGIN




@interface YHYXGameManager : NSObject

#pragma mark -- SDK初始化
/**初始化
 @param configModel 配置model
 @param gameDelegate 回调代理
 */
+ (void)YHYX_SetupWithConfig:(YHYXGameConfigModel *)configModel gameDelegate:(nullable id<YHYXGameDelegate>)gameDelegate;

#pragma mark -- 登录、用户信息
/**
 * 用户信息以及登录
 * 未登录时默认唤起登录UI，可通过YHYXGameConfigModel 配置
 * 已登录返回用户信息
 * 未登录:
 *       配置使用默认UI：唤起登录UI
 *       配置不使用默认UI：返回失败信息、需进行登录操作
 */
+ (void)YHYX_LoginViewComplterHander:(nullable void(^)(NSDictionary *response))complterHander;


/**游客登录*/
+ (void)YHYX_VisitorLoginViewComplterHander:(nullable void(^)(NSDictionary *response))complterHander;

/**手机号登录
 @param phone :手机号(必填)
 @param code :验证码(必填)
 */
+ (void)YHYX_ObtainPhoneLogin:(NSString *)phone
                         code:(NSString *)code
               complterHander:(nullable void(^)(NSDictionary *response))complterHander;
/**账号登录
 @param account :账号(必填)
 @param psd :密码(必填)
 */
+ (void)YHYX_ObtainAccountLogin:(NSString *)account
                     pasword:(NSString *)psd
                 complterHander:(nullable void(^)(NSDictionary *response))complterHander;

/**
 * 苹果登录接口
 * 仅支持iOS13以上
 */
+ (void)YHYX_AppleLogin:(nullable void(^)(NSDictionary *response))complterHander;

/**
 * 登出
 */
+ (void)YHYX_Logout:(nullable void(^)(NSDictionary *response))complterHander;

#pragma mark -- 自定义UI一键登录
/**预取号*/
+ (void)YHYX_SecretLoginPrePhoneNumber:(nullable void(^)(NSDictionary *response))complterHander;
/**取号完成一键登录*/
+ (void)YHYX_SecretLoginWithConfig:(YHYXSecretLoginAuthCfg *)config complterHander:(nullable void(^)(NSDictionary *response))complterHander;
/**获取当前运营商类型*/
+ (YHYXOperatorType)YHYX_GetOperatorType;
/**关闭授权页面*/
+ (void)YHYX_DismissLoginControllerWithAnimated:(BOOL)flag complterHander:(void (^)(void))complterHander;


#pragma mark -- 手机号绑定
/**绑定手机号&微信UI*/
+ (void)YHYX_BindPhoneUIComplterHander:(nullable void(^)(NSDictionary *response))complterHander;
/**绑定手机号接口*/
+ (void)YHYX_BindPhoneApi:(NSString *)phone code:(NSString *)code complterHander:(nullable void(^)(NSDictionary *response))complterHander;

#pragma mark -- 微信功能

/**
 * 微信绑定
 * 绑定成功回调用户信息
 */
+ (void)YHYX_WXBind:(nullable void(^)(NSDictionary *response))complterHander;

/**
 * 微信登录
 * 登录成功 回调用户信息
 */
+ (void)YHYX_WXLogin:(nullable void(^)(NSDictionary *response))complterHander;

/**
 * 微信授权
 * 授权成功 回调code
 */
+ (void)YHYX_WXAuthorization:(nullable void(^)(NSDictionary *response))complterHander;

/**
 *  微信回调信息对外回调
 *  当微信回调触发onReq时、YHYX_WXMessage回调信息返回req
 *  当微信回调触发onResp时，YHYX_WXMessage回调信息返回resq
 *  微信回调过程中可能会触发两次该回调，请根据回调信息具体处理
 */
+ (void)YHYX_WXMessage:(nullable void(^)(id req, id resq))complterHander;

#pragma mark 实名认证+防沉迷

/**
 * 实名认证状态
 */
+ (BOOL)YHYX_IsRealName;

/** 开启实名认证 --暂时无效 不用调用
 @param defaultUI 是否使用默认UI*/
//+ (void)YHYX_OpenCertificationFunction:(BOOL)defaultUI;

/**
 * 实名认证接口
 @param  name 姓名
 @param  idCard 身份证
 */
+ (void)YHYX_CertificationWithName:(NSString *)name
                            idCard:(NSString *)idCard
                    complterHander:(nullable void(^)(NSDictionary *response))complterHander;

/**
 * 实名认证UI
 */
+ (void)YHYX_CertificationWithComplterHander:(nullable void(^)(NSDictionary *response))complterHander;


#pragma mark -- 内购
 
/**
 * 苹果内购（内购优先判断实名认证状态、未实名认证通过block返回code:-1010，认证中 code:159）
 * ！！！！！不能以SDK返回的状态作为支付的最终结果，支付的最终结果以服务端为准！！！！！
 *         ！！！！！SDK的回调信息仅作为服务端订单查询参数的回调！！！！！！
 *  productId                   //商品id（必填）
 *  orderFee                    //订单金额（单位：分）（必填）
 *  currencyType                //币种（必填）
 *  roleId                      //SDK提供的用户信息中的userGameId（必填、纯数字）
 *  serverId                    //游戏区服id（必填）
 *  subject                     //商品名称（必填）
 *  gameOrderId                 //游戏订单id（必填）
 *  extra                       //必填（填写服务器充值成功的回调地址
 */
+ (void)YHYX_FullWithDict:(NSDictionary *)dict
           ComplterHander:(nullable void(^)(NSDictionary *response))complterHander;
/**开启验单 --
 * 请在登录成功后再验单，未登录不验单！！！
 * 验单前请先设置好YHYXGameDelegate，并实现验单回调的代理方法，不设置不验单！！！
 */
+ (void)YHYX_VerifyOrder;

/**
 * 充值记录
 * pagenum 页码
 */
+ (void)YHYX_RechargeData:(NSInteger)pagenum
           complterHander:(void(^)(NSDictionary *result))complterHander;


#pragma mark - 验证码

/**
 *   获取手机验证码接口
 *   phone      手机号（必传）
 *   type          验证码类型 { type:login  登录注册,      type:bindPhone 绑定手机号 } （按照不同的作用传入不同type）（必传）
 *   code        图形验证码数值（非必填）
 *   uuid         图形验证码id(由后台返回) （非必填）
 *   block      当block中code码返回102的时候，需要调用 "获取图片验证码"   的方法  （防刷）
 */
+ (void)YHYX_ObtainPhoneCode:(NSString *)phone
                     type:(NSString *)type
                     code:(NSString *)code
                     uuid:(NSString *)uuid
              complterHander:(void(^)(NSDictionary *result))complterHander;

/**
 * 获取图片验证码接口 （验证码发送太频繁有图片验证码进行验证，防刷）
 *
 * 发送图片验证码的方法，请调用 "获取手机验证码"  方法，（code 和 uuid需要填写上去）
 */
+ (void)YHYX_ObtainImageCodeBlock:(void(^)(NSDictionary *result))complterHander;


#pragma mark SDK版本
+ (NSString *)YHYX_SDKVersion;

@end

NS_ASSUME_NONNULL_END
