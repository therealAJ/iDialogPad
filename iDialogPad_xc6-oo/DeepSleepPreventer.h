//
//  DeepSleepPreventer.h
//  iPhoneInsomnia
//
//  Created by Marco Peluso on 20.08.09.
//  Copyright 2009 Marco Peluso. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class AVAudioPlayer;

//@interface DeepSleepPreventer : AVAudioPlayer <AVAudioPlayerDelegate>{
@interface DeepSleepPreventer : NSObject <AVAudioPlayerDelegate>{    
	AVAudioPlayer *audioPlayer;
	NSTimer *preventSleepTimer;
}
@property (nonatomic, retain) AVAudioPlayer *audioPlayer;
@property (nonatomic, retain) NSTimer *preventSleepTimer;
- (void)playPreventSleepSound;
- (void)startPreventSleep;
- (void)stopPreventSleep;
-(BOOL) isActiv;
@end
