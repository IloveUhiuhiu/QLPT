#include "admin.h"
#include "customer.h"
#include "DoanhThu.h"
#include "problem.h"
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
        gotoXY(x, min(j,40));
        cout << char(makitu) << char(makitu);
    }
}
void khungbang()
{   
    int mau = 6;
    ThanhNgang(1, 1, 154, mau, 9, 177); // ngang tren
    ThanhNgang(1, 38, 154, mau, 9, 177);
    ThanhTru(1, 1, 38, mau, 9, 177);   // tru trái
    ThanhTru(154, 1, 38, mau, 9, 177); // trụ phải
    setColor(0, 14);
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
    w.push_back(17);
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

void menu_user(customer &object2)
{
    int choice;
    Room room;
    dien_nuoc dn;
    hoa_don hd;
    problem p;
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
        cout << "\t\t\t*\t|  5) Add Problem                     |                 *" << endl;
        gotoXY(42, 21);
        cout << "			*    	                                                        *" << endl;
        gotoXY(42, 22);
        cout << "\t\t\t*\t|  0) Logout                          |                 *" << endl;
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
            gotoXY(61,4);cout << "***Information Of Customer***" << endl;
            customer::find_idroom(object2.get_room_id(), L);
            box_customer(4, 6, L);
            getch();
            break;
        case 2:
            gotoXY(63,4); cout << "***Information Of Room***" << endl;
            Room::find_idroom(object2.get_room_id(), L1);
            box_room(50, 6, L1);
            getch();
            break;
        case 3:
            gotoXY(59,4);cout << "***Information Of Electric Water***";
            dien_nuoc::find_dien_nuoc_id(dn.find_max_dien_nuoc_id(), L2);
            box_diennuoc(5, 6, L2);
            getch();
            break;
        case 4:
            gotoXY(64,4);cout << "***Information Of BiLL***";
            hoa_don::find_bill_id(hd.find_max_bill_id(), L3);
            box_hoadon(49, 6, L3);
            getch();
            break;
        case 5: 
            
            gotoXY(62,4);cout << "***Add Information Problem***";
            cin >> p;
            p.add_problem();
            
            gotoXY(4,7);cout << "Add Problem Successful.";
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
        khungbang();
        switch (choice)
        {
        case 1:
            gotoXY(63,4);cout << "***Information Of All Customer***" << endl;
            cout << endl;
            customer::display(L);
            box_customer(4, 6, L);
            getch();
            break;
        case 2:
            // add
            gotoXY(59,4);cout << "***Enter Information New Customer***";
            cin >> object2;
            object2.set_customer_id(Convert::CreateID("customer.txt"));
            object2.add_customer();
            break;
        case 3:
            gotoXY(61,4);cout << "***Find Information Customer***" << endl;
            if (!customer::find_customer(L))
            {
                cout << "Not Found!" << endl;
                getch();
                continue;
            }
            else
            {
                box_customer(4, 13, L);
                gotoXY(0, 0);
            }
            getch();
            break;
        case 4:
            gotoXY(60,4);cout << "***Delete Information Customer***" << endl;
            if (!customer::find_customer(L))
            {
                cout << "Not Found!" << endl;
                getch();
                continue;
            }
            else
            {
                box_customer(4, 13, L);
                
            }
            do
            {   
                xoa(4, 2 * L.getSize() + 16,40);
                xoa(4, 2 * L.getSize() + 17,40);
                gotoXY(4, 2 * L.getSize() + 16);cout << "Enter Customer ID:";
                getline(cin, ID);
                customer::find_idcustomer(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 2 * L.getSize() + 17);cout << "ID does not exist!!!Try Again." << endl;
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            customer::delete_customer(ID);
            break;
        case 5:
            gotoXY(61,4);cout << "***Edit Information Customer***" << endl;
            if (!customer::find_customer(L))
            {
                cout << "Not Found!" << endl;
                continue;
            }
            box_customer(3, 13, L);
            
            L.clear();
            do
            {   
                xoa(4, 2 * L.getSize() + 16,40);
                xoa(4, 2 * L.getSize() + 17,40);
                gotoXY(4, 2 * L.getSize() + 16);cout << "Enter Customer ID:";
                getline(cin, ID);
                customer::find_idcustomer(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 2 * L.getSize() + 17);cout << "ID does not exist!!!Try Again." << endl;
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            system("cls");
            khungbang();
            gotoXY(4,58);cout << "***Information Current Customer***" << endl;
            box_customer(4, 6, L);
            gotoXY(4, 2 * L.getSize() + 9);cout << "Enter New Information: " << endl;
            customer::update_customer(L[0],2*L.getSize()+9);
            break;
        case 6:
            gotoXY(68,4); cout << "***Change Password***";
            cin.ignore();
            do
            {   xoa(4,5,40);
                xoa(4,6,40);
                gotoXY(4,5);cout << "Enter Room ID:";
                getline(cin, ID);
                customer::find_idroom(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4,6);cout << "ID does not exist!!!Try Again." << endl;
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
    int len;
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
        khungbang();
        switch (choice)
        {
        case 1:
            gotoXY(65,4); cout << "***Information Of All Room***" << endl;
            Room::display(L);
            box_room(50, 6, L);
            getch();
            break;
        case 2:
            gotoXY(62,4); cout << "***Information Of All Empty Room***" << endl;
            Room::view_empty_room(L);
            box_roomempty(57, 6, L);
            getch();
            break;
        case 3:
            gotoXY(62,4); cout << "***Information Of All Rented Room***" << endl;
            Room::view_rented_room(L);
            box_roomrent(57, 6, L);
            getch();
            break;
        case 4:
        {
            gotoXY(64,4);cout << "***Find Information Room***" << endl;
            cin.ignore();
            Room::find_room(L);
            if (L.getSize() > 0)
            {
                box_room(50, 9, L);
            }
            else
            {
                cout << "Not Found" << endl;
            }
            getch();
            break;
        }

        case 5:
            gotoXY(64,4);cout << "***Add Information Room***";
            cin >> room;
            room.add_room(1);
            break;
        case 6:
            gotoXY(64,4);cout << "***Delete Room***";
            cin.ignore();
            gotoXY(4,5);cout << "Enter Room ID To Want Delete: ";
            getline(cin,ID);
            if (ID.size()) Room::delete_room(ID);
            gotoXY(4,6);cout << "Delete Successful.";
            getch();
            break;
        case 7:
            gotoXY(64,4);cout << "***Edit Information Room***";
            cin.ignore();
            Room::find_room(L);
            if (!L.getSize())
            {
                cout << "Not Found!" << endl;
                getch();
                continue;
            }
            box_room(50, 9, L);
            len = L.getSize();
            L.clear();
            do
            {   
                xoa(4, 2 * len + 11,40);
                xoa(4, 2 * len + 12,40);
                gotoXY(4, 2 * len + 11);cout << "Enter Room ID: ";
                getline(cin, ID);
               Room::find_idroom(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 2 * len + 12);cout << "ID does not exist!!!Try Again." << endl;
                    getch();
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;

            system("cls");
            khungbang();
            gotoXY(4,5);cout << "Information Current Room: " << endl;
            box_room(50, 7, L);
            gotoXY(4, 2 * L.getSize() + 10);
            cout << "Information New Room: " << endl;
            Room::update_room(L[0],2 * L.getSize() + 10);
            getch();
            break;
        case 8:
        {   
            gotoXY(69,4);cout <<"***Cancel Room***";
            cin.ignore();
            // hủy phòng : đặt trạng thái của phòng về false
            gotoXY(4,5);cout << "Enter Room ID To Want Cancel: ";
            getline(cin,ID);
            if (ID.size()) Room::cancel_room(ID);
            gotoXY(4,6);cout << "Cancel Successful.";
            getch();
            break;
        }
        case 9:
            Room::change_room();
            getch();
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
        khungbang();
        switch (choice)
        {
        case 1:
            gotoXY(66,4);cout << "***Information Of All BiLL***";
            hoa_don::display(L);
            // cout << L.getSize() << endl;
            box_hoadon(49, 6, L);
            getch();
            break;
        case 2:
            gotoXY(64,4);cout << "***Information Of All Pay BiLL***";
            hoa_don::view_payment_room(L);
            box_hoadonpay(49, 6, L);
            getch();
            break;
        case 3:
            gotoXY(64,4);cout << "***Information Of All UnPay BiLL***";
            hoa_don::view_unpayment_room(L);
            box_hoadonunpay(49, 6, L);
            getch();
            break;
        case 4:
            gotoXY(64,4);cout << "***Find Information BiLL***" << endl;
            if (!hoa_don::find_hoa_don(L))
            {
                gotoXY(4,5);cout << "Not Found!" << endl;
                getch();
                continue;
            }
            box_hoadon(49, 9, L);
            getch();
            break;
        case 5:
            gotoXY(70,4);cout << "***Pay BiLL***";
            gotoXY(4,5);cout << "List Of Unpaid Rooms: " << endl;
            hoa_don::view_unpayment_room(L);
            
            box_hoadonunpay(49,6, L);
            getch();
            len = L.getSize();
            L.clear();
            cin.ignore();
            do
            {   
                xoa(4,2*len+9,40);
                xoa(4,2*len+10,40);
                
                gotoXY(4, 2 * len + 9);cout << "Enter ID Of Bill Want To Pay: ";
                getline(cin, ID);
                hoa_don::find_bill_id(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 2 * len + 10);cout << "ID does not exist!!!Try Again." << endl;
                    getch();
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            hoa_don::Pay_bill(L[0], 2 * len + 10);
            break;

        case 6:
            gotoXY(67,4);cout << "***Edit Information BiLL***" << endl;
            if (!hoa_don::find_hoa_don(L))
            {
                cout << "Not Found!" << endl;
                getch();
                continue;
            }
            box_hoadon(49, 9, L);
            len = L.getSize();
            L.clear();
            do
            {   
                xoa(4,2*len+12,40);
                xoa(4,2*len+13,40);
                gotoXY(4,2*len+12);cout << "Enter BiLL ID: ";
                
                getline(cin, ID);
                hoa_don::find_bill_id(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4,2*len+13);cout << "ID does not exist!!!Try Again." << endl;
                    getch();
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            system("cls");
            khungbang();
            gotoXY(4,4);cout << "Infomation Current BiLL:" << endl;
            box_hoadon(49, 6, L);
            gotoXY(4, 2 * L.getSize() + 9);
            cout << "Enter New Information:" << endl;
            hoa_don::update_hoa_don(L[0],2 * L.getSize() + 9);
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
    int choice, number,len;
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
            gotoXY(61,4);cout << "***Information Of All Electric Water***";
            cout << L.getSize() << endl;
            dien_nuoc::display(L);
            box_diennuoc(5, 6, L);
            getch();
            break;
        case 2:
            gotoXY(58,4);cout << "***Information Of UnPaid Electric Water***";
            dien_nuoc::view_unpaid_room(L);
            cout << L.getSize() << endl;
            box_diennuocunpay(9, 6, L);
            getch();
            break;
        case 3:
            gotoXY(60,4);cout << "***Information Of Paid Electric Water***";
            dien_nuoc::view_Paid_room(L);
            cout << L.getSize() << endl;
            box_diennuocpay(9, 6, L);
            getch();
            break;
        case 4:
            gotoXY(60,4);cout << "***Find Informatin Electric Water***" << endl;
            if (!dien_nuoc::find_dien_nuoc(L))
            {
                cout << "Not Found" << endl;
                getch();
                continue;
            }
            box_diennuoc(5, 10, L);
            getch();

            break;
        case 5:
            gotoXY(66,4);cout << "***Pay Electric Water***";
            gotoXY(4,5);cout << "Informatin Unpaid Room:" << endl;
            dien_nuoc::view_unpaid_room(L);
            box_diennuocunpay(5, 7, L);
            len = L.getSize();
            gotoXY(0, 2 * len + 9);
            cin.ignore();
            do
            {   
                xoa(4,2 * len + 10,40);
                xoa(4,2 * len + 11,40);
                gotoXY(4, 2 * len + 10);cout << "Enter ID Of Electric Water Want To Pay: ";
                getline(cin, ID);
                dien_nuoc::find_dien_nuoc_id(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 2 * len + 11);cout << "ID does not exist!!!Try Again." << endl;
                    getch();
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            dien_nuoc::Pay_dien_nuoc(L[0],2*len+10);
            break;
        case 6:
            gotoXY(66,4);cout << "***Edit Cost Electric***";
            gotoXY(4,5);cout << "Current Cost Electric: " << dien_nuoc::getNewCostElectric() << endl;
            cin.ignore();
            gotoXY(4,6);cout << "Enter New Cost Electric:  ";
            getline(cin, ID);
            if (ID.size() == 0)
                break;
            number = Convert::str_to_int(ID);
            dien_nuoc::updateCostElectric(number);
            break;
        case 7:
            gotoXY(67,4);cout << "***Edit Cost Water***";
            gotoXY(4,5);;cout << "Current Cost Water: " << dien_nuoc::getNewCostWater() << endl;
            cin.ignore();
            gotoXY(4,6);cout << "Enter New Cost Water: ";
            getline(cin, ID);
            if (ID.size() == 0)
                break;
            number = Convert::str_to_int(ID);
            dien_nuoc::updateCostWater(number);
            break;
        case 8:
            gotoXY(60,4);cout << "***Edit Information Electric Water***";
            if (!dien_nuoc::find_dien_nuoc(L))
            {
                cout << "Not Found!" << endl;
                getch();
                continue;
            }
            box_diennuoc(5, 10, L);
            len = L.getSize();
            L.clear();
            do
            {   xoa (4,2*len+13,40);
                xoa(4,2*len+14,40);
                gotoXY(4,2*len+13);
                cout << "Enter Electric Water ID: ";
                getline(cin, ID);
                dien_nuoc::find_dien_nuoc_id(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4,2*len+14);cout << "ID does not exist!!!Try Again." << endl;
                    getch();
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;

            system("cls");
            khungbang();
            gotoXY(4,4);cout << "Information Current Electric_Water: " << endl;
            // tin diem nuoc
            box_diennuoc(5, 6, L);
            gotoXY(4, 2 * L.getSize() + 9);
            // dien_nuoc::display(L);

            cout << "Information New Electric_Water: " << endl;
            dien_nuoc::update_dien_nuoc(L[0],2*L.getSize()+9);
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
    Datetime time;
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
        khungbang();
        switch (choice)
        {
        case 1:
            gotoXY(62,4);cout << "***Calculate Revenue By Month***";
            do
            {   
                xoa(4,5,40);
                xoa(4,6,40);
                gotoXY(4,5);cout << "Enter Month: ";
                cin >> month;

                // Kiểm tra giá trị hợp lệ cho tháng (1-12)
                if (month < 1 || month > 12)
                {
                    gotoXY(4,6);cout << "Invalid Month. Please enter a value between 1 and 12." << endl;
                    getch();
                }
            } while (month < 1 || month > 12);

            gotoXY(4,6);cout << "Enter Year: ";
            cin >> year;

            // Gọi hàm tính tổng doanh thu theo tháng
            revenue = doanhThu.tongDoanhThutheothoigian(year, month, 1, year, month, 31);

            // Hiển thị kết quả
            gotoXY(4,7);cout << "Total Revenue for " << month << "/" << year << ": " << revenue << endl;
            getch();
            break;

        case 2:
            gotoXY(62,4);cout << "***Calculate Revenue By Year***";
            gotoXY(4,5);cout << "Enter Year: ";
            cin >> year;

            // Gọi hàm tính tổng doanh thu theo năm
            revenue = doanhThu.tongDoanhThutheothoigian(year, 1, 1, year, 12, 31);

            // Hiển thị kết quả
            gotoXY(4,6);cout << "Total Revenue for Year " << year << ": " << revenue << endl;
            getch();
            break;

        case 3:
            gotoXY(60,4);cout << "***Calculate revenue by time periodr***";
            do
            {
                cin.ignore();
                xoa(4,5,40);
                xoa(4,6,40);
                gotoXY(4,5);cout << "Enter Start Date (yy-mm-dd): ";
                getline(cin, startDate);
                time = Datetime::Split(startDate);
                startYear = time.get_years();
                startMonth = time.get_months();
                startDay = time.get_days();
                // Kiểm tra giá trị hợp lệ cho ngày và tháng
                if (!Datetime::isValidDate(startYear, startMonth, startDay))
                {
                    gotoXY(4,6);cout << "Invalid Date. Please Enter a Valid Date." << endl;
                }
            } while (!Datetime::isValidDate(startYear, startMonth, startDay));

            do
            {   
                xoa(4,6,40);
                xoa(4,7,40);
                gotoXY(4,6);cout << "Enter End Date (yy-mm-dd): ";
                getline(cin, endDate);
                time = Datetime::Split(endDate);
                endYear = time.get_years();
                endMonth = time.get_months();
                endDay = time.get_days();
                // Kiểm tra giá trị hợp lệ cho ngày và tháng
                if (!Datetime::isValidDate(endYear, endMonth, endDay))
                {
                    gotoXY(4,7);cout << "Invalid Date. Please Enter a Valid Date." << endl;
                }
            } while (!Datetime::isValidDate(endYear, endMonth, endDay));

            // Gọi hàm tính tổng doanh thu theo khoảng thời gian
            revenue = doanhThu.tongDoanhThutheothoigian(startYear, startMonth, startDay, endYear, endMonth, endDay);

            // Hiển thị kết quả
            gotoXY(4,7);cout << "Total Revenue from " << startYear << "-" << startMonth << "-" << startDate
                 << " to " << endYear << "-" << endMonth << "-" << endDate << ": " << revenue << endl;
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
    int choice,len;
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
        khungbang();
        switch (choice)
        {
        case 1:
            gotoXY(66,4);cout << "***View List Problem***";
            problem::display(L);
            box_problem(28, 6, L);
            getch();
            break;

        case 2:
            gotoXY(62,4);cout << "***View List Solved Problem***";
            problem::view_solved_problem(L);
            box_solvedproblem(30, 6, L);
            getch();
            break;

        case 3:
            gotoXY(62,4);cout << "***View List UnSolved Problem***";
            problem::view_unsolved_problem(L);
            box_unsolvedproblem(30, 6, L);
            getch();
            break;
        case 4:
            gotoXY(66,4);cout << "***Confirm Solve Problem***";
            gotoXY(4,5);cout << "Information Of UnSolved Problem:" << endl;
            problem::view_unsolved_problem(L);
            box_problem(28, 7, L);
            len = 2*L.getSize();
            L.clear();
            cin.ignore();
            do
            {   
                xoa(4,2*len+10,40);
                xoa(4,2*len+11,40);
                gotoXY(4, 2 * len + 10);cout << "Enter Problem ID:";
                getline(cin, ID);
                problem::find_idproblem(ID, L);
                if (ID.size() && L.getSize() == 0)
                {
                    gotoXY(4, 2 * len + 11);cout << "ID Already Exists!!!Try Again." << endl;
                    getch();
                }
            } while (ID.size() && L.getSize() == 0);
            if (ID.size() == 0)
                break;
            gotoXY(4, 2 * len + 11);cout << "Do you want to Confirm?(Yes/No): ";
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
    {   ThanhNgang(53,13, 50, 6, 10, 177);// ngang tren
        ThanhTru(53,13,17, 6, 10, 177);// tru trai
        ThanhNgang(55,29, 50, 6, 10, 177);// ngang duoi
        ThanhTru(103,13,17, 6, 10, 177);// tru phải
        ThanhNgang(53,17, 50, 6, 10, 177);
        setColor(0, 14);
        gotoXY(75,15); cout << "LOGIN";
        // gotoXY(72,24); cout << "USERNAME: "; //goto(82,24)
        // gotoXY(72,26); cout << "PASSWORD: "; //goto(82,26)
        // gotoXY(0,0);
        // xoa(55,19,40);
        gotoXY(56,19);cout << "Enter User Name: ";
        getline(cin, user_name);
        // xoa(55,21,40);
        gotoXY(56,21);cout << "Enter Password: ";
        hide_password_input(password);
        cout << endl;
        object1.set_user_name(user_name);
        object1.set_password(password);

        if (object1.login())
        {
            role = 1;
            for (int j = 0; j <= 100; j = j + 25)
            {
                gotoXY(56,27); cout << "Checking Information"<<string(j%3+1,'.') << " " << j << "%" << endl;
                sleep(1);
                xoa(56,27,45);
            }
            gotoXY(56,27);cout << "Login successfully!" << endl;
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
                cout << "Checking Information"<<string(j%3+1,'.') << " " << j << "%" << endl;
                sleep(1);
                xoa(56,27,45);
            }
            gotoXY(56,27);cout << "Login successfully!" << endl;
            getch();
            break;
        }
        user_name.clear();
        password.clear();
        gotoXY(56,27);cout << "Username or password is incorrect.Try again." << endl;
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
            system("cls");
            khungbang();
            gotoXY(62,4); cout << "***Information Of All Empty Room***" << endl;
            Room::view_empty_room(L);
            box_roomempty(57, 6, L);
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
