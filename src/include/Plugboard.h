#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "common.h"
#include <stdio.h>
#include<stdint.h>
// #include<stddef.h>

/* Your definition of Plugboard */
typedef struct Plugboard{
    char key;
    char value;
};

void forming_plugboard(struct Plugboard * plug, size_t num_pairs, const char *pairs);`

#endif