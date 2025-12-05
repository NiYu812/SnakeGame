@echo off
echo 正在测试Qt开发环境...
echo.

:: 检查qmake
echo 1. 检查qmake...
qmake --version
if errorlevel 1 (
    echo 错误: 未找到qmake，请确保Qt已正确安装
    goto :error
)
echo ✓ qmake 已找到
echo.

:: 检查g++
echo 2. 检查g++编译器...
g++ --version
if errorlevel 1 (
    echo 错误: 未找到g++编译器，请确保MinGW已正确安装
    goto :error
)
echo ✓ g++ 编译器已找到
echo.

:: 检查mingw32-make
echo 3. 检查mingw32-make...
mingw32-make --version
if errorlevel 1 (
    echo 错误: 未找到mingw32-make，请确保MinGW已正确安装
    goto :error
)
echo ✓ mingw32-make 已找到
echo.

:: 检查Qt版本
echo 4. 检查Qt版本...
qmake -query QT_VERSION
if errorlevel 1 (
    echo 错误: 无法获取Qt版本
    goto :error
)
echo ✓ Qt 版本已确认
echo.

:: 检查Qt安装路径
echo 5. 检查Qt安装路径...
qmake -query QT_INSTALL_PREFIX
if errorlevel 1 (
    echo 错误: 无法获取Qt安装路径
    goto :error
)
echo ✓ Qt 安装路径已确认
echo.

echo 所有测试通过！您的Qt开发环境已正确配置。
echo 现在可以运行以下命令构建项目：
echo.
echo mkdir build
echo cd build
echo qmake ..\SnakeGame_simple.pro
echo mingw32-make
echo.
echo 按任意键退出...
pause >nul
exit /b 0

:error
echo.
echo 环境配置失败！请查看ENVIRONMENT_SETUP.md文档了解解决方案。
echo 按任意键退出...
pause >nul
exit /b 1