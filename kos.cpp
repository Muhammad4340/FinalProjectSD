#include<iostream>
#include<stack>
#include<queue>
#include<list>
 
using namespace std;
 
struct Kamar {
   	int kode;
   	string jenis;
   	int biaya;
};
 
struct Antrian {
    int ekor;
    int nomor[100];
    string nama[100];
};
 
Kamar* cariKamar(Kamar* arr, int n, int kode) {
   	for (int i = 0; i < n; i++) {
	   if (arr[i].kode == kode) {
          	return &arr[i];
	   }
   	}
   	return NULL;
}
 
void sortKamar(Kamar* arr, int n) {
   	for (int i = 0; i < n - 1; i++) {
	   for (int j = i + 1; j < n; j++) {
          	if (arr[i].biaya > arr[j].biaya) {
              swap(arr[i], arr[j]);
          	}
	   }
   	}
}
 
void tampilKamar(Kamar* arr, int n) {
   	cout << "KODE Jenis Kamar Biaya Sewa/Hari" << endl;
   	for (int i = 0; i < n; i++) {
	   cout << arr[i].kode << ". " << arr[i].jenis << " Rp. " << arr[i].biaya << endl;
   	}
   	cout << "----" << endl;
}
 
bool full(Antrian q) {
   	return q.ekor >= 99;
}
 
bool empty(Antrian q) {
   	return q.ekor == -1;
}
 
int main(){
	
    int l_sewa;
    char yatidak;
 
   	Kamar kamar[3];
   	kamar[0].kode = 1;
    kamar[0].jenis = "Standard KM Dalam";
    kamar[0].biaya = 20000;
    kamar[1].kode = 2;
    kamar[1].jenis = "Standard KM Dalam Tempat Masak";
    kamar[1].biaya = 25000;
    kamar[2].kode = 3;
    kamar[2].jenis = "Paviliun";
    kamar[2].biaya = 27000;
 
   	stack<string> nama;
   	queue<string> nama2;
   	queue<int> kode;
   	list<int> lama;
   	queue<int> lama2;
 
   	Antrian q;
      q.ekor = -1;
      awal:
   	int pil;
 
   	do {
	   cout << "Antrian Layanan!" << endl;
	   cout << "Pilihan!" << endl;
	   cout << "1. Masuk Antrian" << endl;
       cout << "2. Keluar Antrian" << endl;
	   cout << "3. Lihat Jumlah Antrian" << endl;
	   cout << "4. Tutup Antrian" << endl;
	   cout << "Silahkan Pilih: ";
	   cin >> pil;
 
	   switch (pil) {
          	case 1:
              if (!full(q)) {
            	 	q.ekor++;
            	 	q.nomor[q.ekor] = q.ekor + 1;
            	 	cout << "Masukkan Nama: ";
            	 	cin >> q.nama[q.ekor];
              } else {
            	 	cout << "Data penuh" << endl;
              }
              break;
          	case 2:
              if (!empty(q)) {
            	 	cout << "Panggilan Nomor: " << q.nomor[0] << endl;
            	 	cout << "Atas nama: " << q.nama[0] << endl;
            	 	for (int i = 1; i <= q.ekor; i++) {
                	 q.nama[i - 1] = q.nama[i];
                	 q.nomor[i - 1] = q.nomor[i];
            	 	}
            	 	q.ekor--;
              } else {
            	 	cout << "Data kosong" << endl;
              }
              break;
    	  	case 3:
              cout << "Jumlah Antrian: " << q.ekor + 1 << endl;
              break;
          	case 4:
              goto sudah_selesai;
	   }
   	} while (pil != 4);
 
   	sudah_selesai:
 
   	sortKamar(kamar, 3);
   	tampilKamar(kamar, 3);
 
   	string nama_penyewa;
   	cout << "Nama: "; cin >> nama_penyewa;
   	cout << "Kode Kamar (1/2/3): "; cin >> pil;
   	cout << "Lama Sewa : "; cin >> l_sewa;
   	
   	nama.push(nama_penyewa);
   	kode.push(pil);
   	lama.push_back(l_sewa);
   	
   	nama2.push(nama_penyewa);
   	lama2.push(l_sewa);
   	
   	system("cls");
   	
   	Kamar* kamar_pilih = cariKamar(kamar, 3, pil);
   	if (kamar_pilih != NULL) {
   		int sub_tot, tot, promo_diskon, bay, balik, biaya_sewa;
   		biaya_sewa = kamar_pilih->biaya;
   		sub_tot = l_sewa * biaya_sewa;
   		if (l_sewa >= 90) (promo_diskon = sub_tot * 0.3);
   		else (promo_diskon = sub_tot * 0);
   		tot = sub_tot - promo_diskon;
   		cout << "Nama Penyewa:" << nama_penyewa << endl;
   		cout << "Kode Kamar (1/2/3) :" << pil << endl;
   		cout << "Jenis Kamar : " << kamar_pilih->jenis << endl;
   		cout << "Biaya Sewa/Hari :" << biaya_sewa << endl;
   		cout << "Lama sewa atau peminjaman :" << l_sewa << "hari" << endl;
   		cout << "Sub Total :Rp " << sub_tot << ",-" << endl;
   		cout << "promo_diskon:Rp " << promo_diskon << ",-" << endl;
   		cout << "Total Pembayaran:Rp " << tot << ",-" << endl;
   		cout << "---"; cout << endl;
   		cout << "Uang yang dibayarkan = Rp. "; cin >> bay;
   		balik = bay - tot;
   		cout << "Uang yang dikembalikan = Rp. " << balik << ",-" << endl;
   	}
   	else {
   		cout << "Pemesanan tidak bisa diproses" << endl;
   		cout << endl;
   	}
   	cout << endl;
   	cout << "Apakah kamu ingin mencoba kembali? [Y/T]: ";
   	cin >> yatidak;
   	cout << endl;
   	
   	if(yatidak == 'Y' || yatidak == 'y') {goto awal;}
   	if(yatidak == 'T' || yatidak == 't') {goto selesai;}
   	
   	selesai:
   	
   	cout << "Data Penyewa:" << endl;
   	cout << "Nama\tKode Kamar\tLama Sewa" << endl;
   	while (!nama.empty() && !kode.empty() && !lama.empty()) {
   		cout << nama.top() << "\t" << kode.front() << "\t\t" << lama.front() << endl;
   		nama.pop();
   		kode.pop();
   		lama.pop_front();
   	}
   	
   	char hapus;
   	cout << "Apakah kamu ingin menghapus data penyewa? [Y/T]: ";
   	cin >> hapus;
   	cout << endl;
   	if (hapus == 'Y' || hapus == 'y') {
   		cout << "Data penyewa yang dihapus adalah: " << endl;
   		cout << "Nama\tKode Kamar\tLama Sewa" << endl;
   		cout << nama2.front() << "\t" << kode.front() << "\t\t" << lama2.front() << endl;
   		nama2.pop();
   		kode.pop();
   		lama2.pop();
   		cin.ignore ();
   		cout << "Tekan ENTER untuk melanjutkan...";
   		getchar ();
   	}
}

