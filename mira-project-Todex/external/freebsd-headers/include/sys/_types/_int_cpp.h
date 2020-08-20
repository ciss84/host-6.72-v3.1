/* SIE CONFIDENTIAL
 * PlayStation(R)4 Programmer Tool Runtime Library Release 05.508.001
 * Copyright (C) 2015 Sony Interactive Entertainment Inc.
 * All Rights Reserved.
 */

#pragma once

#ifdef __cplusplus

#include <sys/_types/_int.h>

_C_LIB_DECL

extern "C++" {

  // OVERLOADS, FOR C++

#ifndef _SCE_LIBC_ABS_DIV_DECL /* B#860 */
  // There were different definitions for abs and div in inttypes.h, but Linux didn't have them.
  inline long abs(long _Left)
  {	// compute abs
    return (labs(_Left));
  }

  inline ldiv_t div(long _Left, long _Right)
  {	// compute quotient and remainder
    return (ldiv(_Left, _Right));
  }
#define _SCE_LIBC_ABS_DIV_DECL
#endif /*_SCE_LIBC_ABS_DIV_DECL*/ /* B#860 */

#if defined(_LONGLONG)
  inline _Longlong abs(_Longlong _Left)
  {	// compute abs
    return (llabs(_Left));
  }

  inline _Lldiv_t div(_Longlong _Left, _Longlong _Right)
  {	// compute quotient and remainder
    return (lldiv(_Left, _Right));
  }
#endif /* !defined(_LLDIV_T) && defined(_LONGLONG) */

}	// extern "C++"

_END_C_LIB_DECL

#endif // __cplusplus
