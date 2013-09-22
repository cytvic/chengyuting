#include <iostream>
using namespace std;
int Fa(int m){
int f;
  if(m==1)
    f=1;
  else
    f=m*Fa(m-1);
  return f;
}
double Combination(int m,int n){
 dpuble c;
  if (m>n)
   return 0;
  else
   c=Fa(n)/Fa(m)/Fa(n-m);
   return c;
}
int main(){
    int m,n;
  cout<<"请输入m="<<endl;
  cout<<"请输入n="<<endl;
  cin>>m>>n;
  cout<<Combination(m,n)<<endl;
return 0;
}
