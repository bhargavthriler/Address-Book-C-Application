/*
function to show all the contact details present in the file

called from main.c

input  - void
return - void
*/

#include <addressBook.h>

int list_contacts(char * fpc)
{
	contacts cont;

	//open file in read mode
	FILE *fp;
	if((fp = fopen(fpc, "r")) == NULL)
    {
    	FILE_ERROR(fpc);    //if can't open file
        exit(3);
     }


	int contactNos = 1;			//contact count

	printf("Contact details available-\n----------\n");
	while(fread(&cont, sizeof(cont), 1, fp) == 1)
	{
		printf("CONTACT %d\nName    : %s\nPhone No: %s\nEmail Id: %s\n----------\n", contactNos, cont.name, cont.phNo, cont.emailId);
		contactNos++;
	}
	if(1 == contactNos)
	{
		printf("no contacts in file\n");
		return -1;
	}
	
	//close file
	fclose(fp);

	return 1;
}
