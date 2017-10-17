#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Copied from 
// https://stackoverflow.com/questions/35103745/read-a-string-as-an-input-using-scanf
void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct {
	char username[15];
	char password[15];
} User;

typedef struct {
	int id; // must be unique
	char title[50];
	char author[50]; // if more than two, separate using ,(COMMA)
	char ISBN[50];
	char category[50];
	char publication[50];
	char description[255];
	int taken;
} Book;

int main(){
	char option, admin_option, username[15], password[15], edit_option;
	int first_time, c, i, j, id, found;
	FILE *f;
	User user;
	Book book;

	f = fopen("librarian.check", "r");
	if (f == NULL) {
		fclose(f);
		f = fopen("librarian.check", "w");
		fputc(1, f);
		fclose(f);
	} else {
		fclose(f);
	}

	f = fopen("id.check", "r");
	if (f == NULL) {
		fclose(f);
		f = fopen("id.check", "w");
		fputc(0, f);
		fclose(f);
	} else {
		fclose(f);
	}
	
	printf("Log in as \n");
	printf("1:  Librarian\n");
	printf("2: Student\n");
	printf("3: Exit\n");
	printf("Enter your choice: ");
	scanf("%c", &option);
	switch(option) {
		case '1':
		f = fopen("librarian.check", "r");
		if (f == NULL) {
			printf("Couldn't read file\n");
			exit(0);
		} else {
			first_time = fgetc(f);
			if (first_time == 1) {
				fclose(f);
				flush();
				printf("Provide username and password to setup\n");
				printf("Username (14 characters max): ");
				fgets(user.username, 15, stdin);
				printf("Password (14 characters max): ");
				fgets(user.password, 15, stdin);

				// write this credential to file
				f = fopen("credential.bin", "wb");
				if (f == NULL) {
					printf("Someting went wrong!!\n");
					exit(0);
				}
				fwrite(&user, sizeof(User), 1, f);
				fclose(f);
				printf("Exit and login again to continue\n");
				f = fopen("librarian.check", "w");
				fputc(0, f);
				fclose(f);
			} else {
				fclose(f);
				flush();
				printf("Provide credential to login\n");
				printf("Username: ");
				fgets(username, 15, stdin);
				printf("Password: ");
				fgets(password, 15, stdin);

				// read the credential from file
				f = fopen("credential.bin", "rb");
				if (f == NULL) {
					printf("Someting went wrong!!\n");
					exit(0);
				}
				fread(&user, sizeof(User), 1, f);
				if (strcmp(username,user.username) != 0 || strcmp(password, user.password) != 0) {
					printf("Username or password invalid\n");
					exit(0);
				}
				printf("Login Successful!!\n");
				printf("1: Add Book\n");
				printf("2: Search Book\n");
				printf("3: Edit Book\n");
				printf("4: Delete Book\n");
				printf("4: Moderate Student Request\n");
				printf("Enter your choice: ");
				scanf("%c", &admin_option);
				switch(admin_option) {
					case '1':
					flush();
					printf("Provide the following information\n");
					printf("Title: ");
					fgets(book.title, 50, stdin);
					printf("Author: ");
					fgets(book.author, 50, stdin);
					printf("ISBN: ");
					fgets(book.ISBN, 50, stdin);
					printf("Category: ");
					fgets(book.category, 50, stdin);
					printf("Publication: ");
					fgets(book.publication, 50, stdin);
					printf("Description: ");
					fgets(book.description, 50, stdin);
					book.taken = 0;

					// increment ID
					f = fopen("id.check", "r");
					if (f == NULL) {
						printf("Someting went wrong\n");
						exit(1);
					}

					id = fgetc(f);
					fclose(f);
					book.id = id;

					// save the record
					f = fopen("book.record", "a");
					fwrite(&book, sizeof(Book), 1, f);
					fclose(f);

					id++;
					f = fopen("id.check", "w");
					fputc(id, f);
					fclose(f);

					printf("Book insertion Successful!!\n");
					break;
					case '2':
					printf("Enter the book id to search: ");
					scanf("%d", &id);

					// search in the database
					f = fopen("book.record", "rb");
					found = 0;
					i = 0;
					while(fread(&book, sizeof(Book), 1, f)) {
						if (book.id == id) {
							// matched
							found = 1;
							printf("Book Found!!\n");
							printf("Title: %s", book.title);
							printf("Author: %s", book.author);
							printf("ISBN: %s", book.ISBN);
							printf("Category: %s", book.category);
							printf("Publication: %s", book.publication);
							printf("Description: %s", book.description);
							break;
						}
						i++;
					}
					if (found == 0) {
						printf("Sorry!! The book is not in the database\n");
					}
					fclose(f);
					break;
					case '3':
					printf("Enter the book id to edit: ");
					scanf("%d", &id);
					f = fopen("book.record", "rb+");
					found = 0;
					while(fread(&book, sizeof(Book), 1, f)) {
						if (book.id == id) {
							// matched
							found = 1;
							break;
						}
					}
					if (found == 0) {
						printf("Sorry!! The book is not in the database\n");
					} else {
						printf("What field do you want to edit:\n");
						printf("1. Title\n");
						printf("2. Author\n");
						printf("3. ISBN\n");
						printf("4. Category\n");
						printf("5. Publication\n");
						printf("6. Description\n");
						printf("Enter your choice: ");
						scanf("\n%c", &edit_option);
						switch(edit_option) {
							case '1':
							flush();
							printf("Enter new title: ");
							fgets(book.title, 50, stdin);
							break;
							case '2':
							printf("Enter new author: ");
							fgets(book.author, 50, stdin);
							break;
							case '3':
							printf("Enter new ISBN: ");
							fgets(book.ISBN, 50, stdin);
							break;
							case '4':
							printf("Enter new Category: ");
							fgets(book.category, 50, stdin);
							break;
							case '5':
							printf("Enter new Publication: ");
							fgets(book.publication, 50, stdin);
							break;
							printf("Enter new Description: ");
							fgets(book.description, 255, stdin);
							break;
							default:
							printf("Enter 1 to 6\n");
							break;
						}
						fseek(f, i, SEEK_SET);
						fwrite(&book, sizeof(Book), 1, f);
						fclose(f);
						printf("Book record modified in the database!!\n");
					}
					break;
					case '4':
					printf("Enter the book id to Delete: ");
					scanf("%d", &id);
					f = fopen("book.record", "rb");
					found = 0;
					while(fread(&book, sizeof(Book), 1, f)) {
						if (book.id == id) {
							// matched
							found = 1;
							break;
						}
					}
					fclose(f);
					if (found == 0) {
						printf("Sorry!! The book is not in the database\n");
					} else {
						// create a temporary file
						FILE * temp;
						temp = fopen("book.temp", "a");
						if (temp == NULL) {
							printf("Something went wrong\n");
							exit(1);
						}

						f = fopen("book.record", "rb");

						// copy all the items except item to delete 
						// to temporary file
						while(fread(&book, sizeof(Book), 1, f)) {
							if (book.id != id)
								fwrite(&book, sizeof(Book), 1, temp);
						}
						fclose(f);
						fclose(temp);

						// delete original file
						remove("book.record");

						// rename the temporary file
						rename("book.temp", "book.record");
						printf("Book record deleted from the database!!\n");
					}
					break;
					default:
					printf("Enter only 1 - 4\n");
					break;
				}				
			}
		}	
		
		break;
		case '2':
		printf("Enter the book id to search: ");
		scanf("%d", &id);

		// search in the database
		f = fopen("book.record", "rb");
		found = 0;
		i = 0;
		while(fread(&book, sizeof(Book), 1, f)) {
			if (book.id == id) {
				// matched
				found = 1;
				printf("Book Found!!\n");
				printf("Title: %s", book.title);
				printf("Author: %s", book.author);
				printf("ISBN: %s", book.ISBN);
				printf("Category: %s", book.category);
				printf("Publication: %s", book.publication);
				printf("Description: %s", book.description);
				printf("Status: ");
				if (book.taken == 1) {
					printf("Not Available");
				} else {
					printf("Available\n");
				}
				break;
			}
			i++;
		}
		if (found == 0) {
			printf("Sorry!! The book is not in the database\n");
		}
		fclose(f);
		break;
		case '3':
		printf("Bye!!\n");
		exit(0);
		default:
		printf("Enter either 1 or 2 only\n");
		break;
	}
	return 0;
}