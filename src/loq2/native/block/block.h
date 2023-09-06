#pragma once

#include "../type.h"

class IBlock {
public:
    Point p;
    byte dir{};

    IBlock() = default;

    IBlock(IBlock const &b) { p = b.p, dir = b.dir; }

    IBlock(Point p, byte dir) { this->p = p, this->dir = dir; }

    IBlock(byte x, byte y, byte dir) { p = Point(x, y), this->dir = dir; }

    IBlock *copy() { return new IBlock(*this); }

    bool internal(bool strict = true) const;

    void operator=(IBlock const &b) { p = b.p, dir = b.dir; }

    [[nodiscard]] State apply(State const &s, bool set = true) const;

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

    bool internal(bool strict = true) const;

    [[nodiscard]] State apply(State const &s, bool set = true) const;

    bool valid() const;

    bool operator!() const { return !p && dir == 0; }
};

#include "../library.h"