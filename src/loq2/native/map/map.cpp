#include "../library.h"

bool Map::h_block(const Point &p) const {
    if (p.x() == 0 || p.y() == 0) return false;
    return h[p.y() - 1][p.x() - 1];
}

bool Map::v_block(const Point &p) const {
    if (p.x() == 0 || p.y() == 0) return false;
    return v[p.y() - 1][p.x() - 1];
}

bool Map::set_h_block(const Point &p, bool set) {
    if (p.x() == 0 || p.y() == 0) return false;
    if (set && h_block(p)) return false;
    h[p.y() - 1][p.x() - 1] = set;
    return true;
}

bool Map::set_v_block(const Point &p, bool set) {
    if (p.x() == 0 || p.y() == 0) return false;
    if (set && v_block(p)) return false;
    v[p.y() - 1][p.x() - 1] = set;
    return true;
}