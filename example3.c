#include "include/Object.h"

int main(int args, const char* argv[]){
    var parent = Object_Create("myparent");
    var children1 = Object_Create("mychild1");
    var children2 = Object_Create("mychild2");

    children1->setValue_Number(children1, 29);
    children2->setValue_Number(children2, 45);
    children1->next = children2;

    parent->setValue_Object(parent, children1);
    var should_be_child1 = parent->getValue_Object(parent);

    int should_be_29 = should_be_child1->getValue_Number(should_be_child1);
    int should_be_45 = should_be_child1->next->getValue_Number(should_be_child1->next);

    printf( "should be 29: %d\n"
            "should be 45: %d\n",
            should_be_29,
            should_be_45);
    return 0;
}
