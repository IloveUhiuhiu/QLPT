#include "problem.h"

int problem::cnt= 0;
problem::problem(string problem_id, string room_id, Datetime registeddate, Datetime finishdate, string content, bool status)
: problem_id(problem_id), room_id(room_id), registeddate(registeddate), finishdate(finishdate), content(content), status(status)
{
}
problem::~problem()
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
bool problem::get_status() const
{
    return this->status;
}
void problem::set_status(bool status)
{
    this->status = status;
}
istream &operator>>(istream &i, problem &obj)
{
    cin.ignore();
    List<Room> room;
    do
    {
        cout << "Enter RoomID: ";
        getline(i, obj.room_id);
        Room::find_idroom(obj.room_id,room);
        if (room[0].getRoomID() != obj.room_id)
        {
            cout << "Room Not Found.Try Again!" << endl;
        }
    } while (room[0].getRoomID() != obj.room_id);
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
    bool status;
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
            else if(id == 5)
            {
                content = str.substr(begin, end - begin);
            } else {
                status = Convert::str_to_bool(str.substr(begin, end - begin));
            }
            ++id;
            begin = end + 1;
        }
        end++;
    }
    return problem(problem_id, room_id,time1,time2,content,status);
}
string problem::Union(problem &obj)
{
    string str = obj.problem_id + "," + obj.room_id + "," + Datetime::Union(obj.registeddate) +"," + Datetime::Union(obj.finishdate) +"," + obj.content + "," + Convert::bool_to_str(obj.status);
    return str;
}


void problem::add_problem()
{
    ofstream inputFile("problem.txt", std::ios::app);
    string str;
    if (inputFile.is_open()) { 
        str = Union(*this);
        inputFile << str << '\n';
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

void problem::view_solved_problem(List<problem> &L)
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
            if (obj.status) L.push_back(obj);
        }
    }
}
void problem::view_unsolved_problem(List<problem> &L)
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
            if (!obj.status) L.push_back(obj);
        }
    }
}
void problem::find_idproblem(string id, List<problem > &L)
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
            if (id == obj.problem_id) L.push_back(obj);
        }
    }
}
void problem::solve(problem &obj1)
{   
    ifstream inputFile;
    inputFile.open("problem.txt");
    string str;
    problem obj;
    List<string> L;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            obj = Split(str);
            if (obj1.problem_id != obj.problem_id) L.push_back(str);
        }
    } 
    L.push_back(Union(obj1));
    write_File(L);
}