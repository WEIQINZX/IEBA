#include <iostream>
using namespace std;

bool isPrime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
            return false;
        }
	}
    return true;
}

int main(){
    long long L = 0, U = 0;
    int C1 = 0, C2 = 0, D1 = 0, D2 = 0;
    cin >> L >> U;
    int primelist[100000]={0}; //用于primelist计数
    int num = 0; //记录有多少个prime
    for (int i = L ; i <= U;i++){
        if(isPrime(i)){
            primelist[num++] = i;
        }
    }
    bool yousushu=false;
    if(primelist[1]==0)
    	yousushu=false;
    else
    	yousushu=true;
    
    int max = primelist[1] - primelist[0], min = primelist[1] - primelist[0];
    int maxnum = 0, minnum = 0;
    int maxsum = primelist[0]+primelist[1], minsum = primelist[0]+primelist[1];
    for (int i = 1; i < num-1;i++){
        int differtemp = primelist[i + 1] - primelist[i];
        int sumtemp = primelist[i + 1] + primelist[i];
        if(differtemp>max){
            max = differtemp;
            maxnum = i;
        }
        if(differtemp==max){
            if(sumtemp<maxsum){
                maxsum = sumtemp;
                maxnum = i;
            }
        } //得到是D
        if(differtemp<min){
            min = differtemp;
            minnum = i;
        }
        if(differtemp==min){
            if(sumtemp<minsum){
                minsum = sumtemp;
                minnum = i;
            }
        }//得到是C
    }
	
	if(yousushu){
    D1 = primelist[maxnum];
    D2 = primelist[maxnum + 1];
    C1 = primelist[minnum];
    C2 = primelist[minnum + 1];
    cout << C1 <<" "<< C2 << endl;
    cout << D1 << " "<<D2 << endl;
	}
	else
		cout<<-1<<endl;

    return 0;
}
