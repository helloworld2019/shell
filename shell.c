#include "head.h"
#include "shell.h"
#include "pipe.h"
struct mypipe* mp ;
int main(){
	mp = (struct mypipe*)malloc(sizeof(struct mypipe));
	mp->init();
	char buffer[MAXBUFFER];
	char* argv[ARGC];
	for(int i2 = 0 ; i2 < MAXBUFFER ; i2++)buffer[i2]=0;
	prompt();
	while(read(0,buffer,MAXBUFFER)){
		if(buffer[0]=='q'&&buffer[1]=='\n')break;
		if(buffer[0]=='\n')continue;
		blank(buffer);
		int part = divide(buffer,argv);
		
		struct node* root =  operate(argv,0 ,part-1);

		deal(root);
	
		for(int i2 = 0 ; i2 < MAXBUFFER ; i2++)buffer[i2]=0;
		read(mp->r,buffer,MAXBUFFER);
		write(0,buffer,strlen(buffer));

		for(int i2 = 0 ; i2 < MAXBUFFER ; i2++)buffer[i2]=0;
		prompt();
	}	
	mp->remove();
}




/*

   printf() is delay output?
*/
