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
ramp=$(free --mega | awk '$1 == "Mem:" {printf("%.2f", ($3*100)/$2)}')

#disk space used
disku=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')

#disk space total
diskt=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{diskst_total += $2} END {printf ("%.0fGb\n"), diskst_total/1024}')

#disk space percentage
diskp=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t += $2} END {printf("%d"), (disk_u*100)/disk_t}')

#cpu wait time
cpuid=$(vmstat 1 3 | tail -1 | awk '{print $15}')
cpu_ex=$(expr 100 - $cpuid)
cpuwt=$(printf "%.1f" $cpu_ex)

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
ip=$(hostname -i)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

#commands executed with sudo
sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

#displayed message
wall "
	#Architecture: $architecture
	#CPU physical: $ppro
	#vCPU: $vpro
	#Memory Usage: $ramu/$ramt MB ($ramp%)
	#Disk Usage: $disku/$diskt ($diskp%)
	#CPU load: $cpuwt%
	#Last boot: $reboot
	#LVM use: $lvm
	#Connections TCP: $tcp ESTABLISHED
	#User log: $users
	#Network: IP $ip ($mac)
	#Sudo: $sudo cmd"

