// DoanhThu.h
#ifndef DOANHTHU_H
#define DOANHTHU_H
#include "Datetime.h"

class DoanhThu {
public:
    // Constructors
    DoanhThu(int years = 0, int months = 0, int days = 0, int thuNhap = 0);  // Constructor với thông tin khởi tạo

    // Destructor
    ~DoanhThu();

    // Getter và Setter date
    Datetime get_date() const;
    void set_date(Datetime);
    

    int getThuNhap() const;
    void setThuNhap(int thuNhap);

    // Phương thức thêm doanh thu
    void addDoanhThu();

    void write_File(List<string> &);
    static DoanhThu Split(string);
    static string Union(DoanhThu &);

    friend ostream& operator<< (ostream&, const DoanhThu&);

    // Phương thức tính tổng doanh thu
<<<<<<< HEAD
        static int tongDoanhThutheothoigian(int startYear,int startMonth, int startDay, int endYear, int endMonth,int endDay);
=======
    static int tongDoanhThutheothoigian(int= 0, int= 0, int = 0, int = 0, int = 0, int = 0);

>>>>>>> 827293509722f40bf4c92222d84c6a5983d4e025
    // Phương thức hiển thị thông tin doanh thu
    // void display() const;

private:
    Datetime date;
    int thuNhap;
};

#endif // DOANHTHU_H