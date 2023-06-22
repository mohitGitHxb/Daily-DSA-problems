#include <iostream>
#include <string>
using namespace std;

string reverseWord(string str){
    
   int end = str.size()-1;
    for(int i = 0; i < str.size()/2; i++)
    {
        swap(str[i], str[end]);
        end--;
    }
    return str; 
  
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<reverseWord(s)<<endl;
 
    }
return 0;
}