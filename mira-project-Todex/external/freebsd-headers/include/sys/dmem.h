/* SIE CONFIDENTIAL
PlayStation(R)4 Programmer Tool Runtime Library Release 05.508.001
* Copyright (C) 2014 Sony Interactive Entertainment Inc.
* All Rights Reserved.
*/

#ifndef	_SCE_KERNEL_SYS_DMEM_H_
#define	_SCE_KERNEL_SYS_DMEM_H_

#include <sys/types.h>

typedef enum {
  SCE_KERNEL_WB_ONION  = 0,
  SCE_KERNEL_WC_GARLIC = 3,

  SCE_KERNEL_WB_ONION_VOLATILE __attribute__ ((deprecated)) = 0,
  SCE_KERNEL_WB_ONION_NONVOLATILE __attribute__ ((deprecated)),
  SCE_KERNEL_WC_GARLIC_VOLATILE __attribute__ ((deprecated)),
  SCE_KERNEL_WC_GARLIC_NONVOLATILE __attribute__ ((deprecated)),
  SCE_KERNEL_WT_ONION_VOLATILE __attribute__ ((deprecated)),
  SCE_KERNEL_WT_ONION_NONVOLATILE __attribute__ ((deprecated)),
  SCE_KERNEL_WP_ONION_VOLATILE __attribute__ ((deprecated)),
  SCE_KERNEL_WP_ONION_NONVOLATILE __attribute__ ((deprecated)),
  SCE_KERNEL_UC_GARLIC_VOLATILE __attribute__ ((deprecated)),
  SCE_KERNEL_UC_GARLIC_NONVOLATILE __attribute__ ((deprecated)),
  SCE_KERNEL_WB_GARLIC,

  SCE_KERNEL_MEMORY_TYPE_END
} SceKernelMemoryType;

#define SCE_KERNEL_MAIN_DMEM_SIZE   (sceKernelGetDirectMemorySize())

#if defined(__INTELLISENSE__)
enum : long long {
#else
enum {
#endif
	__SCE_KERNEL_MAIN_DMEM_OFFSET
		__attribute__ ((deprecated)) = 0x0000000000L,
	__SCE_KERNEL_DMEM_END
		__attribute__ ((deprecated)) = 0x5000000000L,
	__SCE_KERNEL_GPU_SHARED_DMEM_OFFSET
		__attribute__ ((deprecated)) = 0x1000000000L,
	__SCE_KERNEL_GPU_PRIVATE_DMEM_OFFSET
		__attribute__ ((deprecated)) = 0x2000000000L,
	__SCE_KERNEL_GPU_SHARED_DMEM_SIZE
		__attribute__ ((deprecated)) = 0x0d000000L,
	__SCE_KERNEL_GPU_PRIVATE_DMEM_SIZE
		__attribute__ ((deprecated)) = 0x80000000L
};

// The following definitions will be removed soon
#define SCE_KERNEL_MAIN_DMEM_OFFSET	   __SCE_KERNEL_MAIN_DMEM_OFFSET
#ifndef SCE_KERNEL_DMEM_END
#define SCE_KERNEL_DMEM_END		   __SCE_KERNEL_DMEM_END
#endif
#define SCE_KERNEL_GPU_SHARED_DMEM_OFFSET  __SCE_KERNEL_GPU_SHARED_DMEM_OFFSET
#define SCE_KERNEL_GPU_PRIVATE_DMEM_OFFSET __SCE_KERNEL_GPU_PRIVATE_DMEM_OFFSET
#define SCE_KERNEL_GPU_SHARED_DMEM_SIZE    __SCE_KERNEL_GPU_SHARED_DMEM_SIZE
#define SCE_KERNEL_GPU_PRIVATE_DMEM_SIZE   __SCE_KERNEL_GPU_PRIVATE_DMEM_SIZE

#define	SCE_KERNEL_PROT_CPU_READ  0x01
#define	SCE_KERNEL_PROT_CPU_RW	  0x02
#define	SCE_KERNEL_PROT_CPU_EXEC  0x04
#define	SCE_KERNEL_PROT_CPU_ALL	  0x07
#define SCE_KERNEL_PROT_GPU_READ  0x10
#define SCE_KERNEL_PROT_GPU_WRITE 0x20
#define SCE_KERNEL_PROT_GPU_RW	  0x30
#define SCE_KERNEL_PROT_GPU_ALL	  0x30
#define SCE_KERNEL_PAGE_SIZE	  16384

#define	SCE_KERNEL_PROT_CPU_WRITE	SCE_KERNEL_PROT_CPU_RW

#define SCE_KERNEL_MAP_FIXED		0x0010
#define SCE_KERNEL_MAP_NO_OVERWRITE	0x0080
#define SCE_KERNEL_MAP_DMEM_COMPAT	0x0400
#define SCE_KERNEL_MAP_NO_COALESCE	0x400000

#if defined(__INTELLISENSE__)
enum : long long {
#else
enum {
#endif
	__SCE_KERNEL_FIXED_PRT_APERTURE_START_ADDR
		__attribute__ ((deprecated)) = 0x0f00000000UL,
	__SCE_KERNEL_FIXED_PRT_APERTURE_SIZE
		__attribute__ ((deprecated)) = 0x0010000000UL,
	__SCE_KERNEL_FIXED_PRT_APERTURE_END_ADDR
		__attribute__ ((deprecated)) = 0x0f00000000UL + 0x0010000000UL
};

#define SCE_KERNEL_FIXED_PRT_APERTURE_START_ADDR \
	__SCE_KERNEL_FIXED_PRT_APERTURE_START_ADDR
#define SCE_KERNEL_FIXED_PRT_APERTURE_SIZE \
	__SCE_KERNEL_FIXED_PRT_APERTURE_SIZE
#define SCE_KERNEL_FIXED_PRT_APERTURE_END_ADDR \
	__SCE_KERNEL_FIXED_PRT_APERTURE_END_ADDR

#define SCE_KERNEL_APP_MAP_AREA_START_ADDR		0x1000000000UL
#define SCE_KERNEL_APP_MAP_AREA_END_ADDR		0xfc00000000UL
#define SCE_KERNEL_APP_MAP_AREA_SIZE \
  (SCE_KERNEL_APP_MAP_AREA_END_ADDR - SCE_KERNEL_APP_MAP_AREA_START_ADDR)

#define SCE_KERNEL_MAX_MAP_ALIGNMENT		31
#define SCE_KERNEL_MAX_PRT_APERTURE_INDEX	2

__BEGIN_DECLS

typedef enum {
  SCE_KERNEL_MAP_OP_MAP_DIRECT,
  SCE_KERNEL_MAP_OP_UNMAP,
  SCE_KERNEL_MAP_OP_PROTECT,
  SCE_KERNEL_MAP_OP_MAP_FLEXIBLE,
  SCE_KERNEL_MAP_OP_TYPE_PROTECT,
} SceKernelMapEntryOperation;

typedef struct
{
	void	*start;
	off_t	offset;
  	size_t	length;
	char	protection;
	char	type;
	short   pad1;
	int	operation;
} SceKernelBatchMapEntry;

#define SCE_KERNEL_VIRTUAL_RANGE_NAME_SIZE	32

typedef struct
{
	void	 *start;
	void	 *end;
	off_t	  offset;
	int	  protection;
	int	  memoryType;
	unsigned  isFlexibleMemory:1;
	unsigned  isDirectMemory:1;
	unsigned  isStack:1;
	unsigned  isPooledMemory:1;
	unsigned  isCommitted:1;
	char      name[SCE_KERNEL_VIRTUAL_RANGE_NAME_SIZE];
} SceKernelVirtualQueryInfo;

#define SCE_KERNEL_VQ_FIND_NEXT 1

typedef struct
{
	off_t	 start;
	off_t	 end;
	int	 memoryType;
} SceKernelDirectMemoryQueryInfo;

#define SCE_KERNEL_DMQ_FIND_NEXT 1

#define SCE_KERNEL_MEMORY_POOL_OP_COMMIT	1
#define SCE_KERNEL_MEMORY_POOL_OP_DECOMMIT	2
#define SCE_KERNEL_MEMORY_POOL_OP_PROTECT	3
#define SCE_KERNEL_MEMORY_POOL_OP_TYPE_PROTECT	4
#define SCE_KERNEL_MEMORY_POOL_OP_MOVE		5

typedef struct
{
	unsigned	op;
	unsigned	flags;
	union {
		struct {
			void		*addr;
			size_t		len;
			unsigned char	prot;
			unsigned char	type;
		} commit;
		struct {
			void		*addr;
			size_t		len;
		} decommit;
		struct {
			void		*addr;
			size_t		len;
			unsigned char	prot;
		} protect;
		struct {
			void		*addr;
			size_t		len;
			unsigned char	prot;
			unsigned char	type;
		} typeProtect;
		struct {
			void		*dst;
			void		*src;
			size_t		len;
		} move;
		uintptr_t	padding[3];
	};
} SceKernelMemoryPoolBatchEntry;

typedef struct
{
	int availableFlushedBlocks;
	int availableCachedBlocks;
	int allocatedFlushedBlocks;
	int allocatedCachedBlocks;
} SceKernelMemoryPoolBlockStats;

size_t sceKernelGetDirectMemorySize();

int32_t sceKernelMapFlexibleMemory(void** addrInOut, size_t len,
				   int prot, int flags);
int32_t sceKernelReleaseFlexibleMemory(void* addr, size_t len);
int32_t sceKernelSetPrtAperture(int index, void *addr, size_t len);
int32_t sceKernelGetPrtAperture(int index, void **addr, size_t *len);

int32_t sceKernelAllocateDirectMemory(off_t searchStart, off_t searchEnd,
				      size_t len, size_t alignment,
				      int memoryType,
				      off_t *physAddrOut);
int32_t sceKernelAllocateMainDirectMemory(size_t len, size_t alignment,
					  int memoryType,
					  off_t *physAddrOut);
int32_t sceKernelReleaseDirectMemory(off_t start, size_t len);
int32_t sceKernelCheckedReleaseDirectMemory(off_t start, size_t len);
int32_t sceKernelMapDirectMemory(void **addr, size_t len,
				 int prot, int flags, off_t directMemoryStart,
				 size_t maxPageSize);
int32_t sceKernelMapDirectMemory2(void **addr, size_t len,
				  int type, int prot,
				  int flags, off_t directMemoryStart,
				 size_t maxPageSize);
int32_t sceKernelGetDirectMemoryType(off_t start,
				     int *memoryType,
				     off_t *regionStartOut,
				     off_t *regionEndOut);

int32_t sceKernelBatchMap(SceKernelBatchMapEntry* entries,
			  int numberOfEntries,
			  int* numberOfEntriesOut);
int32_t sceKernelBatchMap2(SceKernelBatchMapEntry* entries,
			   int numberOfEntries,
			   int* numberOfEntriesOut,
			   int flags);

int32_t
sceKernelJitCreateSharedMemory(const char *name, size_t len, int maxProt,
			       int *fdOut);
int32_t sceKernelJitCreateAliasOfSharedMemory(int fd, int maxProt, int *fdOut);
int32_t sceKernelJitMapSharedMemory(int fd, int prot, void **startOut);
int32_t sceKernelJitGetSharedMemoryInfo(int fd, char* name, int nameBufferSize,
					void **startOut, size_t *lenOut,
					int *maxProtOut);

int32_t sceKernelQueryMemoryProtection(void* addr,
				       void** start, void** end, int* prot);
int32_t sceKernelIsStack(void* addr, void** start, void** end);
int32_t sceKernelVirtualQuery(const void *addr, int flags,
			      SceKernelVirtualQueryInfo *info,
			      size_t infoSize);
int32_t sceKernelSetVirtualRangeName(void* start, size_t len,
    const char *name);

int32_t sceKernelMapNamedFlexibleMemory(void** addrInOut, size_t len,
					int prot, int flags, const char *name);
int32_t sceKernelMapNamedDirectMemory(void **addr, size_t len,
				      int prot, int flags,
				      off_t directMemoryStart,
				      size_t alignment, const char *name);
int sceKernelReserveVirtualRange(void **addr, size_t len, int flags,
				 size_t alignment);

int32_t sceKernelDirectMemoryQuery(off_t   offset,
				   int	   flags,
				   void   *info,
				   size_t  infoSize);
int32_t sceKernelMtypeprotect(const void *addr, size_t size, int type,
    int prot);

int32_t sceKernelAvailableDirectMemorySize(off_t   start,
					   off_t   end,
					   size_t  alignment,
					   off_t  *startOut,
					   size_t *sizeOut);
int32_t sceKernelGetPageTableStats(int* cpuTotal, int* cpuAvailable,
				   int* gpuTotal, int* gpuAvailable);


int32_t sceKernelMemoryPoolBatch(const SceKernelMemoryPoolBatchEntry *entries,
    int n, int *indexOut, int flags);
int32_t sceKernelMemoryPoolCommit(void *addr, size_t len, int type, int prot,
    int flags);
int32_t sceKernelMemoryPoolDecommit(void *addr, size_t len, int flags);
int32_t sceKernelMemoryPoolExpand(off_t searchStart, off_t searchEnd,
    size_t len, size_t alignment, off_t *physAddrOut);
int32_t sceKernelMemoryPoolGetBlockStats(SceKernelMemoryPoolBlockStats *output,
    size_t outputSize);
int32_t sceKernelMemoryPoolMove(void *dst, void *src, size_t len, int flags);
int32_t sceKernelMemoryPoolReserve(void *addrIn, size_t len, size_t alignment,
    int flags, void **addrOut);

__END_DECLS

#endif /* !_SCE_KERNEL_SYS_DMEM_H_ */
