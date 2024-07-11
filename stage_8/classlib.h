#ifndef CLASSLIB_H
#define CLASSLIB_H

struct Classtable {
 	char *name;                           //name of the class
	struct Fieldlist *fieldPtr;        //pointer to Fieldlist
	struct Methodlist *methodPtr;      //pointer to Memberfunclist
	struct Classtable *parentPtr;         //pointer to the parent's class table
	int classIndex;                      //position of the class in the virtual function table
	int fieldCount;                       //count of fields
  	int methodCount;                      //count of methods
	struct Classtable *next;              //pointer to next class table entry
};

struct Fieldlist{
	char *name;			//name of the field
	int fieldIndex;			//position of the field
	struct Typetable *type;		//pointer to typetable
	struct Classtable *ctype;	//pointer to the class containing the field
	struct Fieldlist *next;		//pointer to next fieldlist entry
};

struct Methodlist {
 	char *name;                      //name of the member function in the class
	struct Typetable *type;          //pointer to typetable
	struct Paramstruct *paramList;   //pointer to the head of the formal parameter list
	int funcIndex;                //position of the function in the class table
 	char* flabel;                      //A label for identifying the starting address of the function's code in the memory
	struct Methodlist *next;     //pointer to next Memberfunclist entry
};

struct Classtable *Chead;

struct Classtable* CInstall(char *name, char *parentClassName, struct Classtable *Cptr);

struct Classtable* CLookup(char *name,  struct Classtable *Cptr);

void Class_FInstall(char *name, char *typename, struct Classtable *Cptr);

void Class_MInstall(char *name, struct Typetable *type, struct Paramstruct *paramList, struct Classtable *Cptr);

struct Methodlist* Class_MLookup(char* name, struct Classtable *Cptr);

struct Fieldlist* Class_Flookup(char *name, struct Classtable *Cptr);

void initFuncTable();

#endif
