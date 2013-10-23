#include <stdafx.h>
#include <iostream>
using  namespace std;
class Stack{
private:
    class Node{
public:
    Node *next;
    Node (int a,Node *p):data(a),next(p){};
    int data;
}*node;
public :
    void push(int item);
    int pop();
    bool isEmpty();
    ~Stack();
};
Stack::~Stack(){
    while(node){
        Node *p=node;   //循环释放栈节点空间
       node= node->next;
        delete(p);
    }
}
void Stack::push(int item){
    node=new Node(item,node);
}
int Stack::pop(){
  int a=node->data;
  Node *p=node;
  node=p->next;
  delete p;
  return a;
}
bool Stack::isEmpty(){
 return node==NULL;
 }
int main(){
	Stack linkstack;
	linkstack.push(7);
	linkstack.push(8);
	linkstack.push(12);
	while (!linkstack.isEmpty())
	{
		cout<<linkstack.pop()<<endl;
	 };
	return 0;

}





