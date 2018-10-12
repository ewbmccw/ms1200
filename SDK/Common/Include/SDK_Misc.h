/**
************************************************************************************************
* @file			SDK_Misc.h
* @author		Solution Team
* @brief		SDK miscellaneous define header file
************************************************************************************************
* @attention
*
* Copyright(c) 2015 ~ 2020 eWBM Korea, Ltd.
* All rights reserved.
* This software contains confidential information of eWBM Korea Co., Ltd.
* And unauthorized distribution of this software, or any portion of it are prohibited.
*
************************************************************************************************
*/

#ifndef	_SYSTEM_MISC_H_
#define	_SYSTEM_MISC_H_

extern U8 BitPositionGet(U16 bit);
extern U16 BitPositionSet(U8 number);
extern void Assert(S8 *Exp, S8 *File, U32 Line);

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
