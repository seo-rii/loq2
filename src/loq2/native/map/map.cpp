#include "../library.h"

inline bool Map::h_block(const Point &p) const {
    return h[p.x() * 10 + p.y()];
}

inline bool Map::v_block(const Point &p) const {
    return v[p.x() * 9 + p.y()];
}

inline bool Map::set_h_block(const Point &p) {
    if (h_block(p)) return false;
    h[p.x() * 10 + p.y()] = true;
    return true;
}

inline bool Map::set_v_block(const Point &p) {
    if (v_block(p)) return false;
    v[p.x() * 9 + p.y()] = true;
    return true;
}