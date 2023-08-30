#include "../library.h"

extern "C" {

API State *State_New() { return new State(INIT_STATE); }

API State *State_Copy(State *s) { return new State(*s); }

API State *State_Next(State *s) { return new State(s->next()); }

API void State_Delete(State *s) { delete s; }

API State *State_Act(State *s, byte type, byte p1, byte p2, byte p3 = 0) {
  return new State(s->act(type, p1, p2, p3));
}

API State *State_Mask(State *s) { return new State(s->mask()); }

API Map *State_GetMap(State *s) { return new Map(s->getMap()); }

API Point *State_Position(State *s, bool my) { return new Point(s->position(my)); }

API IBlock *State_KI(State *s) { return s->getKIBlock(); }

API IBlock *State_PI(State *s) { return s->getPIBlock(); }

API LBlock *State_KL(State *s) { return s->getKLBlock(); }

API LBlock *State_PL(State *s) { return s->getPLBlock(); }

API byte State_Win(State *s) { return s->win(); }

}