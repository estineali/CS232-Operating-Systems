compileall: mycat hush
	
mycat: Lec1_gp05_A2Q1_mycat.o
	gcc Lec1_gp05_A2Q1_mycat.o -o mycat

hush: Lec1_gp05_A2Q2_Hush.o 
	gcc Lec1_gp05_A2Q2_Hush.o -o hush

Lec1_gp05_A2Q2_Hush.o: Lec1_gp05_A2Q2_Hush.c
	gcc -c Lec1_gp05_A2Q2_Hush.c

Lec1_gp05_A2Q1_mycat.o: Lec1_gp05_A2Q1_mycat.c
	gcc -c Lec1_gp05_A2Q1_mycat.c

wrap:  
	tar -zcvf Lec1_gp05_A2.tar.gz ./Makefile ./*.c ./Lec1_gp05_A2.pdf ./*.tex

clean:  
	rm *.o mycat hush 