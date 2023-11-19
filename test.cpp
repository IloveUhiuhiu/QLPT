#include "user.h"
#include "admin.h"
#include "customer.h"
#include "DoanhThu.h"
#include "dien_nuoc.h"
#include "hoa_don.h"


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

void menu_Info_Khach_Tro(customer &object2)
{
    int choice;
    do
    {   
        system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Info Customer ****                     *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View Info Customer |                              *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Edit Info Customer |                              *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit               |                              *" << endl;
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
            // display
            menu_display_customer();
            cout << object2;
            cout << endl;
            break;
        case 2:
            warn();
            // edit
            // menu_display_customer();
            // cout << object2;
            // cout << endl;
            // object2.update_customer(object2.get_customer_id());
            // break;
        default:
            break;
        }
        if (choice == 0) break;
        system("pause");
    } while (choice != 0);
}
void menu_Info_Phong_Tro(customer& object2)
{
    int choice;
    do
    {   
        system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Info Room ****                    *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View Info Room       |                       *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Cancel Room          |                       *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) View Payment Room    |                       *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Transfer Room        |                       *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                 |                       *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 4)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        Room room;
        switch (choice)
        {
        case 1:
            room = Room::find_room(object2.get_room_id());
            cout << room;
            break;
        case 2:
            warn();
            break;
        case 3:
            warn();
            break;
        case 4:
            warn();
            break;
        default:
            break;
        }
        if (choice == 0) break;
        system("pause");
    } while (choice != 0);
}
void menu_Info_Dien_Nuoc(customer &object2)
{
    int choice;
    do
    {   
        system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Info Electric_Water ****                    *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View Info Electric_Water  |                            *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Payment Electric_Water    |                            *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                      |                            *" << endl;
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
            warn();
            break;
        case 2:
            warn();
            break;
        default:
            break;
        }
        if (choice == 0) break;
        system("pause");
    } while (choice != 0);
}
void menu_user(customer &object2)
{
    int choice;
    do
    {   
        system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Wellcome Customer" << setw(15) << object2.get_customer_name() << " ****             *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) Info Customer       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Info Room           |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Info Electric-Water |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Logout              |                             *" << endl;
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
            menu_Info_Khach_Tro(object2);
            break;
        case 2:
            menu_Info_Phong_Tro(object2);
            break;
        case 3:
            menu_Info_Dien_Nuoc(object2);
            break;
        default:
            break;
        }
        if (choice == 0) break;
        system("pause");

    } while (choice != 0);
}

void menu_Manager_Customer()
{
    customer object2;
    string ID;
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
        cout << "\t\t\t*\t|  3) Delete Customer    |                              *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Edit Customer      |                              *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit               |                              *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
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
            // delete
            // menu_display_customer();
            customer::display();
            cout << "Enter ID: ";
            cin >> ID;
            customer::delete_customer(ID);
            break;
        case 4:
            // edit
            // menu_display_customer();
            customer::display();
            cout << "Enter ID: ";
            cin >> ID;
            // object2.update_customer(ID);
            break;
        default:
            break;
        }
        if (choice == 0) break;
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
        cout << "\t\t\t*\t|  4) Add Room                 |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Delete Room              |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  6) Edit Room                |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  7) View List Payment Room   |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  8) Add Payment Room         |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  9) Delete Payment Room      |                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  10) Edit Payment Room       |                        *" << endl;
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
        while (choice < 0 || choice > 10)
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
            cin >> room;
            room.add_room(1);
            break;
        case 5:
            cout << "Enter ID: ";
            cin >> ID;
            Room::delete_room(ID);
            break;
        case 6:
            warn();
            break;
        case 7:
            hoa_don::view_payment_room();
            break;
        case 8:
            warn();

            break;
        case 9:
            warn();
            break;
        case 10:
            warn();
            break;
        default:
            break;
        }
        if (choice == 0) break;
        system("pause");
        
    } while (choice != 0);
}

void menu_Manager_Dien_Nuoc()
{   
    
    int choice;
    do
    {   system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Electric-Water Manager ****                 *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View list Electric-Water |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Add Electric-Water       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Delete Electric-Water    |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Edit Electric-Water      |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                     |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
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
            // dien_nuoc::display();
            break;
        case 2:
            warn();
            break;
        case 3:
            warn();
            break;
        case 4:
            warn();
            break;
        default:
            break;
        }
        if (choice == 0) break;
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
        cout << "\t\t\t*\t|  4) Calculate Revenue by Year    |                    *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Calculate Revenue by Month   |                    *" << endl;
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
            cout << "Enter Year:";
            cin >> year;
            revenue = DoanhThu::tongDoanhThutheonam(year);
            cout << "Revenue: " << revenue << endl;
            break;
        case 5:
            cout << "Enter Month:";
            cin >> month;
            while (month < 1 || month > 12)
            {
                cout << "Enter Right Month:";
                cin >> month;
            }
            revenue = DoanhThu::tongDoanhThutheothang(month);
            cout << "Revenue: " << revenue << endl;
            break;
        default:
            break;
        }
        if (choice == 0) break;
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
    {   system("cls");
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
        if (choice == 0) break;
        system("pause");

    } while (choice != 0);
}
void menu()
{
    int choice;
    do
    {   system("cls");
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
        if (choice == 0) break;
        system("pause");
    } while (choice != 0);
}

int main()
{
    menu();
    return 0;
}