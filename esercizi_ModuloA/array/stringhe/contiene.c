#include <stdio.h>
#include <string.h>

#define DIM 100

int main()
{
    char str[DIM], str2[DIM];
    int c = 0, j = 0;

    printf("Inserisci la prima parola:");
    scanf("%s", str);
    printf("Inserisci la seconda parola:");
    scanf("%s", str2);

    for (int i = 0; i < strlen(str); i++)
    {

        for (int j = 0; j < strlen(str2); j++)
        {

            if (str[i] == str2[j])
            {
                c++;
                //errato a metà
            }
        }

        
    }

    if (c == strlen(str2))
        {
            printf("La parola è contenuta\n");
        }
        else
        {
            printf("La parola NON è contenuta\n");
        }
}


//da completare
//tobia e ia va bene, ma tobia e iai mi dice che compare