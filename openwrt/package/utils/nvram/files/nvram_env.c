/***************************************************************************
    copyright            : (C) by 2021 Lin kai
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License version 2 as     *
 *   published by the Free Software Foundation                             *
 *   You may obtain a copy of the License at                               *
 *   https://opensource.org/licenses/gpl-2.0.php                           *
 *                                                                         *
 ***************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "nvram.h"
#define MAX_NVRAM_SPACE	0x10000

char libnvram_debug = 0;
#define LIBNV_PRINT(x, ...) do { if (libnvram_debug) printf("%s %d: " x, __FILE__, __LINE__, ## __VA_ARGS__); } while(0)
#define LIBNV_ERROR(x, ...) do { printf("%s %d: ERROR! " x, __FILE__, __LINE__, ## __VA_ARGS__); } while(0)

//x is the value returned if the check failed
#define LIBNV_CHECK_INDEX(x) do { \
	if (index < 0 || index >= FLASH_BLOCK_NUM) { \
		LIBNV_PRINT("index(%d) is out of range\n", index); \
		return x; \
	} \
} while (0)

#define FREE(x) do { if (x != NULL) {free(x); x=NULL;} } while(0)

static char buf[MAX_NVRAM_SPACE];
int nvram_set(int index, char *name, char *value)
{
	int fd;
	nvram_ioctl_t nvr;

	LIBNV_PRINT("--> nvram_set\n");

	LIBNV_CHECK_INDEX(-1);

	memset(&nvr, 0, sizeof(nvram_ioctl_t));
	nvr.index = index;
	nvr.name = name;
	nvr.value = value;
	fd = open(NV_DEV, O_RDONLY);
	if (fd < 0) {
		perror(NV_DEV);
		return -1;
	}
	if (ioctl(fd, NVRAM_IOCTL_SET, &nvr) < 0) {
		perror("ioctl");
		close(fd);
		return -1;
	}
	close(fd);

	return 0;
}


int nvram_unset(int index, char *name)
{
	int fd;
	nvram_ioctl_t nvr;

	LIBNV_CHECK_INDEX(-1);

	memset(&nvr, 0, sizeof(nvram_ioctl_t));
	nvr.index = index;
	nvr.name = name;
	fd = open(NV_DEV, O_RDONLY);
	if (fd < 0) {
		perror(NV_DEV);
		return -1;
	}
	if (ioctl(fd, NVRAM_IOCTL_UNSET, &nvr) < 0) {
		perror("ioctl");
		close(fd);
		return -1;
	}
	close(fd);
}

char const *nvram_get(int index, char *name)
{
	int fd;
	nvram_ioctl_t nvr;

	LIBNV_PRINT("--> nvram_get %d\n", index);

	LIBNV_CHECK_INDEX(-1);

	memset(&nvr, 0, sizeof(nvram_ioctl_t));
	memset(buf, 0, sizeof(buf));
	nvr.index = index;
	nvr.name = name;
	nvr.value = buf;
	fd = open(NV_DEV, O_RDONLY);
	if (fd < 0) {
		perror(NV_DEV);
		FREE(nvr.value);
		return "";
	}
	if (ioctl(fd, NVRAM_IOCTL_GET, &nvr) < 0) {
		perror("ioctl");
		close(fd);
		FREE(nvr.value);
		return "";
	}
	close(fd);
	LIBNV_PRINT("-->nvram_get exit\n");
	return nvr.value;
}

int nvram_dump(int index)
{
	int fd;
	char *p;
	nvram_ioctl_t nvr;

	LIBNV_PRINT("--> nvram_dump %d, sizeof(buf):%d\n", index, sizeof(buf));
	LIBNV_CHECK_INDEX(-1);

	memset(&nvr, 0, sizeof(nvram_ioctl_t));
	memset(buf, 0, sizeof(buf));
	nvr.index = index;
	nvr.value = buf;
	fd = open(NV_DEV, O_RDONLY);
	if (fd < 0) {
		perror(NV_DEV);
		return -1;
	}
	if (ioctl(fd, NVRAM_IOCTL_GETALL, &nvr) < 0) {
		perror("ioctl");
		close(fd);
		return -1;
	}
	close(fd);

	p = buf;
	while(*p) {
		printf("%s\n", p);
		p += strlen(p) + 1;
	}

	LIBNV_PRINT("-->nvram_dump exit\n");
	return 0;
}

int nvram_getall(int index, char * allbuf)
{
	int fd;
	nvram_ioctl_t nvr;

	LIBNV_PRINT("--> nvram_getall %d\n", index);
	LIBNV_CHECK_INDEX(-1);

	memset(&nvr, 0, sizeof(nvram_ioctl_t));
	nvr.index = index;
	nvr.value = allbuf;
	fd = open(NV_DEV, O_RDONLY);
	if (fd < 0) {
		perror(NV_DEV);
		return -1;
	}
	if (ioctl(fd, NVRAM_IOCTL_GETALL, &nvr) < 0) {
		perror("ioctl");
		close(fd);
		return -1;
	}
	close(fd);

	return 0;
}

/*
 * write flash from cache
 */
int nvram_commit(int index)
{
	int fd;
	nvram_ioctl_t nvr;

	LIBNV_PRINT("--> nvram_commit %d\n", index);
	LIBNV_CHECK_INDEX(-1);

	memset(&nvr, 0, sizeof(nvram_ioctl_t));
	nvr.index = index;
	fd = open(NV_DEV, O_RDONLY);
	if (fd < 0) {
		perror(NV_DEV);
		return -1;
	}
	if (ioctl(fd, NVRAM_IOCTL_COMMIT, &nvr) < 0) {
		perror("ioctl");
		close(fd);
		return -1;
	}
	close(fd);

	return 0;
}

/*
 * clear flash by writing all 1's value
 */
int nvram_clear(int index)
{
	int fd;
	nvram_ioctl_t nvr;

	LIBNV_PRINT("--> nvram_clear %d\n", index);
	LIBNV_CHECK_INDEX(-1);

	memset(&nvr, 0, sizeof(nvram_ioctl_t));
	nvr.index = index;
	fd = open(NV_DEV, O_RDONLY);
	if (fd < 0) {
		perror(NV_DEV);
		return -1;
	}
	if (ioctl(fd, NVRAM_IOCTL_CLEAR, &nvr) < 0) {
		perror("ioctl");
		close(fd);
		return -1;
	}
	close(fd);
	return 0;
}

int nvram_sync(int index1, int index2)
{
	int fd;
	nvram_ioctl_t nvr;

	LIBNV_PRINT("--> nvram_sync\n");

	memset(&nvr, 0, sizeof(nvram_ioctl_t));
	nvr.index = index1;
	nvr.ret = index2;
	fd = open(NV_DEV, O_RDONLY);
	if (fd < 0) {
		perror(NV_DEV);
		return -1;
	}
	if (ioctl(fd, NVRAM_IOCTL_SYNC, &nvr) < 0) {
		perror("ioctl");
		close(fd);
		return -1;
	}
	close(fd);
	return 0;
}


int nvram_reload(int index)
{
	int fd;
	nvram_ioctl_t nvr;

	LIBNV_PRINT("--> nvram_reload %d\n", index);
	LIBNV_CHECK_INDEX(-1);

	memset(&nvr, 0, sizeof(nvram_ioctl_t));
	nvr.index = index;
	fd = open(NV_DEV, O_RDONLY);
	if (fd < 0) {
		perror(NV_DEV);
		return -1;
	}
	if (ioctl(fd, NVRAM_IOCTL_RELOAD, &nvr) < 0) {
		perror("ioctl");
		close(fd);
		return -1;
	}
	close(fd);
	return 0;
}
