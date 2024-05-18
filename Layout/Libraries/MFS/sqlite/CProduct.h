#ifndef __PRODUCT_
#define __PRODUCT_

#include <iostream>

using namespace std;

class CProduct
{
    public:
    CProduct();
    CProduct( string Name, string Barcode, string Price,string Suplier); //os objetos sao criados no Products.json
    CProduct( string Name, string Barcode, string Price,int Quantity, string Suplier);
    CProduct( string Name, size_t Buyed_Qty);
    ~CProduct();

    void setName(string NewName);
    void setBarcode(string NewBarcode);
    void setPrice(string NewPrice);
    void IncQuantity();
    void DecQuantity();
    void setSuplier(string NewSuplier);
    void setBuyed_Qty(size_t Buyed_Qty);
    void incBuyed_Qty();
    void setScansAmount(int Amount);
    void incScansAmount();

    string getName();
    string getBarcode();
    string getPrice();
    string getSuplier();
    size_t getQuantity();
    size_t getBuyed_Qty();
    int getScansAmount();

    bool operator==(const CProduct &other)const;
    
    private:
    string Name, Barcode, Suplier, Price;
    size_t Quantity, Buyed_Qty, Scanned_counter;
};

#endif
