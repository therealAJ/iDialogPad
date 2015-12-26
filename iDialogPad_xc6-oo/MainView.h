#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#include <AudioToolbox/AudioToolbox.h>
#import "RootViewController.h"
#import "MainViewController.h"
#import "ASK3ViewController.h"
#import "DeepSleepPreventer.h"
#import "PreferenceViewController.h"
#import "AppDelegate.h"
#import "dp_vm.h"
#import <CoreLocation/CoreLocation.h>

@class DP_VM;

@interface MainView : UIView <UIAlertViewDelegate> {
	IBOutlet UILabel *atime;
	IBOutlet UILabel *dtime;
	IBOutlet UILabel *percent;
	IBOutlet UIButton *start;
	IBOutlet UISwitch *sleep;
	IBOutlet UILabel *sleeplabel;
	IBOutlet UILabel *timersymbol;
	IBOutlet UILabel *atimer;
	BOOL sleeping;
	BOOL was_sleeping;
	BOOL dialogrunning;
	BOOL alert_open;
	IBOutlet RootViewController *rootViewController;
	IBOutlet UINavigationBar *mainViewNavigationBar;
	ASK3ViewController *aSK3ViewController;
	DeepSleepPreventer *deepSleepPreventer;
	NSTimer *xtimer;
	DP_VM *dp_vmp;	
}


@property (nonatomic, retain) UILabel *atime;
@property (nonatomic, retain) UILabel *dtime;
@property (nonatomic, retain) UILabel *percent;
@property (nonatomic, retain) IBOutlet UIButton *start;
@property (nonatomic, retain) IBOutlet UISwitch *sleep;
@property (nonatomic, retain) IBOutlet UILabel *sleeplabel;
@property (nonatomic, retain) UILabel *timersymbol;
@property (nonatomic, retain) UILabel *atimer;
@property (nonatomic, retain) IBOutlet RootViewController *rootViewController;
@property (nonatomic, retain) IBOutlet UINavigationBar *mainViewNavigationBar;
@property (nonatomic, retain) IBOutlet ASK3ViewController *aSK3ViewController;
@property (nonatomic, retain) DeepSleepPreventer *deepSleepPreventer;
@property (nonatomic, retain) DP_VM *dp_vmp;

- (void)SetTime;
- (void)SetEVTTime;
- (IBAction)start:(id)sender;
- (IBAction)sleep:(id)sender;
- (IBAction)showError:(NSString*)message;
-(void) prepare;
-(void) startDialog:(long)user;
-(void) stopDialog;
-(void)startAuto;
-(void)startATAuto;
-(void)showTimer;
-(void)loadCmdFile;
-(void) setCurrentCmdfileName:(NSString*)name;
-(void)go_sleep;
-(void)go_wake;
-(void)showTime;
-(void) beep;
-(void)stopnstimer;
-(void)CheckPreventSleep;
-(void)Auto_SaveOutput;
-(void)cmdfile_error:(short)error;
-(void)UpdateTime;
@end
