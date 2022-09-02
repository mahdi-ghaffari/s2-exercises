#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

enum error
{
    invalid_tokenizer_input,
    invalid_command
};

struct stu_info_t
{
    vector<string> names;
    vector<string> scores;
    int stu_num{0};
};

void get_student_info(string filename, stu_info_t *stu_info);
void tokenizer(string s, char del, string score_name[2]);
void gen_error(error msg);
void show_menu();
void cmd_manager(stu_info_t stu_info, string command);
void show_grades();
void show_best_grade(stu_info_t stu_info);
void calculate_class_avg(stu_info_t stu_info);
void get_failed_students(stu_info_t stu_info);

int main(int argc, char *argv[])
{
    string filename("grades.txt");
    stu_info_t stu_info;
    get_student_info(filename, &stu_info);

    while (true)
    {
        show_menu();

        string command;
        cout << "Select Command >" << " ";
        cin >> command;
        cout <<endl;

        if (command.compare("0") == 0)
            break;

        unordered_set<string> commands = {"1", "2", "3", "4"};
        if(commands.count(command) == 0)
        {
            gen_error(invalid_command);
            continue;
        }

        cmd_manager(stu_info, command);
    }
}

void show_menu()
{
    ifstream f("menu.txt");
    if (f.is_open())
        std::cout << f.rdbuf()<<endl;
}

void cmd_manager(stu_info_t stu_info, string command)
{
    int cmd = stoi(command);
    switch ((int)cmd)
    {
    case 1:
        show_grades();
        break;

    case 2:
        show_best_grade(stu_info);
        break;

    case 3:
        calculate_class_avg(stu_info);
        break;

    case 4:
        get_failed_students(stu_info);
        break;

    default:
        break;
    }
}

void show_grades()
{
    ifstream f("grades.txt");
    if (f.is_open())
        std::cout << f.rdbuf()<< endl << endl ;
}

void show_best_grade(stu_info_t stu_info)
{
    int max_id = 0;
    for (size_t i = 1; i < stu_info.stu_num; i++)
    {
        if(stof(stu_info.scores[max_id]) < stof(stu_info.scores[i]))
            max_id = i;
    }
    ostringstream out;  
    out << "The Best Grade is "<< stu_info.scores[max_id]<<" from "<< stu_info.names[max_id]<<endl;;
    cout << out.str() << endl << endl ;
}

void calculate_class_avg(stu_info_t stu_info)
{
    float sum{0};
    for (size_t i = 0; i < stu_info.stu_num; i++)
    {
        sum+= stof(stu_info.scores[i]);
    }
    float avg = sum/(float)stu_info.stu_num;

    ostringstream out;  
    out << "Class average grade is "<< avg<<endl;
    cout << out.str() << endl << endl ;
}

void get_failed_students(stu_info_t stu_info)
{
    vector<int> failed_id;

    for (size_t i = 0; i < stu_info.stu_num; i++)
    {
        if(stof(stu_info.scores[i]) < 10.0)
        {
            ostringstream out;  
            out << stu_info.scores[i] <<"   "<<stu_info.names[i]<<endl;
            cout << out.str() << endl << endl ;
        }
    }
}

void get_student_info(string filename, stu_info_t *stu_info)
{
    string line;
    ifstream file(filename);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            string score_name[2];
            tokenizer(line, ' ', score_name);
            stu_info->scores.push_back(score_name[0]);
            stu_info->names.push_back(score_name[1]);
            stu_info->stu_num++;
        }
        file.close();
    }
}

void gen_error(error msg)
{
    switch (msg)
    {
    case invalid_tokenizer_input:
        cout << "The string input of tokenizer has problem!" << endl;
        break;

    case invalid_command:
        cout << "Invalid Command!" << endl << endl ;
        break;

    default:
        break;
    }
}

void tokenizer(string s, char del, string score_name[2])
{
    stringstream ss(s);
    string word;
    int cnt = 0;
    while (!ss.eof())
    {
        getline(ss, word, del);
        int res = word.compare("");
        if (res <= 0)
            continue;

        if (cnt > 2)
            gen_error(invalid_tokenizer_input);

        score_name[cnt] = word;
        cnt++;
    }
}
