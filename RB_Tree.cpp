#include "RB_Tree.h"

// 初始化根结点
template <class DataType>
RB_Tree<DataType>::RB_Tree(DataType data) : root(std::make_shared<RB_Node<DataType>>(data, BLACK)) {}

// 左旋
template <class DataType>
void RB_Tree<DataType>::left_rotation(std::weak_ptr<RB_Node<DataType>> node)
{
    std::weak_ptr<RB_Node<DataType>> right_node = node.lock()->right;
    // 根节点
    bool root_node = false;
    if (node.lock() == this->root)
    {
        root_node = true;
    }

    // 右侧左孩子
    if (right_node.lock()->left)
    {
        std::shared_ptr<RB_Node<DataType>> left_gson_node = right_node.lock()->left;
        if (!root_node)
        {
            std::weak_ptr<RB_Node<DataType>> parent = node.lock()->parent.lock();
            right_node.lock()->left = node.lock();
            if (parent.lock()->left && parent.lock()->left == node.lock())
            {
                parent.lock()->left = right_node.lock();
            }
            else
            {
                parent.lock()->right = right_node.lock();
            }
            node.lock()->right = std::move(left_gson_node);
            node.lock()->parent = right_node.lock();
            node.lock()->right->parent = node.lock();
            right_node.lock()->parent = parent.lock();
        }
        else
        {
            right_node.lock()->left = node.lock();
            this->root = right_node.lock();
            node.lock()->right = std::move(left_gson_node);
            node.lock()->parent = right_node.lock();
            node.lock()->right->parent = node.lock();
            right_node.lock()->parent.reset();
        }
    }
    else
    {
        if (!root_node)
        {
            std::weak_ptr<RB_Node<DataType>> parent = node.lock()->parent.lock();
            right_node.lock()->left = node.lock();
            if (parent.lock()->left && parent.lock()->left == node.lock())
            {
                parent.lock()->left = right_node.lock();
            }
            else
            {
                parent.lock()->right = right_node.lock();
            }
            node.lock()->right = nullptr;
            node.lock()->parent = right_node.lock();
            right_node.lock()->parent = parent.lock();
        }
        else
        {
            right_node.lock()->left = node.lock();
            this->root = right_node.lock();
            node.lock()->right = nullptr;
            node.lock()->parent = right_node.lock();
            right_node.lock()->parent.reset();
        }
    }
}
// 右旋
template <class DataType>
void RB_Tree<DataType>::right_rotation(std::weak_ptr<RB_Node<DataType>> node)
{
   std::weak_ptr<RB_Node<DataType>> left_node = node.lock()->left;
    // 根节点
    bool root_node = false;
    if (node.lock() == this->root)
    {
        root_node = true;
    }

    // 左侧右孩子
    if (left_node.lock()->right)
    {
        std::shared_ptr<RB_Node<DataType>> right_gson_node = left_node.lock()->right;
        if (!root_node)
        {
            std::weak_ptr<RB_Node<DataType>> parent = node.lock()->parent.lock();
            left_node.lock()->right = node.lock();
            if (parent.lock()->left && parent.lock()->left == node.lock())
            {
                parent.lock()->left = left_node.lock();
            }
            else
            {
                parent.lock()->right = left_node.lock();
            }
            node.lock()->left = std::move(right_gson_node);
            node.lock()->parent = left_node.lock();
            node.lock()->left->parent = node.lock();
            left_node.lock()->parent = parent.lock();
        }
        else
        {
            left_node.lock()->right = node.lock();
            this->root = left_node.lock();
            node.lock()->left = std::move(right_gson_node);
            node.lock()->parent = left_node.lock();
            node.lock()->left->parent = node.lock();
            left_node.lock()->parent.reset();
        }
    }
    else
    {
        if (!root_node)
        {
            std::weak_ptr<RB_Node<DataType>> parent = node.lock()->parent.lock();
            left_node.lock()->right = node.lock();
            if (parent.lock()->left && parent.lock()->left == node.lock())
            {
                parent.lock()->left = left_node.lock();
            }
            else
            {
                parent.lock()->right = left_node.lock();
            }
            node.lock()->left = nullptr;
            node.lock()->parent = left_node.lock();
            left_node.lock()->parent = parent.lock();
        }
        else
        {
            left_node.lock()->right = node.lock();
            this->root = left_node.lock();
            node.lock()->left = nullptr;
            node.lock()->parent = left_node.lock();
            left_node.lock()->parent.reset();
        }
    }
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
        Pos pos = tree_root;
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
                    pos = left;
                }
                else
                {
                    node.lock()->left = std::make_shared<RB_Node<DataType>>(data);
                    node.lock()->left->parent = node.lock();
                    node = node.lock()->left;
                    pos = left;
                    // 插入后进行红色修正
                    red_fix(node.lock(), pos);
                    break;
                }
            }
            else if (node.lock()->data < data)
            {
                if (node.lock()->right)
                {
                    node = node.lock()->right;
                    pos = right;
                }
                else
                {
                    node.lock()->right = std::make_shared<RB_Node<DataType>>(data);
                    node.lock()->right->parent = node.lock();
                    node = node.lock()->right;
                    pos = right;
                    // 插入后进行红色修正
                    red_fix(node, pos);
                    break;
                }
            }
        }
    }
    return true;
}

// 双红修正
template <class DataType>
void RB_Tree<DataType>::red_fix(std::weak_ptr<RB_Node<DataType>> node, Pos pos)
{

    std::weak_ptr<RB_Node<DataType>> parent = node.lock()->parent;
    // 如果父节点是黑色的，那么不会影响黑路同的性质，因为从上到下的所有黑路同的数量不会变。
    // 如果父节点是红色的，那么节点一定是插入到一个红色叶子节点上去了，没有兄弟节点存在,此时肯定还有父节点的存在。
    if (parent.lock()->color == RED)
    {
        // 红色修正
        // 1、如果是叔叔节点是红色，直接黑色下移（黑红红变为红黑红），然后切换为最高结点，再次判断。
        // 此时一定有祖父节点
        std::weak_ptr<RB_Node<DataType>> grand_parent = parent.lock()->parent;
        // 如果左右均存在且都为红色，直接变色
        if (grand_parent.lock()->right && grand_parent.lock()->left && grand_parent.lock()->right->color == RED && grand_parent.lock()->left->color == RED)
        {
            grand_parent.lock()->color = RED;
            grand_parent.lock()->left->color = BLACK;
            grand_parent.lock()->right->color = BLACK;
            node = grand_parent.lock();
            // 如果切换到根节点，那么直接染黑就行了，结束调整，这是树增高的唯一方法。
            if (node.lock()->parent.expired())
            {
                node.lock()->color = BLACK;
            }
            else if (node.lock()->parent.lock()->left == node.lock())
            {
                red_fix(node, left);
            }
            else if (node.lock()->parent.lock()->right == node.lock())
            {
                red_fix(node, right);
            }
        }

        // 2、如果是叔叔结点是黑色或者不存在，那么为了不破坏黑路同的性质，需要将这个叉上的一个红节点，旋到另一叉树上去。
        else
        {
            // LL: 祖父与父换色 祖父右旋
            if (grand_parent.lock()->left == parent.lock() && pos == left)
            {
                grand_parent.lock()->color = RED;
                parent.lock()->color = BLACK;
                right_rotation(grand_parent);
            }

            // LR：与祖父换色，先左旋父节点，再右旋祖父节点
            else if (grand_parent.lock()->left == parent.lock() && pos == right)
            {
                grand_parent.lock()->color = RED;
                node.lock()->color = BLACK;
                left_rotation(parent);
                right_rotation(grand_parent);
            }
            // RL：与祖父换色，先右旋父节点，再左旋祖父节点
            else if (grand_parent.lock()->right == parent.lock() && pos == left)
            {
                grand_parent.lock()->color = RED;
                node.lock()->color = BLACK;
                right_rotation(parent);
                left_rotation(grand_parent);
            }
            // RR：祖父与父换色 祖父左旋
            else if (grand_parent.lock()->right == parent.lock() && pos == right)
            {
                grand_parent.lock()->color = RED;
                parent.lock()->color = BLACK;
                left_rotation(grand_parent);
            }
        }
    }
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

    // 1. 删除的是叶子节点，直接删除就可以了。如果删除的红节点，结束。如果删除的是黑节点，这是最为复杂的一种情况，因为这条路上已经没有可以补充的黑节点，需要改变其他路的黑节点数量。将这个节点变为双黑节点，最后将其调整为单黑节点。
    //    1. 如果它的兄弟是黑色
    //       1. 如果它左孩子是红色，让孩子结点染成父节点的颜色，父节点染成祖父节点的颜色，LL旋转调节，双黑恢复为单黑，就调整好了（RR类似）。
    //       2. 如果它的右孩子是红色，那么直接将其染成祖父的颜色，祖父变黑，然后LR旋转，需要先旋转祖父节点的左孩子，然后再旋转祖父节点，就调整好了（RL类似）。
    //    2. 如果兄弟的孩子都是黑色或者没有孩子， 直接将兄弟染红，然后恢复更大的树，将双黑结点上移为父节点，调整父节点。
    //       1. 如果父节点是红色，那么直接变为黑色就修复好了。
    //       2. 如果父节点是黑色，那么还需要继续看他的兄弟节点。
    //       3. 如果是根结点，并不会破坏黑路同性质，就调整好了。
    //    3. 如果它的兄弟是红色，直接将兄弟和父节点颜色交换，然后继续看他的兄弟节点。
    // 2. 如果只有左孩子或者右孩子，直接代替即可。颜色修正，这种情况只能是一黑一红，不可能是其他情况，也就是说红色节点不可能只有左子树或者右子树，不然就违反了红黑树的性质。删除这个黑结点，让孩子替换过来，这时候这条路径会少一个黑节点，将代替过来的红结点染黑就可以了。
    // 3. 如果都有，那么就它的直接前驱或者直接后继替换它，然后继续判断直接前驱或后继，最终转化为1或2的情况。
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
        print_tree(this->root, 0, tree_root);
    }
    else
    {
        std::cout << "The tree is empty." << std::endl;
    }
}
template <class DataType>
void RB_Tree<DataType>::print_tree(std::weak_ptr<RB_Node<DataType>> node, int depth, Pos pos)
{
    // 打印当前节点的数据
    std::cout << std::string(depth * 2, ' ') << "|_" << "Node(" << node.lock()->data << ", Color: ";
    std::cout << (node.lock()->color == RED ? "RED" : "BLACK") << ")";
    if (pos == tree_root)
    {
        std::cout << "root" << std::endl;
    }
    else if (pos == left)
    {
        std::cout << "left" << std::endl;
    }
    else if (pos == right)
    {
        std::cout << "right" << std::endl;
    }
    else
    {
        std::cout << std::endl;
    }
    // 递归打印左子树
    if (node.lock()->left)
        print_tree(node.lock()->left, depth + 1, left);

    // 递归打印右子树
    if (node.lock()->right)
        print_tree(node.lock()->right, depth + 1, right);
}