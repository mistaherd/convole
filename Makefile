# Defult rule to build the target
all:convole_2D convole_encoder Overlap_and_save 

# link object
convole.o: convole.c convole.h
	gcc -c convole.c -o convole.o
zeropad.o: zeropad.c zeropad.h
	gcc -c zeropad.c -o zeropad.o
Indexing.o: Indexing.c Indexing.h
	gcc -c Indexing.c -o Indexing.o
convole_2D: convole_2D.c
	gcc convole_2D.c -o convole_2D

convole_encoder:convoletional_encoder.c
	
	gcc convoletional_encoder.c -o convoletional_encoder 
Overlap_and_save:Overlap_and_save.c convole.o zeropad.o Indexing.o
	gcc Overlap_and_save.c convole.o zeropad.o Indexing.o -o Overlap_and_save

Overlap_and_save_no_headers:Overlap_with_all_code.c
	gcc Overlap_with_all_code.c -o Overlap_with_all_code
clean:
	del /Q *.o *.exe 2>nul || true
