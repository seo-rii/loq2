import ctypes as T
from ..lib import lib
from .point import PointStruct, Point


class BlockStruct(T.Structure):
    _fields_ = [("p", PointStruct), ("dir", T.c_byte)]


BlockPointer = T.POINTER(BlockStruct)

lib.IBlock_ByValue.argtypes = [T.c_int, T.c_int, T.c_int]
lib.IBlock_ByValue.restype = BlockPointer
lib.LBlock_ByValue.argtypes = [T.c_int, T.c_int, T.c_int]
lib.LBlock_ByValue.restype = BlockPointer
lib.IBlock_Delete.argtypes = [BlockPointer]
lib.LBlock_Delete.argtypes = [BlockPointer]


class IBlock:
    def __init__(self, x, y, dir):
        self.obj = lib.IBlock_ByValue(x, y, dir)

    def __del__(self):
        lib.IBlock_Delete(self.obj)

    @property
    def position(self):
        return Point(self.obj.contents.p)

    @property
    def direction(self):
        return self.obj.contents.dir


class LBlock:
    def __init__(self, x, y, dir):
        self.obj = lib.LBlock_ByValue(x, y, dir)

    def __del__(self):
        lib.LBlock_Delete(self.obj)

    @property
    def position(self):
        return Point(self.obj.contents.p)

    @property
    def direction(self):
        return self.obj.contents.dir
