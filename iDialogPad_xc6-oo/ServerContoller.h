//
//  ServerContoller.h
//  iDialogPad
//
//  Created by Gerhard Mutz1 on 09.10.09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


@class AsyncSocket;
@class MTMessageBroker;
@class PreferenceViewController;

@interface ServerController : NSObject { 
    NSNetService *netService; 
    AsyncSocket *listeningSocket;
    AsyncSocket *connectionSocket;
    MTMessageBroker *messageBroker;
	//PreferenceViewController *preferenceController;
} 

@property (readwrite, retain) AsyncSocket *listeningSocket;
@property (readwrite, retain) AsyncSocket *connectionSocket;
@property (readwrite, retain) MTMessageBroker *messageBroker;
//@property (readwrite, retain) PreferenceViewController *preferenceController;

-(void)startService; 
-(void)stopService; 


@end
