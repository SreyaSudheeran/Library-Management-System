#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library-management.h"

// Read books from CSV
void read_books_from_csv(Book books[], int *book_count) {
    FILE *file = fopen("books.csv", "r");
    if (!file) return;  // No file, assume empty list

    while (fscanf(file, "%d,%99[^,],%99[^,],%d,%d\n", 
                  &books[*book_count].book_no,
                  books[*book_count].book_name, 
                  books[*book_count].author,
                  &books[*book_count].no_of_books,
                  &books[*book_count].no_of_books_available) == 5) {
        (*book_count)++;
    }
    fclose(file);
}

// Write books to CSV
void write_books_to_csv(Book books[], int book_count) {
    FILE *file = fopen("books.csv", "w");
    for (int i = 0; i < book_count; i++) {
        fprintf(file, "%d,%s,%s,%d,%d\n", 
                books[i].book_no, books[i].book_name, books[i].author,
                books[i].no_of_books, books[i].no_of_books_available);
    }
    fclose(file);
}

// Read users from CSV
void read_users_from_csv(User users[], int *user_count) {
    FILE *file = fopen("users.csv", "r");
    if (!file) return;  // No file, assume empty list

    while (fscanf(file, "%d,%99[^,],%d,%d,%d,%10[^,],%10[^\n]\n", 
                  &users[*user_count].id, users[*user_count].name,
                  &users[*user_count].books_issued.len,
                  &users[*user_count].books_issued.books_no[0],
                  &users[*user_count].books_issued.books_no[1],
                  users[*user_count].books_issued.return_date[0],
                  users[*user_count].books_issued.return_date[1]) == 7) {
        (*user_count)++;
    }
    fclose(file);
}

// Write users to CSV
void write_users_to_csv(User users[], int user_count) {
    FILE *file = fopen("users.csv", "w");
    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%d,%s,%d,%d,%d,%s,%s\n", 
                users[i].id, users[i].name, users[i].books_issued.len,
                users[i].books_issued.books_no[0], 
                users[i].books_issued.books_no[1],
                users[i].books_issued.return_date[0], 
                users[i].books_issued.return_date[1]);
    }
    fclose(file);
}

// Add a new book
void add_book(Book books[], int *book_count) {
    printf("Enter book number: ");
    scanf("%d", &books[*book_count].book_no);
    printf("Enter book name: ");
    getchar();  // Consume newline
    fgets(books[*book_count].book_name, 100, stdin);
    books[*book_count].book_name[strcspn(books[*book_count].book_name, "\n")] = 0;
    printf("Enter author name: ");
    fgets(books[*book_count].author, 100, stdin);
    books[*book_count].author[strcspn(books[*book_count].author, "\n")] = 0;
    printf("Enter total copies: ");
    scanf("%d", &books[*book_count].no_of_books);
    books[*book_count].no_of_books_available = books[*book_count].no_of_books;

    (*book_count)++;
    write_books_to_csv(books, *book_count);
    printf("Book added successfully!\n");
}

// Add a new user
void add_user(User users[], int *user_count) {
    printf("Enter user ID: ");
    scanf("%d", &users[*user_count].id);
    printf("Enter user name: ");
    getchar();  // Consume newline
    fgets(users[*user_count].name, 100, stdin);
    users[*user_count].name[strcspn(users[*user_count].name, "\n")] = 0;
    users[*user_count].books_issued.len = 0;

    (*user_count)++;
    write_users_to_csv(users, *user_count);
    printf("User added successfully!\n");
}

// Display all books in the library
void display_books(Book books[], int book_count) {
    printf("\n--- Library Books ---\n");
    for (int i = 0; i < book_count; i++) {
        printf("Book No: %d, Name: %s, Author: %s, Total: %d, Available: %d\n",
               books[i].book_no, books[i].book_name, books[i].author,
               books[i].no_of_books, books[i].no_of_books_available);
    }
}


// Display all users
void display_users(User users[], int user_count) {
    printf("\n--- Library Users ---\n");
    for (int i = 0; i < user_count; i++) {
        printf("ID: %d, Name: %s, Books Issued: %d\n",
               users[i].id, users[i].name, users[i].books_issued.len);
        for (int j = 0; j < users[i].books_issued.len; j++) {
            printf("  Book No: %d, Return Date: %s\n",
                   users[i].books_issued.books_no[j], users[i].books_issued.return_date[j]);
        }
    }
}
