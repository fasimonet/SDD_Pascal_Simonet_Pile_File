#===================================================
# Nom du fichier : Makefile
# Date de creation : 20/03/2019
# Auteurs : Julien PASCAL et Fabien SIMONET (G21)
# Objectif : 
#	- automatiser la compilation
#	- faire de la compilation separee
#===================================================

#===================================================
# EXECUTABLES A COMPILER
#===================================================
all: main manipulation_truc

#===================================================
# COMPILATEUR
#===================================================
CC = gcc

#===================================================
# OPTIONS DE COMPILATION
#===================================================
CFLAGS = -Wall -Wextra -g -O0

#===================================================
# FICHIERS OBJETS
#===================================================

# fichiers .o communs a tous les executables
COMMON_OBJ = file.o pile.o truc.o

# fichier .o relatif a l'executable "main"
MAIN_OBJ = main.o

# fichier .o relatif a l'executable "manipulation_truc"
MANIP_TRUC_OBJ = manipulation_truc.o

#===================================================
# REGLES DE PRODUCTION FINALES
#===================================================

# production executable "main"
main: 	$(COMMON_OBJ) $(MAIN_OBJ)
		$(CC) $(COMMON_OBJ) $(MAIN_OBJ) -o main

# production executable "manipulation_truc"
manipulation_truc: 	$(COMMON_OBJ) $(MANIP_TRUC_OBJ)
					$(CC) $(COMMON_OBJ) $(MANIP_TRUC_OBJ) -o manipulation_truc

#===================================================
# REGLE DE PRODUCTION DES .o
#===================================================

# production fichier objet "manipulation_truc.o"
manipulation_truc.o: 	manipulation_truc.c
			$(CC) -c manipulation_truc.c $(CFLAGS)

# production fichier objet "main.o"
main.o: 	main.c
			$(CC) -c main.c $(CFLAGS)

#===================================================
# NETTOYAGE DES .o
#===================================================
clean:
			@rm -f *.o

#===================================================
# NETTOYAGE DES EXECUTABLES
#===================================================
mrproper:
			rm -f main
			rm -f manipulation_truc