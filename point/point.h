#ifndef LOQ2_POINT_H
#define LOQ2_POINT_H

class Point {
    byte t{};

public:
    Point() = default;

    Point(Point const &p) { t = p.t; }

    Point(int x, int y) { t = (x << 4) | y; }

    Point operator+(const Point &p) const { return {x() + p.x(), y() + p.y()}; }

    bool operator!() const { return !t; }

    bool operator==(const Point &p) const { return t == p.t; }

    [[nodiscard]] byte x() const;

    [[nodiscard]] byte y() const;

    void set(int x, int y) { t = (x << 4) | y; }

    void setX(int x) { t = (x << 4) | y(); }

    void setY(int y) { t = (x() << 4) | y; }

    [[nodiscard]] byte distance(const Point &p) const;

    [[nodiscard]] Point up() const { return {x(), y() + 1}; }

    [[nodiscard]] Point down() const { return {x(), y() - 1}; }

    [[nodiscard]] Point left() const { return {x() - 1, y()}; }

    [[nodiscard]] Point right() const { return {x() + 1, y()}; }
};

#endif //LOQ2_POINT_H


Point lb(const Point &p, const Point &q) { return {MIN(p.x(), q.x()), MIN(p.y(), q.y())}; }

Point rt(const Point &p, const Point &q) { return {MAX(p.x(), q.x()), MAX(p.y(), q.y())}; }

Point md(const Point &p, const Point &q) { return {(p.x() + q.x()) / 2, (p.y() + q.y()) / 2}; }