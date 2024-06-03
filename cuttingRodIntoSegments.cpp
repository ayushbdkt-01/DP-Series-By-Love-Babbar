#include<iostream>
#include<climits>
#include<vector>
using namespace std;


int usingRecursion(int l,int x,int y,int z){
    if(l==0){
        return 0;   // length of the rod is zero
    }
    if(l<0){
        return INT_MIN;   // invalid length (invalid)
    }

    int a=usingRecursion(l-x,x,y,z)+1;
    int b=usingRecursion(l-y,x,y,z)+1;
    int c=usingRecursion(l-z,x,y,z)+1;

    int ans=max(a,max(b,c));

    return ans;
}

int topDownApproach(int l,int x,int y,int z,vector<int> &dp){
    if(l==0){
        return 0;   // length of the rod is zero
    }
    if(l<0){
        return INT_MIN;   // invalid length (invalid)
    }

    if(dp[l]!=-1){
        return dp[l];
    }
    int a=topDownApproach(l-x,x,y,z,dp)+1;
    int b=topDownApproach(l-y,x,y,z,dp)+1;
    int c=topDownApproach(l-z,x,y,z,dp)+1;

    dp[l]=max(a,max(b,c));

    return dp[l];
}



int bottomUpApproach(int l,int x,int y,int z){
    vector<int>dp(l+1,INT_MIN);
    dp[0]=0;

    if(l<0){
        return INT_MIN;   // invalid length (invalid)
    }

    for(int i=1;i<=l;i++){
        if(i-x>=0){
            dp[i]=max(dp[i],dp[i-x]+1);
        }
        if(i-y>=0){
            dp[i]=max(dp[i],dp[i-y]+1);
        }
        if(i-z>=0){
            dp[i]=max(dp[i],dp[i-z]+1);
        }
    }

    if(dp[l]<0){
        return 0;
    }
    else{
        return dp[l];
    }
}


int main(){
    int l;
    int x,y,z;
    cout<<"Enter length of rod: ";
    cin>>l;
    cout<<"Enter 3 segments: ";
    cin>>x>>y>>z;

    int ans1=usingRecursion(l,x,y,z);
    cout<<"Max segments using recursion are: "<<ans1<<endl;

    vector<int> dp(l+1,-1);
    int ans2=topDownApproach(l,x,y,z,dp);
    cout<<"Max segments using top-down approach are: "<<ans2<<endl;

    int ans3=bottomUpApproach(l,x,y,z);
    cout<<"Max segments using bottom-up approach are: "<<ans3<<endl;


    return 0;
}