# Problem Description

Albert has n cards with digits written on them.Each card has exactly one of the digits between 0 and 9 written on it, and cards with a 6 or a 9 cannot be distinguished (you can rotate the card to turn 6 to 9 or turn 9 to 6). Albert wants to make two numbers using all of his cards such that the product of the two numbers would
be maximized. He must use all of his n cards, and each number must use 1 card (and at most n − 1 cards). Cards with
a 6 or a 9 can be rotated arbitrarily.


For instance, suppose that n = 8 and Alber’s cards are given by [2, 0, 2, 0, 2, 0, 2, 1]. Then, Albert can make two numbers “2200” and “2210”, whose product is 4862000. Or, he can make “2020” and “2021”, whose product is 4082420. In this example, the maximum product Albert can achieve is 4862000.
Given n cards, find the maximum product Albert can achieve.

Input
The first line will contain the number of test cases, T.
In each of the next T lines, Albert’s cards will be described as a string consisting of digits (‘0’-‘9’) without
space.

Output
For each test case, output the maximum product Albert can achieve.
Constraints
• 1 ≤ T ≤ 10
• 2 ≤ n ≤ 18
• You may assume that the answer is at most 1018 for all test cases

## Approach  - Greedy Fail
Brute force + Greedy method is used:
For example, if input is 123456 ==> the sorted cards are 9 5 4 3 2 1

```
numListA = 54321 4321 321 21 1
numListB = 9 95 954 9543 95432

productMax = 54321 * 9
```
However, this approach fails because we can have the following:

```
numListA = 5421  9421   321
numListB = 93     53    954
productMax = 504153
```

### Data structure:
* Use vector ```num``` as data structure to store cards
* Sorting the card ```vector num``` reduce the needs to make products of lesser value card.
* Use vector ```numListA``` and ```numListB``` as data structure to store cards
* Use vector ```productList``` to store and sort results
### Algorithm:
1. get the value of numberA from numListA by
```
for (int i = 0; i < n; i++ ){
        int j = i+1;
        if (j<n){
            for (j ; j<n; j++ ){
                numberB += num[j]*(pow(10,n-j-1));
            }
            numberBList.push_back(numberB);
            numberB=0;
        }
    }
```
2. get the value of numberB from numListB by
```
for (int i = 0; i < n-1 ; i++ ){
        numberA *= 10;
        numberA += num[i];
        // cout<<i<<", numberA: "<<numberA<<endl;
        numberAList.push_back(numberA);
    }
```
3. getting the productList by multiplying items in numberListA and numberListB, item by items
```
for (int i = 0; i<n-1; i++){
        product = numberAList[i]*numberBList[i];
        productList.push_back(product);
        cout<<product<<" ";
    }
```
5. sorting the productList in reverse order (low to high) with sort function to get the highest value at front
```
sort(productList.rbegin(), productList.rend());
```
### Complexity Analysis
#### Time complexity
1. O(logN)
2. O(N)
3. O(N)
4. O(N)
5. O(NlogN)

# Solution - Brute Force + Greedy

