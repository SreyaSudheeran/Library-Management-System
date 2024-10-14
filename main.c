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
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Add User\n");
        printf("4. Display Users\n");
        printf("5. Check Book Availability by Number\n");
        printf("6. Check Book Availability by Name\n");
        printf("7. Users Returning on a Specific Date\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
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
            case 5: {
                int book_no;
                printf("Enter Book Number: ");
                scanf("%d", &book_no);
                int availability = check_availability_by_no(books, book_count, book_no);
                if (availability) {
                    printf("Book number %d is available.\n", book_no);
                } else {
                    printf("Book number %d is not available.\n", book_no);
                }
                break;
            }
            case 6: {
                char book_name[100];
                printf("Enter Book Name: ");
                scanf(" %[^\n]", book_name); // Read string with spaces
                int availability = check_availability_by_name(books, book_count, book_name);
                if (availability) {
                    printf("Book named \"%s\" is available.\n", book_name);
                } else {
                    printf("Book named \"%s\" is not available.\n", book_name);
                }
                break;
            }
            case 7: {
                char date[11]; // Format: YYYY-MM-DD
                printf("Enter Date (YYYY-MM-DD): ");
                scanf("%s", date);
                users_returning_on_date(users, user_count, date);
                break;
            }
            case 8:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
