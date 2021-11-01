//
//  YHYXWXManager.h
//  YHYXGameFramework
//
//  Created by fankangpeng on 2021/4/12.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@interface YHYXWXManager : NSObject

+ (BOOL)registerApp:(YHYXGameConfigModel *)model;


+ (NSString *)wx_appkey;



/// 微信授权
+ (void)YHYX_WXAuth:(void(^)(NSDictionary *dict))complter;

/// 微信登录
+ (void)YHYX_WXLogin:(void(^)(NSDictionary *dict))complter;

/// 微信绑定
+ (void)YHYX_WXBind:(void(^)(NSDictionary *dict))complter;

///微信回调信息对外回调
+ (void)YHYX_WXMessage:(void(^)(id req, id resq))complter;

@end


@interface YHYXWXManager (Hook)
+ (void)loadHook;
@end


NS_ASSUME_NONNULL_END
