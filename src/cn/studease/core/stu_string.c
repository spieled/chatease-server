/*
 * stu_string.c
 *
 *  Created on: 2016-9-8
 *      Author: Tonu Lau
 */

#include <stdarg.h>
#include "stu_config.h"
#include "stu_core.h"

void
stu_strlow(u_char *dst, u_char *src, size_t n) {
	while (n) {
		*dst = stu_tolower(*src);
		dst++;
		src++;
		n--;
	}
}

u_char *
stu_strlchr(u_char *p, u_char *last, u_char c) {
	while (p < last) {
		if (*p == c) {
			return p;
		}
		p++;
	}
	return NULL;
}

u_char *
stu_strrchr(u_char *p, u_char *last, u_char c) {
	while (p < last--) {
		if (*last == c) {
			return last;
		}
	}
	return NULL;
}

void *
stu_memzero(void *block, size_t n) {
	return memset(block, 0, n);
}

u_char *
stu_strncpy(u_char *dst, u_char *src, size_t n) {
	if (n == 0) {
		return dst;
	}

	while (n--) {
		*dst = *src;

		if (*dst == '\0') {
			return dst;
		}

		dst++;
		src++;
	}

	*dst = '\0';

	return dst;
}

u_char *
stu_strnstr(u_char *s1, char *s2, size_t n) {
	u_char  c1, c2;

	c2 = *(u_char *) s2++;

	do {
		do {
			c1 = *s1++;

			if (c1 == 0) {
				return NULL;
			}
		} while (c1 != c2);
	} while (stu_strncmp(s1, (u_char *) s2, n) != 0);

	return --s1;
}

stu_int_t
stu_strncasecmp(u_char *s1, u_char *s2, size_t n) {
	stu_uint_t  c1, c2;

	while (n) {
		c1 = (stu_uint_t) *s1++;
		c2 = (stu_uint_t) *s2++;

		c1 = (c1 >= 'A' && c1 <= 'Z') ? (c1 | 0x20) : c1;
		c2 = (c2 >= 'A' && c2 <= 'Z') ? (c2 | 0x20) : c2;

		if (c1 == c2) {
			if (c1) {
				n--;
				continue;
			}

			return 0;
		}

		return c1 - c2;
	}

	return 0;
}


stu_int_t
stu_printf(const char *fmt, ...) {
	va_list    args;
	stu_int_t  n;

	va_start(args, fmt);
	n = stu_vprintf(fmt, args);
	va_end(args);

	return n;
}

u_char *
stu_sprintf(u_char *s, const char *fmt, ...) {
	va_list    args;
	u_char    *p;

	va_start(args, fmt);
	p = stu_vsprintf(s, fmt, args);
	va_end(args);

	return p;
}

stu_int_t
stu_vprintf(const char *fmt, va_list args) {
	return vprintf(fmt, args);
}

u_char *
stu_vsprintf(u_char *s, const char *fmt, va_list args) {
	stu_int_t  n;
	u_char    *p = s;

	n = vsprintf((char *) s, fmt, args);
	if (n < 0) {
		return NULL;
	}
	p += n;

	return p;
}

