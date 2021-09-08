//
//  XMLogManager.h
//  XMLog
//
//  Created by 大大东 on 2019/12/9.
//  Copyright © 2019 大大东. All rights reserved.
//



#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface XMLogConfig : NSObject

/// <option>
/// 按钮打点日志批量上报URL, 如果使用了XMClickLog, 则必传此参数
@property (nonatomic, copy) NSString *XM_clickLog_URL;
@end


@interface XMLogManager : NSObject

// 初始化请在 didFinishLaunchingWithOptions: 方法内部初始化SDK  否则可能出现日志遗漏
+ (void)setupCommonlog:(XMLogConfig * _Nullable)config;

/// 配置对象
@property (nonatomic, strong, readonly) XMLogConfig *config;

/// log实例
@property (nonatomic, strong, readonly, class) XMLogManager *log;

/// 版本号
+ (NSString *)sdkVersion;


// open日志中的字段
// 需要在-didBecomeActive后尽快赋值，SDK会在1s后取值 并且进行上报
+ (void)resetWakeWay:(nullable NSString *)way;



/// 覆盖SDK内部的归因信息(如果宿主有自己的归因数据 可以使用此方法)
/// @param srcplat 归因平台
/// @param srcqid  归因渠道号
+ (void)updateSRCInfo:(NSString *)srcplat srcqid:(NSString *)srcqid;

@end




@interface XMLogManager (CK_Spec)

/// 手动调用open日志上报 (openWay : 冷启动0 热启动1)
+ (void)manual_openLogReport:(int)openWay;

/// 手动调用安装或者更新日志（内部已经区分是安装还是更新）,接口见文档：http://xmjs-apidev.tt.cn/index.do#/interface/detail?projectId=156138572590307000026&id=156154377853912000071
/// patchReport是否是补报回传，例如首次获取不到ua，等到获取到ua时。再次上报安装日志,默认是false
/// 接入方自己做idfa、ua、shumei回传机制，接入方自己做是否上传成功的标记
+ (void)manual_installLogReport:(NSString *)isReturn patchReport:(BOOL)patchReport complete:(nullable void (^)(BOOL success))complete;
@end

NS_ASSUME_NONNULL_END
