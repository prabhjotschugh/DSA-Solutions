class FoodRatings {
public:
    private:
    // Mapping from food names to pairs of cuisine and rating
    unordered_map<string, pair<string, int>> foodToCosine;

    // Mapping from cuisine to ratings and corresponding set of food names
    unordered_map<string, map<int, set<string>>> cosineToRating;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodToCosine[foods[i]] = make_pair(cuisines[i], ratings[i]);
            cosineToRating[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& [cosine, rating] = foodToCosine[food];
        cosineToRating[cosine][rating].erase(food);
        if (cosineToRating[cosine][rating].empty()) {
            cosineToRating[cosine].erase(rating);
        }
        rating = newRating;
        cosineToRating[cosine][newRating].insert(food);
    }

    string highestRated(string cuisine) {
        auto& ratings = cosineToRating[cuisine];
        auto maxRatingIt = ratings.empty() ? ratings.end() : prev(ratings.end());
        if (maxRatingIt != ratings.end() && !maxRatingIt->second.empty()) {
            return *maxRatingIt->second.begin();
        }
        return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */