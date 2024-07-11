%{
    #include <stdio.h>
    #include <string.h>

    int address = 2056 - 16; //removing header
    FILE *in_file;
    FILE *out_file;
    int flag = 0;

    typedef struct label_node {
       int address;
       char* label;
       struct label_node* next;
    }label_node;

    struct label_node* head;

    int getLabelAddress(struct label_node *root, char* l) {

        if(root == NULL) {
            return -1;
        }

        else if(strcmp(root->label, l) == 0) {
            return root->address;
        }

        else if(root->next != NULL){
            return getLabelAddress(root->next, l);
        }

        else{
            return -2;
        }
    }

    void push_label(struct label_node **head_ptr, char* l, int address, int func) {
        struct label_node *temp;
        temp = (struct label_node*)malloc(sizeof(struct label_node));
        temp->address = address;
        if (func == 1) {
            temp->label = strdup(l);
            temp->label[0] = '<';
            temp->label[strlen(l) - 2] = '>';
            temp->label[strlen(l) - 1] = '\0';
        }
        else {
            char str[strlen(l) - 1];        //array to store label without colon
            for(int i = 0; i < strlen(l) - 1; i++) {
                str[i] = l[i];
            }
            str[strlen(l) - 2] = '\0';  //end character
            temp->label = strdup(str);  //allocates and stores from st
        }
        if (*head_ptr == NULL) {
            *head_ptr = temp;
        }
        else {
            temp->next = *head_ptr;
            *head_ptr = temp;
        }

    }

%}


%%
[L][0-9]+":"[\n]                                    {if (flag==0) {push_label(&head, yytext, address, 0); }}
[L][0-9]+                                           {if (flag == 0) {fprintf(out_file, "%s", yytext);} else {address = getLabelAddress(head, yytext); fprintf(out_file, "%d", address);}}
"."[a-zA-Z][_0-9a-zA-Z]*"."?[_0-9a-zA-Z]*":"[\n]    {if (flag==0) {push_label(&head, yytext, address, 1); }}
"<"[a-zA-Z][_0-9a-zA-Z]*"."?[_0-9a-zA-Z]*">"        {if (flag == 0) {fprintf(out_file, "%s", yytext);} else {address = getLabelAddress(head, yytext); fprintf(out_file, "%d", address);}}
[\n]+                                               {if (flag == 0) {address += 2;}; fprintf(out_file, "\n");}
.                                                   {fprintf(out_file, "%s", yytext);}


%%

int yywrap(void)
{
    return 1;
}

int main(int argc, char* argv[]) {

  out_file = fopen("inter.file", "w");
    if (argc == 2) {
 		 in_file = fopen(argv[1], "r");
 		 if(in_file )
 		 yyin = in_file;
    }
    else {
        printf("Usage:\n ./l.out <input_file>\n\n");
        printf("Output:\n out_label.xsm\n");
        exit(0);
    }
	yylex();
	flag = 1;
	fclose(out_file);
	out_file = fopen("out.xsm", "w");
	yyin = fopen("inter.file", "r");
	yylex();
	fclose(out_file);
	return 1;
}
