#include "Enigma.h"
#include "EnigmaImpl.h"
#include "Plugboard.h"
#include "Reflector.h"
// #include "Rotor.h"

/* Your code to implement Enigma here */

Enigma *new_Enigma(size_t num_rotors, const char **rotors, size_t *rings,
                   size_t *inits, const char *reflector, size_t num_pairs,
                   const char *pairs){
                    strcpy(E.plug_switch, LETTERS);
                    E.Plug = forming_plugboard(num_pairs, pairs);
                    //printf("%s\n", E.plug_switch);
                    forming_plug_string(E.Plug, E.plug_switch, num_pairs);
                    //printf("%s\n", E.plug_switch);
                    reflectors(&E.Ref, reflector);
                    // *inits = 0;
                    // *rings = 0;
                    if(rotors && inits && rings){
                        printf("%ld",num_rotors);
                    }
                    
                    return &E;
}

char *encrypt_Enigma(Enigma *self, char *dst, const char *src){
    strcpy(dst,src);
    //printf("Destination Variabe: %s\n", dst);
    for(size_t i = 0; i < strlen(dst); i++){
        //printf("Destination Var Before: %c\n", dst[i]);
        if(dst[i] != ' '){
            dst[i] = self->plug_switch[dst[i] - 'A'];
            dst[i] = self->Ref.letters[dst[i] - 'A'];
            dst[i] = self->plug_switch[dst[i] - 'A'];
        }
        
        //printf("Destination Var After: %c\n", dst[i]);   
    }
    //printf("Destination Variabe2: %s\n", dst);
    return dst;
}

void free_Enigma(Enigma *self){
    free_plugboard(self->Plug);
}