#include "Plugboard.h"
#include "common.h"

void forming_plugboard(struct Plugboard * plug, size_t num_pairs, const char *pairs){ 
    if(num_pairs >= strlen(pairs)){
        plug = NULL;
    }
    else{
        plug = malloc(sizeof(Plugboard) * num_pairs);
        for(size_t i = 0; i < num_pairs; i++){
            plug[i].key = pairs[2*i];
            plug[i].value = pairs[2*i + 1];
        }
    }
}

void forming_plug_string(struct Plugboard * plug, char * plug_switch, size_t num_pairs){
    for(size_t i = 0; i < num_pairs; i++){
        plug_switch[plug[i].key - 'A'] = plug_switch.value;
        plug_switch[plug[i].value - 'A'] = plug_switch.key;
    }
}
/* Your code to implement Plugboard here */