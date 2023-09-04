#include "../library.h"
#include "../type.h"

State State::mask() const {
    if (internal()) return State(*this);
    State state(*this);
    if (internal(false)) {
        if (turn) state.k = {};
        else state.p = {};
    }
    for (int i = 0; i < I_COUNT; i++) {
        if (turn) {
            if (block_ik[i].valid() && block_ik[i].internal()) {
                state = block_ik[i].apply(state, false);
                state.block_ik[i] = {{}, 5};
            }
        } else {
            if (block_ip[i].valid() && block_ip[i].internal()) {
                state = block_ip[i].apply(state, false);
                state.block_ip[i] = {{}, 5};
            }
        }
    }
    for (int i = 0; i < L_COUNT; i++) {
        if (turn) {
            if (block_lk[i].valid() && block_lk[i].internal()) {
                state = block_lk[i].apply(state, false);
                state.block_lk[i] = {{}, 5};
            }
        } else {
            if (block_lp[i].valid() && block_lp[i].internal()) {
                state = block_lp[i].apply(state, false);
                state.block_lp[i] = {{}, 5};
            }
        }
    }
    return state;
}