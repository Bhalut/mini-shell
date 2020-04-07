#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char words[] = "hello olleh holberton world"; /*string a separar*/
	char del[] = " "; /* caracter delimitador de string */
	char *token; /* puntero token que guarda cada palabra del string */
	int n; /* variable para recorrer el string original - tambien la cantidad de letras del mismo */
	int i; /* Cantidad de separadores para identificar cantidad de palabras */
	int j; /* variable para recorrer el doble puntero */
	int m; /* variable para contar la cnatidad de letras de cada palabra */
	char **pingui; /*puntero doble que apunta a los punteros que apuntan a cada palabra */
	
	printf("El string a separar es %s\n", words);

	n = 0;
	i = 0;

	while (words[n] != '\0')
	{
		if (words[n] == ' ')
		{
			i++;
		}
		n++;
	}
	i = i + 1;

	pingui = malloc(i * sizeof(char *));
	if (pingui == '\0')
	{
		printf("No se pudo alocar el espacio de memoria\n");
		exit(2);
	}
	printf("la cantidad de palabras es: %d\n", i);
	printf("\n");

	token = strtok(words, del);

	j = 0;
	while (j < i)
	{
		printf("La palabra actual es %s\n", token);
		m = 0;
		while (token[m] != '\0')
		{
			m++;
		}
		printf("La cantidad de letras de la palabra actual es: %d\n", m);
		pingui[j] = malloc((m * sizeof(char)) + 1);
		/* preguntar si es nulo y liberar memoria en caso de fallo */
		m = 0;
		while (token[m] != '\0')
		{
			pingui[j][m] = token[m];
			m++;
		}
		pingui[j][m] = '\0';
		printf("Ya el array tiene la palabra: %s\n", pingui[j]);
		printf("\n");
		token = strtok(NULL, del);
		j++;
	}

	printf("El puntero doble quedo con la siguiente información:\n");
	m = 0;
	while (m < i)
	{
		printf("La palabra en el indice %d es: %s\n", m, pingui[m]);
		m++;
	}
	return (0);
}

