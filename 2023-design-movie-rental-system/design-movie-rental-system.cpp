class MovieRentingSystem {
public:
    set<array<int, 3> > Rented; /// price, shop, movie
    map<pair<int, int>, int> Price; /// (shop, movie) -> price
    unordered_map<int, set<pair<int, int> > > Movie; /// movie -> (price, shop) --> sorted by price then shop
    MovieRentingSystem(int n, vector<vector<int> > &entries) {
        // shop, movie, price
        for (auto entry: entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            Price[{shop, movie}] = price;
            Movie[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        for (auto [price, shop]: Movie[movie]) {
            res.push_back(shop);
            if (res.size() == 5) break;
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = Price[{shop, movie}];
        Movie[movie].erase({price, shop});
        Rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = Price[{shop, movie}];
        Movie[movie].insert({price, shop});
        Rented.erase({price, shop, movie});
    }

    vector<vector<int> > report() {
        vector<vector<int> > res;
        for (auto [price, shop, movie]: Rented) {
            res.push_back({shop, movie});
            if (res.size() == 5) break;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */