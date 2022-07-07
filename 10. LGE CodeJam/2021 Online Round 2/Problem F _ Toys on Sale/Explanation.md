# Description:

Albert wants to sell n old toys he has collected. Toys are numbered from 0 to n-1, and the i-th toy's selling price is v[i].

Albert wants to sell all n toys to one buyer so he can buy new toys, and Alice wants to purchase these toys. Alice asks Albert to honor the following "bundle discount" in exchange for her purchasing all toys at once.

* If Alice bundles 3k consecutive toys from i-th to i+(3k-1)-th, then she will get a discount equal to the sum of the k most expensive toys in the bundle (Alice calls it a k-bundle discount).
* Each toy can belong to at most one bundle, and each bundle must contain 3k consecutively numbered toys.
* Alice can get multiple bundle discounts, and bundles can contain different numbers of toys (as long as the number of toys in each bundle is a multiple of 3).
* After Alice applies bundle discounts as much as she wants, she will purchase the remaining toys by paying their individual prices.

Because Albert always gets tricked by Alice, Albert decided to accept Alice's request with one condition. Albert will first pick one of the toys whose index is a multiple of 3, and Alice must purchase that toy at the selling price. Then, afterwards, Alice can get bundle discounts on the remaining toys as much as she likes. Alice thought about it for a while, and accepted this.

For instance, suppose n = 7 and v = [1 2 3 100 10 20 30].

* Albert can first choose the 0th, the 3rd, or the 6th toy and sell it to Alice at v[0], v[3], or v[6], respectively.
* If Albert sells the 0th toy (at price 1), then Alice can bundle (1st, 2nd, and 3rd) toys to pay (2+3) and bundle (4th, 5th, and 6th) to pay (10+20) so that she pays 36 in total to purchase all toys.
* If Albert sells the 3rd toy (at price 100), then Alice can bundle (0th, 1st, and 2nd) as well as (4th, 5th, and 6th) to pay 100 + (1 + 2) + (10 + 20) = 133 for all toys.
* If Albert sells the 6th toy (at price 30), then Alice can bundle the remaining six toys to pay 30 + (1+2+3+10) = 46 for all toys.
* In this example, Albert must sell the 3rd toy first to maximize his gain, and Alice will try to pay the least afterwards -- by paying 133.

Alice is very meticulous, and Albert needs your help.

Given n and v, find which toy Albert must pick to sell first so that Albert can maximize the total amount Alice will need to pay.

* **Input**
The first line will contain the number of test cases, T.

Each test case will be given by two lines.

The first line will contain n, the number of toys, and the second line will contain n integers describing prices of the n toys, separated by a whitespace.

* **Output**

For each test case, output two numbers separated by a whitespace in a single line.

The first number is the index of the first toy Albert must sell to Alice (between 0 and n-1, inclusive), and the second number is the total Alice will pay to Albert.

If there are multiple answers with the maximum amount Alice should pay to Albert, output the one with the smallest index of the first toy to be sold.

* **Limit**
```
1 ≤ T ≤ 15
4 ≤ n < 50,000 (in all test cases, the remainder of n divided by 3 will be 1)
1 ≤ v[i] ≤ 1,000,000,000 (1 ≤ i ≤ n)
```

* **Sample Input**
```
4
4
5 1 3 2
4
10 8 5 7
7
1 2 3 100 10 20 30
7
1000 1000 1000 1000 1000 1000 1000
```

* **Sample Output**
```
0 8
0 22
3 133
0 5000
```
Case 1: No explanation.

Case 2: Albert will sell toy #0, and Alice can bundle the remaining 3 toys, paying 10 + (5+7) = 22 in total.

Case 3: Used in the problem statement.

Case 4: When there are multiple solutions, output the smallest index of the toy that Albert must sell at the beginning.

# Solution:

Alice can get the most discounts if there are as many toys as three multiples in a row, always in one bundle.

Because you can get a discount on the most expensive toys in the whole toys.

Except for Albert's choice of toys, the smaller, larger toys will each have as many as 0 or a mutiple of 3.

So Alice can expect Albert to take out the toys he chooses and make one or two bundles. (If you choose 0 or the last number, the number of bundles is one.)

If you know how much money you can get from these bundles, you will tell Albert which item to choose.

* **Minimum / Maximum Heap**
To know the amount of the bundle of 3k, the largest value of k must be found in any array.

You can use the minimum, maximum heap.

Push small value in the array at a minimum heap and large value at a maximum heap.

Max size of the minimum heap is increased by 1 for each index 3. (Initial size is 1)

Calculate two values.

* tot : the sum of all value that pushed at two heap.
* totMinHeap : the sum of all value that pushed at minimum heap.

* **tot-totMinHeap** is the amount of money Albert can get from a bundle of toys with a smaller toy number than the toy he chose.

If you do the above in the opposite direction from the last index, you can know how much Alert get from a bundle of toys with large numbers.

The total amount of money that Albert can get when he chooses a toy can be calculated in the follow formula.

`price of toy that Abert chooses+ price of small number toy bundle + price of large number toy bundle`

And choose the largest one.

## Complexity
Time complexity is O(nlogn) because it involves putting n values into heap.

Pushing a value into heap : O(logn)
The number of toys : n
Pushing n values into heap : O(nlogn)
