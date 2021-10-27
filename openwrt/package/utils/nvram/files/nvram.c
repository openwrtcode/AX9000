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

#include "nvram.h"

void
usage(void)
{
	fprintf(stderr,
	        "usage: nvram [get name] [set name=value] "
	        "[unset name] [show] [commit] [clear file]...\n");
	exit(0);
}

#define UBOOT	0
#define MAX_NVRAM_SPACE 0x10000

/* NVRAM utility */
int
main(int argc, char **argv)
{
	char *name, *value, buf[MAX_NVRAM_SPACE];
	char *nameTemp;
	char rbuf[MAX_NVRAM_SPACE/16];
	char * filename;
	FILE * fp;

	if(argc > 3)
	{
		usage();
	}

	/* Skip program name */
	--argc;
	++argv;

	if (!*argv)
		usage();

	/* Process the arguments */
	for (; *argv; ++argv) {
		if (!strcmp(*argv, "get")) {
			if (*++argv) {
				if ((value = nvram_get(UBOOT, *argv)))
					puts(value);
			}
		} else if (!strcmp(*argv, "set")) {
			if (*++argv) {
				strncpy(value = buf, *argv, sizeof(buf));
				name = strsep(&value, "=");
				if(NULL != value)
					nvram_set(UBOOT, name, value);
				else
					usage();
			}
		} else if (!strcmp(*argv, "unset")) {
			if (*++argv)
				nvram_unset(UBOOT, *argv);
		} else if (!strcmp(*argv, "commit")) {
			nvram_commit(UBOOT);
		} else if (!strcmp(*argv, "show") ||
		           !strcmp(*argv, "dump")) {
			nvram_dump(UBOOT);
		} else if (!strcmp(*argv, "clear") ) {
                        fprintf(stdout,"start nvram clear.....\n");

			if (*++argv)
			{
				filename = *argv;

				//fprintf(stdout,"file name=%s \n",filename);
				if ((fp = fopen(filename,"r")) == NULL)
				{
					fprintf(stderr,"cannot open file name=%s \n",filename);
					return ;
				}

				fread(rbuf,1,MAX_NVRAM_SPACE/16,fp);

				nvram_getall(UBOOT,buf);
				for (name = buf; *name; name += strlen(name) + 1)
				{
					nameTemp = strsep( &name, "=");

					if ( strstr(rbuf,nameTemp) != NULL)
					{
						//fprintf(stdout,"nvram cash...%s!\n",nameTemp);
						continue;
					}
					nvram_unset(UBOOT, nameTemp);
				}
				//nvram_commit(UBOOT);
				fprintf(stdout,"nvram clear...Done!\n");

				fclose(fp);
			}
			else
			{
				usage();
			}

                }
		else
			usage();
	}

	return 0;
}
