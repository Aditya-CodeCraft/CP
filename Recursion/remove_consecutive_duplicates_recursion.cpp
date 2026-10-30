// Question: Remove consecutive duplicate characters from a string using recursion (e.g. "aabccba" -> "abcba").

#include<iostream>
#include<string.h>
using namespace std;

void continuous_duplic_removal(char *input){
    int l=strlen(input);
    
    if(l==0 || l==1)    return;
    
    if(input[0]==input[1]) //1st matches to 2nd means duplicate found
    {
        for(int i=1;i<=l;i++)
            input[i-1]=input[i];
        //iske baad string already got updated
        
        continuous_duplic_removal(input);
        
    }
    else
    continuous_duplic_removal(input+1);
    
}


int main(){
    char p[15];
    cin>>p;  //one imp note cin stops input at first white space
    continuous_duplic_removal(p);
    cout<<"The non continuous new string is: "<<p ;
}
