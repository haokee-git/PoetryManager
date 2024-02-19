#include "ConsoleSettings.h"
#include "FileProcessor.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

string appData;
vector<string> fileList;

void init() {
  hideCursor();
  appData = getDir() + "\\AppData";
}

void addFile() {
  showCursor();
  system("cls");
  cout << "[添加古诗] 格式：标题/作者/正文（最少三行）" << endl;
  cout << "输入完成后按 Ctrl+Z 并换行" << endl;
  string title, author, buffer;
  vector<string> body;
  getline(cin, title);
  getline(cin, author);
  while (getline(cin, buffer)) {
    body.push_back(buffer);
  }
  ofstream fout(string("./AppData/") + title);
  fout << title << '\n';
  fout << author << '\n';
  for (auto line : body) {
    fout << line << '\n';
  }
  fout.close();
}

void preview(string title) {
  setPos(4 + fileList.size() + 1, 1);
  ifstream fin(string("./AppData/") + title);
  string buffer;
  while (getline(fin, buffer)) {
    cout << "\33[2K\r" << buffer << '\n';
  }
  auto key = _getch();
}

void update(string title) {
  showCursor();
  system("cls");
  cout << "您正在更新古诗词 " << title << endl;
  cout << "格式与之前一样，但不用重新输入标题（只需作者与正文）" << endl;
  string author, buffer;
  vector<string> body;
  getline(cin, author);
  while (getline(cin, buffer)) {
    body.push_back(buffer);
  }
  ofstream fout(string("./AppData/") + title);
  fout << title << '\n';
  fout << author << '\n';
  for (auto line : body) {
    fout << line << '\n';
  }
  fout.close();
}

void del(string title) {
  remove((string("./AppData/") + title).c_str());
}

void help() {
  system("cls");
  cout << R"(== 帮助 ==

本软件由好渴鹅制作，当前版本为 1.1.5v。

按键说明：

  ↑ 键：把当前选择的古诗词光标向上调整
  ↓ 键：把当前选择的古诗词光标向下调整
  A 键：添加新的古诗词
  U 键：更改已有的（当前光标）古诗词
  D 键：删除当前光标上的古诗词
  Q 键：退出当前程序

输入说明：

  在添加新的古诗词的时候，请在第一行输入你想要添加的古诗词的标题，然后在第二行输入你想要添加的古诗词的作者、朝代等信息，接下来若干行都是正文的内容，直到输入完成就在单独的一行当中按下 Ctrl+Z 并回车则完成古诗词的添加。
  更改已有的古诗词的时候，不需要重新输入古诗词的标题了，只需要输入朝代和正文并以同样的方式结束输入即可。

若了解完本帮助，请按任意键退出。
)";
  auto key = _getch();
}

void quit() {
  cout << endl << "程序已退出。。。" << endl;
  exit(0);
}

void loop() {
  init();
  cout << "古诗词管理器 [版本 1.1.5v]" << endl;
  cout << "好渴鹅制作，如需帮助请按 H。" << endl;
  cout << endl;
  while (1) {
    int pt = 0;
    while (1) {
      setPos(4, 1);
      fileList = getFiles(appData);
      for (int i = 0; i < fileList.size(); i++) {
        if (i == pt) {
          cout << "> " << fileList[i] << '\n';
        } else {
          cout << "  " << fileList[i] << '\n';
        }
      }
      preview(fileList[pt]);
      int key = _getch();
      switch (key) {
      case UP:
        pt = max(pt - 1, 0);
        break;
      case DOWN:
        pt = min(pt + 1, fileList.size() - 1);
        break;
      case A:
        addFile();
        return;
      case U:
        update(fileList[pt]);
        return;
      case D:
        del(fileList[pt]);
        return;
      case H:
        help();
        return;
      case Q:
        quit();
      }
    }
  }
}

int main() {
  while (1) {
    loop();
    system("cls");
  }
  return 0;
}