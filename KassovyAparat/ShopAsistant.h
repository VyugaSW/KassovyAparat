#pragma once

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class Product {
protected:
	char* name = new char[125];
	int count;
	int price;

	void setCount(Product* a, int c) {
		a->count = c;
	}

public:
	Product() : count{ 0 }, price{ 0 } { strcpy_s(name, 2, " "); };
	Product(const char* n, int c, int p) : count{ c }, price{ p } {
		strcpy_s(name, 126, n);
	};


};



class ShopAsisstant : public Product {
	static Product* products[12];
	static int generalMoney;
	int privateMoney = 0;

	


public:

	ShopAsisstant() : Product(" ", 0, 0) {};

	string sale(int numb, int userCount) {
		numb--;

		if (products[numb]->count < userCount || userCount <= 0)
			return "ERROR";
		if (numb >= 12 || numb <= 0)
			return "ERROR";


		privateMoney += products[numb]->getCount(products[numb]);
		generalMoney += products[numb]->getCount(products[numb]);



		setCount(products[numb], products[numb]->getCount(products[numb]) - userCount);

		return  to_string(userCount) + " " + products[numb]->getName(products[numb]) +
			" " + to_string(products[numb]->getPrice(products[numb]));
	}

	ostream& display(ostream& f) {
		for (int i = 0; i < 12; i++) {
			if (products[i]->getCount(products[i]) > 0) {
				f << left << setw(20) << products[i]->getName(products[i])
					<< setw(8) << to_string(products[i]->getPrice(products[i]))
					<< setw(8) << to_string(products[i]->getCount(products[i])) << endl;
			}
		}
		return f;
	}

	int getAllMoney() {
		return generalMoney;
	}
	int getMoney() {
		return privateMoney;
	}

};

int ShopAsisstant::generalMoney = 0;
Product* ShopAsisstant::products[] = { new Product("Bread",50,40),
		new Product("Milk",20,90), new Product("Wire",90,10), new Product("Potato",125,20),
		new Product("Shampoo",30,250), new Product("Children",15,99000),
		new Product("Fingers",75,105), new Product("La Pasta",25,125),
		new Product("HadPhone(left)",51,17), new Product("Krossovok(right)",21,500),
		new Product("Apple",800,5), new Product("Onion",20,3)
};
