all : shell.o prompt.o  blank.o operate.o divide.o excute.o 
	 @gcc -o shell shell.o prompt.o  blank.o operate.o divide.o excute.o 
	 @rm *.o

debuge: shell.o prompt.o  blank.o operate.o divide.o
	 	@gcc -o st shell.o prompt.o  blank.o operate.o divide.o excute.o  -g
	 	@rm *.o

shell.o : shell.c head.h shell.h
		 @gcc -c shell.c  -g

prompt.o: prompt.c head.h
		 @gcc -c prompt.c 	-g


blank.o: blank.c
		 @gcc -c blank.c   -g  

operate.o: operate.c
			@gcc -c operate.c -g


divide.o: divide.c
		  @ gcc -c divide.c -g


excute.o: excute.c
			@gcc -c excute.c -g 

clean:	
	@rm shell

run:
	@./shell
