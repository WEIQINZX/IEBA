#include <iostream>
using namespace std;

int main(){
    int xtemp=0,ytemp=0,xmax=0,xmin=0,ymax=0,ymin=0;
    int N=0;
    int xlength=0,ylength=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>xtemp>>ytemp;
        if(xtemp>xmax)
            xmax=xtemp;
        if(xtemp<xmin)
            xmin=xtemp;
        if(ytemp>ymax)
            ymax=ytemp;
        if(ytemp<ymin)
            ymin=ytemp;
    }
    xlength=xmax-xmin;
    ylength=ymax-ymin;
    if(xlength>ylength)
        cout<<xlength<<endl;
    else
        cout<<ylength<<endl;
    return 0;
}
