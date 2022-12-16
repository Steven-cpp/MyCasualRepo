#include "container.hpp"
#include <algorithm>
#include <stdexcept>
using namespace std;

void Container::Add(int value) {
  // TODO: implement
  vals.push_back(value);
}

bool Container::Delete(int value) {
  // TODO: implement
  auto tarIt = find(vals.begin(), vals.end(), value);
  if (tarIt == vals.end())
    return false;
  else{
    vals.erase(tarIt);
    return true;
  }
}

int Container::GetMedian() {
  vector<int> copy = vals;
  sort(copy.begin(), copy.end());
  int midId = vals.size() / 2;
  if (vals.size() % 2 == 0) midId -= 1;
  try{
    if (copy.size() == 0)
      throw runtime_error("Container is empty");
    return copy[midId];
  }
  catch (const runtime_error& e){
    cout << "Error: " << e.what() << endl;
    return -999;
  }
}

static int cnt = 0;

template <typename T>
bool REQUIRE(const T& a, const T& b){
  if (a == b)
    cout << "Pass Test Case " << cnt++ << endl;
  else 
    cout << "Falsed Test Case " << cnt++ << endl;
  return true;
}

int main(){
  Container container_;
  container_.Add(5);
  container_.Add(3);
  container_.Add(5);
  REQUIRE(container_.GetMedian() , 5);
  REQUIRE(container_.Delete(5) , true);
  REQUIRE(container_.Delete(5) , true);
  REQUIRE(container_.Delete(5) , false);
  REQUIRE(container_.GetMedian() , 3);
  REQUIRE(container_.Delete(2) , false);
  REQUIRE(container_.Delete(3) , true);
  container_.GetMedian();
  container_.Add(1);
  container_.Add(1);
  container_.Add(2);
  container_.Add(2);
  container_.Add(2);
  REQUIRE(container_.GetMedian() , 2);
  REQUIRE(container_.Delete(2) , true);
  REQUIRE(container_.GetMedian() , 1);
  REQUIRE(container_.Delete(1) , true);
  REQUIRE(container_.GetMedian() , 2);
}
