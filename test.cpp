#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto resPt = nums.begin(), pt = nums.begin();
        while (pt != nums.end()){
            while (*pt == *(pt+1)){
                pt++;
            }
            *(resPt++) = *(pt++);
        }
        return resPt - nums.begin();
    }
};

int main()
{
    // ofstream output("sample.txt");
    // output.close();
    ofstream output2("sample.txt", ofstream::app | ofstream::out);
    string s = "1 3 3 9 10";
    output2 << s << endl;
    output2.close();
}
