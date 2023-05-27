#ifndef ENIGMA_IMPL_H
#define ENIGMA_IMPL_H

#include "Enigma.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "Rotor.h"

struct Enigma {
  Plugboard * Plug;
  char plug_switch[27];
  Reflector Ref;
  Rotor * Rot;
  size_t num_rotors;
  /* Your implementation of Enigma */
}E;



#endif