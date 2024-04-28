class Solution {
public:
    int head[30005], to[60010], nxt[60010], ne;
    void init(int n){
        memset(head, -1, n * sizeof head[0]);
        ne = 0;
    }
    void addEdge(int f, int t){
        to[ne] = t;
        nxt[ne] = head[f];
        head[f] = ne++;
    }
    void addBiEdge(int a, int b){
        addEdge(a, b);
        addEdge(b, a);
    }
    void dfs_cal_sub(int node, int par, vector<int>& sub, vector<int>& sum){
        for(int e = head[node]; ~e ; e = nxt[e]){
            int child = to[e];
            if(child != par){
                dfs_cal_sub(child, node, sub, sum);
                sub[node] += sub[child];
                sum[node] += sum[child] + sub[child];
            }
        }
    }
    void dfsAns(int n, int node, int par, vector<int>& sub, vector<int>& sum){
        for(int e = head[node]; ~e ; e = nxt[e]){
            int child = to[e];
            if(child != par){
                sum[child] = sum[node] - sub[child] + (n - sub[child]);
                dfsAns(n, child, node, sub, sum);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        init(n);
        vector<int> sub(n, 1), sum(n, 0);
        for(int i = 0 ; i  < edges.size() ; i++){
            addBiEdge(edges[i][0], edges[i][1]);
        }
        dfs_cal_sub(0, -1, sub, sum);
        dfsAns(n, 0, -1, sub, sum);
        return sum;
    }
};