names=`cat /etc/passwd | cut -d':' -f1`
length=`cat /etc/passwd | wc -l`
i=1
j=1

while test $i -le $#
do
    while test $j -le $length
    do
	line=`echo $names | tail -n +$j | head -1`
	if test ["$1" = "$line"]
	then
	    ID=`cat /etc/passwd | cut -d':' -f3 | tail -n +$j | head -1`
	    echo "$1 ha id $ID"
	    break
	fi
	j=$[$j+1]
    done
    if test $j -gt $length
    then
	echo "$1 non e' un nome di login valido."
    fi
    j=1
    shift
    i=$[$i+1]
done

exit 0

    
