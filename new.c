#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void displayFile(FILE *file, char *source);
// double convertToFloat(char *num);

#define MAXLEN 20

int main(int argc, char *argv)
{
    FILE *file = fopen("IN.dat", "r");
    float srznach = 0.0;
    int count = 0;

    if(file == NULL){
        fclose(file);
        printf("Sorry, we don`t find your input file\n");
        return 1;
    } else{
        fclose(file);
        displayFile(file, "IN.dat");
    }

    file = fopen("IN.dat", "r");
    
    float values[MAXLEN];
    int i = 0;

    while (1) {
        

        if (fscanf(file, "%f", &values[i]) == 1){
            
            count++;
            values[0] += values[i];
            i++;
        
        }

        if (feof(file)) break;
    }

    values[0] /= (float)(count);

    values[0] = floor(values[0]);

    
    fclose(file);

    file = fopen("IN.dat", "w");

    for ( i = 0; i < count; i++)
    {
        fprintf(file, "%f ", values[i]);
    }
    
    fclose(file);

    displayFile(file, "IN.dat");


    return 0;
}


void displayFile(FILE *file, char *source){
    file = fopen(source, "r");

    char c;

    printf("It is a \"%s\"\n", source);

    while((c = getc(file)) != EOF){
        printf("%c", c);
    }

    printf("\nEnd of \"%s\"\n", source);

    fclose(file);
}