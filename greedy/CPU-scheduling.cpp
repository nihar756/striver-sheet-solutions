// Given a list of job durations representing the time it takes to complete each job. 
// Implement the Shortest Job First algorithm to find the average waiting time for these jobs

#include<bits/stdc++.h>
using namespace std;

float shortestJobFirst(vector<int> jobs) {
    // Sort the jobs in ascending order
    sort(jobs.begin(), jobs.end()); 

    // Initialize total waiting time
    float waitTime = 0; 
    // Initialize total time taken
    int totalTime = 0; 
    // Get the number of jobs
    int n = jobs.size(); 

    for(int i = 0; i < n; ++i) {
        waitTime += totalTime; 
        totalTime += jobs[i]; 
    }
    
    // Return the average waiting time
    return waitTime / n; 
}