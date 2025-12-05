# 贪吃蛇游戏项目总结

## 项目概述

这是一个使用Qt和C++开发的经典贪吃蛇游戏项目。项目包含完整的游戏逻辑、图形界面和用户交互功能。

## 项目结构

```
SnakeGame/
├── main.cpp              # 应用程序入口
├── mainwindow.h/cpp      # 主窗口类
├── snakegame.h/cpp       # 游戏逻辑类
├── gamescene.h/cpp       # 游戏场景绘制类
├── SnakeGame_simple.pro  # 简化版项目文件（推荐使用）
├── CMakeLists.txt        # CMake配置文件
├── ENVIRONMENT_SETUP.md  # 环境配置指南
├── FINAL_BUILD_GUIDE.md  # 最终构建指南
├── TROUBLESHOOTING.md    # 故障排除指南
├── test_qt_env.bat       # Qt环境测试脚本
├── build_simple.bat      # 简化版构建脚本
└── clean_build.bat       # 清理脚本
```

## 已实现功能

- ✅ 经典贪吃蛇游戏玩法
- ✅ 键盘方向键控制
- ✅ 空格键暂停/继续
- ✅ 得分显示
- ✅ 游戏开始/暂停/结束功能
- ✅ 菜单系统
- ✅ 状态栏信息
- ✅ 游戏结束提示
- ✅ 图形化界面
- ✅ 网格背景
- ✅ 蛇身和食物绘制

## 技术栈

- **Qt 5.15+** - 图形界面框架
- **C++11** - 编程语言
- **QGraphicsView/QGraphicsScene** - 2D图形渲染
- **QTimer** - 游戏循环控制
- **qmake** - 构建系统

## 构建步骤

### 步骤1：配置开发环境

1. 运行`test_qt_env.bat`检查环境
2. 如果有错误，查看`ENVIRONMENT_SETUP.md`配置环境
3. 确保以下工具可用：
   - qmake
   - g++ (MinGW)
   - mingw32-make

### 步骤2：构建项目

**方法1：使用命令行**
```bash
# 测试环境
test_qt_env.bat

# 构建项目
mkdir build
cd build
qmake ..\SnakeGame_simple.pro
mingw32-make
```

**方法2：使用构建脚本**
```bash
# 简化版构建
build_simple.bat

# 清理旧构建
clean_build.bat
```

**方法3：使用Qt Creator**
1. 打开`SnakeGame_simple.pro`
2. 配置构建套件（MinGW 8.1.0 64-bit）
3. 右键项目 -> 运行qmake
4. 构建 -> 构建项目

### 步骤3：运行游戏

构建成功后，可执行文件位于：
```
build\bin\SnakeGame.exe
```

## 游戏控制

| 按键 | 功能 |
|------|------|
| ↑↓←→ | 控制蛇的移动方向 |
| 空格 | 暂停/继续游戏 |
| 开始按钮 | 开始新游戏 |
| 暂停按钮 | 暂停游戏 |
| 退出按钮 | 退出游戏 |

## 游戏规则

1. 控制蛇吃红色食物获得分数
2. 每吃一个食物得10分，蛇身会变长
3. 不能撞到墙壁或自己的身体
4. 游戏结束后可以选择开始新游戏

## 常见问题解决方案

### 问题1：无法找到编译器
**解决方案：** 查看`ENVIRONMENT_SETUP.md`配置MinGW环境

### 问题2：undefined reference to vtable
**解决方案：** 运行qmake重新生成MOC文件

### 问题3：构建失败
**解决方案：** 清理旧构建文件，重新运行qmake

### 问题4：游戏运行异常
**解决方案：** 确保Qt版本与编译器版本匹配

## 代码说明

### 主要类结构

1. **MainWindow** - 主窗口类，负责UI布局和用户交互
2. **SnakeGame** - 游戏逻辑类，处理蛇的移动、碰撞检测等
3. **GameScene** - 游戏场景类，负责绘制蛇、食物和网格

### 核心功能实现

- **游戏循环**：使用QTimer定时更新游戏状态
- **碰撞检测**：检查蛇头是否撞墙或撞到自己
- **食物生成**：随机生成食物位置，确保不在蛇身上
- **方向控制**：防止蛇直接反向移动

## 扩展功能建议

- 添加难度级别（速度调节）
- 实现高分榜
- 添加音效
- 支持不同的蛇皮肤
- 实现多人模式
- 添加障碍物

## 技术支持

如果您遇到问题，请提供以下信息：
1. Qt版本
2. MinGW版本
3. 操作系统版本
4. 完整的错误信息
5. 环境变量配置

## 许可证

本项目基于MIT许可证开源，可自由使用和修改。