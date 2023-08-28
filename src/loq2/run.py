from .game import Game


def Run(k, p, log=False):
    a, b = k, p
    s = Game()

    while True:
        if log:
            print(s)
        s.act(*a.next(s.st))
        a, b = b, a

        if s.fin:
            if log:
                print(s)
            return s.fin[0]

        if not s:
            if log:
                print(s)
            return s.fin[0]