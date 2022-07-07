# Description
A popularity poll is done. A list of `N` is given. The result poll has `M` candidates and their score however. Return a result of the 3 most popular on candicate list. Those not on the candidate list should be discarded.
* **Input**
  - 1st line: integer N indicates N registered candidates.
  - 2nd line: names of the candicates.
  - 3rd line: integer M indicates M people.
  - consecutive lines: names and score of M people.
* **Output**

# Solution 1:
* use map to store registered candicates and initialized scores = zero.
* when inputing the result poll, search map for registed names and only save the scored if the input names are found in registered list.
* sort the `map <name, score>` based on score in descending order.

## Algorithm:
* in order to sort the `map<string, int> PollResult` based on its key, in descending order, use `multimap`.
* the multimap stores score as key, names as value.
* the multimap could be declared to sort in descending order:
  ```
  multimap<int, string, greater<int>> sortedPullResult;
  ```
* output only the top 3 values
## Complexity:
* Lookup function for registered name: O(log(N))
* Copy from `map` to `multimap` and sort O(log2(N))

# Solution 2:
* use map to store registered candicates and initialized scores = zero.
* when inputing the result poll, search map for registed names and only save the scored if the input names are found in registered list.
* sort the `map <name, score>` based on score in descending order with the help of `vector` and operator overload

## Algorithm:
* in order to sort the `map<string, int> PollResult` based on its key, in descending order, use `vector`.
* the vector stores `pair<string, int>`.
* the vector could be declared to sort in descending order using operator overload and sort function:
  ```
    vector <pair<string, int>> SortedPollResult;

    // operator overload for SortedPollResult
    static bool greater(pair<string, int>& a, pair<string, int>& b)
    {
        return a.second > b.second;
    }

    sort(SortedPollResult.begin(), SortedPollResult.end(), greater);
  ```
* output only the top 3 values
## Complexity:
* Lookup function for registered name: O(log(N))
* Copy from `map` to `vector`: utilize resize and complexity reduces to O(1)  ==> some improvement
* Sorting vector: O(log2(N))

# Solution 3:
* use sorted `vector<People> SortedPollResult` to return the top score.
* create the `struct People` to store `name` and `score`
* use operator overload to help define how to sort people in vector.
* use `map<string, int> CandidateList` to keep track of name and initial ID of each candiate.
* at the same time of inputting `CandidateList` also fill up the `SortedPollResult` based on ID:
  ```
    SortedPollResult[i].name = name;
  ```
## Algorithm
* 2 ways to create operator overload and use sort function to sort vector.
  1. define `static bool greater` function to allow sorting in descending order
   ```
    static bool greater(const People& a, People& b)
    {
        if(a.score == b.score) {
            return a.ID > b.ID;
        }
        return a.score > b.score;
    }

    sort(SortedPollResult.begin(), SortedPollResult.end(), greater);
   ```
  2. embedded operator overload to *redefine* lesser operator in `struct People` definition=> normal sort will sort using lesser operator, but sort in reserve order.
   ```
    typedef struct People {
        string name;
        int score;
        bool operator < (People people) {
            if(people.score == score) {
                return people.ID > this->ID;
            }
            return people.score < this->score;
        }
    } People;

    sort(SortedPollResult.begin(), SortedPollResult.end());
   ```
* Because solution checker differentiate the order by which the candidate are input, answers such as `Anh 2 , Bo 2` is different from `Bo 2, Anh 2`, we need to ID the people by order in which the candidate were input.
  1. `struct people` is defined as
  ```
  typedef struct People {
    string name;
    int ID;
    int score;
  } People;
  ```
  2. The ID is updated upon candidate input:
  ```
  for (int i = 0; i < N; i++) {
    cin >> name;
    // use i as ID for candidates:
    candidateListID[name] = i;              // update ID to candidate name
    SortedPollResult[i].name = name;        // update name according to ID
    SortedPollResult[i].ID = i;             // also update ID of people for each name.
  }
  ```
  3. Extra logic to sort candidate based on ID and score.
   ## Complexity Analysis