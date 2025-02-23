# Du Gen's 简历

![头像](./avatar_250223.jpg)  <!-- 替换为头像图片的 URL -->

## 联系方式
- **电话:** (+86)186-4285-6913
- **电子邮件:** ddd1695963186@gmail.com
- **求职方向:** AI 编译器研究工程师

## 教育经历
- **2020.09 - 2023.04**  
  **南京理工大学**  
  **专业:** 机械工程（硕士）  
  **排名:** 5%

- **2016.09 - 2020.06**  
  **大连交通大学**  
  **专业:** 汽车工程（本科）  
  **排名:** 10%

## 工作经验

### 2023.04 - 至今  
**算子编译器工程师**  
**理想汽车有限公司**
- 负责高性能算子的设计、开发，对算子进行深度性能分析解决性能瓶颈，确保在自研NPU平台上高效运行。
- 负责 AI 编译器中 conv、ipu 类算子的编译开发，支持引入 Linalg、 Affine、SCF 等 Dialect 的 transform 完成对算子的 sharding 和 tiling，完成对自研NPU conv2d 计算模式的 linalg + n 层 scf.for IR的完全表达。

## 项目经历

### 2024.12 - 2025.02  
**gridSample编译开发**  
- wait for writing。
- wait for writing。

### 2024.05 - 2024.11  
**conv pass 编译开发**  
- wait for writing。
- wait for writing。

### 2023.11 - 2024.04  
**resize/rotate/gridSample 算子开发**  
- 支持 BEV 等网络中的图像旋转、放缩功能，实现 bilinear、nearest mode 的 resize、 rotate、grid_sample 算子。
- 分析 IPU 模块在 denormalize + normalize 过程中的精度损失问题，协助架构完善 IPU 模块设计，定位并排查 rotate nearest mode fp24 精度不足问题。

### 2023.06 - 2023.10  
**conv2d/convTranspose2d 算子开发**  
- 基于自研NPU平台完成 conv2d 开发，完成BEV、FPN等模型中700+ conv算子的适配。
- 完成convTranspose2d开发，并设计了拆分其为多个conv2d运算的weight pattern方案。在2倍上采样场景中，比input swelling方案降低了UM 75%的内存消耗，并提高了50%计算效率。

## 专业技能
- 熟练使用 C++，具备设计和实现复杂数据结构和算法的能力
- 熟练使用 Git、Vim、GDB 等工具，具备Linux环境高效协作开发调试能力
- 熟悉 pytorch 算子的底层实现，具备 conv2d、convTranspose2d、resize、rotate、grid_sample 等算子的 NPU 开发及优化能力

## 个人评价
- 学习能力：热衷于技术挑战，能快速学习并应用新知识
- 独立工作能力：能独立完成任务，具备出色的时间管理和项目管理能力
- 团队协作：具备良好的团队协作和沟通能力，性格开朗
- 职业规划：希望长期从事 AI 编译开发工作
