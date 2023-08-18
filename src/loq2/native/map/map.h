#pragma once

#include "../type.h"

class Map {
    bool h[9][10], v[10][9];
public:
    Map() = default;

    Map(Map const &m) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 10; ++j) {
                h[i][j] = m.h[i][j];
                v[j][i] = m.v[j][i];
            }
        }
    }

    Map &operator=(Map const &m) {
        if (this == &m) return *this;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 10; ++j) {
                h[i][j] = m.h[i][j];
                v[j][i] = m.v[j][i];
            }
        }
        return *this;
    }

    [[nodiscard]] bool h_block(const Point &pos) const;

    [[nodiscard]] bool v_block(const Point &pos) const;

    bool set_h_block(const Point &pos, bool set = true);

    bool set_v_block(const Point &pos, bool set = true);
};

#include "../library.h"