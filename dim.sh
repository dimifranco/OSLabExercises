while true
do
    read linea
    if test $linea = 'fine'
    then
	exit 0;
    else
	dim=`echo $linea | wc -c`
	dim=$[$dim-1]
	echo $dim
	for ((i=1; i<=$dim; i++))
	do
	    echo -n '*';
	done
	if test $dim -gt 0
	then
	    echo
	fi
    fi
done
