#ifndef SUPLIER_H
#define SUPLIER_H

#include <string>

struct Suplier {
	std::string _namaBarang;
	std::string _detailDiskon;
	int _jumlahBarang;
	float _hargaBarang;
	float _total;
	float _diskon;
	float _bayar;	
};

float  grandTotal;
float  bayar;
float  kembali;

std::string nama;
std::string alamat;

#endif
