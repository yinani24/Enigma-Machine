#ifndef ROTOR_H
#define ROTOR_H

#include "common.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Rotor{
    size_t ring;
    size_t init;
    char right[27];
    char left[27];
    char * notch;
    size_t num_notch;
}Rotor;

Rotor * rotor_intialization(size_t num_rotors, const char **rotors, size_t *rings,
                   size_t *inits);
void free_rotor(Rotor* Rot, size_t num_rotors);
/* Your definition of Rotor */

#endif