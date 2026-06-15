#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    int bookID;
    string title;
    string author;
    bool issued;

    Book()
    {
        issued = false;
    }
};

int main()
{
    Book books[100];
    int count = 0;
    int choice;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search by Title";
        cout << "\n4. Search by Author";
        cout << "\n5. Issue Book";
        cout << "\n6. Return Book";
        cout << "\n7. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
        case 1:
            cout << "\nEnter Book ID: ";
            cin >> books[count].bookID;
            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, books[count].title);

            cout << "Enter Author: ";
            getline(cin, books[count].author);

            count++;
            cout << "Book Added Successfully!\n";
            break;

        case 2:
            cout << "\nBook List:\n";
            for(int i = 0; i < count; i++)
            {
                cout << "\nBook ID: " << books[i].bookID;
                cout << "\nTitle: " << books[i].title;
                cout << "\nAuthor: " << books[i].author;
                cout << "\nStatus: "
                     << (books[i].issued ? "Issued" : "Available")
                     << "\n";
            }
            break;

        case 3:
        {
            string searchTitle;
            cout << "\nEnter Title: ";
            getline(cin, searchTitle);

            bool found = false;

            for(int i = 0; i < count; i++)
            {
                if(books[i].title == searchTitle)
                {
                    cout << "\nBook Found!";
                    cout << "\nAuthor: " << books[i].author;
                    found = true;
                }
            }

            if(!found)
                cout << "\nBook Not Found!";
            break;
        }

        case 4:
        {
            string searchAuthor;
            cout << "\nEnter Author: ";
            getline(cin, searchAuthor);

            bool found = false;

            for(int i = 0; i < count; i++)
            {
                if(books[i].author == searchAuthor)
                {
                    cout << "\nTitle: " << books[i].title;
                    found = true;
                }
            }

            if(!found)
                cout << "\nAuthor Not Found!";
            break;
        }
         case 5:
        {
            int id;
            cout << "\nEnter Book ID to Issue: ";
            cin >> id;

            bool found = false;

            for(int i = 0; i < count; i++)
            {
                if(books[i].bookID == id)
                {
                    if(!books[i].issued)
                    {
                        books[i].issued = true;
                        cout << "\nBook Issued Successfully!";
                    }
                    else
                    {
                        cout << "\nBook Already Issued!";
                    }
                    found = true;
                }
            }

            if(!found)
                cout << "\nBook Not Found!";
            break;
        }

        case 6:
        {
            int id;
            cout << "\nEnter Book ID to Return: ";
            cin >> id;

            bool found = false;

            for(int i = 0; i < count; i++)
            {
                if(books[i].bookID == id)
                {
                    if(books[i].issued)
                    {
                        books[i].issued = false;
                        cout << "\nBook Returned Successfully!";
                    }
                    else
                    {
                        cout << "\nBook Was Not Issued!";
                    }
                    found = true;
                }
            }

            if(!found)
                cout << "\nBook Not Found!";
            break;
        }

        case 7:
            cout << "\nThank You!";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while(choice != 7);

    return 0;
}