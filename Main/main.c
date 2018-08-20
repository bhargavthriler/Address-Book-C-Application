/*
TITLE      : address book
DESCRIPTION: 
AUTHOR     :
DATE       :
*/

/*
main function
Library files, macros and function prototypes are present in ../Include/addressBook.h file
function definations present in there respective files
*/

#include <addressBook.h>

int main(int argc, char *argv[])
{
	if(argc == 2)		//only if file is present
	{
		printf("ADDRESS BOOK\n");
		char res;
		//for ease of use
		do
		{
			char *fpc = argv[1];
			//user options
			printf("select options:\n1. Add a contact\n2. Search a contact\n3. Edit a contact\n4. Delete a contact\n5. List all contacts\n6. Exit application\n"); 
		
			//user response
			printf("enter your option: ");
			int option;
			scanf("%d", &option);
		
			int result;
		
			switch(option)
			{
				case 1:
						add_contact(fpc);
						break;
				case 2:
						search_contact(fpc);
						break;
				case 3:
						edit_contact(fpc);
						break;
				case 4:
						del_contact(fpc);
						break;
				case 5:
						list_contacts(fpc);
						break;
				case 6:
						exit(7);
						break;
				default:
						INVALID_OPTION;
						break;
			}

			printf("do you want to continue? y/n: ");
			scanf("\n%c", &res);
		} while(res != 'n');

		return 0;
	}
	else		//argument not passed
	{
		INVALID_ARGUMENTS(argv[0]);
		exit(1);
	}
}
