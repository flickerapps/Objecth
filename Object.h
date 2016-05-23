#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum{
    NUMBER = 1,
    STRING,
    BOOLEAN,
    OBJECT,
    ARRAYOFNUMBER,
    ARRAYOFSTRING,
    ARRAYOFBOOLEAN,
    UNDEFINED
} Type;

//Class Object ( omg!! )
typedef struct Object{

    // attrs
    const char* key;
    void* value;
    Type type;
    Object* next;

    // methods

    /* getters */
    const char*(*getKey)(Object*);
    int(*getType)(Object*);
    void*(*getValue)(Object*); /* generic */
    int(*getNumber)(Object*);
    const char*(*getString)(Object*);
    bool(*getBoolean)(Object*);
    Object*(*getChild)(Object*);
    int*(*getArrayOfNumber)(Object*);
    const char**(*getArrayOfString)(Object*);


    /* setter */
    Object*(*setType)(Object*, Type);
    Object*(*setNumber)(Object*, int);
    Object*(*setString)(Object*, const char*);
    Object*(*setBoolean)(Object*, bool);
    Object*(*setChild)(Object*, Object*);
    Object*(*appendChild)(Object*, Object*);
    Object*(*setArrayOfNumber)(Object*, int*);
    Object*(*setArrayOfString)(Object*, const char**);
    Object*(*setNext)(Object*, Object*);
    Object*(*find)(Object*, const char*);
    Object*(*removeChild)(Object*, const char*);

} Object;

typedef Object* var;

const char* __getKey__(var self){
    return self->key;
}
int __getType__(var self){
    return self->type;
}


const char* getTypeStr(var self){
    switch(self->type){
        case NUMBER:
            return "Number";
        case STRING:
            return "String";
        case OBJECT:
            return "Object";
        case ARRAYOFNUMBER:
            return "Array Of Number";
        case ARRAYOFSTRING:
            return "Array Of String";
        case ARRAYOFBOOLEAN:
            return "Array Of Boolean";
    }
    return "Undefined";
}

bool Objexists(var self){
    return (self == NULL) ? false : true;
}


/* SETTERS */


var __setType__(var self, Type aType){
    if(Objexists(self)){
        self->type = aType;
    }
    return self;
}
var __setValue__(var self, void* value){
    if(Objexists(self)){
        self->value = value;
    }
    /*
     * Examples:
     * setValue(obj, (void*) 3);
     * setValue(obj, (void*) "Hello!");
     * setValue(obj, (void*) true);
    */
    return self;

}
var __setNumber__(var self, int value){
    if(Objexists(self)){
        self->type = NUMBER;
        self->value = (void*)value;
    }
    return self;
}

var __setString__(var self, const char* value){
    if(Objexists(self)){
        self->type = STRING;
        self->value = (void*)value;
    }
    return self;
}
var __setBoolean__(var self, bool value){
    if(Objexists(self)){
        self->type = BOOLEAN;
        self->value = (void*)value;
    }
    return self;
}
var __setChild__(var self, var value){
    if(Objexists(self)){
        self->type = OBJECT;
        self->value = (void*)value;
    }
    return self;
}

var __setArrayOfNumber__(var self, int* value){
    if(Objexists(self)){
        self->type = ARRAYOFNUMBER;
        self->value = (void*)value;
    }
    return self;
}
var __setArrayOfString__(var self, const char** value){
    if(Objexists(self)){
        self->type = ARRAYOFSTRING;
        self->value = (void*)value;
    }
    return self;
}
var __setNext__(var self, var thenext){
    if(Objexists(self)){
        self->next = thenext;
    }
    return thenext;
}
/* Gettets */

void* __getValue__(var self){
    /*
     * Examples:
     * (int)getValue(obj);
     * (const char*)getValue(obj);
     * (bool)getValue(obj);
    */
    return self->value;
}

int __getNumber__(var self){
    return (int)self->value;
}

const char* __getString__(var self){
    return (const char*)self->value;
}
bool __getBoolean__(var self){
    return (bool)self->value;
}
var __getChild__(var self){
    return (var)self->value;
}
int* __getArrayOfNumber__(var self){
    return (int*)self->value;
}
const char** __getArrayOfString__(var self){
    return (const char**)self->value;
}


var __removeChild__(var self, const char* key){
    if(Objexists(self)){
        var aux = (var)self->value;
        while(aux != NULL){
            if(strcmp(aux->key,key) == 0){
                var temp = aux;
                aux = aux->next;
                free(temp);
                break;
            }
            aux = aux->next;
        }
    }
    return self;
}
var __find__(var self, const char* key){
    if(Objexists(self)){
        var aux = (var)self->value;
        while(aux != NULL){
            if(strcmp(aux->key,key) == 0){
                break;
            }
            aux = aux->next;
        }
        return aux;
    }
    return NULL;
}

bool hasChild(var self, const char* key){
    if(Objexists(self)){
        var aux = (var)self->value;
        while(aux != NULL){
            if(strcmp(aux->key,key) == 0){
                return true;
            }
            aux = aux->next;
        }
    }
    return false;
}
/* Evaluators */

bool isNumber(var self){
    if(self->type == NUMBER){
        return true;
    }
    return false;
}
bool isString(var self){
    if(self->type == STRING){
        return true;
    }
    return false;
}
bool isBoolean(var self){
    if(self->type == BOOLEAN){
        return true;
    }
    return false;
}
bool isObject(var self){
    if(self->type == OBJECT){
        return true;
    }
    return false;
}
bool isArray(var self){
    if(self->type == ARRAYOFNUMBER || self->type == ARRAYOFSTRING){
        return true;
    }
    return false;
}
bool isArrayOfNumber(var self){
    if(self->type == ARRAYOFNUMBER){
        return true;
    }
    return false;
}
bool isArrayOfString(var self){
    if(self->type == ARRAYOFSTRING){
        return true;
    }
    return false;
}

bool isUndefined(Object *self){
    if(self == NULL || self->key == NULL || self->type == UNDEFINED ){
        return true;
    }
    return false;
}

var __appendChild__(var self, var value){
    if(Objexists(self)){
        if(isObject(self)){
            var first = self->getChild(self);
            value->next = first;
            self->setChild(self, value);
        }
    }
    return self;
}

int freeObject(var self){
    if(Objexists(self)){
        if(!isObject(self)){
            free(self);
            return 1;
        }
        else{
            var supr = self->getChild(self);
            while(supr != NULL){
                if(supr->next == NULL){
                    free(supr);
                    break;
                }
                var temp = supr;
                supr = supr->next;
                free(temp);
            }
            free(self);
            return 2;
        }
    }
    return 0;
}
// like => new Object();
var ObjectCreate(const char* key){
    var self = (var)calloc(1,sizeof(Object));
    self->key = key;
    self->value = NULL;
    self->type = UNDEFINED;
    self->next = NULL;

    self->getKey = __getKey__;
    self->getType = __getType__;

    self->setType = __setType__;
    self->setNumber = __setNumber__;
    self->setString = __setString__;
    self->setBoolean = __setBoolean__;
    self->setChild = __setChild__;
    self->appendChild = __appendChild__;
    self->setArrayOfNumber = __setArrayOfNumber__;
    self->setArrayOfString = __setArrayOfString__;
    self->setNext = __setNext__;

    self->getValue = __getValue__;
    self->getNumber = __getNumber__;
    self->getString = __getString__;
    self->getBoolean = __getBoolean__;
    self->getChild = __getChild__;
    self->getArrayOfNumber = __getArrayOfNumber__;
    self->getArrayOfString = __getArrayOfString__;

    self->find = __find__;
    self->removeChild = __removeChild__;
    return self;
}

#endif
