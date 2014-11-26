
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int playSound( char *filename ) {
    char command[256];
    int status;

    /* create command to execute */
    sprintf( command, "aplay -c 1 -q -t wav %s", filename );

    /* play sound */
    status = system( command );
     
    return status;
}

int main( int argc, char *argv[] ) {
    if ( argc < 2 ) {
        printf("Syntax:  playSound filename.wav\n\n" );
        exit( 1 );
    }

    /* play the wav file 3 times in a row */
    playSound( argv[1] );
    playSound( argv[1] );
    playSound( argv[1] );

    return 0;
}
