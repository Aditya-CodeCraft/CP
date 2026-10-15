#include <iostream>
using namespace std;

int recur(int *p,int s){
    if(s==0)
        return 0;
    if(s==1)
        return p[0];
    
    return p[0]+recur(p+1,s-1);
}

int main()
{
    int arr[]={10,20,30,40};
    int size= sizeof(arr)/sizeof(arr[0]);
    cout<<"sum is:"<<recur(arr,size);
    return 0;
}
