#ifndef __MAIN_H__
#define __MAIN_H__

#define DEHORS 0
#define DEDANS 1
#define BUF 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <signal.h>
#include <inttypes.h>
#include <errno.h>
extern char **environ;

int number_of_words(char *str, char *separator);
char **fillarguments(char *buf, char *separator);
int prompt(char **buff);
int processus(char **argv, char **av, char *buf, int count);
int _strlen(char *str);
char *_strtok(char *string, const char *cutter);
char *findinthepath(char **firstarg);
void free_p(const unsigned int n, ...);
void free_a(char **arr);
int _strcmp(char *s1, char *s2);
void printenv(void);
int checkBuiltins(char **av, char *buff, int count);
char *_getenv(const char *name);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *updatethepath(char *path, char *pwd);
char *_strstr(char *haystack, char *needle);
char *checkifworkingdirectory(char **pwd, char **path);
void handler(int sig __attribute__((unused)));
int _cd(char **av, int count);
void printerror(char **argv, int count, char **av);
int shell_loop(char **argv, int count);
int write_integer_error(int number);

/* printf */
#define BUFSIZE 1024
/**
 * struct type - structure type
 * @c: character to check
 * @ptr_f: pointer of function
 */
typedef struct type
{
	char c;
	int (*ptr_f)(va_list);
} type;
int _printf(const char *format, ...);
int _prints(va_list);
int _printc(va_list);
int _printd(va_list);
int write_integer(int);
int _printb(va_list);
int _printu(va_list);
int write_uninteger(unsigned int);
int _printb(va_list);
int _printo(va_list);
int write_octal(unsigned int);
int (*get_specifier_func(char))(va_list);
int _printx(va_list);
int write_x(unsigned long int);
int _printX(va_list);
int write_X(unsigned int);
int _printp(va_list);
int _printS(va_list);
int _printR(va_list);
int _printr(va_list);
int write_reverse(char *);
int checkSpecifier(const char *format, int i, va_list arglist);
int _echo(char **av);
int _help(char **av);
#endif
