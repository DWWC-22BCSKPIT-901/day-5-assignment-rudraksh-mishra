// #include <iostream>
// #include <vector>
// #include <chrono>

// using namespace std;

// bool search_2d_matrix_bfbs(vector<vector<int>>& matrix, int target) {
//     bool retval = false;

//     for (const auto& row : matrix) {
//         int lo = 0;
//         int hi = row.size();
//         int mi = (lo + hi) / 2;

//         while (lo < hi) {
//             if (row[mi] == target) {
//                 retval = true;
//                 break;
//             } else if (row[mi] < target) {
//                 lo = mi + 1;
//             } else {
//                 hi = mi;
//             }
//             mi = (lo + hi) / 2;
//         } 
//     }

//     return retval;
// }

// bool search_2d_matrix_sbs(vector<vector<int>>& matrix, int target) {
//     bool retval = false;

//     int m  = matrix.size();
//     int n  = matrix[0].size();
//     int lo = 0;
//     int hi = m * n - 1;
//     int mi = lo + (hi - lo) / 2;

//     while (lo <= hi) {
//         int row = mi / n;           // Converts 1D indexing to 2D by folding the 1D index using number of rows for specific rows
//         int col = mi % n;           // Converts 1D indexing to 2D by using Mod operator and using all possible remainders for columns
    
//         if (matrix[row][col] == target) {
//             retval = true;
//             break;
//         } else if (matrix[row][col] < target) {
//             lo = mi + 1;
//         } else {
//             hi = mi;
//         }
//         mi = lo + (hi - lo) / 2;
//     }

//     return retval;
// }

// int main(int argc, char* argv[]) {
//     vector<vector<int>> t = {
//         {1,  3,  5,  7},
//         {10, 11, 16, 20},
//         {23, 30, 34, 60}
//     };

//     auto start = chrono::high_resolution_clock::now();
    
//     cout << search_2d_matrix_bfbs(t, 3) << endl;
    
//     auto stop = chrono::high_resolution_clock::now();
//     auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
//     cout << "Brute Force Binary Search : " << duration.count() << endl;

//     start = chrono::high_resolution_clock::now();

//     cout << search_2d_matrix_sbs(t, 3) << endl;

//     stop = chrono::high_resolution_clock::now();
//     duration = chrono::duration_cast<chrono::microseconds>(stop - start);
//     cout << "1D Indexed Binary Search : " << duration.count() << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

bool search_2d_matrix_sbs(vector<vector<int>>& matrix, int target) {
    bool retval = false;

    int m  = matrix.size();
    int n  = matrix[0].size();
    int lo = 0;
    int hi = m * n - 1;
    int mi = lo + (hi - lo) / 2;

    while (lo <= hi) {
        int row = mi / n;           
        int col = mi % n;           
        if (matrix[row][col] == target) {
            retval = true;
            break;
        } 
        else if (matrix[row][col] < target) { lo = mi + 1; } 
        else { hi = mi; }
        mi = lo + (hi - lo) / 2;
    }

    return retval;
}
int main(int argc, char* argv[]) {
    vector<vector<int>> t = {
        {1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    auto start = chrono::high_resolution_clock::now();
    
    cout << search_2d_matrix_sbs(t, 3) << endl;

    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "1D Indexed Binary Search : " << duration.count() << endl;

    return 0;
}
