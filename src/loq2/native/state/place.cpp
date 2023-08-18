#include "../library.h"

State State::placeI(const IBlock &iBlock) const {
  if (!iBlock || !iBlock.valid())
    return NULL_STATE;
  if (this->cross(iBlock))
    return NULL_STATE;
  State state(*this);
  if (state.turn) {
    for (int i = 0; i < I_COUNT; i++) {
      if (!state.block_ip[i]) {
        state.block_ip[i] = iBlock;
        state = iBlock.apply(state).next();
        if (!state.endable())
          return NULL_STATE;
        return state;
      }
    }
    return NULL_STATE;
  } else {
    for (int i = 0; i < I_COUNT; i++) {
      if (!state.block_ik[i]) {
        state.block_ik[i] = iBlock;
        state = iBlock.apply(state).next();
        if (!state.endable())
          return NULL_STATE;
        return state;
      }
    }
    return NULL_STATE;
  }
}

State State::placeL(const LBlock &lBlock) const {
  if (!lBlock || !lBlock.valid())
    return NULL_STATE;
  if (this->cross(lBlock))
    return NULL_STATE;
  State state(*this);
  if (state.turn) {
    for (int i = 0; i < L_COUNT; i++) {
      if (!state.block_lp[i]) {
        state.block_lp[i] = lBlock;
        state = lBlock.apply(state).next();
        if (!state.endable())
          return NULL_STATE;
        return state;
      }
    }
    return NULL_STATE;
  } else {
    for (int i = 0; i < L_COUNT; i++) {
      if (!state.block_lk[i]) {
        state.block_lk[i] = lBlock;
        state = lBlock.apply(state).next();
        if (!state.endable())
          return NULL_STATE;
        return state;
      }
    }
    return NULL_STATE;
  }
}
