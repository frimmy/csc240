#ifndef JOB_H
#define JOB_H
#include <ostream>
#include <string>

class Job {
  public:
    Job();
    Job(int p, int l);
    int getLength() const;
    void decrementLength();
    int getPriority() const;
    friend std::ostream& operator<<(std::ostream& out, const Job& j);
    bool operator<(Job otherJob);
    bool operator>(Job otherJob);
    bool operator==(Job otherJob);
    bool operator<=(Job otherJob);

  private:
    int length = 0;
    int priority = 0;
};
///////////////////////////////////////////////////////////////////////////////
//
// IMPLEMENTATION
//
///////////////////////////////////////////////////////////////////////////////

bool Job::operator<(Job otherJob)
// Post: returns whether job's priority is less than otherJob's priority
{
    return this->getPriority() < otherJob.getPriority();
};
bool Job::operator>(Job otherJob)
// Post: returns whether job's priority is greater than otherJob's priority
{
    return this->getPriority() > otherJob.getPriority();
};
bool Job::operator==(Job otherJob)
// Post: returns whether job's priority is equal to otherJob's priority
{
    return this->getPriority() == otherJob.getPriority();
};
bool Job::operator<=(Job otherJob)
// Post: returns whether job's priority is less than or equal to otherJob's
// priority
{
    return this->getPriority() <= otherJob.getPriority();
};

std::ostream& operator<<(std::ostream& out, const Job& j) {
    out << j.getLength() << std::endl;
    return out;
}

// Initializers
// Post: length/priority are set to sentinel values
Job::Job() : length(0), priority(-20) {};
Job::Job(int p, int l) : length(l), priority(p) {};

int Job::getLength() const
// Post returns the jobs' length
{
    return length;
}
void Job::decrementLength()
// Pre: length is positive
// Post: length is decremented by one
{
    length--;
}
int Job::getPriority() const
// Post: returns the job's priority
{
    return priority;
};

#endif
