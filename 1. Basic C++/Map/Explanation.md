# Description:
* hashmap stores Key, values.
* inserting {key,value} takes O(Nlog(size+N)) and inncrease size by 1.
```
    map<int, int> myMap;
    myMap.insert({3,5});
```
* emplace (key,value) takes O(Nlog(size+N)) and inncrease size by 1. Emplace also constructs the pair {key, value}; thus its syntax is:
```
    map<int, int> myMap;
    myMap.emplace(2,5);
```

# Popular usuage
1. To count and retrieve occurance/frequency of Items in a dataset.
```
     map<int, int> myMap;
    int myArray [10] = {1,2,1,3,1,3,2,1,3,1};
    for (item: myArray){
        myMap[item]++;
    }
```