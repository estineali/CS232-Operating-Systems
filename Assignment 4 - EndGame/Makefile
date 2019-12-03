all: *.c *.h	
	client server 
	

client: client.c
	gcc client* -l pthread -o client.comp

server: server.c
	gcc server* -l pthread -o server.comp

wrap:
	mv -i ./*.tar.gz ../endgame_old.tar.gz
	tar -zcvf go05_A4.tar.gz ./*.c ./*.h ./Makefile 
	#add pdf file aswell   ./go05_A4.pdf


clear:
	rm *.comp
