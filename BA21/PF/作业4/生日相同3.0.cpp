#include <iostream>
using namespace std;

struct person{
 char name[21];
 int month;
 int day;
};

int main(){
 int N=0;
 cin>>N;
 person student[102];
 for (int i=1;i<=N;i++){
  cin>>student[i].name>>student[i].month>>student[i].day;
 }
 
 student[0].month=0;
 student[0].day=0;
 student[N+1].month=13;
 student[N+1].day=32;
 
 person q;
 for (int k=1;k<=N;k++){
  for (int i=1;i<=N;i++){
   if(student[i].month>student[i+1].month){
    q=student[i];
    student[i]=student[i+1];
    student[i+1]=q;
   }
  }
 }
 for (int k=1;k<=N;k++){
  for(int i=1;i<=N;i++){
   if(student[i].month==student[i+1].month && student[i].day>student[i+1].day){
    q=student[i];
    student[i]=student[i+1];
    student[i+1]=q;
   }
  }
 }
 
    for (int i = 1; i <= N; i++) 
    {
        if (i == 1&&student[1].month==student[2].month && student[1].day==student[2].day)
            cout << student[i].month << " " << student[i].day << " " << student[i].name; //���student[1]��[2]������ͬһ�� 
        if ((student[i].month != student[i - 1].month || student[i].day != student[i - 1].day) 
		&& student[i].month == student[i + 1].month && student[i].day == student[i + 1].day && i!=1) //���[i]��ǰ���Ǹ�����ͬһ�����գ����Ǻͺ����Ǹ���ͬһ�죬��i����1 
        {
            cout << student[i].month << " " << student[i].day << " " << student[i].name;
        }
        if (student[i].month == student[i - 1].month && student[i].day == student[i - 1].day && student[i].month == student[i + 1].month && student[i].day == student[i + 1].day) //���[i]��ǰ���Ǹ�ͬһ������ ���ͺ����Ҳ��ͬһ�� 
            cout << " " << student[i].name;
        if (student[i].month == student[i - 1].month && student[i].day == student[i - 1].day && i!=1&& (student[i].month!=student[i+1].month||student[i].day!=student[i+1].day)){ //���[i]��ǰ���ͬһ�����գ��ͺ���Ĳ���ͬһ�� 
        	cout << " " << student[i].name;
        	cout<<endl;
        	} 
    }
 
 return 0;
}
