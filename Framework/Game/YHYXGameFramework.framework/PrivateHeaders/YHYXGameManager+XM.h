//
//  YHYXGameManager+XM.h
//  YHYXGameFramework
//
//  Created by fankangpeng on 2021/5/8.
//

#import "YHYXGameManager.h"


NS_ASSUME_NONNULL_BEGIN

@interface YHYXGameManager (XM)

+ (void)initXMWithModel:(YHYXGameConfigModel *)model runmode:(XMSDKRunMode)sdkrunmode;

@end

NS_ASSUME_NONNULL_END
