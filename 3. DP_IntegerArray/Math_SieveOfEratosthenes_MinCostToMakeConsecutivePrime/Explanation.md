# Description 
Albert has recently learned about prime numbers. A positive integer p greater than 1 is called a prime if its only divisors are 1 and p.

If n prime numbers p[1], p[2], ..., p[n] satisfy the following conditions, they are called consecutive primes.

p[1], ..., p[n] are n distinct primes
For every integer q with min(p[1], ..., p[n]) <= q <= max(p[1], ..., p[n]), if q is a prime, then q must be equal to one of p[1], ..., p[n].
For instance, both [5, 3, 2, 7] and [11, 7, 5, 13] are consecutive primes, but [2, 5, 7] or [5, 13, 17] or [2, 2, 3, 5] is not.

Albert came up with the following game with consecutive primes.

First, Albert picks n arbitrary integers (let us call these numbers x[1], x[2], ..., x[n]). Albert then transforms these integers to n consecutive primes, subject to the following rules:

Any x[i] can be transformed into any prime, even if x[i] may already be a prime. (If x[i] is already a prime, Albert may not need to transform it.)
Transforming an integer y into a prime p results in a penalty of | p - y |.
For instance, suppose that n = 3 and x = [7, 13, 3].

Even though all three numbers are primes, they are not consecutive primes.
If Albert transforms these numbers into [5, 7, 11], the overall penalty will be |5 - 7| + |7 - 13| + |11 - 3| = 16.
Alternatively, Albert can transform x[2] from 13 to 11 and x[3] from 3 to 5, and obtain [7, 11, 5] with the overall penalty of 4. Note that the order of primes does not matter.
Here is another example: let n = 3 and x = [2, 2, 2].

If Albert transforms the first number into 3 and the last one into 5, then the overall penalty would be 4 and the resulting numbers will be [3, 2, 5].
Given the n integers x[1], ..., x[n] that Albert picked initially, calculate the smallest penalty needed to transform those numbers into n consecutive primes.

**Input**
The first line will contain the number of test cases, T.

Each test case will be given over two lines.

The first line will contain n and the second line will contain n integers separated by a whitespace.

**Output**
For each test case, output the minimum penalty needed in order to transform the given numbers to consecutive primes.

**Limit**
1 ≤ T ≤ 10
1 ≤ n ≤ 200
1 ≤ x[i] ≤ 100,000 (1 ≤ i ≤ n)

