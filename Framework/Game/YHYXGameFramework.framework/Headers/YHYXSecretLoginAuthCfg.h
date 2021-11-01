//
//  YHYXSecretLoginAuthCfg.h
//  YHYXGameFramework
//
//  Created by fankangpeng on 2021/5/31.
//

#import <Foundation/Foundation.h>

//一键登录默认UI样式
typedef NS_ENUM(NSUInteger, YHYXSecretLoginUIType) {
    YHYXSecretLoginUIType_Screen,//全屏
    YHYXSecretLoginUIType_Center,//居中的弹窗
    YHYXSecretLoginUIType_Bottom,//居底的弹窗
};

NS_ASSUME_NONNULL_BEGIN

@interface YHYXSecretLoginAuthCfg : NSObject

///默认UI一键登录的样式(defaule YHYXSecretLoginUIType_Center)
@property (nonatomic, assign) YHYXSecretLoginUIType defauleSecretLoginUIType;

/**4、导航栏颜色*/
@property (nonatomic,strong) UIColor *navColor;
/**6、导航栏标题*/
@property (nonatomic,strong) NSString *navText;
/**7、导航返回图标(尺寸根据图片大小)*/
@property (nonatomic,strong) UIImage *navReturnImg;


/**10、LOGO图片*/
@property (nonatomic,strong) UIImage *logoImg;
/**11、LOGO图片宽度*/
@property (nonatomic,assign) CGFloat logoWidth;
/**12、LOGO图片高度*/
@property (nonatomic,assign) CGFloat logoHeight;
/**13、LOGO图片偏移量*/
@property (nonatomic,assign) CGFloat logoOffsetY;

/**19、手机号码字体颜色*/
@property (nonatomic,strong) UIColor *numberColor;
/**20、手机号码字体大小*/
@property (nonatomic,assign) CGFloat numberSize;
/**24、号码栏Y偏移量*/
@property (nonatomic,assign) CGFloat numFieldOffsetY;

/**15、登录按钮文本*/
@property (nonatomic,strong) NSString *logBtnText;
/**16、登录按钮Y偏移量*/
@property (nonatomic,assign) CGFloat logBtnOffsetY;
/**17、登录按钮文本颜色*/
@property (nonatomic,strong) UIColor *logBtnTextColor;
/**18、登录按钮背景图片
 */
@property (nonatomic,strong) UIImage *logBtnImg;
/**19、登录按钮背景不可选时图片*/
@property (nonatomic,strong) UIImage *logBtnDisImg;

/**21、隐藏切换账号按钮*/
@property (nonatomic,assign) BOOL swithAccHidden;
/**22、切换账号字体颜色*/
@property (nonatomic,strong) UIColor *swithAccTextColor;
/**23、设置切换账号相对于标题栏下边缘y偏移*/
@property (nonatomic,assign) CGFloat switchOffsetY;
/**24、设置切换账号文本*/
@property (nonatomic,strong) NSString *switchText;

#pragma mark 隐私条款
/**25、复选框未选中时图片*/
@property (nonatomic,strong) UIImage *uncheckedImg;
/**26、复选框选中时图片*/
@property (nonatomic,strong) UIImage *checkedImg;
/**31、隐私条款check框默认状态 默认:NO */
@property (nonatomic,assign) BOOL privacyState;
/**隐私条款字体颜色*/
@property (nonatomic,strong) UIColor *privacyTextColor;
/**隐私条款协议字体颜色*/
@property (nonatomic,strong) UIColor *privateArticleColor;
/**隐私条款自定义协议文字*/
@property (nonatomic,strong) NSString *customArticleText;
/**隐私条款自定义协议文字2*/
@property (nonatomic,strong) NSString *customArticleText2;
/**隐私条款自定义协议url*/
@property (nonatomic,strong) NSString *customArticleUrl;
/**隐私条款自定义协议url2*/
@property (nonatomic,strong) NSString *customArticleUrl2;
/**应用名称*/
@property (nonatomic,strong) NSString *appName;

#pragma mark 自定义按钮
/**自定义按钮是否隐藏（默认隐藏）*/
@property (nonatomic,assign) BOOL customBtnHidden;
/**自定义按钮图片*/
@property (nonatomic,strong) UIImage *customBtnImg;
/**自定义按钮宽度*/
@property (nonatomic,assign) CGFloat customBtnWidth;
/**自定义按钮高度*/
@property (nonatomic,assign) CGFloat customBtnHeight;
/**自定义按钮Y相对于切换账号按钮偏移量*/
@property (nonatomic,assign) CGFloat switchSpaceY;


/**状态栏设置（仅支持移动和联通）默认UIStatusBarStyleDefault*/
@property (nonatomic,assign) UIStatusBarStyle statusBarStyle;

/**授权页背景颜色，默认白色*/
@property (nonatomic,strong) UIColor *bgColor;

/**授权页背景图片，全屏(与bgColor只能设置一个生效) 默认nil*/
@property (nonatomic,strong) UIImage *authPageBackgroundImage;

#pragma mark ----------------------弹窗:(温馨提示:由于受屏幕影响，小屏幕（5S,5E,5）需要改动字体和另自适应和布局)--------------------

#pragma mark ---------------------电信弹窗模式需要自行修改EAccountMiniAuthVC_center_textview（中部）EAccountMiniAuthVC_bottom_textview（底部）--------------------

/**是否是弹窗模式(支持中部弹窗和底部弹窗两种模式，aletrStyle:0为中部，1为底部)*/
@property (nonatomic,assign) BOOL isAlert;

/**窗口模式样式：0为中部，1为底部，默认为0*/
@property (nonatomic,assign) int aletrStyle;

/** 窗口模式推出动画
 UIModalTransitionStyleCoverVertical, 下推
 UIModalTransitionStyleFlipHorizontal,翻转
 UIModalTransitionStyleCrossDissolve, 淡出
 */
@property (nonatomic,assign) UIModalTransitionStyle modalTransitionStyle;



/**自定义窗口弧度 默认是10*/
@property (nonatomic,assign) CGFloat cornerRadius;

/**自定义窗口宽-缩放系数(屏幕宽乘以系数) 默认是0.8，底部需改为1*/
@property (nonatomic,assign) CGFloat scaleW;

/**自定义窗口高-缩放系数(屏幕高乘以系数) 默认是0.5*/
@property (nonatomic,assign) CGFloat scaleH;


/**弹窗模式关闭按钮图片*/
@property (nonatomic,strong) UIImage *alertCloseImg;

/**窗口模式号码offsetY*/
@property (nonatomic,assign) CGFloat alertNumFieldOffsetY;
/**窗口模式登录按钮offsetY*/
@property (nonatomic,assign) CGFloat alertLogBtnOffsetY;
/**窗口模式切花其他按钮offsetY*/
@property (nonatomic,assign) CGFloat alertSwitchOffsetY;
/**窗口模式协议屏幕距底部offsetY*/
@property (nonatomic,assign) CGFloat alertPricacyOffsetY_B;

/**弹窗授权界面自定义控件View的Block*/
@property (nonatomic,copy) void(^authAlertViewBlock)(UIView *customView);
@end

NS_ASSUME_NONNULL_END
