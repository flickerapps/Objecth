#include "include/Object.h"

int main(int args, const char* argv[]){
    var parent = Object_Create("My Parent");


    var children1 = Object_Create("child1");
    children1->setValue_Number(children1, 55);

    var children2 = Object_Create("child2");
    children2->setValue_Number(children2, 65);

    var children3 = Object_Create("child3");
    children3->setValue_Number(children3, 75);


    children1
    ->setNext(children1, children2)
    ->setNext(children2, children3);

    parent->setValue_Object(parent, children1);

    if(isObject(parent)){
        //parent->removeChild(parent, "child2");
        if(hasChild(parent,"child2")){
            var finded = parent->find(parent,"child2");
            finded->setValue_Number(finded,99);
            int should_be_65 = finded->getValue_Number(finded);
            printf("Should be: %d\n", should_be_65);
        }
        else{
            printf("Not found child2\n");
        }
    }
    else{
        printf("Undefined parent");
    }

    return 0;
}
