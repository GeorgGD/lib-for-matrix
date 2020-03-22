#!/bin/bash

make -s clean
make ##-s OFLAGS="-O3 -march=native -ffast-math"

arrN=(10 20 30 40 50 60 70 80 90 100 150 200 300 400 500 600 700 800 900 1000 1500 2000)

for index in ${!arrN[*]}
do
    { time (./lu ${arrN[$index]} 0) >/dev/null; } 2>&1 | grep real | cut -f 2 | cut -c 3- | sed "s/.$/	${arrN[$index]}/" >> time.txt
    echo N = ${arrN[$index]}  
done

echo done, bye
