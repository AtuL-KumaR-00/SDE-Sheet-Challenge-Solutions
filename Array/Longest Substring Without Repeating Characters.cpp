class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int res=0;
        unordered_set<char> st;
        while(r<s.size()){
            if(st.find(s[r])==st.end()){
                res=max(res,r-l+1);
                st.insert(s[r]);
                r++;
            }else{
                while(s[l]!=s[r] && l<r)   {
                    st.erase(s[l]);
                    l++;
                }
                l++;
                st.insert(s[r]);
                r++;
            }
        }
        return res;
    }
};