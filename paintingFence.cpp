#include<iostream>
#include<vector>
using namespace std;


int usingRecursion(int n,int k){
    if(n==1){
        return k;   // single post.....can use all 'k' colors
    }
    if(n==2){
        return k+(k*(k-1));   // from the formula calculated
    }
    
    int ans=usingRecursion(n-2,k)*(k-1)+usingRecursion(n-1,k)*(k-1);  // Recursive relation
    
    return ans;
}


int topDown(int n,int k,vector<int> &dp){
    if(n==1){
        return k;   // single post.....can use all 'k' colors
    }
    if(n==2){
        return k+(k*(k-1));   // from the formula calculated
    }
    
    if(dp[n]!=-1){
        return dp[n];   // checking that the result is previously solved or not
    }
    
    dp[n]=(topDown(n-2,k,dp)*(k-1))+(topDown(n-1,k,dp)*(k-1));  // recurrence relation
    
    return dp[n];
}

int bottomUp(int n,int k){
    vector<int> dp(n+1);
    dp[1]=k;
    dp[2]=k+(k*(k-1));
    
    for(int i=3;i<=n;i++){
        dp[n]=(bottomUp(n-2,k)*(k-1))+(bottomUp(n-1,k)*(k-1));  // mo recursion.. only DP array
    }

    return dp[n];
}


int spaceOptimization(int n,int k){
    int prev1=k;
    int prev2=k+(k*(k-1));
    
    for(int i=3;i<=n;i++){
        int curr=(prev1*(k-1))+(prev2*(k-1));
        prev1=prev2;
        prev2=curr;  // no DP array used
    }
    
    return prev2;
}


int main(){
    int n,k;
    cout<<"Enter number of posts to paint: ";
    cin>>n;
    cout<<"Enter number of colors: ";
    cin>>k;
    
    int ans1=usingRecursion(n,k);
    cout<<"Number of ways to paint using recursion: "<<ans1<<endl;
    
    vector<int> dp(n+1,-1);
    int ans2=topDown(n,k,dp);
    cout<<"Number of ways to paint using top-down approach: "<<ans2<<endl;
    
    int ans3=bottomUp(n,k);
    cout<<"Number of ways to paint using bottom-up approach: "<<ans3<<endl;
    
    int ans4=spaceOptimization(n,k);
    cout<<"Number of ways to paint using spcce optimization approach: "<<ans4<<endl;
    
    return 0;
}