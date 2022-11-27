// BOOKSHOP INVENTORY SYSTEM

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#define max 100
class BOOKSHOP
{
private:
    int bookid;
    string bookname;
    string authorname;
    string bookgenre;
    int bookprice;

public:
    void addbook();
    int Id();
    string Title();
    string Author();
    string Genre();
    int Price();
    int books_sold();
    int booksremained();
};
void BOOKSHOP::addbook()//[THIS BLOCK OF CODE IS FOR THE ADDING OF BOOKS INTOTHE SYSTEM AND VALIDATING OR FULFILLING THE CRITERIA FOR THE SYSTEM INPUT]
{
    cout << "enter book name:\n";
    cin >> bookname;
    if (bookname.length()<=3)
    {
        cout << "invalid bookname" << endl;
    }
    cout << "enter book id:\n";
    cin >> bookid;
    if (bookid==0)
    {
        cout << "invalid bookid" << endl;
    }
    cout << "enter author's name:\n";
    cin >> authorname;
    if (authorname.length() <=3)
    {
        cout << "invalid authorname" << endl;
    }

    cout << "enter genre of book:\n";
    cin >> bookgenre;
    if (bookgenre.length() <= 3)
    
    {
        cout << "invalid bookgenre" << endl;
    }

    cout << "enter book price:\n";
    cin >> bookprice;
    if (bookprice<=0)
    {
        cout<<"invalid bookprice"<<endl;
    }
    
}
int BOOKSHOP::Id()
{
    return bookid;
}
string BOOKSHOP::Title()
{
    return bookname;
}

string BOOKSHOP::Author()
{
    return authorname;
}
string BOOKSHOP::Genre()
{
    return bookgenre;
}
int BOOKSHOP::Price()
{
    return bookprice;
}
void firstrow()
{
    cout << left << setw(10) << "ID"
         << left << setw(10) << "TITLE"
         << left << setw(10) << "GENRE"
         << left << setw(10) << "AUTHOR"
         << left << setw(10) << "PRICE" << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
}
void firstrow(int a)
{
    ofstream ofs;
    ofs.open("BOOKSHOP_INVENTORY.txt", ios::out);
    ofs << left << setw(10) << "ID"
        << left << setw(10) << "TITLE"
        << left << setw(10) << "GENRE"
        << left << setw(10) << "AUTHOR"
        << left << setw(10) << "PRICE" << endl;
    ofs << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
}
void displaybook(BOOKSHOP BOOK)
{
    firstrow();
    cout << left << setw(10) << BOOK.Id();
    cout << left << setw(10) << BOOK.Title();
    cout << left << setw(10) << BOOK.Genre();
    cout << left << setw(10) << BOOK.Author();
    cout << left << setw(10) << BOOK.Price();
}
void displaybook(BOOKSHOP BK[], int x)
{
    for (int i = 0; i < x; i++)
    {
        cout << left << setw(10) << BK[i].Id();
        cout << left << setw(10) << BK[i].Title();
        cout << left << setw(10) << BK[i].Genre();
        cout << left << setw(10) << BK[i].Author();
        cout << left << setw(10) << BK[i].Price();
    }
}
void displaybook(BOOKSHOP B[], int g, int y)
{
    ifstream ifs; // read only
    ifs.open("BOOKSHOP_INVENTORY.txt", ios::in);
    ofstream ofs; // write only
    if (ifs.fail())
    {
        cout << "file not found\n";
        ifs.close();
    }
    else
    {
        ofs.open("BOOKSHOP_INVENTORY.txt", ios::app);
        firstrow(1);
        for (int i = 0; i < g; i++)
        {
            ofs << left << setw(10) << B[i].Id();
            ofs << left << setw(10) << B[i].Title();
            ofs << left << setw(10) << B[i].Genre();
            ofs << left << setw(10) << B[i].Author();
            ofs << left << setw(10) << B[i].Price();
        }
        ofs.close();
    }
}
void emptyfile()
{
    ofstream ofs;
    ofs.open("BOOKSHOP_INVENTORY.txt", ios::out);
    ofs << " ";
    ofs.close();
}
int br = 0, sales = 0;
void findbook(BOOKSHOP BK[], string name, string gn,int n)
{
    for (int i = 0; i < n; i++)
    {
        if (name.compare(BK[i].Title()) == 0 && gn.compare(BK[i].Genre())==0)
        {
            cout << "Book found!" << endl;
            br--;
            sales++;
            displaybook(BK[i]);
            cout<<"books remained:"<<br<<endl;
            cout<<"books sold:"<<sales<<endl;
            break;
            
        }
        
    }
}
void findBook_author(BOOKSHOP BK[], string a_name, int nu)
{
    for (int i = 0; i < nu; i++)
    {
        if (a_name.compare(BK[i].Author()) == 0 )
        {
            cout << "book found!" << endl;
            displaybook(BK[i]);
            break;
        }
    }
}
int BOOKSHOP::booksremained()
{
    return br;
}
int BOOKSHOP::books_sold()
{
    return sales;
} 
void display_earnings()
{
    cout<<left<<setw(10)<<"TOTAL EARNING OF THE DAY"
        <<left<<setw(10)<<"TOTAL EARNING OF THE WEEK"
        <<left<<setw(10)<<"TOTAL EARNING OF THE MONTH"
        <<left<<setw(10)<<"TOTAL EARNING OF THE YEAR"<<endl;
    cout<<"**********************************************************************************************************************";    
}
void display_earnings(int v)
{
    ofstream ofs;
    ofs.open("BOOKSHOP_EARNING.txt",ios::out);
    ofs<<left<<setw(10)<<"TOTAL EARNING OF THE DAY"
       <<left<<setw(10)<<"TOTAL EARNING OF THE WEEK"
       <<left<<setw(10)<<"TOTAL EARNING OF THE MONTH"
       <<left<<setw(10)<<"TOTAL EARNING OF THE YEAR"<<endl;
    ofs<<"**********************************************************************************************************************";
}
void display_earnings(BOOKSHOP Bk[])
{

   ofstream ofs;
   ofs.open("BOOKSHOP_EARNING.txt",ios::app);
   display_earnings(2);
   for (int i = 0; i < sales; i++)
   {
    ofs<<left<<setw(10)<<(Bk[i].books_sold() * Bk[i].Price())
       <<left<<setw(10)<<(Bk[i].books_sold() * Bk[i].Price() * 7)
       <<left<<setw(10)<<(Bk[i].books_sold() * Bk[i].Price() * 30)
       <<left<<setw(10)<<(Bk[i].books_sold() * Bk[i].Price() * 365)<<endl;
    ofs<<"*********************************************************************************************************************";
   }
   
}
int main()
{
    int books = 0;
    int abooks = 0;
    BOOKSHOP BK[max];
    int choice;
    cout << "*********************************************************************************************************************";
    cout << "enter your choice:.\n1. Add books\n2. Find book\n3.Find book  by given author name\n4.number of books remained\n5.number of books soldout\n6. Display books\n7. Print file\n8. Clear file\n9. Exit\n";
    cout << "*********************************************************************************************************************";
    cin >> choice;
    switch (choice)
    {
    case 1: // to add books in the bookshop inventory(done by the book seller in bookshop)
        int n;
        cout << "Enter number of books to add:\n";
        cin >> n;
        cout << "------------------------------------------------------------------------------------------------" << endl;
        while (books < n) // loop runs until  n becomes zero
        {
            cout << "\nEnter details for book " << books + 1 << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;
            BK[max].addbook();
            books++;
        }
        break;
    case 2:
    {
        string book_name,Bookgenre;
        cout << "enter name of book and genre to be searched:\n";
        cin >> book_name;
        cin>>Bookgenre;
        if (book_name.length()>=3 && Bookgenre.length()>=3)
        {
           findbook(BK, book_name,Bookgenre, books);    
        }
        else
        {
            cout<<"invalid customer input,please ask valid data from the customer"<<endl;
        }
    }
    break;
    case 3:
    {
        string author_name;
        cout << "enter name of author:\n";
        cin >> author_name;
        if (author_name.length()>=3)
        {
             findBook_author(BK, author_name, abooks);
        }
        else
        {
            cout<<"invalid customer input,please ask valid data from the customer"<<endl;
        }
    }
    break;

    case 4:
        cout << "books reamined in inventory:" << booksremained();
    case 5:
        cout << "books soldout form the bookshop:" << books_sold();
    case 6:
        firstrow();
        displaybook(BK, books);
        break;
    case 7:
        cout << "Printing..." << endl;
        displaybook(BK, books, 1);
        break;
    case 8:
        emptyfile();
        break;
    case 9:
        exit(0);
        break;

    default:
        return false;
        break;
    }
    return 0;
}
