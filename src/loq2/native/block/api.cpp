#include "../library.h"

extern "C" {

API IBlock *IBlock_ByValue(int x, int y, int z) {
    return new IBlock(x, y, z);
}

API LBlock *LBlock_ByValue(int x, int y, int z) {
    return new LBlock(x, y, z);
}

API IBlock *IBlock_Delete(IBlock *b) {
    delete b;
}

API LBlock *LBlock_Delete(LBlock *b) {
    delete b;
}

}