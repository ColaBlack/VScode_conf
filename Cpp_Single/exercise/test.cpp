#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Student
{
public:
    string id;
    string name;
    string sex;
    int score;

    void print() const
    {
        cout << "学号: " << id;
        cout << ", 姓名: " << name;
        cout << ", 性别: " << sex;
        cout << ", 成绩: " << score << endl;
    }
};

class StudentList
{
private:
    vector<Student> students;

public:
    void insert()
    {
        cout << "请输入学生的学号、姓名、性别、成绩，以空格分隔: ";
        string id, name, sex;
        int score;
        cin >> id >> name >> sex >> score;
        students.push_back(Student{id, name, sex, score});
    }

    void searchById() const
    {
        cout << "请输入待查询的学生学号: ";
        string id;
        cin >> id;
        auto it = find_if(students.begin(), students.end(), [&](const Student &s)
                          { return s.id == id; });
        if (it == students.end())
        {
            cout << "Not found" << endl;
        }
        else
        {
            it->print();
        }
    }

    void searchByScore() const
    {
        cout << "请输入待查询的成绩: ";
        int score;
        cin >> score;
        bool found = false;
        for (const auto &student : students)
        {
            if (student.score >= score)
            {
                found = true;
                student.print();
            }
        }
        if (!found)
        {
            cout << "Not found" << endl;
        }
    }
};

int getMenuChoice()
{
    int choice;
    cout << "\n按0输入数据，1按学号查询，2按成绩查询，3退出\n请输入选择: ";
    cin >> choice;
    return choice;
}

int main()
{
    StudentList studentList;
    while (true)
    {
        int choice = getMenuChoice();
        switch (choice)
        {
        case 0:
            int numStudents;
            cout << "请输入插入学生数目: ";
            cin >> numStudents;
            for (int i = 0; i < numStudents; i++)
            {
                studentList.insert();
            }
            break;
        case 1:
            studentList.searchById();
            break;
        case 2:
            studentList.searchByScore();
            break;
        case 3:
            return 0;
        default:
            cout << "请重新输入" << endl;
        }
    }
}
