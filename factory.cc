#include "factory.h"
#include "production.h"

void factory::add(production *pro) {
  unique_lock<mutex> lock_factory(*m);
  // The warehouse is full
  while (pro->productions.size() >= pro->size) {
    std::cout << "The warehouse is full. So Waking up the producter thread\n";
    std::cout << "The thread id is " << this_thread::get_id() << "\n";
    condProducer->wait(lock_factory);
  }
  int msg = rand() % 100;
  pro->productions.push_back(msg);
  condConsumer->notify_one();
  std::cout << "The factory produced: " << msg << "\n";
  

}