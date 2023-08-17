from loq2 import Point, IBlock, State
import ctypes as T

a = Point(1, 2)
print(a)
a.x = 3
a.y = 4
print(a)

b = IBlock(6, 2, 3)
print(b.position, b.direction)

s = State()
u = s.act(1, 5, 2)
v = u.act(2, 2, 2, 1)
print(s)  # State
print(not s.act(1, 5, 8))  # True
print(not u, u.position(False))  # False, (5, 2)
print(not v.act(2, 1, 2, 1))  # True
print(not v, v.map.h[1][1], v.map.np[0][1][1])  # False, True, True
print(v.block_ip)
print(v)
print(v.map.np[1].shape)
