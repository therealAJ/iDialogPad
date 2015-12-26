/*
 *  getcmdfile.h
 *  iDialogPad
 *
 *  Created by Gerhard Mutz1 on 04.09.09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
 
#define PDA 1

typedef unsigned long UL;
typedef unsigned short US;
typedef unsigned char UB;
typedef float pdouble;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define DEMO 0
#define DEMOLINES 40
#define DEMOVERSION 99


enum {END,LBEEP,ASK1,ASK2,ASK3,ASKA,ASKS,SKIP,SKIPL,SKIPH,UVOC,RVOC,PRINT,SKIPU,SKIPV,TEST,TOUT,PTOUT,INPUT,SYNC,OPTION,PSEL,
	USE,SETV,DSZV,TIME,SNZV,XSCALE,TIMER,RETRY,SZV,SRE,SRN,SRL,SRH,ASKU,ASKM,SKIPRTH,FSIZ,FTOUT,SDIALOG,SRA,TIMS,BFSIZ,SZVE,INCV,GOV,GTS,RLJ,GPS,TSTV,TP,RA,ADDRV,RETRIES,IFSIZ,OKTXT,RM,SRAE,SRAN,SUM,NORM,PA,AGRID,HIST,OETXT,ENDTXT};
// record identifier
enum {AUTO,USER,MARKER,ATAUTO,NETWORK,NONE,NEXT,PREV,ITIMEOUT};

// syntax errors
// leading quote
#define SYNERROR_LQ 1
// ending quote
#define SYNERROR_EQ 2
// label not found
#define SYNERROR_LNF 3
// parameter
#define SYNERROR_PAR 4
// file type
#define SYNERROR_TYP 5
// unknown encoding
#define ENCODING_TYP 6
// memory error
#define MEMORY_TYP 7
// missing se
#define MISSSE_TYP 8
// duplicate label
#define DUPLABEL_TYP 9
// too many strings
#define TOO_MANY_TYP 10
// missing Label
#define MiSS_LABEL_TYP 11
// dupl @ Label
#define DUPLABEL1_TYP 12
// error in @ label
#define INLABEL_TYP 13

#define UNKNOWN_TYP 98

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
#define TSTAMP 0xf2
#define SUMRES 0xf1

#define KEYUP 1
#define KEYDN 8
#define KEYOK 4
#define KEYEX 2
#define NOKEY 0

#define xTIMOUT 30
#define xPTIMOUT 10

#define MAXEVENT 8
#define MAXATIME 128

struct EVENT {
UB hour;
UB mins;
UB txt1;
UB txt2;
UB snd1;
UB snd2;
UB voc;
UB flg;
UB fired;
UB alarm;
};


struct ATIME {
UB day;
UB hour;
UB mins;
UB o_hour;
UB o_mins;
UB FLAGS;
US chance;
};

#define MAXLSIZE 17
#define MAXLABELS 128

struct LABELS {
	char TXT[MAXLSIZE];
	US LINE;
	void *LPOS;
};



long getcmdfile(char *name);

// options 
//1 = zeigt die Uhrzeit an 
#define OPT_SHOWATIME 1
//2 = zeigt die Zeit bis zum nächsten programmierten Start an 
#define OPT_SHOWTIMER 2
//4 = zeigt den noch verbleibenden Speicher in Prozent an.
#define OPT_SHOWPERCENT 4
//8 = erzeugt Popup Menüs mit 4 Einträgen bei ASK1 und ASKS andere ASK Befehle dürfen nicht verwendet werden. 
#define OPT_POP4 8
/*16 = zusammen mit 8 (also 24) wird ein Popup Menu mit 11 Einträgen erzeugt. Die 
Softkeys werden hierdurch verdeckt. Das Menu muß mit dem Griffel oder den 
Navigationstasten (Up,Down,Select) bedient werden. Mit der nur in diesem Modus 
erscheinenden „<“ Taste in der Menuleiste gelangt man zum vorigen Item zurück. 
Ansonsten wie 8 
ANMERKUNG: 
Bei OPT 8+16 wird der gesamte Bildschirm für Text verwendet. Dabei wird der 
proportionale Font des Palm verwendet mit dem ca 30-40 Zeichen pro 
Zeile darstellbar sind. */
#define OPT_POP11 16
/*32 = zusammen mit 8 + 16 erscheint ein OK Knopf in der Menuzeile und die Auswahl 
des Popupmenu muss immer mit OK bestätigt werden, ansonsten wird sofort nach 
Auswahl weitergeschaltet. */
#define OPT_FORCEOK 32
/*64 = eine Checkbox mit der Bezeichnung „Sleep“ wird auf dem Startbildschirm 
 angezeigt. Wird der Haken gesetzt wird das Gerät sofort ausgeschaltet und es 
 werden keine automatischen Alarme mehr erzeugt. 
 Zum Wiedereinschalten der automatischen Alarme muß das Gerät von Hand 
 eingeschaltet und der Haken gelöscht werden. Ist der Startknopf ausgeblendet 
 (GOP=1) dann schaltet sich das Gerät ebenfalls sofort aus. */
#define OPT_SHOWSLEEP 64
//128 = erlaubt es das Programm ohne Sondertaste zu verlassen (Ansonsten muß die Application 2 Taste gedrückt gehalten werden). 
//dynamische Anpassung der Buttongrösse bei Popup 
#define OPT_NOEXIT 128
//#define OPT_PICKER 256
// suppress leading numbers in text header
#define OPT_SNUMB 256
// suppress OK button, if ptimout != 0
#define OPT_NOOK 512
// lock manual input during rel timer
#define OPT_LOCK 1024
// use list instead of buttons
#define OPT_LIST 2048
// back button off
#define OPT_NOBACK 4096


// global options
//1 = Startknopf wird ausgeblendet. Es sind keine Usereingaben mehr möglich, sondern nur programmierte Eingaben 
#define GOPT_NOSTART 1
//2 = Zurück Knopf wird ausgeblendet. Es kann nicht mehr zur letzten Eingabe zurückgegangen werden 
#define GOPT_NOBACK 2
//4 = Benutze alternativen Font bei Popups (Bold Font oder falls ein Narrow.pdb Font existiert dieser) 
// timout setzt den timer auf 15 minuten retry
#define GOPT_NARROWFONT 4
// use list instead of buttons
#define GOPT_LIST 8
// use all space for list items
#define GOPT_ADAPT 16
// use old branch modes for SRH SRL
#define GOPT_BRANCH 32
// save reaction time
#define GOPT_RTIME 64
// PSEL auch bei ASK2 und ASK3
#define GOPT_PSELOPT 128
// supress output dir
#define OPT_NOODIR 256
// auto save no reset
#define GOPT_AS_NCLR 512
// gersdorf switch
#define GOPT_GSWITCH 1024
// local export
#define GOPT_LOCEXP 2048
// dont force syntax
#define GOPT_NFSYNTAX 4096

