/*
 * stu_channel.h
 *
 *  Created on: 2016-9-28
 *      Author: Tony Lau
 */

#ifndef STU_CHANNEL_H_
#define STU_CHANNEL_H_

#include "stu_config.h"
#include "stu_core.h"

#if (__WORDSIZE == 64)

#define STU_MAX_CHANNEL_N  512
#define STU_MAX_USER_N     512

#else

#define STU_MAX_CHANNEL_N  1024
#define STU_MAX_USER_N     1024

#endif

typedef struct {
	stu_base_pool_t *pool; // not used currently.

	stu_str_t        id;
	stu_int_t        message_n;
	u_char           state;

	stu_hash_t       userlist;
} stu_channel_t;

stu_int_t stu_channel_init(stu_channel_t *ch, stu_str_t *id);

#endif /* STU_CHANNEL_H_ */
