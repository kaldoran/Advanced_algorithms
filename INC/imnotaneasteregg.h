#ifndef EE
#define EE

/** Start aplay with the music
 *  %return : pid_t if work
 *            -1 if cant fork
 *            0 else
 */
pid_t spawn_aplay(void);

#endif /* EE include */
