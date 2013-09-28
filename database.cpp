#include <iostream>
#include <cstring>
using namespace std;
struct Student{
    char name[50];
    int number;
    float grade;
}students[100];
int studentCount=0;
void list();
void chooseCourse();
void tuiXuan();
void addscore();
void input(struct Student &student);
int find(char*name);
int main(){
int action;
  do{
 cout<<"---------------菜单-----------------"<<endl;
cout<<"1)查看学生名单"<<endl;
cout<<"2)选课"<<endl;
cout<<"3)退选"<<endl;
cout<<"4)录入成绩"<<endl;
cout<<"5)退出程序"<<endl;
cin>>action;
switch(action){
case 1:
list(); break;
case 2:
chooseCourse(); break;
case 3:
tuiXuan(); break;
case  4:
addscore();break;
case 5:
return 0;
default:
cout<<"你输入了错误的菜单选项，请重新选择！"<<endl;
}
}while(1);
}

void list(){
cout<<"---------名单----------"<<endl;
cout<<"姓名\t"<<""<<"学号\t"<<"成绩"<<endl;
for(int i=0;i<studentCount;i++){
    cout<<students[i].name<<"\t"<<students[i].number<<"\t"<<students[i].grade<<endl;
    }
 cout<<"----------名单----------"<<endl;
}
void chooseCourse(){
    struct Student student;
    input(student);
    int i=find(student.name);
    if(i==studentCount){
        strcpy(students[i].name,student.name);
        students[i].number=student.number;
        studentCount++;
    }
}
void tuiXuan(){
struct Student student;
input(student);
int j,k=0;
int i=find(student.name);
if(i==studentCount){
    cout<<"输入错误"<<endl;
}else{
     for(int j=i;j<studentCount-1;j++)
		{
			while((students[j].name[k++]=students[j+1].name[k++])!='\0');//将数组name由后向前出入，并将后数组'\0'一并传入前数组
			students[j].number=students[j+1].number;
			students[j].grade=students[j+1].grade;
}
        studentCount--;
}
}
void addscore(){
struct Student student;
	input(student);
	int i = find(student.name);
	if(i == studentCount){
		cout<<"输入错误！"<<endl;
	}else{
		cout<<"成绩：";
		cin>>student.grade;
		students[i].grade = student.grade;
	}
}
void input(struct Student &student){
    cout<<"姓名：";
    cin>>student.name;
    cout<<"学号：";
    cin>>student.number;

}
int find(char*name){
int i;
for(i=0;i<studentCount;i++){
    if(strcmp(students[i].name,name)==0){
        break;
    }
}
 return i;
}
