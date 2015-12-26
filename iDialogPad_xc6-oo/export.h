/*
 *  export.h
 *  iDialogPad
 *
 *  Created by Gerhard Mutz1 on 04.09.09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char stocode[][8]={"AUTO","USER","MARKER","TIMOUT","ENDINP","TEXTINP","BEGSUB","ENDSUB"};
extern char stocode1[][8]={"AUTO","USER","MARKER","ATAUTO","NETWORK","NONE"};
//enum {AUTO,USER,MARKER,ATAUTO,NETWORK,NONE,NEXT,PREV,ITIMEOUT};

// output file data opcodes
#define NRM_END 0xff
#define TO_END  0xfe
#define ROM_VOC 0xfd
#define USR_VOC 0xfc
#define SCALE   0xfb
#define TESTR   0xfa
#define XINPUT  0xf9
#define BEGIN_SUB 0xf8
#define END_SUB 0xf7
#define ITEM 0xf6
#define MITEM 0xf5
#define USER_ID 0xf4
#define TITEM 0xf3

#define KEYUP 1
#define KEYDN 8
#define KEYOK 4
#define KEYEX 2
#define NOKEY 0

#define xTIMOUT 30
#define xPTIMOUT 10

#define MAXEVENT 8
#define MAXATIME 128

#define LF 10
#define CR 13

#define MAXUVOC 512
extern char *utext[MAXUVOC];
extern unsigned short usertextanz;
