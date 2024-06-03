#include<iostream>
#include<vector>
using namespace std;



int usingRecursion(vector<int> &cost,int n){
    if(n==0){
        return cost[0];
    }                       // Base case
    if(n==1){
        return cost[1];
    }

    int ans=cost[n]+ min(usingRecursion(cost,n-1),usingRecursion(cost,n-2));  // Recursive call
    return ans;
}



int topDownApproach(vector<int> &cost,int n,vector<int> &dp){
    if(n==0){
        return cost[0];
    }                       // Base case
    if(n==1){
        return cost[1];
    }

    if(dp[n]!=-1){      // Checking that the solution exists in the DP array
        return dp[n];
    }

    dp[n]=cost[n]+ min(topDownApproach(cost,n-1,dp),topDownApproach(cost,n-2,dp));  // Recursive call
    return dp[n];
}



int bottomUpApproach(vector<int> &cost,int n){
    vector<int> dp(n+1);    // dp array for storing tabulations

    dp[0]=cost[0];      // inserting initial values
    dp[1]=cost[1];

    for(int i=2;i<=n;i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);  // Calculating the minimum cost at each stair
    }

    return min(dp[n-1],dp[n-2]);   // Returning the minimum cost
}



int spaceOptimization(vector<int> &cost,int n){
    int prev1=cost[0];      // inserting initial values in variables
    int prev2=cost[1];
    int curr;

    for(int i=2;i<=n;i++){
        curr=cost[i]+min(prev1,prev2);  // calculating the cost at current stair
        prev1=prev2;
        prev2=curr;   // updating the previous variables
    }

    return min(prev1,prev2);   // Returning the minimum cost
}



int main(){
    int n;
    cout<<"Enter number of stairs: ";
    cin>>n;

    vector<int> cost(n);
    vector<int>dp(n+1,-1);    // for top-down approach

    cout<<"Enter cost of each stair: "<<endl;
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }

    int ans1=min(topDownApproach(cost,n-1,dp),topDownApproach(cost,n-2,dp));
    cout<<"Answer using top-down approach: "<<ans1<<endl;   // Recursion + Memoization

    int ans2=bottomUpApproach(cost,n);  // Tabulation
    cout<<"Answer using bottom-up approach: "<<ans2<<endl;

    int ans3=spaceOptimization(cost,n);  // Constant space-> No DP array is used
    cout<<"Answer using bottom-up approach: "<<ans3<<endl;

    return 0;
}