#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

const char* FILE_PATH = "data_f0.c19";
const string username = "TenSinhVien";
const string password = "24020000";

struct date {
    int day;
    int month;
    int year;

    date(string input) {
        
        stringstream ss(input);
        ss >> day;
        ss.ignore(1);
        ss >> month;
        ss.ignore(1);
        ss >> year;
    }

    string repr() {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }
};

date inputDate() {
    cout << "Nhap ngay thang nam (theo dinh dang dd/mm/yyyy hoac dd-mm-yyyy): ";
    string input;
    getline(cin, input);
    return date(input);
}

struct benhnhan {
    int id;
    string hoten;
    int namsinh;
    string diachi;
    date ngayxetnghiemf0;

    benhnhan(string record) {
        stringstream ss(record);
        ss >> id;
        ss.ignore(1);
        getline(ss, hoten, ',');
        ss >> namsinh;
        ss.ignore(1);
        getline(ss, diachi, ',');
        string ngayxetnghiemf0_str;
        getline(ss, ngayxetnghiemf0_str, ',');
        ngayxetnghiemf0 = date(ngayxetnghiemf0_str);
    }

    string export() {
        return to_string(id) + ',' + hoten + ',' + to_string(namsinh) + ',' + diachi + ',' + ngayxetnghiemf0.repr();
    }

};

struct storage {
    vector<benhnhan> data;
    int last_id = 0;
    
    void add(benhnhan bn) {
        bn.id = ++last_id;
        data.push_back(bn);
    }

    bool remove(int id) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i].id == id) {
                data.erase(data.begin() + i);
                return true;
            }
        }
        return false;
    }

    benhnhan* get(int id) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i].id == id) {
                return &data[i];
            }
        }
        return NULL;
    }

    vector<benhnhan> search(string hoten, int namsinh) {
        vector<benhnhan> result;
        for (int i = 0; i < data.size(); i++) {
            if (data[i].hoten == hoten && data[i].namsinh == namsinh) {
                result.push_back(data[i]);
            }
        }
        return result;
    }

    vector<benhnhan> export(int records) {

    }

    storage() {
        ifstream file(FILE_PATH);
        if (!file.is_open()) return;
        string line;
        while (getline(file, line)) {
            if (line == "") continue;
            benhnhan bn(line);
            data.push_back(bn);
            last_id = max(last_id, bn.id);
        }
        file.close();
    }

    void save() {
        ofstream file(FILE_PATH);
        for (int i = 0; i < data.size(); i++) {
            file << data[i].export() << endl;
        }
        file.close();
    }
};


int main() {
    // password challenge
    for (int i = 1; i < 6; i ++) {
        cout << "Nhap ho ten: ";
        string name;
        getline(cin, name);
        cout << "Nhap mat khau: ";
        string pass;
        getline(cin, pass);
        if (name == username && pass == password) {
            break;
        } else {
            cout << "Ban da nhap sai " << i << " lan. Moi ban dang nhap lai." << endl;
            if (i == 5) {
                cout << "Ban da nhap sai qua 5 lan. Vui long lien he ho tro 18001919." << endl;
                return 0;
            }
        }
    }
    cout << "Dang nhap thanh cong!" << endl;
    while (true) {
        cout << R"(
            1. Nhap thon tin
            2. Xuat thong tin
            3. Tim kiem thong tin
            4. Xoa thong tin
            5. Luu thong tin
            ========================
            0. Thoat

            Nhap lua chon: )";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 0:
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
    }
}