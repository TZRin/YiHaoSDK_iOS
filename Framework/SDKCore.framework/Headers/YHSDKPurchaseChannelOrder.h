//
//  YHSDKChannelOrder.h
//  SDKCore
//
//  Created by 老同志 on 2021/10/12.
//

#import <Foundation/Foundation.h>

/// 渠道订单
@interface YHSDKPurchaseChannelOrder : NSObject

/// 渠道用户唯一标识
@property (copy, nonatomic) NSString * channel_openid;

/// 商品id
@property (copy, nonatomic) NSString * goods_id;

/// 商品名称
@property (copy, nonatomic) NSString * goods_name;

/// 金额（元）
@property (copy, nonatomic) NSString * amount;

/// CP方订单号
@property (copy, nonatomic) NSString * game_trade_no;

/// 服务器id
@property (copy, nonatomic) NSString * server_id;

/// 服务器名称
@property (copy, nonatomic) NSString * server_name;

/// 游戏角色唯一id
@property (copy, nonatomic) NSString * role_id;

/// 游戏角色昵称
@property (copy, nonatomic) NSString * role_name;

/// 角色等级
@property (copy, nonatomic) NSString * role_level;

/// userGameId,登录返回的openid
@property (copy, nonatomic) NSString * userGameId;

/// 透传json
@property (copy, nonatomic) NSString * userInfo;

@end
