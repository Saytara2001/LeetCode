class Solution {
public:
    int largestVariance(string s) {
        int freq[26] = {};
        for(auto ss: s) {
            freq[ss-'a']++;
        }
        
        int final_answer = 0;
        
        for(int i = 0; i < 26 ; i++) {
            for(int j = 0; j < 26 ; j++) {
                
                if(!freq[i] or !freq[j] or i == j) 
                    continue;
                
                char major = 'a' + i; 
                char minor = 'a' + j;
                int majorCount = 0;
                int minorCount = 0;
                int remMinor = freq[j];
                
                for(auto ss: s) {
                    
                    if(ss == major)
                        majorCount++;
                    
                    if(ss == minor) {
                        minorCount++;
                        remMinor--;
                    }
                    
                    //update answer if i have at least one minor
                    if(minorCount > 0)
                        final_answer = max(final_answer, majorCount - minorCount);
                    
                    if(minorCount > majorCount and remMinor > 0) {
                        minorCount = majorCount = 0;
                    }
                }
                
            }
        }
        return final_answer;
    }
};