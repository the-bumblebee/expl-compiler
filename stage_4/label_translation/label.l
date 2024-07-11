%{
    #include<stdlib.h>
    #include<stdio.h>
    #include<string.h>
    int address = 2056 - 16; //removing header
    #include "llist.c"
    FILE *in_file;
    FILE *out_file;
    int flag = 0;

    struct lnode* head;

    int ltoi(char * s) {
        int n;
        s[strlen(s) - 1] = 0;
        n = atoi(s + 1);
        return n;
    }

%}


%%
"L"[0-9]+":"[\n]  	{if (flag==0) {pushNode(&head, yytext, address); }}
"L"[0-9]+           {if (flag == 0) {fprintf(out_file, yytext);} else {address = getAddress(head, yytext); fprintf(out_file, "%d", address);}}
[\n]                {if (flag == 0) address += 2; /*printf("\n");*/fprintf(out_file, yytext); /*fprintf(out_file, "%d ", address);*/}
.                   {fprintf(out_file, yytext);}


%%

int yywrap(void)
{
    return 1;
}

int main(int argc, char* argv[]) {

    out_file = fopen("inter.f", "w");
    //fprintf(out_file, "%d ", address);
	if (argc > 1) {
		in_file = fopen(argv[1], "r");
		if(in_file )
			yyin = in_file;
	}
	yylex();
	flag =1;
	fclose(out_file);
	out_file = fopen("out.file", "w");
	yyin = fopen("inter.f", "r");
	yylex();
	fclose(out_file);
	return 1;
}
