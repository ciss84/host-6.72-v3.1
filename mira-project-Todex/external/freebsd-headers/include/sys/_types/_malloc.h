/* SIE CONFIDENTIAL
 * PlayStation(R)4 Programmer Tool Runtime Library Release 05.508.001
 * Copyright (C) 2015 Sony Interactive Entertainment Inc.
 * All Rights Reserved.
 */

#pragma once

#include <yvals.h>
#include <stddef.h>

_C_LIB_DECL

#ifndef _SCE_LIBC_MALLOC_MANAGED_SIZE
#define _SCE_LIBC_MALLOC_MANAGED_SIZE
typedef struct SceLibcMallocManagedSize {
  unsigned short size;
  unsigned short version;
  unsigned int reserved1;
  size_t maxSystemSize;
  size_t currentSystemSize;
  size_t maxInuseSize;
  size_t currentInuseSize;
} SceLibcMallocManagedSize;
#endif

_END_C_LIB_DECL
