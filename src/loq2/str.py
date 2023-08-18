class colors:
    YELLOW = '\033[33m'
    BLUE = '\033[34m'
    RED = '\033[31m'
    CYAN = '\033[96m'
    GREEN = '\033[92m'
    ENDC = '\033[0m'
    PURPLE = '\033[35m'
    GRAY = '\033[90m'


def bold_sym(s: str):
    return "╋" if s == "┼" else "┃" if s == "│" else "━━━" if s == "───" else s


def state_str(self):
    if not self.turn:
        p = self.position()
        o = self.position(False)
    else:
        o = self.position()
        p = self.position(False)
    px = p.x
    py = p.y
    ox = o.x
    oy = o.y
    if px == 0 and py == 0 and ox == 0 and oy == 0:
        return "Invalid State"

    res = ''
    board = [[("┼" if y % 2 else "│") if x % 2 else ("───" if y % 2 else "   ") for x in range(17)] for y in range(17)]

    if px == ox and py == oy and px:
        board[2 * (py - 1)][2 * (px - 1)] = f'{colors.PURPLE} O {colors.GRAY}'
    else:
        if px:
            board[2 * (py - 1)][2 * (px - 1)] = f'{colors.BLUE} O {colors.GRAY}'
        if ox:
            board[2 * (oy - 1)][2 * (ox - 1)] = f'{colors.RED} O {colors.GRAY}'

    def hl(x, y):
        if x >= 0 and x < 17 and y >= 0 and y < 17:
            board[y][x] = f'{colors.ENDC}{bold_sym(board[y][x])}{colors.GRAY}'

    for x in range(10):
        for y in range(9):
            if self.map.h[y][x]:
                hl(2 * x - 1, 2 * y + 1)
                hl(2 * x - 1, 2 * y - 1)
                hl(2 * x - 1, 2 * y)

    for x in range(9):
        for y in range(10):
            if self.map.v[y][x]:
                hl(2 * x + 1, 2 * y - 1)
                hl(2 * x - 1, 2 * y - 1)
                hl(2 * x, 2 * y - 1)

    for i, line in enumerate(board):
        res = f'{colors.GRAY}  {"".join(line)}{colors.CYAN}{(i + 2) // 2 if not i % 2 else " "}{colors.GRAY}\n' + res

    res += f'   {"   ".join(map(lambda i: f"{colors.GREEN}{i}{colors.GRAY}", range(1, 10)))}{colors.ENDC}\n'
    return "%s's turn!\n" % ('POSTECH' if self.turn else 'KAIST') + res
