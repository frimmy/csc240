// Lab 12 driver
// invariant my heap maintains: after every insertion and removal, the children
// nodes in the max heap binary tree are less than or equal to their parent
// nodes, and the root is greater than or equal to its children.
// This occurs in Scheduler addJob (which restores the order via ReheapUp) and
// removeJob(which restores order via ReheapDown)
#include <fstream>
#include <iostream>
typedef int ItemType;
#include "Job.h"
#include "Scheduler.h"
#include <random>

using namespace std;

void simulation(int& successfulSimulations);
int main() {
    int simulationCount = 0;
    int successfulSimulations = 0;
    while (simulationCount < 1000) {
        simulation(successfulSimulations);
        simulationCount++;
    }
    cout << "Completed simulations: " << successfulSimulations << endl;
    cout << "Incomplete simulations: " << 1000 - successfulSimulations << endl;
    return 0;
}

void simulation(int& successfulSimulations) {
    Scheduler<Job> scheduler(50);

    // randomly create jobs
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> jobPriority(-19, 20);
    std::uniform_int_distribution<int> jobLength(1, 100);
    std::uniform_int_distribution<int> coinFlip(0, 1);

    // simulation
    // derived from using AI transcript to achieve p_0 = 95% completion
    // over 1000 runs
    // running 5 times yields 95% reliability rate
    int MAX_CYCLES = 2928;
    int cycleIdx = 0;
    int jobsEnqueued = 0;
    int jobsProcessed = 0;
    int jobsInHeap = 0;
    Job currentJob;
    while (cycleIdx < MAX_CYCLES && jobsProcessed < 50) {
        // process, - and check that we've not processed 50 jobs before
        // proceeding
        if (currentJob.getLength() != 0) {
            currentJob.decrementLength();
            if (currentJob.getLength() == 0) {
                // bump processed
                jobsProcessed++;
            }
        }

        // arrive, check that 50 jobs haven't arrived
        // cycle 0 is where we begin check for eligible cycles
        if (cycleIdx % 20 == 0 && coinFlip(gen) && jobsEnqueued < 50) {
            // add a job
            jobsEnqueued++;
            Job j(jobPriority(gen), jobLength(gen));
            scheduler.addJob(j);
        }

        // schedule, CPU idle
        if (currentJob.getLength() == 0 && scheduler.getNumJobs() > 0) {
            scheduler.removeJob(currentJob);
            scheduler.setCurrentJob(currentJob);
        }
        // tally cycles++;

        jobsInHeap += scheduler.getNumJobs();
        cycleIdx++;
    }
    cout << "Average number of jobs in the heap per cycle: "
         << jobsInHeap / cycleIdx << endl;
    if (jobsProcessed == 50) {
        cout << "The scheduler completed all 50 jobs." << endl;
        cout << "It took " << cycleIdx << " cycles to complete them." << endl;
        successfulSimulations++;
    } else {
        cout << "The scheduler did not complete all 50 jobs." << endl;
        cout << "Jobs processed: " << jobsProcessed << endl;
    }
}
