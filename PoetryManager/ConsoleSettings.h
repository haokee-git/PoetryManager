#pragma once

#include <Windows.h>

#define UP    72
#define DOWN  80
#define ENTER 13
#define ESC   27
#define DEL   83
#define A     97
#define D     100
#define U     117
#define H     104
#define Q     113

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