#import "AppDelegate.h"
#import "Constants.h"
#import "config.h"
#import "tcp.h"
#import "getcmdfile.h"
#import "DataSorter.h"



// AppDelegate class implementation.

@implementation IDialogPadAppDelegate

natural_t get_free_memory(void);

BOOL allow_setup,allow_edit,use_unicode,use_internal_server,use_export_button;
BOOL use_sorted_export,use_export_numbers,use_gps,auto_save;


@synthesize window,currSysVer;
@synthesize rootViewController;

@synthesize soundFileURLRef;
@synthesize soundFileObject;
@synthesize soundFileObject1;

@synthesize cmdfilename,vpid_number;
@synthesize audioPlayer;

SystemSoundID	gsoundFileObject,gsoundFileObject1,gsoundFileObject2,gsoundFileObject3;
void reset_Vars(void);
unsigned char udpbuff[64];


NSString *Export_email;
NSString *Export_email_cc;
NSString *Varioport_URL;
NSString *URL_get;

IDialogPadAppDelegate *iap;
DataSorter *ds;

NSTimer *mintimer,*evttimer;

extern long outputsize,longflag;
extern BOOL is_ipad;
extern unsigned short mopt;

#define EXPORT_OUTPUT 8

UIApplication *appl;


//char *str;

//- (void)applicationDidFinishLaunching:(UIApplication*)application {
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {    
	
	iap=self;
	appl=application;
    
    window.rootViewController = rootViewController;
	
    currSysVer=[[[UIDevice currentDevice] systemVersion] copy];
    
    NSString * version = [[NSBundle mainBundle] objectForInfoDictionaryKey: @"CFBundleShortVersionString"];

    ds=[[DataSorter alloc] init];

#ifdef LOG2FILE
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *logPath = [documentsDirectory stringByAppendingPathComponent:@"logfile.txt"];
    freopen([logPath cStringUsingEncoding:NSASCIIStringEncoding],"a+",stderr);
    NSLog(@"device: %@, platform: %@",[ds platformString],[ds platform]);
    NSLog(@"sysversion: %@",[[UIDevice currentDevice] systemVersion]);
    NSLog(@"free ram: %d MB",get_free_memory()/1000000);
    NSLog(@"appversion: %@",version);
    NSLog(@"UTF version");
    NSLog(@"app launched");
#endif
    
  
    //It is here that we set the defaults
    NSString *textValue = [[NSUserDefaults standardUserDefaults] stringForKey:@"kModeKey"];

    if (textValue == nil) {
        [self registerDefaultsFromSettingsBundle];
    }
    else {
        [self getUserSetup];
    }

    
    if (use_sorted_export==YES) {
        NSLog(@"sorted export activ");
    }
    if (auto_save==YES) {
        NSLog(@"autosave activ");
    }

	use_unicode=YES;
	use_internal_server=NO;
	
	[window addSubview:[rootViewController view]];

	if (use_export_button==YES) {
		UIBarButtonItem *buttonItem = [[UIBarButtonItem alloc]initWithBarButtonSystemItem:UIBarButtonSystemItemCompose target:rootViewController action:@selector(do_export_output)];
		rootViewController.rvnavigationItem.leftBarButtonItem = buttonItem;
		[buttonItem release];
        NSLog(@"Export Button on main screen");
	}
    
    if ([application respondsToSelector:@selector(isRegisteredForRemoteNotifications)]) {
        // iOS 8 Notifications
        [application registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge) categories:nil]];
        
        [application registerForRemoteNotifications];
    } else {
        // iOS < 8 Notifications
        [application registerForRemoteNotificationTypes:
         (UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeAlert | UIRemoteNotificationTypeSound)];
    }
	    
    // Show the window
    [window makeKeyAndVisible];
	
	// 60 second timer for clock display
	mintimer = [NSTimer scheduledTimerWithTimeInterval:(60.0) target:self selector:@selector(onTimer) userInfo:nil repeats:YES];	

	// 60 second timer for clock display
	evttimer = [NSTimer scheduledTimerWithTimeInterval:(60.0) target:self selector:@selector(onEVTTimer) userInfo:nil repeats:YES];	
	
	CFBundleRef mainBundle;
	mainBundle = CFBundleGetMainBundle ();
	// Get the URL to the sound file to play
	soundFileURLRef  =	CFBundleCopyResourceURL(mainBundle,CFSTR ("Sonar"),CFSTR ("aif"),NULL);
    // Create a system sound object representing the sound file
	AudioServicesCreateSystemSoundID (soundFileURLRef,&soundFileObject1);

 	// Get the URL to the sound file to play
	soundFileURLRef  =	CFBundleCopyResourceURL(mainBundle,CFSTR ("Telefon"),CFSTR ("wav"),NULL);
    // Create a system sound object representing the sound file
	AudioServicesCreateSystemSoundID (soundFileURLRef,&soundFileObject2);

    soundFileURLRef  =	CFBundleCopyResourceURL(mainBundle,CFSTR ("Classic"),CFSTR ("aif"),NULL);
    // Create a system sound object representing the sound file
	AudioServicesCreateSystemSoundID (soundFileURLRef,&soundFileObject);
	
	[ds getNumOutputFiles];
    
    // listen to port 2000
    //udp_open("0.0.0.0",2000);
	
	gsoundFileObject1=soundFileObject;
    gsoundFileObject2=soundFileObject1;
    gsoundFileObject3=soundFileObject2;
    
 
	[ds copytodefault];
	reset_Vars();
	[(MainView*)rootViewController.mainViewController.view loadCmdFile];
	    
	if (outputsize) longflag&=(EXPORT_OUTPUT^0xffffffff);
		

	NSDictionary* userInfo = [launchOptions valueForKey:@"UIApplicationLaunchOptionsLocalNotificationKey"];
	if (userInfo) {
		// programm was launched by notification
		// Override point for customization after app launch    
		UIAlertView *alert = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Alarm", @"") message:@"didifinishlaunching with options"
		delegate:self cancelButtonTitle:@"OK" otherButtonTitles: nil];
		[alert show];	
		[alert release];
	}
    
	return YES;
 }

// got a file from eg email
-(BOOL)application:(UIApplication *)application openURL:(NSURL *)xurl
 sourceApplication:(NSString *)sourceApplication
        annotation:(id)annotation {
    if (xurl != nil && [xurl isFileURL]) {
        // move to documents directory
        NSString *fname=[xurl.path lastPathComponent];
        NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES);
        NSString *path=[paths objectAtIndex:0];
        path = [path stringByAppendingPathComponent:fname];
        NSError *error;
        NSFileManager *fm=[NSFileManager defaultManager];
        
        if ([fm fileExistsAtPath:path]) {
            // must remove dest item before copy
            [fm removeItemAtPath:path error:&error];
        }
        
        if ([fm moveItemAtPath:xurl.path toPath:path error:&error] != YES) {
            //[self showError:@"Could not move qdf file!"];
        }
        else {
            if ([[fname pathExtension] isEqualToString:@"qdf"]) {
                // make this file activ
                //self.defname=fname;
                //[mvc reload];
            }
        }
        
    }
    return YES;
}

// later may select different sounds
- (void) Play_Beep:(long)type {
	// Set up sound file
	NSString *soundFilePath = [[NSBundle mainBundle] pathForResource:@"Classic" ofType:@"aif"];
	NSURL *fileURL = [[NSURL alloc] initFileURLWithPath:soundFilePath];
	// Set up audio player with sound file
	self.audioPlayer = [[AVAudioPlayer alloc] initWithContentsOfURL:fileURL error:nil];
	[fileURL release];
	[self.audioPlayer prepareToPlay];
	[self.audioPlayer setVolume:1.0];
	[self.audioPlayer play];
}


- (void)registerDefaultsFromSettingsBundle {
    NSString *settingsBundle = [[NSBundle mainBundle] pathForResource:@"Settings" ofType:@"bundle"];
    if(!settingsBundle) {
        NSLog(@"Could not find Settings.bundle");
        return;
    }
    
    NSDictionary *settings = [NSDictionary dictionaryWithContentsOfFile:[settingsBundle stringByAppendingPathComponent:@"Root.plist"]];
    NSArray *preferences = [settings objectForKey:@"PreferenceSpecifiers"];
    
    NSMutableDictionary *defaultsToRegister = [[NSMutableDictionary alloc] initWithCapacity:[preferences count]];
    for(NSDictionary *prefSpecification in preferences) {
        NSString *key = [prefSpecification objectForKey:@"Key"];
        if(key) {
            [defaultsToRegister setObject:[prefSpecification objectForKey:@"DefaultValue"] forKey:key];
        }
    }
    [[NSUserDefaults standardUserDefaults] registerDefaults:defaultsToRegister];
    [defaultsToRegister release];
}


- (void)getUserSetup {

    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];

	//[[NSUserDefaults standardUserDefaults] synchronize];
	
	// allow setup
	allow_setup = [defaults boolForKey:@"kModeKey"];

	// allow edit
	allow_edit = [defaults boolForKey:@"kModeKey1"];

	// allow unicode
	use_unicode = [defaults boolForKey:@"kModeKey2"];

	use_export_button=[defaults boolForKey:@"kModeKey7"];

	// use @ Export
	use_sorted_export = [defaults boolForKey:@"kModeKey8"];

	// use gps
	use_gps = [defaults boolForKey:@"kModeKey9"];

    // auto save
	auto_save = [defaults boolForKey:@"kModeKey10"];

	// URL get
	URL_get = (NSString *)[defaults stringForKey:(NSString *)@"kModeKey3"];
	// export email
	Export_email = (NSString *)[defaults stringForKey:(NSString *)@"kModeKey4"];
	// export email cc
	Export_email_cc = (NSString *)[defaults stringForKey:(NSString *)@"kModeKey5"];
    
    //use_sorted_export=YES;
    //allow_setup=YES;
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
	[self getUserSetup];
    [ds postOutputFiles];
    NSLog(@"app did become activ");
}

-(void)clroldNotifications {
    UIApplication *app = [UIApplication sharedApplication];
    // cancel old ones
    [app cancelAllLocalNotifications];
}

-(void)ShowNotification:(NSString*)message {
    UILocalNotification *xnotification = [[UILocalNotification alloc] init];
    xnotification.alertBody = message;
    xnotification.alertAction = @"iDialogPad";
    xnotification.soundName=UILocalNotificationDefaultSoundName;
    UIApplication *app = [UIApplication sharedApplication];
    
    // cancel old ones
    [app cancelAllLocalNotifications];
    // present the new
    [app presentLocalNotificationNow:xnotification];
    
    //[app scheduleLocalNotification:xnotification];
    [xnotification release];
}


// this is called on notification
- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {
}

 -(void)applicationWillTerminate:(UIApplication *)application {
	 [ds savedefaults];
     NSLog(@"app terminated");
 }

-(void)applicationDidEnterBackground:(UIApplication *)application {
    [ds savedefaults];
    NSLog(@"app went to background");
}

// play a sound
- (void)playSound {
    AudioServicesPlayAlertSound (soundFileObject);
}

// calls clock update
- (void)onTimer {
    [(MainView*)rootViewController.mainViewController.view SetTime];
}

// calls clock update
- (void)onEVTTimer {
    [(MainView*)rootViewController.mainViewController.view SetEVTTime];
}



// Release resources.
- (void)dealloc {
	[rootViewController release];
    [window release];
    [super dealloc];
	AudioServicesDisposeSystemSoundID (soundFileObject);
	CFRelease (soundFileURLRef);	
}




@end
