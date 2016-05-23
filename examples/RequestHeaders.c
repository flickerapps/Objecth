#include "../Object.h"
#include <stdio.h>


var Headers(){
    var headers = ObjectCreate("Headers");

    var Content_Type =  ObjectCreate("Content-Type");
    Content_Type->setString(Content_Type, "text/html");

    var Content_Length = ObjectCreate("Content-Length");
    var Set_Cookies = ObjectCreate("Set-Cookies");

    headers->setChild(headers, Content_Type);
    headers->appendChild(headers, Content_Length);
    headers->appendChild(headers, Set_Cookies);

    return headers;
};

var setContent_Type(var self, const char* contentType){
    if(!isUndefined(self)){
        if(hasChild(self, "Content-Type")){
            var contype = self->find(self, "Content-Type");
            contype->setString(contype, contentType);
        }
    }
    return self;
}

const char* getContent_Type(var self){
    if(!isUndefined(self)){
        if( hasChild(self, "Content-Type") ){
            var contype = self->find(self, "Content-Type");
            return contype->getString(contype);
        }
    }
    return NULL;
}
int main(int argc, char const *argv[])
{
    var headers = Headers();
    setContent_Type(headers, "application/json");
    printf("Content-Type: %s\n", getContent_Type(headers));
    freeObject(headers);
    return 0;
}
