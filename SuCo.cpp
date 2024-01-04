#include "SuCo.h"

int SuCo::cnt = 0;
SuCo::SuCo(string problem_id, string room_id, ThoiGian registeddate, ThoiGian finishdate, string content, bool status)
    : problem_id(problem_id), room_id(room_id), registeddate(registeddate), finishdate(finishdate), content(content), status(status)
{
}
SuCo::~SuCo()
{
}
string SuCo::get_problem_id() const
{
    return this->problem_id;
}
void SuCo::set_problem_id(string problem_id)
{
    this->problem_id = problem_id;
}

string SuCo::get_room_id() const
{
    return this->room_id;
}
void SuCo::set_room_id(string room_id)
{
    this->room_id = room_id;
}
ThoiGian SuCo::get_registeddate() const
{
    return this->registeddate;
}
void SuCo::set_registeddate(ThoiGian registeddate)
{
    this->registeddate = registeddate;
}
ThoiGian SuCo::get_finishdate() const
{
    return this->finishdate;
}
void SuCo::set_finishdate(ThoiGian finishdate)
{
    this->finishdate = finishdate;
}

string SuCo::get_content() const
{
    return this->content;
}
void SuCo::set_content(string content)
{
    this->content = content;
}
bool SuCo::get_status() const
{
    return this->status;
}
void SuCo::set_status(bool status)
{
    this->status = status;
}
istream &operator>>(istream &i, SuCo &obj)
{
    cin.ignore();
    obj.set_problem_id(ChuyenDoi::CreateID("SuCo.txt"));
    List<Phong> room;
    ThoiGian date;
    obj.registeddate = date;
    gotoXY(4, 5);
    cout << "Content: ";
    getline(i, obj.content);
    return i;
}

void SuCo::write_File(List<string> &L)
{
    ofstream inputFile;
    inputFile.open("SuCo.txt", std::ios::out | std::ios::trunc);
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
        cout << "Error Opening File SuCo.txt" << endl;
    }
}
SuCo SuCo::Split(string str)
{
    string problem_id, room_id, registeddate, finishdate, content;
    bool status;
    ThoiGian time1, time2;
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
                time1 = ThoiGian::Split(registeddate);
            }
            else if (id == 4)
            {
                finishdate = str.substr(begin, end - begin);
                time2 = ThoiGian::Split(finishdate);
            }
            else if (id == 5)
            {
                content = str.substr(begin, end - begin);
            }
            else
            {
                status = ChuyenDoi::str_to_bool(str.substr(begin, end - begin));
            }
            ++id;
            begin = end + 1;
        }
        end++;
    }
    return SuCo(problem_id, room_id, time1, time2, content, status);
}
string SuCo::Union(SuCo &obj)
{
    string str = obj.problem_id + "," + obj.room_id + "," + ThoiGian::Union(obj.registeddate) + "," + ThoiGian::Union(obj.finishdate) + "," + obj.content + "," + ChuyenDoi::bool_to_str(obj.status);
    return str;
}

void SuCo::add_problem()
{
    ofstream inputFile("SuCo.txt", std::ios::app);
    string str;
    if (inputFile.is_open())
    {
        str = Union(*this);
        inputFile << str << '\n';
        inputFile.close();
    }
    else
    {
        cout << "Error Opening File SuCo.txt" << endl;
    }
}

void SuCo::display(List<SuCo> &L, int k)
{
    ifstream inputFile;
    inputFile.open("SuCo.txt");
    string str;
    SuCo obj;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            obj = Split(str);
            if (k == 0)
            {
                L.push_back(obj);
            }
            else if (k == 1)
            {
                if (obj.status)
                    L.push_back(obj);
            }
            else
            {
                if (!obj.status)
                    L.push_back(obj);
            }
        }
    }
    inputFile.close();
}
int SuCo::NumOfProblem()
{
    ifstream inputFile;
    inputFile.open("SuCo.txt");
    string str;
    SuCo obj;
    int ans = 0;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            obj = Split(str);
            if (!obj.status)
                ans++;
        }
    }
    inputFile.close();
    return ans;
}

void SuCo::find_idproblem(string id, List<SuCo> &L)
{
    ifstream inputFile;
    inputFile.open("SuCo.txt");
    string str;
    SuCo obj;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            obj = Split(str);
            if (id == obj.problem_id)
                L.push_back(obj);
        }
    }
}
void SuCo::solve(SuCo &obj1)
{
    ifstream inputFile;
    inputFile.open("SuCo.txt");
    string str;
    SuCo obj;
    List<string> L;
    while (getline(inputFile, str))
    {
        if (str.size())
        {
            obj = Split(str);
            if (obj1.problem_id != obj.problem_id)
                L.push_back(str);
        }
    }
    L.push_back(Union(obj1));
    write_File(L);
}