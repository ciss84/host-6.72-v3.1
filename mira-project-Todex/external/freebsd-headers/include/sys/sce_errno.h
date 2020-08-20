/* SIE CONFIDENTIAL
 * PlayStation(R)4 Programmer Tool Runtime Library Release 05.508.001
 * Copyright (C) 2013 Sony Interactive Entertainment Inc.
 * All Rights Reserved.
 */

/*-
 * Copyright (c) 1982, 1986, 1989, 1993
 *      The Regents of the University of California.  All rights reserved.
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
 *      @(#)errno.h     8.5 (Berkeley) 1/21/94
 * $FreeBSD$
 */

#ifndef _SCE_SYS_SCE_ERRNO_H
#define _SCE_SYS_SCE_ERRNO_H

#if defined(__cplusplus)
extern "C" {
#endif

#define SCE_KERNEL_ERROR_UNKNOWN         0x80020000

/*
 * Error number definition
 */

/**
 * @j 許可されていない操作 @ej
 * @e Operation not permitted @ee
 */
#define SCE_KERNEL_ERROR_EPERM					-2147352575	/* 0x80020001 */

/**
 * @j そのようなファイル、ディレクトリはない @ej
 * @e No such file or directory @ee
 */
#define SCE_KERNEL_ERROR_ENOENT					-2147352574	/* 0x80020002 */

/**
 * @j そのようなプロセスはない @ej
 * @e No such process @ee
 */
#define SCE_KERNEL_ERROR_ESRCH					-2147352573	/* 0x80020003 */

/**
 * @j システムコールが中断された @ej
 * @e Interrupted system call @ee
 */
#define SCE_KERNEL_ERROR_EINTR					-2147352572	/* 0x80020004 */

/**
 * @j I/Oエラー @ej
 * @e Input/output error @ee
 */
#define SCE_KERNEL_ERROR_EIO					-2147352571	/* 0x80020005 */

/**
 * @j デバイスが初期化されていない @ej
 * @e Device not configured @ee
 */
#define SCE_KERNEL_ERROR_ENXIO					-2147352570	/* 0x80020006 */

/**
 * @j 引数のリストが長い @ej
 * @e Argument list too long @ee
 */
#define SCE_KERNEL_ERROR_E2BIG					-2147352569	/* 0x80020007 */

/**
 * @j 実行フォーマットエラー @ej
 * @e Exec format error @ee
 */
#define SCE_KERNEL_ERROR_ENOEXEC				-2147352568	/* 0x80020008 */

/**
 * @j ファイルディスクリプタが不正 @ej
 * @e Bad file descriptor @ee
 */
#define SCE_KERNEL_ERROR_EBADF					-2147352567	/* 0x80020009 */

/**
 * @j 子プロセスがない @ej
 * @e No child processes @ee
 */
#define SCE_KERNEL_ERROR_ECHILD					-2147352566	/* 0x8002000A */

/**
 * @j デッドロックを検出 @ej
 * @e Resource deadlock avoided @ee
 */
#define SCE_KERNEL_ERROR_EDEADLK				-2147352565	/* 0x8002000B */

/**
 * @j メモリが割り当てられない @ej
 * @e Cannot allocate memory @ee
 */
#define SCE_KERNEL_ERROR_ENOMEM					-2147352564	/* 0x8002000C */

/**
 * @j パーミッションがない @ej
 * @e Permission denied @ee
 */
#define SCE_KERNEL_ERROR_EACCES					-2147352563	/* 0x8002000D */

/**
 * @j アドレスが不正 @ej
 * @e Bad address @ee
 */
#define SCE_KERNEL_ERROR_EFAULT					-2147352562	/* 0x8002000E */

/**
 * @j ブロックデバイスではない @ej
 * @e Block device required @ee
 */
#define SCE_KERNEL_ERROR_ENOTBLK				-2147352561	/* 0x8002000F */

/**
 * @j デバイス使用中 @ej
 * @e Device busy @ee
 */
#define SCE_KERNEL_ERROR_EBUSY					-2147352560	/* 0x80020010 */

/**
 * @j ファイルが存在する @ej
 * @e File exists @ee
 */
#define SCE_KERNEL_ERROR_EEXIST					-2147352559	/* 0x80020011 */

/**
 * @j デバイスを越えたリンク @ej
 * @e Cross-device link @ee
 */
#define SCE_KERNEL_ERROR_EXDEV					-2147352558	/* 0x80020012 */

/**
 * @j そのデバイスではサポートされない操作 @ej
 * @e Operation not supported by device @ee
 */
#define SCE_KERNEL_ERROR_ENODEV					-2147352557	/* 0x80020013 */

/**
 * @j ディレクトリではない @ej
 * @e Not a directory @ee
 */
#define SCE_KERNEL_ERROR_ENOTDIR				-2147352556	/* 0x80020014 */

/**
 * @j ディレクトリである @ej
 * @e Is a directory @ee
 */
#define SCE_KERNEL_ERROR_EISDIR					-2147352555	/* 0x80020015 */

/**
 * @j 引数が不正 @ej
 * @e Invalid argument @ee
 */
#define SCE_KERNEL_ERROR_EINVAL					-2147352554	/* 0x80020016 */

/**
 * @j システムでオープンできるファイル数を超えた @ej
 * @e Too many open files in system @ee
 */
#define SCE_KERNEL_ERROR_ENFILE					-2147352553	/* 0x80020017 */

/**
 * @j オープンできるファイル数を超えた @ej
 * @e Too many open files @ee
 */
#define SCE_KERNEL_ERROR_EMFILE					-2147352552	/* 0x80020018 */

/**
 * @j 不適切な ioctl @ej
 * @e Inappropriate ioctl for device @ee
 */
#define SCE_KERNEL_ERROR_ENOTTY					-2147352551	/* 0x80020019 */

/**
 * @j テキストファイルが使用中 @ej
 * @e Text file busy @ee
 */
#define SCE_KERNEL_ERROR_ETXTBSY				-2147352550	/* 0x8002001A */

/**
 * @j ファイルが大きすぎる @ej
 * @e File too large @ee
 */
#define SCE_KERNEL_ERROR_EFBIG					-2147352549	/* 0x8002001B */

/**
 * @j デバイスに残りスペースがない @ej
 * @e No space left on device @ee
 */
#define SCE_KERNEL_ERROR_ENOSPC					-2147352548	/* 0x8002001C */

/**
 * @j 不正なシーク @ej
 * @e Illegal seek @ee
 */
#define SCE_KERNEL_ERROR_ESPIPE					-2147352547	/* 0x8002001D */

/**
 * @j 読み込み専用のファイルシステム @ej
 * @e Read-only filesystem @ee
 */
#define SCE_KERNEL_ERROR_EROFS					-2147352546	/* 0x8002001E */

/**
 * @j リンクが多すぎる @ej
 * @e Too many links @ee
 */
#define SCE_KERNEL_ERROR_EMLINK					-2147352545	/* 0x8002001F */

/**
 * @j パイプが壊れた @ej
 * @e Broken pipe @ee
 */
#define SCE_KERNEL_ERROR_EPIPE					-2147352544	/* 0x80020020 */

/**
 * @j 数値の引数が定義域ではない @ej
 * @e Numerical argument out of domain @ee
 */
#define SCE_KERNEL_ERROR_EDOM					-2147352543	/* 0x80020021 */

/**
 * @j 結果が大きすぎる @ej
 * @e Result too large @ee
 */
#define SCE_KERNEL_ERROR_ERANGE					-2147352542	/* 0x80020022 */

/**
 * @j リソースが一時的に利用できない @ej
 * @e Resource temporarily unavailable @ee
 */
#define SCE_KERNEL_ERROR_EAGAIN					-2147352541	/* 0x80020023 */

/**
 * @j 操作がブロックされる @ej
 * @e Operation would block (SCE_KERNEL_ERROR_EAGAIN) @ee
 */
#define SCE_KERNEL_ERROR_EWOULDBLOCK			-2147352541	/* 0x80020023 */

/**
 * @j 操作は処理中 @ej
 * @e Operation now in progress @ee
 */
#define SCE_KERNEL_ERROR_EINPROGRESS			-2147352540	/* 0x80020024 */

/**
 * @j 操作は既に処理中 @ej
 * @e Operation already in progress @ee
 */
#define SCE_KERNEL_ERROR_EALREADY				-2147352539	/* 0x80020025 */

/**
 * @j ソケットではない @ej
 * @e Socket operation on non-socket @ee
 */
#define SCE_KERNEL_ERROR_ENOTSOCK				-2147352538	/* 0x80020026 */

/**
 * @j 宛先アドレスが必要 @ej
 * @e Destination address required @ee
 */
#define SCE_KERNEL_ERROR_EDESTADDRREQ			-2147352537	/* 0x80020027 */

/**
 * @j メッセージが長過ぎる @ej
 * @e Message too long @ee
 */
#define SCE_KERNEL_ERROR_EMSGSIZE				-2147352536	/* 0x80020028 */

/**
 * @j プロトコルが不正 @ej
 * @e Protocol wrong type for socket @ee
 */
#define SCE_KERNEL_ERROR_EPROTOTYPE				-2147352535	/* 0x80020029 */

/**
 * @j プロトコルが利用できない @ej
 * @e Protocol not available @ee
 */
#define SCE_KERNEL_ERROR_ENOPROTOOPT			-2147352534	/* 0x8002002A */

/**
 * @j プロトコルがサポートされていない @ej
 * @e Protocol not supported @ee
 */
#define SCE_KERNEL_ERROR_EPROTONOSUPPORT		-2147352533	/* 0x8002002B */

/**
 * @j ソケットタイプがサポートされていない @ej
 * @e Socket type not supported @ee
 */
#define SCE_KERNEL_ERROR_ESOCKTNOSUPPORT		-2147352532	/* 0x8002002C */

/**
 * @j 操作がサポートされていない @ej
 * @e Operation not supported @ee
 */
#define SCE_KERNEL_ERROR_EOPNOTSUPP				-2147352531	/* 0x8002002D */

/**
 * @j 操作がサポートされていない @ej
 * @e Operation not supported (SCE_KERNEL_ERROR_EOPNOTSUPP) @ee
 */
#define SCE_KERNEL_ERROR_ENOTSUP				-2147352531	/* 0x8002002D */

/**
 * @j プロトコルファミリーがサポートされていない @ej
 * @e Protocol family not supported @ee
 */
#define SCE_KERNEL_ERROR_EPFNOSUPPORT			-2147352530	/* 0x8002002E */

/**
 * @j アドレスファミリーがサポートされていない @ej
 * @e Address family not supported by protocol family @ee
 */
#define SCE_KERNEL_ERROR_EAFNOSUPPORT			-2147352529	/* 0x8002002F */

/**
 * @j アドレスが使用中 @ej
 * @e Address already in use @ee
 */
#define SCE_KERNEL_ERROR_EADDRINUSE				-2147352528	/* 0x80020030 */

/**
 * @j 要求されたアドレスが割り当てられなかった @ej
 * @e Can't assign requested address @ee
 */
#define SCE_KERNEL_ERROR_EADDRNOTAVAIL			-2147352527	/* 0x80020031 */

/**
 * @j ネットワークが落ちている @ej
 * @e Network is down @ee
 */
#define SCE_KERNEL_ERROR_ENETDOWN				-2147352526	/* 0x80020032 */

/**
 * @j ネットワークが到達できない @ej
 * @e Network is unreachable @ee
 */
#define SCE_KERNEL_ERROR_ENETUNREACH			-2147352525	/* 0x80020033 */

/**
 * @j 接続がネットワーク側からリセットされた @ej
 * @e Network dropped connection on reset @ee
 */
#define SCE_KERNEL_ERROR_ENETRESET				-2147352524	/* 0x80020034 */

/**
 * @j 接続が中断された @ej
 * @e Software caused connection abort @ee
 */
#define SCE_KERNEL_ERROR_ECONNABORTED			-2147352523	/* 0x80020035 */

/**
 * @j 接続がリセットされた @ej
 * @e Connection reset by peer @ee
 */
#define SCE_KERNEL_ERROR_ECONNRESET				-2147352522	/* 0x80020036 */

/**
 * @j バッファが利用できない @ej
 * @e No buffer space available @ee
 */
#define SCE_KERNEL_ERROR_ENOBUFS				-2147352521	/* 0x80020037 */

/**
 * @j ソケットが接続済 @ej
 * @e Socket is already connected @ee
 */
#define SCE_KERNEL_ERROR_EISCONN				-2147352520	/* 0x80020038 */

/**
 * @j ソケットが未接続 @ej
 * @e Socket is not connected @ee
 */
#define SCE_KERNEL_ERROR_ENOTCONN				-2147352519	/* 0x80020039 */

/**
 * @j ソケットが終了している @ej
 * @e Can't send after socket shutdown @ee
 */
#define SCE_KERNEL_ERROR_ESHUTDOWN				-2147352518	/* 0x8002003A */

/**
 * @j 参照が多すぎる @ej
 * @e Too many references: can't splice @ee
 */
#define SCE_KERNEL_ERROR_ETOOMANYREFS			-2147352517	/* 0x8002003B */

/**
 * @j タイムアウト @ej
 * @e Operation timed out @ee
 */
#define SCE_KERNEL_ERROR_ETIMEDOUT				-2147352516	/* 0x8002003C */

/**
 * @j 接続が拒否された @ej
 * @e Connection refused @ee
 */
#define SCE_KERNEL_ERROR_ECONNREFUSED			-2147352515	/* 0x8002003D */

/**
 * @j シンボリックリンクのレベルが多すぎる @ej
 * @e Too many levels of symbolic links @ee
 */
#define SCE_KERNEL_ERROR_ELOOP					-2147352514	/* 0x8002003E */

/**
 * @j ファイル名が長すぎる @ej
 * @e File name too long @ee
 */
#define SCE_KERNEL_ERROR_ENAMETOOLONG			-2147352513	/* 0x8002003F */

/**
 * @j ホストが落ちている @ej
 * @e Host is down @ee
 */
#define SCE_KERNEL_ERROR_EHOSTDOWN				-2147352512	/* 0x80020040 */

/**
 * @j ホストへの経路がない @ej
 * @e No route to host @ee
 */
#define SCE_KERNEL_ERROR_EHOSTUNREACH			-2147352511	/* 0x80020041 */

/**
 * @j ディレクトリが空ではない @ej
 * @e Directory not empty @ee
 */
#define SCE_KERNEL_ERROR_ENOTEMPTY				-2147352510	/* 0x80020042 */

/**
 * @j プロセスが多すぎる @ej
 * @e Too many processes @ee
 */
#define SCE_KERNEL_ERROR_EPROCLIM				-2147352509	/* 0x80020043 */

/**
 * @j ユーザが多すぎる @ej
 * @e Too many users @ee
 */
#define SCE_KERNEL_ERROR_EUSERS					-2147352508	/* 0x80020044 */

/**
 * @j ディスクの容量制限を超えた @ej
 * @e Disc quota exceeded @ee
 */
#define SCE_KERNEL_ERROR_EDQUOT					-2147352507	/* 0x80020045 */

/**
 * @j ファイルハンドルがストール @ej
 * @e Stale NFS file handle @ee
 */
#define SCE_KERNEL_ERROR_ESTALE					-2147352506	/* 0x80020046 */

/**
 * @j パス中のリモートのレベルが多すぎる @ej
 * @e Too many levels of remote in path @ee
 */
#define SCE_KERNEL_ERROR_EREMOTE				-2147352505	/* 0x80020047 */

/**
 * @j RPCの構造が不正 @ej
 * @e RPC struct is bad @ee
 */
#define SCE_KERNEL_ERROR_EBADRPC				-2147352504	/* 0x80020048 */

/**
 * @j RPCのバージョンが不正 @ej
 * @e RPC version wrong @ee
 */
#define SCE_KERNEL_ERROR_ERPCMISMATCH			-2147352503	/* 0x80020049 */

/**
 * @j RPCプログラムが利用できない @ej
 * @e RPC prog. not avail @ee
 */
#define SCE_KERNEL_ERROR_EPROGUNAVAIL			-2147352502	/* 0x8002004A */

/**
 * @j プログラムのバージョンが不正 @ej
 * @e Program version wrong @ee
 */
#define SCE_KERNEL_ERROR_EPROGMISMATCH			-2147352501	/* 0x8002004B */

/**
 * @j 不正なプロシージャ @ej
 * @e Bad procedure for program @ee
 */
#define SCE_KERNEL_ERROR_EPROCUNAVAIL			-2147352500	/* 0x8002004C */

/**
 * @j ロックが利用できない @ej
 * @e No locks available @ee
 */
#define SCE_KERNEL_ERROR_ENOLCK					-2147352499	/* 0x8002004D */

/**
 * @j 実装されていない機能 @ej
 * @e Function not implemented @ee
 */
#define SCE_KERNEL_ERROR_ENOSYS					-2147352498	/* 0x8002004E */

/**
 * @j ファイルタイプ、フォーマットが不適切 @ej
 * @e Inappropriate file type or format @ee
 */
#define SCE_KERNEL_ERROR_EFTYPE					-2147352497	/* 0x8002004F */

/**
 * @j 認証エラー @ej
 * @e Authentication error @ee
 */
#define SCE_KERNEL_ERROR_EAUTH					-2147352496	/* 0x80020050 */

/**
 * @j 認証が必要 @ej
 * @e Need authenticator @ee
 */
#define SCE_KERNEL_ERROR_ENEEDAUTH				-2147352495	/* 0x80020051 */

/**
 * @j 識別子が消去済 @ej
 * @e Identifier removed @ee
 */
#define SCE_KERNEL_ERROR_EIDRM					-2147352494	/* 0x80020052 */

/**
 * @j 指定された種類のメッセージがない @ej
 * @e No message of desired type @ee
 */
#define SCE_KERNEL_ERROR_ENOMSG					-2147352493	/* 0x80020053 */

/**
 * @j 保存する値がそのデータのタイプとしては大きすぎる @ej
 * @e Value too large to be stored in data type @ee
 */
#define SCE_KERNEL_ERROR_EOVERFLOW				-2147352492	/* 0x80020054 */

/**
 * @j 操作がキャンセルされた @ej
 * @e Operation canceled @ee
 */
#define SCE_KERNEL_ERROR_ECANCELED				-2147352491	/* 0x80020055 */

/**
 * @j バイト列が不正 @ej
 * @e Illegal byte sequence @ee
 */
#define SCE_KERNEL_ERROR_EILSEQ					-2147352490	/* 0x80020056 */

/**
 * @j 属性が見つからない @ej
 * @e Attribute not found @ee
 */
#define SCE_KERNEL_ERROR_ENOATTR				-2147352489	/* 0x80020057 */

/**
 * @j プログラミングエラー @ej
 * @e Programming error @ee
 */
#define SCE_KERNEL_ERROR_EDOOFUS				-2147352488	/* 0x80020058 */

/**
 * @j 不正なメッセージ @ej
 * @e Bad message @ee
 */
#define SCE_KERNEL_ERROR_EBADMSG				-2147352487	/* 0x80020059 */

/**
 * @j マルチホップを試みた @ej
 * @e Multihop attempted @ee
 */
#define SCE_KERNEL_ERROR_EMULTIHOP				-2147352486	/* 0x8002005A */

/**
 * @j リンクが切れている @ej
 * @e Link has been severed @ee
 */
#define SCE_KERNEL_ERROR_ENOLINK				-2147352485	/* 0x8002005B */

/**
 * @j プロトコルエラー @ej
 * @e Protocol error @ee
 */
#define SCE_KERNEL_ERROR_EPROTO					-2147352484	/* 0x8002005C */

/**
 * @j ケーパビリティが十分でない @ej
 * @e Capabilities insufficient @ee
 */
#define SCE_KERNEL_ERROR_ENOTCAPABLE			-2147352483	/* 0x8002005D */

/**
 * @j ケーパビリティで許可されない @ej
 * @e Not permitted in capability mode @ee
 */
#define SCE_KERNEL_ERROR_ECAPMODE				-2147352482	/* 0x8002005E */

/**
 * @j ブロックが利用できない @ej
 * @e Block not ready @ee
 */
#define SCE_KERNEL_ERROR_ENOBLK					-2147352481	/* 0x8002005F */

/**
 * @j Integrity check error @ej
 * @e 改ざんチェックエラー @ee
 */
#define SCE_KERNEL_ERROR_EICV					-2147352480	/* 0x80020060 */

/**
 * @j File not found in PlayGo chunk definition @ej
 * @e ファイルがPlayGoチャンク定義ファイル内に見つからない @ee
 */
#define SCE_KERNEL_ERROR_ENOPLAYGOENT			-2147352479	/* 0x80020061 */

/**
 * @j リボークエラー @ej
 * @e File is revoked @ee
 */
#define SCE_KERNEL_ERROR_EREVOKE				-2147352478	/* 0x80020062 */

/**
 * @j バイナリファイルのSDKバージョンが不正 @ej
 * @e SDK version of a binary file is invalid @ee
 */
#define SCE_KERNEL_ERROR_ESDKVERSION			-2147352477	/* 0x80020063 */

/**
 * @j module_start() が失敗 @ej
 * @e module_start() fails @ee
 */
#define SCE_KERNEL_ERROR_ESTART				-2147352476	/* 0x80020064 */

/**
 * @j module_stop() が失敗 @ej
 * @e module_stop() fails @ee
 */
#define SCE_KERNEL_ERROR_ESTOP				-2147352475	/* 0x80020065 */



#if defined(__cplusplus)
}
#endif

#endif  /* _SCE_SYS_SCE_ERRNO_H */
