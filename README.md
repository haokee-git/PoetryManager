# 古诗词管理器 | Poetry Manager

古诗词管理器是由好渴鹅编写的一个简易命令行的管理古诗词的小程序，采用 C++ 编写，MSVC 构建，目前仅可在 Windows 环境下运行。（Windows7 以下或部分 Windows10 的老版本终端可能会出现显示错误）

目前最新的发布版本为版本为 1.1.9v，下载当前版本：[PoetryManager 1.1.9v.zip](https://github.com/haokee-git/PoetryManager/releases/download/1.1.9v/PoetryManager.1.1.9v.zip)。

## 使用手册

### 按键说明

- ↑ 键：把当前选择的古诗词光标向上调整
- ↓ 键：把当前选择的古诗词光标向下调整
- CTRL + N 键：添加新的古诗词
- CTRL + U 键：更改已有的（当前光标）古诗词
- CTRL + D 或 Delete 键：删除当前光标上的古诗词
- CTRL + Q 键：退出当前程序

### 输入说明

在添加新的古诗词的时候，请在第一行输入你想要添加的古诗词的标题，然后在第二行输入你想要添加的古诗词的作者、朝代等信息，接下来若干行都是正文的内容，直到输入完成就在单独的一行当中按下 Ctrl+E 并回车则完成古诗词的添加。

更改已有的古诗词的时候，不需要重新输入古诗词的标题了，只需要输入朝代和正文并以同样的方式结束输入即可。

无需自行排版，程序会默认居中。
