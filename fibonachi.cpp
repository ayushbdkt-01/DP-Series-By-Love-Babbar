#include<iostream>
#include<vector>
using namespace std;



int fibTopDown(int n,vector<int> &dp){
    if(n<=1){
        return n;     // base case
    }

    if(dp[n]!=-1){
        return dp[n];    /// checking that the result is previously solved or not
    }

    dp[n]=fibTopDown(n-1,dp)+fibTopDown(n-2,dp);      // calculating fibonacci number and storing in dp array
    return dp[n];     // returning the fibonacci number
}



int fibBottomUp(int n,vector<int> &dp){
    if(n<=1){
        return n;    // Base case
    }

    dp[0]=0;       // giving initial values to the dp array
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];    // calculating the nth finonacci number
    }

    return dp[n];   // returning the nth fibonacci number
}



int fibSpaceOptimization(int n){
    if(n<=1){
        return n;   // Base case
    }

    int prev1=0;
    int prev2=1;    // Using variables instead of DP array to store the previous numbers
    int curr;

    for(int i=2;i<=n;i++){
        curr=prev1+prev2;
        prev1=prev2;    // Calculating the currrent number by the sum of tw0 previous numbers
        prev2=curr;     // Updating the two previous variables
    }

    return curr;    // returning the current number
}



int main(){
    
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    vector<int> dp(n+1);     // creating a vector for memoization
    for(int i=0;i<=n;i++){ 
        dp[i]=-1;      // ins erting -1 at every index
    }

    cout<<"Answer using top-down approach "<<fibTopDown(n,dp)<<endl;
    cout<<"Answer using bottom-up approach "<<fibBottomUp(n,dp)<<endl;
    cout<<"Answer using space optimisation approach "<<fibSpaceOptimization(n)<<endl;

    return 0;
}