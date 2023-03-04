#include <iostream>
#include <math.h>

using namespace std;
int divisor(int a,int b)
{
	if(a%b!=0)
		return divisor(b,a%b);
	else
		return b;
}
int main() 
{
	int times=0;
    cin >> times;
	int data[times][2010]={0};
	int num[times]={0};
    int max=0;
    int nums=0;
    for(int i=0;i<times;i++)
    {
    	cin>>num[i];
    	for(int j=0;j<num[i];j++)
    		cin>>data[i][j];
    }
    for(int i=0;i<times;i++)
    {
    	max=0;
    	for(int k=0;k<num[i];k++)
    		for(int j=k+1;j<num[i];j++)
    		{
    			nums=divisor(data[i][k],data[i][j]);
    			if(nums>max)
    				max=nums;
			}
		cout<<max<<endl;
	}
	return 0;
}
