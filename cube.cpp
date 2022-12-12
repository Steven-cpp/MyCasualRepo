#include <iostream>
#include <vector>
#include <forward_list>
using namespace std;

class cube
{
private:
    double l, w, h;
public:
    constexpr cube(): l(1), w(2), h(3) { }
    cube(double l, double w, double h)
    {
        this->l = l;
        this->w = w;
        this->h = h;
    }
    cube(const cube &c)
    {
    
    }
    cube(istream &is){
        cout << "l = " << l << ", w = " << w << ", h = " << h << endl;
        read(is, *this);
    }
    cube read(istream &is, cube &obj){
        cout << "Cin Constructor: Input the l, w, h of the cube: ";
        is >> obj.l >> obj.w >> obj.h;
        cout << "Cin Constructor Completed" << endl;
        return obj;
    }
    void setL(double l){
        this->l = l;
    }
    double calcCap()
    {
        return l * w * h;
    }
    bool isEq(cube c)
    {
        return this->l == c.l && this->h == c.h && this->w == c.w;
    }
    ~cube();
};

cube::~cube()
{
     
}

int main() {
    forward_list<int> l = {0, 1, 2, 3, 4, 5};
    auto prev = l.before_begin();
    auto curr = l.begin();
    while (curr != l.end()){
        if (*curr % 2 == 0)
            // [IMP]删除后返回指向被删除元素的下一个元素
            curr = l.erase_after(prev);
        else{
            prev = curr;
            curr++;
        }
    }
    cout << "l[0] = " << *l.begin() << endl;
}