// library-management.h

#ifndef LIBRARY_MANAGEMENT_H
#define LIBRARY_MANAGEMENT_H

// Book structure definition
typedef struct {
    int book_no;
    char book_name[100];
    char author[100];
    int no_of_books;
    int no_of_books_available;
} Book;

// User structure definition
typedef struct {
    char name[100];
    int id;
    struct {
        int len;
        int books_no[2];
        char return_date[2][11];  // Format: dd-mm-yyyy
    } books_issued;
} User;

// Function prototypes
void read_books_from_csv(Book books[], int *book_count);
void write_books_to_csv(Book books[], int book_count);
void read_users_from_csv(User users[], int *user_count);
void write_users_to_csv(User users[], int user_count);

void add_book(Book books[], int *book_count);
void display_books(Book books[], int book_count);
void add_user(User users[], int *user_count);
void display_users(User users[], int user_count);

#endif // LIBRARY_MANAGEMENT_H
