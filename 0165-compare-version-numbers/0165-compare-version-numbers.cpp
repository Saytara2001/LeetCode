class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int n = size(version1), m = size(version2);
        int i = 0, j = 0;
        
        while(i < n or j < m) {
            
            int num = 0;
            while(i < n and version1[i] != '.') {
                num = num * 10 + (version1[i] - '0');
                i++;
            }
            i++;
            
            int num2 = 0;
            while(j < m and version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            j++;
            
            if(num > num2) return 1; 
            if(num < num2) return -1;
        }
        
        return 0;
    }
};