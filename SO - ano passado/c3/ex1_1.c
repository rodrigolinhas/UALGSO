#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int i = 0;

void sighandler() {
	i++;
	if(i < 5){
		printf("\nnice try\n");
	}
	else{
		printf("\nyou got me this time\n");
	}
}

int main (int argc, char* argv[]){
	while(1){
		if (signal(SIGINT,&sighandler) == SIG_ERR ){
			printf ( "NO  signal\n" ) ;
		}
		if(i == 5){
			break;
		}
	}
	return 0 ;
}
