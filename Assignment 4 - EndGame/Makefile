file = gp05_A4

all: *.c *.h	
	make client 
	make server 
	

client: client.c
	gcc client* -l pthread -o client.comp

server: server.c
	gcc server* -l pthread -o server.comp

wrap:
	make $(file).pdf 
	make cleantex
	tar -zcvf gp05_A4.tar.gz ./*.c ./*.h ./Makefile ./gp05_A4.pdf ./*.tex

assign4: $(file).pdf

maketex : assign4

$(file).pdf: *.tex *.c Makefile *.h
	pdflatex $(file)
	pdflatex $(file)
	bibtex $(file).aux
	pdflatex $(file)
	pdflatex $(file)

cleantex:
	rm -f *.aux $(file).log $(file).lof $(file).toc $(file).bbl $(file).blg $(file).brf $(file).out *.snm *.nav *.gz *.fdb_latexmk *.fls

clear:
	rm -f *.comp