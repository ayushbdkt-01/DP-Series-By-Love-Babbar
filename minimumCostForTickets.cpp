#include<iostream>
#include<vector>
#include<climits>
using namespace std;



int usingRecursion(int n,vector<int> &days,vector<int> &cost,int index){
    if(index>=n){     // we've reached to our destination
        return 0;    // then cost will be zero
    }

    // 1-Day ticket
    int ticket1=cost[0]+usingRecursion(n,days,cost,index+1);

    // 7-Days ticket
    int i;
    int ticket2;
    for(i=index;i<n && days[i]<days[index]+7;i++)
        ticket2=cost[1]+usingRecursion(n,days,cost,index+1);

    // 30-Days ticket
    int ticket3;
    for(i=index;i<n && days[i]<days[index]+30;i++)
        ticket3=cost[2]+usingRecursion(n,days,cost,index+1);

    return min(ticket1,min(ticket2,ticket3));
}



int topDown(int n,vector<int> &days,vector<int> &cost,int index,vector<int> &dp){
    if(index>=n){     // we've reached to our destination
        return 0;    // then cost will be zero
    }
    if(dp[index]!=-1){
        return dp[index];
    }

    // 1-Day ticket
    int ticket1=cost[0]+usingRecursion(n,days,cost,index+1);

    // 7-Days ticket
    int i;
    int ticket2;
    for(i=index;i<n && days[i]<days[index]+7;i++)
        ticket2=cost[1]+usingRecursion(n,days,cost,index+1);

    // 30-Days ticket
    int ticket3;
    for(i=index;i<n && days[i]<days[index]+30;i++)
        ticket3=cost[2]+usingRecursion(n,days,cost,index+1);

    dp[index]= min(ticket1,min(ticket2,ticket3));
    return dp[index];
}



int bottomUp(int n,vector<int> &days,vector<int> &cost){
    vector<int> dp(n+1,INT_MAX);

    dp[n]=0;

    for(int k=n-1;k>=0;k--){
        // 1-Day ticket
        int ticket1=cost[0]+dp[k+1];

        // 7-Days ticket
        int i;
        int ticket2;
        for(i=k;i<n && days[i]<days[k]+7;i++)
            ticket2=cost[1]+dp[k+1];
        // 30-Days ticket
        int ticket3;
        for(i=k;i<n && days[i]<days[k]+30;i++)
            ticket3=cost[2]+dp[k+1];

        dp[k]= min(ticket1,min(ticket2,ticket3));
    }
    
    return dp[0];
}



int spaceOptimization(int n,vector<int> &days,vector<int> &cost,int index){

}



int main(){
    vector<int> days={2,5};
    vector<int> cost={1,4,25};
    int n=days.size();
    
    int ans1=usingRecursion(n,days,cost,0);
    cout<<"Min cost of ticket using recursion is: "<<ans1<<endl;
    
    vector<int> dp(n+1,-1);
    int ans2=topDown(n,days,cost,0,dp);
    cout<<"Min cost of ticket using top-down approach is: "<<ans2<<endl;
    
    int ans3=bottomUp(n,days,cost);
    cout<<"Min cost of ticket using top-down approach is: "<<ans3<<endl;
    
    return 0;
}