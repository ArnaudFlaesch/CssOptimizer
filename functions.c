#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

// Permet de vérifier si le fichier cible existe
int file_exist(char * name_file) {
    FILE* fp;
    fp = fopen(name_file,"r");
    if(NULL == fp ){
        printf("File %s does not exists.\n",name_file);
        fclose(fp);
        return 0;
    }
    return 1;
}

// Permet de verifier si le fichier en entrée est bien de type .css
int is_css_file (char * file_input) {
    int i = 0;
    while (file_input[i] != '\0') {
        i++;
    }
    if (file_input[i-1]!='s' || file_input[i-2]!='s' || file_input[i-3]!='c' || file_input[i-4]!='.' ) {
        printf("File %s isn't a css file.\n",file_input);
        return 0;
    }
    return 1;
}