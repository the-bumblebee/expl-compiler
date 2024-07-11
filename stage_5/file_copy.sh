#!/bin/bash

./a.out in.file
./l.out out.xsm
cp out.file ../xsm_expl/
cp out.xsm ../xsm_expl/
cd ../xsm_expl/
echo -------MACHINE IS STARTING----------
./xsm -l library.lib -e out.file
cd ../stage_5_modif
