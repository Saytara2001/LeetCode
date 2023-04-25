class SmallestInfiniteSet {
    set<int> addedIntegers;
    int currentInteger;
public:
    SmallestInfiniteSet() {
        currentInteger = 1;
    }
    int popSmallest() {
        int answer;
        if (!addedIntegers.empty()) {
            answer = *addedIntegers.begin();
            addedIntegers.erase(addedIntegers.begin());
        }else {
            answer = currentInteger;
            currentInteger += 1;
        }
        return answer;
    }
    void addBack(int num) {
        if (currentInteger <= num || 
            addedIntegers.find(num) != addedIntegers.end()) {
            return;
        }
        addedIntegers.insert(num);
    }
};