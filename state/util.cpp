#include "./state.h"

inline Point State::position(bool my) const {
    return (!my ^ this->turn) ? this->k : this->p;
}

inline bool State::internal(bool my) const {
    Point pos = this->position(my);
    return pos.x() >= 4
           && pos.x() <= 6
           && pos.y() >= 4
           && pos.y() <= 6;
}

State State::act(byte type, byte p1, byte p2, byte p3) const {
    if (type == 0) return move({p1, p2});
    if (type == 1) return placeI({{p1, p2}, p3});
    if (type == 2) return placeL({{p1, p2}, p3});
    return NULL_STATE;
}


inline bool State::v_block(const Point &pos) const {
    return this->map.v_block(pos);
}

inline bool State::h_block(const Point &pos) const {
    return this->map.h_block(pos);
}