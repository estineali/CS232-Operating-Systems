namedpipe: read1 read2 read3 write

read1: proc1.c
	gcc proc1.c -o read1

read2: proc3.c
	gcc proc3.c -o read2

read3: proc4.c
	gcc proc4.c -o read3

write: proc2.c
	gcc proc2.c -o write

clean:
	rm read write 