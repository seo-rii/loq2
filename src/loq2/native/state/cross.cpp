#include "../library.h"

bool State::cross(const IBlock &iBlock) const {
    Point pos = iBlock.p;
    byte x = iBlock.p.x(), y = iBlock.p.y();
    if (iBlock.dir == 1) {
        for (auto &b: this->block_ik)
            if (b.dir == 2 && b.p.x() == x - 1 && b.p.y() == y + 1) return true;
        for (auto &b: this->block_ip)
            if (b.dir == 2 && b.p.x() == x - 1 && b.p.y() == y + 1) return true;
    } else {
        for (auto &b: this->block_ik)
            if (b.dir == 1 && b.p.x() == x + 1 && b.p.y() == y - 1) return true;
        for (auto &b: this->block_ip)
            if (b.dir == 1 && b.p.x() == x + 1 && b.p.y() == y - 1) return true;
    }
    return false;
}

bool State::cross(const LBlock &lBlock) const {
    byte x = lBlock.p.x(), y = lBlock.p.y(), ah = 0, av = 0;
    if (lBlock.dir == 3 || lBlock.dir == 4) ah = 1;
    if (lBlock.dir == 3 || lBlock.dir == 2) av = 1;
    for (auto &b: this->block_lk) {
        if (!b) continue;
        auto s = b.dir - lBlock.dir;
        if (s != 2 && s != -2) continue;
        byte bx = b.p.x(), by = b.p.y(), bh = 0, bv = 0;
        if (b.dir == 3 || b.dir == 4) bh = 1;
        if (b.dir == 3 || b.dir == 2) bv = 1;
        if (bx + bh == x + ah && by + bv == y + av) return true;
    }
    for (auto &b: this->block_lp) {
        if (!b) continue;
        auto s = b.dir - lBlock.dir;
        if (s != 2 && s != -2) continue;
        byte bx = b.p.x(), by = b.p.y(), bh = 0, bv = 0;
        if (b.dir == 3 || b.dir == 4) bh = 1;
        if (b.dir == 3 || b.dir == 2) bv = 1;
        if (bx + bh == x + ah && by + bv == y + av) return true;
    }
    return false;
}
