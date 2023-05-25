#include "Plugboard.h"
#include "common.h"

Plugboard* forming_plugboard(size_t num_pairs, const char *pairs){ 
    Plugboard * plug = (Plugboard*) malloc(sizeof(Plugboard) * num_pairs);
    for(size_t i = 0; i < num_pairs; i++){
        plug[i].key = pairs[2*i];
        plug[i].value = pairs[2*i + 1];
        // printf("%c\n", plug[i].value);
        // printf("%c\n", plug[i].key);
    }
    return plug;
}

void forming_plug_string(Plugboard * plug, char * plug_switch, size_t num_pairs){
    for(size_t i = 0; i < num_pairs; i++){
        // printf("%c\n", plug[i].value);
        // printf("%c\n", plug[i].key);
        plug_switch[plug[i].key - 'A'] = plug[i].value;
        plug_switch[plug[i].value - 'A'] = plug[i].key;
    }
}

void free_plugboard(struct Plugboard * plug){
    free(plug);
}