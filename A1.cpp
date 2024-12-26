#include <iostream>
#include <vector>

using namespace std;

int search_k(vector<int> nums, int k) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == k) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    vector<int> a1 = {9,7,16,16,4};
    cout << search_k(a1, 16) << endl;
 
    vector<int> a2 = {1,22,57,47,34,18,66};
    cout << search_k(a2, 98) << endl;
 
    return 0;
}