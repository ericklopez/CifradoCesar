#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void haceHijos(char *);

int main(void){
	char *cadena = NULL;

	printf("Ingresa la cadena a cifrar\n");
	scanf("%m[^\n]s", &cadena);
	haceHijos(cadena);
	free(cadena);

	return EXIT_SUCCESS;
}

void haceHijos(char * restrict cadena){
	char *cadenaDos = (char *)calloc(strlen(cadena)+1, sizeof(char));
	int32_t pid, pipefd[10][2], estado;

	for (int32_t i=0; i<10; i++)
		pipe(pipefd[i]);  //Inicializar pipe

	for (int32_t i=0; i<10; i++) {
		pid = fork();
	
		if (pid) {
			close(pipefd[i][0]); //Cierra Lectura
			write(pipefd[i][1], cadena, sizeof(char)*strlen(cadena));

			if (9 == i) {
				while (i > 0) {
					--i;
					wait(&estado);
				}
				free(cadenaDos);
				exit(EXIT_SUCCESS);
			}

		} else {
			close(pipefd[i][1]); //Cierra escritura
			read(pipefd[i][0], cadenaDos, sizeof(char)*strlen(cadena));

			for (int32_t j=0; j<strlen(cadenaDos); j++) {
				if ((cadenaDos[j] + i) > 127)
					cadenaDos[j] = 65;
				cadenaDos[j] = cadenaDos[j]+i;
			}
			sleep(2);
			printf("Desplazamiento[%d] %s\n", i, cadenaDos);
			free(cadenaDos);
			exit(EXIT_SUCCESS);
		}
	}

	return;
}


