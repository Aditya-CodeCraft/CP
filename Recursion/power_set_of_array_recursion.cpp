// Question: Given an array of n integers, print all its subsets (the power set) using recursion (e.g. [1,2] -> [], [2], [1], [1 2]).

#include <iostream>
#include <vector>
using namespace std;

void powset(int index, int s, int *arr , vector<vector<int>>&ans , vector<int>curr){
    if(index==s){
        ans.push_back(curr);
        return;
    }
    
    // curr.push_back(arr[index]); //take step  also u can pass curr as reference as u cater both push and out so value preserved is removed also accordingly
    // powset(index+1,s,arr,ans,curr);
    // curr.pop_back(); //undo or backtrack step
    // powset(index+1,s,arr,ans,curr);
    
    powset(index+1,s,arr,ans,curr); // In case u dont want backtrack take without 1st then take whatever u want
    curr.push_back(arr[index]); //yeh last step h call by value iske baad fn ese hi vapas ho jayega toh formal change wont reflect in actual
    powset(index+1,s,arr,ans,curr); // also remember is case me curr cant be reference as u have to pop the element manually ese toh call by value ke vajah se gayab ho ja rha tha
}




int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    vector<int>curr;
    vector<vector<int>>ans;
    powset(0,n,arr,ans,curr);
    cout<<endl;
    
    for(auto vec:ans){
        cout<<"[ ";
        for(auto ele:vec){
            cout<<ele<<" ";
        }   
    cout<<"]"<<endl;
    }    
    return 0;
}
