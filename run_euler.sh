#!/bin/bash

FLAGS='-std=c++17'
LIBS='-lgmp -lgmpxx'

[ $# -ne 1 ] && { echo "question_no.?"; exit 1; }

[ ! -f "${1}.cpp" ] && { echo "source code not found."; exit 2; }

make CPPFLAGS=${FLAGS} LDLIBS=${LIBS} $1 && ./${1} 

rm -rf $1