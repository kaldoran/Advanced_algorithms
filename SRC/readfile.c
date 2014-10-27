//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : readfile.h                                     |
// DATE : 27/10/14                                          |
//                                                          |
// - Read a file give in input                              |
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "readfile.h"

#define BUFFER_SIZE 1024

void load(const char *filename) {

	FILE *file;

	unsigned int i= 0, j = 0;
	char buffer[BUFFER_SIZE];

	if ((file = fopen(filename, "r")) == NULL ) {
		QUIT_MSG("Error while opening the file\n");
	}

	while(fgets(buffer, BUFFER_SIZE, file) != NULL ) {
		if ( *buffer == '$' ) {
			(void)sscanf(buffer, "$%u$", &i);
			printf("Number of Node : %u\n", i);
		}
		else if ( *buffer == '-' ) {
			(void)sscanf(buffer, "- %u@%u", &i, &j);
			printf("Node : %u - Number of Subnode : %u\n", i, j);
		}
		else {
			(void)sscanf(buffer, "%u#%u", &i, &j);
			printf("\tSubnode : %u - Weight: %u\n", i, j);
		}
	}
}
