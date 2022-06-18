#include<bits/stdc++.h>
string reverseString(string str)
{
    // Write your code here.
    stack<string> st;
    for(int i=0;i<str.size();i++){
        if(str[i]!=' '){
            string s="";
            while(str[i]!=' ' && i!=str.size()){
                s+=str[i];
                i++;
            }
            st.push(s);
        }
    }
    string ans="";
    while(st.empty()==false){
        ans+=st.top()+" ";
        st.pop();
    }
    ans.pop_back();
    return ans;
}