/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 *
 */

/*
 * Copyright (C) 2015 Sony Interactive Entertainment Inc.
 * All Rights Reserved.
 */

#ifndef _DTRACEP_CDDL_H
#define _DTRACEP_CDDL_H

#include <sys/dtrace.h>
#include <dtracep_sce.h>

#pragma pack(push,4)

typedef struct SceDeci4pDtracepProviderPayload {
	dtrace_providerdesc_t					providerDesc;
} SceDeci4pDtracepProviderPayload;

struct dtrace_probedesc;
typedef struct SceDeci4pDtracepProbesPayload {
	dtrace_probedesc_t						probeDesc;
} SceDeci4pDtracepProbesPayload;

typedef struct SceDeci4pDtracepBufAggSnapPayload {
	dtrace_bufdesc_t						bufDesc;
	uint8_t									bufData[0];
} SceDeci4pDtracepBufAggSnapPayload;

typedef struct SceDeci4pDtracepProbeMatchPayload {
	dtrace_probedesc_t						probeDesc;
} SceDeci4pDtracepProbeMatchPayload;

typedef struct SceDeci4pDtracepEnablePayload {
	uint32_t								nullDofHeader;
	dof_hdr_t								dofHeader;
	uint8_t									dofData[0];
} SceDeci4pDtracepEnablePayload;

typedef struct SceDeci4pDtracepEProbePayload {
	dtrace_eprobedesc_t						eprobeDesc;
	uint8_t									eprobeData[0];
} SceDeci4pDtracepEProbePayload;

typedef struct SceDeci4pDtracepProbeArgPayload {
	dtrace_argdesc_t						argDesc;
} SceDeci4pDtracepProbeArgPayload;

typedef struct SceDeci4pDtracepConfPayload {
	dtrace_conf_t							config;
} SceDeci4pDtracepConfPayload;

typedef struct SceDeci4pDtracepStatusPayload {
	dtrace_status_t							status;
} SceDeci4pDtracepStatusPayload;

typedef struct SceDeci4pDtracepGoPayload {
	uint32_t								cpu;
} SceDeci4pDtracepGoPayload;

typedef struct SceDeci4pDtracepStopPayload {
	uint32_t								cpu;
} SceDeci4pDtracepStopPayload;

typedef struct SceDeci4pDtracepAggDescPayload {
	dtrace_aggdesc_t						aggDesc;
	uint8_t									aggData[0];
} SceDeci4pDtracepAggDescPayload;

typedef struct SceDeci4pDtracepFormatPayload {
	dtrace_fmtdesc_t						fmtDesc;
	uint8_t									fmtData[0];
} SceDeci4pDtracepFormatPayload;

typedef struct SceDeci4pDtracepDofGetPayload {
	dof_hdr_t								dofHeader;
	uint8_t									dofData[0];
} SceDeci4pDtracepDofGetPayload;

typedef struct SceDeci4pDtracepReplicatePayload {
	dtrace_repldesc_t						replDesc;
} SceDeci4pDtracepReplicatePayload;

typedef struct {
	void	*dof;		/* DOF userland address written to driver. */
	int	n_matched;	/* # matches returned by driver. */
} dtrace_enable_io_t;

#pragma pack(pop)

#endif /* _DTRACEP_CDDL_H */
