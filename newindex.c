#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


void displayFile(FILE *file, char *source);
// double convertToFloat(char *num);
int findFile(FILE *file);




#define true 1
#define false 0
#define MAXLEN 20
#define STRMAXLEN 1000

int main(int argc, char *argv)
{
    FILE *file = fopen("IN.dat", "r");
    float srznach = 0.0;
    int count = 0;

    // проверка на нуль
    if(findFile(file)){

        return 1;

    } else{

        fclose(file);
        displayFile(file, "IN.dat");

    }

    
    // открываем файл
    file = fopen("IN.dat", "r");
    
    float values[MAXLEN];
    int i = 0;
    float tempVal = 0;

    while (1) {
        
        if (fscanf(file, "%f", &values[i]) == 1){
            
            count++;
            tempVal += values[i];
            i++;
        
        }

        if (feof(file)) break;
    }



    // printf("values[0] = %f\n", values[0]);
    values[0] = (tempVal) / ((float)(count));


    fclose(file);

    file = fopen("IN.dat", "w");

    if(count == 0){
        fprintf(file,"0\n");
    }
    else{
        for ( i = 0; i < count; i++)
        {
            fprintf(file, "%f ", values[i]);
        }
    }
    fclose(file);


    displayFile(file, "IN.dat");


    file = fopen("IN.txt", "r");

    if (findFile(file)){
        return 1;
    } else {
        fclose(file);
        displayFile(file, "IN.txt");
    }

    file = fopen("IN.txt", "r");

    count = 0;
    i = 0;
    char arrOfStr[STRMAXLEN];

    char c;
    int status = false;
    int temp;
    while ((c = getc(file)) != EOF)
    {
        if(isdigit(c) && status == false){
            status = true;
            temp = (int)(c - 48);
        }  else if (isdigit(c) && status == true){
            temp = (temp * 10) + (c - 48);
        } else if(!(isdigit(c)) && status == true){
            for (int j = 0; j < temp; j++)
            {
                arrOfStr[i++] = ' ';
            }
            
            arrOfStr[i++] = c;
            temp = 0;
            status = false;
        } else{
            arrOfStr[i++] = c;
        }
    }
    arrOfStr[i++] = '\n';
    







    fclose(file);



    file = fopen("IN.txt", "w");
    
    fprintf(file, "%s", arrOfStr);

    fclose(file);

    displayFile(file, "IN.txt");
    
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



int findFile(FILE *file){
    // file = fopen(source, "r");

    if (file == NULL){
        printf("We don`t find file\n");

        return 1;
    } else{
        return 0;
    }


}

