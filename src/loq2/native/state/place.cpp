#include "../library.h"

inline State State::placeI(const IBlock &iBlock) const {
    if (!iBlock || !iBlock.valid()) return NULL_STATE;
    if (this->cross(iBlock)) return NULL_STATE;
    State state(*this);
    auto target = state.turn ? &state.block_ip : &state.block_ik;
    for (auto &b: *target) {
        if (!b) {
            b = iBlock;
            state.turn = !state.turn;
            return b.apply(state);
        }
    }
    return NULL_STATE;
}

inline State State::placeL(const LBlock &lBlock) const {
    if (!lBlock || !lBlock.valid()) return NULL_STATE;
    if (this->cross(lBlock)) return NULL_STATE;
    State state(*this);
    auto target = state.turn ? &state.block_lp : &state.block_lk;
    for (auto &b: *target) {
        if (!b) {
            b = lBlock;
            state.turn = !state.turn;
            return b.apply(state);
        }
    }
    return NULL_STATE;
}