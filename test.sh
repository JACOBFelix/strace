#!/bin/sh

if [ "$1" = "long_test" ]
then
    ./strace
    ./strace -p
    ./strace ./test2
    ./strace ./test3
    ./strace ./test4
    ./strace ls
    ./strace ls -l
    ./strace ls -lRa
    ./strace ls -lRa /
elif [ "$1" = "fast_test" ]
then
    ./strace
    ./strace -p
    ./strace ls
    ./strace ls -l
    ./strace ./test1
    ./strace ./test2
    ./strace ./test3
    ./strace ./test4
    ./strace echo on se marre
    ./strace make
    ./strace cat test.sh
    ./strace ls -lRa 
    ./strace clear
    echo "Press Q for quit when htop will be launched"
    sleep 3
    ./strace htop

else
    echo "Need One argument as long_test / fast_test"
fi
