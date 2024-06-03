#include<iostream>
#include<vector>
#include<climits>
using namespace std;



int usingRecursion(vector<int> &coins,int target){
    if(target==0){
        return 0;       // Base case
    }
    if(target<0){
        return INT_MAX;    // invalid target
    }
    int mini=INT_MAX;

    for(int i=0;i<coins.size();i++){
        int ans=usingRecursion(coins,target-coins[i]);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);   // updating mini if answer is valid
        }
    }

    return mini;
}



int topDownApproach(vector<int> &coins,int target,vector<int> &dp){
    if(target==0){
        return 0;       // Base case
    }
    if(target<0){
        return INT_MAX;    // invalid target
    }
    if(dp[target]!=-1){
        return dp[target];
    }
    int mini=INT_MAX;

    for(int i=0;i<coins.size();i++){
        int ans=usingRecursion(coins,target-coins[i]);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);   // updating mini if answer is valid
        }
    }
    dp[target]=mini;     // Inserting values in the dp array for future use

    return mini;
}



int bottomUpApproach(vector<int>coins,int target){
    vector<int> dp(target+1,INT_MAX);   // dp array for storing answers
    dp[0]=0;  // initializing the dp array

    for(int i=0;i<=target;i++){
        for(int j=0;j<=coins.size();j++){
            if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-coins[j]]);   // inserting the minimum number of coins required for each target in a loop
            }
        }
    }

    if(dp[target]==INT_MAX){
        return -1;
    }
    return dp[target];
}



int main(){
    vector<int>coins={1,2,5,10};    // coins of 1,2,5,10,20

    int target;
    cout<<"Enter target sum: ";
    cin>>target;


    int ans1=usingRecursion(coins,target);
    if(ans1==INT_MAX){     // if the answer is invalid
        cout<<"Invalid target!....Answer is: -1"<<endl;
    }
    else{
    cout<<"Answer using recursion is: "<<ans1<<endl;
    }


    vector<int>dp(target+1,-1);
    int ans2=topDownApproach(coins,target,dp);
    if(ans2==INT_MAX){     // if the answer is invalid
        cout<<"Invalid target!....Answer is: -1"<<endl;
    }
    else{
    cout<<"Answer using top-down approach is: "<<ans1<<endl;
    }


    int ans3=bottomUpApproach(coins,target);
    if(ans3==INT_MAX){     // if the answer is invalid
        cout<<"Invalid target!....Answer is: -1"<<endl;
    }
    else{
    cout<<"Answer using bottom-up approach is: "<<ans3<<endl;
    }


    return 0;
}