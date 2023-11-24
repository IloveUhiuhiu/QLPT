#include "user.h"
#include "admin.h"
#include "customer.h"
#include "DoanhThu.h"
///////////////////////////////////

void warn()
{
    cout << "Chua Co Gi" << endl;
}

// void update_dien_nuoc(dien_nuoc& dn)
// {
//     int choice;
//     do
//     {
//         system("cls");
//         cout << "\t\t\t*****************************************************************" << endl;
//         cout << "\t\t\t*\t                                                        *" << endl;
//         cout << "\t\t\t*\t **** Welcome To Update dien nuoc ****                     *" << endl;
//         cout << "\t\t\t*\t                                                        *" << endl;
//         cout << "			*    	                                                        *" << endl;
//         cout << "\t\t\t*\t|  1) Number Electric Before |                              *" << endl;
//         cout << "			*    	                                                        *" << endl;
//         cout << "\t\t\t*\t|  2) Number Electric Before |                              *" << endl;
//         cout << "			*    	                                                        *" << endl;
//         cout << "\t\t\t*\t|  3) Number Electric After  |                              *" << endl;
//         cout << "			*    	                                                        *" << endl;
//         cout << "\t\t\t*\t|  4) Number Electric After  |                              *" << endl;
//         cout << "			*    	                                                        *" << endl;
//         cout << "\t\t\t*\t|  5) Status                 |                              *" << endl;
//         cout << "			*    	                                                        *" << endl;
//         cout << "\t\t\t*\t|  0) Exit                   |                              *" << endl;
//         cout << "			*    	                                                        *" << endl;
//         cout << "\t\t\t*****************************************************************" << endl;
//         cout << endl;

//         cout << "***********************" << endl
//              << endl;
//         cout << "Enter Your Choice : ";
//         cin >> choice;
//         while (choice < 0 || choice > 5)
//         {
//             cout << "Enter Right Choice : ";
//             cin >> choice;
//         }
//         cout << "\n***********************" << endl;
//         system("cls");
//         int number;
//         string status;
//         switch (choice)
//         {
//         case 1:
//             cout << "Enter Number Electric Before : "; cin >> number;
//             dn.set_num_electric_before(number);
//             dien_nuoc::delete_dien_nuoc(dn.get_dien_nuoc_id());
//             dn.add_dien_nuoc();
//             break;
//         case 2:
//             cout << "Enter Number Water Before : "; cin >> number;
//             dn.set_num_water_before(number);
//             dien_nuoc::delete_dien_nuoc(dn.get_dien_nuoc_id());
//             dn.add_dien_nuoc();
//             break;
//         case 3:
//             cout << "Enter Number Electric After : "; cin >> number;
//             dn.set_num_electric_after();
//             dien_nuoc::delete_dien_nuoc(dn.get_dien_nuoc_id());
//             dn.add_dien_nuoc();
//             break;
//         case 4:
//             cout << "Enter Number Water After : "; cin >> number;
//             dn.set_num_water_after(number);
//             dien_nuoc::delete_dien_nuoc(dn.get_dien_nuoc_id());
//             dn.add_dien_nuoc();
//             break;
//         case 5:
//             cout << "Enter Status (Yes or No) : "; cin >> status;
//             dn.set_status(Convert::str_to_bool(status));
//             dien_nuoc::delete_dien_nuoc(dn.get_dien_nuoc_id());
//             dn.add_dien_nuoc();
//             break;
//         default:
//             break;
//         }
//         if (choice == 0) break;
//         system("pause");
//     } while (choice != 0);
// }
void menu_display_customer()
{
    cout << setw(5) << "Customer_ID";
    cout << " | ";
    cout << setw(5) << "Room_ID";
    cout << " | ";
    cout << setw(10) << "Name";
    cout << " | ";
    cout << setw(10) << "Date Of Birth";
    cout << " | ";
    cout << setw(10) << "Gender";
    cout << " | ";
    cout << setw(15) << "Email";
    cout << " | ";
    cout << setw(10) << "Address";
    cout << " | ";
    cout << setw(10) << "Phone";
    cout << " | ";
    cout << setw(10) << "user_name";
    cout << " | ";
    cout << setw(10) << "password";
    cout << " | ";
    cout << endl;
}
void menu_user(customer &object2)
{
    int choice;
    Room room;
    dien_nuoc dn;
    hoa_don hd;
    do
    {
        system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Wellcome Customer" << setw(15) << object2.get_customer_name() << " ****             *" << endl;
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
        cout  << endl;
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
            menu_display_customer();
            cout << object2;
            cout << endl;
            break;
        case 2:
            room = Room::find_room(object2.get_room_id());
            cout << room;
            break;
        case 3:
            dn = dien_nuoc::find_dien_nuoc_id(dn.find_max_dien_nuoc_id());
            cout << dn;
            break;
        case 4:
            hd = hoa_don::find_bill_id(hd.find_max_bill_id());
            cout << hd;
            break;
        default:
            break;
        }
        if (choice == 0)
            break;
        system("pause");

    } while (choice != 0);
}

void menu_Manager_Customer()
{
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
        cout << "\t\t\t*\t|  1) View List Customer |                              *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Add Customer       |                              *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Find Customer       |                              *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Delete Customer    |                              *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Edit Customer      |                              *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit               |                              *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
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
            // display
            // menu_display_customer();
            customer::display();
            break;
        case 2:
            // add
            cin >> object2;
            object2.set_customer_id(Convert::CreateID("customer.txt"));
            object2.add_customer();
            break;
        case 3:
            cout << "Find Information Customer: " << endl;
            if (!customer::find_customer())
            {
                cout << "Not Found!" << endl;
            }
            break;
        case 4:
            cout << "Find Information Customer: " << endl;
            if (!customer::find_customer())
            {
                cout << "Not Found!" << endl;
                continue;
            }
            cout << "Enter ID: "; cin >> ID;
            object2 = customer::find_idcustomer(ID);
            customer::delete_customer(ID);
            break;
        case 5:
            cout << "Find Information Customer: " << endl;
            if (!customer::find_customer())
            {
                cout << "Not Found!" << endl;
                continue;
            }
            cout << "Enter ID:"; cin >> ID;
            object2 = customer::find_idcustomer(ID);
            customer::update_customer(object2);
            break;
        default:
            break;
        }
        if (choice == 0)
            break;
        system("pause");

    } while (choice != 0);
}
void menu_Manager_Phong_Tro()
{
    int choice;
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
        Room room;
        string ID;
        int month;
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
            Room::display();
            break;
        case 2:
            Room::view_empty_room();
            break;
        case 3:
            Room::view_rented_room();
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

                if (!foundRoom.getRoomID().empty()) {
                    cout << "Room found:" << endl;
                    cout << foundRoom << endl;
                } else {
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
            Room::display();
            Room::edit_room();
            break;
        case 8:
            // hủy phòng
            break;
        case 9:
            // chuyển phòng
            break;
        default:
            break;
        }
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
            hoa_don::find_hoa_don();
            break;
        case 5:
            // add
            break;
        case 6:
            hoa_don::view_unpayment_room();
            cout << "Enter ID OF BILL want to pay: ";
            cin >> ID;
            object2 = hoa_don::find_bill_id(ID);
            hoa_don::Pay_bill(object2);
            break;
        case 7:
            cout << "Enter ID OF ROOM:";
            cin.ignore();
            getline(cin,ID);
            if (!hoa_don::find_room(ID))
            {
                cout << "Not Found" << endl;
            }
            else
            {
                cout << "Enter ID: ";
                cin >> ID;
                object2 = hoa_don::find_bill_id(ID);
                hoa_don::update_hoa_don(object2);
            }
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
            dien_nuoc::display();
            break;
        case 2:
            dien_nuoc::view_unpaid_room();
            break;
        case 3:
            dien_nuoc::view_Paid_room();
            break;
        case 4:
            dien_nuoc::find_dien_nuoc();
            break;
        case 5:
            dien_nuoc::view_unpaid_room();
            cout << "Enter ID OF ELECTRIC_WATER want to pay: ";
            cin >> ID;
            object2 = dien_nuoc::find_dien_nuoc_id(ID);
            dien_nuoc::Pay_dien_nuoc(object2);
            break;
        case 6:
            // add đien nước
            break;
        case 7:
            cout << "Enter ID OF ROOM:";
            cin.ignore();
            getline(cin,ID);
            if (!dien_nuoc::find_room(ID))
            {
                cout << "Not Found" << endl;
            }
            else
            {
                cout << "Enter ID: ";
                cin >> ID;
                object2 = dien_nuoc::find_dien_nuoc_id(ID);
                dien_nuoc::update_dien_nuoc(object2);
            }
            break;
        default:
            break;
        }
        if (choice == 0)
            break;
        system("pause");
    } while (choice != 0);
}

void menu_Calculte_Revenue()
{
    int choice, month, year, revenue;
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
            break;
        case 2:
            cout << "Enter Year:";
            cin >> year;
            break;
        case 3:
            break;
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
            menu_Calculte_Revenue();
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
void menu2()
{
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
            Room::view_empty_room();
            break;
        default:
            break;
        }
        if (choice == 0)
            break;
        system("pause");
    } while (choice != 0);
}

int main()
{
    menu2();
    return 0;
}
//////////////////////////