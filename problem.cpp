#include "problem.h"

int problem::cnt 0;
problem::problem(string problem_id, string room_id, Datetime registeddate, Datetime finishdate, string content) : problem_id(problem_id), room_id(room_id),
                                                                                                                  registeddate(registeddate), finishdate(finishdate), content(content)
{
}
~problem()
{
}
string problem::get_problem_id() const
{
    return this->problem_id;
}
void problem::set_problem_id(string problem_id)
{
    this->problem_id = problem_id;
}

string problem::get_room_id() const
{
    return this->room_id;
}
void problem::set_room_id(string room_id)
{
    this->room_id = room_id;
}
Datetime problem::get_registeddate() const
{
    return this->registeddate;
}
void problem::set_registeddate(Datetime registeddate)
{
    this->registeddate = registeddate;
}
Datetime problem::get_finishdate() const
{
    return this->finishdate;
}
void problem::set_finishdate(Datetime finishdate)
{
    this->finishdate = finishdate;
}

string problem::get_content() const
{
    return this->content;
}
void problem::set_content(string content)
{
    this->content = content;
}

friend istream &operator>>(istream &i, problem &obj)
{
    cin.ignore();
    Room room;
    do
    {
        cout << "Enter RoomID: ";
        getline(i, obj.room_id);
        room = Room::find_room(obj.room_id);
        if (room.getRoomID() != obj.room_id)
        {
            cout << "Room Not Found.Try Again!" << endl;
        }
    } while (room.getRoomID() != obj.room_id);
    Datetime date;
    obj.registeddate = date;
    cout << "Content: ";
    getline(i, obj.content);
    return i;
}

void problem::write_File(List<string> &L)
{
    ofstream inputFile;
    inputFile.open("problem.txt", std::ios::out | std::ios::trunc);
    if (inputFile.is_open())
    {
        int size = L.getSize();
        if (size)
        {
            for (int i = 0; i < size; i++)
            {
                inputFile << L[i] << '\n';
            }
        }
    }
    else
    {
        cout << "Error Opening File problem.txt" << endl;
    }
}
problem problem::Split(string str)
{
    string problem_id, room_id, registeddate, finishdate, content;
    Datetime time1,time2;
    str += ',';
    int id = 1;
    int begin = 0, end = 0;
    for (auto x : str)
    {
        if (x == ',')
        {
            if (id == 1)
            {
                problem_id = str.substr(begin, end - begin);
            }
            else if (id == 2)
            {
                room_id = str.substr(begin, end - begin);
            }
            else if (id == 3)
            {   
                registeddate = str.substr(begin, end - begin);
                time1 = Datetime::Split(registeddate);
            } else if (id == 4)
            {
                finishdate = str.substr(begin,end -begin);
                time2 = Datetime::Split(finishdate);
            }
            else
            {
                content = str.substr(begin, end - begin);
            }
            ++id;
            begin = end + 1;
        }
        end++;
    }
    return customer(problem_id, room_id,time1,time2,content);
}
string problem::Union(problem &obj)
{
    string str = obj.problem_id + "," + obj.room_id + "," + Datetime::Union(obj.registeddate) +"," + Datetime::Union(obj.finishdate) +"," + obj.content;
    return str;
}


void add_problem()
{
    ofstream inputFile("problem.txt", std::ios::app)
    string str, problem_id;
    if (inputFile.is_open()) { 
        inputFile <<  Union(*this);
        inputFile.close(); 
    } else {
        cout << "Error Opening File problem.txt" << endl;
    }
    
}

void problem::display(List<problem>& L)
{
    ifstream inputFile;
    inputFile.open("problem.txt");
    string str;
    problem obj;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            obj = Split(str);
            L.push_back(obj);
        }
    }
}
void problem::find_problem(List<customer>&L)
{
    ifstream inputFile;
    inputFile.open("customer.txt");
    string str;
    customer obj;
    while (getline(inputFile, str))
    {
        obj = Split(str);
        if (customer_id == obj.customer_id)
        {
           L.push_back(obj);
        }
    };
}
static void view_solved_problem(List<problem> &);
static void view_unsolved_problem(List<problem> &);
static bool find_problem(List<problem> &);
static bool find_idproblem(string, List, problem > &);
static void solve(problem &);