#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "ASK3View.h"
#import <AVFoundation/AVFoundation.h>
//#import "dp_vm.h"
#import "config.h"

@interface SAM_Button : UIButton {
	
}

@end

@class MainView;

@interface ASK3ViewController : UIViewController <UITextFieldDelegate,UITextViewDelegate,UITableViewDelegate,UITableViewDataSource,UIPickerViewDelegate,UIPickerViewDataSource,AVAudioPlayerDelegate,UIImagePickerControllerDelegate> {
IBOutlet UITextView *iheader;
IBOutlet UITextView *header;
IBOutlet UITextView *left;
IBOutlet UITextView *right;
IBOutlet UITextView *ileft;
IBOutlet UITextView *iright;
IBOutlet UIButton *back;
IBOutlet UIButton *ok;
IBOutlet SAM_Button *sam;
UISegmentedControl *segmentedControl;
UISlider *sliderControl;
UIImageView *himageview;
    
    UIButton *l_pbutton;
    UIButton *r_pbutton;
	
UILabel *user_id_label;
UITextField *user_id;
UILabel *user_gender_label;
UISegmentedControl *user_gender;
UILabel *user_age_label;
UITextField *user_age;
		
MainView *mainView;
UINavigationBar *mainViewNavigationBar;
UINavigationItem *savednavigationItem;
BOOL itemsup;
short cellheight;
NSMutableArray *items;
UIPickerView		*myPickerView1;
UIDatePicker		*myPickerView;
	
NSInteger pickerisup;
NSInteger pickermode;	
NSInteger pickerrow;
NSMutableArray *listData;
UITableView *tableView;
UIImagePickerController *imagePickerController;	
AVAudioRecorder *audioRecorder;
AVAudioPlayer *audioPlayer;
    UISwitch *gswitch;    
}


@property(nonatomic, retain) NSMutableArray *listData;
//@property(nonatomic, retain) UITableView *tableView;

@property (nonatomic, retain) UITextView *iheader;
@property (nonatomic, retain) UITextView *header;
@property (nonatomic, retain) UITextView *left;
@property (nonatomic, retain) UITextView *right;
@property (nonatomic, retain) UITextView *ileft;
@property (nonatomic, retain) UITextView *iright;
@property (nonatomic, retain) UIButton *back;
@property (nonatomic, retain) UIButton *ok;
@property (nonatomic, retain) SAM_Button *sam;
@property (nonatomic, retain) UISegmentedControl *segmentedControl;
@property (nonatomic, retain) UISlider *sliderControl;
@property (nonatomic, retain) MainView *mainView;
@property (nonatomic, retain) UINavigationBar *mainViewNavigationBar;
@property (nonatomic, retain) UINavigationItem *savednavigationItem;

@property (nonatomic, retain) UILabel *user_id_label;
@property (nonatomic, retain) UITextField *user_id;
@property (nonatomic, retain) UILabel *user_gender_label;
@property (nonatomic, retain) UISegmentedControl *user_gender;
@property (nonatomic, retain) UILabel *user_age_label;
@property (nonatomic, retain) UITextField *user_age;


@property (nonatomic, retain) NSMutableArray *items;

- (void) Draw_pic:(short)num;
- (void) setASKView:(long)num  :(NSMutableString*)theader  :(NSString*)tleft :(NSString*)tright :(NSString*)scale;
-(void) setPopup:(NSMutableArray*)popupstrings;
-(void) setD2:(short) flag :(NSString*)str;
-(void) doSAM:(short) flag;
-(void) doGrid:(short) flag numcells:(short)cells text:(NSMutableArray*)strings;
-(void) doPicSel:(NSString*)header flag:(short) flag;
-(void) setTimeSelect:(NSString*)header :(NSInteger)flags; 
-(unsigned char*)doWMTask:(NSString*)header tout:(short)tout start:(short)start number:(short)number data:(unsigned char*)out;
-(IBAction)go_back:(id)sender;
-(IBAction)go_ok:(id)sender;
-(IBAction)sam_button:(id)sender;
-(void)segmentAction:(id)sender;
-(void)sliderAction:(id)sender;
-(void)clritems;
-(void)itemselected:(id)sender;
-(void) StartDialog:(NSString*)xheader  :(NSString*)button1 :(NSString*)button2;
-(void) ReleaseDialog;
-(long) TakePicture:(short)timout;
-(long) RecordAudio:(NSString*)header timout:(short)timout;
-(long) PlayAudio:(NSString*)header file:(NSString*)file flags:(short)flags timout:(short)timout;
-(void) set_gs_switch:(id)sender;
-(void)form_iheader:(NSString*)xheader;
-(void)ShowHist:(NSMutableArray*)tlist opt:(struct QDF_CMD *)params;
-(void)RemoveHist;
-(void)playbeep;
@end

