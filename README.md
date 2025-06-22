# AUP1400-2 作业项目说明

本项目为 Amirkabir University of Technology 1400-2 高级编程课程的作业集合实现：
- 课程仓库: https://github.com/courseworks
- 贴一个课程实现(本人也有部分参考): https://github.com/Daniel741312/AUT-1400
- 本人实现: https://github.com/SAM0619TJ/AUP1400-2


>- [x] HW1: 线性代数库实现。
>- [x] HW2: 简易加密货币系统模拟。
>- [ ] HW3: 实现 Binary Search Tree (BST)。
>- [ ] HW4: 实现 C++ 中的 SharedPtr 和 UniquePtr 智能指针。
---

## HW1 —— 线性代数库实现

### 简介

实现一个 C++ 线性代数库，支持常见矩阵操作。所有声明写在 `hw1.h`，实现写在 `hw1.cpp`，所有函数均放在 `algebra` 命名空间下。

### 主要功能

- `zeros`：生成全零矩阵
- `ones`：生成全1矩阵
- `random`：生成指定范围的随机矩阵（用 `<random>` 库）
- `show`：美观输出矩阵，保留3位小数
- `multiply`：矩阵与常数、矩阵与矩阵相乘
- `sum`：矩阵与常数、矩阵与矩阵相加
- `transpose`：矩阵转置
- `minor`：返回去掉指定行列的子矩阵
- `determinant`：递归按行展开法计算行列式
- `inverse`：矩阵求逆
- `concatenate`：按行或按列拼接两个矩阵
- **初等行变换（ERO）**：行交换、行数乘、行倍加
- `upper_triangular`：用初等行变换将矩阵化为上三角矩阵（主对角线为0时需与下方非零行交换）

### 注意事项

- 所有函数需对输入合法性进行检查，遇到非法输入应抛出 `logic_error` 异常。
- 空矩阵等特殊情况需妥善处理（如空矩阵行列式为1）。
- 所有实现仅限于 `hw1.cpp` 和 `hw1.h` 文件。
- 测试和调试可在 `main.cpp` 的 debug 区域进行。
- 适用于 Linux 或 WSL 环境。

---

## HW2 —— 简易加密货币系统模拟

### 简介

实现一个中心化的加密货币系统，包含 `Server` 和 `Client` 两个核心类。支持用户注册、转账、交易签名验证、挖矿奖励等功能。

### 主要功能

- **Server 类**
  - `add_client`：注册新用户，初始余额5币，若用户名重复自动加4位随机数
  - `get_client`：通过用户名获取用户指针
  - `get_wallet`：查询指定用户余额
  - `parse_trx`：解析交易字符串（格式如 `alice-bob-1.5`），非法格式抛出异常
  - `add_pending_trx`：校验签名和余额后，将交易加入挂起队列
  - `mine`：拼接所有挂起交易为 mempool，所有客户端尝试 nonce，sha256 前10位出现连续3个0即挖矿成功，矿工奖励6.25币，所有交易正式生效并清空挂起队列

- **Client 类**
  - `get_id`：获取用户名
  - `get_publickey`：获取公钥
  - `get_wallet`：查询余额
  - `sign`：用私钥签名字符串
  - `transfer_money`：发起转账，生成交易字符串并签名，调用服务器挂起交易
  - `generate_nonce`：生成随机 nonce 用于挖矿

### 注意事项

- 交易只有在 `mine` 成功后才会真正影响余额
- 所有签名、哈希等操作请使用 `crypto.cpp/h` 提供的接口
- 只允许修改 `server.cpp/h`、`client.cpp/h`，以及 `main.cpp` 的 debug 区域
- 单元测试和调试可在 `main.cpp` 的 debug 区域进行

---

## 编译与测试

1. 使用支持 C++11 及以上标准的编译器（HW2 推荐 C++20）。
2. 进入对应作业文件夹，编译项目：
   ```sh
   mkdir -p build
   cd build
   cmake ..
   make
   ```
3. 运行程序即可在 debug 区域测试你的实现。若需运行单元测试，将 `main.cpp` 中 debug 区域的条件改为 `false`。

---

**配置环境**

课程使用了[Docker](https://www.docker.com/products/docker-desktop)管理环境，每个homework都提供了对应的**Dockerfile**，课程并不需要你编写**Dockerfile**，只需要使用**Dockerfile**创建镜像，并使用镜像启动容器。不了解Docker的可以查看[Docker 10分钟快速入门](https://www.bilibili.com/video/BV1s54y1n7Ev?vd_source=c1a4fe488e28c685f3d2b18671221525)快速了解Docker。

**Debug**

在完成homework中，可能希望在容器中对程序进行调试。为了实现这一目标你需要准备。

- [VSCode](https://code.visualstudio.com/)
- VSCode的[devcontainer](https://github.com/Microsoft/vscode-remote-release.git)扩展
- [Docker](https://www.docker.com/products/docker-desktop)

完成了以上准备了，我们可以在具体的homework目录打开VSCode,并使用<u>Ctrl+Shift+p</u> 中Reopen in Container。后续devcontainer会根据目录下的.devcontainer.json自动配装环境。

<img src=".\resource\devcontainer.gif" style="zoom:67%;" />

---

配环境部分参考kanzakishigure的README.md，仓库地址：https://github.com/kanzakishigure/AP1400-2