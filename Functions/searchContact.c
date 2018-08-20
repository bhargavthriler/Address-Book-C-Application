/*




*/

#include <addressBook.h>

int search_contact(char * fpc)
{
	contacts cont;
	
	//open file in read mode
	FILE *fp;
	if((fp = fopen(fpc, "r")) == NULL)
    {
    	FILE_ERROR(fpc);    //if can't open file
        exit(4);
    }
	
	char nameS[50];
	char phNoS[11];
	char emailIdS[50];

	printf("Choose your option-\n1. search by Name\n2. search by Phone No\n3. search by Email Id\n4. previous menu\nenter your option: ");
	int option;
	scanf("%d", &option);

	int count = 0;
	switch(option)
	{
		case 1:
				printf("enter a Name to search: ");
				scanf("\n%[^\n]s", nameS);
				while(fread(&cont, sizeof(cont), 1, fp) == 1)
				{
					if(!strcmp(nameS, cont.name))
					{
						printf("contact FOUND\nName    : %s\nPhone No: %s\nEmail Id: %s\n", cont.name, cont.phNo, cont.emailId);
						count++;
					}
		
				}
				if(!count)
				{
					printf("contact NOT FOUND\n");
					return -2;
				}
				else if(count > 1)
				{
					printf("WARNING: contacts with either same Name, Phone No or Emaid Id found\n");
				}
				break;
		case 2:
				printf("enter a Phone No to search: ");
				scanf("%s", phNoS);
				while(fread(&cont, sizeof(cont), 1, fp) == 1)
				{
					if(!strcmp(phNoS, cont.phNo))
					{
						printf("contact FOUND\nName    : %s\nPhone No: %s\nEmail Id: %s\n", cont.name, cont.phNo, cont.emailId);
						count++;
					}
			
				}
				if(!count)
				{
					printf("contact NOT FOUND\n");
					return -2;
				}
				else if(count > 1)
				{
					printf("WARNING: contacts with either same Name, Phone No or Emaid Id found\n");
				}
				break;
		case 3:
				printf("enter a Email Id to search: ");
				scanf("%s", emailIdS);
				while(fread(&cont, sizeof(cont), 1, fp) == 1)
				{
					if(!strcmp(emailIdS, cont.emailId))
					{
						printf("contact FOUND\nName    : %s\nPhone No: %s\nEmail Id: %s\n", cont.name, cont.phNo, cont.emailId);
						count++;
					}
		
				}
				if(!count)
				{
					printf("contact NOT FOUND\n");
					return -2;
				}
				else if(count > 1)
				{
					printf("WARNING: contacts with either same Name, Phone No or Emaid Id found\n");
				}
				break;
		case 4:
				return 3;
		default:
				INVALID_OPTION;
				


	}





	//close file
	fclose(fp);

	return 1;

}
