/*
leetcode 733
*/
class Solution {
public:

    int m , n , startColor , color;

    void dfs(vector<vector<int>>& image , int sr , int sc ){
        if(sr < 0 or sr > m-1 or sc < 0 or sc > n-1) return ;
        if(image[sr][sc] != startColor) return;
        if(image[sr][sc] == color) return;
        image[sr][sc] = color;
        dfs(image , sr+1 , sc);
        dfs(image , sr-1 , sc);
        dfs(image , sr , sc+1);
        dfs(image , sr , sc-1);
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        startColor = image[sr][sc];
        this->color = color;
        dfs(image , sr , sc);
        return image;
    }
};
// can also be done using bfs
//most of grid problems for bfs / dfs traversal doesnt requirers to convert it into graph representataion 