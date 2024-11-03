public class Solution {
    public bool RotateString(string s, string goal) {
        int n = s.Length, m = goal.Length;
        if(n != m)
            return false;
        
        for(int i = 0; i < n; i++) {
            bool ok = true;
            int cur = i;
            for(int j =  0; j < m; j++) {
                if(s[cur] != goal[j]) {
                    ok = false;
                    break;
                }
                cur = (cur + 1) % n;
            }
            if(ok) return true;
        }
        return false;
    }
}