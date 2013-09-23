#include <iostream>
using namespace std;
double power(double x,int y){
   if(y=0)
    return 1.0;
   else
    return power(x,y-1)*x;
}
int main(){
    double x;
    int y;
    cout<<"请依次输入x,y"<<endl;
    cin>>x>>y;
    cout<<power(x,y)<<endl;
return 0;
}
