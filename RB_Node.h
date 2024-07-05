#pragma once
#include <memory>

enum Color
{
    RED,
    BLACK
};

template <class DataType>
class RB_Node
{
public:
    Color color;
    DataType data;
    std::shared_ptr<RB_Node<DataType>> left;
    std::shared_ptr<RB_Node<DataType>> right;
    std::weak_ptr<RB_Node<DataType>> parent; // 使用weak_ptr避免循环引用

    RB_Node(DataType data, Color color = RED)
        : data(data), color(color), left(nullptr), right(nullptr), parent() {}
};