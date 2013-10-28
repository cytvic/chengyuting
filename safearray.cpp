#include "stdafx.h"
#include <iostream>
using namespace std;
class safearray{
private:
public:
      int length;
    int *array;
     safearray(int n);
    ~safearray();
    void setarray(int pos,int value);
    int getarray(int pos);
    bool isSafe(int pos);
};
bool safearray::isSafe(int pos){
  return (pos>=0&&pos<=this->length);
}
safearray::~safearray(){
        delete array;
};
safearray::safearray(int n){
    this->array=new int[n-1];
    this->length=n;
}
void safearray::setarray(int pos,int value){
if(this->isSafe(pos)){
                this->array[pos]=value;       //输入数组
        }else
        {
                cout<<"你的下标越界"<<endl;
        }
}
int safearray::getarray(int pos){
if(this->isSafe(pos)){
                cout<<this->array[pos]<<endl;
                return(this->array[pos]);
        }else
        {
                cout<<"输入的下标错误"<<endl;
                return 0;
        }
}
int main(){
        int number,index;
        safearray a(2);
        cout<<a.length<<endl;
        cout<<"请输入数"<<endl;
        for(int i=0;i<3;i++){
        cin>>number>>index;
        a.setarray(number,index);
        }
    a.getarray(1);
        cout<<endl;
        a.getarray(7);
        return 0;
}







