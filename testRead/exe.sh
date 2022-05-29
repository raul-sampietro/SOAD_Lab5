#!/bin/bash

usage() {
    echo "Usage: exe.sh nTests nFiles nLines" >&2
}

if [ $# != 3 ]; then
    usage
else
    make clean
    make
    for (( i=0; i<$1; i++ ))
    do  
        ./prueba $2 $3
        wait
    done
fi

echo "See results in ./out/results.txt & ./out/raw.txt"