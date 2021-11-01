//
//  YHYXAtuoFillScreenUtils.h
//  YHYX_GameFramework
//
//  Created by Apple on 2020/9/17.
//  Copyright © 2020 YHYX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YHYXAtuoFillScreenUtils : NSObject

//单利
+ (instancetype)shareAtuoFull;

- (void)autoLayoutFillScreen:(UIView *)view;


@end

NS_ASSUME_NONNULL_END
