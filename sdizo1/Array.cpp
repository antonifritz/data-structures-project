#include <iostream>
#include "Array.h"

Array::Array(int size)
{
	this->size = size;
	this->array = new int[size];              //zaalokowanie tablicy o rozmiarze size
}

int Array::getArray(int index)
{
	return this->array[index];				  //zwraca element tablicy o danym indeksie
}

int* Array::getArrayPointer()
{
	return this->array;
}

int Array::getSize()
{
	return this->size;						  //zwraca rozmiar tablicy
}

void Array::setArray(int index, int num)
{
	this->array[index] = num;				  //ustawia element tablicy o danym indeksie
}

void Array::setSize(int size)
{							
	this->size = size;						  //ustawia rozmiar tablicy
}

void Array::insertArrayBeginning(int newElement)
{
	int* oldArray = this->array;

	int* newArray = new int[this->size + 1];  //zaalokowanie nowej tablicy powi�kszonej o 1

	for (int i = 1; i < this->size + 1; i++)
	{
		newArray[i] = this->array[i - 1];     //przypisanie warto�ci ze starej tablicy pomijaj�c indeks 0
	}

	newArray[0] = newElement;				  //nowy element przypisywany do kom�rki o indeksie 0

	this->array = newArray;                   //ustawienie wska�nika na now� tablic�

	delete[] oldArray;                        //usuni�cie starej tablicy

	this->setSize(this->size + 1);            //zwi�kszenie rozmiaru
}

void Array::insertArrayCustom(int index, int newElement)
{
	int* oldArray = this->array;

	int* newArray = new int[this->size + 1];  //zaalokowanie tablicy powi�kszonej o 1

	for (int i = 0; i < index; i++)
	{
		newArray[i] = oldArray[i];			  //przypisanie warto�ci dla indeks�w mniejszych ni� zadeklarowany
	}

	newArray[index] = newElement;             //przypisanie nowego elementu dla zadeklarowanego indeksu tablicy

	for (int i = index + 1; i < this->size + 1; i++)
	{
		newArray[i] = oldArray[i - 1];        //przypisanie reszty kom�rek tablicy
	}

	this->array = newArray;					  //ustawienie tablicy na now�

	delete[] oldArray;						  //usuni�cie starej tablicy

	this->setSize(this->size + 1);			  //zwi�kszenie rozmiaru
}

void Array::insertArrayEnd(int newElement)
{
	int* oldArray = this->array;			  

	int* newArray = new int[this->size + 1];  //zaalokowanie tablicy o powi�kszonej o 1

	for (int i = 0; i < this->size; i++)
	{
		newArray[i] = oldArray[i];			  //przypisanie warto�ci
	}

	newArray[this->size] = newElement;        //nowy element przypisany na ostatni indeks

	this->array = newArray;					  //ustawienie tablicy na now�

	delete[] oldArray;						  //usuni�cie starej tablicy

	this->setSize(this->size + 1);            //zwi�kszenie rozmiaru o 1
}

void Array::deleteArrayBeginning()			  
{
	if (this->size == 0)
	{
		std::cout << "Tablica jest pusta!" << std::endl;
		return;
	}

	int* oldArray = this->array;

	int* newArray = new int[this->size - 1];  //zaalokowanie tablicy pomniejszonej o 1

	for (int i = 0; i < size - 1; i++)
	{
		newArray[i] = oldArray[i + 1];		  //przepisanie element�w pomijaj�c ten o indeksie 0
	}

	this->array = newArray;					  //ustawienie wska�nika na now� tablic�

	delete[] oldArray;						  //usuni�cie starej tablicy

	this->setSize(this->size - 1);            //zmniejszenie rozmiaru o 1
}

void Array::deleteArrayCustom(int index)      
{
	int* oldArray = this->array;			  

	int* newArray = new int[this->size - 1];  //zaalokowanie nowej tablicy o rozmiarze o 1 mniejszym

	for (int i = 0; i < index; i++)
	{
		newArray[i] = oldArray[i];            //przypisanie warto�ci dla element�w o indeksie mniejszym od zadeklarowanego
	}

	for (int i = index; i < this->size - 1; i++)
	{
		newArray[i] = oldArray[i + 1];		  //'omini�cie' elementu o zadeklarowanym indeksie
	}

	this->array = newArray;					  //przypisanie wska�nika do nowej tablicy

	delete[] oldArray;						  //usuni�cie starej tablicy

	this->setSize(this->size - 1);			  //zwi�kszenie rozmiaru o 1
}

void Array::deleteArrayEnd()
{
	if (this->size == 0)
	{
		std::cout << "Tablica jest pusta!" << std::endl;
		return;
	}

	int* oldArray = this->array;

	int* newArray = new int[this->size - 1];  //zaalokowanie tablicy o rozmiarze o 1 mniejszym

	for (int i = 0; i < this->size - 1; i++)	
	{
		newArray[i] = oldArray[i];			  //przypisanie warto�ci pomijaj�c element o najwi�kszym indeksie
	}

	this->array = newArray;					  //przypisanie wska�nika do nowej tablicy

	delete[] oldArray;						  //usuni�cie starej tablicy

	this->setSize(this->size - 1);			  //zmniejszenie rozmiaru o 1
}

int Array::searchArray(int key)
{
	for (int i = 0; i < this->size; i++)      
	{
		if (this->getArray(i) == key)        
		{
			return i;						  //je�li element jest r�wny zadeklarowanemu kluczowi zwracany jest indeks
		}
	}
	return -1;								  //je�li element nie zosta� znaleziony zwracane -1
}

void Array::showData()						  //wy�wietla tablic� na ekran konsoli
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << i << ": " << this->array[i] << std::endl;
	}
}
