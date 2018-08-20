/*




*/

#include <addressBook.h>

int del_contact(char * fpc)
{
	contacts cont;
	//open file in read mode
	FILE *fp, *ftemp;
	if((fp = fopen(fpc, "r")) == NULL)
    {
    	FILE_ERROR(fpc);    //if can't open file
        exit(5);
    }
    else
	{
		ftemp = fopen("temp.txt", "w");
		if(ftemp == NULL)
		{
			FILE_ERROR(fpc);    //if can't open file
			exit(6);
		}
	}

    char nameD[50];
    char phNoD[11];
    char emailIdD[50];

	printf("Choose your option-\n1. delete by searching Name\n2. delete by searching Phone No\n3. delete by searching Email Id\n4. previous menu\nenter your option: ");
    int option;
    scanf("%d", &option);

	int count = 0, keepCount = 0;
	char res;
	switch(option)
	{
		case 1:
				printf("enter the Name for which you want to delete enitre record: ");
				scanf("\n%[^\n]s", nameD);

				while(fread(&cont, sizeof(cont), 1, fp) == 1)
				{
					if(strcmp(nameD, cont.name))
					{
						fwrite(&cont, sizeof(cont), 1, ftemp);
						count = 0;
					}
					else
					{
						count++;
						keepCount = count;
					}
				}
				break;
		case 2:
				printf("enter the Phone No for which you want to delete enitre record: ");
				scanf("%s", phNoD);

				while(fread(&cont, sizeof(cont), 1, fp) == 1)
				{
					if(strcmp(phNoD, cont.phNo))
					{
						fwrite(&cont, sizeof(cont), 1, ftemp);
						count = 0;
					}
					else
					{
						count++;
						keepCount = count;
					}
				}
				break;
		case 3:
				printf("enter the Email Id for which you want to delete enitre record: ");
				scanf("%s", emailIdD);

				while(fread(&cont, sizeof(cont), 1, fp) == 1)
				{
					if(strcmp(emailIdD, cont.emailId))
					{
						fwrite(&cont, sizeof(cont), 1, ftemp);
						count = 0;
					}
					
					else
					{
						count++;
						keepCount = count;
					}
				}
				break;
		case 4:
				return 3;
		default:
				INVALID_OPTION;	
				return -1;


	}

	
	fclose(fp);
	fclose(ftemp);

	remove(fpc);
	rename("temp.txt", fpc);

	if(!keepCount)
	{
		printf("no specified contact details found\n");
		return -2;
	}
	else
	{
		printf("contact details deleted successfully\n");
	}
	
	return 1;
	
}
