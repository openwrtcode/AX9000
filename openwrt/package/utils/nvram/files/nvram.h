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


#ifndef __NVRAM_H__
#define __NVRAM_H__ 	1

#define FLASH_BLOCK_NUM 2

#define NV_DEV "/dev/nvram"

typedef struct nvram_ioctl_s {
	int index;
	int ret;
	char *name;
	char *value;
} nvram_ioctl_t;

#define NVRAM_IOC_MAGIC		'n'
#define NVRAM_IOCTL_GET		_IOR(NVRAM_IOC_MAGIC, 0x01, nvram_ioctl_t *)
#define NVRAM_IOCTL_GETALL	_IOR(NVRAM_IOC_MAGIC, 0x02, nvram_ioctl_t *)
#define NVRAM_IOCTL_SET		_IOW(NVRAM_IOC_MAGIC, 0x03, nvram_ioctl_t *)
#define NVRAM_IOCTL_COMMIT	_IO(NVRAM_IOC_MAGIC, 0x04)
#define NVRAM_IOCTL_CLEAR	_IO(NVRAM_IOC_MAGIC, 0x05)
#define NVRAM_IOCTL_SYNC	_IO(NVRAM_IOC_MAGIC, 0x06)
#define NVRAM_IOCTL_UNSET	_IOW(NVRAM_IOC_MAGIC, 0x07, nvram_ioctl_t *)
#define NVRAM_IOCTL_RELOAD	_IO(NVRAM_IOC_MAGIC, 0x08)


int nvram_set(int index, char *name, char *value);
int nvram_unset(int index, char *name);
const char *nvram_get(int index, char *name);

int nvram_dump(int index);
int nvram_commit(int index);
int nvram_clear(int index);
int nvram_sync(int index1, int index2);

#endif
