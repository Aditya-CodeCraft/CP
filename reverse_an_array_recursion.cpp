// Question: Reverse an array.

#include<iostream>
#include<algorithm>
using namespace std;

void reverse(int *arr , int s){
    if(s==0 || s==1)
        return;

    swap(arr[0],arr[s-1]);

    reverse(arr+1,s-2);
}

int main(){
    int arr[]={10,20,30,40,80};
    int s=sizeof(arr)/sizeof(arr[0]);
    reverse(arr,s);
    for(int i=0;i<s;i++)
        cout<<arr[i]<< " ";


    // s-=1;     iterative approach
    // int i=0,j=s;
    // while(i<j){
    //     swap(arr[i++],arr[j--]);
    // }

    // for(int i=0;i<=s;i++)
    //     cout<<arr[i]<< " "
}
