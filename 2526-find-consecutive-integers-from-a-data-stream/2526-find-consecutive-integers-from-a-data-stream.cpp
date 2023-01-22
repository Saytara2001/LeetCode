class DataStream {
public:
    int cnt, value , k;
    DataStream(int value, int k):value(value), k(k), cnt(0) {
        
    }
    
    bool consec(int num) {
        
       if(num == value) cnt++;
       else cnt = 0;
        
       return cnt >= k; 
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */