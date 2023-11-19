#ifndef DIEN_NUOC_H
#define DIEN_NUOC_H

#include "Datetime.h"

class dien_nuoc
{
private:
    string dien_nuoc_id;
    string room_id;
    int num_electric_before;
    int num_electric_after;
    int num_water_before;
    int num_water_after;
    int cost_water;
    int cost_electric;
    Datetime date;
    bool status;

public:
    dien_nuoc(string = "", string = "", int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, bool = false);
    ~dien_nuoc();
    string get_dien_nuoc_id() const;
    string get_room_id() const;
    int get_num_elecric_before() const;
    int get_num_elecric_after() const;
    int get_num_water_before() const;
    int get_num_water_after() const;
    int get_cost_water() const;
    int get_cost_electric() const;
    Datetime get_date() const;
    bool get_status() const;

    void set_dien_nuoc_id(string);
    void set_room_id(string);
    void set_num_electric_before(int);
    void set_num_electric_after(int);
    void set_num_water_before(int);
    void set_num_water_after(int);
    void set_cost_water(int);
    void set_cost_electric(int);
    void set_date(int, int, int);
    void set_status(bool);

    friend ostream &operator<<(ostream &, const dien_nuoc &);
    friend istream &operator>>(istream &, dien_nuoc &);
    // int electric_bill(int , int , int);
    // int water_bill(int , int, int );
    static dien_nuoc Split(string);
    // string int_to_str(int);
    // int str_to_int(string);
    // string bool_to_str(bool);
    // bool str_to_bool(string);
    static void write_File(List<string> &);
    static string Union(dien_nuoc &);
    static void display();

    static int getNewCostWater();
    static int getNewCostElectric();
    static void updateCostWater(int);
    static void updateCostElectric(int);
    void add_dien_nuoc();
    
    // void find_room(string);
    // void update_dien_nuoc(string);
    static void delete_dien_nuoc(string);
    // int Electric_bill();
    // int Water_bill();
};
#endif
