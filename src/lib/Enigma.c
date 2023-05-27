#include "Enigma.h"
#include "EnigmaImpl.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "Rotor.h"

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
                    if(num_rotors){
                        E.Rot = rotor_intialization(num_rotors, rotors, rings, inits);
                    }
                    E.num_rotors = num_rotors;
                    // if(rotors && inits && rings){
                    //     printf("%ld",num_rotors);
                    // }
                    
                    return &E;
}

void reset_rotor_Enigma(Enigma *self, size_t *new_setting){
    for(size_t i = 0; i < self->num_rotors; i++){
        self->Rot[i].init = new_setting[i];
    }
}

// bool Rotate(Rotor * Rot){
//     for(size_t k = 0 ; k < Rot->num_notch; k++){
//         if(Rot->right[Rot->init] == Rot->notch[k]){
//             break;
//         }
            
//     }
// }

bool Exists(Rotor R, char c){
    for(size_t k = 0 ; k < R.num_notch; k++){
        if(c == R.notch[k]){
            return true;
        }
    }
    return false;
}

void tick_Enigma(Enigma *self){
    self->Rot[0].init = self->Rot[0].init + 1;
    bool shift[self->num_rotors];

    for(size_t i = 0; i < self->num_rotors; i++){
        shift[i] = false;
    }

    for(size_t i = 0 ; i < self->num_rotors; i++){
        
        self->Rot[i].init = self->Rot[i].init % MAX_SIZE;
        char temp = self->Rot[i].right[self->Rot[i].init];
        
        if(Exists(self->Rot[i], temp) && ((i + 1) < self->num_rotors)){
            if(self->Rot[i+1].num_notch)
                shift[i + 1] = true; 
        }
    }

    for(size_t i = 0 ; i < self->num_rotors; i++){
        if(shift[i])
            self->Rot[i].init = (self->Rot[i].init + 1) % MAX_SIZE;
    } 
}

void tick_n_Enigma(Enigma *self, size_t n){
    for(size_t l = 0; l < n; l++){
        tick_Enigma(self);
    }
}

void get_setting_Enigma(Enigma *self, char *ret){
    size_t i = 0;
    for(; i < self->num_rotors; i++){
        size_t temp = self->Rot[i].init % MAX_SIZE;
        ret[i] = temp + 'A';
    }
}

size_t position(char * side, char c){
    for(size_t i = 0; i < strlen(side); i++){
        if(side[i] == c){
            return i;
        }
    }
    return 0;
}

// void Rotate(Enigma * self){
//     size_t shifts[self->num_rotors];
//     for(size_t i = 0 ; i < self->num_rotors; i++){
//         // if(Exists(self->Rot[i], ) && ((i + 1) < num_rotors)){
//         //     if(R[i+1].num_notch)
//         //         R[i+1].init += 1; 
//         // }
//     }
// }

char forward_check(Rotor * R, size_t num_rotors, char src){
    //R[0].init = R[0].init + 1;
    
    char temp = src;

    for(size_t i = 0; i < num_rotors; i++){
        size_t shift = temp - 'A';
        size_t left_pos = 0;
        //DEBUGF("Shift: %ld\n", shift);
        //left_pos += R[i].init;
        size_t k = ((R[i].init % MAX_SIZE) + (shift % MAX_SIZE)) % MAX_SIZE;
        size_t right_pos = ((k % MAX_SIZE - (R[i].ring) % MAX_SIZE) + MAX_SIZE) % MAX_SIZE;
        char f = R[i].right[right_pos];
        
        DEBUGF("Right Position %ld: %ld\n", i, right_pos);
        DEBUGF("Right Char %ld: %c\n", i, f);
        // if(Exists(R[i], f) && ((i + 1) < num_rotors)){
        //     if(R[i+1].num_notch)
        //         R[i+1].init += 1; 
        // }
        
        left_pos = position(R[i].left, f); 
        left_pos = ((left_pos % MAX_SIZE - R[i].init % MAX_SIZE) + MAX_SIZE) % MAX_SIZE;
        left_pos = ((left_pos % MAX_SIZE) + (R[i].ring % MAX_SIZE)) % MAX_SIZE; 
        temp = R[i].left[left_pos];

        DEBUGF("Left Position %ld: %ld\n", i, left_pos);
        DEBUGF("Left Char %ld: %c\n", i, temp);
        
    }
    
    return temp;
}

char backward_check(Rotor * R, size_t num_rotors, char src){
    
    char temp = src;
    
    for(size_t i = num_rotors; i-- >0 ;){
        size_t shift = temp - 'A';
        size_t left_pos = 0;
        //left_pos += R[i].init;
        //DEBUGF("Right Position: %ld\n", shift);
        size_t k = ((R[i].init % MAX_SIZE) + (shift % MAX_SIZE)) % MAX_SIZE;
        size_t right_pos = ((k % MAX_SIZE - (R[i].ring) % MAX_SIZE) + MAX_SIZE) % MAX_SIZE;
        char f = R[i].left[right_pos];
        DEBUGF("Right Position %ld: %ld\n", i, right_pos);
        DEBUGF("Right Char %ld: %c\n", i, f);

        left_pos = position(R[i].right, f); 
        left_pos = ((left_pos % MAX_SIZE - R[i].init % MAX_SIZE) + MAX_SIZE) % MAX_SIZE;
        left_pos = ((left_pos % MAX_SIZE) + (R[i].ring % MAX_SIZE)) % MAX_SIZE; 
        temp = left_pos + 'A';
        
        DEBUGF("Left Position %ld: %ld\n", i, left_pos);
        DEBUGF("Left Char %ld: %c\n", i, temp);

    }
    return temp;
}

char *encrypt_Enigma(Enigma *self, char *dst, const char *src){
    strcpy(dst,src);
    //printf("Destination Variabe: %s\n", dst);
    for(size_t i = 0; i < strlen(dst); i++){
        //printf("Destination Var Before: %c\n", dst[i]);
        if(dst[i] != ' '){
            dst[i] = self->plug_switch[dst[i] - 'A'];
            if(self->num_rotors)
                DEBUGF("\nPosition in Forward %ld\n\n", i+1);
                tick_Enigma(self);
                dst[i] = forward_check(self->Rot, self->num_rotors, dst[i]);
            //DEBUGF("Before Refl Char: %c\n", dst[i]);
            dst[i] = self->Ref.letters[dst[i] - 'A'];
            //DEBUGF("After Refl Char: %c\n", dst[i]);
            if(self->num_rotors)
                DEBUGF("\nPosition in Backward %ld\n\n", i+1);
                dst[i] = backward_check(self->Rot, self->num_rotors, dst[i]);
            dst[i] = self->plug_switch[dst[i] - 'A'];
        }
        
        //printf("Destination Var After: %c\n", dst[i]);   
    }
    //printf("Destination Variabe2: %s\n", dst);
    return dst;
}

void free_Enigma(Enigma *self){
    free_plugboard(self->Plug);
    free_rotor(self->Rot, self->num_rotors);
}