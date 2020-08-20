/* SIE CONFIDENTIAL
 * PlayStation(R)4 Programmer Tool Runtime Library Release 05.508.001
 * Copyright (C) 2015 Sony Interactive Entertainment Inc.
 * All Rights Reserved.
 */

#pragma once

#ifndef _BYTEORDER_PROTOTYPED
#define _BYTEORDER_PROTOTYPED

#ifndef _BYTEORDER_FUNC_DEFINED
#define _BYTEORDER_FUNC_DEFINED

#ifndef htonll
#define htonll(llv) (uint64_t)({ \
	uint64_t _v = (llv); \
	(_v << 56) \
	| ((_v & 0xff00) << 40) \
	| ((_v & 0xff0000) << 24) \
	| ((_v & 0xff000000) << 8) \
	| ((_v >> 8) & 0xff000000) \
	| ((_v >> 24) & 0xff0000) \
	| ((_v >> 40) & 0xff00) \
	| ((_v >> 56) & 0xff); \
})
#endif

#ifndef htonl
#define htonl(lv) (uint32_t)({ \
	uint32_t _v = (lv); \
	(_v << 24) | ((_v & 0xff00) << 8) \
	| ((_v >> 8) & 0xff00) | (_v >> 24); \
	})
#endif

#ifndef htons
#define htons(sv) (uint16_t)({ \
	uint16_t _v = (sv); \
	((_v << 8) & 0xff00) | ((_v >> 8) & 0x00ff); \
})
#endif

#ifndef ntohll
#define ntohll(llv)  htonll(llv)
#endif

#ifndef ntohl
#define ntohl(lv)    htonl(lv)
#endif

#ifndef ntohs
#define ntohs(sv)    htons(sv)
#endif

#endif // _BYTEORDER_FUNC_DEFINED
#endif // _BYTEORDER_PROTOTYPED

#ifndef INET_ADDRSTRLEN
#define	INET_ADDRSTRLEN		16
#endif
