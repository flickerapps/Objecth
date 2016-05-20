#include "include/Object.h"

int main(int args, const char* argv[]){
    var myobj = Object_Create("myobj");
    int nums[] = {3,2,3};
    int nums2[] = {1,8,1};
    myobj
    ->setValue_ArrayOfNumber(myobj,nums)
    ->setValue_ArrayOfNumber(myobj,nums2); // Overwriting setter above
    if(isUndefined(myobj)){
        printf("Undefined Object\n");
    }
    else{
        printf("Type: %s\n",getTypeStr(myobj));
        int mynum = myobj->getValue_ArrayOfNumber(myobj)[1];
        printf("%d\n", mynum);
    }
    return 0;
}
