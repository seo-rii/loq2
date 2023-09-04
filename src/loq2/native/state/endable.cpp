#include "../library.h"

bool State::bfs(const Point &from, int endY) const {
    if(!from.x() && !from.y()) return true;
    bool vis[BOARD_SIZE][BOARD_SIZE] = {};
    Point qu[BOARD_SIZE * BOARD_SIZE] = {};
    int l = 0, r = 0;
    byte x, y;
    Point p;
    qu[r++] = from;
    vis[from.x() - 1][from.y() - 1] = true;
    while (l < r) {
        auto t = qu[l++];
        if (t.y() == endY)
            return true;

        p = t.up();
        x = p.x();
        y = p.y();
        if (x != 0 && x != BOARD_SIZE + 1 && y != 0 && y != BOARD_SIZE + 1 && !vis[x - 1][y - 1] && movable(p, t, {})) {
            qu[r++] = p;
            vis[x - 1][y - 1] = true;
        }

        p = t.down();
        x = p.x();
        y = p.y();
        if (x != 0 && x != BOARD_SIZE + 1 && y != 0 && y != BOARD_SIZE + 1 && !vis[x - 1][y - 1] && movable(p, t, {})) {
            qu[r++] = p;
            vis[x - 1][y - 1] = true;
        }

        p = t.left();
        x = p.x();
        y = p.y();
        if (x != 0 && x != BOARD_SIZE + 1 && y != 0 && y != BOARD_SIZE + 1 && !vis[x - 1][y - 1] && movable(p, t, {})) {
            qu[r++] = p;
            vis[x - 1][y - 1] = true;
        }

        p = t.right();
        x = p.x();
        y = p.y();
        if (x != 0 && x != BOARD_SIZE + 1 && y != 0 && y != BOARD_SIZE + 1 && !vis[x - 1][y - 1] && movable(p, t, {})) {
            qu[r++] = p;
            vis[x - 1][y - 1] = true;
        }
    }
    return false;
}

bool State::endable() const {
    return bfs(position(), turn ? 1 : BOARD_SIZE) &&
           bfs(position(false), turn ? BOARD_SIZE : 1);
}