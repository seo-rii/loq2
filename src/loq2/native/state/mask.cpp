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
            int x = block_ik[i].p.x(), y = block_ik[i].p.y();
            if (block_ik[i].dir) {
                if (block_ik[i].dir == 1) {
                    if ((x == 5 || x == 6) && (y == 4 || y == 5)) {
                        state = block_ik[i].apply(state, false);
                        state.block_ik[i] = {{}, 5};
                    }
                } else {
                    if ((x == 4 || x == 5) && (y == 5 || y == 6)) {
                        state = block_ik[i].apply(state, false);
                        state.block_ik[i] = {{}, 5};
                    }
                }
            }
        } else {
            int x = block_ip[i].p.x(), y = block_ip[i].p.y();
            if (block_ip[i].dir) {
                if (block_ip[i].dir == 1) {
                    if ((x == 5 || x == 6) && (y == 4 || y == 5)) {
                        state = block_ip[i].apply(state, false);
                        state.block_ip[i] = {{}, 5};
                    }
                } else {
                    if ((x == 4 || x == 5) && (y == 5 || y == 6)) {
                        state = block_ip[i].apply(state, false);
                        state.block_ip[i] = {{}, 5};
                    }
                }
            }
        }
    }
    for (int i = 0; i < L_COUNT; i++) {
        if (turn) {
            if (block_lk[i].dir) {
                int x = block_lk[i].p.x(), y = block_lk[i].p.y();
                if (4 <= x && x <= 6 && 4 <= y && y <= 6
                    && !(block_lk[i].dir == 1 && x == 4 && y == 4)
                    && !(block_lk[i].dir == 2 && x == 4 && y == 6)
                    && !(block_lk[i].dir == 3 && x == 6 && y == 6)
                    && !(block_lk[i].dir == 4 && x == 6 && y == 4)) {
                    state = block_lk[i].apply(state, false);
                    state.block_lk[i] = {{}, 5};
                }
            }
        } else {
            if (block_lp[i].dir) {
                int x = block_lp[i].p.x(), y = block_lp[i].p.y();
                if (4 <= x && x <= 6 && 4 <= y && y <= 6
                    && !(block_lp[i].dir == 1 && x == 4 && y == 4)
                    && !(block_lp[i].dir == 2 && x == 4 && y == 6)
                    && !(block_lp[i].dir == 3 && x == 6 && y == 6)
                    && !(block_lp[i].dir == 4 && x == 6 && y == 4)) {
                    state = block_lp[i].apply(state, false);
                    state.block_lp[i] = {{}, 5};
                }
            }
        }
    }
    return state;
}