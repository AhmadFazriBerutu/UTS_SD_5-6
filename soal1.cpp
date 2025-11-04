
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi yg bantu cetak array
void cetak_array(const vector<int> & arr){
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << (i == arr.size() - 1? "" : " ");
    }
    cout << endl;
}

// Fungsi utama rotasi kiri
vector<int> arr_rotasi_kiri(int d, const vector<int> & arr_argha) {
    int n = arr_argha.size(); // Ukuran array (n)
    
    // Periksa jika array kosong
    if (n == 0) return {};
    
    int k = d % n; // hitung rotasi efektif (k = d MOD n)
    
    if (k == 0) { // jika k = 0 arraynya ga berubah
        return arr_argha;
    }

    vector<int> hasil; // array utk nyimpen hasil rotasi

    // Bagian 1: nyalin elemen dari indeks k sampai akhir
    for (int i = k; i < n; i++) { 
        hasil.push_back(arr_argha[i]);
    }

    // Bagian 2: nyalin elemen dari indeks 0 sampai k-1
    for (int i = 0; i < k; i++) { 
        hasil.push_back(arr_argha[i]);
    }

    return hasil;
}

int main() {
    system ("cls");
    int n, d;

    // Input Jumlah Elemen (n) dan Rotasi (d)
    cout << "Masukkan n (jumlah elemen) dan d (banyak rotasi): ";
    if (!(cin >> n >> d)) {
        cerr << "Input tidak valid." << endl;
        return 1;
    }

    if (n <= 0) {
        cerr << "Jumlah elemen (n) harus positif." << endl;
        return 1;
    }

    vector<int> input_arr(n);

    // Input Elemen Array
    cout << "Masukkan " << n << " elemen bilangan bulat (dipisahkan spasi):" << endl;
    for (int i = 0; i < n; i++) {
        if (!(cin >> input_arr[i])) {
            cerr << "Input elemen array tidak valid." << endl;
            return 1;
        }
    }

    // Proses Rotasi
    vector<int> hasil_rotasi = arr_rotasi_kiri(d, input_arr);

    // Output Hasil
    cout << "\n----------------------------------------" << endl;
    cout << "Array Asal: ";
    cetak_array(input_arr);
    
    cout << "Rotasi Kiri Sebanyak: " << d << " kali" << endl;
    
    cout << "Array Hasil Rotasi: ";
    cetak_array(hasil_rotasi);
    cout << "----------------------------------------\n" << endl;

    return 0;
}