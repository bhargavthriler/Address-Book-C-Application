/*
function to create a new contact in the file given

called from main.c

input  - void
return - int 
*/

#include <addressBook.h>

int add_contact(char * fpc)
{
	contacts cont;

	//open file in append mode
	FILE *fp;
	if((fp = fopen(fpc, "a")) == NULL)
	{
		FILE_ERROR(fpc);	//if can't open file
		exit(2);
	}


	int  validate, checkPh = 0, checkEmail = 0;

	//take name
	printf("Enter name : ");
	scanf("\n%[^\n]s", cont.name);

	//take phone no
	printf("Enter phone no : ");
	scanf("%s", cont.phNo);
	//validate phone no
	for(validate = 0; validate < strlen(cont.phNo); validate++)
	{
		if((strlen(cont.phNo) < 10) || (cont.phNo[validate] < '0') || (cont.phNo[validate] > '9'))
		{
			checkPh = 1;
		}
	}

	//take email if
	printf("Enter email id : ");
	scanf("%s", cont.emailId);
	//validate email id to check if it contains atleast one '@' and '.' character
	for(validate = 0; validate < strlen(cont.emailId); validate++)
	{
		if((cont.emailId[validate] == '@') || (cont.emailId[validate] == '.'))
		{
			checkEmail++;
		}
	}
	
	//if either phone no or email id is invalid
	if((checkPh == 1) || (checkEmail < 2))
	{
			printf("invalid phone no or email id\n");
			return -1;
	}

	int added = fwrite(&cont, sizeof(cont), 1, fp);
		
	fclose(fp);	
	if(added)
	{
		printf("Contact details successfully added\n");
	}

	return 1;
}
