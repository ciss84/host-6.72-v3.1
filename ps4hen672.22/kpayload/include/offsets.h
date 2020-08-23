#ifndef __OFFSETS_H__
#define __OFFSETS_H__
#pragma once
// 6.72

// data
#define	XFAST_SYSCALL_addr              0x000001C0
#define M_TEMP_addr                     0x01540EB0
#define MINI_SYSCORE_SELF_BINARY_addr   0x0156A588
#define ALLPROC_addr                    0x022BBE80
#define SBL_DRIVER_MAPPED_PAGES_addr    0x0266AC68
#define SBL_PFS_SX_addr                 0x02679040
#define SBL_KEYMGR_KEY_SLOTS_addr       0x02694570
#define SBL_KEYMGR_KEY_RBTREE_addr      0x02694580
#define SBL_KEYMGR_BUF_VA_addr          0x02698000
#define SBL_KEYMGR_BUF_GVA_addr         0x02698808
#define FPU_CTX_addr                    0x02694080
#define DIPSW_addr                      0x01BD7FD0

// common
#define memcmp_addr                     0x00207E40
#define _sx_xlock_addr                  0x000426C0
#define _sx_xunlock_addr                0x00042880
#define malloc_addr                     0x0000D7A0
#define free_addr                       0x0000D9A0
#define strstr_addr                     0x004817F0
#define fpu_kern_enter_addr             0x0036B6E0
#define fpu_kern_leave_addr             0x0036B7D0
#define memcpy_addr                     0x003C15B0
#define memset_addr                     0x001687D0
#define strlen_addr                     0x002433E0
#define printf_addr                     0x00123280
#define eventhandler_register_addr      0x00402E80

// Fself
#define sceSblACMgrGetPathId_addr       0x00233C70
#define sceSblServiceMailbox_addr       0x0064CC20
#define sceSblAuthMgrSmIsLoadable2_addr 0x0065D7A0
#define _sceSblAuthMgrGetSelfInfo_addr  0x0065E010
#define _sceSblAuthMgrSmStart_addr      0x0065E490
#define sceSblAuthMgrVerifyHeader_addr  0x00660260

// Fpkg
#define RsaesPkcs1v15Dec2048CRT_addr    0x001D6050
#define Sha256Hmac_addr                 0x00335B70
#define AesCbcCfb128Encrypt_addr        0x003C0320
#define AesCbcCfb128Decrypt_addr        0x003C0550
#define sceSblDriverSendMsg_0_addr      0x00637AE0
#define sceSblPfsSetKeys_addr           0x00641520
#define sceSblKeymgrSetKeyStorage_addr  0x00646E00
#define sceSblKeymgrSetKeyForPfs_addr   0x00649800
#define sceSblKeymgrCleartKey_addr      0x00649B80
#define sceSblKeymgrSmCallfunc_addr     0x006493D0

// Patch
#define vmspace_acquire_ref_addr        0x0044CB90
#define vmspace_free_addr               0x0044C9C0
#define vm_map_lock_read_addr           0x0044CD40
#define vm_map_unlock_read_addr         0x0044CD90
#define vm_map_lookup_entry_addr        0x0044D330
#define proc_rwmem_addr                 0x0010EE10

// Fself hooks
#define sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId_hook          0x006591BC
#define sceSblAuthMgrIsLoadable2_hook                               0x0065930F
#define sceSblAuthMgrVerifyHeader_hook1                             0x00659AC6
#define sceSblAuthMgrVerifyHeader_hook2                             0x0065A758
#define sceSblAuthMgrSmLoadSelfSegment__sceSblServiceMailbox_hook   0x0066092A
#define sceSblAuthMgrSmLoadSelfBlock__sceSblServiceMailbox_hook     0x00661571

// Fpkg hooks
#define sceSblKeymgrSetKeyStorage__sceSblDriverSendMsg_hook         0x00646EA5
#define sceSblKeymgrInvalidateKey__sx_xlock_hook                    0x0064AA3D
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_isolated_rif_hook      0x00669500
#define sceSblKeymgrSmCallfunc_npdrm_decrypt_rif_new_hook           0x0066A313
#define mountpfs__sceSblPfsSetKeys_hook1                            0x006CDF15
#define mountpfs__sceSblPfsSetKeys_hook2                            0x006CE141

// SceShellUI patches - debug patches
#define sceSblRcMgrIsAllowDebugMenuForSettings_patch                0x0001D670
#define sceSblRcMgrIsStoreMode_patch                                0x0001D9D0

// SceShellUI patches - remote play patches
#define CreateUserForIDU_patch                                      0x001A0900
#define remote_play_menu_patch                                      0x00EC8291

// SceRemotePlay patches - remote play patches
#define SceRemotePlay_patch1                                        0x0010C6D4
#define SceRemotePlay_patch2                                        0x0010C6EF

// SceShellCore patches
// call sceKernelIsGenuineCEX
#define sceKernelIsGenuineCEX_patch1    0x00189602
#define sceKernelIsGenuineCEX_patch2    0x00835642
#define sceKernelIsGenuineCEX_patch3    0x00880492
#define sceKernelIsGenuineCEX_patch4    0x00A12B92

// call nidf_libSceDipsw
#define nidf_libSceDipsw_patch1         0x00189630
#define nidf_libSceDipsw_patch2         0x00254107
#define nidf_libSceDipsw_patch3         0x00835670
#define nidf_libSceDipsw_patch4         0x00A12BC0

// enable data mount
#define enable_data_mount_patch         0x0033943E

// enable fpkg
#define enable_fpkg_patch               0x003EFCF0
 
// debug pkg free string
#define fake_free_patch                 0x00FD2BF1

// make pkgs installer working with external hdd
#define pkg_installer_patch             0x009FB311

// enable support with 6.xx external hdd
#define ext_hdd_patch1                  0x00606A0D
#define ext_hdd_patch2                  0x00149BF0

// enable debug trophies on retail
#define debug_trophies_patch            0x007268C9

// disable screenshot block
#define disable_screenshot_patch        0x000DD2A6

// 'sce_sdmemory' patch
#define sce_sdmemory_patch				      0x01600060
 
//verify keystone patch
#define verify_keystone_patch			      0x0087F840

//transfer mount permission patch eg mount foreign saves with write permission
#define save_mount_permision			      0x00071130

//some other patch not sure 
#define save_mount_patch				        0x0007379E

//something something patch
#define save_mount_something_patch		  0x00070C38

//patch unk 
#define save_mount_patch_unk			      0x00070855

//save mount never jump
#define save_mount_never_jump			      0x00070054

//save data always jump
#define save_mount_always_jump			    0x00070260

//psn save patch 
#define save_psn_patch					        0x000D6830

// SceShellCore patches - call sceKernelIsAssistMode for Testkits
#define ssc_sceKernelIsAssistMode_patchA 0x00189630

// SceShellCore patches - enable VR without spoof
#define ssc_enable_vr_patch              0x00DDDD70

#endif