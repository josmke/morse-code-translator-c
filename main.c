//- José Maike Ferreira Ferro, 10732694
//- Enzo Ferreira de Andrade, 10743307
//- Gabriel Valieri, 10736421

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Verifica se a entrada foi fornecida
    if (argc < 2)
    {
        printf("Uso: %s <entrada>\n", argv[0]);
        return 1;
    }

    // Dicionário de tradução
    const char *alfabeto[] = {"A", "B", "C", "D", "E",
                              "F", "G", "H", "I", "J",
                              "K", "L", "M", "N", "O",
                              "P", "Q", "R", "S", "T",
                              "U", "V", "W", "X", "Y", "Z"};
    const char *morse[] = {".-", "-...", "-.-.", "-..", ".",
                           "..-.", "--.", "....", "..", ".---",
                           "-.-", ".-..", "--", "-.", "---",
                           ".--.", "--.-", ".-.", "...", "-",
                           "..-", "...-", ".--", "-..-", "-.--", "--.."};

    // Variaveis para a lógica de tradução
    int tamanho = strlen(argv[1]);
    char frase_traduzida[100];
    frase_traduzida[0] = '\0'; // Inicializa a string de saída
    
    char codigo_letra_atual[100]; // Buffer para o código morse de uma letra
    int contador_buffer = 0;

    // Loop principal para percorrer toda a entrada
    for (int i = 0; i <= tamanho; i++)
    {
        // Se encontramos o fim de uma letra (espaço, asterisco ou fim da string)
        if (i == tamanho || argv[1][i] == ' ' || argv[1][i] == '*')
        {
            // Se o buffer tem algo para traduzir
            if (contador_buffer > 0)
            {
                codigo_letra_atual[contador_buffer] = '\0'; // Finaliza a string do código morse atual

                // Lógica para sugestões (caractere '*')
                if (i < tamanho && argv[1][i] == '*')
                {
                    strcat(frase_traduzida, "[");
                    for (int j = 0; j < 26; j++)
                    {
                        if (strncmp(morse[j], codigo_letra_atual, contador_buffer) == 0)
                        {
                            strcat(frase_traduzida, alfabeto[j]);
                        }
                    }
                    strcat(frase_traduzida, "]");
                }
                // Lógica para tradução normal (espaço ou fim da string)
                else
                {
                    int encontrou = 0;
                    for (int j = 0; j < 26; j++)
                    {
                        if (strcmp(morse[j], codigo_letra_atual) == 0)
                        {
                            strcat(frase_traduzida, alfabeto[j]);
                            encontrou = 1;
                            break; // Otimização: para de procurar depois de encontrar
                        }
                    }
                   
                }
            }

            // Lógica para adicionar um espaço entre palavras (dois espaços seguidos)
            if (i < tamanho - 1 && argv[1][i] == ' ' && argv[1][i + 1] == ' ')
            {
                strcat(frase_traduzida, " ");
                i++; // Pula o segundo espaço
            }

            // Limpa o buffer para a próxima letra
            contador_buffer = 0;
        }
        // Se não for um separador, adiciona o caractere ao buffer
        else
        {
            codigo_letra_atual[contador_buffer] = argv[1][i];
            contador_buffer++;
        }
    }

    printf("%s\n", frase_traduzida);

    return 0;
}
