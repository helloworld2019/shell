#include "head.h"
#include "shell.h"

int divide(char* b , char* a[ARGC]);

int fd[2];
int tempory[2];
int main(){
	char buffer[MAXBUFFER];
	char* argv[ARGC];
	pipe(fd[2]);
	pipe(tempory[2]);
	for(int i2 = 0 ; i2 < MAXBUFFER ; i2++)buffer[i2]=0;
	prompt();
	while(read(0,buffer,MAXBUFFER)){
		if(buffer[0]=='\n')continue;
		blank(buffer);
		int part = divide(buffer,argv);
		
		struct node* root =  operate(argv,0 ,part-1);

		deal(root);

		for(int i2 = 0 ; i2 < MAXBUFFER ; i2++)buffer[i2]=0;
		prompt();
	}	
}




/*

   printf() is delay output?
*/
