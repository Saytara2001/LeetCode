class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(begin(students), end(students));
        sort(begin(seats), end(seats));
        int moves = 0;
        for(int i = 0; i < size(seats); i++) {
            moves += abs(seats[i] - students[i]);
        }
        return moves;
    }
};