#include <iostream>
 using namespace std;

int main() 
{
 int N = 0, M = 0;
 int left[1001], right[1001];
 cin >> N;
 int max = 0;
 for (int i = 0; i < N; i++)
 {
  cin >> left[i] >> right[i];
  if (right[i] > max)
   max = right[i];
 } //找最大值 
 bool math[max]; //100000改成max
 for (int i = 0; i < max; i++)
  math[i] = false;  //把math初始化为假 
 for (int i = 0; i < N; i++)
 {
  for (int j = left[i]; j < right[i]; j++)
  {
   math[j] = true;
  }
 }
 int num = 0;
 for (int i = 0; i < max; i++)
 {
  if (math[i])  //这个算法其实算是carry version，但是我的数据范围是int，所以我开不出足够大的数组 
   num++;  //会超出的 
 }
 cout << num << endl;
 return 0;
}
