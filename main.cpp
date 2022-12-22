#include <iostream>
#include "suplier.cpp"

int main() {

	short int max;

	cout << "Nama anda: "; getline(cin, nama);
	cout << "Alamat anda: "; getline(cin, alamat);
	cout << "\nBerapa barang yang ingin di input? "; cin >> max; 
	cin.ignore(); // clear sisa karakter
	
	Suplier obj[max];
	transaksi(obj, max);
	
	return 0;
}
