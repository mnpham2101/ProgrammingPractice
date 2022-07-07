#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // indexing matrix
    int r[4] = {-1, 1, 0, 0};
    int c[4] = {0, 0, -1, 1};


    void floodFillDfs(vector<vector<int>>& image, int x, int y, int targetColor, int replacementColor) {
        int N = image.size();
        int M = image[0].size();
        cout<<"fill X: "<<x<<" Y: "<<y<<endl;
        if (x < 0 || x >= N)
            return ;
        if (y < 0 || y >= M)
            return ;

        if (image[x][y] != targetColor)
            return;
        else image[x][y] = replacementColor;

        for (int i = 0; i < 4; i ++) {
            floodFillDfs(image, x + r[i], y + c[i], targetColor, replacementColor);
        }
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        int color = image[sr][sc];
        if (color != newColor)                                      // must have this condition!
            floodFillDfs(image, sr,sc, color, newColor);
        return image;
    }
};

int main(){
    vector<vector<int>> image = {{0,0,0},{0,1,1}};
    int sr=1, sc=1;
    int replacementColor = 1;
    Solution sol;
    sol.floodFill(image, sr, sc, replacementColor);
}