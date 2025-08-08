// asked in google interview (leetcode HARD)
#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& nums, int m, int n, int maxAllowedPages) {
    int stu=1, pages=0;

    for(int i=0; i<nums.size(); i++){
        if(nums[i]>maxAllowedPages)return false;
        if(pages+nums[i] <= maxAllowedPages){
            pages+=nums[i];
        }
        else{
            stu++;
            pages=nums[i];
        }
    }
    return stu > m ? false : true;
}

int allocateBooks(vector<int>& nums, int m, int n) {
   int st = 0, end = accumulate(nums.begin(), nums.end(), 0);//0 is initial value
    int ans=-1;

    if(m>n){
        return -1;
    }
    while(st<=end){
        int mid = st + (end - st) / 2;

        if(isValid(nums, m, n, mid)){//valid than solution is on left
            ans=mid;
            end=mid-1;
        }
        else{//valid than solution is on right
            st=mid+1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    int m = 2, n=5;
    cout << "Minimum largest sum: " << allocateBooks(nums, m, n) << endl;
    return 0;
}
