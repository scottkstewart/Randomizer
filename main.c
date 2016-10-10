#include <stdio.h>  // printf
#include <stdlib.h> // malloc, free
#include <string.h> // strcmp, strcpy, rand, etc.
#include <time.h>   // time
int main(int argc, char **argv){
    // Declare/allocate pointers for a template and options to randomly select from (max len-80)
    char *template = 0;
    char **options = malloc((argc-1)*sizeof(char*));
    for(int i=0; i<argc-1; i++)
        options[i] = malloc(80*sizeof(char*));

    // All strings are options unless they are prepended by '-i', in which case they are the template
    int ind = 0;
    for(int i=1; i<argc; i++)
        if(strcmp(argv[i], "-i")){
            strcpy(options[ind], argv[i]);
            ind++;
        }
        else{
            template = argv[i+1];
            i++;
            free(options[argc-2]);
            free(options[argc-3]);
        }
    // Randomly select the answer, using the template if available
    srand(time(NULL));
    if(template){
        printf(template, options[rand()%ind]);
        printf("\n");
    }
    else
        printf("%s\n", options[rand()%ind]);
    
    // Free all heap
    for(int i = 0; i < ind; i++)\
        free(options[i]);
    free(options);
}
