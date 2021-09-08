//
//  XMActivityLog.h
//  XMLog
//
//  Created by 大大东 on 2019/12/4.
//  Copyright © 2019 大大东. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@class XMActivityLogParam;

typedef XMActivityLogParam * _Nonnull (^ActLogParamBlock)(NSString *param);
typedef XMActivityLogParam * _Nonnull (^ActLogBlock)(void);


@interface XMActivityLogParam : NSObject

@property (nonatomic, copy, readonly) NSString *kactentryId;
@property (nonatomic, copy, readonly) NSString *kactId;
@property (nonatomic, copy, readonly) NSString *ksubActId;
@property (nonatomic, copy, readonly) NSString *kmaterialId;
@property (nonatomic, copy, readonly) NSString *ktype;
@property (nonatomic, copy, readonly) NSString *kentryType;

/**< 活动入口id，保证唯一性, 一般由产品给定*/
@property (nonatomic, strong, readonly) ActLogParamBlock ac_actentryId;
/**< 活动id，保证唯一性 名称, 如不给定，则使用对应活动id */
@property (nonatomic, strong, readonly) ActLogParamBlock ac_actId;
/**< 素材id，保证唯一性 一般填活动图片URL或者nil */
@property (nonatomic, strong, readonly) ActLogParamBlock ac_materialId;
//
@property (nonatomic, strong, readonly) ActLogParamBlock ac_subActId;
    
/**<  根据点击处类型传上边固定字段 */
@property (nonatomic, strong, readonly) ActLogBlock ac_type_show;
@property (nonatomic, strong, readonly) ActLogBlock ac_type_click;
@property (nonatomic, strong, readonly) ActLogBlock ac_type_close;
/**主要活动类型分为入口、页面、分享、活动内点击**/
@property (nonatomic, strong, readonly) ActLogBlock ac_entryType_page;
@property (nonatomic, strong, readonly) ActLogBlock ac_entryType_entry;
@property (nonatomic, strong, readonly) ActLogBlock ac_entryType_share;
@property (nonatomic, strong, readonly) ActLogBlock ac_entryType_actclick;



// 最后调用这个 记录/上报 日志
@property (nonatomic, strong, readonly) void(^fire)(void);
@end




@interface XMActivityLog : NSObject

/*
    实时上报
    格式为 XMActivityLog.param. **** .fire()
    例: XMActivityLog.param.ac_type_show().ac_entryType_page().ac_actentryId(@"").ac_actId(@"").ac_subActId(@"").ac_materialId(@"").fire();
 */
@property (nonatomic, readonly, class) XMActivityLogParam *param;

@end

NS_ASSUME_NONNULL_END
