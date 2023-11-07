class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time;
        int n = size(dist);
        for(int i = 0; i < n; i++) {
            time.push_back(1.0 * dist[i] / speed[i]);
        }
        sort(begin(time), end(time));
        int curTime = 0;
        for(int i = 0; i < n; i++) {
            if(curTime < time[i]) {
                curTime++;
            }else
                break;
        }
        return curTime;
    }
};