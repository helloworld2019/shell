#include "head.h"
#include "shell.h"
#include "pipe.h"

extern struct mypipe* mp;

int divide_arg(char* arg , char* a[ARGC]){
	int i = 0;
	int flag = 1;
	while(*arg==32){
			arg++;
	}
	while(flag){
		a[i]=(char*)malloc(sizeof(char)*ARGL);
		for(int i1 = 0; i1 < ARGL ; i1++)a[i][i1]=0;
		int k = 0;
		while(*arg){
			if(*arg==' '){
				arg++;
				i++;
				break;
			}
			a[i][k]=*arg;
			k++;
			arg++;
		}
		if(*arg==0){
			flag = 0;
		}
	}
	return i;
}

void filecopy(int from , int to){
	char buffer[1000];
	for(int i = 0; i< 1000 ; i++)buffer[i]=0;
	int byte =	read(from,buffer,MAXBUFFER);
//	printf("%d bytes \n",byte);
//	printf("%s\n",buffer);
	byte = write(to,buffer,byte);
}


void clean(char* a[ARGC]){
	for(int i = 0; i < 20 ;i++){
		if(a[i]==0)break;
		free(a[i]);
	}
}

void excute(char* command){
	char* a[ARGC];
	for(int i =0 ; i< ARGC ;i++)a[i]=0;
	int argc = divide_arg(command , a );
	pid_t pid = fork();
	if(pid<0){
		perror("fork error");
		exit(1);
	}
	if(pid==0){
		int flag = open(a[0],O_RDWR);
		if(flag>0){
			dup2(mp->r,0);
			dup2(mp->w,1);
			execlp("cat","cat",a[0],NULL);
			exit(2);
		}
		dup2(mp->r,0);
		dup2(mp->w,1);
		execvp(a[0],a);
		exit(2);
	}
	waitpid(0,NULL,0);
	mp->transfer();
	clean(a);
}


