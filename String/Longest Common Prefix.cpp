class Solution {
public:
    bool allConsists(char ch,int pos, vector<string>&strs){
        for(int i=0;i<strs.size();i++){
            if(pos>=strs[i].size() || strs[i][pos]!=ch){
                return false;
            }
        }
        return true;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string s="";
        for(int i=0;i<strs[0].size();i++){
            if(allConsists(strs[0][i],i,strs))
                s+=strs[0][i];
            else break;
        }
        return s;
    }
};