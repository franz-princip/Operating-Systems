#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Global variables
double avg=0.0;
int minValue=0, maxValue=0;
int len;

/* calcAvg calculates average of values */
void *calcAvg(void *arg)
{
   int sum = 0;
   int *values;

   //Fetching array
   values = (int*)arg;

   //Iterating over array
   for(int i=0; i<len; i++)
   {
       //Accumulating sum
       sum = sum + values[i];
   }

   //Calculating average
   avg = sum / (double)len;

   return NULL;
}

/* calcMin calculates minimum of values */
void *calcMin(void *arg)
{
   int i = 0;
   int *values;

   //Fetching array
   values = (int*)arg;

   //Initializing minimum value as starting element
   minValue = values[0];

   //Iterating over array
   for(i=0; i<len; i++)
   {
       //Comparing value
       if(values[i] < minValue)  
       {
           //Updating minimum value
           minValue = values[i];
       }
   }

   return NULL;
}

/* Function that calculates maximum of values */
void *calcMax(void *arg)
{
   int i = 0;
   int *values;

   //Fetching array
   values = (int*)arg;

   //Initializing maximum value as starting element
   maxValue = values[0];

   //Iterating over array
   for(i=0; i<len; i++)
   {
       //Comparing value
       if(values[i] > maxValue)  
       {
           //Updating maximum value
           maxValue = values[i];
       }
   }

   return NULL;
}

/* Main function */
int main(int argc, char* argv[])
{
    //array dec and argc length set
    len = argc-1;
    int m = argc - 1;
    int values[m];
   //input loop
    for (int i = 0; i < m; i++) {
        values[i] = atoi(argv[i + 1]);
    }

   //Thread identifiers
   pthread_t avgPth, minPth, maxPth;  

   //Creating three threads one for each operation
   pthread_create(&avgPth, NULL, (void*)calcAvg, values);
   pthread_create(&minPth, NULL, (void*)calcMin, values);
   pthread_create(&maxPth, NULL, (void*)calcMax, values);
  
   //Waiting till all threads finish their work to execute
   pthread_join(avgPth, NULL);
   pthread_join(minPth, NULL);
   pthread_join(maxPth, NULL);
  
   //Printing results
   printf(" average: %d \n", (int)round(avg));
   printf("Minimum: %d \n", minValue);
   printf("Maximum: %d \n", maxValue);

   return 0;
}

