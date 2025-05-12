# Defult rule to build the target
all:convole convole_2D convole_encoder Overlap_and_save

# link object
convole: convole.c
	gcc  convole.c -o convole
convole_2D: convole_2D.c
	gcc convole_2D.c -o convole_2D
convole_encoder:convoletional_encoder.c
	gcc  convoletional_encoder.c -o convole_encoder 
Overlap_and_save:Overlap_and_save.c
	gcc Overlap_and_save.c -o Overlap_and_save
clean:
	del convole_encoder.exe
	del convole_2D.exe
	del convole.exe
	del Overlap_and_save.exe
