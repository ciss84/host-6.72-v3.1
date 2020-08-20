/* SIE CONFIDENTIAL
 * PlayStation(R)4 Programmer Tool Runtime Library Release 05.508.001
 * Copyright (C) 2015 Sony Interactive Entertainment Inc.
 * All Rights Reserved.
 */

#pragma once

#include <yvals.h>

#ifndef _LLDIV_T
#define _LLDIV_T
typedef struct
{	/* result of long long divide */
	_Longlong quot;
	_Longlong rem;
} _Lldiv_t;
#endif
