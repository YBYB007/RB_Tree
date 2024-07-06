#pragma once
#include "RB_Node.h"

enum Pos
{
    tree_root,
    left,
    right
};

template <class DataType>
class RB_Tree
{
public:
    RB_Tree() : root(nullptr) {}
    RB_Tree(DataType data);
    ~RB_Tree() {}
    // 插入
    bool insert(DataType data);
    // 删除
    bool remove(DataType data);
    // 输出红黑树
    void print_tree_pre();
    std::shared_ptr<RB_Node<DataType>> root;

private:
    // 打印完整的树
    void print_tree(std::weak_ptr<RB_Node<DataType>> node, int depth = 0, Pos pos=tree_root);
    // 左旋
    void left_rotation(std::weak_ptr<RB_Node<DataType>> node);
    // 右旋
    void right_rotation(std::weak_ptr<RB_Node<DataType>> node);
    // 双红修正
    void red_fix(std::weak_ptr<RB_Node<DataType>> node, Pos pos);
    // 黑色修正
    void black_fix(std::weak_ptr<RB_Node<DataType>> node, Pos pos);
    // 删除节点
    void remove_node(std::weak_ptr<RB_Node<DataType>> node, Pos pos);
};
