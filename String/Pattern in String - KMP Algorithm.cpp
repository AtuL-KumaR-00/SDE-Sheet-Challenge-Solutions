vector<int> lps(string s){
    vector<int>LPS(s.size(),0);
    for(int i=1;i<s.size();i++){
        int prevLPS=LPS[i-1];
        while(prevLPS>0 && s[i]!=s[prevLPS]){
            prevLPS=LPS[prevLPS-1];
        }
        if(s[i]==s[prevLPS]){
            prevLPS++;
        }
        LPS[i]=prevLPS;
    }
    return LPS;
}

bool findPattern(string p, string s)
{
    // Write your code here.
    vector<int> LPS = lps(p);
    int i=0,j=0;
    while(i<s.size()){
        if(s[i]==p[j]){
            i++;
            j++;
        }    
        else{
            if(j!=0){
                j=LPS[j-1];
            }else{
                i++;
            }
        }
        if(j==p.size())    return true;
    }
    return false;
}