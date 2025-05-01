#include <stdio.h>
#include <string.h>

void Opciones();

int main()
{
    int countpeleadores = 0, countpeleas = 0, peleadores[6] = {0};
    char nombres[6][30] = {0};
    int opc = 0, countNom = 0, len = 0;
    int val;

    do
    {
        Opciones();

        val = scanf("%d", &opc);
        if (val != 1 || opc < 1 || opc > 4)
        {
            printf("Entrada invalida. Solo se permiten numeros del 1 al 4.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opc)
        {
        case 1:
            if (countNom <= 5)
            {
                for (int i = 0; i < 2; i++)
                {
                    printf("Ingrese el nombre del peleador %i:", countNom + 1);
                    fflush(stdin);
                    fgets(nombres[countNom], 30, stdin);
                    len = strlen(nombres[countNom]);
                    if (len > 0 && nombres[countNom][len - 1] == '\n')
                    {
                        nombres[countNom][len - 1] = '\0';
                    }

                    countNom++;
                }
                countpeleas++;
            }
            else
            {
                printf("Ya ingreso a todos los peleadores.\n");
            }
            break;

        case 2:
            if (countpeleadores + 1 < countNom)
            {
                printf("-- Ingrese resultados de la pelea #%i --\n", countpeleas);
                printf("%s vs %s\n", nombres[countpeleadores], nombres[countpeleadores + 1]);

                int ganador = 0, tipoVictoria = 0;

                do
                {
                    printf("Quien gano? (1 o 2): ");
                    val = scanf("%d", &ganador);
                    if (val != 1 || (ganador != 1 && ganador != 2))
                    {
                        printf("Entrada invalida. Debe ser 1 o 2.\n");
                        while (getchar() != '\n');
                        val = 0;
                    }
                } while (val != 1 || (ganador != 1 && ganador != 2));

                do
                {
                    printf("Fue por knockout (1) o por victoria normal (2)?: ");
                    val = scanf("%d", &tipoVictoria);
                    if (val != 1 || (tipoVictoria != 1 && tipoVictoria != 2))
                    {
                        printf("Entrada invalida. Debe ser 1 o 2.\n");
                        while (getchar() != '\n');
                        val = 0;
                    }
                } while (val != 1 || (tipoVictoria != 1 && tipoVictoria != 2));

                if (ganador == 1)
                {
                    peleadores[countpeleadores] += (tipoVictoria == 1) ? 3 : 1;
                }
                else
                {
                    peleadores[countpeleadores + 1] += (tipoVictoria == 1) ? 3 : 1;
                }

                countpeleadores += 2;
            }
            else
            {
                printf("No hay suficientes peleadores registrados.\n");
            }
            break;

        case 3:
            for (int i = 0; i < countNom - 1; i++)
            {
                for (int j = 0; j < countNom - i - 1; j++)
                {
                    if (peleadores[j] < peleadores[j + 1])
                    {
                        int temp = peleadores[j];
                        peleadores[j] = peleadores[j + 1];
                        peleadores[j + 1] = temp;
                        char tempnom[30];
                        strcpy(tempnom, nombres[j]);
                        strcpy(nombres[j], nombres[j + 1]);
                        strcpy(nombres[j + 1], tempnom);
                    }
                }
            }

            if (countNom >= 2)
            {
                printf("Combate final: %s vs %s con puntos %i y %i\n",
                       nombres[0], nombres[1], peleadores[0], peleadores[1]);
            }
            else
            {
                printf("No hay suficientes peleadores para combate final.\n");
            }
            break;

        default:
            break;
        }
    } while (opc != 4);

    return 0;
}

void Opciones()
{
    printf("\n--- Menu --- \n");
    printf("1. Ingresar Peleadores\n");
    printf("2. Resultados de los combates\n");
    printf("3. Combate final\n");
    printf("4. Salir\n");
    printf(">> ");
}
