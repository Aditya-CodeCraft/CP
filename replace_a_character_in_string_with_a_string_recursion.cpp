// Question: Replace every occurrence of a character in a string with a given string.

#include<iostream>
// #include<algorithm>
#include<string.h>
using namespace std;


void remove_a_particular_char(char *input, char c,char *kr){ //kr=kisse_Replace
    int li=strlen(input), lk=strlen(kr);
    if(li==0 || lk==0)
        return;
    
    if(input[0]==c)
    {
        for(int i=li ; i>=1 ; i--) // i=li kyuki null ko bhi shift krna hoga
            input[i+(lk-1)] = input[i];
            
        for(int i=0;i<lk;i++)
            input[i]=kr[i];
            
            
        remove_a_particular_char(input+lk,c,kr);
            
    }
    else
        remove_a_particular_char(input+1,c,kr);
    
    
}


int main(){
  char arr[40],c,k[10];
  cin>>arr; //original string
  cin>>c; //that particular character to replace
  cin>>k; //kisse replace krna h uss word ko
  remove_a_particular_char(arr,c,k);
  cout<<arr;
  
}