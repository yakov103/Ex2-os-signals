all : run

run : main
	./$^

main : main
	gcc main.c -w -o main ; ./main

clean : 
	rm *.o main