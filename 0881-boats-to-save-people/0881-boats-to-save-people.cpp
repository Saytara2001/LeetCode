class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;
        int boats = 0;
        while(l <= r) {
            int lst = people[r--];
            if(l <= r and lst + people[l] <= limit)
                l++;
            boats++;
        }
        return boats;
    }
};