class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int T = 0, F = 0;
        int left = 0, mxSize = 0;
        for(int i = 0; i < size(answerKey); i++) {
            answerKey[i] == 'T' ? T++ : F++;
            while(min(T, F) > k) {
                answerKey[left] == 'T' ? T-- : F--;
                left++;
            }
            mxSize = max(mxSize, i - left + 1);
        }
        return mxSize;
    }
};