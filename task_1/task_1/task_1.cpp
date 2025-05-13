#include <iostream>
using namespace std;

class Base {
protected:
    int baseVal;
public:
    Base() : baseVal(1) {}
};

class D1 : public Base {
protected:
    int d1Val;
public:
    D1() : d1Val(2) {}
};

class D2 : public Base {
protected:
    int d2Val;
public:
    D2() : d2Val(3) {}
};

class D12 : public D1, public D2 {
protected:
    int d12Val;
public:
    D12() : d12Val(4) {}
};

class R : public D12 {
protected:
    int rVal;
public:
    R() : rVal(5) {}
};

class BaseV {
protected:
    int baseVal;
public:
    BaseV() : baseVal(10) {}
};

class D1V : virtual public BaseV {
protected:
    int d1Val;
public:
    D1V() : d1Val(20) {}
};

class D2V : virtual public BaseV {
protected:
    int d2Val;
public:
    D2V() : d2Val(30) {}
};

class D12V : public D1V, public D2V {
protected:
    int d12Val;
public:
    D12V() : d12Val(40) {}
};

class RV : public D12V {
protected:
    int rVal;
public:
    RV() : rVal(50) {}
};

int main() {
    cout << "--- Without virtual ---" << endl;
    cout << "Base: " << sizeof(Base) << endl;
    cout << "D1: " << sizeof(D1) << endl;
    cout << "D2: " << sizeof(D2) << endl;
    cout << "D12: " << sizeof(D12) << endl;
    cout << "R: " << sizeof(R) << endl;

    cout << "\n--- With virtual ---" << endl;
    cout << "BaseV: " << sizeof(BaseV) << endl;
    cout << "D1V: " << sizeof(D1V) << endl;
    cout << "D2V: " << sizeof(D2V) << endl;
    cout << "D12V: " << sizeof(D12V) << endl;
    cout << "RV: " << sizeof(RV) << endl;

    return 0;
}
