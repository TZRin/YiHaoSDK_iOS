//
//  YHSDKUser.h
//  SDKCore
//
//  Created by 老同志 on 2021/8/24.
//

#import <Foundation/Foundation.h>
 
@interface YHSDKUser : NSObject
 
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
 
@property (copy, nonatomic) NSString * user_id;
@property (copy, nonatomic) NSString * time;
@property (copy, nonatomic) NSString * sign;
@property (copy, nonatomic) NSString * user_code;
@property (copy, nonatomic) NSString * float_url;
@property (copy, nonatomic) NSString * float_show_now;
@property (copy, nonatomic) NSString * is_reg;

/// 是否悬浮窗展示
@property (copy, nonatomic) NSString * is_show_float;

/// 是否弹出游客密码信息 1是 0否
@property (copy, nonatomic) NSString * show_userinfo;

/// 是否弹出验证身份证
@property (copy, nonatomic) NSString * show_check_idcard;

/// 本地记录的登录时间戳
@property (copy, nonatomic) NSString * loginTS;

/// "是否开启心跳：0不开启，1开启"
@property (copy, nonatomic) NSString * is_open_heartbeat;

/// 每次心跳相隔多少秒
@property (copy, nonatomic) NSString * heartbeat_sec;

/// 实名完成后是否弹
@property (copy, nonatomic) NSString * is_open_win;

/// 实名完成后弹窗的话显示的文本
@property (copy, nonatomic) NSString * open_win_msg;

/// 实名完成后弹窗的话,点击弹窗的确认是否登出
@property (copy, nonatomic) NSString * open_win_is_logout;

@end 
