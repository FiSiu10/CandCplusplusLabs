/* Uses multiple threads to increment a shared counter.
 * If -DMUTEX is specified at compile time, a
 * mutex protects against concurrent modification.
 * Without the mutex, the result is incorrect!
 * Also prints out the CPU time.
 *
 * The number of threads and the number of increments per
 * thread must be given on the command line.
 *
 * Dale Shpak
 * Sept 4, 2017
 */

// Turn off mutex code -> -DNO_MUTEX in additional outputs

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#define MIN_THREADS 2
#define MIN_ITERS 1000

using namespace std;
static long total = 0;
static pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;

/* Code that is run by each thread to repeatedly
 * increment the shared counter
 */
void *countUp (void *np) {
  long n = *((long *)np);

  for (int k=0; k < n; k++) {
#ifndef NO_MUTEX
      pthread_mutex_lock(&mymutex);
#endif
      ++total;
#ifndef NO_MUTEX
      pthread_mutex_unlock(&mymutex);
#endif
  }
  return NULL;
}

int main (int argc, char *argv[]) {
  clock_t start, end;
  
  int nThreads;
  long nIters;
  
  if (argc != 3){
      std::cerr << "Error: Need 2 arguments" << std::endl;
      return EXIT_FAILURE;
  }
  
  if (sscanf(argv[1], "%d", &nThreads) != 1){
      cerr << "Error: cannot read integer" << endl;
      return EXIT_FAILURE;
  }
  if (nThreads < MIN_THREADS){
      std::cerr << "Error: Does not meet minimum" << std::endl;
      return EXIT_FAILURE;
  }
  if (sscanf(argv[2], "%ld", &nIters) != 1){
      cerr << "Error: cannot read number of threads" << endl;
      return EXIT_FAILURE;
  }
  if (nIters < MIN_ITERS){
      std::cerr << "Error: Does not meet minimum" << std::endl;
      return EXIT_FAILURE;
  }

  pthread_t *threadIDs = (pthread_t *) malloc(nThreads * sizeof(pthread_t));

  start = clock();

  for (int k=0; k < nThreads; k++) {
    // Passing nIters as shown below is unsafe if nIters changes!
    // This is because we are passing a pointer to nIters
    pthread_create (&threadIDs[k], NULL, countUp, (void *) &nIters);
  }

  // The main() thread needs to wait for the other threads to complete.
  // Otherwise main() will complete before our worker threads
  for (int k=0; k < nThreads; k++) {
    pthread_join (threadIDs[k], NULL);
  }

  end = clock();

  printf("Total is %ld.  It should be %ld.  %lf%% success. CPU time %lf ms\n",
	 total, nIters*nThreads, 100.0*total/(nIters*nThreads), 1000.0*(end - start) / CLOCKS_PER_SEC);

  free (threadIDs);  // Not really needed here since main() is completing...

  return EXIT_SUCCESS;
}

/* Question 4
 * 
 * 4a) Without the compiler flag -> Total is 2000000.  It should be 2000000.  100.000000% success. CPU time 2615.455000 ms
 *     With the compiler flag -> Total is 1748551.  It should be 2000000.  87.427550% success. CPU time 9.486000 ms
 * 4b) The wrong answer is computed when there is no mutex because all the threads start and use the same total variable which prevents it from finishing. 
 * 4c) Using the mutex increases the run time because only one thread can use the total varible at a time. It has to  wait until the previous 
 *      thread is done with total until it can start.
 */