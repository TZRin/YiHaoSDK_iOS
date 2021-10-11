//
//  YHYXAESCipher.h
//  YHYXAESCipher
//
//  Created by Welkin Xie on 8/13/16.
//  Copyright © 2016 WelkinXie. All rights reserved.
//
//

#import <Foundation/Foundation.h>

NSString * YHYX_AESEncryptString(NSString *content);
NSString * YHYX_AESDecryptString(NSString *content);

NSData * YHYX_AESEncryptData(NSData *data, NSData *key);
NSData * YHYX_AESDecryptData(NSData *data, NSData *key);
