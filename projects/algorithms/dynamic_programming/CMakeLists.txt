# 查找当前目录下的所有源文件
file(GLOB SOURCES "*.cpp")

# 为每个源文件创建可执行文件
foreach(source_file ${SOURCES})
    # 获取文件名（不含扩展名）
    get_filename_component(executable_name ${source_file} NAME_WE)
    
    # 添加可执行文件
    add_executable(${executable_name} ${source_file})
endforeach()