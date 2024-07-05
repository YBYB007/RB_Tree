#pragma once
#include "RB_Node.h"

template <class DataType>
class RB_Tree
{
public:
    RB_Tree() : root(nullptr) {}
    RB_Tree(DataType data);
    ~RB_Tree() {}
    // 左旋
    void left_rotation(std::weak_ptr<RB_Node<DataType>> node);
    // 右旋
    void right_rotation(std::weak_ptr<RB_Node<DataType>> node);
    // 插入
    bool insert(DataType data);
    // 双红修正
    void red_fix(std::weak_ptr<RB_Node<DataType>> node);
    // 删除
    bool remove(DataType data);
    // 黑色修正
    void black_fix(std::weak_ptr<RB_Node<DataType>> node);
    // 输出红黑树
    void print_tree_pre();
    std::shared_ptr<RB_Node<DataType>> root;
private:
   void print_tree(std::weak_ptr<RB_Node<DataType>> node, int depth = 0, int flag = 0);
};
