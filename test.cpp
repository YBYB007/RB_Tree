#include "iostream"
#include "RB_Tree.cpp"
void red_test(){
    RB_Tree<int> T1;
    if(T1.root==nullptr){
         std::cout<<"empty"<<std::endl;
     }
     else{
         std::cout<<T1.root->data<<" "<<T1.root->color<<std::endl;
    }
    T1.insert(17);
    T1.print_tree_pre();
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
    T1.insert(18); 
    T1.print_tree_pre(); 
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
    T1.insert(23);
    T1.print_tree_pre();
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
    T1.insert(34);
    T1.print_tree_pre();
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
    T1.insert(27);
    T1.print_tree_pre();
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
    T1.insert(15);
    T1.print_tree_pre();
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
    T1.insert(9);
    T1.print_tree_pre();
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
    T1.insert(6);
    T1.print_tree_pre();
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
    T1.insert(8);
    T1.print_tree_pre();
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
    T1.insert(5);
    T1.print_tree_pre();
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
    T1.insert(25);   
    T1.print_tree_pre(); 
    std::cout<<"----------------------------------------------------------------------"<<std::endl;
}
/*
// 测试案例
empty
|_Node(17, Color: BLACK)root
----------------------------------------------------------------------
|_Node(17, Color: BLACK)root
  |_Node(18, Color: RED)right
----------------------------------------------------------------------
|_Node(18, Color: BLACK)root
  |_Node(17, Color: RED)left
  |_Node(23, Color: RED)right
----------------------------------------------------------------------
|_Node(18, Color: BLACK)root
  |_Node(17, Color: BLACK)left
  |_Node(23, Color: BLACK)right
    |_Node(34, Color: RED)right
----------------------------------------------------------------------
|_Node(18, Color: BLACK)root
  |_Node(17, Color: BLACK)left
  |_Node(27, Color: BLACK)right
    |_Node(23, Color: RED)left
    |_Node(34, Color: RED)right
----------------------------------------------------------------------
|_Node(18, Color: BLACK)root
  |_Node(17, Color: BLACK)left
    |_Node(15, Color: RED)left
  |_Node(27, Color: BLACK)right
    |_Node(23, Color: RED)left
    |_Node(34, Color: RED)right
----------------------------------------------------------------------
|_Node(18, Color: BLACK)root
  |_Node(15, Color: BLACK)left
    |_Node(9, Color: RED)left
    |_Node(17, Color: RED)right
  |_Node(27, Color: BLACK)right
    |_Node(23, Color: RED)left
    |_Node(34, Color: RED)right
----------------------------------------------------------------------
|_Node(18, Color: BLACK)root
  |_Node(15, Color: RED)left
    |_Node(9, Color: BLACK)left
      |_Node(6, Color: RED)left
    |_Node(17, Color: BLACK)right
  |_Node(27, Color: BLACK)right
    |_Node(23, Color: RED)left
    |_Node(34, Color: RED)right
----------------------------------------------------------------------
|_Node(18, Color: BLACK)root
  |_Node(15, Color: RED)left
    |_Node(8, Color: BLACK)left
      |_Node(6, Color: RED)left
      |_Node(9, Color: RED)right
    |_Node(17, Color: BLACK)right
  |_Node(27, Color: BLACK)right
    |_Node(23, Color: RED)left
    |_Node(34, Color: RED)right
----------------------------------------------------------------------
|_Node(15, Color: BLACK)root
  |_Node(8, Color: RED)left
    |_Node(6, Color: BLACK)left
      |_Node(5, Color: RED)left
    |_Node(9, Color: BLACK)right
  |_Node(18, Color: RED)right
    |_Node(17, Color: BLACK)left
    |_Node(27, Color: BLACK)right
      |_Node(23, Color: RED)left
      |_Node(34, Color: RED)right
----------------------------------------------------------------------
|_Node(15, Color: BLACK)root
  |_Node(8, Color: BLACK)left
    |_Node(6, Color: BLACK)left
      |_Node(5, Color: RED)left
    |_Node(9, Color: BLACK)right
  |_Node(18, Color: BLACK)right
    |_Node(17, Color: BLACK)left
    |_Node(27, Color: RED)right
      |_Node(23, Color: BLACK)left
        |_Node(25, Color: RED)right
      |_Node(34, Color: BLACK)right
----------------------------------------------------------------------
*/