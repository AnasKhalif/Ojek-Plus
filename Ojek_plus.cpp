#include <iostream>
#include <array>
using namespace std;

void cekFoto(int id);
void pemesananPelanggan(int id, double jarak);
void tampilanPelanggan();
void menarikPelanggan(int id);
void tampilanDriver();

int main(){

    int user;
    bool cariUser = false;

    cout << "\n====== Selamat Datang di Applikasi OJEK PLUS ======" << endl;
    cout << "\n====== 1.Pelanggan ======" << endl;
    cout << "====== 2.Driver    ======" << endl;

    while(!cariUser){
        cout << "\nMasuk sebagai (1.pelanggan/2.driver): ";
        cin >> user;
        if(user == 1){
            tampilanPelanggan();
            break;
        }else if(user == 2){
            tampilanDriver();
            break;
        }else{
            cout << "\nMasukkan pilihan yang sesuai!!!" << endl;
        }
    }
    return 0;
}

void cekFoto(int id){
    int kataSandi;
    bool menemukan = false;
    array<double,3> katasandi = {123, 321, 134};
    id -= 1;

    for(int i = 0; i < katasandi.size() ; i++){
        if(id == i){
            while(!menemukan){
                cout  << "Masukkan kata sandi anda : ";
                cin >> kataSandi;
                if(kataSandi == katasandi[i]){
                    cout << "kata sandi anda benar" << endl; 
                    break;
                }else{
                    cout << "kata sandi anda Salah mohon ulangi" << endl;
                }
            }
        }
    }
}

void pemesananPelanggan(int id, double jarak){
    array<string,3> tanggal = {"Sabtu, 24 Desember 16:00", "Minggu, 25 Desember 17:00", "Senin 26 Desember 18:00"};
    array<string,3> nama    = {"Bibi","Amy","Adi"};
    string titik_jemput[]   = {"Kepanjen", "Kediri", "Nganjuk"};
    string titik_antar[]    = {"Malang", "Surabaya", "Malang"};
    int golongan_motor[]    = {1,3,2};
    int biaya[]             = {4000, 5000, 6000};
    int tarif               = 0;
    int biayaAman           = 2000;
    int jarakBaru;
    string lokasiBaru;
    char tanya;
    id -= 1;

    for(int i = 0; i < tanggal.size() ; i++){
        if(id == i){
            cout << "\n====== RINCIAN PESANAN ANDA ======" << endl;
            cout << "Nama Pelanggan     : " << nama[i] << endl;
            cout << "Tanggal            : " << tanggal[i] << endl;
            cout << "Lokasi Jemput      : " << titik_jemput[i] << endl;
            cout << "Lokasi Tujuan      : " << titik_antar[i] << endl;
            cout << "Golongan motor     : " << golongan_motor[i] << endl;
            cout << "Apakah anda ingin mengganti lokasi titik antar ? (y/t) :";
            cin >> tanya;
            switch (tanya)
            {
            case 'y':
                cout << "Masukkan jarak tempuh anda :";
                cin >> jarakBaru;
                cout << "Masukkan lokasi titik antar baru : ";
                cin >> lokasiBaru;
                jarak = jarakBaru;
                titik_antar[i] = lokasiBaru;

                cout << "\n====== RINCIAN PESANAN ANDA ======" << endl;
                cout << "Nama Pelanggan     : " << nama[i] << endl;
                cout << "Tanggal            : " << tanggal[i] << endl;
                cout << "Lokasi Jemput      : " << titik_jemput[i] << endl;
                cout << "Lokasi Tujuan      : " << lokasiBaru << endl;
                cout << "Golongan motor     : " << golongan_motor[i] << endl;

                for(int a = 0; a < 3; a++){
                    if(golongan_motor[i] == a+1){
                        tarif = jarakBaru * biaya[a];
                    }
                }
                cout << "\n====== RINCIAN PEMBAYARAN ANDA ======" << endl;
                cout << "Tarif anda         : " << tarif << endl;
                cout << "Biaya Aman         : " << biayaAman << endl;
                cout << "Total biaya anda   : " << tarif + biayaAman  << endl;
                break;
            
            case 't':
                for(int a = 0; a < 3; a++){
                    if(golongan_motor[i] == a+1){
                        tarif = jarak * biaya[a];
                    }
                }
                cout << "\n====== RINCIAN PEMBAYARAN ANDA ======" << endl;
                cout << "Tarif anda         : " << tarif << endl;
                cout << "Biaya Aman         : " << biayaAman << endl;
                cout << "Total biaya anda   : " << tarif + biayaAman  << endl;
            break;
            }
        }
    }


}

void tampilanPelanggan(){
    int pilihan, id;
    double jarak;
    bool menemukan = false;
    cout << "\n====== 1. Mencari ojek ======" << endl;
    cout << "====== 2. Keluar ============" << endl;

    while(!menemukan){
    cout << "\nMasukkan pilihan anda (1.Mencari ojek/2.Keluar) : ";
    cin >> pilihan;

        if(pilihan == 1){
            cout << "Masukkan id Akun : ";
            cin >> id;
            if(id > 0 && id < 4){
                cout << "Masukkan jarak tempuh anda : ";
                cin >> jarak;
                pemesananPelanggan(id,jarak);
                break;
            }else{
                cout << "id anda tidak terdaftar";
            }
        }else if(pilihan == 2){
            cout << "keluar";
            break;
        }else{
            cout << "\nMasukkan pilihan yang benar!! (1.Mencari ojek/2.Keluar) : " << endl;
        }
    }
}

void tampilanDriver(){
    int pilihan, id;
    string nama;
    bool menemukan = false;
    cout << "\n====== 1.Menarik pelanggan ======" << endl;
    cout << "====== 2.Keluar    ==============" << endl;

    while(!menemukan){

    cout << "\nMasukkan pilihan anda (1.Menarik pelanggan/2.Keluar) : ";
    cin >> pilihan;

        if(pilihan == 1){
            cout << "Masukkan id Akun : ";
            cin >> id;
            if(id > 0 && id < 4){
                cekFoto(id);
                menarikPelanggan(id);
                break;
            }else{
                cout << "id anda tidak terdaftar";
            }
        }else if(pilihan == 2){
            cout << "keluar";
            break;
        }else{
            cout << "\nMasukkan pilihan yang benar!! (1.Menarik pelanggan/2.Keluar) : " << endl;
        }
    }
}

void menarikPelanggan(int id){
    array<string,3> penumpang = {"Bibi","Amy","Adi"};
    array<string,3> ojek      = {"Otong", "Ocit", "Tuyul"};
    string titik_jemput[]   = {"Kepanjen", "Kediri", "Nganjuk"};
    string titik_antar[]    = {"Malang", "Surabaya", "Malang"};
    int jarak[]          = {12,20,22};
    int golongan_motor[]    = {1,3,2};
    int biaya[]             = {4000, 5000, 6000};
    int tarif             = 0;
    bool sesuai = false;
    char tanya;
    id -= 1;

    for(int i = 0; i < penumpang.size() ; i++){
        if(id == i ){
            cout << "\n====== RINCIAN PENUMPANG ======" << endl;
            cout << "Nama Penumpang         : " << penumpang[i] << endl;
            cout << "Titik jemput penumpang : " << titik_jemput[i] << endl;
            cout << "Titik antar penumpang  : " << titik_antar[i] << endl;
            cout << "Jarak                  : " << jarak[i] << endl;

            for(int j = 0; j < 3; j++){
                if(golongan_motor[i] == j+1){
                tarif = jarak[i] * biaya[j];
            }
            }

            cout << "Tarif                  : " << tarif << endl;

            cout << "Apakah anda ingin menerima pelanggan " << penumpang[i] << " ? (y/t) :";

            cin >> tanya;

            switch (tanya)
            {
            case 'y':
                cekFoto(id+1);
                    cout << "\nProses Penjemputan penumpang " << penumpang[i] << endl;
                    cout << "\n====== IDENTITAS OJEK ======" << endl;
                    cout << "Golongan motor ojek : " << golongan_motor[i] << endl;
                    cout << "Nama Ojek           : " << ojek[i] << endl;
                    while(!sesuai){
                        cout << "\nApakah sudah sampai titik antar ? (y/t) :";
                        cin >> tanya;
                        if(tanya == 'y'){
                            cout << "Pengantaran Selesai " << endl;
                            break;
                        }else if(tanya == 't'){
                            cout << "Pengantaran belum selesai" << endl;
                        }
                    }
                break;
            
            case 't':
                cout << "Keluar";
                break;
            }
        }
    }
}