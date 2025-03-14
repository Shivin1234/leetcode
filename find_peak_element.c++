#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int left=0,right=nums.size()-1;

    while(left < right){
        int mid=(left + right)/2;

        if(nums[mid] > nums[mid+1]){
            right=mid;
        }else
            left=mid+1;
    }
    return left;

}

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << "Peak Element Index: " << findPeakElement(nums) << endl;
    return 0;
}
