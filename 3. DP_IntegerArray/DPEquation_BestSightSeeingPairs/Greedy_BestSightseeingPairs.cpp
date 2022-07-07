#include <vector>
// choose to add places with higher values.
// check that the distance doesn't outweight the values.
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int bestScore = 0;
        int bestPlaceSoFar = values[0];
        int bestPlaceLocation = 0;
        for (int currentLocation=1; currentLocation<values.size(); currentLocation++){
            // set current location , calculate score
            int current = values[currentLocation];
            int current_score = bestPlaceSoFar + current + (bestPlaceLocation - currentLocation);

            // update best score
            if (current_score > bestScore){
                bestScore = current_score;
            }

            // check conditions to update bestPlaceSoFar, best locations
            // if (current > bestPlaceSoFar){                 // this condition is not enough for TC [7,8,8,10]
            //     bestPlaceSoFar = current;
            //     bestPlaceLocation = currentLocation;
            // }
            // if (current >= bestPlaceSoFar)                 // this condition is not enough for TC [7,2,6,6,9,4,3]
            //     bestPlaceSoFar = current;
            //     bestPlaceLocation = currentLocation;
            // }

            // check conditions to update bestPlaceSoFar, best locations
            // if ((current - currentLocation) >= values[currentLocation-1] - (currentLocation-1)){   // this condition is not enough for TC [7,2,6,6,9,4,3]
            //     bestPlaceSoFar = current;
            //     bestPlaceLocation = currentLocation;
            // }

            // check conditions to update bestScore, best locations
            // check that the distance doesn't outweight the values.
            if ((current + currentLocation)> (bestPlaceSoFar+ bestPlaceLocation)){
                bestPlaceSoFar = current;
                bestPlaceLocation = currentLocation;
            }
        }
        return bestScore;
    }
};

int main() {
    Solution sol;
    vector <int> values = {1,2};
    vector <int> values = {1,3,5};
    vector <int> values = {7,8,8,10};
    vector <int> values = {7,2,6,6,9,4,3};
    vector <int> values = {4,7,5,8};
}