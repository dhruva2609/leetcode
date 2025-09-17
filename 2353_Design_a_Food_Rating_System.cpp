#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class FoodRatings {
private:
    unordered_map<string, pair<string, int>> foodInfo;
    unordered_map<string, set<pair<int, string>>> cuisineRatings;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineRatings[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodInfo[food].first;
        int oldRating = foodInfo[food].second;

        cuisineRatings[cuisine].erase({-oldRating, food});

        foodInfo[food].second = newRating;

        cuisineRatings[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine) {
        return cuisineRatings[cuisine].begin()->second;
    }
};
