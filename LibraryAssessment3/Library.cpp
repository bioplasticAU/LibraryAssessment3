// Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;
//Testing update
void showMenu();
void showAllBooks();
void borrowBooks();
void returnBooks();
void sortBooks();
void addNewBooks();
void clearScreen();

Book arrayBook[100];
int totalBooks = 0;

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
        clearScreen();
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
    cout << char(178) << "             LIBRARY MENU             " << char(178) << endl;
    cout << "========================================" << endl;
    cout << char(178) << " 1: Show all books                    " << char(178) << endl;
    cout << char(178) << " 2: Borrow Books                      " << char(178) << endl;
    cout << char(178) << " 3: Return a Book                     " << char(178) << endl;
    cout << char(178) << " 4: Sort Books                        " << char(178) << endl;
    cout << char(178) << " 5: Add New Books                     " << char(178) << endl;
    cout << char(178) << " 6: QUIT the program                  " << char(178) << endl;
    cout << "========================================" << endl;
    cout << endl;

}

void showAllBooks() {
    cout << "========================================" << endl;
    cout << char(178) << "          Displaying all Books        " << char(178) << endl;
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
        cout << char(178) << "  There are NO Books registered yet!  " << char(178) << endl;
    }
    cout << endl;
}

void borrowBooks() {
    cout << "========================================" << endl;
    cout << char(178)<<"             Borrowing Books          "<<char(178) << endl;
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
    cout << char(178) << "            Returning Books           " << char(178) << endl;
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
    cout << char(178);
    cout << "        Books Sorted By Title         "; 
    cout << char(178) << endl;
    cout << "========================================" << endl;
    Book temp;
    for (int i = 0; i < totalBooks -1 ; i++){
        for (int j = i + 1; j < totalBooks; j++){
            if (arrayBook[i].title > arrayBook[j].title) {
                //swap book positions
                temp = arrayBook[i];
                arrayBook[i] = arrayBook[j];
                arrayBook[j] = temp;
            }
        }
    }
    
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
        cout << char(178) << "  There are NO Books registered yet!  " << char(178) << endl;
    }

    cout << endl;
}

void addNewBooks() {
    cout << "========================================" << endl;
    cout << char(178) << "            Adding New Books          " << char(178) << endl;
    cout << "========================================" << endl;
    string title;
    string isbn;
    string author;
    bool available;
    //int index = 0;
    
    char answer;
    bool addAnotherBook = true;
    while (addAnotherBook) {
        cin.ignore();
        Book book; // create a book variable / instance to store the data.
        cout << "Book's title: ";
        getline(cin, title);
        cout << "Book's ISBN: ";
        cin >> isbn;
        cin.ignore();
        cout << "Book's author: ";
        getline(cin, author);
        //place all information in the created book
        book.setBookDetails(title, isbn, author, true);
        //adding the book to the array
        arrayBook[totalBooks] = book;
        cout << "Book: " << book.title << " added."<<endl;
        totalBooks++; // increment the book index
        cout << "Would you like to add another book (Y/N) ? ";
        cin >> answer;
        if (answer == 'N' or answer == 'n'){
            addAnotherBook = false;
        }
    }
    
    cout << endl;
    
}

void clearScreen() {
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Linux/macOS/other Unix-like systems
#endif
}