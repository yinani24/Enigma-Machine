#include "Reflector.h"
#include "common.h"
#include "stdlib.h"
#include "string.h"


void reflectors(struct Reflector  * Ref, const char * reflectors){
    strcpy(Ref->letters, reflectors);
}
/* Your code to implement Reflector here */