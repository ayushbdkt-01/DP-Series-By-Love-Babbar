#include<iostream>
#include<vector>
using namespace std;


int usingRecursion(vector<int> &nums,int target){
    if(target==0){   // if combination is done ...then there is only one way
        return 1;
    }
    if(target<0){   // invalid combination..then no combination
        return 0;
    }

    int ans=0;
    for(int i=0;i<nums.size();i++){
        ans=ans+usingRecursion(nums,target-nums[i]);  // sum of all recursive calls
    }
    return ans;
}



int topDown(vector<int> &nums,int target,vector<int> &dp){
    if(target==0){   // if combination is done ...then there is only one way
        return 1;
    }
    if(target<0){   // invalid combination..then no combination
        return 0;
    }

    if(dp[target]!=-1){
        return dp[target];
    }

    int ans=0;
    for(int i=0;i<nums.size();i++){
        ans=ans+usingRecursion(nums,target-nums[i]);  // sum of all recursive calls
    }
    dp[target]=ans;
    return dp[target];
}



int bottomUp(vector<int> &nums,int target){
    vector<int> dp(target+1,0);
    dp[0]=1;

    for(int i=1;i<=target;i++){   // traversing the target
        for(int j=0;j<nums.size();j++)   // traversing the nums vector
            if(i-nums[j]>=0){
                dp[i]=dp[i]+dp[i-nums[j]];
            }
    }
    return dp[target];
}



int main(){
    vector<int> nums={1,2,5};

    int target;
    cout<<"Enter target: ";
    cin>>target;

    int ans1=usingRecursion(nums,target);
    cout<<"Combinations using recursion is: "<<ans1<<endl;

    vector<int> dp(target+1,-1);
    int ans2=topDown(nums,target,dp);
    cout<<"Combinations using top-down approach is: "<<ans2<<endl;

    int ans3=bottomUp(nums,target);
    cout<<"Combinations using bottom-up approach is: "<<ans3<<endl;


    return 0;

}