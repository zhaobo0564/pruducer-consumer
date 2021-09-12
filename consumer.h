#ifndef CONSUMER_H
#define CONSUMER_H
#include "production.h"
#include <iostream>
using namespace std;

class consumer {
  public:
    mutex *m;
    condition_variable *condConsumer;
    condition_variable *condProducer;
    void set(mutex *m, condition_variable *condConsumer, condition_variable *condProducer) {
      this->m = m;
      this->condConsumer = condConsumer;
      this->condProducer = condProducer;
    }

    void operator()(production *pro){
      while (true) {
        pop(pro);
      }
      
    }
    void pop(production *pro);
};

#endif // !CONSUMER_H
