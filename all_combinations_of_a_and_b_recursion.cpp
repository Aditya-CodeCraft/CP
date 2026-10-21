// Question: Given n, generate all strings made of exactly n 'a's and n 'b's using recursion (e.g. n=2 -> "aabb", "abab", "abba", "baab", "baba", "bbaa").

#include <iostream>
#include<vector>
using namespace std;

void combos_of_a_and_b(int opr,int clr , string tillnow ,vector<string>&v){ //note this is an extension of valid parenthesis
    if(opr==0 && clr==0){
        v.push_back(tillnow);
        return;
    }
    
    if(opr>0)
        combos_of_a_and_b(opr-1,clr,tillnow+'a',v);
    
    if(clr>0)
        combos_of_a_and_b(opr,clr-1,tillnow+'b',v);    
}

//NOTE: by reject/take method > never duplicates occur as in the recurssion tree Two leaves can never produce the same string because that would require making the same choice at every position, which means following the same path, which means they’re the same leaf.

int main()
{
    int n;
    cin>>n;
    vector<string>v;
   
    combos_of_a_and_b(n,n,"",v); //a remaining , b remaining , string tillnow
   
    for(int i=0;i<v.size();i++) 
        cout<<v[i]<<endl;

    return 0;
}
