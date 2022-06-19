int compareVersions(string a, string b) 
{
    // Write your code here
    int i=0,j=0;
    while(i<a.size() || j<b.size()){
        long long int na=0,nb=0;
        while(i<a.size() && a[i]!='.'){
            na = na*10 + (a[i]-'0');
            i++;
        }
        while(j<b.size() && b[j]!='.'){
            nb = nb*10 + (b[j]-'0'); 
            j++;
        }
        if(na>nb)    return 1;
        if(nb>na)    return -1;
        i++;
        j++;
    }
    //if(i>=a.size() && j<b.size())    return 1;
    //if(j>=b.size() && i<a.size())    return -1;
    return 0;
}