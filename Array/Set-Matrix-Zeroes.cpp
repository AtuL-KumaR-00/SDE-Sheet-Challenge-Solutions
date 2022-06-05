#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    stack <pair<int,int>> st;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)    st.push({i,j});
            }
        }
        while(st.empty()==false){
            pair<int,int> itr= st.top();
            st.pop();
            int a=itr.first;
            for(int j=0;j<matrix[0].size();j++){
                matrix[a][j]=0;
            }
            int b=itr.second;
            for(int i=0;i<matrix.size();i++){
                matrix[i][b]=0;
            }
        }
}