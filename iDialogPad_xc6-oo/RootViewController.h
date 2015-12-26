//
//  RootViewController.h
//  UDecide
//
//  Created by acs on 10/12/08.
//  Copyright ACS Technologies 2008. All rights reserved.
//

#import <UIKit/UIKit.h>

@class MainViewController;
@class FlipsideViewController;
@class PreferenceViewController;


@interface RootViewController : UIViewController {

	IBOutlet UIButton *infoButton;
	MainViewController *mainViewController;
	FlipsideViewController *flipsideViewController;
	PreferenceViewController *preferenceViewController;
	UIViewController *currentViewController;
	UINavigationBar *flipsideNavigationBar;
	UINavigationBar *mainViewNavigationBar;
	UINavigationItem *rvnavigationItem;
	NSDictionary *addresses;
}

@property (nonatomic, retain) UIButton *infoButton;
@property (nonatomic, retain) MainViewController *mainViewController;
@property (nonatomic, retain) UINavigationBar *flipsideNavigationBar;
@property (nonatomic, retain) FlipsideViewController *flipsideViewController;
@property (nonatomic, retain) UINavigationBar *mainViewNavigationBar;
@property (nonatomic, retain) UIViewController *currentViewController;
@property (nonatomic, retain) PreferenceViewController *preferenceViewController;
@property (nonatomic, retain) UINavigationItem *rvnavigationItem;

- (IBAction)toggleView;
-(IBAction) do_export_output;

-(void) startServer;
-(void) stopServer;
- (void)showError:(NSString*)message;
- (void)showAlert:(NSString*)message;

@end
