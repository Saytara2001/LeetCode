class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mx = nums.back();
        int ans = -1, n = nums.size();
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < mx)
                ans = max(ans, mx - nums[i]);
            mx = max(nums[i], mx);
        } 
        return ans;
    }
};


// class Solution {
// public:
//     int maximumDifference(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> mn(n), mx(n);
//         mn[0] =  nums[0];
//         for(int i = 1; i < n; i++){
//             mn[i] = min(nums[i], mn[i-1]);
//         } 
//         mx[n-1] = nums[n-1];
//         for(int i = n-2; i >= 0; i--){
//             mx[i] = max(nums[i], mx[i+1]);
//         } 
//         int ans = -1;
//         for(int i = 0; i < n; i++){
//             if(mx[i] > mn[i]) 
//                 ans = max(ans, mx[i]-mn[i]);
//         }
//         return ans;
//     }
// };