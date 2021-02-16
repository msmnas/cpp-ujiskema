#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include <conio.h>
#include <sstream>
using namespace std;

void header()
{
    cout << "============================\n"
         << "\tPT. BANK ABC\n"
         << "============================\n";
}
int main()
{

    int saldo_awal = 10000, tarik, cek_saldo, pilih, blokir = 0, setor;
    string opsi, pin, nama, setorr, tarikk;
    nama = "Selamat datang , who dis ? \n";
pin:
    if (blokir == 3)
    {
        header();
        cout << "Kartu ATM anda terblokir, mohon hubungi pihak bank\n\n";
        system("pause");
        return 0;
    }
    else
    {
        header();
        cout << "PIN ? : ";
        for (int i = 0;;)
        {
            int c = getch();

            if (c == '\r')
            {
                break;
            }
            else if (c >= '0' && c <= '9' && i < 6)
            {
                pin.push_back(c);
                _putch('*');
                ++i;
            }
            else if (c == '\b' && i >= 1)
            {
                cout << "\b \b";
                pin.resize(pin.length() - 1);
                --i;
            }
        }
        if (pin.length() < 6)
        {
            cout << endl;
            cout << "Pin anda salah\n";
            Sleep(3000);
            system("cls");
            blokir += 1;
            pin = "";
            goto pin;
        }
        else
        {
            system("cls");
            goto menu;
        }
    }
menu:
    system("cls");
    header();
    cout << nama;
    cout << "Saldo : Rp." << saldo_awal << "\n";
    cout << "\nMenu Transaksi\n";
    cout << "1. Setor Tabungan\n";
    cout << "2. Ambil Tabungan\n";
    cout << "3. Cek Saldo\n";
    cout << "4. Exit\n";
    cout << "Pilihan menu (1/2/3) ? ";
    cin >> pilih;
    switch (pilih)
    {
    case 1:
        system("cls");
    setor:
        header();
        cout << "\nJumlah Setoran : ";
        for (int i = 0;;)
        {
            int c = getch();

            if (c == '\r')
            {
                break;
            }
            else if (c >= '0' && c <= '9' && i < 8)
            {
                setorr.push_back(c);
                _putch(c);
                ++i;
            }
            else if (c == '\b' && i >= 1)
            {
                cout << "\b \b";
                setorr.resize(setorr.length() - 1);
                --i;
            }
        }
        stringstream(setorr) >> setor;
        if (setor % 50000 == 0 || setor > 10000)
        {
            saldo_awal += setor;
            cout << "\nTransaksi Berhasil...\n";
            cout << "Saldo Saat ini : Rp." << saldo_awal << "\n";
            cout << "\n\nIngin Melakukan transaksi kembali ? ";
            cin >> opsi;
            if (opsi == "y" || opsi == "Y")
            {
                goto menu;
            }
            else
            {
                return 0;
            }
            goto menu;
        }

    case 2:
        system("cls");
    tarik:
        header();
        cout << "Saldo :" << saldo_awal;
        cout << "\nJumlah Penarikan : ";
        for (int i = 0;;)
        {
            int c = getch();

            if (c == '\r')
            {
                break;
            }
            else if (c >= '0' && c <= '9' && i < 8)
            {
                tarikk.push_back(c);
                _putch(c);
                ++i;
            }
            else if (c == '\b' && i >= 1)
            {
                cout << "\b \b";
                tarikk.resize(tarikk.length() - 1);
                --i;
            }
        }
        stringstream(tarikk) >> tarik;
        if (tarik % 50000 == 0)
        {
            if (tarik > saldo_awal)
            {
                cout << "\nNominal melebihi saldo anda\n";
                system("cls");
                tarikk = "";
                goto tarik;
            }
            else if (saldo_awal - tarik < 50000)
            {
                cout << "\nSisa saldo tidak boleh kurang dari Rp 50000\n";
                system("cls");
                tarikk = "";
                goto tarik;
            }
            else
            {
                saldo_awal -= tarik;
                cout << endl;
                cout << "Penarikan Berhasil...\n";
                cout << "Sisa saldo anda Rp " << saldo_awal << "\n";
                Sleep(2000);
                cout << "\n\nIngin Melakukan transaksi kembali ? ";
                cin >> opsi;
                if (opsi == "y" || opsi == "Y")
                {
                    goto menu;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            cout << "\nNominal harus dalam kelipatan Rp 50000\n";
            Sleep(2000);
            system("cls");
            tarikk = "";
            goto tarik;
        }

    case 3:
        system("cls");
    cek_saldo:
        header();
        cout << "Sisa Saldo : Rp." << saldo_awal;
        cout << "\n\nIngin Melakukan transaksi kembali ? ";
        cin >> opsi;
        if (opsi == "y" || opsi == "Y")
        {
            goto menu;
        }
        else
        {
            return 0;
        }
    }
}