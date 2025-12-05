@echo off
echo 正在清理构建目录...

:: 删除CMake构建目录
if exist build rmdir /s /q build
if exist build_qmake rmdir /s /q build_qmake

:: 删除临时文件和目录
if exist obj rmdir /s /q obj
if exist moc rmdir /s /q moc
if exist bin rmdir /s /q bin
if exist debug rmdir /s /q debug
if exist release rmdir /s /q release

:: 删除Qt Creator配置文件
if exist .qtcreator rmdir /s /q .qtcreator
if exist *.user del /f /q *.user

:: 删除临时文件
del /f /q *.qmake.stash
del /f /q *.log
del /f /q *.tmp

echo 清理完成！
echo 现在可以重新在Qt Creator中打开项目或使用build.bat构建。
pause