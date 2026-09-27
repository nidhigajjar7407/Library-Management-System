#include<iostream>
#include<string>
using namespace std;

class LibraryItem{
    private:
        string title;
        string author;
        string dueDate;
    public:
        string getTitle(){
            return title;
        }
        string getAuthor(){
            return author;
        }
        string getDueDate(){
            return dueDate;
        }
        void setTitle(string newTitle){
            title = newTitle;
        }
        void setAuthor(string newAuthor){
            author = newAuthor;
        }
        void setDueDate(string newDueDate){
            dueDate = newDueDate;
        }

        virtual void checkOut() = 0;
        virtual void returnItem() = 0;
        virtual void displayDetails() = 0;

        LibraryItem(){

        }
        virtual ~LibraryItem(){
            
        }
};

class Book : public LibraryItem{
    private:
        string ISBN;

    public:
        void setISBN(string newISBN){
            ISBN = newISBN;
        }
        string getISBN(){
            return ISBN;
        }
        void checkOut() override{
            cout << "Book Checked Out Successfully" << endl;
        }
        void returnItem() override{
            cout << "Book Returned Successfully" << endl;
        }
        void displayDetails() override{
            cout << "Book Details : " << endl;
            cout << "Book ISBN : " << getISBN() << endl;
            cout << "Book Author : " << getAuthor() << endl;
            cout << "Book Due Date : " << getDueDate() << endl;
        }
};

class DVD : public LibraryItem{
    private:
        int duration;

    public:
        void setDuration(int newDuration){
            if(newDuration <= 0){
                throw invalid_argument("Duration must be Greater than 0...!");
            }
            duration = newDuration;
        }
        int getDuration(){
            return duration;
        }
        void checkOut() override{
            cout << "DVD Checked Out Successfully" << endl;
        }
        void returnItem() override{
            cout << "DVD Returned Successfully" << endl;
        }
        void displayDetails() override{
            cout << "DVD Details" << endl;
            cout << "DVD Title : " << getTitle() << endl;
            cout << "DVD Author : " << getAuthor() << endl;
            cout << "DVD Due Date : " << getDueDate() << endl;
            cout << "DVD Duration : " << getDuration() << endl;
        }
};

class Magazines : public LibraryItem{
    private:
        int issueNumber;

    public:
        void setIssueNumber(int newIssueNumber){
            if(newIssueNumber <= 0){
                throw invalid_argument("Duration must be Greater than 0...!");
            }
            issueNumber = newIssueNumber;
        }
        int getIssueNumber(){
            return issueNumber;
        }
        void checkOut() override{
            cout << "Magazines Checked Out Successfully" << endl;
        }
        void returnItem() override{
            cout << "Magazines Returned Successfully" << endl;
        }
        void displayDetails() override{
            cout << "Magazines Details" << endl;
            cout << "Magazines Title : " << getTitle() << endl;
            cout << "Magazines Author : " << getAuthor() << endl;
            cout << "Magazines Due Date : " << getDueDate() << endl;
            cout << "Magazines Issue Number : " << getIssueNumber() << endl;
        }
};

void addBook(LibraryItem* libraryItems[], int& itemCount, int MAX_ITEMS){
    if(itemCount >= MAX_ITEMS){
        throw runtime_error("Library is Full...");
    }

    Book* book = new Book();

    string title;
    string author;
    string dueDate;
    string ISBN;

    cout << "Enter Book Title : ";
    cin.ignore();
    getline(cin,title);

    cout << "Enter Book Author : ";
    cin.ignore();
    getline(cin,author);

    cout << "Enter Book Due Date : ";
    cin.ignore();
    getline(cin,dueDate);

    cout << "Enter Book ISBN : ";
    cin.ignore();
    getline(cin,ISBN);

    book->setTitle(title);
    book->setAuthor(author);
    book->setDueDate(dueDate);
    book->setISBN(ISBN);

    libraryItems[itemCount] = book;
    itemCount++;
    cout << "Book Added Successfully..." << endl;
}

void addDVD(LibraryItem* libraryItems[], int& itemCount, int MAX_ITEMS){
    if(itemCount >= MAX_ITEMS){
        throw runtime_error("Library is Full...");
    }

    DVD* dvd = new DVD();

    string title;
    string author;
    string dueDate;
    int duration;

    cout << "Enter DVD Title : ";
    cin.ignore();
    getline(cin,title);

    cout << "Enter DVD Author : ";
    cin.ignore();
    getline(cin,author);

    cout << "Enter DVD Due Date : ";
    cin.ignore();
    getline(cin,dueDate);

    cout << "Enter DVD Duration in Minutes : ";
    cin >> duration;
    

    dvd->setTitle(title);
    dvd->setAuthor(author);
    dvd->setDueDate(dueDate);
    dvd->setDuration(duration);

    libraryItems[itemCount] = dvd;
    itemCount++;
    cout << "DVD Added Successfully..." << endl;
}

void addMagazines(LibraryItem* libraryItems[], int& itemCount, int MAX_ITEMS){
    if(itemCount >= MAX_ITEMS){
        throw runtime_error("Library is Full...");
    }

    Magazines* magazine = new Magazines();

    string title;
    string author;
    string dueDate;
    int issueNumber;

    cout << "Enter DVD Title : ";
    cin.ignore();
    getline(cin,title);

    cout << "Enter DVD Author : ";
    cin.ignore();
    getline(cin,author);

    cout << "Enter DVD Due Date : ";
    cin.ignore();
    getline(cin,dueDate);

    cout << "Enter DVD Duration in Minutes : ";
    cin >> issueNumber;
    

    magazine->setTitle(title);
    magazine->setAuthor(author);
    magazine->setDueDate(dueDate);
    magazine->setIssueNumber(issueNumber);

    libraryItems[itemCount] = magazine;
    itemCount++;
    cout << "Magazines Added Successfully..." << endl;
}

void displayAllItems(LibraryItem* libraryItems[], int itemCount){
    if(itemCount == 0){
        cout << "No Items Available in the Library...";
        return;
    }

    cout << "=======================================" << endl;
    cout << "===========All Library Items===========" << endl;
    cout << "=======================================" << endl;

    for(int i = 0; i < itemCount; i++){
        cout << "Item Number : " << i + 1 << endl;
        libraryItems[i]->displayDetails();
    }
    
    cout << "=======================================" << endl;
}

void searchItem(LibraryItem* libraryItems[], int itemCount){
    if(itemCount == 0){
        cout << "No Items Available in the Library...";
        return;
    }

    string searchTitle;

    cout << "Enter Title to Search : ";
    cin.ignore();
    getline(cin,searchTitle);

    bool found = false;

    for(int i = 0; i < itemCount; i++){
        if(libraryItems[i]->getTitle() == searchTitle){
            cout << "Item Found..!" << endl;
            libraryItems[i]->displayDetails();
            found = true;
        }
    }

    if(!found){
        cout << "Item not Found..." << endl;
    }
}

void checkOutItem(LibraryItem* libraryItems[], int itemCount){
    if(itemCount == 0){
        cout << "No Items Available in the Library...";
        return;
    }

    string searchTitle;

    cout << "Enter Title to Check Out : ";
    cin.ignore();
    getline(cin,searchTitle);

    bool found = false;

    for(int i = 0; i < itemCount; i++){
        if(libraryItems[i]->getTitle() == searchTitle){
            libraryItems[i]->checkOut();
            found = true;
            break;
        }
    }

    if(!found){
        cout << "Item not Found..." << endl;
    }
}

void returnItem(LibraryItem* libraryItems[], int itemCount){
    if(itemCount == 0){
        cout << "No Items Available in the Library...";
        return;
    }

    string searchTitle;

    cout << "Enter Title to Return : ";
    cin.ignore();
    getline(cin,searchTitle);

    bool found = false;

    for(int i = 0; i < itemCount; i++){
        if(libraryItems[i]->getTitle() == searchTitle){
            libraryItems[i]->returnItem();
            found = true;
            break;
        }
    }

    if(!found){
        cout << "Item not Found..." << endl;
    }
}

int main(){

    const int MAX_ITEMS = 100;
    LibraryItem* libraryItems[MAX_ITEMS];

    int itemCount = 0;

    int choice;
    do
    {
        cout << "=======================================" << endl;
        cout << "=======Library Management System=======" << endl;
        cout << "=======================================" << endl;
        cout << "1. Add Book..." << endl;
        cout << "2. Add DVD..." << endl;
        cout << "3. Add Magagines..." << endl;
        cout << "4. Display All Items..." << endl;
        cout << "5. Search Item..." << endl;
        cout << "6. Check Out Item..." << endl;
        cout << "7. Return Item..." << endl;
        cout << "0. Exit..." << endl;
        cout << "Enter Your Choice : " << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                addBook(libraryItems,itemCount, MAX_ITEMS);
                break;
            case 2:
                addDVD(libraryItems,itemCount, MAX_ITEMS);
                break;
            case 3:
                addMagazines(libraryItems,itemCount, MAX_ITEMS);
                break;
            case 4:
                displayAllItems(libraryItems, itemCount);
                break;
            case 5:
                searchItem(libraryItems, itemCount);
                break;
            case 6:
                checkOutItem(libraryItems, itemCount);
                break;
            case 7:
                returnItem(libraryItems, itemCount);
                break;
            case 0:
                cout << "Thank You to Use LMS System..." << endl;
                break;            
            default:
                cout << "Invalid Choice..." << endl;
                break;
        }

    } while (choice);
    

    return 0;
}