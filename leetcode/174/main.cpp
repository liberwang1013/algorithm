#include <iostream>


#include <vector>

using namespace std;

class Solution {
public:

    void printDP(vector<vector<int>> &dp) {

        int rows = dp.size();
        int cols = dp.size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << dp[i][j] <<" ";
            }

            cout << endl;
        }
    }


    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();

        //cout << "rows is " << rows <<", cols is " << cols << endl;

        int row = rows - 1;
        int col = cols - 1;

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        //printDP(dp);

        dp[row][col] = dungeon[row][col] > 0 ? 1: (1- dungeon[row][col]);
        for(int j = col - 1; j >= 0; j--) {
            dp[row][j] = max(dp[row][j+1] - dungeon[row][j], 1);
        }

        //printDP(dp);

        int right = 0;
        int down = 0;
        for (int i = row - 1; i >= 0; i--) {
            dp[i][col] = max(dp[i + 1][col] - dungeon[i][col], 1);
            for (int j = col - 1; j >=0; j--) {
                right = max(dp[i][j + 1] - dungeon[i][j], 1);
                down = max(dp[i + 1][j] - dungeon[i][j] , 1);
                dp[i][j] = min(right, down);
            }

            //printDP(dp);
        }

        //printDP(dp);

        return dp[0][0];
    }
};


int main() {
    vector<vector<int>>map;

    vector<int> r0;
    r0.push_back(-2);
    r0.push_back(-3);
    r0.push_back(3);


    map.push_back(r0);

    vector<int> r1;
    r1.push_back(-5);
    r1.push_back(-10);
    r1.push_back(1);

    map.push_back(r1);

    vector<int> r2;
    r2.push_back(10);
    r2.push_back(30);
    r2.push_back(-5);

    map.push_back(r2);



    Solution solution;
//    solution.calculateMinimumHP(map);

    vector<vector<int>>m1;

    vector<int> m1r0;
    m1r0.push_back(0);
    m1r0.push_back(-3);

    //cout << "m1r0 size is " << m1r0.size() << endl;

    m1.push_back(m1r0);

    solution.calculateMinimumHP(m1);


}
