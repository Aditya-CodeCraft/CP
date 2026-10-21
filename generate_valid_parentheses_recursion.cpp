// Question: Given n pairs of parentheses, generate all combinations of well-formed (valid) parentheses using recursion (e.g. n=3 -> "((()))", "(()())", "(())()", "()(())", "()()()").

#include <iostream>
#include<vector>
using namespace std;

//generate all possible valid parenthesis
void valid_parenth(int opr,int clr , string tillnow ){
    if(opr==0 && clr==0){
        cout<<tillnow<<endl;
        return;
    }
    
    if(opr>0)
        valid_parenth(opr-1,clr,tillnow+'(');
    
    if(clr>0 && opr<clr) //opr<clr as i want open first  //dont give else if as we want all possible combo else if dene se yeh execute nhi hoga
        valid_parenth(opr,clr-1,tillnow+')');    
}

void valid_parenth(int opr,int clr , string tillnow ,vector<string>&v){
    if(opr==0 && clr==0){
        v.push_back(tillnow);
        return;
    }
    
    if(opr>0)
        valid_parenth(opr-1,clr,tillnow+'(',v);
    
    if(clr>0 && opr<clr) //opr<clr as i want open first  //dont give else if as we want all possible combo else if dene se yeh execute nhi hoga
        valid_parenth(opr,clr-1,tillnow+')',v);    
}


int main()
{
    int n;
    cin>>n;
//   string input;
  vector<string>v;
//   cin>>input;
//   cout<<"The following subsequence of string "<<input<<" is: "<<endl;
//   subseq2(0,input,"",v);
   
   valid_parenth(n,n,"",v); //open ( remaining , close ) remaining , string tillnow
   
  for(int i=0;i<v.size();i++) 
    cout<<v[i]<<endl;
   

    return 0;
}
