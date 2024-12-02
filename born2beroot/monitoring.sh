#!/bin/bash

#architecture
architecture=$(uname -a)

#physical processors
ppro=$(lscpu | awk '$1 == "CPU(s):" {print $2}')

#virtual processors
vpro=$(nproc)

#ram usage
ramu=$(free --mega | awk '$1 == "Mem:" {printf("%i/%iMB (%.2f%%)", $3, $2, ($3*100)/$2)}')

#disk space used
disku=$(df -m  --total | tail -1 | awk '$1 == "total" {print $3}')

#disk space total and usage
diskt=$(df -h  --total / | tail -1 | awk '$1 == "total" {printf("%sb (%s)", $2, $5)}')

#idle cpu
#sudo apt install sysstat
$cpuidle$(mpstat 1 3 | tail -1 | awk '{printf("%.1f%%", 100-$12)}')

#last reboot date
reboot=$(who -b | awk '{print $3 " " $4}')

#logical volume manager status
#could have fix for collumn with awk '{print $6}' b4 grep
lvm=$( if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ];
then
	echo yes
else
	echo no
fi )

#tcp connections
tcpestab=$(ss --summary | sed 's/,/ /'| awk '$1 == "TCP:" {print $4}')

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
	#Memory Usage: $ramu
	#Disk Usage: $disku/$diskt
	#CPU load: $cpuidle
	#Last boot: $reboot
	#LVM use: $lvm
	#Connections TCP: $tcp ESTABLISHED
	#User log: $users
	#Network: IP $ip ($mac)
	#Sudo: $sudo cmd"