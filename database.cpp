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
 cout<<"---------------�˵�-----------------"<<endl;
cout<<"1)�鿴ѧ������"<<endl;
cout<<"2)ѡ��"<<endl;
cout<<"3)��ѡ"<<endl;
cout<<"4)¼��ɼ�"<<endl;
cout<<"5)�˳�����"<<endl;
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
cout<<"�������˴���Ĳ˵�ѡ�������ѡ��"<<endl;
}
}while(1);
}

void list(){
cout<<"---------����----------"<<endl;
cout<<"����\t"<<""<<"ѧ��\t"<<"�ɼ�"<<endl;
for(int i=0;i<studentCount;i++){
    cout<<students[i].name<<"\t"<<students[i].number<<"\t"<<students[i].grade<<endl;
    }
 cout<<"----------����----------"<<endl;
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
    cout<<"�������"<<endl;
}else{
     for(int j=i;j<studentCount-1;j++)
		{
			while((students[j].name[k++]=students[j+1].name[k++])!='\0');//������name�ɺ���ǰ���룬����������'\0'һ������ǰ����
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
		cout<<"�������"<<endl;
	}else{
		cout<<"�ɼ���";
		cin>>student.grade;
		students[i].grade = student.grade;
	}
}
void input(struct Student &student){
    cout<<"������";
    cin>>student.name;
    cout<<"ѧ�ţ�";
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
