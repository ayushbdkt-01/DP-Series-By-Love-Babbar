#include<iostream>
#include<vector>
using namespace std;


int rob(vector<int> nums){
    int n=nums.size();
    int prev1=0;
    int prev2=nums[0];

    for(int i=1;i<n;i++){
        int including=prev1+nums[i];
        int excluding=prev2+0;
        int curr=max(including,excluding);
        prev1=prev2;
        prev2=curr;
    }
    return prev2;
}



int main(){
    vector<int> cash={10,20,30,40,50};
    
    if(cash.size()==1){    // single house is present
        cout<<"Max robbery amount is: "<<cash[0]<<endl;
        return 0;
    }

    vector<int> v1;
    for(int i=0;i<cash.size()-1;i++){ 
        v1.push_back(cash[i]);  // not taking the last element in the vector v1
    }

    vector<int> v2;
    for(int i=1;i<cash.size();i++){ 
        v2.push_back(cash[i]);  // not taking the first element in the vector v2
    }

    int ans=max(rob(v1),rob(v2));
    cout<<"Max robbery amount is: "<<ans<<endl;
    return 0;
}