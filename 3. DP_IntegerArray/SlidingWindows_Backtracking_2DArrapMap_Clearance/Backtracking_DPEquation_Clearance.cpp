#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

int answer = INT_MAX;
int N;                              // number of products 7<=N<=10^5
int M;                              // number of productType 2<=M<=9
int productTypeOccurance[10];       // count occurance of 9 productType, each match index, no productType = index0

vector<int> layout;
vector<vector<int>> mapProductTypeByLocation;           // row: same as layout index ==> used to query the number of productType in orginal layout at a position
                                                        //
                                                        // col: product type

vector<vector<int>> permutationList;                    // a list of permutation configs lists all the layouts of GROUP product type of product
vector<int>permutation;                                 // a single permutation config indicates layout of GROUP product type of product
unordered_map<int, bool>markCandidates;                  // indicates if the candidate is used for permutation already (true) or not (false)

void InputData() {

    cin >> N >> M;
    int productType;
    layout.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> productType;
        layout[i] = productType;
        productTypeOccurance[productType]++;
    }

    mapProductTypeByLocation.resize(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int productType = 1; productType <= M; productType++) {
            if (layout[i] == productType) {
                mapProductTypeByLocation[i][productType] = mapProductTypeByLocation[i - 1][productType] + 1;
            }
            else {
                mapProductTypeByLocation[i][productType] = mapProductTypeByLocation[i - 1][productType];
            }
        }
    }

    for (int productType = 1; productType <= M; productType++) {
        markCandidates[productType] = false;
    }
    permutation.resize(M+1);
}



// recursive backtracking algorithm
void backtracking(int startingCandidate) {

    // base case
    if (startingCandidate > M) {                                        // reaching the lowest level of permutation tree
                                                                        // level = productType = candidate, 0 doesn't count,
        // acquire a single permutation configuration, push_back to list
        permutationList.push_back(permutation);
        return;                       // return permutation for that starts with candidates at firstIndex
    }

    // recursive cases
                                                                        // candidates are productTypes
    for (int candidate=1; candidate <= M; candidate++) {                 // for loop adds next candidates to permutation at the level indicated by index
        if (markCandidates[candidate] != true) {                        // if candidate has not been used in permutation config
            markCandidates[candidate] = true;                           // set true: the candidate is now used for permutation config
            permutation[startingCandidate] = candidate;                 // add the candidate to the position indicate by index
            backtracking(startingCandidate + 1);                        // goes to deeper level by index+1
            // restore condition:
            // after backtracking returning result, we go back to higher level, previous index
            // we need to remark the candidate from lower level as false because, we want to put them back to candidate list for permutation
            markCandidates[candidate] = false;
        }
    }
}


void countingSwap(){
    int swapCount = 0;

    for (auto permutation : permutationList) {
        swapCount = 0;
        /*
            *     group1         group2
            * |------------|_________________________|
            * pos1        pos2=pos1+sizeOfGroup1;
            *             pos1=pos2        pos2=pos1+sizeOfGroup2
            */
        int position1 = 0;
        int position2 = 0;
        for (int productTypeGroup : permutation) {                 // a productTypeGroup contains only products of the same productType
            // the size of each productType group is the occurance of the product type
            int totalItemsOfProductTypeGroup = productTypeOccurance[productTypeGroup];
            // productTypeGroupSize indicates the end position of productTypeGroup
            int productTypeGroupSize = totalItemsOfProductTypeGroup;
            position2 = position1 + productTypeGroupSize;
            // number of products in orignal layout, counted from i = 1 to position of productTypeGroup
            int numberOfProductsInUnswappedGroup = mapProductTypeByLocation[position2][productTypeGroup] - mapProductTypeByLocation[position1][productTypeGroup];
            position1 = position2;
            swapCount += totalItemsOfProductTypeGroup - numberOfProductsInUnswappedGroup;
        }
        answer = min(answer, swapCount);
    }

}

void Solve() {
    backtracking(1);
    countingSwap();
}

void OutputData() {
    cout << answer << endl;
}

int main() {


    InputData();//	Input function

    //	Create the code
    Solve();

    OutputData();

    return 0;
}