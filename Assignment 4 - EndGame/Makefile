file = gp05_A4

all: client server 

client: gp05_client.c
	gcc gp05_client.c -l pthread -o client.comp

server: gp05_server.c
	gcc gp05_server.c -l pthread -o server.comp

wrap: 
	tar -zcvf gp05_A4.tar.gz ./*.c ./Makefile ./gp05_A4.pdf ./*.tex

maketex : $(file).pdf

$(file).pdf: *.tex *.c Makefile
	pdflatex $(file)
	pdflatex $(file)
	bibtex $(file).aux
	pdflatex $(file)
	pdflatex $(file)

clean:
	rm -f *.comp *.aux $(file).log $(file).lof $(file).toc $(file).bbl $(file).blg $(file).brf $(file).out *.snm *.nav *.gz *.fdb_latexmk *.fls

submission:
	make 
	make maketex
	make clean
	make wrap