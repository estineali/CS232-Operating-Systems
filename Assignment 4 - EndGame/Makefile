file = gp05_A4

all: client server 

client: gp05_client.c
	gcc gp05_client.c -l pthread -o client.comp

server: gp05_server.c
	gcc gp05_client.c -l pthread -o server.comp

wrap:
	make $(file).pdf 
	make cleantex
	tar -zcvf gp05_A4.tar.gz ./*.c ./Makefile ./gp05_A4.pdf ./*.tex


maketex : $(file).pdf
# assign4: 

$(file).pdf: *.tex *.c Makefile
	pdflatex $(file)
	pdflatex $(file)
	bibtex $(file).aux
	pdflatex $(file)
	pdflatex $(file)

cleantex:
	rm -f *.aux $(file).log $(file).lof $(file).toc $(file).bbl $(file).blg $(file).brf $(file).out *.snm *.nav *.gz *.fdb_latexmk *.fls

clear:
	rm -f *.comp