# Explanation

Given a characters array `letters` that is sorted in non-decreasing order and a character `target`, return the smallest character in the array that is larger than `target`.

Note that the letters wrap around.

For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.
 
## Example 1:
```
Input: letters = ["c","f","j"], target = "a"
Output: "c"
```

## Example 2:
```
Input: letters = ["c","f","j"], target = "c"
Output: "f"
```

## Example 3:
```
Input: letters = ["c","f","j"], target = "d"
Output: "f"
``` 

## Constraints:
```
2 <= letters.length <= 104
letters[i] is a lowercase English letter.
letters is sorted in non-decreasing order.
letters contains at least two different characters.
target is a lowercase English letter.
```

# Solution 1: Map, record
* There are only 26 alphabet in Endlish. A set/map/array could be used as a record when searching linearly through the `letter` array. The index of the arrays corresponds to the letter:
    * `index = c - 'a'`
* The index tells the position/ characters that is largert than target
```
// vector<bool> seen(26, false);
bool seen[26] = { [0 ... 25] = false} ;         // must use designated initializer
for (char c: letters)
    seen[c - 'a'] = true;
while (true) {                           
    target++;   
    if (target > 'z') 
        target = 'a';                   // letters 'wrap' around
    if (seen[target - 'a']== true) {
        
        return target;
    }        
}
```
