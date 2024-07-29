#include<iostream>

using namespace std;

// 二叉树部分
typedef struct
{
   int data;//根节点的值
   TreeNode* left;//左子树
   TreeNode* right;//右子树
}TreeNode;


// 队列部分(不带头节点)
typedef struct 
{
   TreeNode* data;//数据域
   Qnode* next;//指针域
}Qnode;

typedef struct 
{
   Qnode* front;//头节点
   Qnode *rear;//尾节点
}Queue;
void Qinit(Queue* Q){
   Q->front = nullptr;
   Q->rear = nullptr;
}
bool Qempty(Queue* const Q){//const确保队列不被修改
   return Q->front==nullptr? true:false;//空队返回true否则为false
}
void Qpush(Queue* Q,TreeNode* const T){//const确保了树的节点不被修改
   Qnode *newNode = new Qnode;
   newNode->data = T;
   newNode->next = nullptr;
   if (Qempty(Q)){//队空时入队头节点就是尾节点就是新节点
      Q->front = newNode;
      Q->rear = newNode;
   }
   else{
      Q->rear->next = newNode;
      Q->rear = newNode;
   }
}

TreeNode* Qpop(Queue* Q){
   if (Qempty(Q)){
      cout << "队空，出队失败" << endl;
      exit(1);
   }
   Qnode *tempNode = Q->front;
   TreeNode *retTree = tempNode->data;
   Q->front = tempNode->next;
   delete tempNode;
   if (Q->front==nullptr){//如果出队后队为空则rear指针成为了野指针需要重新赋值
      Q->rear = nullptr;
   }
   return retTree;
}

// 层序遍历
void dfs(TreeNode* T){
   if (T==nullptr){
      return;
   }
   Queue *Q = new Queue;
   Qinit(Q);
   Qpush(Q, T);
   while (Qempty(Q)==false){
      
   }
   
}


int main(){

}