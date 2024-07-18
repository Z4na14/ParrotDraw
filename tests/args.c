#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char folderName[] = "./frames";
    int numOfFiles = 50;

    if (argc != 0) {
        for (int i = 1; i < argc; i++) {
            printf("%s ", argv[i]);

            if (strcmp(argv[i], "--folder") == 0){
                sprintf(folderName, "%s", argv[i+1]);
            }

            else if (strcmp(argv[i], "--C") == 0) {
                numOfFiles = atoi(argv[i+1]);
            }
        }
    }

    printf("\n");
    printf("%s\n", folderName);
    printf("%d\n", numOfFiles);
}