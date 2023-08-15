import ctypes as T
import numpy as np
from ..lib import lib


class MapStruct(T.Structure):
    _fields_ = [("h", (T.c_bool * 10) * 9), ("v", (T.c_bool * 9) * 10)]

    @property
    def list(self):
        return (
            [[self.h[y][x] for x in range(10)] for y in range(9)],
            [[self.v[y][x] for x in range(9)] for y in range(10)]
        )

    @property
    def np(self):
        li = self.list
        return (
            np.array(li[0], dtype=bool),
            np.array(li[1], dtype=bool)
        )


MapPointer = T.POINTER(MapStruct)


class Map:
    pass
