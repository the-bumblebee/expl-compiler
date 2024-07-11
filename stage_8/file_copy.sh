#!/bin/bash

./a.out in.file
./label_translation/label.out out_label.xsm
cp out.xsm ../xsm_expl/
cd ../xsm_expl/
echo -------MACHINE IS STARTING----------
./xsm -l library.lib -e out.xsm
