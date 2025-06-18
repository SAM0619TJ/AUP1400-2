#AUP1400-2


# HW1 —— 线性代数库实现

## 作业简介

本项目是基于Amirkabir University of Technology 1400-2: Advanced Programming Course的课程作业集合
课程源码：https://github.com/courseworks

矩阵类型定义如下：

```cpp
using Matrix = std::vector<std::vector<double>>;
```

所有函数均应放在 `algebra` 命名空间下。

---

## 功能列表

- **zeros**：生成 n 行 m 列的全零矩阵
- **ones**：生成 n 行 m 列的全1矩阵
- **random**：生成 n 行 m 列、元素为 [min, max) 区间随机数的矩阵（用 `<random>` 库）
- **show**：美观输出矩阵，每个元素保留3位小数
- **multiply**：支持矩阵与常数、矩阵与矩阵相乘
- **sum**：支持矩阵与常数、矩阵与矩阵相加
- **transpose**：矩阵转置
- **minor**：返回去掉指定行列后的子矩阵
- **determinant**：递归按行展开法计算行列式
- **inverse**：矩阵求逆
- **concatenate**：按行或按列拼接两个矩阵
- **初等行变换（ERO）**：
  - 行交换
  - 行数乘
  - 行倍加
- **upper_triangular**：用初等行变换将矩阵化为上三角矩阵（主对角线为0时需与下方非零行交换）

---

## 注意事项

- 所有函数需对输入合法性进行检查，遇到非法输入应抛出 `logic_error` 异常。
- 空矩阵等特殊情况需妥善处理（如空矩阵行列式为1）。
- 所有实现仅限于 `hw1.cpp` 和 `hw1.h` 文件。
- 测试和调试可在 `main.cpp` 的 debug 区域进行。
- 此项目适用于 linux or wsl

---

## 编译与测试

1. 使用支持 C++11 及以上标准的编译器。
2. 编译项目后，运行程序即可在 debug 区域测试你的实现。
3. 若需运行单元测试，将 `main.cpp` 中 debug 区域的条件改为 `false`。

---

ps.此README由AI生成.
