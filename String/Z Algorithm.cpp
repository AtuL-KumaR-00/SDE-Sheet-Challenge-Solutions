#include<bits/stdc++.h>
void computeLPSArray(string pat, int M, int* lps) 
{ 
    // Your code here
    lps[0]=0;
    for(int i=1;i<M;i++){
        int j=lps[i-1];
        while(j>0 && pat[i]!=pat[j]){
            j=lps[j-1];
        }
        if(pat[i]==pat[j]){
            j++;
        }
        // if(j==0){
        //     lps[i]=0;
        //     continue;
        // }
        lps[i]=j;
    }
    
}

int zAlgorithm(string txt, string pat, int n, int m)
{
	// Write your code here
    int lps[pat.size()];
    computeLPSArray(pat,pat.size(),lps);
    
//     for(int i=0;i<m;i++){
//         cout<<pre[i]<<" ";
//     }cout<<"\n";
    int count=0;
    int j=0;
    int i=0;
    while(i<txt.size()){
        if(txt[i]==pat[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
        if(j==pat.size()){
            count++;
        }
    }
    return count;
}