#!/bin/bash

usage() {
    echo "Usage:    exe.sh nFiles" >&2
}

if [ $# != 1 ]; then
    usage
else
    make clean
    make
    program $1
fi