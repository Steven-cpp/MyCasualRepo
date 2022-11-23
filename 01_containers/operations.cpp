#include <vector>
#include <iostream>
#include <string>
using namespace std;

// 1. 如果两容器的类型不同,但可以隐式转换,可以赋值吗?
vector<const char*> v1 = {"hello", "my", "name", "is"};
vector<string> v2 = {"My", "name", "is", "Seventeen"};
vector<string> v3 = {"My", "Name", "Is", "Seventeen"};

int main(){
    // ERROR
    // v1 = v2;
    // SUCCESS
    v2 = v3;
}
