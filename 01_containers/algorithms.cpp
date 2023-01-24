#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

template <typename Iterator>
class Algorithms{
public:
    int searchWithFind(Iterator begin, Iterator end, int tar){
        return 0;
    }
private:
    
};

int main(){
    // 1. Search through arrays
    int arr[] = {10, 9, 8, 71};
    int tarVar = 10;
    auto id = find(begin(arr), end(arr), tarVar);
    cout << tarVar << (id == end(arr) ? " Not Exists": " Exsits") << endl;

    // 2. Fill 2D vector with 0
    vector<vector<int>> vec2D(4, vector<int>(4));
    // fill(vec2D.begin(), vec2D.end(), 10); <-- ERROR: CANNOT assign 10 to a vector
    for (auto vec: vec2D)
        fill(vec.begin(), vec.end(), 10);
    cout << "SUCCESS: Filling vec2D with 10" << endl;

    // 3. `fill_n()` and `back_inserter` 
    vector<int> vec;
    fill_n(back_inserter(vec), 10, 0);
    cout << "vec.size() = " << vec.size() << endl;

    return 0;
}