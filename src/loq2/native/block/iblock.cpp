#include "../library.h"

State IBlock::apply(const State &s) const {
    State ns = s;
    if (this->dir == 1) {
        if (!ns.map.set_h_block(this->p)) return NULL_STATE;
        if (!ns.map.set_h_block(this->p.up())) return NULL_STATE;
    } else {
        if (!ns.map.set_v_block(this->p)) return NULL_STATE;
        if (!ns.map.set_v_block(this->p.right())) return NULL_STATE;
    }
    return ns;
}

bool IBlock::valid() const {
    if (dir == 1)
        return this->p.x() >= 1
               && this->p.x() <= 10
               && this->p.y() >= 1
               && this->p.y() <= 8;
    if (dir == 2)
        return this->p.x() >= 1
               && this->p.x() <= 8
               && this->p.y() >= 1
               && this->p.y() <= 10;
    return false;
}