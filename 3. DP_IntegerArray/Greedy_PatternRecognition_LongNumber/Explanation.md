# Description
Albert is interested in arithmetic sequences, and is creating interesting problems.

First, he'd pick two positive integers a and b, and define an arithmetic sequence x: xi := a + b * (i-1). That is, x1 = a, x2 = a+b, x3 = a+b*2, and so on.

Albert didn't think carefully when he wrote x1, x2, x3, ... with no spaces in-between (from left to right), and ended up writing a really long number.
At this point, Albert is now curious what the c-th digit (from the left) would be in this long number.

For instance, when a = 1 and b = 1, Albert would have written the following number (for the first 21 numbers in the sequence): 123456789101112131415161718192021... Then, the 15th digit is "2" (coming from "12") and the 16th digit is 1 (coming from "13"). 

Another example: when a = 3 and b = 7, the long number would be (for the first 11 numbers in the sequence): 310172431384552596673...

Then, the 15th digit is "2' (coming from "52") and the 16th digit is 5 (coming from "59").

Given a, b, and c, find the c-th digit (from the left) in the long number that Albert obtains by writing the arithmetic sequence xi = a + b * (i-1) with no spaces.

**Input**
The first line will contain the number of test cases, T.

Each test case will be given in a single line that contains a, b, and c separated by a whitespace.

**Output**
Output the answer for each test case in a single line.

**Limit**
1 ≤ T ≤ 5,000
1 ≤ a, b, ≤ 106
1 ≤ c ≤ 1012

# Approach 1: O(n) time limited
* observe that the long number is : X1*10^(c-1) + X2*10^(c-2) + .... Xn*(10^0)   ==> to solve this problem, we need to find Xn. 
  For example: a=1,b=1,c=15
  The long number is 123456789101112 = 1*10^14 + 2*10^13 + 3*10^12 + ... + 9*10^6 + 10*10^4 + 11*10^2 + 12
  where X1=1, X2=2 .... Xn= 12
* the number of digit in X1, X2, Xn could be found.
* Xn is calculated by for loop until the number of digits is greater than c. 
* For every X1, X2, .... Xn, the number of digit could be counted. 
* Once Xn and the total number of digits is calculated => do adjustment to get answer.
# Algorithm
1. Step 1: calculated the series, get Xn
```
while (totalNumLength <= c) {                       // Time out due to complexity O(n)
        Xn = a + b * i;
        // Log
        // cout << Xn << " ";
        i++;                                            // since i++ is added after Xn is calculated, i needs to be compensated by -2 if Xn is not the last number.
        numLength = countDigit(Xn);
        totalNumLength += numLength;
    }
```
2. Step 2: does adjustment to get answer from Xn
```
    int remain = 0;
    if (totalNumLength > c) {                 
        int numberOfDigitTobeCutOff = totalNumLength - c;
        remain = cutOff(Xn, numberOfDigitTobeCutOff);         
        if (remain == 0) {
            i = i - 2;
            remain = a + b * i;
        }
    }

    // Log:
    ////cout << "remain: " << remain << endl;
    result = remain % 10;
    cout <<result<<endl;
```
# Time complexity:
* O(n) due to calculating Xn at step 1

# Approach 1: improved algorithm to O(logN)

# Algorithm

# Time complexity:
