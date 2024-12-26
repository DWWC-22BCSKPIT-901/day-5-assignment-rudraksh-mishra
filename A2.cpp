#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> Sorted_Squares(vector<int>& arr) {
    vector<int> res;

    for (const int a : arr) { res.push_back(a * a); }

    sort(res.begin(), res.end());

    return res;
}

int main(int argc, char* argv[]) {
    vector<int> t = {-4,-1,0,3,10};
    vector<int> r = Sorted_Squares(t);

    for (const int a : r) { cout << a << " "; }

    return 0;
}