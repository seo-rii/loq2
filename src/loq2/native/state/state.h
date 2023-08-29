#pragma once

#include "../type.h"

class State {
    friend class IBlock;

    friend class LBlock;

    Point k, p;
    LBlock block_lk[L_COUNT], block_lp[L_COUNT];
    IBlock block_ik[I_COUNT], block_ip[I_COUNT];
    Map map{};
    bool turn{};

public:

    State() = default;

    State(const State &state) = default;

    State(const Point &k, const Point &p, byte turn = false) : k(k), p(p), turn(turn) {}

    bool operator!() const { return !k && !p; }

    // State

    [[nodiscard]] State act(byte type, byte p1, byte p2, byte p3 = 0) const;

    State *copy() { return new State(*this); }

    [[nodiscard]] State move(const Point &to) const;

    [[nodiscard]] State placeI(const IBlock &iBlock) const;

    [[nodiscard]] State placeL(const LBlock &lBlock) const;

    [[nodiscard]] State mask() const;

    [[nodiscard]] State next() const;

    [[nodiscard]] Map getMap() const;

    // Utils

    bool getTurn() const;

    bool movable(const Point &to, const Point &from, const Point &op) const;

    bool bfs(const Point &from, int endY) const;

    [[nodiscard]] Point position(bool my = true) const;

    bool endable() const;

    bool v_block(const Point &lf) const;

    bool h_block(const Point &bt) const;

    [[nodiscard]] bool internal(bool my = true) const;

    bool cross(const IBlock &iBlock) const;

    bool cross(const LBlock &iBlock) const;

    byte win() const;

    IBlock *getKIBlock();

    IBlock *getPIBlock();

    LBlock *getKLBlock();

    LBlock *getPLBlock();
};

extern const State INIT_STATE, NULL_STATE;

#include "../library.h"