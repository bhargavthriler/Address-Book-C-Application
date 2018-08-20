/*
header file
contains all library files, macros and function prototypes 


*/

//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main structure definations
typedef struct Contact
{
	char name[50];
	char  phNo[11];
	char emailId[50];
}contacts;

//functions prototypes 
int add_contact(char * fpc);
int search_contact(char * fpc);
int edit_contact(char * fpc);
int del_contact(char * fpc);
int list_contacts(char * fpc);

//required macros
#define INVALID_OPTION printf("invalid option\nchoose a correct one\n")
// define INVALID_PH_EM 1

#define INVALID_ARGUMENTS(arg) printf("%s: missing file operand\nTry- %s <file name>\n", arg, arg)

#define FILE_ERROR(file_name) printf("couldn't open file: %s\n", file_name)
