#ifndef PROBLEM_H
#define PROBLEM_H
#include "Phong.h"
using namespace std;
class SuCo
{   
    private:
    string problem_id;
    string room_id;
    ThoiGian registeddate;
    ThoiGian finishdate;
    string content;
    bool status;
    public:
    static int cnt;
    SuCo(string = "",string = "",ThoiGian = ThoiGian(0,0,0),ThoiGian = ThoiGian (0,0,0),string = "", bool = false);
    ~SuCo();
    string get_problem_id() const;
    void set_problem_id(string);

    string get_room_id() const;
    void set_room_id(string);
    
    ThoiGian get_registeddate() const;
    void set_registeddate(ThoiGian);

     
    ThoiGian get_finishdate() const;
    void set_finishdate(ThoiGian);

    string get_content() const;
    void set_content(string);

    bool get_status() const;
    void set_status(bool);
    friend istream &operator>>(istream &, SuCo &);

    static void write_File(List<string> &);
    static SuCo Split(string);
    static string Union(SuCo &);

    void add_problem();

    static int NumOfProblem();

    static void display(List<SuCo>&, int = 0); // 0 bình thường, 1 solved, 2 unsolved

    static void find_idproblem(string,List<SuCo>&);
    static void solve(SuCo&);
};
#endif


