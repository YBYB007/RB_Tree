#include "RB_Tree.h"

// 初始化根结点
template <class DataType>
RB_Tree<DataType>::RB_Tree(DataType data) : root(std::make_shared<RB_Node<DataType>>(data, BLACK)) {}

// 左旋
template <class DataType>
void RB_Tree<DataType>::left_rotation(std::weak_ptr<RB_Node<DataType>> node)
{
}
// 右旋
template <class DataType>
void RB_Tree<DataType>::right_rotation(std::weak_ptr<RB_Node<DataType>> node)
{
}

// 插入
template <class DataType>
bool RB_Tree<DataType>::insert(DataType data)
{
    if (!root)
    {
        root = std::make_shared<RB_Node<DataType>>(data, BLACK);
    }
    else
    {
        std::weak_ptr<RB_Node<DataType>> node = root;
        for (;;)
        {
            if (node.lock()->data == data)
            {
                return false;
            }
            else if (node.lock()->data > data)
            {
                if (node.lock()->left)
                {
                    node = node.lock()->left;
                }
                else
                {
                    node.lock()->left = std::make_shared<RB_Node<DataType>>(data);
                    node.lock()->left->parent = node.lock();
                    // 插入后进行红色修正
                    // red_fix(node);
                    break;
                }
            }
            else if (node.lock()->data < data)
            {
                if (node.lock()->right)
                {
                    node = node.lock()->right;
                }
                else
                {
                    node.lock()->right = std::make_shared<RB_Node<DataType>>(data);
                    node.lock()->right->parent = node.lock();
                    // 插入后进行红色修正
                    // red_fix(node);
                    break;
                }
            }
        }
    }
    return true;
}
// 双红修正
template <class DataType>
void RB_Tree<DataType>::red_fix(std::weak_ptr<RB_Node<DataType>> node)
{
    std::cout << "修正好了" << std::endl;
}

// 删除
template <class DataType>
bool RB_Tree<DataType>::remove(DataType data)
{
    if (!root)
    {
        return false;
    }
    else
    {
        std::weak_ptr<RB_Node<DataType>> node = root;
        Pos pos = tree_root;
        for (;;)
        {
            if (node.lock()->data == data)
            {
                // 黑色修正
                black_fix(node, pos);
                break;
            }
            else if (node.lock()->data > data)
            {
                if (!node.lock()->left)
                {
                    return false;
                }
                else
                {
                    node = node.lock()->left;
                    pos = left;
                }
            }
            else if (node.lock()->data < data)
            {
                if (!node.lock()->right)
                {
                    return false;
                }
                else
                {
                    node = node.lock()->right;
                    pos = right;
                }
            }
        }
    }
    return true;
}

// 黑色修正
template <class DataType>
void RB_Tree<DataType>::black_fix(std::weak_ptr<RB_Node<DataType>> node, Pos pos)
{
    remove_node(node, pos);
}
// 删除节点
template <class DataType>
void RB_Tree<DataType>::remove_node(std::weak_ptr<RB_Node<DataType>> node, Pos pos)
{
    if (pos == tree_root)
    {
        root.reset();
    }
    else if (pos == left)
    {
        node.lock()->parent.lock()->left.reset();
    }
    else if (pos == right)
    {
        node.lock()->parent.lock()->right.reset();
    }
}

// 输出红黑树
template <class DataType>
void RB_Tree<DataType>::print_tree_pre()
{
    if (root)
    {
        print_tree(this->root, 0);
    }
    else
    {
        std::cout << "The tree is empty." << std::endl;
    }
}
template <class DataType>
void RB_Tree<DataType>::print_tree(std::weak_ptr<RB_Node<DataType>> node, int depth, int flag)
{
    // 打印当前节点的数据
    std::cout << std::string(depth * 2, ' ') << "|_" << "Node(" << node.lock()->data << ", Color: ";
    std::cout << (node.lock()->color == RED ? "RED" : "BLACK") << ")";
    if (flag == 1)
    {
        std::cout << "left" << std::endl;
    }
    else if (flag == 2)
    {
        std::cout << "right" << std::endl;
    }
    else
    {
        std::cout << std::endl;
    }
    // 递归打印左子树
    if (node.lock()->left)
        print_tree(node.lock()->left, depth + 1, 1);

    // 递归打印右子树
    if (node.lock()->right)
        print_tree(node.lock()->right, depth + 1, 2);
}