# Du Gen

<!-- ![Avatar](./avatar_250223.jpg) -->

## Personal Information
- **Phone:** (+86) 186-4285-6913
- **Email:** 1695963186@qq.com
- **Job Objective:** AI Operator Development Engineer

## Work Experience

### Operator Compiler Engineer | Li Auto Inc. | Apr 2023 - Present
- Participated in the full-cycle development of a self-developed NPU chip from design to successful tape-out and bring-up, **responsible for critical operator development and performance optimization**
- **Built an MLIR-based operator compilation framework**, implementing operator fusion, splitting, and parallel optimization, completing the conversion from high-level IR to hardware-specific IR
- **Designed compilation optimization solutions for convolution and sampling operators**, reducing hardware awareness barriers and improving team development efficiency

## Project Experience

### Operator Compilation Framework Development | May 2024 - Present

**Sampling Operator Compilation Optimization | Dec 2024 - Present**
- **Implemented fusion optimization for GridSample combined with Mul and ReduceSum operators**
- Abstracted computation processes of **GridSample, Resize, Rotate**, etc., **decomposing sampling operators into a two-stage model (Sample2D + DepthwiseConv)** to achieve diverse image processing through configuration combinations

**Convolution Operator Compilation Optimization | May 2024 - Nov 2024**
- Leveraged MLIR ecosystem to **construct multi-layer nested scf.for and scf.forall structures, precisely mapping NPU hardware behaviors** and fully expressing convolution computation patterns
- **Enabled hardware-agnostic operator expressions via Transform dialect**, providing a unified framework for tiling optimization, computation reordering, and bank conflict elimination

### High-Performance Operator Development & Optimization | Apr 2023 - Apr 2024

**Sampling Operator Development | Nov 2023 - Apr 2024**
- Implemented **GridSample, Resize, Rotate** operators supporting **BEV, UniAD** networks with bilinear/nearest interpolation modes
- **Designed Spatial Splitting Strategy** to **eliminate redundant global transpose operations** via cross-tile data access, significantly boosting network performance
- Assisted in optimizing IPU module precision (fp16→fp24→fp32), **resolving normalization precision loss** and achieving bitwise alignment with PyTorch

**Convolution Operator Development & Optimization | Jun 2023 - Oct 2023**
- Designed and implemented **Conv2d** operator for proprietary NPU architecture, achieving **100% functional coverage** for convolution in **BEV, FPN, UniAD** models
- **Optimized ConvTranspose2d** by replacing traditional input swelling with weight pattern splitting, **reducing memory usage by 75% and improving computational efficiency by 50%** in 2x upsampling scenarios
- Developed **WrapBack optimization** for Conv operator, reordering computation to build fine-grained pipelines and resolving edge data dependency bottlenecks in RegNet networks

## Professional Skills
- **Programming Languages:** Proficient in C++ with complex algorithm design and implementation capabilities
- **AI Compilation: Familiar with MLIR framework and core Dialects (Linalg, Affine, SCF, Transform)**, experienced in operator fusion/splitting/parallel optimization and Pass development
- **Operator Development:** Deep understanding of PyTorch operator principles, skilled in NPU operator design, performance tuning, and precision optimization
- **Development Tools:** Proficient in **Git, Vim, GDB**, etc., capable of efficient collaborative development and debugging in Linux environments

## Education
- **Nanjing University of Science and Technology | M.Eng. in Mechanical Engineering | Rank: Top 5% | Sep 2020 - Apr 2023**
- **Dalian Jiaotong University | B.Eng. in Automotive Engineering | Rank: Top 10% | Sep 2016 - Jun 2020**

## Self-Assessment
- **Technology-Driven:** Passionate about tackling technical challenges with rapid learning ability and innovative thinking
- **Problem-Solving:** Strong analytical skills in designing efficient solutions for complex technical issues
- **Team Collaboration:** Excellent communication skills and team spirit
- **Career Vision:** Committed to advancing technical innovation in AI compilation and hardware-software co-design