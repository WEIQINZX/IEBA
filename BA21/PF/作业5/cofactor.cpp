#include <iostream>
int num[6][6]={0};
int line = 0;
using namespace std;
int gottimes(int y,int x[])
{
	int result=0;
	if (y==line-1)
		for(int i=0;i<line;i++)
			if(x[i]==0)
				return num[line-1][i];
	int i=0;
	int xi=0;		
	while(i<line)
	{
		if(x[i]==0)
		{
			x[i]=1;
			xi+=1;
			if(xi%2==1)
				result+=num[y][i]*gottimes(y+1,x);
			else
				result-=num[y][i]*gottimes(y+1,x);
			x[i]=0;
		}
		i++;
	}
	return result;
}

int main() 
{
    cin >> line;
    int x[line]={0};  //用于记录删掉了哪些列，1=已经删掉，0=还未删 
    for (int i = 0; i < line; i++)
        for (int j = 0; j < line; j++)
            cin >> num[i][j];
    cout << gottimes(0,x) << endl;
    return 0;
}
