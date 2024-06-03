#include<iostream>
using namespace std;


int climbingStairs(int n,int start){
    if(start==n){   // Base case
        return 1;
    }

    if(start>n){    // Base case
        return 0;
    }

    return climbingStairs(n,start+1)+climbingStairs(n,start+2);  // Recursive calls
}



int main(){
    int n;
    cout<<"Enter nth stair: ";
    cin>>n;

    int ans=climbingStairs(n,0);
    cout<<"Ways to reach "<<n<<"th stairs are: "<<ans<<endl;

    return 0;
}