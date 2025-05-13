#include <iostream>
#include <cmath>
using namespace std;

// Абстрактний клас
class DataSet {
public:
    virtual double Norm() = 0;
    virtual void Print() = 0;
    virtual ~DataSet() {}
};

class ComplexNumber : public DataSet {
private:
    double real, imag;
public:
    ComplexNumber(double r, double i) : real(r), imag(i) {}

    double Norm() override {
        return real * real + imag * imag;
    }

    void Print() override {
        cout << "ComplexNumber: " << real << " + " << imag << "i" << endl;
    }
};

class Vector10 : public DataSet {
private:
    double v[10];
public:
    Vector10() {
        cout << "Enter 10 elements of the vector:\n";
        for (int i = 0; i < 10; i++) {
            cout << "Element [" << i << "]: ";
            cin >> v[i];
        }
    }

    double Norm() override {
        double sum = 0;
        for (int i = 0; i < 10; i++)
            sum += v[i] * v[i];
        return sqrt(sum);
    }

    void Print() override {
        cout << "Vector10: ";
        for (int i = 0; i < 10; i++)
            cout << v[i] << " ";
        cout << endl;
    }
};

class Matrix2x2 : public DataSet {
private:
    double m[2][2];
public:
    Matrix2x2() {
        cout << "Enter 4 elements of 2x2 matrix (row-wise):\n";
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> m[i][j];
            }
    }

    double Norm() override {
        double sum = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                sum += m[i][j] * m[i][j];
        return sqrt(sum);
    }

    void Print() override {
        cout << "Matrix2x2:" << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                cout << m[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "How many data objects do you want to create? ";
    cin >> n;

    DataSet* arr[100]; 

    for (int i = 0; i < n; i++) {
        int type;
        cout << "\nChoose data type for object " << i + 1 << ":\n";
        cout << "1 - ComplexNumber\n";
        cout << "2 - Vector10\n";
        cout << "3 - Matrix2x2\n";
        cout << "Enter choice: ";
        cin >> type;

        switch (type) {
        case 1: {
            double r, im;
            cout << "Enter real part: "; cin >> r;
            cout << "Enter imaginary part: "; cin >> im;
            arr[i] = new ComplexNumber(r, im);
            break;
        }
        case 2:
            arr[i] = new Vector10();
            break;
        case 3:
            arr[i] = new Matrix2x2();
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            i--;
        }
    }

    cout << "\n--- Data Summary ---\n";
    for (int i = 0; i < n; i++) {
        arr[i]->Print();
        cout << "Norm = " << arr[i]->Norm() << "\n\n";
    }
    for (int i = 0; i < n; i++)
        delete arr[i];

    return 0;
}
