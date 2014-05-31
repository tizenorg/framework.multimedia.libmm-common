/*
 * libmm-common
 *
 * Copyright (c) 2000 - 2011 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Contact: Jonghyuk Choi <jhchoi.choi@samsung.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
 


/* ===========================================================================================
EDIT HISTORY FOR MODULE

	This section contains comments describing changes made to the module.
	Notice that changes are listed in reverse chronological order.

when		who							what, where, why
---------	--------------------		----------------------------------------------------------
09/28/07	jhchoi.choi@samsung.com		Created
10/03/30	seungbae.shin@samsung.com	Revised (remove some ifdefs)

=========================================================================================== */
#ifndef __MMF_DEBUG_H__
#define __MMF_DEBUG_H__

#ifdef __cplusplus
	extern "C" {
#endif

enum {
	MMF_DEBUG_LEVEL_0,
	MMF_DEBUG_LEVEL_1,
	MMF_DEBUG_LEVEL_2,
	MMF_DEBUG_LEVEL_3,
	MMF_DEBUG_LEVEL_4,
	MMF_DEBUG_LEVEL_5,
	MMF_DEBUG_LEVEL_ALL,

	MMF_DEBUG_CRITICAL	= MMF_DEBUG_LEVEL_0,
	MMF_DEBUG_ERROR		= MMF_DEBUG_LEVEL_1,
	MMF_DEBUG_WARNING	= MMF_DEBUG_LEVEL_2,
	MMF_DEBUG_INFO		= MMF_DEBUG_LEVEL_3,
	MMF_DEBUG_LOG		= MMF_DEBUG_LEVEL_4,
	MMF_DEBUG_VERBOSE	= MMF_DEBUG_LEVEL_5,

	MMF_DEBUG_PROFILE	= MMF_DEBUG_LEVEL_0,
};

/******************************************************************************
 *
 *	DEBUG CONFIGURATION
 *
 *****************************************************************************/
#ifndef MMF_LOG_OWNER
#define MMF_LOG_OWNER		LOG_NONE
#endif

#ifndef MMF_DEBUG_LEVEL
#define MMF_DEBUG_LEVEL		4
#endif

#ifndef MMF_DEBUG_PREFIX
#define MMF_DEBUG_PREFIX	"MMF"
#endif

#ifndef MMF_DEBUG_FILE
#define MMF_DEBUG_FILE		"/var/log/mmf-log"
#endif

/******************************************************************************
 *	DEBUG OUTPUT:
 *		0 = None
 *		1 = Log Manager
 *		2 = Debug System
 *		3 = Console
 *		4 = File
 *****************************************************************************/
/*
 *	LOG MANAGER
 */
#include <mm_log.h>

#define mmf_debug(type, fmt, arg...)	\
	{	\
		switch (type) {	\
			case MMF_DEBUG_VERBOSE:	\
				log_print_rel(MMF_LOG_OWNER, LOG_CLASS_VERBOSE, fmt, ##arg);	\
				break;	\
			case MMF_DEBUG_LOG:	\
				log_print_rel(MMF_LOG_OWNER, LOG_CLASS_DEBUG, fmt, ##arg);	\
				break;	\
			case MMF_DEBUG_INFO: \
				log_print_rel(MMF_LOG_OWNER, LOG_CLASS_INFO, fmt, ##arg);	\
				break;	\
			case MMF_DEBUG_WARNING:	\
				log_print_rel(MMF_LOG_OWNER, LOG_CLASS_WARNING, fmt, ##arg);	\
				break;	\
			case MMF_DEBUG_ERROR:	\
				log_print_rel(MMF_LOG_OWNER, LOG_CLASS_ERR, fmt, ##arg);	\
				break;	\
			case MMF_DEBUG_CRITICAL:	\
				log_print_rel(MMF_LOG_OWNER, LOG_CLASS_CRITICAL, fmt, ##arg);	\
				break;	\
		}	\
	}

#define mmf_secure_debug(type, fmt, arg...)	\
	{	\
		switch (type) {	\
			case MMF_DEBUG_VERBOSE:	\
				secure_log_print_rel(MMF_LOG_OWNER, LOG_CLASS_VERBOSE, fmt, ##arg);	\
				break;	\
			case MMF_DEBUG_LOG:	\
				secure_log_print_rel(MMF_LOG_OWNER, LOG_CLASS_DEBUG, fmt, ##arg);	\
				break;	\
			case MMF_DEBUG_INFO: \
				secure_log_print_rel(MMF_LOG_OWNER, LOG_CLASS_INFO, fmt, ##arg);	\
				break;	\
			case MMF_DEBUG_WARNING:	\
				secure_log_print_rel(MMF_LOG_OWNER, LOG_CLASS_WARNING, fmt, ##arg);	\
				break;	\
			case MMF_DEBUG_ERROR:	\
				secure_log_print_rel(MMF_LOG_OWNER, LOG_CLASS_ERR, fmt, ##arg);	\
				break;	\
			case MMF_DEBUG_CRITICAL:	\
				secure_log_print_rel(MMF_LOG_OWNER, LOG_CLASS_CRITICAL, fmt, ##arg);	\
				break;	\
		}	\
	}

/******************************************************************************
 *
 *	DEBUG FUNCTION MACROS
 *
 *****************************************************************************/
#define debug_verbose(fmt, arg...)	mmf_debug(MMF_DEBUG_VERBOSE, fmt, ##arg)
#define debug_log(fmt, arg...)		mmf_debug(MMF_DEBUG_LOG, fmt, ##arg)
#define debug_msg(fmt, arg...)		mmf_debug(MMF_DEBUG_INFO, fmt, ##arg)
#define debug_warning(fmt, arg...)	mmf_debug(MMF_DEBUG_WARNING, fmt, ##arg)
#define debug_error(fmt, arg...)	mmf_debug(MMF_DEBUG_ERROR, fmt, ##arg)
#define debug_critical(fmt, arg...)	mmf_debug(MMF_DEBUG_CRITICAL, fmt, ##arg)
#define debug_profile(fmt, arg...)	mmf_debug(MMF_DEBUG_PROFILE,	"<TIMER> " fmt, ##arg)
#define debug_fenter()				mmf_debug(MMF_DEBUG_LOG, 		"<ENTER> \n")
#define debug_fleave()				mmf_debug(MMF_DEBUG_LOG, 		"<LEAVE> \n")
#define debug_enter(fmt, arg...)	mmf_debug(MMF_DEBUG_LOG,		"<ENTER> [<---] " fmt, ##arg)
#define debug_leave(fmt, arg...)	mmf_debug(MMF_DEBUG_LOG,		"<LEAVE> [--->] " fmt, ##arg)

#define secure_debug_verbose(fmt, arg...)	mmf_secure_debug(MMF_DEBUG_VERBOSE, fmt, ##arg)
#define secure_debug_log(fmt, arg...)		mmf_secure_debug(MMF_DEBUG_LOG, fmt, ##arg)
#define secure_debug_msg(fmt, arg...)		mmf_secure_debug(MMF_DEBUG_INFO, fmt, ##arg)
#define secure_debug_warning(fmt, arg...)	mmf_secure_debug(MMF_DEBUG_WARNING, fmt, ##arg)
#define secure_debug_error(fmt, arg...)	mmf_secure_debug(MMF_DEBUG_ERROR, fmt, ##arg)
#define secure_debug_critical(fmt, arg...)	mmf_secure_debug(MMF_DEBUG_CRITICAL, fmt, ##arg)
#define secure_debug_profile(fmt, arg...)	mmf_secure_debug(MMF_DEBUG_PROFILE,	"<TIMER> " fmt, ##arg)

#define return_if_fail(expr)	\
	if(!(expr)) {	\
		debug_warning("failed [%s]\n", #expr);	\
		return;	\
	}

#define return_val_if_fail(expr, val)	\
	if (!(expr)) {	\
		debug_warning("failed [%s]\n", #expr);	\
		return val;	\
	}

#define assert_not_reached() \
{ \
	debug_error("assert_not_reached()"); \
	assert(0); \
}


#ifdef __cplusplus
	}
#endif

#endif	/* __MMF_DEBUG_H__ */