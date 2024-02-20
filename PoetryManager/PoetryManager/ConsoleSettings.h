#pragma once

#include <Windows.h>

#define UP     72
#define DOWN   80
#define ENTER  13
#define ESC    27
#define DEL    83
#define CTRL_D 4
#define CTRL_E 5
#define CTRL_H 8
#define CTRL_N 14
#define CTRL_U 21
#define CTRL_Q 17

void setPos(int y, int x) {
  COORD coord;
  coord.X = x - 1;
  coord.Y = y - 1;
  HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(a, coord);
}

void hideCursor() {
  HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO info;
  GetConsoleCursorInfo(hand, &info);
  info.bVisible = false;
  SetConsoleCursorInfo(hand, &info);
}

void showCursor() {
  HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO info;
  GetConsoleCursorInfo(hand, &info);
  info.bVisible = true;
  SetConsoleCursorInfo(hand, &info);
}