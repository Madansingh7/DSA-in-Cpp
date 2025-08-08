#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>arr, int n, int tar){
    int st=0, end=n-1;
    while(st<=end){
        int mid=(st+end)/2;
        if(tar == arr[mid]){
            return mid;
        }
        else if(tar>arr[mid]){
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int main(){
    
    int n, res, tar;
    cout<<"Enter no of elements: ";
    cin>>n;
    vector<int>arr(n);
     
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    cout<<"Enter target value: ";
    cin>>tar;

    for(int var : arr){
        cout<<" "<<var;
    }
    cout<<endl;
    res = binarySearch(arr, n, tar);
    
    if(res!=-1){
        cout<<"Found at index: "<<res<<endl;
    }
    else{
        cout<<"Not found in given array"<<endl;
    }
    return 0;
}   