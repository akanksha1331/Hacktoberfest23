class Solution {
public:
    
    int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        
        grid[0][0] = -1; //visited
        
        int ans = grid[0][0];
        
        while(!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            
            int x = temp[1];
            int y = temp[2];
            int t = temp[0];
            
            ans = max(ans, t);
            
            if(x == n-1 && y == n-1)
                return ans;
            
            for(int d = 0;d<4;d++)
            {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] != -1)
                {
                    pq.push({grid[nx][ny], nx, ny});
                    grid[nx][ny] = -1;
                }
            }
        }
        return -1;
    }
};
