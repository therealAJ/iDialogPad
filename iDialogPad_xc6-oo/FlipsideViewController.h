//
//  FlipsideViewController.h
//  UDecide
//
//  Created by acs on 10/12/08.
//  Copyright ACS Technologies 2008. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MainView.h"

@interface FlipsideViewController : UIViewController {
IBOutlet UITextView *text;
@public MainView *mv;
}

@property (nonatomic, retain)  UITextView *text;

@end
