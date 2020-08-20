/* SIE CONFIDENTIAL
 * PlayStation(R)4 Programmer Tool Runtime Library Release 05.508.001
 * Copyright (C) 2015 Sony Interactive Entertainment Inc.
 * All Rights Reserved.
 */

#pragma once

#include <sys/_types/_lldiv.h>

_C_LIB_DECL

#ifndef _LDIV_T_DECLARED
#define _LDIV_T_DECLARED
typedef struct
{	/* result of long divide */
	long quot;
	long rem;
} ldiv_t;

typedef _Lldiv_t lldiv_t;


extern long labs(long);
extern _Longlong llabs(_Longlong);
extern ldiv_t ldiv(long, long);
extern lldiv_t lldiv(_Longlong, _Longlong);
#endif

_END_C_LIB_DECL
