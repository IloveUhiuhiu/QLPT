#include "admin.h"
#include "customer.h"
#include "DoanhThu.h"
#include <list>  // Include the appropriate header for your List class

void TextColor(int textColor)
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hConsoleOut;
    COORD Home = {0, 0};
    DWORD dummy;

    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

    FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
    csbiInfo.dwCursorPosition.X = 0;
    csbiInfo.dwCursorPosition.Y = 0;
    SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void gotoXY(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void textcolor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void setColor(int maunen, int mauchu)
{
    SetBGColor(maunen);
    textcolor(mauchu);
}
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
        gotoXY(x, j);
        cout << char(makitu) << char(makitu);
    }
}
void khung(int a, int b, int c, int d, const string content)
{
    int mau = 6;
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
    cout << "Number Of Rooms: " << a;
    gotoXY(4, 18);
    cout << "Number Of Customers: " << b;
    gotoXY(4, 25);
    cout << "Number Of Empty Rooms: " << c;
    gotoXY(4, 32);
    cout << "Number Of Problem: " << d;
    gotoXY(2 + (154 - content.size()) / 2, 4);
    cout << content;
}
void bia()
{
    ThanhNgang(2, 15, 154, 6, 10, 177); // ngang tren
    ThanhNgang(2, 27, 154, 6, 10, 177); // ngang duoi
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
void box_customer(int x, int y, List<customer> &L)
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
    w.push_back(18);
    content.push_back("DateofBirth");
    w.push_back(14);
    content.push_back("DateCheckIn");
    w.push_back(14);
    content.push_back("Gender");
    w.push_back(10);
    content.push_back("Email");
    w.push_back(20);
    content.push_back("Address");
    w.push_back(14);
    content.push_back("Phone");
    w.push_back(14);
    content.push_back("UserName");
    w.push_back(12);
    content.push_back("Password");
    w.push_back(10);
    for (int i = 0; i < n; i++)
    {
        content.push_back(L[i].get_customer_id());
        content.push_back(L[i].get_room_id());
        content.push_back(L[i].get_customer_name());
        content.push_back(Datetime::Union(L[i].get_customer_dateofbirth()));
        content.push_back(Datetime::Union(L[i].get_check_in()));
        content.push_back(L[i].get_customer_gender());
        content.push_back(L[i].get_customer_email());
        content.push_back(L[i].get_customer_address());
        content.push_back(L[i].get_customer_phone());
        content.push_back(L[i].get_user_name());
        content.push_back(L[i].get_password());
    }
    box(x, y, w, n + 1, 11, content);
}

void box_room(int x, int y, List<Room> &L)
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
    for (int i = 0; i < n; i++)
    {
        content.push_back(L[i].getRoomID());
        content.push_back(L[i].getKindOf());
        content.push_back(Convert::int_to_str((L[i].getCost())));
        content.push_back((L[i].isOccupied() ? "Rent" : "Empty"));
    }
    box(x, y, w, n + 1, 4, content);
}

void box_roomrent(int x, int y, List<Room> &L)
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
    for (int i = 0; i < n; i++)
    {
        content.push_back(L[i].getRoomID());
        content.push_back(L[i].getKindOf());
        content.push_back(Convert::int_to_str(L[i].getCost()));
    }
    box(x, y, w, n + 1, 3, content);
}

void box_roomempty(int x, int y, List<Room> &L)
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
    for (int i = 0; i < n; i++)
    {
        content.push_back(L[i].getRoomID());
        content.push_back(L[i].getKindOf());
        content.push_back(Convert::int_to_str(L[i].getCost()));
    }
    box(x, y, w, n + 1, 3, content);
}
void box_diennuoc(int x, int y, List<dien_nuoc> &L)
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
    for (int i = 0; i < n; i++)
    {
        content.push_back(L[i].get_dien_nuoc_id());
        content.push_back(L[i].get_room_id());
        content.push_back(Convert::int_to_str(L[i].get_num_electric_before()));
        content.push_back(Convert::int_to_str(L[i].get_num_electric_after()));
        content.push_back(Convert::int_to_str(L[i].get_num_water_before()));
        content.push_back(Convert::int_to_str(L[i].get_num_water_after()));
        content.push_back(Convert::int_to_str(L[i].get_cost_electric()));
        content.push_back(Convert::int_to_str(L[i].get_cost_water()));
        content.push_back(Datetime::Union(L[i].get_date()));
        content.push_back(Convert::bool_to_str(L[i].get_status()));
    }
    box(x, y, w, n + 1, 10, content);
}
void box_diennuocpay(int x, int y, List<dien_nuoc> &L)
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
    for (int i = 0; i < n; i++)
    {
        content.push_back(L[i].get_dien_nuoc_id());
        content.push_back(L[i].get_room_id());
        content.push_back(Convert::int_to_str(L[i].get_num_electric_before()));
        content.push_back(Convert::int_to_str(L[i].get_num_electric_after()));
        content.push_back(Convert::int_to_str(L[i].get_num_water_before()));
        content.push_back(Convert::int_to_str(L[i].get_num_water_after()));
        content.push_back(Convert::int_to_str(L[i].get_cost_electric()));
        content.push_back(Convert::int_to_str(L[i].get_cost_water()));
        content.push_back(Datetime::Union(L[i].get_date()));
    }
    box(x, y, w, n + 1, 9, content);
}
void box_diennuocunpay(int x, int y, List<dien_nuoc> &L)
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
    for (int i = 0; i < n; i++)
    {
        content.push_back(L[i].get_dien_nuoc_id());
        content.push_back(L[i].get_room_id());
        content.push_back(Convert::int_to_str(L[i].get_num_electric_before()));
        content.push_back(Convert::int_to_str(L[i].get_num_electric_after()));
        content.push_back(Convert::int_to_str(L[i].get_num_water_before()));
        content.push_back(Convert::int_to_str(L[i].get_num_water_after()));
        content.push_back(Convert::int_to_str(L[i].get_cost_electric()));
        content.push_back(Convert::int_to_str(L[i].get_cost_water()));
        content.push_back(Datetime::Union(L[i].get_date()));
    }
    box(x, y, w, n + 1, 9, content);
}
void box_hoadon(int x, int y, List<hoa_don> &L)
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
    for (int i = 0; i < n; i++)
    {
        content.push_back(L[i].get_bill_id());
        content.push_back(L[i].get_room_id());
        content.push_back(Datetime::Union(L[i].get_date()));
        content.push_back(Convert::int_to_str(L[i].get_total_cost()));
        content.push_back(Convert::bool_to_str(L[i].get_status()));
    }
    box(x, y, w, n + 1, 5, content);
}
void box_hoadonpay(int x, int y, List<hoa_don> &L)
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
    for (int i = 0; i < n; i++)
    {
        content.push_back(L[i].get_bill_id());
        content.push_back(L[i].get_room_id());
        content.push_back(Datetime::Union(L[i].get_date()));
        content.push_back(Convert::int_to_str(L[i].get_total_cost()));
    }
    box(x, y, w, n + 1, 4, content);
}
void box_hoadonunpay(int x, int y, List<hoa_don> &L)
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
    for (int i = 0; i < n; i++)
    {
        content.push_back(L[i].get_bill_id());
        content.push_back(L[i].get_room_id());
        content.push_back(Datetime::Union(L[i].get_date()));
        content.push_back(Convert::int_to_str(L[i].get_total_cost()));
    }
    box(x, y, w, n + 1, 4, content);
}

void box_problem(int x, int y, List<problem> &L)
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
    for (int i = 0; i < n; i++)
    {
        content.push_back(L[i].get_problem_id());
        content.push_back(L[i].get_room_id());
        content.push_back(Datetime::Union(L[i].get_registeddate()));
        content.push_back(Datetime::Union(L[i].get_finishdate()));
        content.push_back(L[i].get_content());
        content.push_back(Convert::bool_to_str(L[i].get_status()));
    }
    box(x, y, w, n + 1, 6, content);
}
void box_solvedproblem(int x, int y, List<problem> &L)
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
    for (int i = 0; i < n; i++)
    {
        content.push_back(L[i].get_problem_id());
        content.push_back(L[i].get_room_id());
        content.push_back(Datetime::Union(L[i].get_registeddate()));
        content.push_back(Datetime::Union(L[i].get_finishdate()));
        content.push_back(L[i].get_content());
    }
    box(x, y, w, n + 1, 5, content);
}
void box_unsolvedproblem(int x, int y, List<problem> &L)
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
    for (int i = 0; i < n; i++)
    {
        content.push_back(L[i].get_problem_id());
        content.push_back(L[i].get_room_id());
        content.push_back(Datetime::Union(L[i].get_registeddate()));
        content.push_back(Datetime::Union(L[i].get_finishdate()));
        content.push_back(L[i].get_content());
    }
    box(x, y, w, n + 1, 5, content);
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
void xoa(int x, int y, int dodai)
{
    gotoXY(x, y);
    for (int i = x; i <= x + dodai; i++)
    {
        cout << " ";
    }
}
void menu_user(customer &object2)
{
    int choice;
    Room room;
    dien_nuoc dn;
    hoa_don hd;
    List<customer> L;
    List<Room> L1;
    List<dien_nuoc> L2;
    List<hoa_don> L3;
    do
    {
        system("cls");
        string content = "**** Wellcome Customer " + object2.get_user_name();
        content = content + " ***";
        khung(0, 0, 0, 0, content);
        gotoXY(42, 10);
        cout << "\t\t\t*****************************************************************" << endl;
        gotoXY(42, 10);
        cout << "\t\t\t*\t                                                        *" << endl;
        gotoXY(42, 11);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 12);
        cout << "\t\t\t*\t|  1) View Information Customer       |                 *" << endl;
        gotoXY(42, 13);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 14);
        cout << "\t\t\t*\t|  2) View Information Room           |                 *" << endl;
        gotoXY(42, 15);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 16);
        cout << "\t\t\t*\t|  3) View Information Electric-Water |                 *" << endl;
        gotoXY(42, 17);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 18);
        cout << "\t\t\t*\t|  4) View Information Payment        |                 *" << endl;
        gotoXY(42, 19);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 20);
        cout << "\t\t\t*\t|  0) Logout                          |                 *" << endl;
        gotoXY(42, 21);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 22);
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        gotoXY(42, 23);
        cout << "***********************" << endl;
        cout << endl;
        gotoXY(42, 24);
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 4)
        {
            gotoXY(42, 24);
            xoa(42, 24, 50);
            gotoXY(42, 24);
            cout << "Enter Right Your Choice : ";
            cin >> choice;
        }
        system("cls");
        switch (choice)
        {
        case 1:
            customer::find_idroom(object2.get_room_id(), L);
            box_customer(3, 3, L);
            getch();
            break;
        case 2:
            Room::find_idroom(object2.get_room_id(), L1);
            box_room(3, 3, L1);
            gotoXY(0, 0);
            getch();
            break;
        case 3:
            dien_nuoc::find_dien_nuoc_id(dn.find_max_dien_nuoc_id(), L2);
            box_diennuoc(3, 3, L2);
            getch();
            break;
        case 4:
            hoa_don::find_bill_id(hd.find_max_bill_id(), L3);
            box_hoadon(3, 3, L3);
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
    List<customer> L;
    List<Room> L1;
    customer object2;
    string ID;
    Room room;
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
        cout << "\t\t\t*\t|  1) View List Customer  |                             *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t|  2) Add Customer        |                             *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t|  3) Find Customer       |                             *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*\t|  4) Delete Customer     |                             *" << endl;
        gotoXY(42, 20);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 21);
        cout << "\t\t\t*\t|  5) Edit Customer       |                             *" << endl;
        gotoXY(42, 22);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 23);
        cout << "\t\t\t*\t|  6) Change User_Password|                             *" << endl;
        gotoXY(42, 24);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 25);
        cout << "\t\t\t*\t|  0) Exit                |                             *" << endl;
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
        switch (choice)
        {
        case 1:
            cout << "***Information Of All Customer***" << endl;
            cout << endl;
            customer::display(L);
            box_customer(3, 3, L);
            getch();
            break;
        case 2:
            // add
            cin >> object2;
            object2.set_customer_id(Convert::CreateID("customer.txt"));
            object2.add_customer();
            break;
        case 3:
            cout << "Find Information Customer: " << endl;
            if (!customer::find_customer(L))
            {
                cout << "Not Found!" << endl;
                getch();
                continue;
            }
            else
            {
                box_customer(3, 10, L);
                gotoXY(0, 0);
            }
            getch();
            break;
        case 4:
            cout << "Find Information Customer: " << endl;
            if (!customer::find_customer(L))
            {
                cout << "Not Found!" << endl;
                getch();
                continue;
            }
            else
            {
                box_customer(3, 10, L);
                gotoXY(0, 2 * L.getSize() + 13);
            }

            do
            {
                cout << "Enter Customer ID:";
                getline(cin, ID);
                customer::find_idcustomer(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    cout << "ID does not exist!!!Try Again." << endl;
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            customer::delete_customer(ID);
            break;
        case 5:
            cout << "Find Information Customer: " << endl;
            if (!customer::find_customer(L))
            {
                cout << "Not Found!" << endl;
                continue;
            }
            box_customer(3, 10, L);
            gotoXY(0, 2 * L.getSize() + 13);
            L.clear();
            do
            {
                cout << "Enter Customer ID:";
                getline(cin, ID);
                customer::find_idcustomer(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    cout << "ID does not exist!!!Try Again." << endl;
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            system("cls");
            cout << "Information Current Customer: " << endl;
            box_customer(3, 3, L);
            gotoXY(0, 2 * L.getSize() + 6);
            cout << "Enter New Information: " << endl;
            customer::update_customer(L[0]);
            break;
        case 6:
            cin.ignore();
            do
            {
                cout << "Enter Room ID:";
                getline(cin, ID);
                customer::find_idroom(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    cout << "ID does not exist!!!Try Again." << endl;
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            customer::change_user_name(ID);
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
    Room room;
    string ID;
    int month;
    List<Room> L;
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
        cout << "\t\t\t*\t|  1) View List Room           |                        *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t|  2) View List Empty Room     |                        *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t|  3) View List Rented Room    |                        *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*\t|  4) Find Room                |                        *" << endl;
        gotoXY(42, 20);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 21);
        cout << "\t\t\t*\t|  5) Add Room                 |                        *" << endl;
        gotoXY(42, 22);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 23);
        cout << "\t\t\t*\t|  6) Delete Room              |                        *" << endl;
        gotoXY(42, 24);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 25);
        cout << "\t\t\t*\t|  7) Edit Room                |                        *" << endl;
        gotoXY(42, 26);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 27);
        cout << "\t\t\t*\t|  8) Cancel Room              |                        *" << endl;
        gotoXY(42, 28);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 29);
        cout << "\t\t\t*\t|  9) Change Room              |                        *" << endl;
        gotoXY(42, 30);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 31);
        cout << "\t\t\t*\t|  0) Exit                     |                        *" << endl;
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
        switch (choice)
        {
        case 1:
            Room::display(L);
            box_room(3, 3, L);
            getch();
            break;
        case 2:
            Room::view_empty_room(L);
            box_roomempty(3, 3, L);
            getch();
            break;
        case 3:
            Room::view_rented_room(L);
            box_roomrent(3, 3, L);
            getch();
            break;
        case 4:
        {
            Room room;

            List<Room> foundRooms = room.find_room();

            if (foundRooms.getSize() > 0) {
                cout << "Found rooms matching the criteria:\n";
                for (int i = 0; i < foundRooms.getSize(); ++i) {
                    cout << foundRooms[i] << endl;
                }
            } else {
                cout << "No rooms found matching the criteria.\n";
            }
            getch();
            break;
        }

        case 5:
            cin >> room;
            room.add_room(1);
            break;
        case 6:
            cout << "Enter ID: ";
            cin >> ID;
            Room::delete_room(ID);
            break;
        case 7:
            // Room::display();
            Room::edit_room();
            break;
        case 8:
        {
            // hủy phòng : đặt trạng thái của phòng về false
            cout << "Enter Room ID To Want Cancel: " << endl;
            string room_id;
            cin >> room_id;
            Room::cancel_room(room_id);
            break;
        }
        case 9:
            // chuyển phòng
            break;
        default:
            break;
        }
        L.clear();
        // if (choice)
        //     getch();

    } while (choice != 0);
}
void menu_Manager_Payment()
{
    List<hoa_don> L;
    hoa_don object2;
    string ID;
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
        cout << "\t\t\t*\t|  1) View List Bill          |                        *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t|  2) View Paid Bill          |                        *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t|  3) View UnPaid Bill        |                        *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*\t|  4) Find Bill               |                        *" << endl;
        gotoXY(42, 20);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 21);
        cout << "\t\t\t*\t|  5) Paid Bill               |                        *" << endl;
        gotoXY(42, 22);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 23);
        cout << "\t\t\t*\t|  6) Edit Bill               |                        *" << endl;
        gotoXY(42, 24);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 25);
        cout << "\t\t\t*\t|  0) Exit                    |                        *" << endl;
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
        switch (choice)
        {
        case 1:
            hoa_don::display(L);
            box_hoadon(3, 3, L);
            getch();
            break;
        case 2:
            hoa_don::view_payment_room(L);
            box_hoadonpay(3, 3, L);
            gotoXY(0, 0);
            break;
        case 3:
            hoa_don::view_unpayment_room(L);
            box_hoadonunpay(3, 3, L);
            getch();
            break;
        case 4:
            cout << "Find Information BiLL: " << endl;
            if (!hoa_don::find_hoa_don(L))
            {
                cout << "Not Found!" << endl;
                getch();
                continue;
            }
            box_hoadon(3, 6, L);
            getch();
            break;
        case 5:
            cout << "List Of Unpaid Rooms: " << endl;
            hoa_don::view_unpayment_room(L);
            box_hoadonunpay(3, 3, L);
            gotoXY(0, 2 * L.getSize() + 6);
            L.clear();
            do
            {
                cout << "Enter ID Of Bill Want To Pay: ";
                getline(cin, ID);
                hoa_don::find_bill_id(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    cout << "ID does not exist!!!Try Again." << endl;
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            hoa_don::Pay_bill(L[0]);
            break;

        case 6:
            cout << "Find Information BiLL: " << endl;
            if (!hoa_don::find_hoa_don(L))
            {
                cout << "Not Found!" << endl;
                getch();
                continue;
            }
            box_hoadon(3, 5, L);
            gotoXY(0, 2 * L.getSize() + 8);
            L.clear();
            do
            {
                cout << "Enter BiLL ID: ";
                getline(cin, ID);
                hoa_don::find_bill_id(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    cout << "ID does not exist!!!Try Again." << endl;
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            system("cls");
            cout << "Infomation Current BiLL:" << endl;
            box_hoadon(3, 3, L);
            gotoXY(0, 2 * L.getSize() + 6);

            cout << "Enter New Information:" << endl;
            hoa_don::update_hoa_don(L[0]);
            break;
        default:
            break;
        }
        L.clear();
        // if (choice)
        //     getch();

    } while (choice != 0);
}
void menu_Manager_Dien_Nuoc()
{
    dien_nuoc object2;
    List<dien_nuoc> L;
    int choice, number;
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
        cout << "\t\t\t*\t|  1) View list Electric-Water        |                 *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t|  2) View List Unpaid Electric_Water |                 *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t|  3) View List Paid Electric_Water   |                 *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*\t|  4) Find Electric_Water             |                 *" << endl;
        gotoXY(42, 20);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 21);
        cout << "\t\t\t*\t|  5) Paid Electric_Water             |                 *" << endl;
        gotoXY(42, 22);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 23);
        cout << "\t\t\t*\t|  6) Edit Cost Electric              |                 *" << endl;
        gotoXY(42, 24);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 25);
        cout << "\t\t\t*\t|  7) Edit Cost Water                 |                 *" << endl;
        gotoXY(42, 26);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 27);
        cout << "\t\t\t*\t|  8) Edit Electric-Water             |                 *" << endl;
        gotoXY(42, 28);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 29);
        cout << "\t\t\t*\t|  0) Exit                            |                 *" << endl;
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
        while (choice < 0 || choice > 7)
        {
            xoa(42, 33, 50);
            gotoXY(42, 33);
            cout << "Enter Right Your Choice : ";
            cin >> choice;
        }
        system("cls");
        switch (choice)
        {
        case 1:
            dien_nuoc::display(L);
            box_diennuoc(3, 3, L);
            getch();
            break;
        case 2:
            dien_nuoc::view_unpaid_room(L);
            box_diennuocunpay(3, 3, L);
            getch();
            break;
        case 3:
            dien_nuoc::view_Paid_room(L);
            box_diennuocpay(3, 3, L);
            getch();
            break;
        case 4:
            cout << "Find Informatin Electric Water:" << endl;
            if (!dien_nuoc::find_dien_nuoc(L))
            {
                cout << "Not Found" << endl;
                getch();
                continue;
            }
            box_diennuoc(3, 5, L);
            getch();

            break;
        case 5:
            cout << "Informatin Unpaid Room:" << endl;
            dien_nuoc::view_unpaid_room(L);
            box_diennuocunpay(3, 3, L);
            gotoXY(0, 2 * L.getSize() + 6);
            cin.ignore();
            do
            {
                cout << "Enter ID Of Electric Water Want To Pay: ";
                getline(cin, ID);
                dien_nuoc::find_dien_nuoc_id(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    cout << "ID does not exist!!!Try Again." << endl;
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            dien_nuoc::Pay_dien_nuoc(L[0]);
            break;
        case 6:
            cout << "Current Cost Electric: " << dien_nuoc::getNewCostElectric() << endl;
            cin.ignore();
            cout << "Enter New Cost Electric:  ";
            getline(cin, ID);
            if (ID.size() == 0)
                break;
            number = Convert::str_to_int(ID);
            dien_nuoc::updateCostElectric(number);
            break;
        case 7:
            cout << "Current Cost Water: " << dien_nuoc::getNewCostWater() << endl;
            cin.ignore();
            cout << "Enter New Cost Water: ";
            getline(cin, ID);
            if (ID.size() == 0)
                break;
            number = Convert::str_to_int(ID);
            dien_nuoc::updateCostWater(number);
        case 8:
            cout << "Find Informatin Electric Water:" << endl;
            if (!dien_nuoc::find_dien_nuoc(L))
            {
                cout << "Not Found!" << endl;
                getch();
                continue;
            }
            box_diennuoc(3, 5, L);
            gotoXY(0, 2 * L.getSize() + 8);
            L.clear();
            do
            {
                cout << "Enter Electric Water ID: ";
                getline(cin, ID);
                dien_nuoc::find_dien_nuoc_id(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    cout << "ID does not exist!!!Try Again." << endl;
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;

            system("cls");

            cout << "Information Current Electric_Water: " << endl;
            // tin diem nuoc
            box_diennuoc(3, 3, L);
            gotoXY(0, 2 * L.getSize() + 6);
            // dien_nuoc::display(L);

            cout << "Information New Electric_Water: " << endl;
            dien_nuoc::update_dien_nuoc(L[0]);
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
    int startYear, startMonth, startDay, endYear, endMonth, endDay; // Declare variables

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
        cout << "\t\t\t*\t|  1) Calculate Revenue By Month      |                 *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t|  2) Calculate Revenue By Year       |                 *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t|  3) Calculate revenue by time period|                 *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*\t|  0) Exit                            |                 *" << endl;
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

        switch (choice)
        {
        case 1:
            do
            {
                cout << "Enter Month: ";
                cin >> month;

                // Kiểm tra giá trị hợp lệ cho tháng (1-12)
                if (month < 1 || month > 12)
                {
                    cout << "Invalid Month. Please enter a value between 1 and 12." << endl;
                }
            } while (month < 1 || month > 12);

            cout << "Enter Year: ";
            cin >> year;

            // Gọi hàm tính tổng doanh thu theo tháng
            revenue = doanhThu.tongDoanhThutheothoigian(year, month, 1, year, month, 31);

            // Hiển thị kết quả
            cout << "Total Revenue for " << month << "/" << year << ": " << revenue << endl;

            break;

        case 2:
            cout << "Enter Year: ";
            cin >> year;

            // Gọi hàm tính tổng doanh thu theo năm
            revenue = doanhThu.tongDoanhThutheothoigian(year, 1, 1, year, 12, 31);

            // Hiển thị kết quả
            cout << "Total Revenue for Year " << year << ": " << revenue << endl;

            break;

        case 3:
            do
            {
                cout << "Enter Start Date (YYYY MM DD): ";
                cin >> startYear >> startMonth >> startDay;

                // Kiểm tra giá trị hợp lệ cho ngày và tháng
                if (!Datetime::isValidDate(startYear, startMonth, startDay))
                {
                    cout << "Invalid Date. Please enter a valid date." << endl;
                }
            } while (!Datetime::isValidDate(startYear, startMonth, startDay));

            do
            {
                cout << "Enter End Date (YYYY MM DD): ";
                cin >> endYear >> endMonth >> endDay;

                // Kiểm tra giá trị hợp lệ cho ngày và tháng
                if (!Datetime::isValidDate(endYear, endMonth, endDay))
                {
                    cout << "Invalid Date. Please enter a valid date." << endl;
                }
            } while (!Datetime::isValidDate(endYear, endMonth, endDay));

            // Gọi hàm tính tổng doanh thu theo khoảng thời gian
            revenue = doanhThu.tongDoanhThutheothoigian(startYear, startMonth, startDay, endYear, endMonth, endDay);

            // Hiển thị kết quả
            cout << "Total Revenue from " << startDay << "/" << startMonth << "/" << startYear
                 << " to " << endDay << "/" << endMonth << "/" << endYear << ": " << revenue << endl;

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
    int choice;
    problem obj;
    List<problem> L;
    string ID;
    Datetime time;
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
        cout << "\t\t\t*\t|  1) View List Problem          |                      *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t|  2) View List Solved Problem   |                      *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t|  3) View List UnSolved Problem |                      *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*\t|  4) Confirm Solve Problem      |                      *" << endl;
        gotoXY(42, 20);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 21);
        cout << "\t\t\t*\t|  0) Exit                       |                      *" << endl;
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

        switch (choice)
        {
        case 1:
            problem::display(L);
            box_problem(3, 3, L);
            getch();
            break;

        case 2:
            problem::view_solved_problem(L);
            box_solvedproblem(3, 3, L);
            getch();
            break;

        case 3:
            problem::view_unsolved_problem(L);
            box_unsolvedproblem(3, 3, L);
            getch();
            break;
        case 4:

            cout << "Information Of UnSolved Problem:" << endl;
            problem::view_unsolved_problem(L);
            box_problem(3, 3, L);
            gotoXY(0, 2 * L.getSize() + 6);
            L.clear();
            cin.ignore();
            do
            {
                cout << "Enter Problem ID:";
                getline(cin, ID);
                problem::find_idproblem(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    cout << "ID Already Exists!!!Try Again." << endl;
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            cout << "Do you want to Confirm?(Yes/No): ";
            cin >> ID;
            if (ID == "Yes")
            {
                L[0].set_finishdate(time);
                L[0].set_status(true);
                problem::solve(L[0]);
            }
            break;
        default:
            break;
        }
        L.clear();
        // if (choice)
        //     getch();
    } while (choice != 0);
}


void menu_admin(admin &object1)
{
    int choice;
    do
    {
        system("cls");

        string content = "**** Welcome To Admin iloveuhiuhiu ***";
        khung(0, 0, 0, 0, content);
        gotoXY(42, 10);
        cout << "\t\t\t*****************************************************************" << endl;
        gotoXY(42, 11);
        cout << "\t\t\t*\t                                                        *" << endl;
        gotoXY(42, 12);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 13);
        cout << "\t\t\t*\t|  1) Manager Customer             |                    *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t|  2) Manager Room                 |                    *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t|  3) Manager Electric-Water       |                    *" << endl;
        gotoXY(42, 18);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 19);
        cout << "\t\t\t*\t|  4) Manager Payment              |                    *" << endl;
        gotoXY(42, 20);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 21);
        cout << "\t\t\t*\t|  5) Calculate Revenue            |                    *" << endl;
        gotoXY(42, 22);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 23);
        cout << "\t\t\t*\t|  6) Manager Problem              |                    *" << endl;
        gotoXY(42, 24);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 25);
        cout << "\t\t\t*\t|  0) Logout                       |                    *" << endl;
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
        case 6:
            menu_problem();
            break;
        default:
            break;
        }
        // if (choice)
        //     getch();
    } while (choice != 0);
}
void menu_login()
{
    string user_name, password;
    admin object1;
    customer object2;

    int role = 0;
    cin.ignore();
    do
    {
        cout << "Enter User Name: ";
        getline(cin, user_name);
        cout << "Enter Password: ";
        hide_password_input(password);
        cout << endl;
        object1.set_user_name(user_name);
        object1.set_password(password);

        if (object1.login())
        {
            role = 1;
            break;
        }
        object2.set_user_name(user_name);
        object2.set_password(password);
        if (object2.login())
        {
            role = 2;
            break;
        }
        user_name.clear();
        password.clear();
        cout << "Username or password is incorrect. Please try again!!!" << endl;
        getch();
        cin.ignore();
        system("cls");
    } while (!role);
    if (role == 1)
        menu_admin(object1);
    else
        menu_user(object2);
}
void menu()
{
    List<Room> L;
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
        cout << "\t\t\t*\t|  1) Login                     |                       *" << endl;
        gotoXY(42, 14);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 15);
        cout << "\t\t\t*\t|  2) View Empty Room           |                       *" << endl;
        gotoXY(42, 16);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 17);
        cout << "\t\t\t*\t|  0) Exit                      |                       *" << endl;
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
            Room::view_empty_room(L);
            box_roomempty(3, 3, L);
            getch();
        default:
            break;
        }
        L.clear();
        // if (choice)
        //     getch();
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
