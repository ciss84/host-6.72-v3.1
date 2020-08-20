/* SIE CONFIDENTIAL
 * PlayStation(R)4 Programmer Tool Runtime Library Release 05.508.001
 * Copyright (C) 2015 Sony Interactive Entertainment Inc.
 * All Rights Reserved.
 */

#pragma once

#ifndef _TYPEID
#ifdef __GXX_RTTI
#define _TYPEID(x) typeid(x)
#else /* __GXX_RTTI */
#define _TYPEID(x) (*(std::type_info const *)0)
#endif /* __GXX_RTTI */
#endif
