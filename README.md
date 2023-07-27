# Sliding_window
Aditya Verma
// Online C++ compiler to run C++ program online
// Maximum Sum SubArray of size k
#include<bits/stdc++.h>
using namespace std;
int maxsubarray(int *arr,int n,int k){
    int i=0,j=0,cursum=0,maxsum=0;
    while(j<n){
        cursum+=arr[j];
        if(j-i+1<k)
            j++;
      else if(j-i+1==k){
            maxsum=max(maxsum,cursum);
            cursum=cursum-arr[i];
            i++;
            j++;
        }
    }
    return maxsum;
}
int main()
{
    int n=7;
    int k=3;
    int arr[]={2,3,5,2,9,7,1};
    cout<<maxsubarray(arr,n,k);
    return 0;
}
