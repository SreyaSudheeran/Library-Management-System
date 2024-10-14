// main.c
#include <stdio.h>
#include "library-management.h"

#define MAX_BOOKS 100
#define MAX_USERS 50

int main() {
    Book books[MAX_BOOKS];
    User users[MAX_USERS];
    int book_count = 0, user_count = 0;

    // Load data from CSV files
    read_books_from_csv(books, &book_count);
    read_users_from_csv(users, &user_count);

    int choice;
    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n2. Display Books\n3. Add User\n4. Display Users\n");
        printf("5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book(books, &book_count);
                break;
            case 2:
                display_books(books, book_count);
                break;
            case 3:
                add_user(users, &user_count);
                break;
            case 4:
                display_users(users, user_count);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
