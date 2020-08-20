/* SIE CONFIDENTIAL
 * PlayStation(R)4 Programmer Tool Runtime Library Release 05.508.001
 * Copyright (C) 2015 Sony Interactive Entertainment Inc.
 * All Rights Reserved.
 */

#pragma once

#include <sys/_types.h>
#include <yvals.h>

_C_STD_BEGIN

#ifndef _MBSTATET
#define _MBSTATET
typedef struct _Mbstatet
	{	/* state of a multibyte translation */
	unsigned long _Wchar;
	unsigned short _Byte, _State;
	int :32;

 #ifdef __cplusplus
	_Mbstatet()
		: _Wchar(0), _Byte(0), _State(0)
		{	// default construct
		}

	_Mbstatet(const _Mbstatet& _Right)
		: _Wchar(_Right._Wchar), _Byte(_Right._Byte),
			_State(_Right._State)
		{	// copy construct
		}

	_Mbstatet& operator=(const _Mbstatet& _Right)
		{	// assign
		_Wchar = _Right._Wchar;
		_Byte = _Right._Byte;
		_State = _Right._State;
		return (*this);
		}
 #endif /* __cplusplus */
	} _Mbstatet;
#endif

_C_STD_END
