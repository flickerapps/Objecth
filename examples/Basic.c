#include "../Object.h"

int main(int args, const char* argv[]){
    int nums[] = {3,2,3};
    int nums2[] = {1,8,1};
    var myobj = ObjectCreate("myobj");
    myobj->setArrayOfNumber(myobj,nums)
    ->setArrayOfNumber(myobj,nums2); // Overwriting setter above
    if(isUndefined(myobj)){
        printf("Undefined Object\n");
    }
    else{
        printf("Type: %s\n",getTypeStr(myobj));
        int mynum = myobj->getArrayOfNumber(myobj)[1];
        printf("%d\n", mynum);
    }

    freeObject(myobj);
    return 0;
}
