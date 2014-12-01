
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>    /* for fork, exec, kill */
#include <sys/types.h> /* for pid_t            */
#include <sys/wait.h> 

pid_t spawn_aplay(char *file) {
    pid_t pid = fork();
	char *cmd[] = { "aplay", "-D", "front", "-q", file, NULL };
    if (pid == -1) {
        fprintf(stderr, "Fork problem");
        return -1;
    }
    
	if (pid == 0) {
        execvp("aplay", cmd );
        fprintf(stderr, "Can't start aplay");
		return 0;
    } else {
        /* parent, return the child's PID back to main. */
        return pid;
    }

}

