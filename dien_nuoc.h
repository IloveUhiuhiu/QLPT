#ifndef DIEN_NUOC_H
#define DIEN_NUOC_H

#include "Datetime.h"
#include "Room.h"

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
    dien_nuoc(string = "", string = "", int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, Datetime = Datetime(0,0,0), bool = false);
    ~dien_nuoc();
    string get_dien_nuoc_id() const;
    string get_room_id() const;
    int get_num_electric_before() const;
    int get_num_electric_after() const;
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
    void set_date(Datetime);
    void set_status(bool);

    friend ostream &operator<<(ostream &, const dien_nuoc &);

    static dien_nuoc Split(string);
    static void write_File(List<string> &);
    static string Union(dien_nuoc &);

    static void display(List<dien_nuoc>&,int = 0); // 0 bình thường, 1 paid, 2 unpaid

    static int getNewCostWater();
    static int getNewCostElectric();
    static void updateCostWater(int);
    static void updateCostElectric(int);
    void add_dien_nuoc();
    
    static bool find_room(string);
    static bool find_dien_nuoc(List<dien_nuoc>&);
    static void find_dien_nuoc_id(string,List<dien_nuoc>&);
    static dien_nuoc find_nearest_dien_nuoc(string);

    static void update_dien_nuoc(dien_nuoc&,int);
    static void Pay_dien_nuoc(dien_nuoc&,int);
    static void delete_dien_nuoc(string);
    static void delete_by_room(string);

};
#endif
