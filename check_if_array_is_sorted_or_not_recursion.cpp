// Question: Check whether an array is sorted or not.

#include<iostream>
using namespace std;

bool is_sorted(int *arr , int s){
    if(s==0 || s==1)
        return true;

    if(arr[0]>arr[1]) //vimp check always use checks on failing condition
        return false;

    return is_sorted(arr+1,s-1);
}

int main(){
    int arr[]={10,20,20};
    int s=sizeof(arr)/sizeof(arr[0]);
    if(is_sorted(arr,s))
        cout<<"array is sorted";
    else
        cout<<"array is unsorted";

}
