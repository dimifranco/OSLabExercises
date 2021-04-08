if ! test -d $1
then
    echo "L'argomento deve essere una directory."
    exit 1
fi

if test $# -ne 1
then
    echo "Ci deve essere un solo argomento."
    exit 2
fi

file=`find $1 -type f | wc -l`
dir=`find $1 -type d | wc -l`

echo "Numero di file: $file"
echo "Numero di directory: $dir"

exit 0
