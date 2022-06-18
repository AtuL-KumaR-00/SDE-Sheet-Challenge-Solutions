int atoi(string str) {
    // Write your code here.
    int ans=0;
    int i=0;
    bool neg=false;
    if(str[0]=='-')    {
        neg=true;
        i=1;
    }
    for(;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9')
            ans=ans*10+(str[i]-'0');
    }
    if(neg==true)    return -1*ans;
    else return ans;
}