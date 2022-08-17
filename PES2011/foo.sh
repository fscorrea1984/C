#!/bin/bash

if [ -z $1 ] ; then
    echo "usage: $0 <arguments>"
    exit
fi

[[ -f $1 ]] || exit

# STR1="MALGANI"
# STR2="MARADONA"

# cat cargentina.csv | cut -d';' -f2
cat $1 | cut -d';' -f2 > A.txt
cat $1 | cut -d';' -f3 > B.txt

# sed s/"$STR1"/"$STR2"/ foo.txt

sed -i "1 d" A.txt
sed -i "1 d" B.txt

###

exec 3<A.txt
exec 4<B.txt

let line=2

while read -u 3 STR1 && read -u 4 STR2
do
    # echo "$STR2 -> $STR1"
    sed -i "$line s/$STR2/$STR1/" $1
    (( line++ ))
done

exec 3<&-
exec 4<&-

rm -f A.txt B.txt