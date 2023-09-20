from agent.ka.main import Init as kaInit, next as kaNext
from agent.po.main import Init as poInit, next as poNext
from loq2 import Game, State
import time

l = []


def Run(k, p, f, log=False):
    a, b = k, p
    s = Game(State().next())
    f.write('[')

    while True:
        if log:
            print(s)
        lt = time.time()
        act, nxt = a[1](s.st.mask, a[2])
        f.write(str(act) + ',')
        print(act)
        elap = time.time() - lt
        print(elap)
        a[2] = nxt
        l.append([*act, elap])
        s.act(*act)
        a, b = b, a
        if s.fin:
            l.append([0, *s.fin])
            f.write(str(s.fin[0]) + ']')
            return s.fin[0]

        if not s:
            l.append([0, *s.fin])
            f.write(str(s.fin[0]) + ']')
            return s.fin[0]


with open('log/' + str(time.time()) + '.txt', 'w') as f:
    print(Run([1, kaNext, kaInit()], [2, poNext, poInit()], f, True))
