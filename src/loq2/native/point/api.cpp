#include "../library.h"

extern "C" {

API Point *Point_ByValue(int x, int y) {
    return new Point(x, y);
}

API Point *Point_Copy(Point *p) {
    return new Point(*p);
}

API void Point_Delete(Point *p) {
    delete p;
}

API byte Point_X(Point *p) {
    return p->x();
}

API byte Point_Y(Point *p) {
    return p->y();
}

API void Point_Set(Point *p, int x, int y) {
    p->set(x, y);
}

API void Point_SetX(Point *p, int x) {
    p->setX(x);
}

API void Point_SetY(Point *p, int y) {
    p->setY(y);
}

API byte Point_Distance(Point *p, Point *q) {
    return p->distance(*q);
}

API Point *Point_Up(Point *p) {
    return new Point(p->up());
}

API Point *Point_Down(Point *p) {
    return new Point(p->down());
}

API Point *Point_Left(Point *p) {
    return new Point(p->left());
}

API Point *Point_Right(Point *p) {
    return new Point(p->right());
}

}