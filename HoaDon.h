#ifndef HoaDon_H
#define HoaDon_H
#include "ThoiGian.h"
#include "Phong.h"
#include "DoanhThu.h"
class HoaDon
{
private:
    string bill_id;
    string room_id;
    ThoiGian date;
    int total_cost;
    bool status;

public:
    HoaDon(string = "", string = "",ThoiGian = ThoiGian(0,0,0), int = 0, bool = false);
    ~HoaDon();
    string get_room_id() const;
    string get_bill_id() const;
    ThoiGian get_date() const;
    int get_total_cost() const;
    bool get_status() const;

    void set_room_id(string);
    void set_bill_id(string);
    void set_date(ThoiGian);
    void set_total_cost(int);
    void set_status(bool);

    friend istream &operator>>(istream &, HoaDon &);
    friend ostream &operator<<(ostream &, const HoaDon &);

    static void write_File(List<string> &);
    static HoaDon Split(string);
    static string Union(HoaDon &);
    void add_hoa_don();

    static void display(List<HoaDon>&, int = 0);

    static bool find_hoa_don(List<HoaDon>&);
    static bool find_room(string);
    static void find_bill_id(string,List<HoaDon>&);
    static HoaDon find_nearest_hoa_don(string);

    static void update_hoa_don(HoaDon&,int);
    static void Pay_bill(HoaDon&,int);
    static void delete_by_room(string );
};
#endif
