#include "consumer.h"
#include "production.h"
#include <iostream>
#include <thread>

void consumer::pop(production *pro) {
  unique_lock<mutex> lock_consumer(*m);
  while (pro->productions.size() == 0) {
    std::cout << "The warehouse is empty. So Waking up the consumer thread\n";
    std::cout << "The thread id is " << std::this_thread::get_id() << "\n";
    condConsumer->wait(lock_consumer);
  }
  int msg = pro->productions.back();
  pro->productions.pop_back();
  condProducer->notify_one();
  std::cout << "The factory consume: " << msg << "\n";
  
}