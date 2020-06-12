#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
static char buffer[2048];

char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy
}
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif
int main(int argc, char** argv) {

  /* Print Version and Exit Information */
  puts("Lispy Version 0.0.0.0.1");
  puts("Press Ctrl+c to Exit\n");

  while (1) {

    /* Output our prompt */
    char* input = readline("lispy> ");

#if ! defined (_WIN32)
    add_history(input);
#endif

    printf("No you're a %s\n", input);

    // Memory management
    free(input);
  }

  return 0;
}
