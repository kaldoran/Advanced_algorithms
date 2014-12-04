//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : imnotanesteregg.h                              |
// DATE : 02/11/14                                          |
//                                                          |
//----------------------------------------------------------

#ifndef EE
#define EE

/** Start aplay with the music
 *  %return : pid_t if work
 *            -1 if cant fork
 *            0 else
 */
pid_t spawn_aplay(char *file);

#endif /* EE include */
