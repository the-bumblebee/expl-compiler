#include <stdio.h>
#include <stdlib.h>
#include "exprtree.h"
#include "classlib.h"
#include "debuglib.h"

struct Typetable *Thead;
struct Classtable *Chead;
struct Fieldlist *Fhead;

int main() {
    TypeTableCreate();
    Chead = NULL;
    Chead = CInstall("Yolo", NULL, Chead);
    Class_FInstall("hello", Tlookup("int"), Chead);
    Class_FInstall("heo", Tlookup("int"), Chead);
    Class_FInstall("hell", Tlookup("int"), Chead);
    Class_FInstall("ello", Tlookup("int"), Chead);
    Class_FInstall("llo", Tlookup("int"), Chead);
    Class_FInstall("heoo", Tlookup("int"), Chead);
    Class_FInstall("helo", Tlookup("int"), Chead);
    Class_FInstall("hoo", Tlookup("int"), Chead);
    //printf("%s\n", Chead->methodPtr->name);
    Class_MInstall("fefe", Tlookup("void"), NULL, Chead);
    Class_MInstall("fee", Tlookup("void"), NULL, Chead);
    Class_MInstall("fe", Tlookup("void"), NULL, Chead);
    Class_MInstall("ffe", Tlookup("void"), NULL, Chead);
    Class_MInstall("f", Tlookup("void"), NULL, Chead);
    Class_MInstall("feffe", Tlookup("void"), NULL, Chead);
    Class_MInstall("fegfe", Tlookup("void"), NULL, Chead);
    Class_MInstall("feefe", Tlookup("void"), NULL, Chead);
    Chead = CInstall("Peter", NULL, Chead);
    print_Ctable(Chead);
    return 0;
}
