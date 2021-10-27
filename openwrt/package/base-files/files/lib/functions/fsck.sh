#!/bin/sh

# copyright            : (C) by 2021 Lin kai 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as         
# published by the Free Software Foundation                                
# You may obtain a copy of the License at                                   
# https://opensource.org/licenses/gpl-2.0.php 


libmount_fsck() {
	local device="$1"
	local fsck_fstype="$2"
	local fsck_enabled="$3"
	local known_type
	local found_fsck=0
	

	grep -q "$device" /proc/swaps 2>/dev/null || grep -q "$device" /proc/mounts || {
		[ -e "$device" ] && [ "$fsck_enabled" -eq 1 ] && {
			for known_type in $libmount_known_fsck; do
				if [ "$known_type" = "$fsck_fstype" ]; then
					fsck_${known_type} "$device"
					found_fsck=1
					break
				fi
			done
			if [ "$found_fsck" -ne 1 ]; then
				logger -t 'fstab' "Unable to check/repair $device; no known fsck for filesystem type $fstype"
			fi
		}
	}
}

libmount_known_fsck=""

pi_include /lib/functions/fsck

