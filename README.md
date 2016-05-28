Object.h
====
"Objects" in C Language using type "var" like Javascript (not confused with Classes).

```c
#include "Object.h"

int main(int args, const char* argv[]){

    var myObj = ObjectCreate((char*)"myObj"); /* => Setting the key 'myObj' */

    myObj->setString(myObj, (char*)"Hello World"); /* => like, myObj: "Hello World" */
    const char* myval = myObj->getString(myObj); /* => "Hello World" */

    return 0;
}
```

You can change the type of object value:
```c
myObj   ->setString(myObj, (char*)"Foo") /* type: String */
        ->setNumber(myObj, 3445); /* now, type: Number */
```

Supported Types:

* Number
* String
* Boolean
* Object (childs)
* ArrayOfNumber
* ArrayOfString
* ArrayOfBoolean
* Undefined (default)

You can set childs to your object:
```c
var myParent = ObjectCreate((char*)"Parent");
var myChild = ObjectCreate((char*)"Child");

myParent->setChild(myParent, myChild); /* args: 'to' myParent, 'from' myChild */

myChild->setNumber(myChild, 75);

var child = myParent->getChild(myParent);
int should_be_75 =  child->getNumber(child); /* => 75 */
```

You can `find()` in childs Linked List;
```c
var myParent = ...

var myChild1 = ...
var myChild2 = ...
var myChild3 = ObjectCreate((char*)"child3");

myParent->setChild(myParent, myChild1);
myParent->appendChild(myParent, myChild2); /* or using `setNext()` in myChild1 */
myParent->appendChild(myParent, myChild3); /* or using `setNext()` in myChild2 */

var found = myParent->find(myParent, "child3"); /* find using the key setted in ObjectCreate() */
```

Using test functions:
```c
if(!isUndefined(myParent)){
    /* ... */
    if(hasChild(myParent, (char*)"child3")){
        /* ... */
        if(isString(myChild3)){
            /* ... */
        }
    }
}
```
License
====
[MIT](LICENSE)
