//
//  NSString+YHYXMD5.h
//  YHYX_GameFramework
//
//  Created by LS on 2020/10/10.
//  Copyright © 2020 YHYX. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (YHYXMD5)

///md5加密
- (NSString *)YH_MD5Str;

///base64解密
- (NSString *)YH_Base64String;

///返回字符串
- (NSString *)YH_IsBlankString:(NSString *)string;

//普通字符串转换为十六进制的。
- (NSString *)hexStringFromString;




@end

NS_ASSUME_NONNULL_END
