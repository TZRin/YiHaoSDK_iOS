//
//  XMClickLog.h
//  XMLog
//
//  Created by zhazhenwang on 2020/3/19.
//  Copyright © 2020 大大东. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XMClickLog : NSObject

/// 增加一条按钮打点日志
/// @param senderId    按钮id
/// @param description 可以是一个json字符串 便于增加自定义参数
+ (void)clickEvent:(NSString *)senderId description:(NSString *)description;

@end
