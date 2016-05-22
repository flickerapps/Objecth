#include "../Object.h"

int main(int args, const char* argv[]){
    var parent = ObjectCreate("myparent");
    var children1 = ObjectCreate("mychild1");
    var children2 = ObjectCreate("mychild2");

    children1->setNumber(children1, 29);
    children2->setNumber(children2, 45);
    children1->next = children2;

    parent->setChild(parent, children1);
    var should_be_child1 = parent->getChild(parent);

    int should_be_29 = should_be_child1->getNumber(should_be_child1);
    int should_be_45 = should_be_child1->next->getNumber(should_be_child1->next);

    printf( "should be 29: %d\n"
            "should be 45: %d\n",
            should_be_29,
            should_be_45);

    freeObject(parent);
    return 0;
}
