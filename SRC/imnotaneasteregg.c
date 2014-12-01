
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>    /* for fork, exec, kill */
#include <sys/types.h> /* for pid_t            */
#include <sys/wait.h> 

pid_t spawn_aplay(void) {
    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Fork problem");
        return -1;
    }
    
	if (pid == 0) {
        execl("/bin/aplay", "aplay -q sound.wav", (char*)NULL);
        fprintf(stderr, "Can't start aplay");
		return 0;
    } else {
        /* parent, return the child's PID back to main. */
        return pid;
    }

}

