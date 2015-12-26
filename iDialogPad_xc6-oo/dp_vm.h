//
//  dp_vm.h
//  iDialogPad
//
//  Created by Gerhard Mutz1 on 29.09.09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "ASK3ViewController.h"
#import "AppDelegate.h"

@class ASK3ViewController;
@class MainView;

@interface DP_VM : NSObject {
ASK3ViewController *askp;
MainView *mv;
}

@property (nonatomic, retain) ASK3ViewController *askp;
@property (nonatomic, retain) MainView *mv;


- (void)timerFireMethod:(NSTimer*)theTimer;

@end
