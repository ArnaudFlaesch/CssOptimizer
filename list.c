#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_balise * balise_create(char * balise){
    list_balise * list = (list_balise *)malloc(sizeof(list_balise));    
    list->balise = balise;
    list->inside = NULL;
    list->next = NULL;
    return list;
}

list_property * property_create(char * property, char * value) {
    list_property * list_p = (list_property *)malloc(sizeof(list_property));    
    list_p->property = property;
    list_p->value = value;
    list_p->next = NULL;
    return (list_p);
}

list_balise * balise_append (list_balise * list, char * balise) {
    if (list) {
        list_balise * save = list;
        while (list->next != NULL) {
            list = list->next;     
        }
        list->next = balise_create(balise);
        return (save);
    }
    else {
        return(balise_create(balise));
    }
}

list_balise * property_append (list_balise * list, char * property, char * value) {
    list_balise * save = list; 
    while (list->next != NULL) {
        list = list->next;
    }
    if (!(list->inside->next)) {
        printf ("inside vide\n");
        list->inside = property_create(property, value);
    }
    else {
        while (list->inside->next != NULL) {
            list->inside = list->inside->next;
        }
        list->inside->next = property_create(property, value);
    }
    return (save);
}

void list_display (list_balise * list) {
    list_balise * save = list;
    while (save != NULL) {
        printf ("%s {\n",save->balise);
        while (save->inside != NULL) {
            printf ("%s : %s; \n",save->inside->property,save->inside->value);
            save->inside = save->inside->next;
        }
        printf("}\n");
        save = save->next;
    }
    free(save);
}

list_balise * tri_list( list_balise * list){
    list_balise * save = list,*save2 = list;
    while( save != NULL ){
        while( save->inside != NULL){
            while( save2 != NULL ){
                while( save2->inside != NULL){
                    save2->inside = save2->inside->next;   
                }
                save2 = save2->next;    
            }
            save->inside = save->inside->next;   
        }
        save = save->next;    
    }
    return (save);
}

void writeToFile (char * css_file_output,list_balise * list) {
    FILE * file_output = fopen(css_file_output,"w+");
    list_balise * save = list;
    while (save != NULL) {
        fprintf(file_output,"%s {",save->balise);
        while (save->inside != NULL) {
            fprintf (file_output,"%s : %s ;\n",save->inside->property,save->inside->value);
            save->inside = save->inside->next;
        }
        fprintf(file_output,"}\n");
        save = save->next;
    }
    fclose(file_output);
}

int equals (char * chaine1,char * chaine2) {  
    int i=0;
    while (chaine1[i] != '\0' || chaine2[i]!='\0') {
        if (chaine1[i] != chaine2[i]) {
            return (0);
        }
        i++;
    }
    return (1);
}

char * word_copy (char * word) {
    int i=0;
    char * word_copy;
    word_copy = (char *)malloc(sizeof(word));

    for (i=0;word[i] != '\0';i++){      
        
    } 
    int longueur = i;
	
    for (i=0;i<=longueur;i++) {
        word_copy[i] = word[i];
        if (word[i]=='\0') { word_copy[i] = '\0';}
    }
    
    return (word_copy);
}

char* concat(char* chaine1,char* chaine2) {
    int i=0,j=0;
    char * chaine3;
    chaine3 =(char *)malloc(2 * (sizeof(chaine1)+sizeof(chaine2)) );
    for (i=0;chaine1[i]!='\0';i++) {
        chaine3[i] = chaine1[i];
        j++;
    }
    chaine3[j]=44;
    j++;
    for (i=0;chaine2[i]!='\0';i++) {
        chaine3[j] = chaine2[i];
        j++;
    }
    chaine3[j+1]='\0';

    return(chaine3);
}
