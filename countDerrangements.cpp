// count derrangements: rfind the number of ways to replace the elements of an array from their original place

#include<iostream>
#include<vector>
using namespace std;


int usingRecursion(int n){
    if(n==0 || n==1){
        return 0;   // Sindle or no element in the array. so derrangements are zero
    }
    if(n==2){
        return 1;  // 2 elements ..just swap them ...only 1 way
    }
    
    int ans=(n-1)*(usingRecursion(n-1)+usingRecursion(n-2));  // recursive relation
    
    return ans;
}


int topDownApproach(int n,vector<int> &dp){
    if(n==0 || n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    
    dp[n]=(n-1)*(topDownApproach(n-1,dp)+topDownApproach(n-2,dp));
    
    return dp[n];
}


int bottomUpApproach(int n){
    vector<int>dp(n+1,0);
    
    dp[1]=0;
    dp[2]=1;
    
    for(int i=3;i<=n;i++){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);  // recurrence relation to DP array
    }
    
    return dp[n];
}

int spaceOptimization(int n){
    int prev1=0;
    int prev2=1;
    int curr;
    
    for(int i=3;i<=n;i++){
        curr=(i-1)*(prev1+prev2);
        prev1=prev2;
        prev2=curr;
    }
    
    return prev2;
}


int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;  // n is the number of elements in the array..from 0 to n-1
    
    int ans1=usingRecursion(n);
    cout<<"The max derrangements using recursion are: "<<ans1<<endl;
    
    vector<int> dp(n+1,-1);
    int ans2=topDownApproach(n,dp);
    cout<<"The max derrangements uisng top-down approach are: "<<ans2<<endl;
    
    int ans3=bottomUpApproach(n);
    cout<<"The max derrangements uisng bottom-up approach are: "<<ans3<<endl;
    
    int ans4=spaceOptimization(n);
    cout<<"The max derrangements uisng space optimization are: "<<ans4<<endl;
    
    return 0;
}