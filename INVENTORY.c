#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*For system independent Screen clears*/
#ifdef _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

#define gotoxy(x, y) printf("\033[%d;%dH", (y), (x))

#define TRUE 1
#define HEADER_COL 3
#define FALSE 0

struct ITEM
{
	char name[MAX_NAME_LENGTH];
	int quantity;
};

struct ITEM inventory[MAX_ITEMS];

struct ITEM tempinv[MAX_ITEMS]; /*FOR STORING THE EDITED INVENTORY TEMPORARILY*/

int ITEM_COUNT = 0;

void startMenu();
int choice_Menu();
int endMenu();
void addItem();
void viewInventory();
void updateItem();
void deleteItem();
void displayInventory();

enum op
{
	ADD = 1,
	VIEW,
	UPDATE,
	DELETE,
	EXIT
};

/*---Main Function---*/
int main()
{
	void (*menuFunctions[4])(void) = {addItem, viewInventory, updateItem, deleteItem}; /* A FUNCTION POINTER POINTING TO THE VARIOUS FUNCTIONS USED*/

	char continueChoice;
	int choice;

	do
	{
		startMenu();
		choice = choice_Menu();
		if (choice == EXIT)
		{
			printf("Exiting...\n");
			sleep(1);
			exit(0);
		}
		else if (choice >= ADD && choice <= DELETE)
		{
			menuFunctions[choice - 1]();
		}
	} while (1);
}

/*---Function Definitions---*/
void startMenu()
{
	CLEAR;
	gotoxy(15, 5);
	printf("**************************************");
	gotoxy(15, 6);
	printf("*            INVENTORY SYSTEM        *");
	gotoxy(15, 7);
	printf("*              BY:ADRISH DATTA       *");
	gotoxy(15, 8);
	printf("**************************************");
	gotoxy(15, 10);
	printf("1. Add Item");
	gotoxy(15, 11);
	printf("2. View Inventory");
	gotoxy(15, 12);
	printf("3. Update Item");
	gotoxy(15, 13);
	printf("4. Delete Item");
	gotoxy(15, 14);
	printf("5. Exit");
	gotoxy(15, 16);
	printf("Enter your choice: ");
}

int choice_Menu()
{
	int choice, tryagain;
	char input[15];
	tryagain = TRUE;
	/*Taking input from User*/
	while (tryagain)
	{
		fgets(input, sizeof(input), stdin);
		if ((sscanf(input, "%d", &choice) != 1) || (choice < ADD || choice > EXIT))
		{
			printf("\t      Invalid input. Please enter a number.\n");
			printf("\t      Enter your choice: ");
			tryagain = TRUE;
		}
		else
		{
			tryagain = FALSE;
		}
	}
	return choice;
}

void addItem()
{
	CLEAR;
	char name[MAX_NAME_LENGTH], squantity[20];
	int quantity = 0, tryagain = TRUE;
	gotoxy(15, HEADER_COL);
	printf("************* ADD ITEM *************\n");

	if (ITEM_COUNT >= MAX_ITEMS)
	{
		printf("Inventory is full. Cannot add more items.\n");
		return;
	}
	else
	{
		gotoxy(15, 5);
		printf("Enter item name: ");
		fgets(name, sizeof(name), stdin);
		name[strcspn(name, "\n")] = '\0';

		gotoxy(15, 7);
		printf("Enter item quantity: ");
		while (tryagain)
		{
			fgets(squantity, sizeof(squantity), stdin);
			if ((sscanf(squantity, "%d", &quantity) != 1) || (quantity < 0))
			{
				printf("\t      Invalid input. Please enter a valid quantity.\n");
				printf("\t      Enter item quantity: ");
			}
			else
			{
				tryagain = FALSE;
			}
		}
		// Add item to inventory
		strcpy(inventory[ITEM_COUNT].name, name);
		inventory[ITEM_COUNT].quantity = quantity;
		ITEM_COUNT++;
		printf("\n\tItem added successfully!\n");
	}
	printf("\tPress Enter to continue: ");
	while (getchar() != '\n')
		;
}
void viewInventory()
{
	CLEAR;
	gotoxy(15, HEADER_COL);
	printf("************* VIEW INVENTORY *************\n");
	if (ITEM_COUNT == 0)
	{
		gotoxy(15, 5);
		printf("Inventory is empty.\n");

		printf("\tPress Enter to continue: ");
		while (getchar() != '\n')
			;
		return;
	}
	displayInventory();
}

void updateItem()
{
	CLEAR;
	gotoxy(15, HEADER_COL);
	printf("************* UPDATE ITEM *************\n");
	gotoxy(15, 5);
	printf("This feature is currently under development. Please check back later.\n\n");
	printf("\tPress Enter to continue: ");
	while (getchar() != '\n')
		;
}

void deleteItem()
{
	CLEAR;
	char item_name[MAX_NAME_LENGTH];
	int found = FALSE;
	int t = 0; // index for tempinv

	if (ITEM_COUNT == 0)
	{
		gotoxy(15, 5);
		printf("Inventory is empty. No items to delete.\n");
		return;
	}
	else
	{
		gotoxy(15, HEADER_COL);
		printf("************* DELETE ITEM *************\n");
		if (ITEM_COUNT == 0)
		{
			printf("\tPress Enter to continue: ");
			while (getchar() != '\n')
				;
			return;
		}
		else
		{
			displayInventory();

			gotoxy(15, (5 + ITEM_COUNT));
			printf("Enter the name of the item to delete: ");
			fgets(item_name, sizeof(item_name), stdin);
			item_name[strcspn(item_name, "\n")] = '\0';

			for (int i = 0; i < ITEM_COUNT; i++)
			{
				if (strcmp(inventory[i].name, item_name) == 0)
				{
					found = TRUE; // skip the matched item
				}
				else
				{
					tempinv[t] = inventory[i];
					t++;
				}
			}
			ITEM_COUNT = t; // new count after deletion
			if (found)
			{
				gotoxy(15,(7+ITEM_COUNT));
				printf("processing.....");
				usleep(120000);
				gotoxy(15,(7+ITEM_COUNT));	
				printf("\tItem deleted successfully!\n");
			}
			else
			{
					gotoxy(15,(7+ITEM_COUNT));
				printf("processing.....");
				usleep(120000);
					gotoxy(15,(8+ITEM_COUNT));
				printf("Item not found in inventory.");
			}
			/*Copies back to original struct from the temporary struct*/
			for (int i = 0; i < ITEM_COUNT; i++)
			{
				inventory[i] = tempinv[i];
			}
		}
		gotoxy(15,(10+ITEM_COUNT));
		printf("Press Enter to continue: ");
		while (getchar() != '\n')
			;
	}
}

void displayInventory()
{
	for (int i = 0; i < ITEM_COUNT; i++)
	{
		gotoxy(15, 5 + i);
		printf("%d. %s - Quantity: %d\n", i + 1, inventory[i].name, inventory[i].quantity);
	}
	return;
}