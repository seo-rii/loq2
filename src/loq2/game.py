from .types.state import State


class EndGameReason:
    INVALID_ACTION = 0
    WIN = 1


class Game:
    def __init__(self, state=None, acts=None):
        if acts is None:
            acts = []
        self.st = State(state)
        self.acts = acts
        self.fin = False

    def __bool__(self):
        return self.st.__bool__()

    def copy(self):
        return Game(self.st.copy(), self.acts.copy())

    def player(self, op=None):
        return self.st.turn(op)

    def act(self, action, *args):
        if self.fin:
            return False
        ret = self.st.act(action, *args)
        if not ret:
            self.fin = (1 - self.st.turn(), EndGameReason.INVALID_ACTION)
            return None
        self.st = ret
        self.acts.append((action, args))
        win = self.st.win()
        if win is not None:
            self.fin = (win, EndGameReason.WIN)
            return True
        return True

    def __str__(self):
        return self.st.__str__()
