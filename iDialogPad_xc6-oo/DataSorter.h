//
//  DataSorter.h
//  iDialogPad
//
//  Created by Gerhard Mutz on 25.12.15.
//  Copyright (c) 2015 becker. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface DataSorter : NSObject {
    NSString *autosavePath;
    NSString *autosavePathc;
    NSString *cmdfilename;
    NSString *uuids;
    NSString *uuidn;
    NSString *vpid_number;
}


@property (nonatomic, copy) NSString *autosavePath;
@property (nonatomic, copy) NSString *autosavePathc;
@property (nonatomic, copy) NSString *cmdfilename;
@property (nonatomic, copy) NSString    *uuids;
@property (nonatomic, copy) NSString    *uuidn;
@property (nonatomic, copy) NSString    *vpid_number;


-(NSString*) getCurrentCmdfilePath;
-(NSString*)GetOutputpath;
-(NSString*)GetOutputpathbin;
- (void)xls_tset:(long)row column:(long)column nstr:(NSString*)nstr;
-(long) cnv_idp:(NSString*)qdfp sp:(NSString*)sp dp:(NSString*)dp flags:(long)flags;
-(long)getNumOutputFiles;
- (NSString *) platform ;
- (NSString *) platformString;
- (void)showError:(NSString*)message;
-(void)copytodefault;
-(void)savedefaults;
-(void)httpPost:(NSString*)path;
-(long)postOutputFiles;

@end
