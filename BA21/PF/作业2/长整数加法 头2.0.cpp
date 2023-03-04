#include <iostream>
#include <string.h>
using namespace std;

int main() {
 char strA[100];
 char strB[100];
 int strC[100];
 int carry = 0, sum = 0, numA = 0, numB = 0;
 cin >> strA >> strB;
 int a = strlen(strA);
 int b = strlen(strB);
 int c = min(a, b);
 int k = 0;
 for (int i = 1; i <= c; i++)
 {
  sum = 0;
  numA = strA[a - i] - '0';
  numB = strB[b - i] - '0';
  sum = numA + numB + carry;
  strC[c - i] = sum % 10;
  if (sum >= 10)
   carry = 1;
  else
   carry = 0;
 }
 sum = c;
 if (a > b)
 {
  if (carry == 1)
  {
   while (strA[a - sum - 1] == '9')
   {
    if ((a - sum - 1) == 0)
    {
     sum++;
     cout << '1';
     break;
    }
    sum++;
   }
   if (a - sum - 1 > 0)
   {
    for (int i = 0; i < a - sum - 2; i++)
     cout << strA[i];
    numA = strA[a - c - 1] - '0';
    numA++;
    cout << numA;
   }
   while (sum-c > 0)
   {
    cout << '0';
    sum--;
   }
  }
  else
   cout << strA[a - c - 1];
 }
 if (a < b)
 {
  if (carry == 1)
  {
   while (strB[b - sum - 1] == '9')
   {
    if ((b - sum - 1) == 0)
    {
     sum++;
     cout << '1';
     break;
    }
    sum++;
   }
   if (b - sum - 1 > 0)
   {
    for (int i = 0; i < b - sum - 2; i++)
     cout << strB[i];
    numB = strB[b - c - 1] - '0';
    numB++;
    cout << numB;
   }
   while (sum-c > 0)
   {
    cout << '0';
    sum--;
   }
  }
  else
   cout << strB[b - c - 1];
 }
 if (a == b && sum >= 10)
  cout << '1';
 for (int j = 0; j < c; j++)
 {
  cout << strC[j];
 }
 cout << endl;
 return 0;
}
