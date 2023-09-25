#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int longestCommonSubstring( vector<vector<int>> tabulator, string subs1, string subs2) {
    int maxInt = 0;
    for(int row = 0; row < tabulator.size(); row ++) {
        for(int col = 0; col < tabulator[0].size(); col++) {
            if(col == 0 || row == 0){
                tabulator[row][col] = 0;
            }
            else {
                if (subs1[col - 1] == subs2[row - 1]) {
                    tabulator[row][col] = max(tabulator[row - 1][col - 1] + 1, tabulator[row][col - 1] + 1);
                } else {
                    tabulator[row][col] = 0;
                }
                if(maxInt < tabulator[row][col]) {
                    maxInt = tabulator[row][col];
                }
            }
        }
    }
    return maxInt;
}

int main(int argc, char *argv[]) {
    string subs1 = "baaxcd";
    string subs2 = "baaxd";

    vector<vector<int>> tabulator(subs2.size(), vector<int>(subs1.size()));

    int max = longestCommonSubstring(tabulator, subs1, subs2);
    cout << max;

}