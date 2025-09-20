#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Router {
public:
    int MAX;
    queue<array<int, 3> > q;
    set<array<int, 3> > exist;
    map<int, ordered_multiset<int> > idx;

    Router(int memoryLimit) {
        MAX = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        if (exist.count({source, destination, timestamp}))
            return false;

        q.push({source, destination, timestamp});
        exist.insert({source, destination, timestamp});
        idx[destination].insert(timestamp);

        if (q.size() > MAX) {
            forwardPacket(); // pop
        }
        return true;
    }

    vector<int> forwardPacket() {
        vector<int> res;
        if (q.size()) {
            auto [src, dest, timestamp] = q.front();
            res.insert(res.begin(), {src, dest, timestamp});
            exist.erase({src, dest, timestamp});
            // cout << dest <<" "<< timestamp <<" "<< idx[dest].size() << endl;
            // cout << idx[dest].find(timestamp) << endl;
            idx[dest].erase(idx[dest].upper_bound(timestamp));
            //  cout << dest <<" "<< timestamp <<" "<< idx[dest].size() << endl;
            q.pop();
        }
        return res;
    }

    int getCount(int dest, int startTime, int endTime) {

        if (idx[dest].size() == 0)
            return 0;
        int r = idx[dest].order_of_key(endTime + 1);
        int l = idx[dest].order_of_key(startTime);
    
        if(r >= idx[dest].size() or *idx[dest].find_by_order(r) > endTime) 
            --r;

        return max(r - l + 1, 0);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */