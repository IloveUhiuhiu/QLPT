#include "QuanLy.h"
#include "NguoiThue.h"
#include "DoanhThu.h"
#include "SuCo.h"
char ch = ' ';
int sz, page, p;
void ThanhNgang(int x, int y, int dodai, int maunen, int mauchu, int makitu)
{
    setColor(maunen, mauchu);
    for (int i = x; i < x + dodai; i++)
    {
        gotoXY(i, y);
        cout << char(makitu);
    }
}
void ThanhTru(int x, int y, int dodai, int maunen, int mauchu, int makitu)
{
    setColor(maunen, mauchu);
    for (int j = y; j < y + dodai; j++)
    {
        gotoXY(x, min(j, 40));
        cout << char(makitu) << char(makitu);
    }
}
void khungbang()
{
    int mau = 9;
    ThanhNgang(1, 1, 154, mau, 9, 177); // ngang tren
    ThanhNgang(1, 38, 154, mau, 9, 177);
    ThanhTru(1, 1, 38, mau, 9, 177);   // tru trái
    ThanhTru(154, 1, 38, mau, 9, 177); // trụ phải
    setColor(0, 14);
}
void khung(int a, int b, int c, int d, const string content)
{
    int mau = 9;
    ThanhNgang(2, 1, 154, mau, 9, 177); // ngang tren
    ThanhNgang(2, 8, 154, mau, 9, 177); // ngang giua
    ThanhNgang(2, 15, 40, mau, 9, 177);
    ThanhNgang(2, 22, 40, mau, 9, 177);
    ThanhNgang(2, 29, 40, mau, 9, 177);
    ThanhNgang(2, 36, 154, mau, 9, 177);
    ThanhTru(2, 1, 36, mau, 9, 177);   // tru trái
    ThanhTru(154, 1, 36, mau, 9, 177); // trụ phải
    ThanhTru(40, 8, 29, mau, 9, 177);  // tru giưa
    setColor(0, 14);
    gotoXY(4, 11);
    cout << " Number Of Rooms: " << Phong::NumOfRoom();
    gotoXY(4, 18);
    cout << " Number Of Customers: " << NguoiThue::NumOfCustomer();
    gotoXY(4, 25);
    cout << " Number Of Empty Rooms: " << Phong::NumOfEmptyRoom();
    gotoXY(4, 32);
    cout << " Number Of Problem: " << SuCo::NumOfProblem();
    gotoXY(2 + (154 - content.size()) / 2, 4);
    cout << content;
}
void bia()
{
    ThanhNgang(2, 15, 154, 9, 10, 177); // ngang tren
    ThanhNgang(2, 27, 154, 9, 10, 177); // ngang duoi
    setColor(0, 10);
    gotoXY(67, 17);
    cout << "PBL2-DU AN LAP TRINH";
    gotoXY(60, 18);
    cout << "XAY DUNG UNG DUNG QUAN LI PHONG TRO";
    gotoXY(25, 21);
    cout << "*GVHD: Dang Hoai Phuong";
    gotoXY(110, 21);
    cout << "*SV: Dang Phuc Long(22T_DT4)";
    gotoXY(114, 22);
    cout << " Nguyen Thanh Nam(22T_DT3)";
    gotoXY(114, 23);
    cout << " Thai Viet Quoc Hung(22T_DT4)";
    setColor(0, 14);
}
void box(int x, int y, List<int> &w, int n, int m, List<string> &content)
{
    n++;
    int W = x;
    int xx = x, yy = y;
    int H = y + (n - 1) * 2;
    for (int i = 1; i <= m; i++)
        W += w[i];
    for (int iy = 1; iy <= n; iy++)
    {
        gotoXY(xx, yy);
        for (int ix = x; ix <= W; ix++)
            cout << char(196);
        yy += 2;
    }
    xx = x;
    for (int ix = 0; ix <= m; ix++)
    {
        xx += w[ix];
        for (int iy = y; iy <= H; iy++)
        {
            gotoXY(xx, iy);
            cout << char(179);
        }
    }
    xx = x;
    for (int i = 1; i < m; i++)
    {
        xx += w[i];
        gotoXY(xx, y);
        cout << char(194);
        gotoXY(xx, H);
        cout << char(193);
    }
    gotoXY(x, y);
    cout << char(218);
    gotoXY(W, y);
    cout << char(191);
    gotoXY(x, H);
    cout << char(192);
    gotoXY(W, H);
    cout << char(217);
    int xm, ym;

    for (int i = 0; i < n - 1; i++)
    {
        xx = x;
        yy = y + i * 2;
        for (int j = 0; j < m; j++)
        {
            xx += w[j];
            ym = (2 * yy + 2) / 2;
            xm = (2 * xx + w[j + 1] - content[i * m + j].size()) / 2;
            gotoXY(xm, ym);
            cout << content[i * m + j];
        }
    }
}
void box_count(int x, int y, int cnt)
{
    List<int> w;
    List<string> L;
    w.push_back(20);
    string s = "";
    while (cnt)
    {
        s += (cnt % 10);
        cnt /= 10;
    }
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        swap(s[l++], s[r--]);
    }
    if (s.size() == 0)
        s = "0";
    s = "Number Of Results: " + s;
    L.push_back(s);
    box(x, y, w, 1, 1, L);
}
void box_customer(int x, int y, List<NguoiThue> &L, int page_p = 0, int choose = 6)
{
    int n = L.getSize();
    List<int> w;
    List<string> content;
    w.push_back(0);
    content.push_back("CustomerID");
    w.push_back(12);
    content.push_back("RoomID");
    w.push_back(12);
    content.push_back("Name");
    w.push_back(22);
    content.push_back("DateofBirth");
    w.push_back(16);
    content.push_back("DateCheckIn");
    w.push_back(16);
    content.push_back("Gender");
    w.push_back(10);
    content.push_back("Email");
    w.push_back(23);
    content.push_back("Address");
    w.push_back(14);
    content.push_back("Phone");
    w.push_back(14);
    for (int i = page_p * choose; i < min(n, (page_p + 1) * choose); i++)
    {
        content.push_back(L[i].get_customer_id());
        content.push_back(L[i].get_room_id());
        content.push_back(L[i].get_customer_name());
        content.push_back(ThoiGian::Union(L[i].get_customer_dateofbirth()));
        content.push_back(ThoiGian::Union(L[i].get_check_in()));
        content.push_back(L[i].get_customer_gender());
        content.push_back(L[i].get_customer_email());
        content.push_back(L[i].get_customer_address());
        content.push_back(L[i].get_customer_phone());
    }
    box(x, y, w, min(choose + 1, n - choose * page_p + 1), 9, content);
}

void box_room(int x, int y, List<Phong> &L, int page_p = 0, int choose = 10)
{
    int n = L.getSize();
    List<int> w;
    List<string> content;
    w.push_back(0);
    content.push_back("RoomID");
    w.push_back(14);
    content.push_back("Type");
    w.push_back(14);
    content.push_back("Cost(VND)");
    w.push_back(14);
    content.push_back("Status");
    w.push_back(14);
    for (int i = page_p * choose; i < min(n, (page_p + 1) * choose); i++)
    {
        content.push_back(L[i].getRoomID());
        content.push_back(L[i].getKindOf());
        content.push_back(ChuyenDoi::int_to_str((L[i].getCost())));
        content.push_back((L[i].isOccupied() ? "Rent" : "Empty"));
    }
    box(x, y, w, min(choose + 1, n - choose * page_p + 1), 4, content);
}

void box_roomrent(int x, int y, List<Phong> &L, int page_p = 0, int choose = 10)
{
    int n = L.getSize();
    List<int> w;
    List<string> content;
    w.push_back(0);
    content.push_back("RoomID");
    w.push_back(14);
    content.push_back("Type");
    w.push_back(14);
    content.push_back("Cost(VND)");
    w.push_back(14);
    for (int i = page_p * choose; i < min(n, (page_p + 1) * choose); i++)
    {
        content.push_back(L[i].getRoomID());
        content.push_back(L[i].getKindOf());
        content.push_back(ChuyenDoi::int_to_str(L[i].getCost()));
    }
    box(x, y, w, min(choose + 1, n - choose * page_p + 1), 3, content);
}

void box_roomempty(int x, int y, List<Phong> &L, int page_p = 0, int choose = 10)
{
    int n = L.getSize();
    List<int> w;
    List<string> content;
    w.push_back(0);
    content.push_back("RoomID");
    w.push_back(14);
    content.push_back("Type");
    w.push_back(14);
    content.push_back("Cost(VND)");
    w.push_back(14);
    for (int i = page_p * choose; i < min(n, (page_p + 1) * choose); i++)
    {
        content.push_back(L[i].getRoomID());
        content.push_back(L[i].getKindOf());
        content.push_back(ChuyenDoi::int_to_str(L[i].getCost()));
    }
    box(x, y, w, min(choose + 1, n - choose * page_p + 1), 3, content);
}
void box_diennuoc(int x, int y, List<DienNuoc> &L, int page_p = 0, int choose = 10, int ok = 0)
{
    int n = L.getSize();
    List<int> w;
    List<string> content;
    w.push_back(0);
    content.push_back("DienNuocID");
    w.push_back(13);
    content.push_back("RoomID");
    w.push_back(10);
    content.push_back("NumElectricBefore");
    w.push_back(19);
    content.push_back("NumElectricAfter");
    w.push_back(19);
    content.push_back("NumWaterBefore");
    w.push_back(17);
    content.push_back("NumWaterAfter");
    w.push_back(17);
    content.push_back("CostElectric");
    w.push_back(14);
    content.push_back("CostWater");
    w.push_back(14);
    content.push_back("PaymentDate");
    w.push_back(14);
    content.push_back("Status");
    w.push_back(10);
    for (int i = page_p * choose; i < min(n, (page_p + 1) * choose); i++)
    {
        content.push_back(L[i].get_dien_nuoc_id());
        content.push_back(L[i].get_room_id());
        content.push_back(ChuyenDoi::int_to_str(L[i].get_num_electric_before()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_num_electric_after()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_num_water_before()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_num_water_after()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_cost_electric()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_cost_water()));
        content.push_back(ThoiGian::Union(L[i].get_date()));
        content.push_back(ChuyenDoi::bool_to_str(L[i].get_status()));
        if (ok == 1)
        {
            if (L[i].get_num_electric_after() != 0 || L[i].get_num_water_after() != 0)
            {
                gotoXY(6, 12);
                cout << "Bill Electric: " << ChuyenDoi::int_to_str((L[i].get_num_electric_after() - L[i].get_num_electric_before()) * L[i].get_cost_electric()) << "VND" << endl;
                gotoXY(6, 13);
                cout << "Bill Water: " << ChuyenDoi::int_to_str((L[i].get_num_water_after() - L[i].get_num_water_before()) * L[i].get_cost_water()) << "VND";
                gotoXY(6, 14);
                cout << "Total: " << ChuyenDoi::int_to_str(((L[i].get_num_electric_after() - L[i].get_num_electric_before()) * L[i].get_cost_electric()) + ((L[i].get_num_water_after() - L[i].get_num_water_before()) * L[i].get_cost_water())) << "VND";
            }
            else if (L[i].get_num_electric_after() == 0 && L[i].get_num_water_after() == 0)
            {
                gotoXY(6, 12);
                cout << "Bill Electric: 0VND" << endl;
                gotoXY(6, 13);
                cout << "Bill Water: 0VND";
                gotoXY(6, 14);
                cout << "Total: 0VND";
            }
        }
    }
    box(x, y, w, min(choose + 1, n - choose * page_p + 1), 10, content);
}
void box_diennuocpay(int x, int y, List<DienNuoc> &L, int page_p = 0, int choose = 10)
{
    int n = L.getSize();
    List<int> w;
    List<string> content;
    w.push_back(0);
    content.push_back("DienNuocID");
    w.push_back(13);
    content.push_back("RoomID");
    w.push_back(10);
    content.push_back("NumElectricBefore");
    w.push_back(19);
    content.push_back("NumElectricAfter");
    w.push_back(19);
    content.push_back("NumWaterBefore");
    w.push_back(16);
    content.push_back("NumWaterAfter");
    w.push_back(16);
    content.push_back("CostElectric");
    w.push_back(14);
    content.push_back("CostWater");
    w.push_back(14);
    content.push_back("PaymentDate");
    w.push_back(14);
    for (int i = page_p * choose; i < min(n, (page_p + 1) * choose); i++)
    {
        content.push_back(L[i].get_dien_nuoc_id());
        content.push_back(L[i].get_room_id());
        content.push_back(ChuyenDoi::int_to_str(L[i].get_num_electric_before()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_num_electric_after()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_num_water_before()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_num_water_after()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_cost_electric()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_cost_water()));
        content.push_back(ThoiGian::Union(L[i].get_date()));
    }
    box(x, y, w, min(choose + 1, n - choose * page_p + 1), 9, content);
}
void box_diennuocunpay(int x, int y, List<DienNuoc> &L, int page_p = 0, int choose = 10)
{
    int n = L.getSize();
    List<int> w;
    List<string> content;
    w.push_back(0);
    content.push_back("DienNuocID");
    w.push_back(13);
    content.push_back("RoomID");
    w.push_back(10);
    content.push_back("NumElectricBefore");
    w.push_back(19);
    content.push_back("NumElectricAfter");
    w.push_back(19);
    content.push_back("NumWaterBefore");
    w.push_back(16);
    content.push_back("NumWaterAfter");
    w.push_back(16);
    content.push_back("CostElectric");
    w.push_back(14);
    content.push_back("CostWater");
    w.push_back(14);
    content.push_back("PaymentDate");
    w.push_back(14);
    for (int i = page_p * choose; i < min(n, (page_p + 1) * choose); i++)
    {
        content.push_back(L[i].get_dien_nuoc_id());
        content.push_back(L[i].get_room_id());
        content.push_back(ChuyenDoi::int_to_str(L[i].get_num_electric_before()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_num_electric_after()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_num_water_before()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_num_water_after()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_cost_electric()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_cost_water()));
        content.push_back(ThoiGian::Union(L[i].get_date()));
    }
    box(x, y, w, min(choose + 1, n - choose * page_p + 1), 9, content);
}
void box_hoadon(int x, int y, List<HoaDon> &L, int page_p = 0, int choose = 10)
{
    int n = L.getSize();
    List<int> w;
    List<string> content;
    w.push_back(0);
    content.push_back("BiLLID");
    w.push_back(14);
    content.push_back("RoomID");
    w.push_back(14);
    content.push_back("Date");
    w.push_back(14);
    content.push_back("TotalCost(VND)");
    w.push_back(16);
    content.push_back("Status");
    w.push_back(14);
    for (int i = page_p * choose; i < min(n, (page_p + 1) * choose); i++)
    {
        content.push_back(L[i].get_bill_id());
        content.push_back(L[i].get_room_id());
        content.push_back(ThoiGian::Union(L[i].get_date()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_total_cost()));
        content.push_back(ChuyenDoi::bool_to_str(L[i].get_status()));
    }
    box(x, y, w, min(choose + 1, n - choose * page_p + 1), 5, content);
}
void box_hoadonpay(int x, int y, List<HoaDon> &L, int page_p = 0, int choose = 10)
{
    int n = L.getSize();
    List<int> w;
    List<string> content;
    w.push_back(0);
    content.push_back("BiLLID");
    w.push_back(14);
    content.push_back("RoomID");
    w.push_back(14);
    content.push_back("Date");
    w.push_back(14);
    content.push_back("TotalCost(VND)");
    w.push_back(16);
    for (int i = page_p * choose; i < min(n, (page_p + 1) * choose); i++)
    {
        content.push_back(L[i].get_bill_id());
        content.push_back(L[i].get_room_id());
        content.push_back(ThoiGian::Union(L[i].get_date()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_total_cost()));
    }
    box(x, y, w, min(choose + 1, n - choose * page_p + 1), 4, content);
}
void box_hoadonunpay(int x, int y, List<HoaDon> &L, int page_p = 0, int choose = 10)
{
    int n = L.getSize();
    List<int> w;
    List<string> content;
    w.push_back(0);
    content.push_back("BiLLID");
    w.push_back(14);
    content.push_back("RoomID");
    w.push_back(14);
    content.push_back("Date");
    w.push_back(14);
    content.push_back("TotalCost(VND)");
    w.push_back(16);
    for (int i = page_p * choose; i < min(n, (page_p + 1) * choose); i++)
    {
        content.push_back(L[i].get_bill_id());
        content.push_back(L[i].get_room_id());
        content.push_back(ThoiGian::Union(L[i].get_date()));
        content.push_back(ChuyenDoi::int_to_str(L[i].get_total_cost()));
    }
    box(x, y, w, min(choose + 1, n - choose * page_p + 1), 4, content);
}

void box_problem(int x, int y, List<SuCo> &L, int page_p = 0, int choose = 10)
{
    int n = L.getSize();
    List<int> w;
    List<string> content;
    w.push_back(0);
    content.push_back("ProblemID");
    w.push_back(14);
    content.push_back("RoomID");
    w.push_back(14);
    content.push_back("Registed Date");
    w.push_back(15);
    content.push_back("Finish Date");
    w.push_back(15);
    content.push_back("Content");
    w.push_back(30);
    content.push_back("Status");
    w.push_back(10);
    for (int i = page_p * choose; i < min(n, (page_p + 1) * choose); i++)
    {
        content.push_back(L[i].get_problem_id());
        content.push_back(L[i].get_room_id());
        content.push_back(ThoiGian::Union(L[i].get_registeddate()));
        content.push_back(ThoiGian::Union(L[i].get_finishdate()));
        content.push_back(L[i].get_content());
        content.push_back(ChuyenDoi::bool_to_str(L[i].get_status()));
    }
    box(x, y, w, min(choose + 1, n - choose * page_p + 1), 6, content);
}
void box_solvedproblem(int x, int y, List<SuCo> &L, int page_p = 0, int choose = 10)
{
    int n = L.getSize();
    List<int> w;
    List<string> content;
    w.push_back(0);
    content.push_back("ProblemID");
    w.push_back(14);
    content.push_back("RoomID");
    w.push_back(14);
    content.push_back("Registed Date");
    w.push_back(15);
    content.push_back("Finish Date");
    w.push_back(15);
    content.push_back("Content");
    w.push_back(30);
    for (int i = page_p * choose; i < min(n, (page_p + 1) * choose); i++)
    {
        content.push_back(L[i].get_problem_id());
        content.push_back(L[i].get_room_id());
        content.push_back(ThoiGian::Union(L[i].get_registeddate()));
        content.push_back(ThoiGian::Union(L[i].get_finishdate()));
        content.push_back(L[i].get_content());
    }
    box(x, y, w, min(choose + 1, n - choose * page_p + 1), 5, content);
}
void box_unsolvedproblem(int x, int y, List<SuCo> &L, int page_p = 0, int choose = 10)
{
    int n = L.getSize();
    List<int> w;
    List<string> content;
    w.push_back(0);
    content.push_back("ProblemID");
    w.push_back(14);
    content.push_back("RoomID");
    w.push_back(14);
    content.push_back("Registed Date");
    w.push_back(15);
    content.push_back("Finish Date");
    w.push_back(15);
    content.push_back("Content");
    w.push_back(30);
    for (int i = page_p * choose; i < min(n, (page_p + 1) * choose); i++)
    {
        content.push_back(L[i].get_problem_id());
        content.push_back(L[i].get_room_id());
        content.push_back(ThoiGian::Union(L[i].get_registeddate()));
        content.push_back(ThoiGian::Union(L[i].get_finishdate()));
        content.push_back(L[i].get_content());
    }
    box(x, y, w, min(choose + 1, n - choose * page_p + 1), 5, content);
}
void hide_password_input(string &password)
{
    char ch;
    int status = 0;
    int next_job = 0;
    int i = 0;
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            break;
        }
        else if (ch == 8)
        {
            if (i > 0)
            {
                i--;
                cout << "\b \b";
                password.pop_back();
            }
        }
        if (ch >= 32 && ch <= 126)
        {
            password += ch;
            i++;
            cout << "*";
        }
    }
}
void warn()
{
    cout << "Chua Co Gi" << endl;
}

void menu_user(NguoiThue &object2)
{
    int choice;
    Phong room;
    DienNuoc dn;
    HoaDon hd;
    SuCo sc;
    List<NguoiThue> L;
    List<Phong> L1;
    List<DienNuoc> L2;
    List<HoaDon> L3;
    do
    {
        system("cls");
        string content = "**** Wellcome Customer " + object2.get_user_name();
        content = content + " ***";
        khung(0, 0, 0, 0, content);
        gotoXY(42, 10);
        cout << "\t\t\t*****************************************************************" << endl;
        gotoXY(42, 11);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 12);
        cout << "\t\t\t*\t  1) View Information Customer                          *" << endl;
        gotoXY(42, 13);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 14);
        cout << "\t\t\t*\t  2) View Information Room                              *" << endl;
        gotoXY(42, 15);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 16);
        cout << "\t\t\t*\t  3) View Information Electric-Water                    *" << endl;
        gotoXY(42, 17);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 18);
        cout << "\t\t\t*\t  4) View Information Payment                           *" << endl;
        gotoXY(42, 19);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 20);
        cout << "\t\t\t*\t  5) Add Problem                                        *" << endl;
        gotoXY(42, 21);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 22);
        cout << "\t\t\t*\t  0) Logout                                             *" << endl;
        gotoXY(42, 23);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 24);
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        gotoXY(42, 25);
        cout << "***********************" << endl;
        cout << endl;
        gotoXY(42, 26);
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 5)
        {
            xoa(42, 26, 50);
            gotoXY(42, 26);
            cout << "Enter Right Your Choice : ";
            cin >> choice;
        }

        system("cls");
        khungbang();
        switch (choice)
        {
        case 1:
            gotoXY(61, 4);
            cout << "***Information Of Customer***" << endl;
            NguoiThue::find_idroom(object2.get_room_id(), L);
            sz = L.getSize();
            page = (sz - 1) / 6;
            p = 0;
            while (true)
            {
                xoa(4, 6, 144, 31);
                box_customer(9, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 2:
            gotoXY(63, 4);
            cout << "***Information Of Room***" << endl;
            Phong::find_idroom(object2.get_room_id(), L1);
            sz = L1.getSize();
            page = (sz - 1) / 14;
            p = 0;
            while (true)
            {
                xoa(4, 6, 140, 31);
                box_room(50, 6, L1, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 3:
            gotoXY(59, 4);
            cout << "***Information Of Electric Water***";
            L2.push_back(DienNuoc::find_nearest_dien_nuoc(object2.get_room_id()));
            sz = L2.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 6, 148, 31);
                box_diennuoc(5, 6, L2, p, 10, 1);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 4:
            gotoXY(64, 4);
            cout << "***Information Of BiLL***";
            L3.push_back(HoaDon::find_nearest_hoa_don(object2.get_room_id()));
            sz = L3.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 6, 140, 31);
                box_hoadon(49, 6, L3, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            box_hoadon(49, 6, L3);
            getch();
            break;
        case 5:

            gotoXY(62, 4);
            cout << "***Add Information Problem***";
            cin >> sc;
            sc.set_room_id(object2.get_room_id());
            sc.add_problem();

            gotoXY(4, 7);
            cout << "Add Problem Successful.";
            getch();
            break;
        default:
            break;
        }
        L.clear();
        L1.clear();
        L2.clear();
        // if (choice)
        //     getch();

    } while (choice != 0);
}

void menu_Manager_Customer()
{
    List<NguoiThue> L;
    List<Phong> L1;
    NguoiThue object2;
    string ID;
    Phong room;
    int choice;
    do
    {
        system("cls");
        khung(0, 0, 0, 0, "**** Welcome To Customer Manager ****");
        gotoXY(42, 10);
        cout << "\t\t\t*****************************************************************" << endl;
        gotoXY(42, 11);
        cout << "\t\t\t*\t                                                        *" << endl;
        gotoXY(42, 12);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 13);
        cout << "\t\t\t*\t  1) View List Customer                                 *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t  2) Add Customer                                       *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t  3) Find Customer                                      *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*\t  4) Delete Customer                                    *" << endl;
        gotoXY(42, 20);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 21);
        cout << "\t\t\t*\t  5) Edit Customer                                      *" << endl;
        gotoXY(42, 22);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 23);
        cout << "\t\t\t*\t  6) Change User_Password                               *" << endl;
        gotoXY(42, 24);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 25);
        cout << "\t\t\t*\t  0) Exit                                               *" << endl;
        gotoXY(42, 26);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 27);
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        gotoXY(42, 28);
        cout << "***********************" << endl
             << endl;
        gotoXY(42, 29);
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 6)
        {
            xoa(42, 29, 40);
            gotoXY(42, 29);
            cout << "Enter Right Your Choice : ";
            cin >> choice;
        }
        system("cls");
        khungbang();
        switch (choice)
        {
        case 1:
            gotoXY(63, 4);
            cout << "***Information Of All Customer***" << endl;
            NguoiThue::display(L);
            sz = L.getSize();
            page = (sz - 1) / 6;
            p = 0;
            while (true)
            {
                xoa(4, 5, 144, 32);
                box_customer(9, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 2:
            gotoXY(59, 4);
            cout << "***Enter Information New Customer***";
            cin >> object2;
            object2.set_customer_id(ChuyenDoi::CreateID("NguoiThue.txt"));
            object2.add_customer();
            break;
        case 3:
            gotoXY(61, 4);
            cout << "***Find Information Customer***" << endl;
            NguoiThue::find_customer(L);
            sz = L.getSize();
            page = (sz - 1) / 6;
            p = 0;
            while (true)
            {
                xoa(4, 14, 144, 23);
                box_customer(9, 14, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 4:
            gotoXY(60, 4);
            cout << "***Delete Information Customer***" << endl;
            gotoXY(4, 4);
            cout << "Find Information Customer";
            NguoiThue::find_customer(L);
            sz = L.getSize();
            page = (sz - 1) / 6;
            p = 0;
            while (true)
            {
                xoa(4, 14, 144, 23);
                box_customer(9, 14, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }

            do
            {
                xoa(4, 33, 40);
                xoa(4, 34, 40);
                gotoXY(4, 33);
                cout << "Enter Customer ID:";
                getline(cin, ID);
                NguoiThue::find_idcustomer(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 34);
                    cout << "ID does not exist!!!Try Again." << endl;
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            gotoXY(4, 34);
            cout << "Delete Successful." << endl;
            getch();
            NguoiThue::delete_customer(ID);
            break;
        case 5:
            gotoXY(61, 4);
            cout << "***Edit Information Customer***" << endl;
            gotoXY(4, 4);
            cout << "Find Information Customer";
            NguoiThue::find_customer(L);
            sz = L.getSize();
            page = (sz - 1) / 6;
            p = 0;
            while (true)
            {
                xoa(4, 14, 144, 23);
                box_customer(9, 14, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            L.clear();
            do
            {
                xoa(4, 33, 40);
                xoa(4, 34, 40);
                gotoXY(4, 33);
                cout << "Enter Customer ID:";
                getline(cin, ID);
                NguoiThue::find_idcustomer(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 34);
                    cout << "ID does not exist!!!Try Again." << endl;
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            system("cls");
            khungbang();
            gotoXY(4, 5);
            cout << "Information Current Customer:" << endl;
            box_customer(9, 6, L);
            gotoXY(4, 11);
            cout << "Enter New Information: " << endl;
            NguoiThue::update_customer(L[0], 11);
            break;
        case 6:
            gotoXY(68, 4);
            cout << "***Change Password***";
            cin.ignore();
            do
            {
                xoa(4, 5, 40);
                xoa(4, 6, 40);
                gotoXY(4, 5);
                cout << "Enter Room ID:";
                getline(cin, ID);
                NguoiThue::find_idroom(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 6);
                    cout << "ID does not exist!!!Try Again." << endl;
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            NguoiThue::change_user_name(ID);
            break;
        default:
            break;
        }
        L.clear();
        // if (choice)
        //     getch();

    } while (choice != 0);
}
void menu_Manager_Phong_Tro()
{
    int choice;
    Phong room;
    string ID, inputYN, ID_room_before, ID_room_after;
    Phong roomAfter, roomBefore;
    int month;
    int len;
    List<Phong> L;
    List<DienNuoc> L1;
    List<HoaDon> L2;
    ThoiGian now;
    do
    {
        system("cls");
        khung(0, 0, 0, 0, "**** Welcome To Room Manager ****");

        gotoXY(42, 10);
        cout << "\t\t\t*****************************************************************" << endl;
        gotoXY(42, 11);
        cout << "\t\t\t*\t                                                        *" << endl;
        gotoXY(42, 12);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 13);
        cout << "\t\t\t*\t  1) View List Room                                     *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t  2) View List Empty Room                               *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t  3) View List Rented Room                              *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*\t  4) Find Room                                          *" << endl;
        gotoXY(42, 20);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 21);
        cout << "\t\t\t*\t  5) Add Room                                           *" << endl;
        gotoXY(42, 22);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 23);
        cout << "\t\t\t*\t  6) Delete Room                                        *" << endl;
        gotoXY(42, 24);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 25);
        cout << "\t\t\t*\t  7) Edit Room                                          *" << endl;
        gotoXY(42, 26);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 27);
        cout << "\t\t\t*\t  8) Cancel Room                                        *" << endl;
        gotoXY(42, 28);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 29);
        cout << "\t\t\t*\t  9) Change Room                                        *" << endl;
        gotoXY(42, 30);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 31);
        cout << "\t\t\t*\t  0) Exit                                               *" << endl;
        gotoXY(42, 32);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 33);
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        gotoXY(42, 34);
        cout << "***********************" << endl
             << endl;
        gotoXY(42, 35);
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 9)
        {
            xoa(42, 35, 50);
            gotoXY(42, 35);
            cout << "Enter Right Your Choice : ";
            cin >> choice;
        }
        system("cls");
        khungbang();
        switch (choice)
        {
        case 1:
            gotoXY(65, 4);
            cout << "***Information Of All Room***" << endl;
            Phong::display(L);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 5, 140, 32);
                box_room(50, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 2:
            gotoXY(62, 4);
            cout << "***Information Of All Empty Room***" << endl;
            Phong::display(L, 2);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 5, 140, 32);
                box_roomempty(56, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 3:
            gotoXY(62, 4);
            cout << "***Information Of All Rented Room***" << endl;
            Phong::display(L, 1);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 5, 140, 32);
                box_roomrent(56, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 4:
        {
            gotoXY(64, 4);
            cout << "***Find Information Room***" << endl;
            cin.ignore();
            Phong::find_room(L);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 9, 140, 28);
                box_room(50, 9, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        }

        case 5:
            gotoXY(64, 4);
            cout << "***Add Information Room***";
            cin >> room;
            room.add_room(1);
            break;
        case 6:
            gotoXY(64, 4);
            cout << "***Delete Room***";
            cin.ignore();
            gotoXY(4, 5);
            cout << "Enter Room ID To Want Delete: ";
            getline(cin, ID);
            if (ID.size())
                Phong::delete_room(ID);
            gotoXY(4, 6);
            cout << "Delete Successful.";
            getch();
            break;
        case 7:
            gotoXY(64, 4);
            cout << "***Edit Information Room***";
            gotoXY(4, 4);
            cout << "Find Information Room";
            cin.ignore();
            Phong::find_room(L);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 9, 140, 28);
                box_room(50, 9, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            L.clear();
            do
            {
                xoa(4, 33, 40);
                xoa(4, 34, 40);
                gotoXY(4, 33);
                cout << "Enter Room ID: ";
                getline(cin, ID);
                Phong::find_idroom(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 34);
                    cout << "ID does not exist!!!Try Again." << endl;
                    getch();
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;

            system("cls");
            khungbang();
            gotoXY(4, 5);
            cout << "Information Current Room: " << endl;
            box_room(50, 7, L);
            gotoXY(4, 2 * L.getSize() + 10);
            cout << "Information New Room: " << endl;
            Phong::update_room(L[0], 2 * L.getSize() + 10);
            getch();
            break;
        case 8:
        {
            gotoXY(69, 4);
            cout << "***Cancel Room***";
            cin.ignore();
            L.clear();
            // hủy phòng : đặt trạng thái của phòng về false
            gotoXY(4, 5);
            cout << "Enter Room ID To Want Cancel: ";
            getline(cin, ID);
            if (ID.size())
            {
                Phong::find_idroom(ID, L);
                if (L.getSize())
                {
                    gotoXY(4, 6);
                    cout << "Information Room";
                    box_room(50, 7, L);
                    gotoXY(4, 12);
                    L1.push_back(DienNuoc::find_nearest_dien_nuoc(ID));
                    if (now <= L1[0].get_date())
                    {
                        cout << "Electricity and water bills have been paid";
                    }
                    else
                    {
                        cout << "Electricity and water bills have not been paid";
                    }

                    L2.push_back(HoaDon::find_nearest_hoa_don(ID));
                    gotoXY(4, 13);
                    if (now <= L2[0].get_date())
                    {
                        cout << "Room bill has been paid";
                    }
                    else
                    {
                        cout << "Room bill has not been paid";
                    }
                    gotoXY(4, 14);
                    cout << "Do you want cancel(Yes/No): ";
                    getline(cin, inputYN);
                    if (inputYN == "Y" || inputYN == "y" || inputYN == "Yes" || inputYN == "yes")
                    {
                        Phong::cancel_room(ID);
                        gotoXY(4, 15);
                        cout << "Cancel Successful.";
                    }
                }
                else
                {
                    gotoXY(4, 6);
                    cout << "Room ID is Invalid. Try Again.";
                }
            }
            getch();
            break;
        }
        case 9:
            gotoXY(69, 4);
            cout << "***Change Room***";
            L.clear();
            cin.ignore();
            do
            {
                xoa(4, 5, 40);
                xoa(4, 6, 40);
                gotoXY(4, 5);
                cout << "Enter ID Room Before: ";
                getline(cin, ID_room_before);
                Phong::find_idroom(ID_room_before, L);
                if (L.getSize() == 0)
                {
                    gotoXY(4, 6);
                    cout << "Room ID is Invalid. Try Again.";
                }
            } while (L.getSize() == 0 && ID_room_before.size());
            if (ID_room_before.size() == 0)
                break;
            roomBefore = L[0];
            L.clear();
            // lấy thông tin phòng after
            do
            {
                xoa(4, 6, 40);
                xoa(4, 7, 40);
                gotoXY(4, 6);
                cout << "Enter ID Room After: ";
                getline(cin, ID_room_after);
                Phong::find_idroom(ID_room_after, L);
                if (L.getSize() == 0)
                {
                    gotoXY(4, 7);
                    cout << "Room ID is Invalid. Try Again.";
                }
            } while (L.getSize() == 0 && ID_room_after.size());
            if (ID_room_after.size() == 0)
                break;
            roomAfter = L[0];
            L.clear();
            gotoXY(4, 7);
            cout << "Information Room Before";
            L.push_back(roomBefore);
            box_room(50, 8, L);
            L.clear();
            gotoXY(4, 13);
            cout << "Information Room After";
            L.push_back(roomAfter);
            box_room(50, 14, L);
            gotoXY(4, 19);
            cout << "Do you want cancel(Yes/No): ";
            getline(cin, inputYN);
            if (inputYN == "Y" || inputYN == "y" || inputYN == "Yes" || inputYN == "yes")
            {
                Phong::change_room(roomBefore, roomAfter);
                gotoXY(4, 23);
                cout << "Cancel Successful.";
            }

            getch();
            break;
        default:
            break;
        }
        L.clear();
    } while (choice != 0);
}
void menu_Manager_Payment()
{
    List<HoaDon> L;
    HoaDon object2;
    string ID;
    int len;
    int choice;
    do
    {
        system("cls");
        khung(0, 0, 0, 0, "**** Welcome To Payment Manager ****");
        gotoXY(42, 10);
        cout << "\t\t\t*****************************************************************" << endl;
        gotoXY(42, 11);
        cout << "\t\t\t*\t                                                        *" << endl;
        gotoXY(42, 12);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 13);
        cout << "\t\t\t*\t  1) View List Bill                                     *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t  2) View Paid Bill                                     *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t  3) View UnPaid Bill                                   *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*\t  4) Find Bill                                          *" << endl;
        gotoXY(42, 20);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 21);
        cout << "\t\t\t*\t  5) Paid Bill                                          *" << endl;
        gotoXY(42, 22);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 23);
        cout << "\t\t\t*\t  6) Edit Bill                                          *" << endl;
        gotoXY(42, 24);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 25);
        cout << "\t\t\t*\t  0) Exit                                               *" << endl;
        gotoXY(42, 26);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 27);
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        gotoXY(42, 28);
        cout << "***********************" << endl
             << endl;
        gotoXY(42, 29);
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 6)
        {
            xoa(42, 29, 50);
            gotoXY(42, 29);
            cout << "Enter Right Your Choice : ";
            cin >> choice;
        }
        system("cls");
        khungbang();
        switch (choice)
        {
        case 1:
            gotoXY(66, 4);
            cout << "***Information Of All BiLL***";
            HoaDon::display(L);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 5, 140, 32);
                box_hoadon(49, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 2:
            gotoXY(64, 4);
            cout << "***Information Of All Pay BiLL***";
            HoaDon::display(L, 1);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 5, 140, 32);
                box_hoadonpay(49, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 3:
            gotoXY(64, 4);
            cout << "***Information Of All UnPay BiLL***";
            HoaDon::display(L, 2);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 5, 140, 32);
                box_hoadonunpay(49, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 4:
            gotoXY(64, 4);
            cout << "***Find Information BiLL***" << endl;
            HoaDon::find_hoa_don(L);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 9, 140, 28);
                box_hoadon(49, 9, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 5:
            gotoXY(70, 4);
            cout << "***Pay BiLL***";
            gotoXY(4, 5);
            cout << "List Of Unpaid Rooms: " << endl;
            HoaDon::display(L, 2);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 9, 140, 28);
                box_hoadonunpay(49, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            cin.ignore();
            do
            {
                L.clear();
                xoa(4, 30, 100);
                xoa(4, 31, 100);
                xoa(4, 32, 100);
                xoa(4, 33, 100);
                xoa(4, 34, 100);
                xoa(4, 35, 100);
                xoa(4, 36, 100);
                gotoXY(4, 30);
                cout << "Enter ID Of Bill Want To Pay: ";
                getline(cin, ID);
                if (ID == "exit")
                    break;
                HoaDon::find_bill_id(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 31);
                    cout << "ID does not exist!!!Try Again." << endl;
                    getch();
                }
                HoaDon::Pay_bill(L[0], 30);
            } while ((ID.size() && L.getSize() == 0) || ID.size() == 0 || true);
            break;

        case 6:
            gotoXY(67, 4);
            cout << "***Edit Information BiLL***" << endl;
            gotoXY(4, 4);
            cout << "Find Information BiLL";
            HoaDon::find_hoa_don(L);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 9, 140, 28);
                box_hoadon(49, 9, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }

            len = L.getSize();
            L.clear();
            do
            {
                xoa(4, 33, 40);
                xoa(4, 34, 40);
                gotoXY(4, 33);
                cout << "Enter BiLL ID: ";

                getline(cin, ID);
                HoaDon::find_bill_id(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 34);
                    cout << "ID does not exist!!!Try Again." << endl;
                    getch();
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            system("cls");
            khungbang();
            gotoXY(4, 4);
            cout << "Infomation Current BiLL:" << endl;
            box_hoadon(49, 6, L);
            gotoXY(4, 11);
            cout << "Enter New Information:" << endl;
            HoaDon::update_hoa_don(L[0], 11);
            break;
        default:
            break;
        }
        L.clear();

    } while (choice != 0);
}
void menu_Manager_Dien_Nuoc()
{
    DienNuoc object2;
    List<DienNuoc> L;
    int choice, number, len;
    string ID;
    do
    {
        system("cls");
        khung(0, 0, 0, 0, "**** Welcome To Electric-Water Manager ****");
        gotoXY(42, 10);
        cout << "\t\t\t*****************************************************************" << endl;
        gotoXY(42, 11);
        cout << "\t\t\t*\t                                                        *" << endl;
        gotoXY(42, 12);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 13);
        cout << "\t\t\t*\t  1) View list Electric-Water                           *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t  2) View List Unpaid Electric_Water                    *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t  3) View List Paid Electric_Water                      *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*\t  4) Find Electric_Water                                *" << endl;
        gotoXY(42, 20);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 21);
        cout << "\t\t\t*\t  5) Paid Electric_Water                                *" << endl;
        gotoXY(42, 22);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 23);
        cout << "\t\t\t*\t  6) Edit Cost Electric                                 *" << endl;
        gotoXY(42, 24);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 25);
        cout << "\t\t\t*\t  7) Edit Cost Water                                    *" << endl;
        gotoXY(42, 26);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 27);
        cout << "\t\t\t*\t  8) Edit Electric-Water                                *" << endl;
        gotoXY(42, 28);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 29);
        cout << "\t\t\t*\t  0) Exit                                               *" << endl;
        gotoXY(42, 30);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 31);
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        gotoXY(42, 32);
        cout << "***********************" << endl
             << endl;
        gotoXY(42, 33);
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 8)
        {
            xoa(42, 33, 50);
            gotoXY(42, 33);
            cout << "Enter Right Your Choice : ";
            cin >> choice;
        }
        system("cls");
        khungbang();
        switch (choice)
        {
        case 1:
            gotoXY(61, 4);
            cout << "***Information Of All Electric Water***";
            DienNuoc::display(L);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 5, 148, 32);
                box_diennuoc(5, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 2:
            gotoXY(58, 4);
            cout << "***Information Of UnPaid Electric Water***";
            DienNuoc::display(L, 2);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 5, 148, 32);
                box_diennuocunpay(9, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 3:
            gotoXY(60, 4);
            cout << "***Information Of Paid Electric Water***";
            DienNuoc::display(L, 1);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 5, 148, 32);
                box_diennuocpay(9, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 4:
            gotoXY(60, 4);
            cout << "***Find Informatin Electric Water***" << endl;
            DienNuoc::find_dien_nuoc(L);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 10, 148, 27);
                box_diennuoc(5, 10, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }

            break;
        case 5:
            gotoXY(66, 4);
            cout << "***Pay Electric Water***";
            gotoXY(4, 5);
            cout << "Informatin Unpaid Room:" << endl;
            DienNuoc::display(L, 2);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(5, 7, 148, 30);
                box_diennuocunpay(9, 7, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            cin.ignore();
            do
            {
                L.clear();
                xoa(4, 30, 100);
                xoa(4, 31, 100);
                xoa(4, 32, 100);
                xoa(4, 33, 100);
                xoa(4, 34, 100);
                xoa(4, 35, 100);
                xoa(4, 36, 100);
                gotoXY(4, 30);
                cout << "Enter ID Of Electric Water Want To Pay: ";
                getline(cin, ID);
                if (ID == "exit")
                    break;
                DienNuoc::find_dien_nuoc_id(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 31);
                    cout << "ID does not exist!!!Try Again." << endl;
                    getch();
                }
                DienNuoc::Pay_dien_nuoc(L[0], 30);
            } while ((ID.size() && L.getSize() == 0) || ID.size() == 0 || true);
            break;
        case 6:
            gotoXY(66, 4);
            cout << "***Edit Cost Electric***";
            gotoXY(4, 5);
            cout << "Current Cost Electric: " << DienNuoc::getNewCostElectric() << endl;
            cin.ignore();
            gotoXY(4, 6);
            cout << "Enter New Cost Electric:  ";
            getline(cin, ID);
            if (ID.size() == 0)
                break;
            number = ChuyenDoi::str_to_int(ID);
            DienNuoc::updateCostElectric(number);
            break;
        case 7:
            gotoXY(67, 4);
            cout << "***Edit Cost Water***";
            gotoXY(4, 5);
            ;
            cout << "Current Cost Water: " << DienNuoc::getNewCostWater() << endl;
            cin.ignore();
            gotoXY(4, 6);
            cout << "Enter New Cost Water: ";
            getline(cin, ID);
            if (ID.size() == 0)
                break;
            number = ChuyenDoi::str_to_int(ID);
            DienNuoc::updateCostWater(number);
            break;
        case 8:
            gotoXY(60, 4);
            cout << "***Edit Information Electric Water***";
            gotoXY(4, 4);
            cout << "Find Informatin Electric Water";
            DienNuoc::find_dien_nuoc(L);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(5, 10, 148, 27);
                box_diennuoc(5, 10, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            len = L.getSize();
            L.clear();
            do
            {
                xoa(4, 33, 40);
                xoa(4, 34, 40);
                gotoXY(4, 33);
                cout << "Enter Electric Water ID: ";
                getline(cin, ID);
                DienNuoc::find_dien_nuoc_id(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 34);
                    cout << "ID does not exist!!!Try Again." << endl;
                    getch();
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;

            system("cls");
            khungbang();
            gotoXY(4, 4);
            cout << "Information Current Electric_Water: " << endl;
            // tin diem nuoc
            box_diennuoc(5, 6, L);
            gotoXY(4, 11);
            // DienNuoc::display(L);

            cout << "Information New Electric_Water: " << endl;
            DienNuoc::update_dien_nuoc(L[0], 11);
            break;
        default:
            break;
        }
        L.clear();
        // if (choice)
        //     getch();
    } while (choice != 0);
}

void menu_Calculate_Revenue()
{
    int choice, month, year, revenue;
    int startYear, startMonth, startDay, endYear, endMonth, endDay;
    string startDate, endDate; // Declare variables
    ThoiGian time;
    DoanhThu doanhThu; // Create an object of the DoanhThu class

    do
    {
        system("cls");
        khung(0, 0, 0, 0, "**** Welcome To Calculate Revenue ****");
        gotoXY(42, 10);
        cout << "\t\t\t*****************************************************************" << endl;
        gotoXY(42, 11);
        cout << "\t\t\t*\t                                                        *" << endl;
        gotoXY(42, 12);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 13);
        cout << "\t\t\t*\t  1) Calculate Revenue By Month                         *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t  2) Calculate Revenue By Year                          *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t  3) Calculate revenue by time period                   *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*\t  0) Exit                                               *" << endl;
        gotoXY(42, 20);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 21);
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        gotoXY(42, 22);
        cout << "***********************" << endl
             << endl;
        gotoXY(42, 23);
        cout << "Enter Your Choice : ";
        cin >> choice;

        while (choice < 0 || choice > 3)
        {
            xoa(42, 23, 50);
            gotoXY(42, 23);
            cout << "Enter Right Your Choice : ";
            cin >> choice;
        }

        system("cls");
        khungbang();
        switch (choice)
        {
        case 1:
            gotoXY(62, 4);
            cout << "***Calculate Revenue By Month***";
            do
            {
                xoa(4, 5, 100);
                xoa(4, 6, 100);
                gotoXY(4, 5);
                cout << "Enter Month: ";
                cin >> month;

                // Kiểm tra giá trị hợp lệ cho tháng (1-12)
                if (month < 1 || month > 12)
                {
                    gotoXY(4, 6);
                    cout << "Invalid Month. Please enter a value between 1 and 12." << endl;
                    getch();
                }
            } while (month < 1 || month > 12);

            gotoXY(4, 6);
            cout << "Enter Year: ";
            cin >> year;

            // Gọi hàm tính tổng doanh thu theo tháng
            revenue = doanhThu.tongDoanhThutheothoigian(year, month, 1, year, month, 31);

            // Hiển thị kết quả
            gotoXY(4, 7);
            cout << "Total Revenue for " << month << "/" << year << ": " << revenue << endl;
            getch();
            break;

        case 2:
            gotoXY(62, 4);
            cout << "***Calculate Revenue By Year***";
            gotoXY(4, 5);
            cout << "Enter Year: ";
            cin >> year;

            // Gọi hàm tính tổng doanh thu theo năm
            revenue = doanhThu.tongDoanhThutheothoigian(year, 1, 1, year, 12, 31);

            // Hiển thị kết quả
            gotoXY(4, 6);
            cout << "Total Revenue for Year " << year << ": " << revenue << endl;
            getch();
            break;

        case 3:
            gotoXY(60, 4);
            cout << "***Calculate revenue by time periodr***";
            do
            {
                cin.ignore();
                xoa(4, 5, 100);
                xoa(4, 6, 100);
                gotoXY(4, 5);
                cout << "Enter Start Date (yy-mm-dd): ";
                getline(cin, startDate);
                time = ThoiGian::Split(startDate);
                startYear = time.get_years();
                startMonth = time.get_months();
                startDay = time.get_days();
                // Kiểm tra giá trị hợp lệ cho ngày và tháng
                if (!ThoiGian::isValidDate(startYear, startMonth, startDay))
                {
                    gotoXY(4, 6);
                    cout << "Invalid Date. Please Enter a Valid Date." << endl;
                }
            } while (!ThoiGian::isValidDate(startYear, startMonth, startDay));

            do
            {
                xoa(4, 6, 100);
                xoa(4, 7, 100);
                gotoXY(4, 6);
                cout << "Enter End Date (yy-mm-dd): ";
                getline(cin, endDate);
                time = ThoiGian::Split(endDate);
                endYear = time.get_years();
                endMonth = time.get_months();
                endDay = time.get_days();
                // Kiểm tra giá trị hợp lệ cho ngày và tháng
                if (!ThoiGian::isValidDate(endYear, endMonth, endDay))
                {
                    gotoXY(4, 7);
                    cout << "Invalid Date. Please Enter a Valid Date." << endl;
                }
            } while (!ThoiGian::isValidDate(endYear, endMonth, endDay));

            // Gọi hàm tính tổng doanh thu theo khoảng thời gian
            revenue = doanhThu.tongDoanhThutheothoigian(startYear, startMonth, startDay, endYear, endMonth, endDay);

            // Hiển thị kết quả
            gotoXY(4, 7);
            cout << "Total Revenue from " << startYear << "-" << startMonth << "-" << startDay
                 << " to " << endYear << "-" << endMonth << "-" << endDay << ": " << revenue << endl;
            getch();
            break;

        default:
            break;
        }

        // if (choice)
        //     getch();
    } while (choice != 0);
}

void menu_problem()
{
    int choice, len;
    SuCo obj;
    List<SuCo> L;
    string ID;
    ThoiGian time;
    do
    {
        system("cls");
        khung(0, 0, 0, 0, "**** Welcome To Manager Problem ****");
        gotoXY(42, 10);
        cout << "\t\t\t*****************************************************************" << endl;
        gotoXY(42, 11);
        cout << "\t\t\t*\t                                                        *" << endl;
        gotoXY(42, 12);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 13);
        cout << "\t\t\t*\t  1) View List Problem                                  *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t  2) View List Solved Problem                           *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t  3) View List UnSolved Problem                         *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*\t  4) Confirm Solve Problem                              *" << endl;
        gotoXY(42, 20);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 21);
        cout << "\t\t\t*\t  0) Exit                                               *" << endl;
        gotoXY(42, 22);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 23);
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        gotoXY(42, 24);
        cout << "***********************" << endl
             << endl;
        gotoXY(42, 25);
        cout << "Enter Your Choice : ";
        cin >> choice;

        while (choice < 0 || choice > 4)
        {
            xoa(42, 25, 50);
            gotoXY(42, 25);
            cout << "Enter Right Your Choice : ";
            cin >> choice;
        }
        system("cls");
        khungbang();
        switch (choice)
        {
        case 1:
            gotoXY(66, 4);
            cout << "***View List Problem***";
            SuCo::display(L);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 6, 148, 31);
                box_problem(28, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;

        case 2:
            gotoXY(62, 4);
            cout << "***View List Solved Problem***";
            SuCo::display(L, 1);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 6, 148, 31);
                box_solvedproblem(30, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }

            break;

        case 3:
            gotoXY(62, 4);
            cout << "***View List UnSolved Problem***";
            SuCo::display(L, 2);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 6, 148, 31);
                box_unsolvedproblem(30, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            break;
        case 4:
            gotoXY(66, 4);
            cout << "***Confirm Solve Problem***";
            gotoXY(4, 5);
            cout << "Information Of UnSolved Problem:" << endl;
            SuCo::display(L, 2);
            sz = L.getSize();
            page = (sz - 1) / 10;
            p = 0;
            while (true)
            {
                xoa(4, 6, 148, 31);
                box_unsolvedproblem(30, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }
            L.clear();
            cin.ignore();
            do
            {
                xoa(4, 30, 40);
                xoa(4, 31, 40);
                gotoXY(4, 30);
                cout << "Enter Problem ID:";
                getline(cin, ID);
                SuCo::find_idproblem(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 31);
                    cout << "ID Already Exists!!!Try Again." << endl;
                    getch();
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            gotoXY(4, 31);
            cout << "Do you want to Confirm?(Yes/No): ";
            cin >> ID;
            if (ID == "Yes")
            {
                L[0].set_finishdate(time);
                L[0].set_status(true);
                SuCo::solve(L[0]);
            }
            break;
        default:
            break;
        }
        L.clear();

    } while (choice != 0);
}

void menu_admin(QuanLy &object1)
{
    int choice;
    do
    {
        system("cls");

        string content = "**** Welcome To Admin ***";
        khung(0, 0, 0, 0, content);
        gotoXY(42, 10);
        cout << "\t\t\t*****************************************************************" << endl;
        gotoXY(42, 11);
        cout << "\t\t\t*\t                                                        *" << endl;
        gotoXY(42, 12);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 13);
        cout << "\t\t\t*\t  1) Manager Customer                                   *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t  2) Manager Room                                       *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t  3) Manager Electric-Water                             *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*\t  4) Manager Payment                                    *" << endl;
        gotoXY(42, 20);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 21);
        cout << "\t\t\t*\t  5) Calculate Revenue                                  *" << endl;
        gotoXY(42, 22);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 23);
        cout << "\t\t\t*\t  6) Manager Problem                                    *" << endl;
        gotoXY(42, 24);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 25);
        cout << "\t\t\t*\t  0) Logout                                             *" << endl;
        gotoXY(42, 26);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 27);
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        gotoXY(42, 28);
        cout << "***********************" << endl
             << endl;
        gotoXY(42, 29);
        cout << "Enter Your Choice : ";
        cin >> choice;
        int year, month, revenue;
        while (choice < 0 || choice > 6)
        {
            xoa(42, 29, 50);
            gotoXY(42, 29);
            cout << "Enter Right Your Choice : ";
            cin >> choice;
        }
        system("cls");
        switch (choice)
        {
        case 1:
            menu_Manager_Customer();
            break;
        case 2:
            menu_Manager_Phong_Tro();
            break;
        case 3:
            menu_Manager_Dien_Nuoc();
            break;
        case 4:
            menu_Manager_Payment();
            break;
        case 5:
            menu_Calculate_Revenue();
            break;
        case 6:
            menu_problem();
            break;
        default:
            break;
        }
    } while (choice != 0);
}
void menu_login()
{

    string user_name, password;
    QuanLy object1;
    NguoiThue object2;

    int role = 0;
    cin.ignore();
    do
    {
        ThanhNgang(53, 13, 50, 8, 10, 177); // ngang tren
        ThanhTru(53, 13, 17, 8, 10, 177);   // tru trai
        ThanhNgang(55, 29, 50, 8, 10, 177); // ngang duoi
        ThanhTru(103, 13, 17, 8, 10, 177);  // tru phải
        ThanhNgang(53, 17, 50, 8, 10, 177);
        setColor(0, 14);
        gotoXY(75, 15);
        cout << "LOGIN";
        // gotoXY(72,24); cout << "USERNAME: "; //goto(82,24)
        // gotoXY(72,26); cout << "PASSWORD: "; //goto(82,26)
        // gotoXY(0,0);
        // xoa(55,19,40);
        gotoXY(56, 19);
        cout << "Enter User Name: ";
        getline(cin, user_name);
        // xoa(55,21,40);
        gotoXY(56, 21);
        cout << "Enter Password: ";
        hide_password_input(password);
        cout << endl;
        object1.set_user_name(user_name);
        object1.set_password(password);

        if (object1.login())
        {
            role = 1;
            for (int j = 0; j <= 100; j = j + 25)
            {
                gotoXY(56, 27);
                cout << "Checking Information" << string(j % 3 + 1, '.') << " " << j << "%" << endl;
                sleep(1);
                xoa(56, 27, 45);
            }
            gotoXY(56, 27);
            cout << "Login successfully!" << endl;
            getch();
            break;
        }
        object2.set_user_name(user_name);
        object2.set_password(password);
        if (object2.login())
        {
            role = 2;
            for (int j = 0; j <= 100; j = j + 25)
            {
                gotoXY(56, 27);
                cout << "Checking Information" << string(j % 3 + 1, '.') << " " << j << "%" << endl;
                sleep(1);
                xoa(56, 27, 45);
            }
            gotoXY(56, 27);
            cout << "Login successfully!" << endl;
            getch();
            break;
        }
        user_name.clear();
        password.clear();
        gotoXY(56, 27);
        cout << "Username or password is incorrect.Try again." << endl;
        getch();
        cin.ignore();
        system("cls");
    } while (!role);
    if (role == 1)
        menu_admin(object1);
    else
        menu_user(object2);

    // customer object1;
    // string user_name = "c111";
    // string  password = "1111";
    // object1.set_user_name(user_name);
    // object1.set_password(password);
    // menu_user(object1);
}
void menu()
{
    List<Phong> L;
    int choice;
    do
    {
        system("cls");
        khung(0, 0, 0, 0, "**** Welcome To System Motel Room Manager ****");
        gotoXY(42, 10);
        cout << "\t\t\t*****************************************************************" << endl;
        gotoXY(42, 11);
        cout << "\t\t\t*\t                                                        *" << endl;
        gotoXY(42, 12);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 13);
        cout << "\t\t\t*\t  1) Login                                              *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t  2) View Empty Room                                    *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t  0) Exit                                               *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;
        gotoXY(42, 20);
        cout << "***********************" << endl
             << endl;
        gotoXY(42, 21);
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 2)
        {
            xoa(42, 21, 50);
            gotoXY(42, 21);
            cout << "Enter Right Your Choice : ";
            cin >> choice;
        }
        system("cls");

        switch (choice)
        {
        case 1:
            menu_login();
            break;
        case 2:
            system("cls");
            khungbang();
            gotoXY(62, 4);
            cout << "***Information Of All Empty Room***" << endl;
            Phong::display(L, 2);
            sz = L.getSize();
            page = (sz - 1) / 14;
            p = 0;
            while (true)
            {
                xoa(4, 5, 140, 32);
                box_roomempty(56, 6, L, p);
                gotoXY(145, 36);
                cout << p + 1 << " / " << page + 1;
                ch = getch();
                if (ch == 'l')
                {
                    if (p < page)
                        p++;
                }
                else if (ch == 'x')
                {
                    if (p > 0)
                        p--;
                }
                else
                {
                    break;
                }
            }

            break;
        default:
            break;
        }
        L.clear();
    } while (choice != 0);
}

int main()
{
    system("cls");
    bia();
    getch();
    menu();
    return 0;
}
