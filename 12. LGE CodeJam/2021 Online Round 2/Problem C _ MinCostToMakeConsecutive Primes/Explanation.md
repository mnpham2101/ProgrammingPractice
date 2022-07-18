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

# Solution:
The sequence of solving the problem is as follows:
* Sort the input array
* Find consecutive prime numbers
* Calculate the minimum penalty value

1. Sort the input array
First of all, you should sort the given the input array to make comparisons with consecutive primes easier. At this time, the input range of n is very small, less than 200, so you don't need to worry about the efficiency of the sorting. You can implement a simple bubble sort or use the sort function provided by the programming language as it is.

2. Find consecutive prime numbers
The consecutive prime numbers do not change for each test case, so you only need to find them once. Then, you can save execution time because that consecutive primes can be used in all test cases.

The maximum value of n is 20 and the maximum value of x[i] is 100,000. So, you should consider up to about 101,000 because an array that all elements are 100,000 can be input.

* *Brute Force*

Using only the rule of "a positive integer p greater than 1 is called a prime if its only divisors are 1 and p", you can check whether the numbers from 2 to 101,000 can be divided by another numbers. → This method cannot be passed within the time limit.

* *Reduce range*

In method (1), you can only check up to sqrt(p) to reduce the range of checking if p is dividing by another numbers.
* *Using the stored array of prime numbers*

To find out if the integer p is a prime number, you just need to check that it divides by the prime numbers rather than all numbers less than p. While the integer p increases from 2 to 101,000, you should check whether it is divided by the prime numbers already stored in the array, and if p is a prime number, store it in the array.

* *Sieve of Eratosthenes*

To find the prime numbers, you can use a method called "Sieve of Eratosthenes". It is a method of listing all numbers from 2 to the range you want to find prime numbers (in this case 101,000) and removing non-prime numbers (multiples of a specific number) one by one.

The image below shows the process of finding prime numbers out of 120 or less.

(Reference: https://commons.wikimedia.org/wiki/File:Sieve_of_Eratosthenes_animation.gif)

3. Calculate the minimum penalty value
The "sorted input array" obtained in step 1 and the "consecutive prime numbers" obtained in step 2 are compared through a loop, and the penalty points (difference between the element values) are added together. And then, you can find and output the minimum value among the sum of each penalty.

