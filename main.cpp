#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<cstring>
using namespace std;


class Date {
public:
    int day, month, year;

    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    long toDays() const
    {
        return year * 365L + month * 30 + day;//assumed each month=30days
    }

 
    int operator-(const Date& other) const
    {
        return (int)(this->toDays() - other.toDays());
    }

    void display() const 
 {
        cout << day << "/" << month << "/" << year;
    }
};


Date currentDate()
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    return Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}


class Item {
protected:
    char* name;
    float originalPrice;

public:
    Item(const char* n, float price) : originalPrice(price) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    virtual ~Item() {
        delete[] name;
    }
    virtual float getPrice() = 0;
    virtual void display() = 0;
};


class Perishable : public Item {
private:
    Date expiryDate;
    int quantity;

public:
    Perishable(char* n, float price, int day, int month, int year, int qty)
        : Item(n, price), expiryDate(day, month, year), quantity(qty) {
    }

    virtual float getPrice() override
    {
        Date today = currentDate();
        int diff = today - expiryDate;  
        return (diff > 0) ? 0.0f : originalPrice;
    }

    virtual void display() override {
        cout << "\n[Perishable Item]" << endl;
        cout << "  Name        : " << name << endl;
        cout << "  Orig. Price : Rs " << originalPrice << endl;
        cout << "  Expiry Date : "; expiryDate.display();                   
        cout << endl;
        cout << "  Quantity    : " << quantity << endl;
        cout << "  Status      : "
            << ((currentDate() - expiryDate > 0) ? "EXPIRED" : "Valid") << endl;
        cout << "  Sale Price  : Rs " << getPrice() << endl;
    }
};

class Permanent : public Item {
protected:
    Date entryDate;

public:
    Permanent(char* n, float price, int day, int month, int year)
        : Item(n, price), entryDate(day, month, year) {
    }

    // 0.02% depreciation per day
    virtual float getPrice() override
    {
        Date today = currentDate();
        int ageDays = today - entryDate;
        if (ageDays < 0) 
            ageDays = 0;
        float price = originalPrice - (originalPrice * 0.0002f * ageDays);
        return (price < 0.0f) ? 0.0f : price;
    }

    virtual void display() override 
    {
        Date today = currentDate();
        int ageDays = today - entryDate;
        cout << "\n[Permanent Item]" << endl;
        cout << "  Name        : " << name << endl;
        cout << "  Orig. Price : Rs " << originalPrice << endl;
        cout << "  Entry Date  : "; entryDate.display(); cout << endl;
        cout << "  Age (days)  : " << ageDays << endl;
        cout << "  Sale Price  : Rs " << getPrice() << endl;
    }
};


class Bulk_Item : public Permanent {
private:
    char* description;
    bool isSet;

public:
    Bulk_Item(char* n, float price, int day, int month, int year, char* desc, bool s)
        : Permanent(n, price, day, month, year), isSet(s)
    {
        description = new char[strlen(desc) + 1];
        strcpy(description, desc);
    }

    virtual ~Bulk_Item() {
        delete[] description;
    }

  
    virtual float getPrice() override {
        if (isSet) 
            return originalPrice;
        return Permanent::getPrice();
    }

    virtual void display() override {
        Date today = currentDate();
        int ageDays = today - entryDate;
        cout << "\n[Bulk Item]" << endl;
        cout << "  Name        : " << name << endl;
        cout << "  Description : " << description << endl;
        cout << "  Orig. Price : Rs " << originalPrice << endl;
        cout << "  Entry Date  : "; entryDate.display();                            
        cout << endl;
        cout << "  Age (days)  : " << ageDays << endl;
        cout << "  Is Set      : " << (isSet ? "Yes (fixed price)" : "No (depreciating)") << endl;
        cout << "  Sale Price  : Rs " << getPrice() << endl;
    }
};

class Pharmacy {
private:
    Item** items;
    int capacity;
    int count;

public:
    Pharmacy(int size) : capacity(size), count(0) {
        items = new Item * [capacity];
    }

    void AddItem(Item* item) {
        if (count < capacity)
            items[count++] = item;
        else
            cout << "Pharmacy is full!" << endl;
    }

    void DisplayItems() {
        cout << "\nPHARMACY INVENTORY" << endl;
        for (int i = 0; i < count; i++) {
            cout << "Item #" << (i + 1);
            items[i]->display();        
        }
        cout  << endl;
    }

    ~Pharmacy() {
        for (int i = 0; i < count; i++)
            delete items[i];         
        delete[] items;
    }
};


int main()
{
    int itemCount = 4;
    Pharmacy ph(itemCount);

    Item* iptr = new Permanent((char*)"glucometer", 5000, 15, 11, 2016);
    ph.AddItem(iptr);

    iptr = new Perishable((char*)"Panadol", 20, 16, 11, 2018, 500);
    ph.AddItem(iptr);

    iptr = new Bulk_Item((char*)"Gloves", 500, 12, 10, 2016,
        (char*)"Glove box for doctors", true);
    ph.AddItem(iptr);

    iptr = new Bulk_Item((char*)"5CC Syringe", 90, 15, 7, 2017,
        (char*)"For Injections only", false);
    ph.AddItem(iptr);

    ph.DisplayItems();
    return 0;
}



