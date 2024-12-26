#include <iostream>
#include <vector>

using namespace std;

int Find_Minimum(vector<int>& nums) {
    int lo = 0;
    int hi = nums.size() - 1;

    if (nums[lo] < nums[hi]) { return nums[lo]; }

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] == nums[hi]) {
            lo++;
            continue;
        }

        if (nums[mid] > nums[hi]) {
            lo = mid + 1;
        } else if (nums[mid] < nums[hi]) {
            hi = mid;
        } else {
            hi--;
        }
    }

    return nums[lo];
}

int main(int argc, char* argv[]) {
    vector<int> t = {2,2,2,0,1};
    cout << "Minimum : " << Find_Minimum(t) << endl;
    return 0;
}