#Programmer : Parwiz Khan
#!/bin/bash

default_ip=`ip route | grep default | cut -d ' ' -f 3`

#now we ping to the default_ip address 5 times and store the avg score
avg_default=`ping -c 5 $default_ip | grep rtt |  cut -d ' ' -f 4 | cut -d "/" -f 2`

#We do the same for the example.com
avg_example=`ping -c 5 example.com | grep rtt | cut -d ' ' -f 4  | cut -d "/" -f 2`


#availble interfaces on the machine
interfaces=`ls -A /sys/class/net | grep -v lo`

#count the interfaces using word count
num_interfaces=`ls -A /sys/class/net | grep -v lo | wc -l`
up_interfaces=0

#this iterates over each interface
for i in $(seq 1 $num_interfaces)
do
   #here we retrieve the i-th interface in the variable 'interfaces'
   eth=`echo $interfaces | cut -d' ' -f $i`
   #now we get the status of that interface
   status=`cat /sys/class/net/$eth/operstate`
  
   # if the interface is up then var 'up_interfaces' is incremented
   if [ "$status" = "up" ]
   then
       up_interfaces=$((up_interfaces+1))
   fi
done  
#active listening tcp ports
n=`netstat -anp | grep -w -c LISTEN`
#output
echo "Ping time to default gateway: $avg_default ms."
echo "Ping time to example.com: $avg_example ms"
echo "Interface count: $num_interfaces, and $up_interfaces / $num_interfaces are up."
echo "There are $n TCP ports in the LISTEN state."