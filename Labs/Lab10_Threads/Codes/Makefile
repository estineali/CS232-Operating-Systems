task: todo_51.c
	gcc todo_51.c -l pthread -o task

my_making: threaded

all: no_join ret2 argThreads creation

threaded: Threaded.c
	gcc Threaded.c -l pthread -o threaded

no_join: thread_no_join.c
	gcc thread_no_join.c -l pthread -o no_join

ret2:	thread_ret2.c
	gcc thread_ret2.c -l pthread -o ret2

argThreads: thread_args.c
	gcc thread_args.c -l pthread -o argThreads

creation: thread_create.c
	gcc thread_create.c -l pthread -o creation

clean:
	rm creation argThreads ret2 no_join threaded 