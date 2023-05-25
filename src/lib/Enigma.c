#include "Enigma.h"
#include "EnigmaImpl.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "Rotor.h"

/* Your code to implement Enigma here */

Enigma *new_Enigma(size_t num_rotors, const char **rotors, size_t *rings,
                   size_t *inits, const char *reflector, size_t num_pairs,
                   const char *pairs){
                    Enigma E;
                    strcpy(E.plug_switch, LETTERS);
                    forming_plugboard(E.plug, num_pairs, pairs);
                    forming_plug_string(E.plug, E.plug_switch);
                    reflector(E.Ref, reflector);
                    return &E;
}

char *encrypt_Enigma(Enigma *self, char *dst, const char *src){
    for(size_t i = 0; i < strlen(src); i++){
        src[i] = E.plug_switch[src[i] - 'A'];
        src[i] = E.Ref.letters[src[i] - 'A'];
        src[i] = E.plug_switch[src[i] - 'A'];   
    }
}

free_Enigma(Enigma *self){
    free(self->plug);
}