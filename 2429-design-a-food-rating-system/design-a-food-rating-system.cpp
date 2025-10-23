class FoodRatings {
public:
    map<string, string> cuisine; // food -> cuisine
    map<string, set<pair<int, string> > > mp;
    map<string, int> rating; // food -> rate
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        for (int i = 0; i < cuisines.size(); i++) {
            cuisine[foods[i]] = cuisines[i];
            mp[cuisines[i]].insert({ratings[i], foods[i]});
            rating[foods[i]] = ratings[i];
        }
    }

    void changeRating(string food, int newRating) {
        mp[cuisine[food]].erase({rating[food], food});
        mp[cuisine[food]].insert({newRating, food});
        rating[food] = newRating;
    }

    string highestRated(string cuisine) {
        int highestRate = mp[cuisine].rbegin()->first;
        return mp[cuisine].lower_bound({highestRate, ""})->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */