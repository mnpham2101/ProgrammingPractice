#include <iostream>
#include <algorithm>
#include <map>
int main() {
    std::map<char,int> x = { { 'a',1 },{ 'b',2 },{'c',0} };
    std::map<char,int>::iterator best
        = std::max_element(x.begin(),x.end(),[] (const std::pair<char,int>& a, const std::pair<char,int>& b)->bool{ return a.second < b.second; } );
    std::cout << best->first << " , " << best->second << "\n";
}