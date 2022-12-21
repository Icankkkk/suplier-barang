#ifndef SUPLIER_H
#define SUPLIER_H

#include <string>

struct Suplier {
	std::string _namaBarang;
	int _jumlahBarang;
	int _hargaBarang;
	long int _total;
	int _diskon;
	long int _bayar;	
};

long int grandTotal;
long int bayar;
long int kembali;

#endif
