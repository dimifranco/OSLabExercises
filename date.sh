date=`date | tr -s ' '`
day=`echo $date | cut -d' ' -f2`
month=`echo $date | cut -d' ' -f3`
year=`echo $date | cut -d' ' -f6`
time=`echo $date | cut -d' ' -f4 | tr ':' '_'`
echo "$day/$month/$year - $time"
exit 0;
