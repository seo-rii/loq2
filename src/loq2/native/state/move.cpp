#include "../library.h"

bool State::movable(const Point &to, const Point &from, const Point &op) const {
  if (!internal(false) && to == op)
    return false;
  if (to.x() <= 0 || to.x() > BOARD_SIZE || to.y() <= 0 || to.y() > BOARD_SIZE)
    return false;
  byte dis = from.distance(to);
  if (dis == 1) {
    if (from.x() == to.x()) {
      if (v_block(rtP(from, to)))
        return false;
    } else {
      if (h_block(rtP(from, to)))
        return false;
    }
  } else if (dis == 2) {
    if (from.distance(op) != 1 || op.distance(to) != 1)
      return false;
    if (from.x() == to.x()) {
      if (v_block(op) || v_block(rtP(from, to)))
        return false;
    } else if (from.y() == to.y()) {
      if (h_block(op) || h_block(rtP(from, to)))
        return false;
    } else {
      if (from.x() == op.x() && op.y() == to.y()) {
        if (v_block(rtP(from, op)))
          return false;
        if (h_block(rtP(to, op)))
          return false;
        if (!v_block({from.x(), op.y() * 2 - from.y() + (op.y() < from.y() ? 1 : 0)}) &&
            !(op.y() > from.y() && op.y() == BOARD_SIZE) &&
            !(op.y() < from.y() && op.y() == 1))
          return false;
      } else if (from.y() == op.y() && op.x() == to.x()) {
        if (h_block(rtP(from, op)))
          return false;
        if (v_block(rtP(to, op)))
          return false;
        if (!h_block({op.x() * 2 - from.x() + (op.x() < from.x() ? 1 : 0), from.y()}) &&
            !(op.x() > from.x() && op.x() == BOARD_SIZE) &&
            !(op.x() < from.x() && op.x() == 1))
          return false;
      } else
        return false;
    }
  } else
    return false;
  return true;
}

State State::move(const Point &to) const {
  if (!movable(to, position(), position(false)))
    return NULL_STATE;
  auto ns = State(*this);
  if (!ns.turn)
    ns.k = to;
  else
    ns.p = to;
  return ns.next();
}