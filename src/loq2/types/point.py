import ctypes as T
from ..lib import lib


class PointStruct(T.Structure):
    _fields_ = [("t", T.c_ubyte)]


PointPointer = T.POINTER(PointStruct)

lib.Point_ByValue.argtypes = [T.c_int, T.c_int]
lib.Point_ByValue.restype = PointPointer
lib.Point_Copy.argtypes = [PointPointer]
lib.Point_Copy.restype = PointPointer
lib.Point_Delete.argtypes = [PointPointer]

lib.Point_X.argtypes = [PointPointer]
lib.Point_X.restype = T.c_ubyte
lib.Point_Y.argtypes = [PointPointer]
lib.Point_Y.restype = T.c_ubyte

lib.Point_Set.argtypes = [PointPointer, T.c_ubyte, T.c_ubyte]
lib.Point_SetX.argtypes = [PointPointer, T.c_ubyte]
lib.Point_SetY.argtypes = [PointPointer, T.c_ubyte]


class Point(object):
    def __init__(self, x, y=None):
        if type(x) is int:
            self.ref = lib.Point_ByValue(x, y)
        elif type(x) is PointPointer or type(x) is PointStruct:
            self.ref = x
            self.r = True

    def __eq__(self, other):
        if type(other) == Point: other = other.tuple
        return self.tuple == other

    def __del__(self):
        if 'r' in self.__dict__: return
        lib.Point_Delete(self.ref)

    def __copy__(self):
        return Point(lib.Point_Copy(self.ref))

    def __bool__(self):
        return bool(self.x or self.y)

    @property
    def x(self):
        return lib.Point_X(self.ref)

    @property
    def y(self):
        return lib.Point_Y(self.ref)

    @x.setter
    def x(self, value):
        lib.Point_SetX(self.ref, value)

    @y.setter
    def y(self, value):
        lib.Point_SetY(self.ref, value)

    def __repr__(self):
        return f'Point({self.x}, {self.y})'

    def __str__(self):
        return f'({self.x}, {self.y})'

    def set(self, x, y):
        lib.Point_Set(self.ref, x, y)

    @property
    def tuple(self):
        return (self.x, self.y)
