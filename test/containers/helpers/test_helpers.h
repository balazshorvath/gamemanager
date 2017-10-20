#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include <sys/time.h>

long get_long_time() {
	struct timeval timecheck;
	gettimeofday(&timecheck, NULL);
	return (long)timecheck.tv_sec * 1000 + (long)timecheck.tv_usec / 1000;
}

#endif /* TEST_HELPERS_H */