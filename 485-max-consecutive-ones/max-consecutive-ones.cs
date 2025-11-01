public class Solution {
    public int FindMaxConsecutiveOnes(int[] nums) {
        int maxOnes = 0;
         var dic = new Dictionary<int, List<int>>();
            for (int i = 0; i < nums.Length; i++)
            {
                if(nums[i] != 1) continue;
                if (!dic.ContainsKey(nums[i]))
                {
                    dic.Add(nums[i], new List<int> { i });
                }
                else
                {
                    var value = dic[nums[i]];
                    if (i - value.Last() == 1)
                    {
                        value.Add(i);
                        dic[nums[i]] = value;
                    }
                    else
                    {
                        maxOnes = Math.Max(maxOnes, dic[nums[i]].Count);
                        dic[nums[i]] = new List<int>() {i};

                    }
                }
            }
            if (dic.ContainsKey(1))
                maxOnes = Math.Max(maxOnes, dic[1].Count);
            return maxOnes;
    }
}