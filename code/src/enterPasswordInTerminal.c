#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>

int main(int argc, char **argv)
{
    char password[100];
    struct termios oldFlags;
    struct termios newFlags;

    //Get the terminal current attributes and save them in oldFlags to restore the old attributes later
    tcgetattr(fileno(stdin), &oldFlags);

    //Set the newFlags. The ~ECHO will disable echo flag
    //Also add a newline ECHONL to the flags
    newFlags = oldFlags;
    newFlags.c_lflag &= ~ECHO;
    newFlags.c_lflag |= ECHONL;

    //Set the new terminal attributes
    //  TCSADRAIN = the change occurs after all output written to stdin file descriptor has been transmitted
    //  This function should be used when changing parameters that affect output
    if(tcsetattr(fileno(stdin), TCSADRAIN, &newFlags) != 0)
    {
        perror("tcsetattr()");
        exit(1);
    }

    //Ask for password from the user
    printf("Enter password (Echo is disabled): ");
    fgets(password, sizeof(password), stdin);
    password[strlen(password)-1] = '\0';
    printf("Entered password: %s\n", password);

    //Set the old saved terminal attributes i.e. restore the terminal back to old state
    //  TCSANOW = the change occurs immediately
    if(tcsetattr(fileno(stdin), TCSANOW, &oldFlags) != 0)
    {
        perror("tcsetattr()");
        exit(1);
    }

    //Ask for password from the user
    printf("Enter password (Echo is enabled): ");
    fgets(password, sizeof(password), stdin);
    password[strlen(password)-1] = '\0';
    printf("Entered password: %s\n", password);

    return 0;
}
