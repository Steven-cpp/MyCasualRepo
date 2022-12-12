#include <vector>
#include <iostream>
#include <string>
using namespace std;

// 1. 如果两容器的类型不同,但可以隐式转换,可以赋值吗?
vector<const char*> v1 = {"hello", "my", "name", "is"};
vector<string> v2 = {"My", "name", "is", "Seventeen", "haha"};
vector<string> v3 = {"My", "Name", "Is", "Seventeen"};

int main(){
    // ERROR
    // v1 = v2;
    // SUCCESS
    v2 = v3;
    v2.assign(v1.begin(), v1.end());
    cout << v2.size() << endl;

    // 2. 使用swap交换两个str
    string s1 = "hello";
    string s2 = "seventeen";
    string& p = s1;
    swap(s1, s2);
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "p[0] = " << p[0] << endl;

}
