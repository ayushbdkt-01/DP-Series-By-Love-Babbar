// knapsack problem: There is a bag which can carry a maximum of 'w' weight. We have given 'n' items with their weights(kg) and value(Rs). We've to pickup those items such that the value is maximum(Rs) and the weight of those items do not cross the weight capacity of the bag.


#include<iostream>
#include<vector>
using namespace std;


int usingRecursion(vector<int> &weight, vector<int> &value, int index, int capacity){
    if(index==0){   // Base case
        if(weight[0]<=capacity){   // index start from end and goes towards index 0
            return value[0];  // if bag can hold the weight of the item, then return the value if that item, otherwise return 0.
        }
        else{
            return 0;
        }
    }
    
    int include=0;
    int exclude=0;
    
    if(weight[index]<=capacity){
        include=usingRecursion(weight,value,index-1,capacity-weight[index])+ value[index];
        // while including the item, add the value of the item and decrement the capacity of the bag.
    }
    
    exclude=usingRecursion(weight,value,index-1,capacity)+ 0;
    // while excluding the item, add 0 as no item is choosen and the capacity remains same.

    int ans=max(include,exclude);  // calculating the maximum value after inclusion/exclusion.
    
    return ans;
}


int topDown(vector<int> &weight, vector<int> &value, int index, int capacity,vector<vector<int>> &dp){
    if(index==0){   // Base case
        if(weight[0]<=capacity){   // index start from end and goes towards index 0
            return value[0];  // if bag can hold the weight of the item, then return the value if that item, otherwise return 0.
        }
        else{
            return 0;
        }
    }
    
    int include=0;
    int exclude=0;
    
    if(weight[index]<=capacity){
        include=topDown(weight,value,index-1,capacity-weight[index],dp)+ value[index];
        // while including the item, add the value of the item and decrement the capacity of the bag.
    }
    
    exclude=topDown(weight,value,index-1,capacity,dp)+ 0;
    // while excluding the item, add 0 as no item is choosen and the capacity remains same.

    dp[index][capacity]=max(include,exclude);  // calculating the maximum value after inclusion/exclusion.
    
    return dp[index][capacity];
}



int bottomUp(vector<int> &weight, vector<int> &value, int n, int capacity) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        
        for (int w = 1; w <= capacity; ++w) {
            
            int include = 0, exclude = 0;
            if (weight[i - 1] <= w) {
                include = value[i - 1] + dp[i - 1][w - weight[i - 1]];
            }
            exclude = dp[i - 1][w];
            dp[i][w] = max(include, exclude);
        }
    }
    
    return dp[n][capacity];
}


int spaceOptimization(){
}


int main(){
    int n;
    cout<<"Enter number of items: ";
    cin>>n;
    
    vector<int> weight(n);
    vector<int> value(n);
    
    for(int i=0;i<n;i++){
        cout<<"Enter weight and value for "<<i+1<<"th item: ";
        cin>>weight[i]>>value[i];
    }
    
    int capacity;
    cout<<"Enter the max capacity of the bag: ";
    cin>>capacity;
    
    int ans1=usingRecursion(weight,value,n-1,capacity);
    cout<<"Maximum value using recursion is: "<<ans1<<endl;
    
    vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
    int ans2=topDown(weight,value,n-1,capacity,dp);
    cout<<"Maximum value using top-down approach is: "<<ans2<<endl;
    
    int ans3=bottomUp(weight,value,n,capacity);
    cout<<"Maximum value using bottom-up approach is: "<<ans3<<endl;
    
    return 0;
}