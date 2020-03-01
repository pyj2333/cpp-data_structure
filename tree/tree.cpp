#include <string>


typedef struct TreeNode
{
    char data;
    TreeNode* lctree;
    TreeNode* rctree;
}tree, *ptree;

//ptree指向根节点的指针
ptree pre_cre();//前序创建法1
void  pre_cre(ptree*);//前序创建法2
void in_cre(ptree*);//中序创建
void pos_cre(ptree*);//后序创建
void pre_tra(ptree);//前序遍历
void in_tra(ptree);//中序遍历
void pos_tra(ptree);//后序遍历


ptree pre_cre(){
     char ch;
     printf("输入先序遍历的节点:");
     scanf("%c",&ch);
     getchar();//清除缓冲区的内容
     if(ch == '0'){
         return nullptr;
     }
     ptree root  = new tree;
     root -> data = ch;
     root -> lctree = pre_cre();
     root -> rctree = pre_cre();
     return root;
}


void pre_cre(ptree* proot){//此时root为空，我们只讨论从零开始创建
     char ch;
     printf("输入先序遍历的节点:");
     scanf("%c",&ch);
     getchar();
     if(ch == '0'){
         *proot = nullptr;}
    else{
     //创建根节点
     //tree node = {d,nullptr,nullptr};
     //*proot = &node;
     //严重错误，绝对不要在函数内部静态创建变量，等函数结束后再去用指针访问这个变量。
     *proot = new tree;
     (*proot) -> data = ch;
     //创建左子树
     pre_cre(&(*proot) -> lctree);
     //创建右子树
     pre_cre(&(*proot) -> rctree);}
}

 
void in_cre(ptree* proot){
return;
}

void pos_cre(ptree* proot){
return;
}


void pro_tra(ptree root){
    if(root == nullptr)return;
    printf("%c\n",root -> data);
    pro_tra(root ->lctree);
    pro_tra(root ->rctree);
    return;
}


void in_tra(ptree root){
    if (root == nullptr)return;
    pro_tra(root ->lctree);
    printf("%c\n",root -> data);
    pro_tra(root ->rctree);
}

void pos_tra(ptree root){
if (root == nullptr)return;
    pro_tra(root ->lctree);
    pro_tra(root ->rctree);
    printf("%c\n",root -> data);
}


int main(){
    /*错误,编译器只是为二级指针分配内存，一级指针没有分配
    ptree* proot;
    pro_cre(proot);
   ptree proot;
   proot = pro_cre();
   pro_tra(proot);
    */
   ptree proot;
   pre_cre(&proot);
   pre_tra(proot); 
}
