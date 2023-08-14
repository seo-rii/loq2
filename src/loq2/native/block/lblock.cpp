#include "../library.h"

State LBlock::apply(const State &s) const {
    State ns = s;
    if (this->dir == 1) {
        if (!ns.map.set_h_block(this->p)) return NULL_STATE;
        if (!ns.map.set_v_block(this->p)) return NULL_STATE;
    } else if (this->dir == 2) {
        if (!ns.map.set_h_block(this->p)) return NULL_STATE;
        if (!ns.map.set_v_block(this->p.up())) return NULL_STATE;
    } else if (this->dir == 3) {
        if (!ns.map.set_h_block(this->p.right())) return NULL_STATE;
        if (!ns.map.set_v_block(this->p.up())) return NULL_STATE;
    } else {
        if (!ns.map.set_h_block(this->p.right())) return NULL_STATE;
        if (!ns.map.set_v_block(this->p)) return NULL_STATE;
    }
    return ns;
}

bool LBlock::valid() const {
    if (this->dir < 1 || this->dir > 4) return false;
    return this->p.x() >= 1
           && this->p.x() <= 9
           && this->p.y() >= 1
           && this->p.y() <= 9;
}