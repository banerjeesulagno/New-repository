#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[100];
    char author[50];
    int year;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

// Function to add a book to the library
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter the title of the book: ");
    scanf("%s", library[bookCount].title);  // Simple input using scanf

    printf("Enter the author of the book: ");
    scanf("%s", library[bookCount].author);  // Simple input using scanf

    printf("Enter the publication year: ");
    scanf("%d", &library[bookCount].year);

    bookCount++;
    printf("Book added successfully!\n");
}

// Function to view all books in the library
void viewLibrary() {
    if (bookCount == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("Books in the Library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book %d:\n", i + 1);
        printf("  Title: %s\n", library[i].title);
        printf("  Author: %s\n", library[i].author);
        printf("  Year: %d\n", library[i].year);
    }
}

// Function to search for a book by title
void searchBook() {
    char searchTitle[100];
    printf("Enter the title of the book to search: ");
    scanf("%s", searchTitle);  // Simple input using scanf

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Book found:\n");
            printf("  Title: %s\n", library[i].title);
            printf("  Author: %s\n", library[i].author);
            printf("  Year: %d\n", library[i].year);
            return;
        }
    }
    printf("Book not found in the library.\n");
}

int main() {
    int choice;

    do {
        printf("\nBook Library System\n");
        printf("1. Add Book\n");
        printf("2. View Library\n");
        printf("3. Search Book by Title\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewLibrary(); break;
            case 3: searchBook(); break;
            case 4: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
