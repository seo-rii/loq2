#include "../library.h"

State LBlock::apply(const State &s, bool set) const {
    State ns = s;
    if (this->dir == 1) {
        if (!ns.map.set_h_block(this->p, set)) return NULL_STATE;
        if (!ns.map.set_v_block(this->p, set)) return NULL_STATE;
    } else if (this->dir == 2) {
        if (!ns.map.set_h_block(this->p, set)) return NULL_STATE;
        if (!ns.map.set_v_block(this->p.up(), set)) return NULL_STATE;
    } else if (this->dir == 3) {
        if (!ns.map.set_h_block(this->p.right(), set)) return NULL_STATE;
        if (!ns.map.set_v_block(this->p.up(), set)) return NULL_STATE;
    } else {
        if (!ns.map.set_h_block(this->p.right(), set)) return NULL_STATE;
        if (!ns.map.set_v_block(this->p, set)) return NULL_STATE;
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

bool LBlock::internal() const {
    if (this->p.x() < 4 || this->p.x() > 6 || this->p.y() < 4 || this->p.y() > 6) return false;
    if (this->dir == 1 && this->p.x() == 4 && this->p.y() == 4) return false;
    if (this->dir == 2 && this->p.x() == 4 && this->p.y() == 6) return false;
    if (this->dir == 3 && this->p.x() == 6 && this->p.y() == 6) return false;
    if (this->dir == 4 && this->p.x() == 6 && this->p.y() == 4) return false;
    return true;
}