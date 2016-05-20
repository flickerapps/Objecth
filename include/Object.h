#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum{
    Number_ = 1,
    String_,
    Boolean_,
    Object_,
    ArrayOfNumber_,
    ArrayOfString_,
    ArrayOfBoolean_,
    ArrayOfObject_,
    Undefined_
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
    int(*getValue_Number)(Object*);
    const char*(*getValue_String)(Object*);
    bool(*getValue_Boolean)(Object*);
    Object*(*getValue_Object)(Object*);
    int*(*getValue_ArrayOfNumber)(Object*);
    const char**(*getValue_ArrayOfString)(Object*);
    Object**(*getValue_ArrayOfObject)(Object*);


    /* setter */
    Object*(*setValue_Number)(Object*, int);
    Object*(*setValue_String)(Object*, const char*);
    Object*(*setValue_Boolean)(Object*, bool);
    Object*(*setValue_Object)(Object*, Object*);
    Object*(*setValue_ArrayOfNumber)(Object*, int*);
    Object*(*setValue_ArrayOfString)(Object*, const char**);
    Object*(*setValue_ArrayOfObject)(Object*, Object**);
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
        case Number_:
            return "Number";
        case String_:
            return "String";
        case Object_:
            return "Object";
        case ArrayOfNumber_:
            return "Array Of Number";
        case ArrayOfString_:
            return "Array Of String";
        case ArrayOfBoolean_:
            return "Array Of Boolean";
        case ArrayOfObject_:
            return "Array Of Object";
    }
    return "Undefined";
}

/* SETTERS */

var __setValue_Number__(var self, int value){
    self->type = Number_;
    self->value = (void*)value;
}

var __setValue_String__(var self, const char* value){
    self->type = String_;
    self->value = (void*)value;
    return self;
}
var __setValue_Boolean__(var self, bool value){
    self->type = Boolean_;
    self->value = (void*)value;
    return self;
}
var __setValue_Object__(var self, var value){
    self->type = Object_;
    self->value = (void*)value;
    return self;
}
var __setValue_ArrayOfNumber__(var self, int* value){
    self->type = ArrayOfNumber_;
    self->value = (void*)value;
    return self;
}
var __setValue_ArrayOfString__(var self, const char** value){
    self->type = ArrayOfString_;
    self->value = (void*)value;
    return self;
}
var __setValue_ArrayOfObject__(var self, var* value){
    self->type = ArrayOfObject_;
    self->value = (void*)value;
    return self;
}

var __setNext__(var self, var thenext){
    self->next = thenext;
    return thenext;
}
/* Gettets */


int __getValue_Number__(var self){
    return (int)self->value;
}

const char* __getValue_String__(var self){
    return (const char*)self->value;
}
bool __getValue_Boolean__(var self){
    return (bool)self->value;
}
var __getValue_Object__(var self){
    return (var)self->value;
}
int* __getValue_ArrayOfNumber__(var self){
    return (int*)self->value;
}
const char** __getValue_ArrayOfString__(var self){
    return (const char**)self->value;
}
var* __getValue_ArrayOfObject__(var self){
    return (var*)self->value;
}

var __removeChild__(var self, const char* key){
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
    return self;
}
var __find__(var self, const char* key){
    var aux = (var)self->value;
    while(aux != NULL){
        if(strcmp(aux->key,key) == 0){
            break;
        }
        aux = aux->next;
    }
    return aux;
}

bool hasChild(var self, const char* key){
    var aux = (var)self->value;
    while(aux != NULL){
        if(strcmp(aux->key,key) == 0){
            return true;
        }
        aux = aux->next;
    }
    return false;
}
/* Evaluators */

bool isNumber(var self){
    if(self->type == Number_){
        return true;
    }
    return false;
}
bool isString(var self){
    if(self->type == String_){
        return true;
    }
    return false;
}
bool isBoolean(var self){
    if(self->type == Boolean_){
        return true;
    }
    return false;
}
bool isObject(var self){
    if(self->type == Object_){
        return true;
    }
    return false;
}
bool isArray(var self){
    if(self->type == ArrayOfNumber_ || self->type == ArrayOfString_ || self->type == ArrayOfObject_){
        return true;
    }
    return false;
}
bool isArrayOfNumber(var self){
    if(self->type == ArrayOfNumber_){
        return true;
    }
    return false;
}
bool isArrayOfString(var self){
    if(self->type == ArrayOfString_){
        return true;
    }
    return false;
}
bool isArrayOfObject(var self){
    if(self->type ==ArrayOfObject_){
        return true;
    }
    return false;
}

bool isUndefined(Object *self){
    if(self->type == Undefined_){
        return true;
    }
    return false;
}

// like => new Object();
var Object_Create(const char* key){
    var self = (var)malloc(sizeof(Object));
    self->key = key;
    self->value = NULL;
    self->type = Undefined_;
    self->next = NULL;

    self->getKey = __getKey__;
    self->getType = __getType__;

    self->setValue_Number = __setValue_Number__;
    self->setValue_String = __setValue_String__;
    self->setValue_Boolean = __setValue_Boolean__;
    self->setValue_Object = __setValue_Object__;
    self->setValue_ArrayOfNumber = __setValue_ArrayOfNumber__;
    self->setValue_ArrayOfString = __setValue_ArrayOfString__;
    self->setValue_ArrayOfObject = __setValue_ArrayOfObject__;
    self->setNext = __setNext__;

    self->getValue_Number = __getValue_Number__;
    self->getValue_String = __getValue_String__;
    self->getValue_Boolean = __getValue_Boolean__;
    self->getValue_Object = __getValue_Object__;
    self->getValue_ArrayOfNumber = __getValue_ArrayOfNumber__;
    self->getValue_ArrayOfString = __getValue_ArrayOfString__;
    self->getValue_ArrayOfObject = __getValue_ArrayOfObject__;

    self->find = __find__;
    self->removeChild = __removeChild__;
    return self;
}

#endif
