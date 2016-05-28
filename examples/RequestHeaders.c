#include "../Object.h"
#include <stdio.h>


var Headers(){
    var headers = ObjectCreate((char*)"Headers");

    var Content_Type =  ObjectCreate((char*)"Content-Type");
    Content_Type->setString(Content_Type, (char*)"text/html");

    var Content_Length = ObjectCreate((char*)"Content-Length");
    var Set_Cookies = ObjectCreate((char*)"Set-Cookies");

    headers->setChild(headers, Content_Type);
    headers->appendChild(headers, Content_Length);
    headers->appendChild(headers, Set_Cookies);

    return headers;
};

var setContent_Type(var self, char* contentType){
    if(!isUndefined(self)){
        if(hasChild(self, (char*)"Content-Type")){
            var contype = self->find(self, (char*)"Content-Type");
            contype->setString(contype, contentType);
        }
    }
    return self;
}

var setContent_Length(var self, unsigned int size){
    if(!isUndefined(self)){
        if(hasChild(self, (char*)"Content-Length")){
            var conlength = self->find(self, (char*)"Content-Length");
            conlength->setNumber(conlength, size);
        }
    }
    return self;
}

var Set_Cookies(var self, char* cookiestr){
    if(!isUndefined(self)){
        if(hasChild(self, (char*)"Set-Cookies")){
            var cookies = self->find(self, (char*)"Set-Cookies");
            cookies->setString(cookies, cookiestr);
        }
    }
    return self;
}

char* getContent_Type(var self){
    if(!isUndefined(self)){
        if( hasChild(self, (char*)"Content-Type") ){
            var contype = self->find(self, (char*)"Content-Type");
            return contype->getString(contype);
        }
    }
    return NULL;
}

char* getCookies(var self){
    if(!isUndefined(self)){
        if( hasChild(self, (char*)"Set-Cookies") ){
            var cookies = self->find(self, (char*)"Set-Cookies");
            return cookies->getString(cookies);
        }
    }
    return NULL;
}

int getContent_Length(var self){
    if(!isUndefined(self)){
        if( hasChild(self, (char*)"Content-Length") ){
            var conlength = self->find(self, (char*)"Content-Length");
            return conlength->getNumber(conlength);
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    var headers = Headers();
    setContent_Type(headers, (char*)"application/json");
    setContent_Length(headers, sizeof(char) * 1024);
    Set_Cookies(headers, (char*)"foo=bar&lorem=ipsum");
    printf(
        "Content-Type: %s,\n"
        "Content-Length: %i,\n"
        "Set-Cookies: '%s'\n",
        getContent_Type(headers),
        getContent_Length(headers),
        getCookies(headers)
    );
    freeObject(headers);
    return 0;
}
