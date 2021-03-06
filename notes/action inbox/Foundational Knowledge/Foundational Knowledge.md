# Data Structure

## Tree

平均二叉树的平均深度为`O(N^0.5)`，二叉查找树的平均深度为`O(log N)`。

### Binary Search Tree

1. Find，`O(log N)`
2. FindMin和FindMax，`O(log N)`
3. Insert，`O(log N)`
4. Delete，`O(log N)`
    * 如果node是leaf，则直接删除
    * 如果node有一个child，则父结点**绕过它**，指向child，然后删除该node
    * 如果node有两个child，则(1)**用右子树的min代替该node数据**，(2)（在右子树中）递归删除那个node

### AVL

左右子树高度**最多差1**的Binary Search Tree。

假设必须重新平衡的node叫a，由于任意node最多有两个child，如果高度不平衡，那么a的两个子树的高度差2。不平衡可能出现在这么几种情况中：

1. 对a的left child的left subtree做一次插入
2. 对a的left child的right subtree做一次插入
3. 对a的right child的left subtree做一次插入
4. 对a的right child的right subtree做一次插入

#### 单旋转

1和4实际上是插入发生在外侧的情况，用单旋转来处理，**提升外侧**subtree的高度。

`Tx < k1 < Ty < k2 < Tz`

![](./_image/2016-03-27 22-02-52.jpg)

![](./_image/2016-03-27 22-03-08.jpg)

#### 双旋转

2和3是插入发生在内侧的情况，用双旋转处理。因为单旋转只能改变外侧subtree的高度，但无法处理内侧的subtree。双旋转**本质上也是提升（内侧）subtree的高度**。

`Ta < k1 < Tb < k2 < Tc < k3 < Td`

![](./_image/2016-03-27 22-03-51.jpg)

![](./_image/2016-03-27 22-04-19.jpg)

#### 关键点

**如何找到**重新平衡的node，a。

## Hash Map和Hash Table

## 排序

稳定，非稳定

## 查找

# C/C++

## 虚函数

虚函数，纯虚函数，虚析构函数

## static，inline，const

## 多态

## overload和override

## 继承

## 内存对齐

# Operating System

## 死锁条件以及解除

## 调度

## 设备利用率

# Data Base

## Key

# Network

# OSI

# TCP/IP