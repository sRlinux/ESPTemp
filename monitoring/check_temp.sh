#!/bin/bash
temp=`nc $1 1234 | head -n1 | cut -d" " -f$2`
inttemp=${temp/.*}

if [ "$inttemp" -gt "$3" ]
then
        if [ "$inttemp" -gt "$4" ]
                then
                echo "ERROR: Temp$2: "$temp"|Temp$2="$temp
                exit 2
        fi
        echo "WARNING: Temp$2: "$temp"|Temp$2="$temp
        exit 1
else
echo "OK: Temp$2: "$temp"|Temp$2="$temp
exit 0
fi
