#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int usingRecursion(int n){
    if(n==0){         // if number is zero..no way to make squares with 0
        return 0;
    }
    
    int ans=n;   // assuming the ans to be max (n)
    for(int i=1;i*i<=n;i++){
        ans=min(ans,1+usingRecursion(n-i*i));    // getting the minimum answer
    }
    return ans;        // recursive call for reducing the number by the square of 'i'
}



int topDown(int n,vector<int> &dp){
    if(n==0){         // if number is zero..no way to make squares with 0
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    
    int ans=n;   // assuming the ans to be max (n)
    for(int i=1;i*i<=n;i++){
        ans=min(ans,1+usingRecursion(n-i*i));    // getting the minimum answer
    }
    dp[n]=ans;        // recursive call for reducing the number by the square of 'i'
    return dp[n];
}



int bottomUp(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=n;j++){
            if(i-j*j>=0){
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
    }
    return dp[n];
}



int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;

    int ans1=usingRecursion(n);
    cout<<"Minimum perfect squares using recursion are: "<<ans1<<endl;

    vector<int> dp(n+1,-1);
    int ans2=topDown(n,dp);
    cout<<"Minimum perfect squares using top-down approach are: "<<ans2<<endl;

    int ans3=bottomUp(n);
    cout<<"Minimum perfect squares using bottom-up approach are: "<<ans3<<endl;

    return 0;
}