#include <stdio.h>
#include <string.h>

int main() {
    char books[100][100];
    int choice, bookCount = 0;
    char bookName[100];
    int i, found;

    while (1) {
        printf("\nBook Database Management System\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Search Book by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (bookCount < 100) {
                    printf("Enter book name: ");
                    fgets(bookName, sizeof(bookName), stdin);
                    bookName[strcspn(bookName, "\n")] = '\0';  // Remove trailing newline

                    strcpy(books[bookCount], bookName);
                    bookCount++;
                    printf("Book added successfully.\n");
                } else {
                    printf("Database is full, cannot add more books.\n");
                }
                break;

            case 2:
                printf("Enter book name to remove: ");
                fgets(bookName, sizeof(bookName), stdin);
                bookName[strcspn(bookName, "\n")] = '\0';  // Remove trailing newline

                found = 0;
                for (i = 0; i < bookCount; i++) {
                    if (strcmp(books[i], bookName) == 0) {
                        found = 1;
                        // Shift all books after the found one to the left
                        for (int j = i; j < bookCount - 1; j++) {
                            strcpy(books[j], books[j + 1]);
                        }
                        bookCount--;
                        printf("Book removed successfully.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Book not found.\n");
                }
                break;

            case 3:
                printf("Enter book name to search: ");
                fgets(bookName, sizeof(bookName), stdin);
                bookName[strcspn(bookName, "\n")] = '\0';  // Remove trailing newline

                found = 0;
                for (i = 0; i < bookCount; i++) {
                    if (strcmp(books[i], bookName) == 0) {
                        found = 1;
                        printf("Book found: %s\n", books[i]);
                        break;
                    }
                }
                if (!found) {
                    printf("Book not found.\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
