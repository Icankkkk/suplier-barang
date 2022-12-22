// file khusus implementasi semua fungsi-fungsi

#include <iostream>
#include "suplier.h"

using namespace std;

void pembatas(char a, int n) {
	for (int i = 0; i < n; i++) { cout << a;} cout << '\n';
}

// untuk input data suplier
void inputData(Suplier suplier[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Data ke-" << i + 1 << " :\n";
		cout << "Input nama barang: "; getline(cin, suplier[i]._namaBarang);
		cout << "Input jumlah barang: "; cin >> suplier[i]._jumlahBarang;
		cout << "Input harga barang: "; cin >> suplier[i]._hargaBarang;
		cin.ignore();
	}
}

// hitung semua data
void calculate(Suplier suplier[], int n) {
	for (int i = 0; i < n; i++) {
		suplier[i]._total = suplier[i]._hargaBarang * suplier[i]._jumlahBarang;

		// jika diskon
		if (suplier[i]._total <= 50000) 
		{
			suplier[i]._detailDiskon = "-(0%)";
			suplier[i]._bayar = suplier[i]._total;
		}
		else 
		{
			if (suplier[i]._total > 50000 && suplier[i]._total <= 100000)
			{
				suplier[i]._detailDiskon = "-(5%)";
				suplier[i]._diskon = (suplier[i]._total * 5) / 100;
				suplier[i]._bayar = suplier[i]._total - suplier[i]._diskon;
			}
			else if (suplier[i]._total > 100000 && suplier[i]._total <= 200000)
			{
				suplier[i]._detailDiskon = "-(10%)";
				suplier[i]._diskon = (suplier[i]._total * 10) / 100;
				suplier[i]._bayar = suplier[i]._total - suplier[i]._diskon;
			}
			else if (suplier[i]._total > 200000 && suplier[i]._total <= 400000)
			{
				suplier[i]._detailDiskon = "-(15%)";
				suplier[i]._diskon = (suplier[i]._total * 15) / 100;
				suplier[i]._bayar = suplier[i]._total - suplier[i]._diskon;
			} 
			else
			{
				suplier[i]._detailDiskon = " (25%)";
				suplier[i]._diskon = (suplier[i]._total * 25) / 100;
				suplier[i]._bayar = suplier[i]._total - suplier[i]._diskon;
			}
		}
		// jumlahkan semua total barang yang harus di bayarkan
		grandTotal += suplier[i]._bayar;
	}
}

void inputTunai() {
	cout << "Jumlah uang tunai: "; cin >> bayar;
}

void outputTunai() {
	// hitung kembalian
	kembali = bayar - grandTotal;
	
	cout << "Bayar: " << bayar << '\n';
	cout << "Kembali: " << kembali << '\n';
}

// cetak data suplier
void outputData(Suplier suplier[], int n) {
	pembatas('=', 100);
	for (int i = 0; i < n; i++) {
		cout << "Nama barang: " << suplier[i]._namaBarang << " | " << "Jumlah: " << suplier[i]._jumlahBarang << " | " << "Harga: " << suplier[i]._hargaBarang << " | " << "Total: " << suplier[i]._total << " | " << "Diskon: " << suplier[i]._diskon << suplier[i]._detailDiskon << " | " << "Bayar: " << suplier[i]._bayar << '\n';
	}
	pembatas('=', 100);
	cout << "Grand total: " << grandTotal << '\n';
}

void transaksi(Suplier suplier[], int n) {
	inputData(suplier, n);
	calculate(suplier, n);
	outputData(suplier, n);
	inputTunai();
	outputTunai();
}
