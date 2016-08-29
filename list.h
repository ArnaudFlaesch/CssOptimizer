typedef struct list_balise {
    char * balise;
    struct list_property * inside;
    struct list_balise * next;
}list_balise;  
    
typedef struct list_property {
    char * property;
    char * value;
    struct list_property * next;
}list_property;

list_balise * balise_create(char * balise);
list_property * property_create(char * property, char * value);
list_balise * balise_append (list_balise * list, char * balise);
list_balise * property_append (list_balise * list, char * property, char * value);
list_balise * list_remove (list_balise * list, int index);
void list_display (list_balise * list);

list_balise * tri_list(list_balise * list);
void writeToFile(char * css_file_output,list_balise * list);
int equals (char * chaine1,char * chaine2);
char * list_concat(char *chaine1,char *chaine2);
char * word_copy (char * word);