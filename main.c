#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// getting the platform using preprocessor directives
void clear(char platform) {
    switch (platform) {
        case 'L': // Linux
            system("cls");
            break;

        case 'W': // Windows
            system("clear");
            break;

        default:
            printf("System not recognized");
    }
}


int main(int argc, char *argv[]) {

    char folderName[50];
    int numOfFiles = 100;

    if (argc != 0) {
        for (int i = 1; i < argc; i++) {

            if (strcmp(argv[i], "--folder") == 0){
                sprintf(folderName, "%s", argv[i+1]);
            }

            else if (strcmp(argv[i], "--C") == 0) {
                numOfFiles = atoi(argv[i+1]);
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
    numOfFiles = index - 2; // Changed the number of files to the actual one
}