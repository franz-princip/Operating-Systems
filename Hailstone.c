#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>



//Hailstone sequence with forked processes
int main()
{
	//int vars
	int k=0;
	//declare thread
	pid_t pid;
        
//input loop
		do
		{
			printf("Please enter a number greater than 0 (Example: 35)\n"); 
  			scanf("%d", &k);	
		}while (k <= 0);
//fork to make child
		pid = fork();
//main logic loop - checks if child
		if (pid == 0)
		{
			printf("Child is working...\n");
			printf("%d\n",k);
            //if child, run hailstone sequence			
            while (k!=1)
			{
				if (k%2 == 0)
				{
					k = k/2;
				}
				else if (k%2 == 1)
				{
					k = 3 * (k) + 1;
				}	
			
				printf("%d\n",k);
			}
		
			printf("Child process is done.\n");
		}
        //if parent, wait for child
		else
		{
			printf("Parents is waiting on child process...\n");
			wait();
			printf("Parent process is done.\n");
		}
	return 0; 
}
