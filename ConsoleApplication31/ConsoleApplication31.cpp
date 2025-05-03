#include <iostream>
#include <vector>
using namespace std;

class Project {
public:
    string name;
    string description;
    string status;

    Project(string n, string d) : name(n), description(d), status("активний") {}

    void change_status(string new_status) {
        status = new_status;
    }

    void show_info() {
        cout << "Проєкт: " << name << "\nОпис: " << description << "\nСтатус: " << status << "\n";
    }
};

class Task {
public:
    string name;
    string assignee;
    string status;

    Task(string n, string a) : name(n), assignee(a), status("в процесі") {}

    void change_assignee(string new_assignee) {
        assignee = new_assignee;
    }

    void change_status(string new_status) {
        status = new_status;
    }

    void show_task() {
        cout << "Завдання: " << name << "\nВиконавець: " << assignee << "\nСтатус: " << status << "\n";
    }
};

class Employee {
public:
    string name;
    string email;

    Employee(string n, string e) : name(n), email(e) {}

    void show_info() {
        cout << "Працівник: " << name << "\nEmail: " << email << "\n";
    }
};

class ProjectManager {
public:
    vector<Project> projects;
    vector<Task> tasks;

    void add_project(string name, string desc) {
        projects.push_back(Project(name, desc));
    }

    void add_task(string name, string assignee) {
        tasks.push_back(Task(name, assignee));
    }

    void show_all_projects() {
        for (auto& p : projects) {
            p.show_info();
            cout << "------------------\n";
        }
    }

    void show_all_tasks() {
        for (auto& t : tasks) {
            t.show_task();
            cout << "------------------\n";
        }
    }
};

int main() {
    system("chcp 1251>null");
    ProjectManager manager;

    manager.add_project("Мобільний додаток", "Розробка додатку для Android/iOS");
    manager.add_task("Створити дизайн", "Іван Петренко");
    manager.add_task("Програмування API", "Олена Сидоренко");

    cout << "\n🗂 Усі проєкти:\n";
    manager.show_all_projects();

    cout << "\n📝 Усі завдання:\n";
    manager.show_all_tasks();

    return 0;
}
