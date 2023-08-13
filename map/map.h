#ifndef LOQ2_MAP_H
#define LOQ2_MAP_H

#include "../library.h"

class Map {
    bool h[90], v[90];
public:
    Map() = default;

    Map(Map const &m) {
        for (int i = 0; i < 90; ++i) {
            h[i] = m.h[i];
            v[i] = m.v[i];
        }
    }

    Map &operator=(Map const &m) {
        for (int i = 0; i < 90; ++i) {
            h[i] = m.h[i];
            v[i] = m.v[i];
        }
        return *this;
    }

    [[nodiscard]] bool h_block(const Point &pos) const;

    [[nodiscard]] bool v_block(const Point &pos) const;

    bool set_h_block(const Point &pos);

    bool set_v_block(const Point &pos);
};

#endif //LOQ2_MAP_H
