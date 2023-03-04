#include <iostream>
using namespace std;

int main(){
 int l, r;
 cin >>l>>r;
 int num = 0;
 int temp;
 for (int a = l; a <= r; a++) {
  temp = a;
   while (temp > 1){
    if (temp % 10 == 2)
     num++;
    temp /= 10;
   }
 }
 cout << num << endl;
 return 0;
} 
