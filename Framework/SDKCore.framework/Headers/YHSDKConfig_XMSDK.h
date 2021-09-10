//
//  YHSDKConfig_XMSDK.h
//  SDKCore
//
//  Created by 老同志 on 2021/9/10.
//

#import <Foundation/Foundation.h>
#import "YHSDKConfig.h"
#import <XMCommon/XMCommon.h>
#import <XMLog/XMLog.h>
#import <XMGame/XMGame.h>
 
@interface YHSDKConfig_XMSDK : YHSDKConfig

/// ====================================== XMCommon ======================================
/// 以下参数咨询相关产品负责⼈,必填
@property (copy, nonatomic)   NSString * APP_TypeId;

/// 测试正式环境区分(默认是正式环境)
@property (assign, nonatomic) XMSDKRunMode  sdkRunMode;

/// 设置log打印级别
@property (assign, nonatomic) XMSDKLogLevel logLevel;

/// 根据需要 禁⽌SDK主动请求IDFA权限，sdk默认主动访问idfa权限(iOS 14)
@property (assign, nonatomic) BOOL          allowFireIDFAAuth;

/// 实现 XMDynamicParamBridge 协议，可选实现。
@property (weak, nonatomic) id<XMDynamicParamBridge> XMDynamicParamBridgeDelegate;

/// ====================================== XMLog  ======================================
/// 是否启动XMLog相关功能
@property (assign, nonatomic) BOOL enableXMLog;

/// 按钮打点⽇志接⼝ (可选)
@property (copy, nonatomic) NSString * XM_clickLog_URL;

/// 覆盖SDK内部的归因平台(如果宿主有自己的归因数据 可以设置此值)
@property (copy, nonatomic) NSString * srcplat;

/// 覆盖SDK内部的归因渠道号(如果宿主有自己的归因数据 可以设置此值)
@property (copy, nonatomic) NSString * srcqid;

/// ====================================== XMGame  ======================================
/// 是否启动XMGame相关功能
@property (assign, nonatomic) BOOL enableXMGame;

@end
