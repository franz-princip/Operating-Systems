Compile:
gcc -Wall -pthread -o  q5 q5.c -lm

Run:
./q5

Sample Input: 90, 81, 78, 95, 79, 72, 85 

Sample Output:
Improperly rounded average: 82 
Properly rounded average: 83 

C rounds down when you typecast floats/doubles to int, and sum(90, 81, 78, 95, 79, 72, 85)/7 is: 82.857143 - use c.math.round

Minimum: 72 
Maximum: 95 

