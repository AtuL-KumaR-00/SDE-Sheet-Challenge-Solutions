#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int top=0,bottom=n-1,left=0,right=m-1;
    while(bottom>top && right>left){
        vector<int> temp;
        for(int i=left;i<=right;i++)    temp.push_back(mat[top][i]);
        for(int i=top+1;i<=bottom;i++)    temp.push_back(mat[i][right]);
        for(int i=right-1;i>=left;i--)    temp.push_back(mat[bottom][i]);
        for(int i=bottom-1;i>top;i--)    temp.push_back(mat[i][left]);
        mat[top][left]=temp[temp.size()-1];
        int idx=0;
        for(int i=left+1;i<=right;i++)  {mat[top][i]=temp[idx];idx++;}      
        for(int i=top+1;i<=bottom;i++)    {mat[i][right]=temp[idx];idx++;}
        for(int i=right-1;i>=left;i--)    {mat[bottom][i]=temp[idx];idx++;}
        for(int i=bottom-1;i>top;i--)   {mat[i][left]=temp[idx];idx++;}
        top++;
        bottom--;
        left++;
        right--;
    }
}