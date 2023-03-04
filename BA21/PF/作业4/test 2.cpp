#include <iostream>
using namespace std;

struct whatever{
	int x;
	int y;
};

whatever test(whatever a,whatever b){
	whatever c;
	c.x=a.x+b.x;
	c.y=a.y+b.y;
	return c;
}

int main(){
	whatever what1;
	whatever what2;
	cin>>what1.x>>what1.y;
	cin>>what2.x>>what2.y;
	
	whatever what3=test(what1,what2);
	cout<<what3.x<<" "<<what3.y<<endl;
	return 0;
} 
