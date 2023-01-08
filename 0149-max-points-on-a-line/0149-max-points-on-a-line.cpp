class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), mx = 0;
        for(int i = 0; i < n ; i++){
            map<double,int> mp;
            int maxi = 0;
            for(int j = i+1 ; j < n; j++){
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                double mile = (x == 0 ? 1000000009 : y*1.0/x);
                maxi = max(maxi, ++mp[mile]);
            }
            mx = max(mx, maxi+1);
        }
        return mx;
    }
};