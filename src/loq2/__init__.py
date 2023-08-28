from .types.point import Point
from .types.map import Map
from .types.block import IBlock, LBlock
from .types.state import State
from .game import Game
from .run import Run

ACTION_MOVE = 1
ACTION_PLACE_I = 2
ACTION_PLACE_L = 3


class ACTION:
    MOVE = ACTION_MOVE
    PLACE_I = ACTION_PLACE_I
    PLACE_L = ACTION_PLACE_L


BOARD_SIZE = 9
I_COUNT = 7
L_COUNT = 3
