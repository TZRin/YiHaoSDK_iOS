//
//  YHSDKReportInfo.h
//  SDKCore
//
//  Created by 凌天子 on 2021/10/3.
//

#import <Foundation/Foundation.h>
 
@interface YHSDKReportInfo : NSObject
 
/// 用户登录票据
@property (copy, nonatomic) NSString * token;

/// 用户唯一ID
@property (copy, nonatomic) NSString * user_id;

/// 区服ID
@property (copy, nonatomic) NSString * server_id;

/// 区服名称
@property (copy, nonatomic) NSString * server_name;

/// 角色ID
@property (copy, nonatomic) NSString * role_id;

/// 角色名称
@property (copy, nonatomic) NSString * role_name;

/// 角色等级
@property (copy, nonatomic) NSString * role_level;
 
/// 创角时间
@property (copy, nonatomic) NSString * create_time;
 
/// 登陆时间戳
@property (copy, nonatomic) NSString * login_time;

/// 登出时间戳
@property (copy, nonatomic) NSString * logout_time;

/// 在线时长 秒
@property (copy, nonatomic) NSString * online_time;

@end
 
