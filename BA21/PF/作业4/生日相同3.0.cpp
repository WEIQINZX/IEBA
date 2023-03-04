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
            cout << student[i].month << " " << student[i].day << " " << student[i].name; //如果student[1]和[2]生日是同一天 
        if ((student[i].month != student[i - 1].month || student[i].day != student[i - 1].day) 
		&& student[i].month == student[i + 1].month && student[i].day == student[i + 1].day && i!=1) //如果[i]和前面那个不是同一天生日，但是和后面那个是同一天，且i不是1 
        {
            cout << student[i].month << " " << student[i].day << " " << student[i].name;
        }
        if (student[i].month == student[i - 1].month && student[i].day == student[i - 1].day && student[i].month == student[i + 1].month && student[i].day == student[i + 1].day) //如果[i]和前面那个同一天生日 ，和后面的也是同一天 
            cout << " " << student[i].name;
        if (student[i].month == student[i - 1].month && student[i].day == student[i - 1].day && i!=1&& (student[i].month!=student[i+1].month||student[i].day!=student[i+1].day)){ //如果[i]和前面的同一天生日，和后面的不是同一天 
        	cout << " " << student[i].name;
        	cout<<endl;
        	} 
    }
 
 return 0;
}
