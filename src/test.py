from loq2 import Point, IBlock, State, ACTION

a = Point(1, 2)
assert a == (1, 2)
a.x = 3
a.y = 4
assert a == (3, 4)

b = IBlock(6, 2, 3)
assert b.position == (6, 2)
assert b.direction == 3

s = State()
u = s.act(1, 5, 2)
v = u.act(2, 2, 2, 1)

assert not s.act(1, 5, 8)
assert u
assert v
assert u.position(False) == (5, 2)
assert not v.act(2, 2, 3, 1)
assert v.map.h[1][1]
assert not v.map.h[1][2]
assert v.map.np[0][1][1]
assert v.block_ip[0].position == (2, 2)

a = State()
a = a.act(ACTION.MOVE, 5, 2)
a = a.act(ACTION.PLACE_I, 1, 8, 2)
a = a.act(ACTION.PLACE_I, 5, 8, 2)
a = a.act(ACTION.PLACE_I, 8, 9, 2)
a = a.act(ACTION.PLACE_I, 3, 8, 2)
a = a.act(ACTION.PLACE_I, 7, 8, 2)
assert a
assert not a.act(ACTION.PLACE_I, 8, 8, 1)

a = State()
a = a.act(ACTION.PLACE_I, 8, 7, 2)
a = a.act(ACTION.PLACE_I, 9, 5, 1)
assert not a.act(ACTION.PLACE_I, 7, 7, 2)

a = State()
a.act(ACTION.PLACE_I, 8, 7, 2)
a.act(ACTION.PLACE_I, 8, 5, 1)
assert a.act(ACTION.PLACE_I, 8, 6, 2)

a = State()
a = a.act(ACTION.MOVE, 5, 2)
a = a.act(ACTION.MOVE, 5, 8)
a = a.act(ACTION.MOVE, 5, 3)
a = a.act(ACTION.MOVE, 5, 7)
a = a.act(ACTION.MOVE, 5, 4)
m = a.mask
assert m
assert not m.position(False)
a = a.act(ACTION.MOVE, 5, 6)
a = a.act(ACTION.PLACE_I, 2, 6, 2)
a = a.act(ACTION.PLACE_I, 4, 6, 2)
a = a.act(ACTION.PLACE_I, 6, 6, 2)
a = a.act(ACTION.PLACE_I, 8, 6, 2)
a = a.act(ACTION.PLACE_L, 1, 6, 1)
assert not a

a = State()
a = a.act(ACTION.MOVE, 4, 1)
a = a.act(ACTION.MOVE, 4, 9)
a = a.act(ACTION.MOVE, 3, 1)
a = a.act(ACTION.MOVE, 3, 9)
a = a.act(ACTION.MOVE, 2, 1)
a = a.act(ACTION.MOVE, 2, 9)
a = a.act(ACTION.MOVE, 1, 1)
a = a.act(ACTION.MOVE, 2, 8)
a = a.act(ACTION.MOVE, 1, 2)
a = a.act(ACTION.MOVE, 2, 7)
a = a.act(ACTION.MOVE, 1, 3)
a = a.act(ACTION.MOVE, 2, 6)
a = a.act(ACTION.MOVE, 1, 4)
a = a.act(ACTION.MOVE, 2, 5)
a = a.act(ACTION.MOVE, 1, 5)
a = a.act(ACTION.MOVE, 1, 4)
assert a

print('Test Success!')
