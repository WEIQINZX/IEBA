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
 } //�����ֵ 
 bool math[max]; //100000�ĳ�max
 for (int i = 0; i < max; i++)
  math[i] = false;  //��math��ʼ��Ϊ�� 
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
  if (math[i])  //����㷨��ʵ����carry version�������ҵ����ݷ�Χ��int�������ҿ������㹻������� 
   num++;  //�ᳬ���� 
 }
 cout << num << endl;
 return 0;
}
