#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "list.h"

int main(int argc, char** argv) {
    
    int i_word = 0, i_files=1; // Variable incrémentée à chaque fois qu'on ouvre un nouveau fichier
    char lecture, *balise, *property, *value,word[256];
    char *filename,* css_file_input,* css_file_output; // Respectivement les variables qui vont contenir les noms des fichiers 
                                                   // d'entrée et de sortie
    
    FILE *file_input,*file_output;
    list_balise * list = NULL;
    argc = 4;
    argv[1,1] = "style.css"; // Fichier d'entrée
    argv[1,2] = "style2.css"; // Fichier d'entrée
    argv[1,3] = "result.css"; // Fichier de sortie
    
    if (3 > argc) { // On vérifie qu'on a bien au moins un fichier entrée et un fichier sortie en paramètres
        printf("Not enough parameters.\n");
        return (1);
    }
    
    while (i_files<argc-1) {
        filename = argv[1,i_files];
        file_exist(filename);
        is_css_file(filename);                
        i_files++;
    }
    
    filename = argv[1,i_files];
    if (NULL != (file_output = fopen(filename,"r"))) {
        printf("Output file %s already exists.\n",filename);
        fclose(file_output);
    }
    else {
        css_file_output = filename;
        fclose(file_output);
    }
    for (i_files=1;i_files<argc-1;i_files++) {
        css_file_input = argv[1,i_files];
        file_input = fopen(css_file_input,"r");
        if (NULL == file_input) {
            printf("Cannot read from file %s.\n",css_file_input);
            fclose(file_input);
            return (1);
        }
        else {
            /*while ((lecture=fgetc(file_input))!= EOF) {
                switch (lecture) {
                    case '{' : word[i_word]='\0';balise = word_copy(word);word[0]='\0';i_word=0;list = balise_append(list,balise);break;
                    case ':' : word[i_word]='\0';property = word_copy(word);word[0]='\0';i_word=0;break;
                    case ';' : word[i_word]='\0';value = word_copy(word);word[0]='\0';i_word=0;
                                list = property_append(list,property,value);
                                break;
                    case '}' : word[i_word]='\0';word[0]='\0';i_word=0;break;
                    case ' ' : break;
                    case '\t' : break;
                    case '\n' : break;
                    default : word[i_word]=lecture;i_word++; break;
                }  
            }
            fclose(file_input);*/
        }
    }

    list = balise_append(list,"div");
    list = property_append(list,"margin","0");
    list = property_append(list,"height","100%");
    list = property_append(list,"top","0px");
    list = property_append(list,"color","blue");
    list = balise_append(list,"p");
    list = property_append(list,"margin","1");
    list = balise_append(list,"h1");
    list = property_append(list,"margin","2");
    list = balise_append(list,"p");
    list = property_append(list,"margin","2");
    
    list_display(list);
    //list = tri_list(list);
    
    //writeToFile(css_file_output,list);
    
    return (EXIT_SUCCESS);
}



