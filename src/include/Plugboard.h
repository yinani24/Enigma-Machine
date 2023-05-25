#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "common.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
// #include<stddef.h>

/* Your definition of Plugboard */
typedef struct Plugboard{
    char key;
    char value;
}Plugboard;

Plugboard * forming_plugboard(size_t num_pairs, const char *pairs);
void free_plugboard(struct Plugboard * plug);
void forming_plug_string(struct Plugboard * plug, char * plug_switch, size_t num_pairs);

#endif