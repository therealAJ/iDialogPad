//
//  Uploader.h
//  iDialogPad
//
//  Created by Mutz Gerhard on 07.02.12.
//  Copyright (c) 2012 becker. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Uploader : NSObject
{
    NSURL *serverURL;
    NSString *filePath;
    NSString *fileName;
    id delegate;
    SEL doneSelector;
    SEL errorSelector;
    
    BOOL uploadDidSucceed;
}

- (id)initWithURL: (NSURL *)serverURL
         filePath: (NSString *)filePath
         fileName: (NSString *)fileName
         delegate: (id)delegate
     doneSelector: (SEL)doneSelector
    errorSelector: (SEL)errorSelector;

- (NSString *)filePath;

@end