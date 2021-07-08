int entry_state(void);
int foo_state(void);
int bar_state(void);
int exit_state(void);

int (*state[])(void) = {entry_state, foo_state, bar_state, exit_state};

typedef enum state_codes{
    entry,
    foo,
    bar,
    end
}state_codes;

typedef enum ret_codes{
    ok, fail, repeat
}ret_codes;

typedef struct transition{
    state_codes src_state;
    ret_codes ret_code;
    state_code dest_state;
} transition_t;

transition_t state_transition[] = {
    {entry, ok, foo},
    {entry, fail, end},
    {foo, ok, bar},
    {foo, fail, end},
    {foo, repeat, foo},
    {bar, ok, end},
    {bar, fail, end},
    {bar, repeat, foo}
};

state_codes lookup_transition(){
    return (state_codes)(rand()%4);
}

int main(int argc, char* argv[]){
    state_codes curr_state = entry;
    ret_codes rc;
    int(*state_fun)(void);
    while(true){
        state_fun = state[curr_state];
        rc = state_fun();
        if(curr_state == end){
            break;
        }
        curr_state = lookup_transition();
    }
    return 0;
}
    
