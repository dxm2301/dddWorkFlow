# Du Gen

<!-- ![Avatar](./avatar_250223.jpg) -->

## Personal Information
- **Phone:** (+86) 186-4285-6913
- **Email:** 1695963186@qq.com
- **Job Objective:** AI Operator Development Engineer

## Work Experience

### Operator Compiler Engineer | Li Auto Inc. | Apr 2023 - Present
- Participated in the full process from design to successful tape-out and bring-up of self-developed NPU chip, **responsible for key operator development and performance optimization**
- **Built an MLIR-based operator compilation framework**, implementing operator fusion, splitting, and parallel optimization, completing the conversion process from high-level IR to hardware-specific IR
- **Designed compilation optimization solutions for convolution and sampling operators**, reducing hardware awareness barriers and improving team development efficiency

## Project Experience

### Operator Compilation Framework Development | May 2024 - Present

**Sampling Operator Compilation Optimization | Dec 2024 - Present**
- **Implemented fusion optimization solutions for GridSample with Mul and ReduceSum operators**
- Abstracted the computation process of **GridSample, Resize, Rotate** and other operators, **splitting sampling operators into a two-stage computation model of Sample2D+DepthwiseConv**, achieving various image processing functions through configuration combinations

**Convolution Operator Compilation Optimization | May 2024 - Nov 2024**
- Utilized the MLIR ecosystem to **build multi-layer nested scf.for and scf.forall structures, precisely mapping NPU hardware behavior**, fully expressing convolution computation patterns
- **Implemented hardware-independent operator expressions through Transform dialect**, providing a unified framework for tiling optimization, computation reordering, and bank conflict elimination

### High-Performance Operator Development and Optimization | Apr 2023 - Apr 2024

**Sampling Operator Development | Nov 2023 - Apr 2024**
- Implemented **GridSample, Resize, Rotate** operators supporting **BEV, UniAD** and other networks, supporting bilinear and nearest interpolation modes
- **Designed Spatial splitting strategy**, **eliminating redundant global_transpose operations** through cross-tile data access, significantly improving overall network performance
- Assisted in optimizing IPU module precision (fp16→fp24→fp32), **resolving precision loss in the normalization process**, achieving bitwise alignment with PyTorch

**Convolution Operator Development and Optimization | Jun 2023 - Oct 2023**
- Designed and implemented **Conv2d** operator based on self-developed NPU architecture, achieving **100% functional coverage** of convolution operators in **BEV, FPN, UniAD** and other models
- **Optimized ConvTranspose2d implementation**, improving the traditional input swelling method to weight pattern splitting strategy, **reducing memory usage by 75% and improving computational efficiency by 50%** in 2x upsampling scenarios
- Implemented **WrapBack optimization strategy** for Conv operator, reordering computation to build fine-grained pipeline, solving edge data dependency bottlenecks in RegNet networks

## Professional Skills
- **Programming Languages:** Proficient in C++, capable of complex algorithm design and implementation
- **AI Compilation: Familiar with MLIR framework and core Dialects (Linalg, Affine, SCF, Transform)**, experienced in operator fusion, splitting, parallel optimization, and Pass development
- **Operator Development:** Deep understanding of PyTorch operator principles, **experienced in NPU platform operator design, performance tuning, and precision optimization**
- **Development Tools:** Proficient in **Git, Vim, GDB** and other tools, capable of efficient collaborative development and debugging in Linux environment

## Education
- **Nanjing University of Science and Technology | Mechanical Engineering | Master | Rank: 5% | Sep 2020 - Apr 2023**
- **Dalian Jiaotong University | Automotive Engineering | Bachelor | Rank: 10% | Sep 2016 - Jun 2020**

## Self-Assessment
- **Technology-Driven:** Passionate about technical challenges, with rapid learning ability and innovative technical thinking
- **Problem-Solving:** Good at analyzing complex problems and designing efficient solutions
- **Team Collaboration:** Excellent communication skills and team spirit
- **Career Planning:** Committed to technical innovation and in-depth research in the field of AI compilation