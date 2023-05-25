#ifndef ENIGMA_IMPL_H
#define ENIGMA_IMPL_H

#include "Enigma.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "Rotor.h"

struct Enigma {
  struct Plugboard * plug;
  char plug_switch[27];
  struct Reflector Ref;
  /* Your implementation of Enigma */
};

#endif