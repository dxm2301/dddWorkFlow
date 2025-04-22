# 顶层Makefile，简化构建流程

# 默认目标
all: prepare build_all

# 准备构建目录
prepare:
	@mkdir -p build
	@cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug

# 构建所有目标
build_all:
	@cd build && make

# 清理构建产物
clean:
	@rm -rf build

# 构建特定目录下的所有目标
sorting linked_list binary_tree dynamic_programming graph string:
	@cd build && make $(shell find $@ -name "*.cpp" | sed 's/\.cpp$$//')

# 运行特定目标 (从 bin 目录运行)
run-%: prepare
	@cd build && make $* && ./bin/$*

# 构建单个文件
%: prepare
	@cd build && make $@

.PHONY: all prepare build_all clean sorting linked_list binary_tree dynamic_programming graph string