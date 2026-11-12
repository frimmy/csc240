#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "PQType.h"

template <class ItemType> class Scheduler : public PQType<ItemType> {
  public:
    Scheduler(int s);
    int getNumJobs() const;
    void setCurrentJob(ItemType& j);
    void addJob(ItemType& j);
    void removeJob(ItemType& j);

  private:
    int numJobs;
    ItemType currentJob;
};

template <class ItemType>
Scheduler<ItemType>::Scheduler(int size)
    : PQType<ItemType>(size)
// Post: queue is initialized to max capacity of `size` and numJobs is set to 0
{
    numJobs = 0;
}

template <class ItemType>
int Scheduler<ItemType>::getNumJobs() const
// Post: returns the current number of jobs in the heap
{
    return numJobs;
}

template <class ItemType>
void Scheduler<ItemType>::removeJob(ItemType& j)
// Pre: the queue has at least one job in its heap
// Post: the highest priority job is removed from the heap and the count is
// decremented
{
    this->Dequeue(j);
    numJobs--;
};

template <class ItemType>
void Scheduler<ItemType>::setCurrentJob(ItemType& j)
// post: current job is assigned to a copy of the job, j
{
    currentJob = j;
};

template <class ItemType>
void Scheduler<ItemType>::addJob(ItemType& j)
// Pre: the heap has capacity to have an item added
// Post: the heap is re-prioritized to ensure the heap's max job is at the top,
// and the count is incremented
{
    this->Enqueue(j);
    numJobs++;
};

#endif
