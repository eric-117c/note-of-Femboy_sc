### 数据库系统笔记：Lec 2 关系模型

#### 什么是关系型数据库
- 基于关系模型
- 优势在于：直截了当的数据表示；复杂查询操作也能很难轻松的实现

##### 区分 relation & relationship
- relationship 是实体之间的联系
- relation 是数学概念，是一张表

#### 关系型数据的结构
- 笛卡尔积
  - relation $r = D_1 \times D_2 \times ... \times D_n$
  - $D$指代一个数属性下的取值集合

- 属性(attribute)
  - 属性被允许的值的集合称为**域**（domain）
  - 属性值要求是**原子的**（atomic）
  - null是一种**特殊的**属性值

- 关系(relation)
  - 关系模式(relation schema)和关系实例(relation instance)

- 关系模式
  - 假设$A_1,A_2,...,A_n$是不同的属性
  - 那么$R=(A_1,A_2,...,A_n)$就是一个关系模式
  - $r(R)$代表基于关系模式 R 的 关系 r

- 关系实例
  - 几个元素值的组合称为一个**元组**(tuple)
  - 元组在一张表里面表现为一行

- 关系的性质
  - 关系实例是**不相关的**
  - 关系实例**不可重复**
  - 属性值是**原子的**

- 数据库由多个关系组成

- 码 Key
  - 超码（superkey）—— 能区分不同元组的属性集
  - 候选码（candidate key）—— 能唯一区分不同元组的**最小**属性集
  - 主码（primary key）—— 制作者选出来作为区分不同关系实例的key，会用**下划线**标识
  - 外码（foreign key）—— 来自其他表的码的约束，使用外码的叫 referencing relation，被引用的叫 referenced relation
  - 主码和外码合称复合约束（integrated constraint）

- 查询语言
  - 一种用户用来向数据库查询数据的方法
  - pure language（后两个不要求）
    - relation algebra
    - tuple relation calculus
    - domain relation calculus
  - pure language构成查询语言的基础

#### 基础关系代数操作
- 六个基本运算
  - SELECT 选择 $\sigma_{select\_ approach}(r)$
  - PROJECT 投影
  - UNION 并集
  - SET DIFFERNENCE 差集
  - CARTESIAN PRODUCT 笛卡尔积
  - RENAME 重命名

- SELECT 选择
  - $\sigma_{select\_ predicate}(r)$
  - 选择复合条件的tuple
  - 示例：$\sigma_{branch-name=‘Perryridge’}(account)$

- PROJECT 投影
  - $\Pi_{A_1,A_2,...,A_k}(r)$
  - 按照投影要求选择指定属性形成行的元素，然后去除重复的tuple
  - 示例：$\Pi_{account-number, balance}(account)$
  - 