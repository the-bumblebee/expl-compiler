#!/bin/bash

yacc -d exprtree.y
lex exprtree.l
gcc lex.yy.c y.tab.c
