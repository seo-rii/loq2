import ctypes as T
from ..lib import lib
from .map import MapStruct, MapPointer
from .point import Point, PointStruct, PointPointer
from .block import BlockStruct, IBlock, LBlock
from ..str import state_str


class StateStruct(T.Structure):
    _fields_ = [
        ("k", PointStruct), ("p", PointStruct),
        ("block_lk", BlockStruct * 3), ("block_lp", BlockStruct * 3),
        ("block_ik", BlockStruct * 7), ("block_ip", BlockStruct * 7),
        ("map", MapStruct), ("turn", T.c_bool),
    ]


StatePointer = T.POINTER(StateStruct)

lib.State_New.argtypes = []
lib.State_New.restype = StatePointer
lib.State_Win.argtypes = []
lib.State_Win.restype = T.c_ubyte
lib.State_Delete.argtypes = [StatePointer]

lib.State_Mask.argtypes = []
lib.State_Mask.restype = StatePointer
lib.State_Copy.argtypes = []
lib.State_Copy.restype = StatePointer
lib.State_Next.argtypes = []
lib.State_Next.restype = StatePointer

lib.State_Act.argtypes = [StatePointer, T.c_ubyte, T.c_ubyte, T.c_ubyte, T.c_ubyte]
lib.State_Act.restype = StatePointer
lib.State_GetMap.argtypes = [StatePointer]
lib.State_GetMap.restype = MapPointer

lib.State_Position.argtypes = [StatePointer, T.c_bool]
lib.State_Position.restype = PointPointer


class State(object):
    def __init__(self, st=None):
        if st is not None:
            self.obj = st
        else:
            self.obj = lib.State_New()

    def __del__(self):
        lib.State_Delete(self.obj)

    def __bool__(self):
        return self.obj.contents.k.t != 0 or self.obj.contents.p.t != 0

    def act(self, action, x, y, w=0) -> 'State':
        return State(lib.State_Act(self.obj, action, x, y, w))

    @property
    def map(self):
        return lib.State_GetMap(self.obj).contents

    def __repr__(self):
        return f'State({self.obj})'

    def __str__(self):
        return f'State({self.obj})'

    def position(self, is_player=True):
        return Point(lib.State_Position(self.obj, is_player))

    @property
    def turn(self):
        return self.obj.contents.turn

    @property
    def win(self):
        return lib.State_Win(self.obj)

    def __str__(self):
        return state_str(self)

    @property
    def block_ik(self):
        return [IBlock(i) for i in self.obj.contents.block_ik]

    @property
    def block_ip(self):
        return [IBlock(i) for i in self.obj.contents.block_ip]

    @property
    def block_lk(self):
        return [LBlock(i) for i in self.obj.contents.block_lk]

    @property
    def block_lp(self):
        return [LBlock(i) for i in self.obj.contents.block_lp]

    @property
    def mask(self):
        return State(lib.State_Mask(self.obj))

    def copy(self):
        return State(lib.State_Copy(self.obj))