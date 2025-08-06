// Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

void showMenu();
void showAllBooks();
void borrowBooks();
void returnBooks();
void sortBooks();
void addNewBooks();

Book arrayBook[300];
//TODO: Change totalBooks to 5
int totalBooks = 3;

int main()
{
    cout << boolalpha; // displays true instead of 1 and false instead of 0 for boolean values
   /* Book book1;
    book1.setBookDetails("Twilight", "AAAAA", "Alex", true);
    Book book2;
    book2.setBookDetails("Sapiens", "BBBBB", "Camila", true);
    Book book3;
    book3.setBookDetails("Harry Potter", "CCCCC", "Zin Ko", true);*/
    //TODO: ADD 2 MORE BOOKS

   /* arrayBook[0] = book1;
    arrayBook[1] = book2;
    arrayBook[2] = book3;*/

    int option;
    while (true) {
        showMenu();
        cout << "Select an option from 1 to 6: ";
        cin >> option;
        if (option == 1) { //display all books
            showAllBooks();
        }else if (option == 2) {
            borrowBooks();
        }else if (option == 3) {
            returnBooks();
        }else if (option == 4) {
            sortBooks();
        }else if (option == 5) {
            addNewBooks();
        }else if (option == 6) {
            cout << "BYE I hope to see you soon again!";
            break;
        }else {
            cout << "Invalid Option, please select and option from 1 to 6" << endl;
        }

    }

    /*

    */
}

void showMenu() {
    cout << "========================================" << endl;
    cout << "=             LIBRARY MENU             =" << endl;
    cout << "========================================" << endl;
    cout << "= 1: Show all books                    =" << endl;
    cout << "= 2: Borrow Books                      =" << endl;
    cout << "= 3: Return a Book                     =" << endl;
    cout << "= 4: Sort Books                        =" << endl;
    cout << "= 5: Add New Books                     =" << endl;
    cout << "= 6: QUIT the program                  =" << endl;
    cout << "========================================" << endl;
    cout << endl;

}

void showAllBooks() {
    cout << "========================================" << endl;
    cout << "=          Displaying all Books        =" << endl;
    cout << "========================================" << endl;
    int counter = 0;
    for (int i = 0; i < totalBooks; i++)
    {
        //validate the book has at least isbn and also title to display it
        if (!arrayBook[i].isbn.empty() && !arrayBook[i].title.empty()) {
            cout << "isbn: " << arrayBook[i].isbn << ", "
            << "title: " << arrayBook[i].title << ", "
            << "author: " << arrayBook[i].author << ", "
            << "available: " << arrayBook[i].available << endl;
            counter++;
        }
    }
    if (counter == 0) {
        cout << "==> There are NO Books registered yet!" << endl;
    }
    cout << endl;
}

void borrowBooks() {
    cout << "========================================" << endl;
    cout << "=             Borrowing Books          =" << endl;
    cout << "========================================" << endl;
    string isbnToBorrow = "";
    bool found = false;
    while (isbnToBorrow != "0") {

        cout << "==> Input the book's ISBN you want to borrow or 0 (zero) to Quit: ";
        cin >> isbnToBorrow;

        for (int i = 0; i < totalBooks; i++)
        {
            if (arrayBook[i].isbn == isbnToBorrow) {
                found = true;
                if (arrayBook[i].borrowBook()) {
                    cout << "==> You have borrowed the book: " << arrayBook[i].title << endl;
                    cout << "==> Don't forget to return the book: " << arrayBook[i].title << endl;
                    break;
                }
                else { // we couldn't borrow the book
                    cout << "==> The book is unavailable" << endl;
                }
            }
            
        }
        //after searching for all books, we check if we found the book
        if (!found) {
            cout << "==> Book NOT FOUND" << endl;
        }

    }
    cout << endl;
}

void returnBooks() {
    bool found = false;
    cout << "========================================" << endl;
    cout << "=            Returning Books           =" << endl;
    cout << "========================================" << endl;
    string isbnToReturn;
    cout << "==> Input the ISBN of the book you want to return, 0 (zero) to QUIT ";
    cin >> isbnToReturn;
    for (int i = 0; i < totalBooks; i++)
    {
        if (arrayBook[i].isbn == isbnToReturn) {
            found = true;
            arrayBook[i].returnBook();
            cout << "==> You have returned the book: " << arrayBook[i].title << endl;
        }
    }
    //after searching for all books, we check if we found the book
    if (!found) {
        cout << "==> Book NOT FOUND" << endl;
    }
    cout << endl;
}
void sortBooks() {
    cout << "========================================" << endl;
    cout << "=             Sorting Books            =" << endl;
    cout << "========================================" << endl;
    Book temp;
    for (int i = 0; i < totalBooks - 1; i++){
        for (int j = i + 1; j < totalBooks; j++){
            if (arrayBook[i].title > arrayBook[j].title) {
                //swap book positions
                temp = arrayBook[i];
                arrayBook[i] = arrayBook[j];
                arrayBook[j] = temp;
            }
        }
    }
    cout << endl;
}

void addNewBooks() {
    cout << "========================================" << endl;
    cout << "=            Adding New Books          =" << endl;
    cout << "========================================" << endl;
    string title;
    string isbn;
    string author;
    bool available;
    int index = 0;
    char answer;
    bool addAnotherBook = true;
    while (addAnotherBook) {
        Book book; // create a book variable / instance to store the data.
        cout << "Book's title: ";
        getline(cin, title);
        cout << "Book's ISBN: ";
        getline(cin, isbn);
        cout << "Book's author: ";
        getline(cin, author);
        //place all information in the created book
        book.setBookDetails(title, isbn, author, true);
        //adding the book to the array
        arrayBook[index] = book;
        cout << "Book: " << book.title << " added."<<endl;
        index++; // increment the book index
        cout << "Would you like to add another book (Y/N) ? ";
        cin >> answer;
        if (answer == 'N' or answer == 'n'){
            addAnotherBook = false;
        }
    }
    cout << endl;
}