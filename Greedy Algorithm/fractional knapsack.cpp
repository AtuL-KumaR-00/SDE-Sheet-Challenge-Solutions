#include<bits/stdc++.h>

static bool cmp(pair<int,int> a,pair<int,int> b){
    double tempa= (double)a.second/(double)a.first;
    double tempb= (double)b.second/(double)b.first;
    return tempa>tempb;
    //else return b>a;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),cmp);
//     for(int i=0;i<n;i++){
//         cout<<items[i].first<<" "<<items[i].second<<"\n";
//     }
//     cout<<"\n";
    double ans=0;
    for(int i=0;i<n;i++){
        if(w>=items[i].first){
            w=w-items[i].first;
            ans += (double)items[i].second;
        }
        else {
            ans +=  (double)w*(double)items[i].second/(double)items[i].first;
            w=0;
            break;
        }
    }
    return ans;    
}