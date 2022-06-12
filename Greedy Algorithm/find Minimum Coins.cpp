int findMinimumCoins(int amount) 
{
    // Write your code here
    int count=0;
    vector<int> coins={1000,500,100,50,20,10,5,2,1};
    for(int i=0;i<coins.size();i++){
        if(amount>=coins[i]){
            //cout<<coins[i]<<"\n";
            int temp= amount/coins[i];
            count += temp;
            amount = amount - temp*coins[i];
        }//else continue;
    }
    return count;
}
