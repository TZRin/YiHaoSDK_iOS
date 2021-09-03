//
//  YHSDKUser.h
//  SDKCore
//
//  Created by 老同志 on 2021/8/24.
//

#import <Foundation/Foundation.h>
 
@interface YHSDKUser : NSObject

//1是 0否

@property (copy, nonatomic) NSString * phone;
@property (copy, nonatomic) NSString * account;
@property (copy, nonatomic) NSString * password;
@property (copy, nonatomic) NSString * token;

/// 是否要强制实名 1是 0否
@property (copy, nonatomic) NSString * is_force_idcard;

/// 是否弹出实名认证界面 1是 0否
@property (copy, nonatomic) NSString * show_idcard;

/// 是否实名认证，0标识没有实名认证，1已经实名认证
@property (copy, nonatomic) NSString * is_idcard;
@property (copy, nonatomic) NSString * idcard_num;
@property (copy, nonatomic) NSString * idcard_name;
 
/// 是否弹出绑定手机界面 1是 0否
@property (copy, nonatomic) NSString * show_bindphone;

/// 是否完成login流程
@property (assign, nonatomic) BOOL loginCompleted;

/// 原始json返回数据,不是最新
@property (strong, nonatomic) id oriData;

@property (copy, nonatomic) NSString * user_id;
@property (copy, nonatomic) NSString * time;
@property (copy, nonatomic) NSString * sign;
@property (copy, nonatomic) NSString * user_code;
@property (copy, nonatomic) NSString * float_url;
@property (copy, nonatomic) NSString * float_show_now;
@property (copy, nonatomic) NSString * is_reg;

/// 是否弹出游客密码信息 1是 0否
@property (copy, nonatomic) NSString * show_userinfo;

/// 是否弹出验证身份证
@property (copy, nonatomic) NSString * show_check_idcard;

@end 
