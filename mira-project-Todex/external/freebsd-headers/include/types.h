/* SIE CONFIDENTIAL
 * PlayStation(R)4 Programmer Tool Runtime Library Release 05.508.001
 * Copyright (C) 2015 Sony Interactive Entertainment Inc.
 * All Rights Reserved.
 */
/*-
 * Copyright (c) 1982, 1986, 1991, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)types.h	8.6 (Berkeley) 2/19/95
 * $FreeBSD$
 */

#ifndef _SYS_TYPES_H_
#define	_SYS_TYPES_H_

#include <sys/cdefs.h>

/* Machine type dependent parameters. */
#include <machine/endian.h>
#include <sys/_types.h>

#include <sys/_pthreadtypes.h>

#if __BSD_VISIBLE
typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
#ifndef _KERNEL
typedef	unsigned short	ushort;		/* Sys V compatibility */
typedef	unsigned int	uint;		/* Sys V compatibility */
#endif
#endif

/*
 * XXX POSIX sized integrals that should appear only in <sys/stdint.h>.
 */
#include <sys/_stdint.h>

typedef __uint8_t	u_int8_t;	/* unsigned integrals (deprecated) */
typedef __uint16_t	u_int16_t;
typedef __uint32_t	u_int32_t;
typedef __uint64_t	u_int64_t;

typedef	__uint64_t	u_quad_t;	/* quads (deprecated) */
typedef	__int64_t	quad_t;
typedef	quad_t *	qaddr_t;

typedef	char *		caddr_t;	/* core address */
typedef	__const char *	c_caddr_t;	/* core address, pointer to const */
typedef	__volatile char *v_caddr_t;	/* core address, pointer to volatile */

#include <sys/_types/_blksize_t.h>

typedef	__cpuwhich_t	cpuwhich_t;
typedef	__cpulevel_t	cpulevel_t;
typedef	__cpusetid_t	cpusetid_t;

#include <sys/_types/_blkcnt_t.h>

typedef	__cap_rights_t	cap_rights_t;

#include <sys/_types/_clock_t.h>

#include <sys/_types/_clockid_t.h>

typedef	__critical_t	critical_t;	/* Critical section value */
typedef	__int64_t	daddr_t;	/* disk address */

#include <sys/_types/_dev_t.h>

#include <sys/_types/_fflags_t.h>

typedef	__fixpt_t	fixpt_t;	/* fixed point number */

/* for statvfs() */
typedef	__fsblkcnt_t	fsblkcnt_t;
typedef	__fsfilcnt_t	fsfilcnt_t;

#include <sys/_types/_gid_t.h>

#include <sys/_types/_in_addr_t.h>

#include <sys/_types/_in_port_t.h>

typedef	__id_t		id_t;		/* can hold a uid_t or pid_t */

#include <sys/_types/_ino_t.h>

typedef	__key_t		key_t;		/* IPC key (for Sys V IPC) */

#ifndef _LWPID_T_DECLARED
typedef	__lwpid_t	lwpid_t;	/* Thread ID (a.k.a. LWP) */
#define _LWPID_T_DECLARED
#endif


#include <sys/_types/_mode_t.h>

typedef	__accmode_t	accmode_t;	/* access permissions */

#include <sys/_types/_nlink_t.h>

#include <sys/_types/_off_t.h>

#include <sys/_types/_pid_t.h>

typedef	__register_t	register_t;

#ifndef _RLIM_T_DECLARED
typedef	__rlim_t	rlim_t;		/* resource limit */
#define _RLIM_T_DECLARED
#endif

typedef	__segsz_t	segsz_t;	/* segment size (in pages) */

#include <sys/_types/_size_t.h>

#include <sys/_types/_ssize_t.h>

#include <sys/_types/_suseconds_t.h>

#include <sys/_types/_time_t.h>

typedef	__timer_t	timer_t;

typedef	__mqd_t	mqd_t;

typedef	__u_register_t	u_register_t;

#include <sys/_types/_uid_t.h>

#include <sys/_types/_useconds_t.h>

typedef	__vm_offset_t	vm_offset_t;
typedef	__vm_ooffset_t	vm_ooffset_t;
typedef	__vm_paddr_t	vm_paddr_t;
typedef	__vm_pindex_t	vm_pindex_t;
typedef	__vm_size_t	vm_size_t;

#ifdef _KERNEL
typedef	int		boolean_t;
typedef	struct device	*device_t;
typedef	__intfptr_t	intfptr_t;

/*
 * XXX this is fixed width for historical reasons.  It should have had type
 * __int_fast32_t.  Fixed-width types should not be used unless binary
 * compatibility is essential.  Least-width types should be used even less
 * since they provide smaller benefits.
 *
 * XXX should be MD.
 *
 * XXX this is bogus in -current, but still used for spl*().
 */
typedef	__uint32_t	intrmask_t;	/* Interrupt mask (spl, xxx_imask...) */

typedef	__uintfptr_t	uintfptr_t;
typedef	__uint64_t	uoff_t;
typedef	char		vm_memattr_t;	/* memory attribute codes */
typedef	struct vm_page	*vm_page_t;

#define offsetof(type, field) __offsetof(type, field)

#endif /* !_KERNEL */

/*
 * The following are all things that really shouldn't exist in this header,
 * since its purpose is to provide typedefs, not miscellaneous doodads.
 */
#if __BSD_VISIBLE

#include <sys/select.h>

/*
 * minor() gives a cookie instead of an index since we don't want to
 * change the meanings of bits 0-15 or waste time and space shifting
 * bits 16-31 for devices that don't use them.
 */
#define	major(x)	((int)(((u_int)(x) >> 8)&0xff))	/* major number */
#define	minor(x)	((int)((x)&0xffff00ff))		/* minor number */
#define	makedev(x,y)	((dev_t)(((x) << 8) | (y)))	/* create dev_t */

/*
 * These declarations belong elsewhere, but are repeated here and in
 * <stdio.h> to give broken programs a better chance of working with
 * 64-bit off_t's.
 */
#ifndef _KERNEL
#include <sys/_types/_ftruncate.h>
#include <sys/_types/_lseek.h>
#include <sys/_types/_mmap.h>
#include <sys/_types/_truncate.h>
#endif /* !_KERNEL */

#endif /* __BSD_VISIBLE */

#endif /* !_SYS_TYPES_H_ */
