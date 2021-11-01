//
//  YHYXGameConfigModel.h
//  YHYXGameFramework
//
//  Created by fankangpeng on 2021/5/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
// 日志等级
typedef NS_ENUM(NSInteger, YHYXSDKLogLevel) {
    YHYXSDKLogLevelAll,
    YHYXSDKLogLevelError,
    YHYXSDKLogLevelNone
};
// 当前网络类型
typedef NS_ENUM(NSUInteger, YHYXOperatorType) {
    None,//未知
    CMobile,//移动
    CTelecom,//电信
    CUnicom,//联通
    CRailcom,//铁通
};
typedef NS_ENUM(NSInteger, YHYXSDKRunMode) {
    YHYXSDKRunModeRelease = 0,
    YHYXSDKRunModeTest   = -999,  // URL改为测试环境
};



@interface YHYXGameConfigModel : NSObject
///游戏ID
@property (nonatomic ,copy) NSString * _Nullable gameId;
///渠道ID
@property (nonatomic ,copy) NSString * _Nullable channelId;
///游戏key
@property (nonatomic ,copy) NSString * _Nullable gameKey;

///微信Appid
@property (nonatomic ,copy) NSString * _Nullable wxAppId;
///微信AppSecret
@property (nonatomic ,copy) NSString * _Nullable wxAppSecret;
///微信Link
@property (nonatomic ,copy) NSString * _Nullable wxLink;
///XMLog APP_TypeId
@property (nonatomic ,copy) NSString * _Nullable xmAppTypeId;
///XMLog XM_clickLog_URL(可选)
@property (nonatomic ,copy) NSString * _Nullable xmClickLogURL;
/// 是否允许SDK初始化时请求IDFA权限(defult YES)(请设置Privacy - Tracking Usage Description)
@property (nonatomic, assign) BOOL allowFireIDFAAuth;
/// 是否使用SDK默认登录注册UI(defult YES)
@property (nonatomic, assign) BOOL userDefauleLoginUI;
///默认UI上是否使用微信登录(default YES)
@property (nonatomic, assign) BOOL defaultLoginUIUseWX;
///默认UI上是否使用Apple登录(default YES)
@property (nonatomic, assign) BOOL defaultLoginUIUseApple;

///默认UI上是否使用账号登录(default YES)
@property (nonatomic, assign) BOOL defaultLoginUIUseAccount;
///默认UI上是否使用微信绑定(default YES)
@property (nonatomic, assign) BOOL defaultBindUIUseWX;

/// development mode default YHYXSDKLogLevelNone
@property (nonatomic, assign) YHYXSDKLogLevel logLevel;
///SDK环境设置  默认正式环境
@property (nonatomic, assign) YHYXSDKRunMode sdkrunMode;


///是否使用一键登录(default YES)
@property (nonatomic, assign) BOOL defaultUseSecretLogin;
///是否使用一键登录默认UI(default YES)
@property (nonatomic, assign) BOOL defaultUseSecretLoginUI;
/// 一键登录的UI配置默认中部弹窗
@property (nonatomic ,strong) YHYXSecretLoginAuthCfg *secretLoginAuthCfg;

/// 游戏scheme配置，用于支付返回
@property (nonatomic, copy) NSString *gameScheme;

@end


@protocol YHYXGameDelegate <NSObject>
@optional
/* * 防沉迷状态代理-->自定义实名认证UI时被调用*/
- (void)YHYX_IndulgeDelegate:(XMGMRealNameState)realNameState overtime:(XMGMOverTime)overtime extraInfo:(XMGameAntiAddictionExtraInfo *)extraInfo;

/* 默认UI防沉迷 宵禁状态下 退出游戏代理，收到通知可执行退出游戏操作 --->默认实名认证UI 被调用*/
- (void)YHYX_AntiAddictionQuitGame:(XMGMRealNameState)realNameState overtime:(XMGMOverTime)overtime extraInfo:(XMGameAntiAddictionExtraInfo *)extraInfo;;

/**补单代理*/
- (void)YHYX_IAP_RepairOrderDelegate:(NSDictionary *)repairOrderInfo;

@end

NS_ASSUME_NONNULL_END
