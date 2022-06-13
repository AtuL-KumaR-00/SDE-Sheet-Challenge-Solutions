void f(int idx,string s,vector<string>&ans){
    if(idx==s.size()){
        ans.push_back(s);
    }
    
    for(int i=idx;i<s.size();i++){
        swap(s[i],s[idx]);
        f(idx+1,s,ans);
        swap(s[idx],s[i]);
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    //string cotri=
    f(0,s,ans);
    return ans;
}