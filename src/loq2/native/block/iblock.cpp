#include "../library.h"

State IBlock::apply(const State &s, bool set) const {
    State ns = s;
    if (this->dir == 1) {
        if (!ns.map.set_h_block(this->p, set)) return NULL_STATE;
        if (!ns.map.set_h_block(this->p.up(), set)) return NULL_STATE;
    } else {
        if (!ns.map.set_v_block(this->p, set)) return NULL_STATE;
        if (!ns.map.set_v_block(this->p.right(), set)) return NULL_STATE;
    }
    return ns;
}

bool IBlock::valid() const {
    if (dir == 1)
        return this->p.x() >= 2
               && this->p.x() <= 9
               && this->p.y() >= 1
               && this->p.y() <= 8;
    if (dir == 2)
        return this->p.x() >= 1
               && this->p.x() <= 8
               && this->p.y() >= 2
               && this->p.y() <= 9;
    return false;
}

bool IBlock::internal(bool strict) const {
    if (strict) {
        if (dir == 1)
            return this->p.x() >= 5 && this->p.x() <= 6 && this->p.y() >= 4 && this->p.y() <= 5;
        if (dir == 2)
            return this->p.x() >= 4 && this->p.x() <= 5 && this->p.y() >= 5 && this->p.y() <= 6;
    } else {
        if (dir == 1)
            return this->p.x() >= 5 && this->p.x() <= 6 && this->p.y() >= 3 && this->p.y() <= 6;
        if (dir == 2)
            return this->p.x() >= 3 && this->p.x() <= 6 && this->p.y() >= 5 && this->p.y() <= 6;
    }
    return true;
}
