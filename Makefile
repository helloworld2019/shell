all: shell.o prompt.o  blank.o operate.o divide.o excute.o 
	 @g++ -o shell shell.o prompt.o  blank.o operate.o divide.o excute.o 
	 @rm *.o

debuge: shell.o prompt.o  blank.o operate.o divide.o excute.o
	 	@g++ -o st shell.o prompt.o  blank.o operate.o divide.o excute.o  -g
	 	@rm *.o

shell.o: shell.c head.h shell.h
		 @g++ -c shell.c  -g

prompt.o: prompt.c head.h
		 @g++ -c prompt.c 	-g


blank.o: blank.c
		 @g++ -c blank.c   -g  

operate.o: operate.c
			@g++ -c operate.c -g


divide.o: divide.c
		  @ g++ -c divide.c -g


excute.o: excute.c
		@g++ -c excute.c -g 

		
clean:	
	@rm shell

run:
	@./shell
