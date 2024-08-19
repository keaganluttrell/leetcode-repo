#! /bin/bash

LIB="./lib"
INCLUDE="./include"
PROGRAM=${1}

touch ${INCLUDE}/${PROGRAM}.h
cp ./problem-solving.template ${LIB}/${PROGRAM}.c

echo "#include <${PROGRAM}.h>\n" >> ${LIB}/${PROGRAM}.c

