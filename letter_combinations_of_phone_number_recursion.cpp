// 17. Letter Combinations of a Phone Number >leetcode

#include <iostream>
using namespace std;

void gen(int index, string ip , string *map , string op){
    if(index==ip.size()){
        cout<<op<<endl;
        return;
    }

    int x = ip[index]-'0'; //heavy trick to convert char to int
    string val=map[x];
    if(val=="") //number == 0 or 1 i.e x==0 || x==1
        gen(index+1 ,ip ,map ,op);

    else
    {
        for(int i=0 ; i<val.size() ; i++)
            gen(index+1 ,ip ,map ,op+val[i] );

    }

}


int main()
{
    string map[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string input;
    cin>>input;
    gen(0,input,map,"");


    return 0;
}
// complexity via recursion >  O(4^n) where 4=max length of string i.e pqrs ,wxyz and n=length of the the input
