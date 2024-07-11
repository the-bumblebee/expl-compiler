
Usage::>

./ab.out <filename>


Compiling::>

>> yacc -d exprtree.y
>> lex exprtee.l
>> gcc lex.yy.c y.tab.c -o ab.out
