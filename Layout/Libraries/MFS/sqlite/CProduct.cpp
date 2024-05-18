#include <iostream>
#include "CProduct.h"
CProduct::CProduct(){}
CProduct::CProduct(string Name, string Barcode, string Price,string Suplier): Buyed_Qty(0),Scanned_counter(0)
{
    this->Name = Name;
    this->Barcode = Barcode;
    this->Price = Price;
    this->Suplier = Suplier;
}
CProduct::CProduct(string Name, string Barcode, string Price,int Quantity, string Suplier): Buyed_Qty(0),Scanned_counter(0)
{
    this->Name = Name;
    this->Barcode = Barcode;
    this->Price = Price;
    this->Quantity = Quantity;
    this->Suplier = Suplier;
}

CProduct::CProduct( string Name, size_t Buyed_Qty): Buyed_Qty(0),Scanned_counter(0)
{
    this->Name = Name;
    this->Buyed_Qty = Buyed_Qty;
}

CProduct::~CProduct()
{
    this->Name = "";
    this->Barcode = "";
    this->Price = "";
    this->Quantity = 0;
    this->Suplier = "";
}

void CProduct::setName(string NewName)       {this->Name = NewName;}
void CProduct::setPrice(string NewPrice)     {this->Price = NewPrice;}
void CProduct::setBarcode(string NewBarcode) {this->Barcode = NewBarcode;}
void CProduct::IncQuantity()                 {this->Quantity += 1;}
void CProduct::DecQuantity()                 {this->Quantity -= 1;}
void CProduct::setSuplier(string NewSuplier) {this->Suplier = NewSuplier;}
void CProduct::setBuyed_Qty(size_t Buyed_Qty){this->Buyed_Qty = Buyed_Qty;}
void CProduct::incBuyed_Qty()                {this->Buyed_Qty +=1;}
void CProduct::setScansAmount(int Amount)    {this->Scanned_counter = Amount;}
void CProduct::incScansAmount(){this->Scanned_counter +=1; }

string CProduct::getName()        {return Name;}
string CProduct::getBarcode()     {return Barcode;}
string CProduct::getPrice()       {return Price;}
string CProduct::getSuplier()     {return Suplier;}
size_t CProduct::getQuantity()    {return Quantity;}
size_t CProduct::getBuyed_Qty()   {return Buyed_Qty;};
int CProduct::getScansAmount() {return Scanned_counter;}


bool CProduct::operator==(const CProduct &other)const
{
    return (Name == other.Name && Barcode == other.Barcode && Price == other.Price && Quantity == other.Quantity && Suplier == other.Suplier);

}
