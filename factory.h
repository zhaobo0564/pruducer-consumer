#ifndef FACTORY_H
#define FACTORY_H

#include "production.h"
#include <thread>
#include <iostream>

class factory{
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
        add(pro);
      }
    }
    void add(production *pro);
    
};

#endif // !FACTORY_H