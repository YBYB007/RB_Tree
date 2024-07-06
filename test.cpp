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