#include <iostream>
 using namespace std;

int main() 
{
 int N = 0, M = 0;
 cin >> N >> M;
 int factor[N+1][M+1];
 int b[N + 1][M + 1];
 for (int i = 0; i <= N; i++) 
 {
  for (int j = 0; j <= M; j++)
  {
   if (i == 0 || j == 0)
    factor[i][j] = 0;
   else
    cin >> factor[i][j];
   b[i][j] = 0;  //��b��ʼ��Ϊ0 
  }
 }
 
 for (int i = 1; i <= N; i++)
 {  //�ӵ�һ�п�ʼŲ 
  for (int j = 1; j <= M; j++) 
  {  //�ӵ�һ�п�ʼŲ 
   b[i][j] = factor[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
  }
 }
 
 int profit = 0;
 int max = factor[0][0];
 int min = 0;
 for (int r1 = 1; r1 <= N; r1++)
 { 
  for (int c1 = 1; c1 <= M; c1++)
  {  
   min = 0;
   profit = b[r1][c1];
   for (int r2 = 0; r2 < r1; r2++)
   {  
    for (int c2 = 0; c2 < c1; c2++)
    {     
     if (min > (b[r1][c2] + b[r2][c1] - b[r2][c2]))
      min = (b[r1][c2] + b[r2][c1] - b[r2][c2]);
    }
   }
   profit -= min;
   if (profit > max)
    max = profit;
  }
 }
 cout << max << endl;
 return 0;
}
