#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>
#include <time.h>

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif



int main(int argc, char *argv[]) {

    char folderName[50];
    int numOfFiles = 100;

    // Leave the loop in case more options are added
    if (argc != 0) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "--folder") == 0){
                sprintf(folderName, "%s", argv[i+1]);
            }
        }
    }

    char filenames[numOfFiles][50];

    if (folderName[0] == '\0') { // If no folder is specified, return default
        sprintf(folderName, "%s", ".");
    }

    // Retrieving the files from the folder into an array

    struct dirent *de;
    DIR *dr = opendir(folderName);

    if (dr == NULL) {
        printf("Could not open directory\n");
        return 0;
    }

    int index = 0;
    while ((de = readdir(dr)) != NULL) { // Appending the source of the files
        sprintf(filenames[index], "%s/%s", folderName, de->d_name);
        index++;
    }


    closedir(dr);
    numOfFiles = index; // Changed the number of files to the actual one

    index = 2;
    while (true) {

        clrscr();


        if (index == numOfFiles) {
            index = 2;
        }

        FILE *currFrame = fopen(filenames[index], "r");

        char currbuff[50];
        do {
            if (fgets(currbuff, 49, currFrame) == NULL){
                break;
            }
            printf("%s", currbuff);
        }
        while (currbuff[0] != '\0');

        fclose(currFrame);
        index++;

        nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
    }
}