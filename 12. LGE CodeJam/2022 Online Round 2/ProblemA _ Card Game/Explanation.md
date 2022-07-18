# Description:

Alice and Bob have n cards each, and each card has a digit (between `1` and `9`, inclusive) written on it. Each of the two people shall make a number (up to n digits) using their cards, and the kid who makes the strictly larger number will win.

Bob is too little to understand how to make a big number using cards. Instead, he would simply arrange his cards on the floor, and he would choose the `n`-digit number by reading the digits either from left to right or from right to left.

For instance, if Bob's cards are arranged as `{2, 3, 4}`, then he can make either `234` (from left to right) or `432` (from right ot left).

Alice wants to let Bob win the game, so she will play according to her own rules below:

* First, she would wait until Bob arranges his cards on the floor.
* Regardless of whether Bob reads the digits from left to right or from right to left, Alice wants to ensure that Bob could win -- yet, she must use at least one card.
* Among all of the numbers she can make while letting Bob win, she wants to make the largest number possible.

For instance, using the example above, suppose that Bob arranged his cards as `{2, 3, 4}` and Alice has three cards with `{1, 2, 3}`.

* Alice can make one of the six 3-digit numbers: `123`, `132`, `213`, `231`, `312`, or `321`.
* Without knowing whether Bob would pick `234` or `432`, Alice can choose `231` to ensure that Bob would win, and `231` is the largest such number.

To give another example, suppose Bob has `{2, 1, 2}` and Alice has `{2, 2, 2}`.

* Bob can only make `212` in this case.
* The only `3`-digit number Alice can make is `222`, which is strictly larger than `212`, and thus she cannot let Bob win by creating a `3`-digit number.
* Alice can instead make a `2`-digit number, `22`, and this is the largest number she can make while letting Bob win.
* 
Given `n` and the digits written on the cards that the two kids have, output the largest number Alice can make while letting Bob win.

## Input
The first line of the input will contain `T`, the number of test cases. Each test case will consist of three lines.

The first line will contain `n`.

The second line will contain `n` digits (without space) describing Bob's cards. Bob will arrange his cards on the floor in the same order as in the input.

The third line will contain n` `digits (without space) describing Alice's cards.

## Output

Output the answer for each test case in each line.

## Limit
```
1 ≤ T ≤ 10 
2 ≤ n ≤ 8
```

## Sample Input
```
5
2
99
99
3
212
222
3
234
123
4
4123
2345
8
12345678
99999999
```

## Sample Output
```
9
22
231
2543
9999999
```

# Approach 1:
1. Generate subsets of n digits of Alice cards with complexity O(N*2^N). 
2. Compare the result to Bob cards while generating subsets, once getting the a desired value, then stop generating subsets
## Detail implementation:
1. Take input of Bob and Alice cards as `string Alice, Bob`. Process each digits as `char Alicecard = Alice{i}` or `char Bobcard = Bob{i}`
2. Use backtracking by length , start with length = n, to generate Alice's card subsets
   ```
   void backtrack(vector<int>& AliceCards, vector<vector<int>>& AliceSubsetList, vector<int>&AliceSubset, int &length, int startIndex ){
        if (subset.size() == length){
            result.push_back(subset);               // we have a subset to be put in subset list                   
                                                    
            return;
        }
        for (int i = startIndex; i< nums.size(); i++){
            // add item to subset
            subset.push_back(nums{i});
            // continue to add item from i=startIndex+1 to subset until subset of lenght is filled
            backtrack(nums, result, subset, length, i+1);
            // perform comparison with BobValue here, if good, return result from here. 
            // backtrack to get another subset
            subset.pop_back();
        }
    }
   ```
3. Consider adding comparison while doing `step 2`
   ```
    vector<int> AliceSubset = { 1, 2, 3 , 4, 5};                                
    int AliceValue = 0;
    for (int i = 0; i < AliceSubset.size(); i++) {                          // n <= 9, thus this wont be a problem
        AliceValue = AliceValue * 10 + AliceSubset{i};
    }
    if (AliceValue > BobValue) {
        cout << AliceValue;
        return; 
    }
   ```
4. If not subset of a lenght is lesser than `BobValue`, reduce the subset length. 