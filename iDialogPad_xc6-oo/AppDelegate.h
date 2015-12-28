#import "MainView.h"
#import "MainViewController.h"
#import "RootViewController.h"
#include <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <Availability.h>


// AppDelegate class interface.
@class RootViewController;
@class IDialogPadAppDelegate;
//@class LocalNotificationViewController;


@interface IDialogPadAppDelegate :  NSObject <UIApplicationDelegate>
//@interface LocalNotificationAppDelegate : NSObject <UIApplicationDelegate> 
{
    IBOutlet UIWindow *window;
	BOOL	mode;
	NSInteger	backgroundColor;
	NSInteger	textColor;
	IBOutlet RootViewController *rootViewController;
	CFURLRef		soundFileURLRef;
	SystemSoundID	soundFileObject;
    SystemSoundID	soundFileObject1;
    SystemSoundID	soundFileObject2;
	AVAudioPlayer *audioPlayer;
    CFUUIDRef uuidr;
}


@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) RootViewController *rootViewController;
@property (readwrite)	CFURLRef		soundFileURLRef;
@property (readonly)	SystemSoundID	soundFileObject;
@property (readonly)	SystemSoundID	soundFileObject1;

@property (nonatomic, retain) NSString *cmdfilename;
@property (nonatomic, retain) NSString *vpid_number;
@property (nonatomic, retain) AVAudioPlayer *audioPlayer;


- (void)onTimer;
- (void)onEVTTimer;
- (void)playSound; 
- (void) Play_Beep:(long)type;
- (void)getUserSetup ;


-(void)ShowNotification:(NSString*)message;
- (void)clroldNotifications;


@end
