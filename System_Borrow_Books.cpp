#include <iostream>
#define MAX 5

using namespace std;

// Struct untuk  menyimpan input dari pengguna
struct StudentsData
{
    // Variable untuk memeriksa antrean
    int rear[MAX];
    int front[MAX];
    // Variable untuk menyimpan pilihan judul buku
    int InputBooksTitle[MAX];
    // Variable untuk menyimpan waktu peminjaman buku
    int InputTimeToBorrowBooks[MAX];
    // Variable untuk menyimpan nim mahasiswa
    int InputStudentsNumber[MAX];
    // Variable untuk menyimpan piihan mahasiswa
    int InputStudentOptions;
    // Variable untuk menyimpan nama mahasiswa
    string InputStudentsName[MAX];
    // Variable untuk menyimpan alamat mahasiswa
    string InputStudentsAdress[MAX];
} StudentsDataInput;

// Deklarasi  pointer
struct StudentsData *inputData = &StudentsDataInput;

// Array untuk menampilkan daftar judul - judul buku
string booksTitle[5] =
    {
        "Pemograman web",
        "Basis data",
        "Bahasa pemograman javascript",
        "Struktur data dan algorithma",
        "Membuat game dengan unreal engine"};

// Array untuk menyimpan pilihan meminjam atau mengembalikan buku
string userListOptions[2] = {" Meminjam buku ", " Mengembalikan buku "};

// Variable untuk melakukan pengulangan pada pilihan meminjam atau mengembalikan buku
int IndexOptions = 0;

// Function untuk menampilkan judul buku dan input data mahasiswa
void ShowBooksTitleOptions()
{
    // Variable untuk pengulangan
    int BooksTitleIndex = 1;
    cout << "" << endl;
    cout << " === Judul buku yang bisa dipinjam === " << endl;
    for (BooksTitleIndex; BooksTitleIndex < 5; BooksTitleIndex++)
    {
        cout << BooksTitleIndex << ". " << booksTitle[BooksTitleIndex] << endl;
    }
    cout << " ===================================== " << endl;
}

// Function untuk menampilkan pilihan meminjam atau mengembalikan buku
void ShowInputOptions()
{
    cout << "" << endl;
    cout << " === SELAMAT DATANG  DI PERPUSTAKAAN === " << endl;
    for (IndexOptions; IndexOptions < 2; IndexOptions++)
    {
        cout << IndexOptions << "." << userListOptions[IndexOptions] << endl;
    }
    // Masukkan pilihan
    cout << "" << endl;
    cout << " MASUKKAN PILIHAN : ";
    cin >> inputData->InputStudentOptions;

    // Jika input pilihan tidak kosong tampilkan semua judul buku
    // Dan jika pengguna memasukkan pilihan 0 atau 1 tampilkan semua judul buku
    if (inputData->InputStudentOptions == 0 || inputData->InputStudentOptions == 1)
    {
        ShowBooksTitleOptions();
    }
    // Ketika pengguna memasukkan pilihan selain 0 atau 1 harus menginputkan pilihan lagi
    else if (!inputData->InputStudentOptions == 0 || inputData->InputStudentOptions == 1)
    {
        // Masukkan pilihan
        cout << "" << endl;
        cout << " MASUKKAN PILIHAN DENGAN BENAR : ";
        cin >> inputData->InputStudentOptions;
        ShowBooksTitleOptions();
    }
}

// Function untuk pengguna melakukan input
void InputStudentsData()
{
    // Periksa apakah antrean terakhir kosong
    // Jika antrean terakhir kosong pengguna lain bisa melakukan peminjaman / pengembalian
    switch (inputData->rear[MAX])
    {
    case 0:
    InputDataFull:
        for (int indexValue = 0; indexValue < 5; indexValue++)
        {
            cout << "Masukkan nama : \n";
            cin >> inputData->InputStudentsName[indexValue];
            cout << "Masukkan nim : \n";
            cin >> inputData->InputStudentsNumber[indexValue];
            cout << "Masukkan alamat : \n";
            cin >> inputData->InputStudentsAdress[indexValue];
            cout << "Masukkan pilihan buku : \n";
            cin >> inputData->InputBooksTitle[indexValue];
            cout << "Masukkan waktu peminjaman buku : \n";
            cin >> inputData->InputTimeToBorrowBooks[indexValue];

            // Jika input data pengguna lengkap tampilkan data yang diinput dan berganti ke antrean selanjutnya
            if (inputData->InputStudentsName[indexValue] != "" && inputData->InputStudentsAdress[indexValue] != "")
            {
                if (inputData->InputBooksTitle[indexValue] > 0 && inputData->InputTimeToBorrowBooks[indexValue] > 0)
                {
                    cout << "" << endl;
                    cout << " ===== Terimakasih sudah berkunjung di perpustakaan ===== " << endl;
                    cout << "Nama mahasiswa : " << inputData->InputStudentsName[indexValue] << endl;
                    cout << "Nim mahasiswa : " << inputData->InputStudentsNumber[indexValue] << endl;
                    cout << "Alamat mahasiswa : " << inputData->InputStudentsAdress[indexValue] << endl;
                    cout << "Judul buku : " << booksTitle[inputData->InputBooksTitle[indexValue]] << endl;
                    cout << "Waktu peminjaman buku : " << inputData->InputTimeToBorrowBooks[indexValue] << " hari" << endl;
                    cout << "Keterangan : " << userListOptions[inputData->InputStudentOptions] << endl;
                    cout << "" << endl;

                    // Hapus antrean dari data paling depan
                    cout << "" << endl;
                    cout << " ===== Hapus antrean perpustakaan ===== " << endl;
                    cout << "Hapus  Nama mahasiswa : " << inputData->InputStudentsName[indexValue - indexValue] << endl;
                    cout << "Hapus Nim mahasiswa : " << inputData->InputStudentsNumber[indexValue - indexValue] << endl;
                    cout << "Hapus Alamat mahasiswa : " << inputData->InputStudentsAdress[indexValue - indexValue] << endl;
                    cout << "Hapus Judul buku : " << booksTitle[inputData->InputBooksTitle[indexValue - indexValue]] << endl;
                    cout << "Hapus Waktu peminjaman buku : " << inputData->InputTimeToBorrowBooks[indexValue - indexValue] << " hari" << endl;
                    cout << "Hapus keterangan : " << userListOptions[inputData->InputStudentOptions] << endl;
                    cout << "" << endl;
                }
            }
            // Jika sudah masuk antrean ke 2 tampilkan pilihan pinjam / kembalikan buku
            ShowInputOptions();

            // Jika input dan hapus selesai berganti ke antrean selanjutnya
            goto InputDataFull;
        }
        break;
    }
}

int main()
{
    // Jalankan function untuk menginputkan pilihan meminjam / megembalikan buku
    ShowInputOptions();
    // Jalankan function untuk menginputkan data nama,nim,alamat dll
    InputStudentsData();
    return 0;
}