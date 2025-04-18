/*
Captura SIGTERM e imprime uma mensagem. O programa lê entradas do teclado até receber SIGTERM.
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sighandler (int signum) {
	printf ( "Hide SIGTERM\n" ) ;
}

int main ( void ){
	char buffer [256] ;
	if (signal(SIGTERM,&sighandler ) == SIG_ERR ){
		printf ( "NO  signal\n" ) ;
	}
	while(1){
		fgets(buffer, sizeof (buffer), stdin) ;
		printf (" Input : %s ", buffer ) ;
	}
	return 0 ;
}
