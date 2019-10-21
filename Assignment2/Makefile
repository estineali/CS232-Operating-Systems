compileall: mycat hush
	
mycat: Lec1_gp05_A2Q1_mycat.o
	clang Lec1_gp05_A2Q1_mycat.o -o mycat

hush: Lec1_gp05_A2Q2_Hush.o 
	clang Lec1_gp05_A2Q2_Hush.o -o hush

Lec1_gp05_A2Q2_Hush.o: Lec1_gp05_A2Q2_Hush.c
	clang -c Lec1_gp05_A2Q2_Hush.c

Lec1_gp05_A2Q1_mycat.o: Lec1_gp05_A2Q1_mycat.c
	clang -c Lec1_gp05_A2Q1_mycat.c

wrap:  
	tar -zcvf Lec1_gp05_A2.tar.gz ./Makefile ./*.c ./*.pdf

clean:  
	rm *.o mycat hush 