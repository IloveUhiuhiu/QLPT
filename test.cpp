#include "admin.h"
#include "customer.h"
#include "DoanhThu.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include <list>  // Include the appropriate header for your List class

=======
>>>>>>> parent of 8272935 (okok)
=======
>>>>>>> parent of 8272935 (okok)
void TextColor(int textColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor & 0x0F);
}
void gotoXY(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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
    box(3, 3, w, n + 1, 4, content);
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
    box(3, 3, w, n + 1, 3, content);
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
    box(3, 3, w, n + 1, 3, content);
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
    List<customer> L;
    List<Room> L1;
    List<dien_nuoc> L2;
    List<hoa_don> L3;
    do
    {
        system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Wellcome Customer" << setw(8) << object2.get_user_name() << " ****                   *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View Info Customer       |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) View Info Room           |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) View Info Electric-Water |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) View Info Payment        |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Logout                   |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl;
        cout << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 4)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        switch (choice)
        {
        case 1:
            customer::find_idroom(object2.get_room_id(), L);
            box_customer(3, 3, L);
            gotoXY(0, 0);
            break;
        case 2:
            Room::find_idroom(object2.get_room_id(), L1);
            box_room(3, 3, L1);
            gotoXY(0, 0);
            break;
        case 3:
            dien_nuoc::find_dien_nuoc_id(dn.find_max_dien_nuoc_id(), L2);
            box_diennuoc(3, 3, L2);
            gotoXY(0, 0);
            break;
        case 4:
            hoa_don::find_bill_id(hd.find_max_bill_id(), L3);
            box_hoadon(3, 3, L3);
            gotoXY(0, 0);
            break;
        default:
            break;
        }
        L.clear();
        L1.clear();
        L2.clear();
        if (choice == 0)
            break;
        system("pause");

    } while (choice != 0);
}

void menu_Manager_Customer()
{
    List<customer> L;
    customer object2;
    string ID;
    Room room;
    int choice;
    do
    {
        system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Customer Manager ****                  *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View List Customer  |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Add Customer        |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Find Customer       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Delete Customer     |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Edit Customer       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  6) Change User_Password|                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 6)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        switch (choice)
        {
        case 1:
            customer::display(L);
            box_customer(3, 3, L);
            gotoXY(0, 0);
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
                continue;
            }
            else
            {
                box_customer(3, 10, L);
                gotoXY(0, 0);
            }
            break;
        case 4:
            cout << "Find Information Customer: " << endl;
            if (!customer::find_customer(L))
            {
                cout << "Not Found!" << endl;
                continue;
            }
            else
            {
                box_customer(3, 10, L);
                gotoXY(0, 2 * L.getSize() + 13);
            }
            cout << "Enter Customer ID: ";
            cin >> ID;
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
            cout << "Informatin Current Customer: " << endl;
            box_customer(3, 3, L);
            gotoXY(0, 2 * L.getSize() + 6);
            cout << "Enter New Information: " << endl;
            customer::update_customer(L[0]);
            break;
        case 6:
            cout << "Enter Room ID: ";
            cin >> ID;
            customer::change_user_name(ID);
            break;
        default:
            break;
        }
        L.clear();
        if (choice == 0)
            break;
        system("pause");

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
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Room Manager ****                      *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View List Room           |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) View List Empty Room     |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) View List Rented Room    |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Find Room                |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Add Room                 |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  6) Delete Room              |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  7) Edit Room                |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  8) Cancel Room              |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  9) Change Room              |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                     |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 9)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        switch (choice)
        {
        case 1:
            Room::display(L);
            box_room(3, 3, L);
            gotoXY(0, 0);
            break;
        case 2:
            Room::view_empty_room(L);
            box_roomempty(3, 3, L);
            gotoXY(0, 0);
            break;
        case 3:
            Room::view_rented_room(L);
            box_roomrent(3, 3, L);
            gotoXY(0, 0);
            break;
        case 4:
        {
<<<<<<< HEAD
<<<<<<< HEAD
            Room room;

            List<Room> foundRooms = room.find_room();

            if (foundRooms.getSize() > 0) {
                cout << "Found rooms matching the criteria:\n";
                for (int i = 0; i < foundRooms.getSize(); ++i) {
                    cout << foundRooms[i] << endl;
                }
            } else {
                cout << "No rooms found matching the criteria.\n";
=======
=======
>>>>>>> parent of 8272935 (okok)
            cout << "Choose search type:" << endl;
            cout << "1. By Room ID" << endl;
            cout << "2. By Kind of Room(A , B , C)" << endl;

            int searchType;
            cin >> searchType;

            cout << "Enter search term: ";
            string searchTerm;
            cin >> searchTerm;

            Room foundRoom = Room::find_room(searchTerm);

            if (!foundRoom.getRoomID().empty())
            {
                cout << "Room found:" << endl;
                cout << foundRoom << endl;
            }
            else
            {
                cout << "Room not found." << endl;
<<<<<<< HEAD
>>>>>>> parent of 8272935 (okok)
=======
>>>>>>> parent of 8272935 (okok)
            }

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
        if (choice == 0)
            break;
        system("pause");

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
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Payment Manager ****                 *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View List Bill          |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) View Paid Bill          |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) View UnPaid Bill        |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Find Bill               |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Add Bill                |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  6) Paid Bill               |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  7) Edit Bill               |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                    |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 7)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        switch (choice)
        {
        case 1:
            hoa_don::display(L);
            box_hoadon(3, 3, L);
            gotoXY(0, 0);
            break;
        case 2:
            hoa_don::view_payment_room(L);
            box_hoadonpay(3, 3, L);
            gotoXY(0, 0);
            break;
        case 3:
            hoa_don::view_unpayment_room(L);
            box_hoadonunpay(3, 3, L);
            gotoXY(0, 0);
            break;
        case 4:
            cout << "Find Information BiLL: " << endl;
            if (!hoa_don::find_hoa_don(L))
            {
                cout << "Not Found!" << endl;
                continue;
            }
            box_hoadon(3, 6, L);
            gotoXY(0, 0);
            break;
        case 5:
            cout << "Enter Information BiLL:" << endl;
            cin >> object2;
            object2.set_bill_id(Convert::CreateID("hoa_don.txt"));
            object2.add_hoa_don();
            break;
        case 6:
            cout << "List Of Unpaid Rooms: " << endl;
            hoa_don::view_unpayment_room(L);
            box_hoadonunpay(3, 3, L);
            gotoXY(0, 2 * L.getSize() + 6);
            cout << "Enter ID Of Bill Want To Pay: ";
            cin >> ID;
            hoa_don::find_bill_id(ID, L);
            hoa_don::Pay_bill(L[0]);
            break;

        case 7:
            cout << "Find Information BiLL: " << endl;
            if (!hoa_don::find_hoa_don(L))
            {
                cout << "Not Found!" << endl;
                continue;
            }
            box_hoadon(3, 5, L);
            gotoXY(0, 2 * L.getSize() + 8);
            L.clear();
            cout << "Enter BiLL ID:";
            cin >> ID;
            system("cls");
            cout << "Infomation Current BiLL:" << endl;
            hoa_don::find_bill_id(ID, L);
            box_hoadon(3, 3, L);
            gotoXY(0, 2 * L.getSize() + 6);
            cout << "Enter New Information:" << endl;
            hoa_don::update_hoa_don(L[0]);
            break;
        default:
            break;
        }
        L.clear();
        if (choice == 0)
            break;
        system("pause");

    } while (choice != 0);
}
void menu_Manager_Dien_Nuoc()
{
    dien_nuoc object2;
    List<dien_nuoc> L;
    int choice;
    string ID;
    do
    {
        system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Electric-Water Manager ****            *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View list Electric-Water        |                 *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) View List Unpaid Electric_Water |                 *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) View List Paid Electric_Water   |                 *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Find Electric_Water             |                 *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Paid Electric_Water             |                 *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  6) Add Electric-Water              |                 *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  7) Edit Electric-Water             |                 *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                            |                 *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 7)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        switch (choice)
        {
        case 1:
            dien_nuoc::display(L);
            box_diennuoc(3, 3, L);
            gotoXY(0, 0);
            break;
        case 2:
            dien_nuoc::view_unpaid_room(L);
            box_diennuocunpay(3, 3, L);
            gotoXY(0, 0);
            break;
        case 3:
            dien_nuoc::view_Paid_room(L);
            box_diennuocpay(3, 3, L);
            gotoXY(0, 0);
            break;
        case 4:
            if (!dien_nuoc::find_dien_nuoc(L))
            {
                cout << "Not Found" << endl;
                continue;
            }
            box_diennuoc(3, 5, L);
            gotoXY(0, 0);

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
            cin >> object2;
            object2.set_dien_nuoc_id(Convert::CreateID("dien_nuoc.txt"));
            object2.add_dien_nuoc();
            break;
        case 7:
            cout << "Find Informatin Electric Water:" << endl;
            if (!dien_nuoc::find_dien_nuoc(L))
            {
                cout << "Not Found!" << endl;
                continue;
            }
            box_diennuoc(3, 3, L);
            gotoXY(0, 2 * L.getSize() + 6);
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
            L.clear();
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
        if (choice == 0)
            break;
        system("pause");
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
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Calculate Revenue ****                 *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) Calculate Revenue By Month      |                 *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Calculate Revenue By Year       |                 *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Calculate revenue by time period|                 *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                            |                 *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        while (choice < 0 || choice > 3)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }

        cout << "\n***********************" << endl;
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
<<<<<<< HEAD
<<<<<<< HEAD
            {
                cout << "Enter Start Date (YYYY MM DD): ";
                cin >> startYear >> startMonth >> startDay;

=======
=======
>>>>>>> parent of 8272935 (okok)
            {   
                cin.ignore();
                cout << "Enter Start Date (yy-mm-dd): ";
                getline(cin,startDate);
                time = Datetime::Split(startDate);
                startYear = time.get_years();
                startMonth = time.get_months();
                startDay = time.get_days();
>>>>>>> parent of 8272935 (okok)
                // Kiểm tra giá trị hợp lệ cho ngày và tháng
                if (!Datetime::isValidDate(startYear, startMonth, startDay))
                {
                    cout << "Invalid Date. Please enter a valid date." << endl;
                }
            } while (!Datetime::isValidDate(startYear, startMonth, startDay));

            do
            {
<<<<<<< HEAD
                cout << "Enter End Date (YYYY MM DD): ";
                cin >> endYear >> endMonth >> endDay;

=======
                cout << "Enter End Date (yy-mm-dd): ";
                getline(cin,endDate);
                time = Datetime::Split(endDate);
                endYear = time.get_years();
                endMonth = time.get_months();
                endDay = time.get_days();
>>>>>>> parent of 8272935 (okok)
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

        if (choice == 0)
            break;

        system("pause");
    } while (choice != 0);
}
<<<<<<< HEAD

=======
>>>>>>> parent of 8272935 (okok)

void menu_admin(admin &object1)
{
    int choice;
    do
    {
        system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Admin " << setw(10) << object1.get_user_name() << " ****                *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) Manager Customer             |                    *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Manager Room                 |                    *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Manager Electric-Water       |                    *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Manager Payment              |                    *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Calculate Revenue            |                    *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Logout                       |                    *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        int year, month, revenue;
        while (choice < 0 || choice > 5)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
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
        default:
            break;
        }
        if (choice == 0)
            break;
        system("pause");
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
        system("pause");
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
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To System Motel Room Manager ****         *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) Login                     |                       *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) View Empty Room           |                       *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                      |                       *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 2)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");

        switch (choice)
        {
        case 1:
            menu_login();
            break;
        case 2:
            Room::view_empty_room(L);
            box_roomempty(3, 3, L);
            gotoXY(0, 0);
            break;
        default:
            break;
        }
        L.clear();
        if (choice == 0)
            break;
        system("pause");
    } while (choice != 0);
}

int main()
{
    menu();
    return 0;
}
