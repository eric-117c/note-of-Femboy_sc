### 数据库系统笔记：Lec 1 引言

#### 0.成绩组成
* 作业 — — — 10pts 
* 小测 — — — 10pts
* 实验 — — — 30pts
* 考试 — — — 50pts

#### 1. 数据库基础概念
* **数据库 (Database)**：一个非常大的、集成的、用于模拟现实世界企业的数据集合。
* **DBMS (数据库管理系统)**：用于存储、管理和方便访问数据库的软件系统。
* **DBMS 的效益**：
    * 提高数据访问的<font color="red">效率</font>与<font color="red">扩展性</font>。
    * 缩短应用开发时间。
    * 实现<font color="red">数据独立性</font>（物理与逻辑）。
    * 确保<font color="red">数据完整性</font>与<font color="red">安全性</font>。
    * 支持并发访问与系统的<font color="red">鲁棒性（故障恢复）</font>。

#### 2. 数据抽象与数据视图
* **三个抽象层次**：
    1.  **物理层 (Physical level)**：描述记录是<font color="red">如何存储</font>的。
    2.  **逻辑层 (Logical level)**：描述存储的数据及其<font color="red">相互关系</font>。
    3.  **视图层 (View level)**：应用程序隐藏数据类型细节。
* **关键定义**：
    * **模式 (Schema)**：数据库的<font color="red">结构</font>（类似变量类型）。
    * **实例 (Instance)**：特定时刻数据库的<font color="red">实际内容</font>（类似变量的值）。
* **物理数据独立性**：修改物理模式而不影响逻辑模式的能力，是使用 DBMS 的<font color="red">最重要收益之一</font>。
* **逻辑数据独立性**：保护程序免受逻辑数据结构受到影响
* **数据模型**：
  * Relation Model
  * E-R Model
  * OO Model



#### 3. 数据库语言 (SQL)
* **DDL (数据定义语言)**：用于定义数据库模式、存储结构和一致性约束。
* **DML (数据操纵语言)**：
    * **过程化 DML**：需要指定“要什么”以及“<font color="red">如何做</font>”。
    * **非过程化 DML (如 SQL)**：只需指定“<font color="red">要什么</font>”，无需说明具体步骤。
* **核心构成**：<font color="red">SQL = DDL + DML + DCL</font>。

#### 4. 数据库设计与事务
* **设计步骤**：
    1.  需求分析 -> 2. 概念设计 (<font color="red">E-R 模型</font>) -> 3. 逻辑设计 -> 4. 模式精化 (<font color="red">范式化 Normalization</font>) -> 5. 物理设计。
* **事务 (Transaction)**：
    * 必须满足 ACID 特性：<font color="red">原子性 (Atomicity)</font>、<font color="red">一致性</font>、<font color="red">隔离性</font>和<font color="red">持久性</font>。

#### 5. 系统架构与管理
* **存储管理器 (Storage Manager)**：负责与文件管理器交互，实现数据的<font color="red">高效存储、检索与更新</font>。
* **查询处理器 (Query Processor)**：包含 DDL 解析、DML 编译及<font color="red">查询优化</font>。
* **DBA (数据库管理员)**：对系统拥有中央控制权的特殊用户，拥有<font color="red">最高权限</font>。

