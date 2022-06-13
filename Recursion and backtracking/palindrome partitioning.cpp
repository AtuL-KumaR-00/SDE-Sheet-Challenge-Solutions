
class Solution {
public:
    void f(int start,string &s,vector<string> &contri, vector<vector<string>>&ans){
        if(start==s.size()){
            ans.push_back(contri);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isPalindrome(s,start,i)){
                contri.push_back(s.substr(start,i-start+1));
                f(i+1,s,contri,ans);
                contri.pop_back();
            }
        }
        
    }
    bool isPalindrome(string s, int start,int end){
        while(start<end){
            if(s[start]!=s[end])    return false;
            start++;
            end--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> contri;
        f(0,s,contri,ans);
        return ans;
    }
};