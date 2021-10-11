//
//  YHYXHeaderTool.h
//  YHYX_GameFramework
//
//  Created by Apple on 2020/9/15.
//  Copyright © 2020 YHYX. All rights reserved.
//

#ifndef YHYXHeaderTool_h

#define YHYXHeaderTool_h





//define this constant if you want to use Masonry without the 'mas_' prefix
#define MAS_SHORTHAND

//define this constant if you want to enable auto-boxing for default syntax
#define MAS_SHORTHAND_GLOBALS


#define LSGAMEID     @"LSGameid"
#define LSCHANNELID  @"LSChannelId"
#define LSGAMEKEY    @"LSGameKey"

#define YH_BLOCK_EXEC(block, ...) if (block) { block(__VA_ARGS__); };


#define YH_ScreenWidth  [[UIScreen mainScreen] bounds].size.width
#define YH_ScreenHeight [[UIScreen mainScreen] bounds].size.height

#define YHYX_ISVERTICAL_SCREEN [UIApplication sharedApplication].statusBarOrientation == UIInterfaceOrientationPortrait || [UIApplication sharedApplication].statusBarOrientation == UIInterfaceOrientationPortraitUpsideDown
#define YHYX_ISIPHONEX (YH_ScreenWidth/YH_ScreenHeight < 0.5) || (YH_ScreenWidth/YH_ScreenHeight > 2.0)
#define YH_NAV_HEIGHT (YHYX_ISVERTICAL_SCREEN ? ((YHYX_ISIPHONEX ? 88 : 64)) : 64)
#define YHYX_STATUS_HEIGHT YHYX_ISIPHONEX ? 44 : 20



#define YH_IS_IPHONE           (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define YH_IS_IPHONE_4         (YH_IS_IPHONE && YH_SCREEN_MAX_LENGTH == 480.0)
#define YH_IS_IPHONE_SE        (YH_IS_IPHONE && YH_SCREEN_MAX_LENGTH == 568.0)
#define YH_IS_IPHONE_8         (YH_IS_IPHONE && YH_SCREEN_MAX_LENGTH == 667.0)
#define YH_IS_IPHONE_8P        (YH_IS_IPHONE && YH_SCREEN_MAX_LENGTH == 736.0)
#define YH_IS_IPHONE_XS        (YH_IS_IPHONE && YH_SCREEN_MAX_LENGTH == 812.0)
#define YH_IS_IPHONE_XRMAX     (YH_IS_IPHONE && YH_SCREEN_MAX_LENGTH == 896.0)

#define YH_IS_IPHONE_12MINI    (YH_IS_IPHONE && YH_SCREEN_MAX_LENGTH == 780.0)
#define YH_IS_IPHONE_12PRO     (YH_IS_IPHONE && YH_SCREEN_MAX_LENGTH == 844.0)
#define YH_IS_IPHONE_12MAX     (YH_IS_IPHONE && YH_SCREEN_MAX_LENGTH == 926.0)




#define YH_SCREEN_MAX_LENGTH   (MAX(YH_ScreenWidth, YH_ScreenHeight))

///头部未选中字体颜色
#define YHYXCOLOLR_TOPUNCHECK YH_UIColorRGB(0x666666)
///头部选中下划线颜色
#define YHYXCOLOLR_TOPLINE YH_UIColorRGB(0x222222)
///登录按钮颜色不能点击状态
#define YHYXCOLOLR_LOGIN YH_UIColorRGB(0xD1D1D1)
///登录按钮颜色能点击状态
#define YHYXCOLOLR_LOGIN_CLICK YH_UIColorRGB(0xFF7900)

///手机号码
#define YHYXCOLOLR_PHONE YH_UIColorRGB(0x002222)
///登录框下面的横线
#define YHYXCOLOLR_LINE YH_UIColorRGB(0xE6E6E6)
///验证码框颜色
#define YHYXCOLOLR_CODEWIN YH_UIColorRGB(0xE81616)
///忘记账号密码颜色
#define YHYXCOLOLR_FORGETPASS YH_UIColorRGB(0xFF9921)
///账号信息用户信息
#define YHYXCOLOLR_USER YH_UIColorRGB(0x343434)
///账号信息用户名称
#define YHYXCOLOLR_USERNAME YH_UIColorRGB(0x808080)
///账号信息用户名称
#define YHYXCOLOLR_INFORMATIONBACK YH_UIColorRGB(0xEEEEEE)



#define YH_UIColorRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]



// 延时加载
#define YH_BLOCK ^()block
#define YH_DISPATCH_AFTER(time, YH_BLOCK) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(time * NSEC_PER_SEC)), dispatch_get_main_queue(), YH_BLOCK)





#endif /* YHYXHeaderTool_h */



/**兼容屏幕的宽度计算
 * 以375 为基准 按比例计算
 */
static inline CGFloat YHWidth(CGFloat width){

    if ([UIScreen mainScreen].bounds.size.height > [UIScreen mainScreen].bounds.size.width) {
        CGFloat www = (width*([UIScreen mainScreen].bounds.size.width/375));
        return www;
    }else{
        CGFloat www = (width*([UIScreen mainScreen].bounds.size.width/667));
        return www;
    }
}



/**兼容屏幕的高度计算
 * 以667 为基准 按比例计算
 */
static inline CGFloat YHHeight(CGFloat height){
    
    if ([UIScreen mainScreen].bounds.size.height > [UIScreen mainScreen].bounds.size.width) {
        CGFloat hhh = (height*([UIScreen mainScreen].bounds.size.height/667));
        return hhh;
    }else{
        CGFloat hhh = (height*([UIScreen mainScreen].bounds.size.height/375));
        return hhh;
    }
   
}
