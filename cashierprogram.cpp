#include <iostream>
#include <conio.h>
#include <string>

using namespace std;


int main()
{

	//Inisialisasi atau deklarasi variabel
	int jum_item, bayar, diskon, jumlah[50], harga[50], sub_tot[50];
	string jenis_pakaian[50], nama, pilih;
	float *tot, x;
	tot = &x;

menu:
	cout << "Member atau Non member <YA/TIDAK>: ";
	cin >> pilih;
	cout << "------------------------------------------" << endl
		 << endl;

	if (pilih == "YA")
	{
		cout << "========== Hai Member Toko Zalza ==========" << endl;
		cout << "Nama: ";
		cin.ignore();
		getline(cin, nama);
		cout << "Masukan Jumlah Item : ";
		cin >> jum_item; //Pengguna memasukan jumlah item

		for (int i = 0; i < jum_item; i++)
		{
			cout << "------------------------------------------" << endl;
			cout << "Masukan Barang Ke-" << i + 1 << endl;
			cout << "Jenis Pakaian : ";
			cin >> jenis_pakaian[i]; //Pengguna input Jenis Pakaian disimpan pada array jenis_pakaian
			cout << "Jumlah      : ";
			cin >> jumlah[i]; //Pengguna input jumlah disimpan pada array jumlah
			cout << "Harga       : ";
			cin >> harga[i];				   //Pengguna input harga disimpan pada array harga
			sub_tot[i] = jumlah[i] * harga[i]; // Menjumlahkan Harga sub total item
			*tot += sub_tot[i];				   //Menjumlahkan seluruh sub total item
		}

		//Kondisi untuk menentukan diskon yang didapatkan berdasarkan total belanja
		if (*tot >= 100000)
		{
			diskon = 0.05 * *tot;
			//Menampilkan Keterangan
			cout << "=============== PEMBAYARAN ===============" << endl;
			cout << "Jenis Member 	: Ya" << endl;
			cout << "Nama Pelanggan	: " << nama << endl;
			cout << "Jumlah Bayar 	: Rp." << *tot << endl;			 //Menampilkan jumlah bayar (belum termasuk diskon)
			cout << "Diskon        	: Rp." << diskon << endl;		 //Menampilkan diskon
			cout << "Total Bayar  	: Rp." << *tot - diskon << endl; //Menampilkan total harga yang harus dibayar
			cout << "Bayar        	: Rp.";
			cin >> bayar;														 // Input dari user untuk jumlah yang dibayar
			cout << "Kembali      	: Rp." << (bayar - (*tot - diskon)) << endl; // Menampilkan uang kembali
			cout << "-------------- TERIMA KASIH --------------" << endl;
		}
		else
		{
			cout << "=============== PEMBAYARAN ===============" << endl;
			cout << "Jenis Member 	: Ya" << endl;
			cout << "Nama Pelanggan	: " << nama << endl;
			cout << "Diskon        	: Rp.-" << endl;
			cout << "Total Bayar  	: Rp." << *tot << endl;
			cout << "Bayar          : Rp.";
			cin >> bayar;
			cout << "-------------- TERIMA KASIH --------------" << endl;
		}
	}
	else if (pilih == "TIDAK")
	{
		cout << "========== Hai Member Toko Zalza ==========" << endl;
		cout << "Nama: ";
		cin.ignore();
		getline(cin, nama);
		cout << "Masukan Jumlah Item : ";
		cin >> jum_item; //Pengguna memasukan jumlah beli
		for (int i = 0; i < jum_item; i++)
		{
			cout << "------------------------------------------" << endl;
			cout << "Masukan Barang Ke-" << i + 1 << endl;
			cout << "Jenis Pakaian : ";
			cin >> jenis_pakaian[i]; //Pengguna input jenis pakaian disimpan pada array nama_barang
			cout << "Jumlah      : ";
			cin >> jumlah[i]; //Pengguna input jumlah disimpan pada array jumlah
			cout << "Harga       : ";
			cin >> harga[i];				   //Pengguna input harga disimpan pada array harga
			sub_tot[i] = jumlah[i] * harga[i]; // Menjumlahkan Harga sub total barang
			*tot += sub_tot[i];				   //Menjumlahkan seluruh sub total barang
		}
		//Menampilkan Keterangan
		cout << "=============== PEMBAYARAN ===============" << endl;
		cout << "Jenis Member 	: Tidak" << endl;
		cout << "Nama Pelanggan	: " << nama << endl;
		cout << "Jumlah Bayar 	: Rp." << *tot << endl;			 //Menampilkan jumlah bayar (belum termasuk diskon)
		cout << "Diskon        	: Rp.-" << endl;				 //Menampilkan diskon
		cout << "Total Bayar  	: Rp." << *tot - diskon << endl; //Menampilkan total harga yang harus dibayar
		cout << "Bayar        	: Rp.";
		cin >> bayar;														 // Input dari user untuk jumlah yang dibayar
		cout << "Kembali      	: Rp." << (bayar - (*tot - diskon)) << endl; // Menampilkan uang kembal
		cout << "-------------- TERIMA KASIH --------------" << endl;
	}
	else
	{
		cout << "Data yang anda masukan salah" << endl;
	}
	goto menu;

	cin.get();

	return 0;
}
