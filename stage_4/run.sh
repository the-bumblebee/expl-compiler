#!/bin/bash

./a.out
./l.out out.xsm
cp out.file ../xsm_expl
cd ../xsm_expl/ && ./xsm -l library -e out.file && cd -
