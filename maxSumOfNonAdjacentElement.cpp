#include<iostream>
#include<vector>
using namespace std;


int usingRecursion(vector<int> &nums,int end){
    if(end<0){
        return 0;  // array is empty
    }
    if(end==0){
        return nums[0];  // single element in the array
    }

    int including=usingRecursion(nums,end-2)+nums[end];  // including the element by adding and decrementing the end by 2 b/c we need non-adjacent elements
    int excluding=usingRecursion(nums,end-1)+0;   // adding zero (including nothing) and decrementing the end by 1 b/c we need adjacent element to exclude

    return max(including,excluding);
}


int topDownApproach(vector<int> &nums,int end,vector<int> &dp){
    if(end<0){
        return 0;  // array is empty
    }
    if(end==0){
        return nums[0];  // single element in the array
    }
    if(dp[end]!=-1){
        return dp[end];   // checking if the answer already exists or not

    }
    int including=usingRecursion(nums,end-2)+nums[end]; 
    int excluding=usingRecursion(nums,end-1)+0;

    dp[end]=max(including,excluding); // inserting the answers in the dp array

    return dp[end];
}



int bottomUpApproach(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,0);  // creating a dp array for tabulation

    dp[0]=nums[0];  // from the base case from the above function

    for(int i=1;i<n;i++){
        int including = nums[i];
        if (i > 1) {      // checking index bounds
            including =dp[i-2]+nums[i];
        }
        int excluding=dp[i-1]+0;
        dp[i]=max(including,excluding);
    }
    return dp[n-1];
}



int spaceOptimiationv(vector<int> &nums){
    int n=nums.size();

    int prev1=0;    // 2 initial variables
    int prev2=nums[0];
    int curr;
    for(int i=1;i<n;i++){
        int including=prev1+nums[i];
        int excluding=prev2+0;
        curr=max(including,excluding); // updating current value
        prev1=prev2;
        prev2=curr;
    }

    return prev2;
}



int main(){
    vector<int> nums={9,9,8,2};
    int n=nums.size();

    int ans1=usingRecursion(nums,n-1);   // passing the array and the last index
    cout<<"Maximum sum using recursion is: "<<ans1<<endl;

    vector<int> dp(n,-1);
    int ans2=topDownApproach(nums,n-1,dp);
    cout<<"Maximum sum using top-down approach is: "<<ans2<<endl;

    int ans3=bottomUpApproach(nums);
    cout<<"Maximum sum using bottom-up approach is: "<<ans3<<endl;

    int ans4=spaceOptimiationv(nums);
    cout<<"Maximum sum using space-optimization approach is: "<<ans4<<endl;


    return 0;
}