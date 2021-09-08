//
//  XMGameAntiAddiction.h
//  XMGame
//
//  Created by 大大东 on 2021/3/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, XMGMRealNameState) {
    XMGMRealNameStateError = -1, // error
    XMGMRealNameStateNO    =  1, // 未认证
    XMGMRealNameStateVerifiing,// 认证中
    XMGMRealNameStateTeen,     // 已认证-未成年
    XMGMRealNameStateAdult,    // 已认证-成年
    XMGMRealNameStateFailure,  // 认证失败 
};
typedef NS_ENUM(NSInteger, XMGMOverTime) {
    XMGMOverTimeTrigger = 1,          // 触发防沉迷状态
    XMGMOverTimeNomal,                // 正常状态
    XMGMOverTimeWithTeenOnSpecailTime,// 未成年人 & 在不可玩游戏时间 (法规:每日22时至次日8时,不得为未成年人提供游戏服务)
    XMGMOverTimeWithNotVerifyAndOnSpecailTime,// 未认证用户 & 在不可玩游戏时间 (法规:每日22时至次日8时,不得为未成年人提供游戏服务)
};


@interface XMGameAntiAddictionExtraInfo : NSObject
/// 当前账号今日在线总时长 (毫秒)
@property (nonatomic, copy) NSString *onlineTime;

/// 当前账号实名认证状态下 法规允许今日的在线总时长 (毫秒)
@property (nonatomic, copy) NSString *totalTime;
@end



@class XMGameAntiAddiction;
@protocol XMGameAntiAddictionDelegate <NSObject>
@required
/// 回调
/// @param result  实名认证的结果
/// @param overt   防沉迷状态
/// @param info    其他信息
- (void)xm_responseWithStatus:(XMGMRealNameState)result overTime:(XMGMOverTime)overt extraInfo:(XMGameAntiAddictionExtraInfo *)info;

@end



@interface XMGameAntiAddiction : NSObject


/// 结果回调代理
@property (nonatomic, weak, class) id<XMGameAntiAddictionDelegate> delegate;

/// 用户已经登录
/// @param userid   当前用户唯一id
/// @param platid   平台id( 没有可不传 )
+ (void)userDidLogin:(NSString *)userid platid:(nullable NSString *)platid;

/// 当前用户id
+ (nullable NSString *)currentUserID;

/// 用户退出登录
+ (void)userDidLogout;


/// 请求实名认证
/// @param realName 真实姓名
/// @param idinmber 身份证号
/// @param completion 回调(if error != nil, please ignore result)
+ (void)verifyWithRealName:(NSString *)realName
                  idNumber:(NSString *)idinmber
                completion:(void(^)(NSError * _Nullable error, XMGMRealNameState result))completion;
@end

NS_ASSUME_NONNULL_END
