# 贪吃蛇游戏 (Snake Game)

一个使用 C++ 和 Qt 框架开发的经典贪吃蛇游戏。

## 功能特性

- 🎮 经典贪吃蛇游戏玩法
- ⌨️ 支持方向键和 WASD 键位控制
- 📊 实时分数显示
- 🏆 最高分记录功能
- ⚡ 随着分数增加，游戏速度逐渐加快
- 🎨 简洁美观的图形界面
- ▶️ 开始、暂停、重置游戏功能

## 技术实现

- **开发语言**: C++
- **框架**: Qt 5/6
- **图形系统**: QGraphicsScene / QGraphicsView
- **构建系统**: QMake 和 CMake

## 项目结构

```
SnakeGame/
├── main.cpp              # 主函数入口
├── mainwindow.h          # 主窗口类头文件
├── mainwindow.cpp        # 主窗口类实现
├── mainwindow.ui         # 主窗口UI设计
├── snakegame.h           # 游戏核心逻辑头文件
├── snakegame.cpp         # 游戏核心逻辑实现
├── SnakeGame.pro         # QMake项目文件
├── CMakeLists.txt        # CMake项目文件
├── resources.qrc         # 资源文件
└── README.md             # 项目说明文档
```

## 游戏规则

1. 使用方向键（↑ ↓ ← →）或 WASD 键控制蛇的移动方向
2. 吃到红色食物可以增加 10 分并增加蛇的长度
3. 每吃到 10 个食物，游戏速度会增加 10%
4. 撞到墙壁或蛇自己的身体会游戏结束
5. 最高分会自动保存在本地文件中

## 构建和运行

### 使用 Qt Creator

1. 打开 Qt Creator
2. 选择 "Open Project"
3. 选择 `SnakeGame.pro` 文件
4. 配置 Qt 构建套件
5. 点击 "Run" 按钮编译并运行

### 使用 CMake

```bash
mkdir build
cd build
cmake ..
cmake --build .
./SnakeGame
```

## 控制说明

- **方向键** / **WASD**: 控制蛇的移动方向
- **开始按钮**: 开始或继续游戏
- **暂停按钮**: 暂停游戏
- **重置按钮**: 重置游戏到初始状态

## 开发环境

- Qt 5.15 或更高版本
- C++11 或更高版本
- 支持 Qt Widgets 的编译器

## 未来改进

- 添加音效和背景音乐
- 增加不同难度级别
- 添加游戏道具（如加速、减速、穿墙等）
- 实现多人对战模式
- 添加游戏排行榜
- 支持自定义游戏主题

## 许可证

MIT License

## 作者

使用 Qt 和 C++ 开发的经典贪吃蛇游戏