@echo off
echo 正在构建贪吃蛇游戏...

:: 检查qmake是否可用
qmake -version >nul 2>&1
if errorlevel 1 (
    echo 错误: 未找到qmake，请确保Qt已正确安装并添加到系统路径
    pause
    exit /b 1
)

:: 创建构建目录
if not exist build_qmake mkdir build_qmake
cd build_qmake

:: 生成Makefile
echo 正在生成Makefile...
qmake ..\SnakeGame.pro
if errorlevel 1 (
    echo 错误: qmake失败
    pause
    exit /b 1
)

:: 编译项目
echo 正在编译项目...
mingw32-make
if errorlevel 1 (
    echo 错误: 编译失败
    pause
    exit /b 1
)

:: 检查可执行文件是否生成
if exist bin\SnakeGame.exe (
    echo 构建成功！
    echo 可执行文件位于: build_qmake\bin\SnakeGame.exe
    echo 按任意键退出...
    pause >nul
) else (
    echo 错误: 未生成可执行文件
    pause
    exit /b 1
)