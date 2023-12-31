
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

ThoiGian DoanhThu::get_date() const
{
    return this->date;

}
void DoanhThu::set_date(ThoiGian time)
{
    this->date = time;
}


int DoanhThu::getThuNhap() const {
    return thuNhap;
}

void DoanhThu::setThuNhap(int thuNhap) {
    this->thuNhap = thuNhap;
}
DoanhThu DoanhThu::Split(string str) // hàm tách chuổi
{
    ThoiGian date;
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
                date = ThoiGian::Split(str.substr(begin, end - begin));
            }
            else 
            {
                thuNhap = ChuyenDoi::str_to_int(str.substr(begin, end - begin));
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
    inputFile.open("DoanhThu.txt", std::ios::out | std::ios::trunc);
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
        cout << "Error Opening File DoanhThu.txt" << endl;
    }
}
string DoanhThu::Union(DoanhThu &obj)
{
    string str =  ThoiGian::Union(obj.date) + "," + ChuyenDoi::int_to_str(obj.thuNhap);
    return str;
}
// Phương thức thêm doanh thu
void DoanhThu::addDoanhThu() {
    // Thêm thông tin doanh thu mới
    string str = Union(*this);
    ofstream inputFile("DoanhThu.txt", std::ios_base::app); // Mở tệp tin để ghi tiếp vào cuối tệp

    if (inputFile.is_open()) {
        inputFile << str << "\n"; // Ghi dòng mới vào tệp
        inputFile.close(); // Đóng tệp sau khi ghi
    } else {
        cout << "Can't Open File DoanhThu.txt!!!\n";
    }
    
}

int DoanhThu::tongDoanhThutheothoigian(int startYear, int startMonth, int startDay, int endYear, int endMonth, int endDay) {
    ThoiGian startDate(startYear, startMonth, startDay);
    ThoiGian endDate(endYear, endMonth, endDay);

    int res = 0;
    List<string> L;
    ifstream inputFile("DoanhThu.txt");
    
    if (!inputFile.is_open()) {
        cout << "Error Opening File DoanhThu.txt" << endl;
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
// viết đa năng hóa toán tử <<
ostream& operator<< (ostream& o, const DoanhThu& obj) {
    cout << "Date: ";
    o << obj.date << endl;
    cout << "Revenue: ";
    o << obj.thuNhap << endl;
    return o;
}
