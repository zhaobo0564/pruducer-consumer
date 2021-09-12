#ifndef PRODUCTION_H
#define PRODUCTION_H
#include <vector>
#include <mutex>
#include<condition_variable>
using namespace std;


class production {
  public:
    int size;       // size of warehouse
    vector<int> productions;
    production(){}
    production(int size) {
      this->size = size;
    }
};

#endif // !PRODUCTION_H
