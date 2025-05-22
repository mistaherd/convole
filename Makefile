# Defult rule to build the target
all:convole_2D convole_encoder Overlap_and_save test

# link object
convole.o: convole.c convole.h
	gcc -c convole.c -o convole.o
zeropad.o: zeropad.c zeropad.h
	gcc -c zeropad.c -o zeropad.o
convole_2D: convole_2D.c
	gcc convole_2D.c -o convole_2D
convole_encoder:convoletional_encoder.c
	gcc convoletional_encoder.c -o convoletional_encoder 
Overlap_and_save:Overlap_and_save.c convole.o zeropad.o
	gcc Overlap_and_save.c convole.o zeropad.o -o Overlap_and_save
test: test.c
	gcc test.c -o Test
clean:
	del /Q *.o *.exe 2>nul || true
