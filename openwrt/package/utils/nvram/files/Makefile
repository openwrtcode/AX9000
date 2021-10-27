# copyright            : (C) by 2021 Lin kai 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as         
# published by the Free Software Foundation                                
# You may obtain a copy of the License at                                   
# https://opensource.org/licenses/gpl-2.0.php 


include $(TOPDIR)/rules.mk
include $(TOPDIR)/include/kernel.mk

all: nvram

nvram: nvram_env.o nvram.o
	$(CC) -o nvram nvram_env.o nvram.o

clean:
	$(RM) *.o nvram

