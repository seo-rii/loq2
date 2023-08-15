import ctypes as T
from ..lib import lib


class MapStruct(T.Structure):
    _fields_ = [("h", T.c_bool * 90), ("v", T.c_bool * 90)]


MapPointer = T.POINTER(MapStruct)


class Map:
    pass
