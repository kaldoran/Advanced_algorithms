//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : readfile.h                                     |
// DATE : 25/10/14                                          |
//                                                          |
// - Prototypes of function of readfile.c                   |
// - Function to read a file                                |
//----------------------------------------------------------

#ifndef READFILE_H
#define READFILE_H

#include "struct_graph.h"

/** Load a file and print the content
 * %param filename : name of the file to load 
 */
Graph load(const char *filename);

#endif /* READFILE_H included */
