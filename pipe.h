#include "head.h"

struct mypipe{
	
	int r ;
	int w ;

	void init(){
		r = open("tepread",O_RDWR|O_CREAT,0666);
		w = open("tepwrite",O_RDWR|O_CREAT,0666);
	}

	void clean(int fd){
		ftruncate(fd,0);
		lseek(fd,0,SEEK_SET);
	}

	int transfer(){
		char buffer[210];
		for(int i = 0; i < 200 ; i++)buffer[i]=0;
		lseek(w,0,SEEK_SET);
		int n = read(w,buffer,200);
		clean(w);
		clean(r);
		write(r,buffer,n);
		lseek(r,0,SEEK_SET);
		return n ;
	}	

	void remove(){
		close(r);
		close(w);
		unlink("tepread");
		unlink("tepwrite");
	}
};
/*
int main(){
	struct mypipe* p = (struct mypipe*)malloc(sizeof(struct mypipe));
	p->init();
	char *a="0123456789";
	char b[100]={0};
	char buffer[100]={0};
	write(p->w,a,strlen(a));
	int n =p->transfer();
	read(p->r,buffer,n);
	printf("%s",buffer);
	p->remove();
}
*/
