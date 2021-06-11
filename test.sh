#!/bin/bash
test_func(){
    ./$1
    if 0 = $? ; then
	echo $1":OK"
    else
	echo $1":error"
    fi
}
test_func test_sequential
