#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> primeNums;                             // stored array of prime numbers
int x[205];

// Sieve of Eratosthenes
void findPrimeNums()
{
    const int MAX_PRIME = 110000;
    bool isPrime[MAX_PRIME];
    fill(isPrime, isPrime + MAX_PRIME, true);

    // O(2^n)
    for (int i = 2; i < MAX_PRIME; ++i) {
        if (!isPrime[i]) continue;
        primeNums.push_back(i);                     // push prime number to vector primeNums
                                                    // prime number are marked as "true", and value is i
        for (int k = i; k < MAX_PRIME; k += i)      // mark all multiples of 2, 3 ... as non-prime (false)
            isPrime[k] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC, n;
    cin >> TC;

    findPrimeNums();

    while (TC--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> x[i];

        sort(x, x + n);
            
        int minDiff = 1000000000;       
        // brue force: compare the value of EVERY prime numbers in stored array and EVERY prime number in input array
        for (int i = 0; i < primeNums.size() - n; ++i) {          
            int diffSum = 0;
            for (int p = 0; p < n; ++p)                         // parallel comparison 
                diffSum += abs(x[p] - primeNums[i + p]);        // diff = x[0] - prime[0]
                                                                //         + x[1] - prime[1]
                                                                //            + x[2] - prime[2]
            if (diffSum < minDiff)
                minDiff = diffSum;
        }
        cout << minDiff << '\n';
    }
}