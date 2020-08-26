#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once

// 6.72
#define	XFAST_SYSCALL_addr              0x000001C0

// Names - Data
#define PRISON0_addr                    0x0113E518
#define ROOTVNODE_addr                  0x02300320
#define PMAP_STORE_addr                 0x01BB7880
#define DT_HASH_SEGMENT_addr            0x00C00468

// Functions
#define pmap_protect_addr               0x00050F50
#define pmap_protect_p_addr             0x00050F9C

// Patches
// debug menu error
#define debug_menu_error_patch1         0x00504A94
#define debug_menu_error_patch2         0x00504C77
#define debug_menu_error_patch3         0x00507A01
#define debug_menu_error_patch4         0x00507B09
#define debug_menu_error_patch5         0x00507BB8
#define debug_menu_error_patch6         0x00507ECF
#define debug_menu_error_patch7         0x00508D5C
#define debug_menu_error_patch8         0x00510423
#define debug_menu_error_patch9         0x005108E3
#define debug_menu_error_patch10        0x00510BFA
#define debug_menu_error_patch11        0x005115E1
#define debug_menu_error_patch12        0x00511B4D
#define debug_menu_error_patch13        0x00512002
#define debug_menu_error_patch14        0x00512191
#define debug_menu_error_patch15        0x005140A8
#define debug_menu_error_patch16        0x00514293
#define debug_menu_error_patch17        0x00515E71
#define debug_menu_error_patch18        0x00515EE7
#define debug_menu_error_patch19        0x00515F71
#define debug_menu_error_patch20        0x00515F8D
#define debug_menu_error_patch21        0x0051F123

// disable signature check
#define disable_signature_check_patch   0x006A8EB0

// enable debug RIFs
#define enable_debug_rifs_patch1        0x0066AEB0
#define enable_debug_rifs_patch2        0x0066AEE0

// allow sys_dynlib_dlsym in all processes
#define sys_dynlib_dlsym_patch          0x001D895A

// sdk version spoof - enable all VR fws
#define sdk_version_patch               0x0044C79B
#define sdk_version_patch1              0x0044D719
#define sdk_version_patch2              0x0044D7BA
#define sdk_version_patch3              0x00666158
#define sdk_version_patch4              0x006A9DB2
#define sdk_version_patch5              0x0077A5B4
#define sdk_version_patch6              0x0078315D
#define sdk_version_patch7              0x01A84248
#define sdk_version_patch8              0x022C0718
#define sdk_version_patch9              0x02926C81
#define sdk_version_patch20             0x007AFDBF
#define sdk_version_patch21             0x00854B70
#define sdk_version_patch22             0x00854C4D
#define sdk_version_patch23             0x00B48982
    
// enable debug log
#define enable_debug_log_patch          0x00123367

// enable uart output
#define enable_uart_patch               0x01A6EB18

#endif