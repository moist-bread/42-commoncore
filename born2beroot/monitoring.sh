#!/bin/bash

#architecture
architecture=$(uname -a)

#physical processors
ppro=$(grep "physical id" /proc/cpuinfo | wc -l)

#virtual processors
vpro=$(grep processor /proc/cpuinfo | wc -l)

#ram used
ramu=$(free --mega | awk '$1 == "Mem:" {print $3}')

#ram total
ramt=$(free --mega | awk '$1 == "Mem:" {print $2}')

#ram usage percentage
ramp=$(free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", ($3*100)/$2)}')

#disk space used
disku=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{diskst_used += $3} END {print diskst_used}')

#disk space total
diskt=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{diskst_total += $2} END {printf ("%.0fGb\n"), diskst_total/1024}')

diskp=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{diskst_used += $3} {diskst_total += $2} END {printf("(%d%%)\n"), (diskst_used*100)/diskst_total}')

#cpu wait time
cpuwt=$(vmstat 1 3 | tail -1 | awk '{print $15}')

#last reboot date
reboot=$(who -b | awk '$1 == "system" {print $3 " " $4}')

#logical volume manager status
lvm=$( if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then
	echo yes
else
	echo no
fi )

#tcp connections
tcp=$(ss -at | grep ESTAB | wc -l)

#users
users=$(users | wc -w)

#ipv4
ip=$(ip link | grep "link/ether" | awk '{print $2}')

#commands executed with sudo
sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

#displayed message
wall "	#Architecture: $architecture
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
		#Sudo:"