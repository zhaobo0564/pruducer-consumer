#include "production.h"
#include "consumer.h"
#include "factory.h"
#include <mutex>
#include<thread>
using namespace std;



mutex m;
condition_variable condConsumer;
condition_variable condProducer;

int main(int argc, char **argv) {
  production *pro = new production(100);
  factory fa;
  consumer co;
  fa.set(&m, &condConsumer, &condProducer);
  co.set(&m, &condConsumer, &condProducer);
  thread Factory(fa, pro);
  thread Consume(co, pro);
  
  Consume.join();
  Factory.join();
}