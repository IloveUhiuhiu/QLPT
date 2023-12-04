// DoanhThu.cpp
#include "DoanhThu.h"

// Constructors
DoanhThu::DoanhThu(int years,int months,int days,int thuNhap) : date(years,months,days), thuNhap(thuNhap)
{
    // Khởi tạo thông tin doanh thu mặc định
}

// Destructor
DoanhThu::~DoanhThu() {
    // Không có công việc đặc biệt cần thực hiện trong destructor ở đây
}

// Getter và Setter
// int DoanhThu::getNgay() const {
//     return ngay;
// }

// void DoanhThu::setNgay(int ngay) {
//     this->ngay = ngay;
// }

Datetime DoanhThu::get_date() const
{
    return this->date;

}
void DoanhThu::set_date(Datetime time)
{
    this->date = time;
}
// int DoanhThu::getThang() const {
//     return thang;
// }

// void DoanhThu::setThang(int thang) {
//     this->thang = thang;
// }

// int DoanhThu::getNam() const {
//     return nam;
// }

// void DoanhThu::setNam(int nam) {
//     this->nam = nam;
// }

int DoanhThu::getThuNhap() const {
    return thuNhap;
}

void DoanhThu::setThuNhap(int thuNhap) {
    this->thuNhap = thuNhap;
}
DoanhThu DoanhThu::Split(string str) // hàm tách chuổi
{
    Datetime date;
    int thuNhap;
    str += ',';
    int id = 1;
    int begin = 0, end = 0;
    for (auto x : str)
    {
        if (x == ',')
        {
            if (id == 1)
            {
                date = Datetime::Split(str.substr(begin, end - begin));
            }
            else 
            {
                thuNhap = Convert::str_to_int(str.substr(begin, end - begin));
            }
            ++id;
            begin = end + 1;
        }
        end++;
    }
    return DoanhThu(date.get_years(),date.get_months(),date.get_days(),thuNhap);
}

void DoanhThu::write_File(List<string> &L)
{
    ofstream inputFile;
    inputFile.open("doanhthu.txt", std::ios::out | std::ios::trunc);
    if (inputFile.is_open())
    {
        int size = L.getSize();
        if (size)
        {
            for (int i = 0; i < size; i++)
            {
                inputFile << L[i] << '\n';
            }
        }
    }
    else
    {
        cout << "Error Opening File doanhthu.txt" << endl;
    }
}
string DoanhThu::Union(DoanhThu &obj)
{
    string str =  Datetime::Union(obj.date) + "," + Convert::int_to_str(obj.thuNhap);
    return str;
}
// Phương thức thêm doanh thu
void DoanhThu::addDoanhThu() {
    // Thêm thông tin doanh thu mới
    string str = Union(*this);
    ofstream inputFile("doanhthu.txt", std::ios_base::app); // Mở tệp tin để ghi tiếp vào cuối tệp

    if (inputFile.is_open()) {
        inputFile << str << "\n"; // Ghi dòng mới vào tệp
        inputFile.close(); // Đóng tệp sau khi ghi
    } else {
        cout << "Can't Open File doanhthu.txt!!!\n";
    }
    
}


// viết hàm tongDoanhThutheonam
// Phương thức tính tổng doanh thu theo năm
// viết đa năng hóa toán tử <<
ostream& operator<< (ostream& o, const DoanhThu& obj) {
    cout << "Date: ";
    o << obj.date << endl;
    cout << "Revenue: ";
    o << obj.thuNhap << endl;
    return o;
}
// Phương thức hiển thị thông tin doanh thu
// void DoanhThu::display() const {
//     cout << "Ngay: " << ngay << "/" << thang << "/" << nam << endl;
//     cout << "Thu nhap: " << thuNhap << endl;
// }


int DoanhThu::tongDoanhThutheothoigian(int startYear, int startMonth, int startDay, int endYear, int endMonth, int endDay) {
    Datetime startDate(startYear, startMonth, startDay);
    Datetime endDate(endYear, endMonth, endDay);

    int res = 0;
    List<string> L;
    ifstream inputFile("doanhthu.txt");
    
    if (!inputFile.is_open()) {
        cout << "Error Opening File doanhthu.txt" << endl;
        return -1; // Trả về giá trị đặc biệt để chỉ ra rằng không có doanh thu
    }

    string str;
    while (getline(inputFile, str)) {
        L.push_back(str);
    }
    inputFile.close();

    int size = L.getSize();
    for (int i = 0; i < size; i++) {
        DoanhThu obj = Split(L[i]);
        if (obj.date >= startDate && obj.date <= endDate) {
            res += obj.thuNhap;
        }
    }

    return res;
}
