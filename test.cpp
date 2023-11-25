#include "admin.h"
#include "customer.h"
#include "DoanhThu.h"
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
void box(int x, int y, int w, int h, const string content)
{

    int ym = (2 * y + h) / 2;
    int xm = (2 * x + w - content.size()) / 2;
    TextColor(7);
    gotoXY(xm, ym);
    cout << content;
    if (h <= 1 || w <= 1)
        return;

    for (int ix = x; ix <= x + w; ix++)
    {
        gotoXY(ix, y);
        cout << char(196);
        gotoXY(ix, y + h);
        cout << char(196);
    }
    for (int iy = y; iy <= y + h; iy++)
    {
        gotoXY(x, iy);
        cout << char(179);
        gotoXY(x + w, iy);
        cout << char(179);
    }
    gotoXY(x, y);
    cout << char(218);
    gotoXY(x + w, y);
    cout << char(191);
    gotoXY(x, y + h);
    cout << char(192);
    gotoXY(x + w, y + h);
    cout << char(217);
}
void box_customer(int x, int y, List<customer> &L)
{
    int n = L.getSize();
    int m = 11;
    int w = 17;
    int h = 2;
    int xx = x, yy = y;
    for (int j = 0; j < m; j++)
    {
        if (j == 0)
        {
            box(xx, yy, w / 2 + 4, h, "CustomerID");
            xx += w / 2 + 4;
        }
        else if (j == 1)
        {
            box(xx, yy, w / 2, h, "RoomID");
            xx += w / 2;
        }
        else if (j == 2)
        {
            box(xx, yy, w + 4, h, "Name");
            xx += w + 4;
        }
        else if (j == 3)
        {
            box(xx, yy, w - 3, h, "DateofBirth");
            xx += w - 3;
        }
        else if (j == 4)
        {
            box(xx, yy, w - 3, h, "DateCheckIn");
            xx += w - 3;
        }
        else if (j == 5)
        {
            box(xx, yy, w / 2, h, "Gender");
            xx += w / 2;
        }
        else if (j == 6)
        {
            box(xx, yy, w, h, "Email");
            xx += w;
        }
        else if (j == 7)
        {
            box(xx, yy, w / 2 + 4, h, "Address");
            xx += w / 2 + 4;
        }
        else if (j == 8)
        {
            box(xx, yy, w - 2, h, "Phone");
            xx += w - 2;
        }
        else if (j == 9)
        {
            box(xx, yy, w, h, "UserName");
            xx += w;
        }
        else if (j == 10)
        {
            box(xx, yy, w / 2 + 4, h, "Password");
            xx += w / 2 + 4;
        }
    }
    yy += h;
    for (int i = 0; i < n; i++)
    {
        xx = x;
        for (int j = 0; j < m; j++)
        {

            if (j == 0)
            {
                box(xx, yy, w / 2 + 4, h, L[i].get_customer_id());
                xx += w / 2 + 4;
            }
            else if (j == 1)
            {
                box(xx, yy, w / 2, h, L[i].get_room_id());
                xx += w / 2;
            }
            else if (j == 2)
            {
                box(xx, yy, w + 4, h, L[i].get_customer_name());
                xx += w + 4;
            }
            else if (j == 3)
            {
                box(xx, yy, w - 3, h, Datetime::Union(L[i].get_customer_dateofbirth()));
                xx += w - 3;
            }
            else if (j == 4)
            {
                box(xx, yy, w - 3, h, Datetime::Union(L[i].get_check_in()));
                xx += w - 3;
            }
            else if (j == 5)
            {
                box(xx, yy, w / 2, h, L[i].get_customer_gender());
                xx += w / 2;
            }
            else if (j == 6)
            {
                box(xx, yy, w, h, L[i].get_customer_email());
                xx += w;
            }
            else if (j == 7)
            {
                box(xx, yy, w / 2 + 4, h, L[i].get_customer_address());
                xx += w / 2 + 4;
            }
            else if (j == 8)
            {
                box(xx, yy, w - 2, h, L[i].get_customer_phone());
                xx += w - 2;
            }
            else if (j == 9)
            {

                box(xx, yy, w, h, L[i].get_user_name());
                xx += w;
            }
            else if (j == 10)
            {

                box(xx, yy, w / 2 + 4, h, L[i].get_password());
                xx += w / 2 + 4;
            }
        }
        yy += h;
    }
}

void box_room(int x, int y, List<Room> &L)
{
    int n = L.getSize();
    int m = 4;
    int w = 17;
    int h = 2;
    int xx = x, yy = y;
    for (int j = 0; j < m; j++)
    {
        if (j == 0)
        {
            box(xx, yy, w / 2 + 4, h, "RoomID");
            xx += w / 2 + 4;
        }
        else if (j == 1)
        {
            box(xx, yy, w / 2 + 4, h, "KindOf");
            xx += w / 2 + 4;
        }
        else if (j == 2)
        {
            box(xx, yy, w + 4, h, "Cost");
            xx += w + 4;
        }
        else if (j == 3)
        {
            box(xx, yy, w, h, "IsOccupied");
            xx += w;
        }
    }
    yy += h;
    for (int i = 0; i < n; i++)
    {
        xx = x;
        for (int j = 0; j < m; j++)
        {

            if (j == 0)
            {
                box(xx, yy, w / 2 + 4, h, L[i].getRoomID());
                xx += w / 2 + 4;
            }
            else if (j == 1)
            {
                box(xx, yy, w / 2 + 4, h, L[i].getKindOf());
                xx += w / 2 + 4;
            }
            else if (j == 2)
            {
                box(xx, yy, w + 4, h, Convert::int_to_str(L[i].getCost()));
                xx += w + 4;
            }
            else if (j == 3)
            {
                box(xx, yy, w, h, Convert::bool_to_str(L[i].isOccupied()));
                xx += w;
            }
        }
        yy += h;
    }
}

void box_diennuoc(int x, int y, List<dien_nuoc> &L)
{
    int n = L.getSize();
    int m = 10;
    int w = 17;
    int h = 2;
    int xx = x, yy = y;
    for (int j = 0; j < m; j++)
    {
        if (j == 0)
        {
            box(xx, yy, w / 2 + 4, h, "DienNuocID");
            xx += w / 2 + 4;
        }
        else if (j == 1)
        {
            box(xx, yy, w / 2, h, "RoomID");
            xx += w / 2;
        }
        else if (j == 2)
        {
            box(xx, yy, w + 3, h, "NumElecticBefore");
            xx += w + 3;
        }
        else if (j == 3)
        {
            box(xx, yy, w + 3, h, "NumElecticAfter");
            xx += w + 3;
        }
        else if (j == 4)
        {
            box(xx, yy, w, h, "NumWaterBefore");
            xx += w;
        }
        else if (j == 5)
        {
            box(xx, yy, w, h, "NumWaterAfter");
            xx += w;
        }
        else if (j == 6)
        {
            box(xx, yy, w - 2, h, "CostWater");
            xx += w - 2;
        }
        else if (j == 7)
        {
            box(xx, yy, w - 1, h, "CostElectric");
            xx += w - 1;
        }
        else if (j == 8)
        {
            box(xx, yy, w - 2, h, "PaymentDate");
            xx += w - 2;
        }
        else if (j == 9)
        {
            box(xx, yy, w / 2, h, "Status");
            xx += w / 2;
        }
    }
    yy += h;
    for (int i = 0; i < n; i++)
    {
        xx = x;
        for (int j = 0; j < m; j++)
        {

            if (j == 0)
            {
                box(xx, yy, w / 2 + 4, h, L[i].get_dien_nuoc_id());
                xx += w / 2 + 4;
            }
            else if (j == 1)
            {
                box(xx, yy, w / 2, h, L[i].get_room_id());
                xx += w / 2;
            }
            else if (j == 2)
            {
                box(xx, yy, w + 3, h, Convert::int_to_str(L[i].get_num_electric_before()));
                xx += w + 3;
            }
            else if (j == 3)
            {
                box(xx, yy, w + 3, h, Convert::int_to_str(L[i].get_num_electric_after()));
                xx += w + 3;
            }
            else if (j == 4)
            {
                box(xx, yy, w, h, Convert::int_to_str(L[i].get_num_water_before()));
                xx += w;
            }
            else if (j == 5)
            {
                box(xx, yy, w, h, Convert::int_to_str(L[i].get_num_water_after()));
                xx += w;
            }
            else if (j == 6)
            {
                box(xx, yy, w - 2, h, Convert::int_to_str(L[i].get_cost_water()));
                xx += w - 2;
            }
            else if (j == 7)
            {
                box(xx, yy, w - 1, h, Convert::int_to_str(L[i].get_cost_electric()));
                xx += w - 1;
            }
            else if (j == 8)
            {
                box(xx, yy, w - 2, h, Datetime::Union(L[i].get_date()));
                xx += w - 2;
            }
            else if (j == 9)
            {
                box(xx, yy, w / 2, h, Convert::bool_to_str(L[i].get_status()));
                xx += w / 2;
            }
        }
        yy += h;
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
    do
    {
        system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Wellcome Customer" << setw(10) << object2.get_user_name() << " ****             *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View Info Customer       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) View Info Room           |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) View Info Electric-Water |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) View Info Payment        |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Logout                   |                             *" << endl;
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
            customer::find_idroom(object2.get_room_id(),L);
            box_customer(3,3,L);
            gotoXY(0,0);
            break;
        case 2:
            Room::find_idroom(object2.get_room_id(),L1);
            box_room(3,3,L1);
            gotoXY(0,0);
            break;
        case 3:
            dien_nuoc::find_dien_nuoc_id(dn.find_max_dien_nuoc_id(),L2);
            box_diennuoc(3,3,L2);
            gotoXY(0,0);
            break;
        case 4:
            hd = hoa_don::find_bill_id(hd.find_max_bill_id());
            cout << hd;
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
            cout << "Enter Customer ID:";
            cin >> ID;
            customer::find_idcustomer(ID, L);
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
        cout << "\t\t\t*\t **** Welcome To Room Manager ****                 *" << endl;
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
            box_room(3, 3, L);
            gotoXY(0, 0);
            break;
        case 3:
            Room::view_rented_room(L);
            box_room(3, 3, L);
            gotoXY(0, 0);
            break;
        case 4:
        {
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
            hoa_don::display();
            break;
        case 2:
            hoa_don::view_payment_room();
            break;
        case 3:
            hoa_don::view_unpayment_room();
            break;
        case 4:
           cout << "Find Information BILL: " << endl;
            if (!hoa_don::find_hoa_don())
            {
                cout << "Not Found!" << endl;
            }
            break;
        case 5:
            cin >> object2;
            object2.set_bill_id(Convert::CreateID("hoa_don.txt"));
            object2.add_hoa_don();
            break;
        case 6:
            hoa_don::view_unpayment_room();
            cout << "Enter ID Of Bill Want To Pay: ";
            cin >> ID;
            object2 = hoa_don::find_bill_id(ID);
            hoa_don::Pay_bill(object2);
            break;
            
        case 7:
            cout << "Edit BILL: " << endl;
            if (!hoa_don::find_hoa_don())
            {
                cout << "Not Found!" << endl;
                continue;
            }
            cout << "Enter ID:"; cin >> ID;
            object2 = hoa_don::find_bill_id(ID);
            hoa_don::update_hoa_don(object2);
            break;
        default:
            break;
        }
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
        cout << "\t\t\t*\t **** Welcome To Electric-Water Manager ****                 *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View list Electric-Water        |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) View List Unpaid Electric_Water |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) View List Paid Electric_Water   |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Find Electric_Water             |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Paid Electric_Water             |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  6) Add Electric-Water              |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  7) Edit Electric-Water             |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                            |                             *" << endl;
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
            gotoXY(0,0);
            break;
        case 2:
            dien_nuoc::view_unpaid_room(L);
            box_diennuoc(3, 3, L);
            gotoXY(0,0);
            break;
        case 3:
            dien_nuoc::view_Paid_room(L);
            box_diennuoc(3, 3, L);
            gotoXY(0,0);
            break;
        case 4:
            if (dien_nuoc::find_dien_nuoc(L)) {
                box_diennuoc(3,5, L);
                gotoXY(0,0);
            } else {
                cout << "Not Found!" << endl;
                continue;
            }
            
            break;
        case 5:
            // dien_nuoc::view_unpaid_room();
            cout << "Enter ID Of Electric Water Want To Pay: ";
            cin >> ID;
            dien_nuoc::find_dien_nuoc_id(ID,L);
            dien_nuoc::Pay_dien_nuoc(L[0]);
            break;
        case 6:
            cin >> object2;
            object2.set_dien_nuoc_id(Convert::CreateID("dien_nuoc.txt"));
            object2.add_dien_nuoc();
            break;
        case 7:
            if (!dien_nuoc::find_dien_nuoc(L))
            {
                cout << "Not Found!" << endl;
                continue;
            }
            box_diennuoc(3, 3, L);
            gotoXY(0,2*L.getSize() + 6);
            cout << "Enter ID:"; cin >> ID;
            L.clear();
            system("cls");
            
            cout << "Information Current Electric_Water: " << endl;
            dien_nuoc::find_dien_nuoc_id(ID,L);
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
    DoanhThu doanhThu; // Create an object of the DoanhThu class

    do
    {
        system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Calculate Revenue ****                       *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) Calculate Revenue By Month      |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Calculate Revenue By Year       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Calculate revenue by time period|                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                            |                             *" << endl;
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
            cout << "Enter Month:";
            cin >> month;
            while (month < 1 || month > 12)
            {
                cout << "Enter Right Month:";
                cin >> month;
            }
            revenue = doanhThu.tongDoanhThutheothang(month);
            cout << "Total Revenue for Month " << month << ": " << revenue << endl;
            break;

        case 2:
            cout << "Enter Year:";
            cin >> year;
            revenue = doanhThu.tongDoanhThutheonam(year);
            cout << "Total Revenue for Year " << year << ": " << revenue << endl;
            break;

        case 3:
        {
            int startYear, startMonth, startDay, endYear, endMonth, endDay;
            cout << "Enter Start Year:";
            cin >> startYear;

            cout << "Enter Start Month:";
            cin >> startMonth;
            while (startMonth < 1 || startMonth > 12)
            {
                cout << "Enter Right Start Month:";
                cin >> startMonth;
            }

            cout << "Enter Start Day:";
            cin >> startDay;
            while (startDay < 1 || startDay > 31)
            {
                cout << "Enter Right Start Day:";
                cin >> startDay;
            }

            cout << "Enter End Year:";
            cin >> endYear;

            cout << "Enter End Month:";
            cin >> endMonth;
            while (endMonth < 1 || endMonth > 12)
            {
                cout << "Enter Right End Month:";
                cin >> endMonth;
            }

            cout << "Enter End Day:";
            cin >> endDay;
            while (endDay < 1 || endDay > 31)
            {
                cout << "Enter Right End Day:";
                cin >> endDay;
            }

            Datetime startDate(startYear, startMonth, startDay);
            Datetime endDate(endYear, endMonth, endDay);
            int totalRevenue = 0;
            Datetime currentDate = startDate;

            while (currentDate <= endDate)
            {
                // Calculate revenue for the current month
                int revenue = doanhThu.tongDoanhThutheothang(currentDate.get_months());

                // Accumulate the revenue
                totalRevenue += revenue;

                // Move to the next month
                int nextMonth = currentDate.get_months() + 1;
                int nextYear = currentDate.get_years();

                if (nextMonth > 12)
                {
                    nextMonth = 1;
                    nextYear++;
                }

                // Update currentDate
                currentDate = Datetime(nextYear, nextMonth, currentDate.get_days());
            }

            cout << "Total Revenue for the specified time period: " << totalRevenue << endl;
            break;
        }
        default:
            break;
        }

        if (choice == 0)
            break;

        system("pause");
    } while (choice != 0);
}

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
    admin object1;
    customer object2;
    string user_name, password, ID;
    int choice;
    do
    {
        system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Login  ****                                       *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t* Are You:                                                      *      " << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) Admin    |                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Customer |                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit     |                                        *" << endl;
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

            do
            {
                cin.ignore();
                cout << "Enter Admin: ";
                getline(cin, user_name);
                object1.set_user_name(user_name);
                cout << "Enter Admin Password: ";
                getline(cin, password);
                object1.set_password(password);

            } while (!object1.login());
            menu_admin(object1);
            break;
        case 2:
            do
            {
                cin.ignore();
                cout << "Enter Customer: ";
                getline(cin, user_name);
                object2.set_user_name(user_name);
                cout << "Enter Customer Password: ";
                getline(cin, password);
                object2.set_password(password);
                system("cls");
            } while (!object2.login());
            menu_user(object2);
            break;
        default:
            break;
        }
        if (choice == 0)
            break;
        system("pause");

    } while (choice != 0);
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
            box_room(3, 3, L);
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
