/*
 *  config.h
 *  iDialogPad
 *
 *  Created by Egon  Stephan on 29.06.10.
 *  Copyright 2010 Universität zu Köln. All rights reserved.
 *
 */

#if 0

// old format
#define FILE_FORMAT NSMacOSRomanStringEncoding
#define DefaultCmd @"demo.cmd"
#define CmdFileSuffix @".cmd"
#define PathExtension @"cmd"

#else

#define FILE_FORMAT NSUTF8StringEncoding
#define DefaultCmd @"demo.qdf"
#define CmdFileSuffix @".qdf"
#define PathExtension @"qdf"

#endif

#define BYTE 1
#define WORD 2
#define TXTINDEX BYTE

#define UTF16STRINGS 1

#define LOG2FILE 1
//#define NSLog


// max Nr of Items with ASK
#define MAXITEMS 16


#define UTFTEXT(A) [usertext_array objectAtIndex:A]

#define UTEXT(A) utext[A]


#define USE_SS 1

#define ATDEBUG 1

#define SUBFILELEN 24
#define MAXLINES 500
struct QDF_CMD {
    unsigned short CMD;
    short HEADER;
    short NUM;
    short MAX;
    short LINK[8];
    union X {
        short ANSWER[MAXITEMS];
        char FILE[SUBFILELEN];
    } STORE;
};

struct PARAMS {
    unsigned short options; 
    unsigned char ptimeout;
    unsigned short timeout;
    unsigned char praesel;
    unsigned char cfsize;
    unsigned char cbfsize;
    unsigned char cifsize;
    short xscale_s;
    short xscale_l;
    short xscale_r;
    short ok_txt;
    short end_txt;
    struct QDF_CMD *qdf;
    struct QDF_CMD *savqdf;
    unsigned char *out;
    unsigned long filpos;
    char cmdfile[64];
    unsigned char usefile;
    short lines;
    unsigned char rlj_init;
    unsigned char rlj;
    unsigned char rlcnt;
    unsigned char rmp;
    unsigned char rmf;
};