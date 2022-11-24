all1: run1 clean1
all2: run2 clean2

run1:
	gcc -o forkchecker forkchecker.c
	sh running.sh

run2:
	rm -rf OTHER.txt RR.txt FIFO.txt
	gcc -o createfiles2 createfiles2.c
	./createfiles2
	gcc -o OS1_1 OS1_1.c
	./OS1_1

reset1:
	rm -rf fork1.txt fork2.txt fork3.txt
	gcc -o createfiles createfiles.c
	./createfiles

clean1:
	rm forkchecker
clean2:
	rm createfiles2 OS1_1
