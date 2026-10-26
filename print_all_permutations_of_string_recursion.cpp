// Question: Given a string, print all its permutations using recursion (swap-based approach, e.g. "abc" -> abc, acb, bac, bca, cba, cab).

#include <iostream>
#include <vector>
using namespace std;

void permut(int index , int size , string input , vector<string>&ans){
    if(index==size-1){ //or can use directly input.size() instead of size as we dont change or manipulate the original string size throughout the code 
        ans.push_back(input);
        return;
    } //index-1 == size is wrong bcoz index is incrementing so it never reaches size bcoz suppose at size 3(2 is the last correct or needed base call) so 2-1=1 not equal to size (nor it can ever be in decades)
    
    int n=size;
    for(int i=index ; i<n ; i++){
        swap(input[index],input[i]); //phele change kiye each index like i=0 se till last element
        permut(index+1,n,input,ans);
        swap(input[index],input[i]); //undo or backtrack before another call  if this has been the last line of code it will have been call by value 
    }
        
}

// The version without undo prints in sorted (lexicographic like abc > acb) order when the input starts sorted, which some solutions rely on.
// When the undo is required when using: pass-by-reference > talking about input btw

int main()
{
    string s;
    cin>>s;
    vector<string>ans;
    int n=s.size();
    permut(0,n,s,ans);
    
    cout<<endl;
    
    for(string s:ans)
        cout<<s<<endl;
    return 0;
}
