#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 50
#define MAX_AUTHOR 50

typedef struct {
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    Book newBook;
    newBook.id = bookCount + 1;

    printf("Enter book title: ");
    getchar(); // Consume newline
    fgets(newBook.title, MAX_TITLE, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline

    printf("Enter author name: ");
    fgets(newBook.author, MAX_AUTHOR, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline

    library[bookCount] = newBook;
    bookCount++;
    printf("Book added successfully with ID %d.\n", newBook.id);
}

void viewBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("Books in the Library:\n");
    printf("ID\tTitle\t\t\tAuthor\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d\t%s\t\t%s\n", library[i].id, library[i].title, library[i].author);
    }
}

void deleteBook() {
    if (bookCount == 0) {
        printf("No books to delete.\n");
        return;
    }
    int id;
    printf("Enter the ID of the book to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > bookCount) {
        printf("Invalid book ID.\n");
        return;
    }

    for (int i = id - 1; i < bookCount - 1; i++) {
        library[i] = library[i + 1];
    }
    bookCount--;
    printf("Book with ID %d deleted successfully.\n", id);
}

int main() {
    int choice;

    do {
        printf("\nBook Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Delete Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

 return 0;
}
