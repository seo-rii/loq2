#include "../library.h"

[[nodiscard]] byte Point::x() const { return t >> 4; }

[[nodiscard]] byte Point::y() const { return t & 0xf; }

byte Point::distance(const Point &r) const {
    return ABS(x() - r.x()) + ABS(y() - r.y());
}

Point lb(const Point &p, const Point &q) { return {MIN(p.x(), q.x()), MIN(p.y(), q.y())}; }

Point rt(const Point &p, const Point &q) { return {MAX(p.x(), q.x()), MAX(p.y(), q.y())}; }