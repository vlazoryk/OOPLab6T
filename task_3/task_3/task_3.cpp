#include <iostream>
#include <string>
using namespace std;

class Human {
protected:
    string name;
    int age;
public:
    Human(string n = "", int a = 0) : name(n), age(a) {}
    virtual ~Human() {}

    virtual void read() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    virtual void print() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Father : virtual public Human {
protected:
    string job;
public:
    Father(string n = "", int a = 0, string j = "") : Human(n, a), job(j) {}
    virtual ~Father() {}

    void read() override {
        Human::read();
        cout << "Enter father's job: ";
        cin >> job;
    }

    void print() const override {
        Human::print();
        cout << "Father's Job: " << job << endl;
    }
};

class Mother : virtual public Human {
protected:
    string hobby;
public:
    Mother(string n = "", int a = 0, string h = "") : Human(n, a), hobby(h) {}
    virtual ~Mother() {}

    void read() override {
        Human::read();
        cout << "Enter mother's hobby: ";
        cin >> hobby;
    }

    void print() const override {
        Human::print();
        cout << "Mother's Hobby: " << hobby << endl;
    }
};

class Daughter : public Father, public Mother {
private:
    string school;
public:
    Daughter(string n = "", int a = 0, string j = "", string h = "", string s = "")
        : Human(n, a), Father(n, a, j), Mother(n, a, h), school(s) {
    }

    ~Daughter() override {}

    void read() override {
        Human::read();
        cout << "Enter father's job: ";
        cin >> job;
        cout << "Enter mother's hobby: ";
        cin >> hobby;
        cout << "Enter daughter's school: ";
        cin >> school;
    }

    void print() const override {
        cout << "Daughter Information:\n";
        Human::print();
        cout << "Father's Job: " << job << endl;
        cout << "Mother's Hobby: " << hobby << endl;
        cout << "School: " << school << endl;
    }
};

// Головна функція
int main() {
    Daughter d;
    d.read();
    cout << endl;
    d.print();
    return 0;
}
