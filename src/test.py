from loq2 import Point, IBlock, State

a = Point(1, 2)
print(a)
a.x = 3
a.y = 4
print(a)

b = IBlock(6, 2, 3)
print(b.position, b.direction)

s = State()
t = s.act(0, 5, 8)
u = s.act(0, 5, 2)
print(s)
print(not t)
print(not u, u.position(False))
