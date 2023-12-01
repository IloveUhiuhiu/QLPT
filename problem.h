#ifndef PROBLEM_H
#define PROBLEM_H
#include "Room.h"
using namespace std;
class problem
{   
    private:
    string problem_id;
    string room_id;
    Datetime registeddate;
    Datetime finishdate;
    string content;
    bool status;
    public:
    static int cnt;
    problem(string = "",string = "",Datetime = Datetime(0,0,0),Datetime = Datetime (0,0,0),string = "", bool = false);
    ~problem();
    string get_problem_id() const;
    void set_problem_id(string);

    string get_room_id() const;
    void set_room_id(string);
    
    Datetime get_registeddate() const;
    void set_registeddate(Datetime);

     
    Datetime get_finishdate() const;
    void set_finishdate(Datetime);

    string get_content() const;
    void set_content(string);

    bool get_status() const;
    void set_status(bool);
    friend istream &operator>>(istream &, problem &);

    static void write_File(List<string> &);
    static problem Split(string);
    static string Union(problem &);

    void add_problem();
    static void display(List<problem>&);
    static void view_solved_problem(List<problem>&);
    static void view_unsolved_problem(List<problem>&);
    static void find_idproblem(string,List<problem>&);
    static void solve(problem&);
};
#endif


