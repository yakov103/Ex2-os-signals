#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void sig_handler(int signum)
{

	switch (signum) {
        // the first signal : when the child got out  . 
		case SIGCHLD:
			printf("I am in SIGCHILD !!\n");
            sleep(1);
			fflush(stdout);
			raise(SIGUSR1);

        // second signal : we raised our USR1 signal .
		case SIGUSR1: 
			printf("I am in SIGUSR!1\n");
            sleep(1);
			fflush(stdout);
			int b = 5/0 ;
			fflush(stdout);
			break;
        // third signal : try to devide by zero 
		case SIGFPE:
			printf("I am SIGFPE !!!\n");
            sleep(1);
			fflush(stdout);
			raise(SIGUSR2); 
            break ; 
		// fourth signal : we raised our USR2 signal .
        case SIGUSR2: 
            printf("I am SIGUSR2 !!!\n");
            sleep(1);
            fflush(stdout); 
            int *ptr = 0 ; 
            *ptr= 1000;
            break ; 
        // fifth signal : invalid memory signal 
        case SIGSEGV: 
            printf ("I am SIGSEGV !! \n");
            printf( "5 signals done , thank you for your time !\n "); 
            exit(1); 


    }


        
}


int main()
{
	int status;
	signal (SIGCHLD, sig_handler);
	signal (SIGUSR1, sig_handler);
    signal (SIGUSR2, sig_handler);
	signal (SIGFPE, sig_handler);
    signal (SIGSEGV, sig_handler); 
    signal (SIGSTOP , sig_handler);
    	if (!(fork())) {
		exit(1);
	}
	wait(&status);
    

}