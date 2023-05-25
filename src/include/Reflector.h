#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "common.h"

/* Your definition of Reflector */
typedef struct Reflector{
    char letters[27];
}Reflector;

void reflectors(struct Reflector  * Ref, const char * reflectors);

#endif