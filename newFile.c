#include <locale.h>
#include <stdio.h>

void newFile(FILE *file, char source[]);
void newTextFile(FILE *file, char source[]);

int main(void){
    setlocale(LC_ALL, "ru");
    FILE *file1,
        *file2;
    printf("Привет, это моя софтяра.\nА вот мой github: \"https://github.com/lyubchenko-ivan\" \n Короче, лафа вот в чем: данный интерфейс послужит тебе\nдля заполнения двух файлов.\nМожем начинать...\n");
    newFile(file1, "IN.dat");
    newTextFile(file2, "IN.txt");
    return 0;

}

void newFile(FILE *file, char source[]){
    file = fopen(source, "w");
    fclose(file);
    int n;
    file = fopen(source, "a");
    
    do
    {
        printf("Введи количество значений  для \"%s\": ", source);
        scanf("%d", &n);
    } while (n <= 1);

    puts("CPU благодарит тебя!");

    printf("Ну а теперь начинаем вводить вещественные числа \"%s\":\n", source);

    for (int i = 0; i < n; i++)
    {
        float temp;
        scanf("%f", &temp);
        fprintf(file, "%f ", temp);
    }

    fclose(file);

}


void newTextFile(FILE *file, char source[]){
    file = fopen(source, "w");
    
    printf("А теперь заполним файл \"%s\": просто вводи от фонаря текст (on the English, please): ", source);
    char str[1000];

    scanf("%s", str);

    fprintf(file, "%s", str);
    



    fclose(file);
}