bool isMatch(char a,char b){
    if(a=='(' && b==')')    return true;
    if(a=='{' && b=='}')    return true;
    if(a=='[' && b==']')    return true;
    return false;
}

bool isValidParenthesis(string str)
{
    // Write your code here.
    stack<char> st;
    for(int i=0;i<str.size();i++){
        if(str[i]=='{'||str[i]=='[' || str[i] == '(')    st.push(str[i]);
        else if(st.empty())    return false;
        else {
            if(isMatch(st.top(),str[i]))    st.pop();
            else return false;
        }
    }
    return (st.size()==0);
}