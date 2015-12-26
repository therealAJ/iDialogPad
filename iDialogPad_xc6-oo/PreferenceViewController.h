//
//  FlipsideViewController.h
//  UDecide
//
//  Created by acs on 10/12/08.
//  Copyright ACS Technologies 2008. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import "ServerContoller.h"
#import <CoreBluetooth/CoreBluetooth.h>

@class PreferenceViewController;
@class RootViewController;
@class IDialogPadAppDelegate;


//MFMailComposeViewControllerDelegate


@interface PreferenceViewController :   UIViewController <UITextFieldDelegate,UIPickerViewDelegate,MFMailComposeViewControllerDelegate,UITableViewDelegate,UITableViewDataSource> {
IBOutlet UITextView *cmftext;
IBOutlet UIButton *cmdfile;
IBOutlet UITextField *vpid;
IBOutlet UIButton *reset_output;
IBOutlet UIButton *export_output;
IBOutlet UIButton *show_voctab;
IBOutlet UIButton *sync;
IBOutlet UIButton *bonjour;
IBOutlet UILabel *copyright;
IBOutlet UILabel *iphone_ip;
UINavigationItem *navitem;
UINavigationBar *preferenceNavigationBar;
RootViewController *rootViewController;
IDialogPadAppDelegate *iDialogPadAppDelegate;


NSMutableArray		*pickerViewArray;
UIPickerView		*myPickerView;
NSInteger pickerisup;
NSInteger pickerrow;
NSString *pickedstring;
    NSMutableArray *deviceList;
}

@property (nonatomic, retain) NSMutableArray *deviceList;
@property (nonatomic, retain) IBOutlet UITextView *cmftext;
@property (nonatomic, retain) IBOutlet UIButton *cmdfile;
@property (nonatomic, retain) IBOutlet UITextField *vpid;
@property (nonatomic, retain) IBOutlet UIButton *reset_output;
@property (nonatomic, retain) IBOutlet UIButton *export_output;
@property (nonatomic, retain) IBOutlet UIButton *show_voctab;
@property (nonatomic, retain) IBOutlet UIButton *sync;
@property (nonatomic, retain) IBOutlet UIButton *bonjour;
@property (nonatomic, retain) IBOutlet UILabel *copyright;
@property (nonatomic, retain) IBOutlet UILabel *iphone_ip;
@property (nonatomic, retain) UINavigationItem *navitem;
@property (nonatomic, retain) UINavigationBar *preferenceNavigationBar;
@property (nonatomic, retain) RootViewController *rootViewController;
@property (nonatomic, retain) IDialogPadAppDelegate *iDialogPadAppDelegate;



-(IBAction) edit_text:(id)sender;
-(IBAction) select_cmdfile:(id)sender;
-(IBAction) edit_vpid:(id)sender;
-(IBAction) do_reset_output:(id)sender;
-(IBAction) do_export_output:(id)sender;
-(IBAction) do_show_voctab:(id)sender;
-(IBAction) do_sync:(id)sender;
-(IBAction) start_stop_bonjour:(id)sender;

-(void) edit;
-(void) save;
-(void) done;
-(void)cmdfileload;
- (void)showError:(NSString*)message;
-(NSString*)getfromAdressbook:(long)flg;
- (NSString*)createPicker:(NSInteger)selector;

#define LOAD_CMD 1
#define DELETE_CMD 2


- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component;
- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component;
- (CGFloat)pickerView:(UIPickerView *)pickerView widthForComponent:(NSInteger)component;
- (CGFloat)pickerView:(UIPickerView *)pickerView rowHeightForComponent:(NSInteger)component;
- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component;
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView;

-(void)setURL:(NSString*)text;
-(void)displayComposerSheet : (id) sender;
- (void)showMessage:(NSString*)message;

@end
