/* SIE CONFIDENTIAL
 * PlayStation(R)4 Programmer Tool Runtime Library Release 05.508.001
 * Copyright (C) 2015 Sony Interactive Entertainment Inc.
 * All Rights Reserved.
 */

#pragma once

#include <sys/_types/_off_t.h>
#include <sys/_types/_size_t.h>

__BEGIN_DECLS
#ifndef _MMAP_DECLARED
#define _MMAP_DECLARED
void *	mmap(void *, size_t, int, int, int, off_t);
#endif
__END_DECLS
