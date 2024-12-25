#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct sinhvien {
    string hoten;
    int mssv;
    double dcc, dgk, dck;

    sinhvien() {
        hoten = "";
        mssv = 0;
        dcc = dgk = dck = 0;
    }

    sinhvien(string hoten, int mssv, double dcc, double dgk, double dck) {
        this->hoten = hoten;
        this->mssv = mssv;
        this->dcc = dcc;
        this->dgk = dgk;
        this->dck = dck;
    }

    double tinhDTB() {
        return (dcc + dgk + dck) / 3;
    }
    
    void xuatDuLieu() {
        cout << hoten << ' ' << mssv << ' ' << fixed << setprecision(2) << tinhDTB() << endl;
    }
};

void nhapsinhvien(sinhvien& sv) {
    getline(cin, sv.hoten);
    cin >> sv.mssv >> sv.dcc >> sv.dgk >> sv.dck;
}