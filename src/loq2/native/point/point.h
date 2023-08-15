#pragma once

#include "../type.h"

class Point {
    byte t{};

public:
    Point() = default;

    Point(Point const &p) { t = p.t; }

    Point(int x, int y) { t = (x << 4) | y; }

    Point operator+(const Point &p) const { return {x() + p.x(), y() + p.y()}; }

    bool operator!() const { return !t; }

    bool operator==(const Point &p) const { return t == p.t; }

    void operator=(const Point &p) { t = p.t; }

    [[nodiscard]] byte x() const;

    [[nodiscard]] byte y() const;

    void set(int x, int y);

    void setX(int x);

    void setY(int y);

    [[nodiscard]] byte distance(const Point &p) const;

    [[nodiscard]] Point up() const { return {x(), y() + 1}; }

    [[nodiscard]] Point down() const { return {x(), y() - 1}; }

    [[nodiscard]] Point left() const { return {x() - 1, y()}; }

    [[nodiscard]] Point right() const { return {x() + 1, y()}; }
};

extern "C" Point lbP(const Point &p, const Point &q);

extern "C" Point rtP(const Point &p, const Point &q);

#include "../library.h"