#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<long long> least_prime;

// sieve of Eratosthenes
void leastPrimeFactor(int n)
{
    // Create a vector to store least primes.
    // Initialize all entries as 0.
    least_prime = vector<long long>(n+1, 0);

    // We need to print 1 for 1.
    least_prime[1] = 1;

    for (long long i = 2; i <= n; i++)
    {
        // least_prime[i] == 0
        // means it i is prime
        if (least_prime[i] == 0)
        {
            // marking the prime number
            // as its own lpf
            least_prime[i] = i;

            // mark it as a divisor for all its
            // multiples if not already marked
            for (long long j = i*i; j <= n; j += i)
                if (least_prime[j] == 0)
                   least_prime[j] = i;
        }
    }#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> least_prime;

// sieve of Eratosthenes
void leastPrimeFactor(int n)
{
    // Create a vector to store least primes.
    // Initialize all entries as 0.
    least_prime = vector<long long>(n + 1, 0);

    // We need to print 1 for 1.
    least_prime[1] = 1;

    for (long long i = 2; i <= n; i++)
    {
        // least_prime[i] == 0
        // means it i is prime
        if (least_prime[i] == 0)
        {
            // marking the prime number
            // as its own lpf
            least_prime[i] = i;

            // mark it as a divisor for all its
            // multiples if not already marked
            for (long long j = i * i; j <= n; j += i)
                if (least_prime[j] == 0)
                    least_prime[j] = i;
        }
    }
}


struct Node {
    long long parent_count;
    long long sum_of_leaf_path;
    long long local_total_path;
    int child;                                  // childNode = thisNode / least_prime
    Node() {
        parent_count = 0;                       // how many connections/edges to parent node that this node has
        sum_of_leaf_path = 0;                   // distance from a V[i] node to this current node
        local_total_path = 0;
        child = 0;
    }
};

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    //  sieve of Eratosthenes
    leastPrimeFactor(1000000);
    int t; cin >> t;
    while (t > 0) {
        t--;
        int n;
        cin >> n;
        vector<int> v(n);                               // nodes of the graph provided by input V[i]
        int maxV = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            maxV = max(maxV, v[i]);
        }
        long long sum = 0;
        vector<long long> score(n, 0);
        vector<struct Node> tree(maxV + 1);             // full graph

        // construct full graph from V[i]
        for (int i = 0; i < n; i++) {
            int curr = v[i];
            int path_point = 0;
            tree[curr].parent_count++;
            while (curr != 1) {
                path_point += least_prime[curr];                           // the least prime number of V[i] 
                                                                           // for every nodes, there is a smallest divisor so that the edge connecting it to another is the divisor
                                                                           // the divisor is the least prime number of node V[i]
                tree[curr].child = curr / least_prime[curr];              // if the node x>y, the smallest divisor of x is d, and x/d = y, then the edge connecting x<->y is d
                                                                           // y is the child of current node
                curr = tree[curr].child;
                tree[curr].sum_of_leaf_path += path_point;                 // the distance from current Node V[i] to 1 is incremented by all distances from node V[i] to parentNode
                                                                           // distance from node V[i] to a child Node is the least prime number
                                                                           // distance from node V[i] to a child node is cumulative
                tree[curr].parent_count++;
            }
        }

        for (int i = 0; i < n; i++) {
            int curr = v[i];
            int path_point = 0;
            while (curr != 1) {
                path_point += least_prime[curr];
                int child = curr / least_prime[curr];
                sum += path_point * (tree[child].parent_count - tree[curr].parent_count);                   // why ???
                score[i] += path_point * (tree[child].parent_count - tree[curr].parent_count);              // why ???
                score[i] += tree[child].sum_of_leaf_path - tree[curr].sum_of_leaf_path - least_prime[curr] * tree[curr].parent_count;           // why ???
                curr = child;
            }
        }

        sort(score.begin(), score.end());
        reverse(score.begin(), score.end());

        cout << sum - score[0] << "\n";
    }
    return 0;
}
}

// Sieve of Eratosthenes
// void findPrimeNums()
// {
//     const int MAX_PRIME = 110000;
//     bool isPrime[MAX_PRIME];
//     fill(isPrime, isPrime + MAX_PRIME, true);

//     // O(2^n)
//     for (int i = 2; i < MAX_PRIME; ++i) {
//         if (!isPrime[i]) continue;
//         primeNums.push_back(i);                     // push prime number to vector primeNums
//                                                     // prime number are marked as "true", and value is i
//         for (int k = i; k < MAX_PRIME; k += i)      // mark all multiples of 2, 3 ... as non-prime (false)
//             isPrime[k] = false;
//     }
// }

struct Node {
    long long leaf_count;
    long long sum_of_leaf_path;
    long long local_total_path;
    int parent;
    Node() {
        leaf_count = 0;
        sum_of_leaf_path = 0;
        local_total_path = 0;
        parent = 0;
    }
};

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    //  sieve of Eratosthenes
    leastPrimeFactor(1000000);
    int t; cin >> t;
    while(t > 0) {
        t--;
        int n;
        cin >> n; 
        vector<int> v(n);                               // nodes of the graph provided by input
        int maxV = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i]; 
            maxV = max(maxV, v[i]);
        }
        long long sum = 0;
        vector<long long> score(n, 0);
        vector<struct Node> tree(maxV + 1);             // full graph

        for(int i = 0; i < n; i++) {
            int curr = v[i];
            int path_point = 0;
            tree[curr].leaf_count++;
            while(curr != 1) {
                path_point += least_prime[curr];
                tree[curr].parent = curr / least_prime[curr];
                curr = tree[curr].parent;
                tree[curr].sum_of_leaf_path += path_point;
                tree[curr].leaf_count++;
            }
        }

        for(int i = 0; i < n; i++) {
            int curr = v[i];
            int path_point = 0;
            while(curr != 1) {
                path_point += least_prime[curr];
                int parent = curr / least_prime[curr];
                sum += path_point * (tree[parent].leaf_count - tree[curr].leaf_count);
                score[i] += path_point * (tree[parent].leaf_count - tree[curr].leaf_count);
                score[i] += tree[parent].sum_of_leaf_path - tree[curr].sum_of_leaf_path - least_prime[curr] * tree[curr].leaf_count;
                curr = parent;
            }
        }

        sort(score.begin(), score.end());
        reverse(score.begin(), score.end());

        cout << sum - score[0] << "\n";
    }
    return 0;
}
