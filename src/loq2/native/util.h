#pragma once

typedef unsigned char byte;
#define BOARD_SIZE 9
#define I_COUNT 7
#define L_COUNT 3
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) > (y) ? (y) : (x))

#ifdef _WIN32
#define API __declspec(dllexport)
#else
#define API
#endif