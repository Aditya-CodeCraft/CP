// Question: Return all subsequences of a given string using recursion (e.g. "abc" -> "", "c", "b", "bc", "a", "ac", "ab", "abc").
// Also print all subsequences directly using recursion (take/reject method), without storing them.
// Variations: index method + printing, and index method + storing in a vector.

#include <iostream>
#include<math.h>
#include<vector>
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
    
    return 2*small_size; //double the previous size
    
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

// Approach 3: index method + printing
void subseqIndex(int index,string input, string tillnow){
   if(index==input.size()){
      cout<<"["<<tillnow<<"]"<<endl;
       return ;
   }
   
   subseqIndex(index+1, input, tillnow + input[index]); //take
   subseqIndex(index+1, input, tillnow);                //reject
    
}

// Approach 4: index method + store in vector
// (vector passed by reference, else it will be call by value so no change in actual args)
void subseqVector(int index, string input, string tillnow, vector<string>&v){
            if(index==input.size()){
                v.push_back(tillnow);
                return;
            }    
            
            subseqVector(index+1, input, tillnow+input[index], v); //take
            subseqVector(index+1 , input, tillnow,v);              //reject
}

int main()
{
   string input;
   cin>>input; //getline(cin,s)
   int n=pow(2,input.size());
   string *output = new string[n+1]; //check with n 
   
   cout<<"Approach 1 - returned in array:"<<endl;
   int size=subseq(input,output);
   for(int i=0;i<size;i++) //try with i<n
    cout<<output[i]<<endl;
   delete [] output;
   
   cout<<"Approach 2 - take/reject printing:"<<endl;
   printSubseq(input,"");
   
   cout<<"Approach 3 - index method printing:"<<endl;
   subseqIndex(0,input,"");
   
   cout<<"Approach 4 - index method stored in vector:"<<endl;
   vector<string>v;
   subseqVector(0,input,"",v);
   for(int i=0;i<v.size();i++) 
    cout<<v[i]<<endl;

    return 0;
}
