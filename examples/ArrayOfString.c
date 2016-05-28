#include "../Object.h"
#include <stdio.h>

int main(int args, const char* argv[]){
    const char* movies[4] = {
        "Civil War",
        "Batman v Superman",
        "Deadpool",
        "X-men: Apocalipsis"
    };
    var myobj = ObjectCreate((char*)"mymovies");
    myobj->setArrayOfString(myobj,(char**)movies);
    if(isUndefined(myobj)){
        printf("Undefined Object\n");
    }
    else{
        printf("Type: %s\n",getTypeStr(myobj));
        const char* myfavoriteMovie = myobj->getArrayOfString(myobj)[1];
        printf("My favorite movie: %s\n", myfavoriteMovie);
    }

    freeObject(myobj);
    return 0;
}
