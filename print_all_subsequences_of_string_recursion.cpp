// Question: Return all subsequences of a given string using recursion (e.g. "abc" -> "", "c", "b", "bc", "a", "ac", "ab", "abc").
// Also print all subsequences directly using recursion (take/reject method), without storing them.

#include <iostream>
#include<math.h>
using namespace std;

// Approach 1: return all subsequences in an output array
int subseq(string input, string *output){
   if(input.size()==0){
       output[0]="";
       return 1; //empty string dala toh size 1 hogaya abhi
   }
   
   int small_size=subseq(input.substr(1),output);
   for(int i=0;i<small_size;i++)
        output[i+small_size] = input[0]+output[i];
    
    return 2*small_size;
    
}

// Approach 2: print all subsequences (take/reject method)
void printSubseq(string input, string tillnow){
   if(input.size()==0){
      cout<<"["<<tillnow<<"]"<<endl;
       return ;
   }
   
   printSubseq(input.substr(1),tillnow + input[0]); //take
   printSubseq(input.substr(1), tillnow);           //reject
    
}

int main()
{
   string input;
   cin>>input; //getline(cin,s)
   int n=pow(2,input.size());
   string *output = new string[n+1]; //check with n 
   
   int size=subseq(input,output);
   
   cout<<"Returned subsequences:"<<endl;
   for(int i=0;i<size;i++) //try with i<n
    cout<<output[i]<<endl;
   
   cout<<"The following subsequence of string "<<input<<" is: "<<endl;
   printSubseq(input,"");
   
   delete [] output;

    return 0;
}
