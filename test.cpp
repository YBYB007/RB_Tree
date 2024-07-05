#include "iostream"
#include "RB_Tree.cpp"
void test1(){
    RB_Tree<int> T1(123);
    if(T1.root==nullptr){
         std::cout<<"yes"<<std::endl;
     }
     else{
         std::cout<<T1.root->data<<" "<<T1.root->color<<std::endl;
    }
    T1.insert(12);
    T1.insert(13);
    T1.insert(1234);
    T1.insert(123);    
    T1.print_tree_pre();
}