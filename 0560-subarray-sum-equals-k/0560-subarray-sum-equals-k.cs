public class Solution {
    public int SubarraySum(int[] nums, int k) {
        var mp = new Dictionary<int, int>();
        
        
        int sum = 0, cnt = 0;
        mp[sum] = 1;
        
        for(int i = 0; i < nums.Length; i++) {
            sum += nums[i];
            
            
            if(mp.ContainsKey(sum - k)) 
                cnt += mp[sum - k];
            
        
            if(mp.ContainsKey(sum)){
                mp[sum]++;
            }else {
                mp[sum] = 1;
            }
        }
        
        return cnt;
    }
}