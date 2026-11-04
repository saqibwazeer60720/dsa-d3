#include <iostream>
#include <string>
using namespace std;

class Item
{
public:
    virtual void display() = 0;
};

class Book : public Item
{
public:
    string title, author;
    int pages;

    Book()
    {
        title = "";
        author = "";
        pages = 0;
    }

    Book(string t, string a, int p)
    {
        title = t;
        author = a;
        pages = p;
    }

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};

class Newspaper : public Item
{
public:
    string name, date, edition;

    Newspaper(string n, string d, string e)
    {
        name = n;
        date = d;
        edition = e;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};

template <class T>
int linearSearch(T arr[], int size, string key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].title == key)
        {
            return i;
        }
    }

    return -1;
}

template <class T>
int binarySearch(T arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid].pages == key)
        {
            return mid;
        }
        else if (arr[mid].pages < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    Book books[2] = {
        Book("The Catcher in the Rye", "J.D. Salinger", 277),
        Book("To Kill a Mockingbird", "Harper Lee", 324)
    };

    Newspaper newspapers[2] = {
        Newspaper("Washington Post", "2024-10-13", "Morning Edition"),
        Newspaper("The Times", "2024-10-12", "Weekend Edition")
    };

    cout << "Books:" << endl;

    for (int i = 0; i < 2; i++)
    {
        books[i].display();
        cout << endl;
    }

    cout << "Newspapers:" << endl;

    for (int i = 0; i < 2; i++)
    {
        newspapers[i].display();
        cout << endl;
    }

    for (int i = 0; i < 1; i++)
    {
        if (books[i].pages > books[i + 1].pages)
        {
            Book temp = books[i];
            books[i] = books[i + 1];
            books[i + 1] = temp;
        }
    }

    cout << "Linear Search:" << endl;

    int result = linearSearch(books, 2, "The Catcher in the Rye");

    if (result != -1)
    {
        books[result].display();
    }
    else
    {
        cout << "Book not found." << endl;
    }

    cout << "Binary Search:" << endl;

    result = binarySearch(books, 2, 324);

    if (result != -1)
    {
        books[result].display();
    }
    else
    {
        cout << "Book not found." << endl;
    }

    return 0;
}