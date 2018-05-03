#include "head.h"
#include "shell.h"
extern int fd[2];
extern int tempory[2];
int divide_arg(char* arg , char* a[ARGC]){
	int i = 0;
	int flag = 1;
	while(flag){
		a[i]=malloc(sizeof(char)*ARGL);
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
	char buffer[100];
	for(int i = 0; i< 1000 ; i ++)buffer[i]=0;
	read(from,buffer,MAXBUFFER);
	write(to,buffer,strlen(buffer));
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
				dup2(fd[READ],0);
				dup2(tempory[WRITE],1);
				execvp(a[0],a);
				int t = open(a[0],O_RDWR);
				dup2(t,0);
				execlp("cat","cat",a[0],NULL);
				perror("exec error");
				exit(2);
			}
	wait(NULL);
	filecopy(tempory[WRITE],fd[READ]);	
	clean(a);
}


