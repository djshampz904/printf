#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024

int _printf(char *format, ...);

void loop(void);
#endif
