#ifndef LOQ2_BLOCK_H
#define LOQ2_BLOCK_H

#include "../library.h"

class IBlock {
public:
    Point p;
    byte dir{};

    IBlock() = default;

    IBlock(IBlock const &b) { p = b.p, dir = b.dir; }

    IBlock(Point p, byte dir) { this->p = p, this->dir = dir; }

    IBlock(byte x, byte y, byte dir) { p = Point(x, y), this->dir = dir; }

    IBlock *copy() { return new IBlock(*this); }

    [[nodiscard]] State apply(State const &s) const;

    bool valid() const;

    bool operator!() const { return !p && dir == 0; }
};

class LBlock {
public:
    Point p;
    byte dir{};

    LBlock() = default;

    LBlock(LBlock const &b) { p = b.p, dir = b.dir; }

    LBlock(Point p, byte dir) { this->p = p, this->dir = dir; }

    LBlock(byte x, byte y, byte dir) { p = Point(x, y), this->dir = dir; }

    LBlock *copy() { return new LBlock(*this); }

    [[nodiscard]] State apply(State const &s) const;

    bool valid() const;

    bool operator!() const { return !p && dir == 0; }
};

#endif //LOQ2_BLOCK_H
