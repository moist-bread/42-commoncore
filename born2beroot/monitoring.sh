#!/bin/bash

#architecture
architecture=$(uname -a)

#physical processors
ppro=$(grep "physical id" /proc/cpuinfo | wc -l)

#virtual processors
vpro=$(grep processor /proc/cpuinfo | wc -l)

free --mega | awk '$1 == "Mem:" {print $3}' #ram used
free --mega | awk '$1 == "Mem:" {print $2}' #ram total
free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", ($3*100)/$2)}' #ram usage percentage
df -m | grep "/dev/" | grep -v "/boot" | awk '{diskst_used += $3} END {print diskst_used}' #disk space used
df -m | grep "/dev/" | grep -v "/boot" | awk '{diskst_total += $2} END {printf ("%.0fGb\n"), diskst_total/1024}' #disk space total
df -m | grep "/dev/" | grep -v "/boot" | awk '{diskst_used += $3} {diskst_total += $2} END {printf("(%d%%)\n"), (diskst_used*100)/diskst_total}'
vmstat 1 3 | tail -1 | awk '{print $15}' #cpu wait time
who -b | awk '$1 == "system" {print $3 " " $4}' #last reboot date
if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then #logical volume manager status
	echo yes
else
	echo no
fi
ss -at | grep ESTAB | wc -l #tcp connections
users | wc -w #users
ip link | grep "link/ether" | awk '{print $2}' #ipv4
journalctl _COMM=sudo | grep COMMAND | wc -l #commands executed with sudo

wall "
		#Architecture: $architecture
		#CPU physical: $ppro
		#vCPU: $vpro
		#Memory Usage:
		#Disk Usage:
		#CPU load:
		#Last boot:
		#LVM use:
		#Connections TCP:
		#User log:
		#Network:
		#Sudo:
"