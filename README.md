# dddWorkFlow

此仓库用于记录学习过程、管理个人项目和技术积累，特别关注 AI 编译器、算子优化和算法实践。

## 项目结构

```plaintext
/Users/dugen/scc/dddWorkFlow/
├── .ccls-cache/         # (Ignored) ccls 语言服务器缓存
├── .git/                # (Hidden) Git 版本控制元数据
├── .github/             # GitHub 相关配置 (CI/CD, Issue模板等)
│   ├── ISSUE_TEMPLATE/
│   └── workflows/
├── .gitignore           # Git 忽略规则配置文件
├── README.md            # 本文件 - 项目根说明
├── docs/                # 文档、笔记和学习资料
│   ├── README.md
│   ├── architecture/
│   ├── blog/
│   ├── frameworks/
│   ├── language/
│   └── tools/
├── projects/            # 主要项目代码
│   ├── README.md
│   ├── ai-compiler/
│   ├── algorithms/      # 算法练习 (C++)
│   │   ├── CMakeLists.txt
│   │   ├── Makefile       # 用于简化构建命令
│   │   ├── binary_tree/
│   │   ├── build/         # (Ignored) CMake 构建目录
│   │   ├── dynamic_programming/
│   │   ├── graph/
│   │   ├── linked_list/
│   │   ├── sorting/
│   │   ├── string/
│   │   └── utils/         # 通用数据结构 (data_structures.h)
│   ├── operator-optimization/
│   └── utils/
├── resources/           # 非代码资源 (数据集, 模型等)
│   ├── README.md
│   ├── datasets/
│   └── models/
├── resume/              # 简历相关文件
│   ├── README.md
│   ├── applications/
│   ├── assets/
│   ├── pdf/
│   └── templates/
└── scripts/             # 自动化脚本 (构建, 部署, 工具等)
    ├── README.md
    ├── build/
    ├── deploy/
    └── tools/

