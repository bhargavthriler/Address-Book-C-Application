/*




*/

#include <addressBook.h>

int edit_contact(char * fpc)
{
	contacts cont, edit;
	//open file in read mode
	FILE *fp;
	if((fp = fopen(fpc, "r+")) == NULL)
    {
    	FILE_ERROR(fpc);    //if can't open file
        exit(5);
    }

    char nameE[50];
    char phNoE[11];
    char emailIdE[50];

	printf("Choose your option-\n1. edit by searching Name\n2. edit by searching Phone No\n3. edit by searching Email Id\n4. previous menu\nenter your option: ");
    int option;
    scanf("%d", &option);

	int count = 0;
	char res;
	switch(option)
	{
		case 1:
				printf("enter the Name which you want to edit: ");
				scanf("\n%[^\n]s", nameE);
				while(fread(&cont, sizeof(cont), 1, fp) == 1)
				{
					if(!strcmp(nameE, cont.name))
					{
						printf("contact FOUND\nName    : %s\nPhone No: %s\nEmail Id: %s\n", cont.name, cont.phNo, cont.emailId);
						printf("enter new Name: ");
						scanf("\n%[^\n]s", edit.name);
						
						printf("Do you want to edit the Phone No also?y/n: ");
						scanf("\n%c", &res);
						if(res == 'y')
						{
							printf("enter new Phone No: ");
							scanf("%s", edit.phNo);
						}
						else if(res == 'n')
						{
							printf("%s\n", cont.phNo);
							strcpy(edit.phNo, cont.phNo);
						}
						else
						{
							INVALID_OPTION;
						}

						printf("Do you want to edit the Email Id also?y/n: ");
						scanf("\n%c", &res);
						if(res == 'y')
						{
							printf("enter new Email Id: ");
							scanf("%s", edit.emailId);
						}
						else if(res == 'n')
						{
							printf("%s\n", cont.emailId);
							strcpy(edit.emailId,cont.emailId); 
						}
						else
						{
							INVALID_OPTION;
						}

						fseek(fp, -sizeof(cont), SEEK_CUR);
						fwrite(&edit, sizeof(cont), 1, fp);

						fclose(fp);
						count++;
						break;

					}
		
				}
				break;
		case 2:
				printf("enter the Phone No which you want to edit: ");
				scanf("%s", phNoE);
				while(fread(&cont, sizeof(cont), 1, fp) == 1)
				{
					if(!strcmp(phNoE, cont.phNo))
					{
						printf("contact FOUND\nName    : %s\nPhone No: %s\nEmail Id: %s\n", cont.name, cont.phNo, cont.emailId);
						printf("enter new Phone No: ");
						scanf("%s", edit.phNo);
						
						printf("Do you want to edit the Name also?y/n: ");
						scanf("\n%c", &res);
						if(res == 'y')
						{
							printf("enter new Name: ");
							scanf("\n%[^\n]s", edit.name);
						}
						else if(res == 'n')
						{
							strcpy(edit.name,cont.name); 
						}
						else
						{
							INVALID_OPTION;
						}

						printf("Do you want to edit the Email Id also?y/n: ");
						scanf("\n%c", &res);
						if(res == 'y')
						{
							printf("enter new Email Id: ");
							scanf("%s", edit.emailId);
						}
						else if(res == 'n')
						{
							strcpy(edit.emailId,cont.emailId); 
						}
						else
						{
							INVALID_OPTION;
						}

						fseek(fp, -sizeof(cont), SEEK_CUR);
						fwrite(&edit, sizeof(cont), 1, fp);

						fclose(fp);
						count++;
						break;

					}
		
				}
				break;
		case 3:
				printf("enter the Email Id which you want to edit: ");
				scanf("%s", emailIdE);
				while(fread(&cont, sizeof(cont), 1, fp) == 1)
				{
					if(!strcmp(emailIdE, cont.emailId))
					{
						printf("contact FOUND\nName    : %s\nPhone No: %s\nEmail Id: %s\n", cont.name, cont.phNo, cont.emailId);
						printf("enter new Email Id: ");
						scanf("%s", edit.emailId);
						
						printf("Do you want to edit Name also?y/n: ");
						scanf("\n%c", &res);
						if(res == 'y')
						{
							printf("enter new Name: ");
							scanf("\n%[^\n]s", edit.name);
						}
						else if(res == 'n')
						{
							strcpy(edit.name,cont.name); 
						}
						else
						{
							INVALID_OPTION;
						}

						printf("Do you want to edit Phone No also?y/n: ");
						scanf("\n%c", &res);
						if(res == 'y')
						{
							printf("enter new Phone No: ");
							scanf("%s", edit.phNo);
						}
						else if(res == 'n')
						{
							strcpy(edit.phNo,cont.phNo); 
						}
						else
						{
							INVALID_OPTION;	
						}

						fseek(fp, -sizeof(cont), SEEK_CUR);
						fwrite(&edit, sizeof(cont), 1, fp);

						fclose(fp);
						count++;
						break;
					
					}
		
				}
				break;
		case 4:
				return 3;
		default:
				INVALID_OPTION;	
				return -1;

	}
	if(count)
	{
		printf("Contact details editted successfully\n");
	}
	else
	{
		printf("Data you are trying to edit is not available\n");
		return -2;
	}
	return 1;
}
