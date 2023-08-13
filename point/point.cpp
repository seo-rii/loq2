#include "../library.h"

[[nodiscard]] byte Point::x() const { return t >> 4; }

[[nodiscard]] byte Point::y() const { return t & 0xf; }

byte Point::distance(const Point &r) const {
    return ABS(x() - r.x()) + ABS(y() - r.y());
}