import ctypes as T
from ..lib import lib
from .map import MapStruct
from .point import Point, PointStruct, PointPointer
from .block import BlockStruct


class StateStruct(T.Structure):
    _fields_ = [
        ("k", PointStruct), ("p", PointStruct),
        ("block_lk", BlockStruct * 3), ("block_lp", BlockStruct * 3),
        ("block_ik", BlockStruct * 7), ("block_ip", BlockStruct * 7),
        ("map", MapStruct), ("turn", T.c_byte),
    ]


StatePointer = T.POINTER(StateStruct)

lib.State_New.argtypes = []
lib.State_New.restype = StatePointer
lib.State_Delete.argtypes = [StatePointer]

lib.State_Act.argtypes = [StatePointer, T.c_byte, T.c_byte, T.c_byte]
lib.State_Act.restype = StatePointer
lib.State_GetMap.argtypes = [StatePointer]
lib.State_GetMap.restype = MapStruct

lib.State_Position.argtypes = [StatePointer, T.c_bool]
lib.State_Position.restype = PointPointer


class State:
    def __init__(self, st=None):
        if st is not None:
            self.obj = st
        else:
            self.obj = lib.State_New()

    def __del__(self):
        lib.State_Delete(self.obj)

    def __bool__(self):
        return self.obj.contents.k.t != 0

    def act(self, action, x, y):
        return State(lib.State_Act(self.obj, action, x, y))

    @property
    def map(self):
        return lib.State_GetMap(self.obj)

    def __repr__(self):
        return f'State({self.obj})'

    def __str__(self):
        return f'State({self.obj})'

    def position(self, is_player=True):
        return Point(lib.State_Position(self.obj, is_player))

    @property
    def turn(self):
        return self.obj.contents.turn
