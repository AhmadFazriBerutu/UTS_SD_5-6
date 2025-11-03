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

vector<int> arr_rotasi_kiri(int d, const vector<int> & arr_argha) {
    int n = arr_argha.size(); // Ukuran array (n)
    int k = d % n; // hitung rotasi (k = d MOD n)
    
    if (k == 0) { // jika k = 0 arraynya ga berubah
        return arr_argha;
    }

    vector<int> hasil; // array utk nyimpen hasil rotasi

    for (int i = k; i < n; i++) { // nyalin elemen arr_argha[k] sampe arr_argha[n-1]
        hasil.push_back(arr_argha[i]);
    }

    for (int i = 0; i < k; i++) { // nyalin elemen arr_argha[0] sampe arr_argha[k-1]
        hasil.push_back(arr_argha[i]);
    }

    return hasil;
}

int main() {
    system ("cls");

    vector<int> tc1_input = {1, 2, 3, 4, 5};
    int tc1_rotasi = 4;
    vector<int> tc1_hasil = arr_rotasi_kiri(tc1_rotasi, tc1_input);
    cout << "Test Case 1 (Rotasi : 4)" << endl;
    cout << "Masukkan n dan banyak rotasi : 5 4" << endl;
    cout << "Input: "; cetak_array(tc1_input);
    cout << "Hasil: "; cetak_array(tc1_hasil);
    cout << "\n\n";

    vector<int> tc2_input = {10, 20, 30, 40, 50, 60};
    int tc2_rotasi = 1;
    vector<int> tc2_hasil = arr_rotasi_kiri(tc2_rotasi, tc2_input);
    cout << "Test Case 2 (Rotasi : 1)" << endl;
    cout << "Masukkan n dan banyak rotasi : 6 1" << endl;
    cout << "Input: "; cetak_array(tc2_input);
    cout << "Hasil: "; cetak_array(tc2_hasil);
    cout << "\n\n";

    vector<int> tc3_input = {2, 4, 6, 8, 10};
    int tc3_rotasi = 7;
    vector<int> tc3_hasil = arr_rotasi_kiri(tc3_rotasi, tc3_input);
    cout << "Test Case 3 (Rotasi : 7)" << endl;
    cout << "Masukkan n dan banyak rotasi : 5 7" << endl;
    cout << "Input: "; cetak_array(tc3_input);
    cout << "Hasil: "; cetak_array(tc3_hasil);
    cout << "\n\n";

    vector<int> tc4_input = {5, -2, 0, 13, 9, -7, 4};
    int tc4_rotasi = 3;
    vector<int> tc4_hasil = arr_rotasi_kiri(tc4_rotasi, tc4_input);
    cout << "Test Case 4 (Rotasi : 3)" << endl;
    cout << "Masukkan n dan banyak rotasi : 7 3" << endl;
    cout << "Input: "; cetak_array(tc4_input);
    cout << "Hasil: "; cetak_array(tc4_hasil);
    cout << "\n\n";

    return 0;
}