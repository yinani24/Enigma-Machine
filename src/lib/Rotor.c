#include "Rotor.h"
#include "common.h"

Rotor * rotor_intialization(size_t num_rotors, const char **rotors, size_t *rings,
                   size_t *inits){
    Rotor * Rot = malloc(sizeof(Rotor) * num_rotors);
    for(size_t i = 0; i < num_rotors; i++){
        
        Rot[i].ring = rings[i];
        Rot[i].init = inits[i];
        memcpy(Rot[i].right, rotors[i], 26);
        memcpy(Rot[i].left, LETTERS, 26);

        size_t len = strlen(rotors[i]) - 26 - 1;
        //DEBUGF("Len Value: %ld\n", len);

        Rot[i].notch = malloc(sizeof(char) * len);
        char temp[len];
        
        memcpy(temp, rotors[i] + 27, len);
        
        for(size_t j = 0; j < len; j++){
            Rot[i].notch[j] = temp[j];
            //DEBUGF("Len Value: %c\n", Rot[i].notch[j]);
        }

        if(temp[0] == '\0'){
            Rot[i].num_notch = 0;
        }
        else{
            Rot[i].num_notch = len;
        }

    }
    return Rot;
}

void free_rotor(Rotor* Rot, size_t num_rotors){
    for(size_t i = 0; i < num_rotors; i++){
        free(Rot[i].notch);
    }
    free(Rot);
}
/* Your code to implement Rotor here */