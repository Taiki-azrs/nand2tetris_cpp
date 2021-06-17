#!/bin/bash
test_func(){
    ./$1
    if [ $? -eq 0 ] ; then
	echo $1":OK"
	exit 1
    else
	echo $1":error"
    fi
}
test_func test_gate
test_func test_adder
test_func test_sequential
