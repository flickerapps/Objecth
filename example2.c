#include "include/Object.h"

int main(int args, const char* argv[]){
    var myobj = Object_Create("mymovies");
    const char* movies[4] = {
        "Civil War",
        "Batman v Superman",
        "Deadpool",
        "X-men: Apocalipsis"
    };
    myobj->setValue_ArrayOfString(myobj,movies);
    if(isUndefined(myobj)){
        printf("Undefined Object\n");
    }
    else{
        printf("Type: %s\n",getTypeStr(myobj));
        int myfavoriteMovie = myobj->getValue_ArrayOfNumber(myobj)[1];
        printf("My favorite movie: %s\n", myfavoriteMovie);
    }
    return 0;
}
