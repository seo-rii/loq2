#include "../library.h"

Point State::position(bool my) const {
    return ((!my && this->turn) || (my && !this->turn)) ? this->k : this->p;
}

bool State::internal(bool my) const {
    Point pos = this->position(my);
    return pos.x() >= 4
           && pos.x() <= 6
           && pos.y() >= 4
           && pos.y() <= 6;
}

State State::act(byte type, byte p1, byte p2, byte p3) const {
    if (type == 1) return move({p1, p2});
    if (type == 2) return placeI({{p1, p2}, p3});
    if (type == 3) return placeL({{p1, p2}, p3});
    return NULL_STATE;
}


bool State::v_block(const Point &pos) const {
    return this->map.v_block(pos);
}

bool State::h_block(const Point &pos) const {
    return this->map.h_block(pos);
}

Map State::getMap() const {
    return this->map;
}

IBlock *State::getKIBlock() {
    return block_ik;
}

IBlock *State::getPIBlock() {
    return block_ip;
}

LBlock *State::getKLBlock() {
    return block_lk;
}

LBlock *State::getPLBlock() {
    return block_lp;
}

const State INIT_STATE{{5, 1},
                       {5, 9}};

const State NULL_STATE{{0, 0},
                       {0, 0}};