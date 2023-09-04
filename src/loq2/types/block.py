import ctypes as T
from ..lib import lib
from .point import PointStruct, Point


class BlockStruct(T.Structure):
    _fields_ = [("p", PointStruct), ("dir", T.c_ubyte)]


BlockPointer = T.POINTER(BlockStruct)

lib.IBlock_ByValue.argtypes = [T.c_int, T.c_int, T.c_int]
lib.IBlock_ByValue.restype = BlockPointer
lib.LBlock_ByValue.argtypes = [T.c_int, T.c_int, T.c_int]
lib.LBlock_ByValue.restype = BlockPointer
lib.IBlock_Delete.argtypes = [BlockPointer]
lib.LBlock_Delete.argtypes = [BlockPointer]


class IBlock(object):
    def __init__(self, x, y=None, dir=None):
        if type(x) is BlockStruct:
            self.obj = x
            self.r = True
        elif type(x) is BlockPointer:
            self.obj = x.contents
            self.r = True
        elif y is None:
            self.obj = BlockPointer.from_address(x).contents
            self.r = True
        else:
            self.obj = lib.IBlock_ByValue(x, y, dir).contents

    def __del__(self):
        return
        if 'r' in self.__dict__: return
        lib.IBlock_Delete(self.obj)

    def __repr__(self):
        return f'IBlock({self.position}, {self.direction})'

    def __str__(self):
        return f'IBlock({self.position}, {self.direction})'

    @property
    def position(self):
        return Point(self.obj.p)

    @property
    def direction(self):
        return self.obj.dir


class LBlock(object):
    def __init__(self, x, y=None, dir=None):
        if type(x) is BlockStruct:
            self.obj = x
            self.r = True
        else:
            self.obj = lib.LBlock_ByValue(x, y, dir)

    def __del__(self):
        if 'r' in self.__dict__: return
        lib.LBlock_Delete(T.addressof(self.obj))

    def __repr__(self):
        return f'LBlock({self.position}, {self.direction})'

    def __str__(self):
        return f'LBlock({self.position}, {self.direction})'

    @property
    def position(self):
        return Point(self.obj.p)

    @property
    def direction(self):
        return self.obj.dir
