//
//  YHYXStringUtils.h
//  YHYX_GameFramework
//
//  Created by Apple on 2020/9/16.
//  Copyright © 2020 YHYX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YHYXStringUtils : NSObject



///检测字符串是否为空
+ (BOOL)YH_BlankString:(NSString *)string;

///手机正则
+ (BOOL)YH_CheckPhone:(NSString *)phone;

///账号正则 a-z0-9不能数字开头
+ (BOOL)YH_CheckAccount:(NSString *)account;

///密码正则
+ (BOOL)YH_CheckPassword:(NSString *)paw;

///身份证
+ (BOOL)YH_IDCardNumber:(NSString *)number;

///中文字符串
+ (BOOL)YH_CheckChinese:(NSString *)chinese;

///字典排序后转字符串
+ (NSString *)YH_StringWithDict:(NSMutableDictionary*)dict;

///随机数
+ (NSString *)YH_RandomNumber;

///获取当前时间戳
+(NSString *)YH_TimeTimestamp;

///获取当前日期时间
+ (NSString *)YH_CurrentTimes;

///获取设备名称
+ (NSString *)YH_IphoneName;

///系统版本号
+ (NSString *)YH_SystemVersion;

///获取设备型号
+ (NSString *)YH_DeviceModel;

/// 获取外部版本号
+ (NSString *)YH_AppVersion;


/// 获取外部build
+ (NSString *)YH_AppBuild;


+ (NSString *)jsonToString:(id)jsonObj;
+ (NSDictionary *)stringToJson:(NSString *)jsonStr;

@end

NS_ASSUME_NONNULL_END
