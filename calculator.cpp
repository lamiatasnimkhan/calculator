#include<bits/stdc++.h>
#include<math.h>
using namespace std;

class Calculator
{
protected:
    double result;
    double mem;
public:
    Calculator()
    {
        result =0.0;
        mem=0.0;
    }
    void add()
    {
        string a, b;
        cout << "Enter the first number: ";
        cin >> a;
        cout << "Enter the second number: ";
        cin >> b;
        result = stoint(a) + stoint(b);
        cout << "The result is " << result;
    }
    void subtract()
    {
        string a, b;
        cout << "Enter the first number: ";
        cin >> a;
        cout << "Enter the second number: ";
        cin >> b;
        result = stoint(a) - stoint(b);
        cout << "The result is " << result;
    }
    void multiply()
    {
        string a, b;
        cout << "Enter the first number: ";
        cin >> a;
        cout << "Enter the second number: ";
        cin >> b;
        result = stoint(a) * stoint(b);
        cout << "The result is " << result;
    }
    void divide()
    {
        string a, b;
        cout << "Enter the first number: ";
        cin >> a;
        cout << "Enter the second number: ";
        cin >> b;
        result = stoint(a) / stoint(b);
        cout << "The result is " << result;
    }
    void factorial()
    {
        string a;
        cout<<"ENTER THE NUMBER: ";
        cin>>a;
        int n=stoint(a);

        int fact=1;
        for(int i=1; i<=n; i++)
        {
            fact=fact*i;
        }
        result=fact;
        cout<<"The result is:"<<result;
    }
    void square()
    {
        string a;
        cout << "Enter a number: ";
        cin >> a;
        double sA = stoint(a);
        result = sA * sA;
        cout << "The result is " << result;
    }
    void sqrt()
    {
        string a;
        cout << "Enter a number: ";
        cin >> a;
        result =std:: sqrt(stoint(a));
        cout << "The result is " << result;
    }
    void setMem()
    {
        string a;
        cout << "Enter a number: ";
        cin >> a;
        mem = stoint(a);
        cout << "The mem is " << mem;
    }

    void printMemory()
    {
        cout << "The memory is " << mem;
    }
    virtual double stoint( string& input)
    {
        if (input == "result")
        {
            return result;
        }
        else if (input == "mem")
        {
            return mem;
        }
        else
        {
            return stod(input);
        }
    }

    virtual void welcome()
    {
        cout << "\n\nEnter an operation (+, -, /, *, sqrt, square, change,factorial, setmem, printmem) or exit"<<endl<<endl;
    }
    virtual void calc_operation( string& input)
    {
        if (input == "+" )
        {
            add();
        }
        else if (input == "-" )
        {
            subtract();
        }
        else if (input == "/")
        {
            divide();
        }
        else if (input == "*" )
        {
            multiply();
        }
        else if (input == "sqrt")
        {
            sqrt();
        }
        else if (input == "square")
        {
            square();
        }
        else if (input == "setmem")
        {
            setMem();
        }
        else if (input == "printmem")
        {
            printMemory();
        }
        else if (input == "factorial")
        {
            factorial();
        }

    }


};


class Scientific : public Calculator
{
public:
    Scientific() {}

    void welcome()
    {
        cout << "\n\nEnter one of:"<<endl
             << "+, -, /, *, sqrt, square, change, setmem, printmem,factorial, sin, cos, log, tan, ln, abs, pow"<<endl
             << "or exit"<<endl;
    }
    void calc_operation( string& input)
    {
        Calculator::calc_operation(input);

        if (input == "sin")
        {
            sin();
        }
        else if (input == "cos")
        {
            cos();
        }
        else if (input == "tan")
        {
            cos();
        }
        else if (input == "ln")
        {
            ln();
        }
        else if (input == "log")
        {
            log();
        }
        else if (input == "abs")
        {
            abs();
        }
        else if (input == "pow")
        {
            pow();
        }
    }

    void sin()
    {
        string a;
        cout << "Enter a number: ";
        cin >> a;
        result=std::sin(stoint(a));
        cout << "The result is " << result;
    }
    void cos()
    {
        string a;
        cout << "Enter a number: ";
        cin >> a;
        result =std::cos(stoint(a));
        cout << "The result is " << result;
    }
    void tan()
    {
        string a;
        cout << "Enter a number: ";
        cin >> a;
        result =std:: tan(stoint(a));
        cout << "The result is " << result;
    }
    void ln()
    {
        string a;
        cout << "Enter a number: ";
        cin >> a;
        result =std::log(stoint(a));
        cout << "The result is " << result;
    }
    void log()
    {
        string a,b;
        cout << "Enter the base: ";
        cin >> a;
        cout << "Enter a number: ";
        cin >> b;
        result =std:: log(stoint(b))/std::log(stoint(a));
        cout << "The result is " << result;
    }
    void abs()
    {
        string a;
        cout << "Enter a number: ";
        cin >> a;
        result = std::abs(stoint(a));
        cout << "The result is " << result;
    }
    void pow()
    {
        string a, b;
        cout << "Enter the base: ";
        cin >> a;
        cout << "Enter the exponent: ";
        cin >> b;
        result = std::pow(stoint(a), stoint(b));
        cout << "The result is " << result;
    }
};

int main()
{
    Calculator calc;
    Scientific sci;

    Calculator *Ptr = &calc;
    int sciActive = 0;

    cout << "CALCULATOR APP"<<endl<<endl
         << "This calculator has 2 modes:normal and scientific."<<endl
         << "'change' keyword can be used to change the mode"<<endl<<endl
         << "This app has 2 other special keywords, result and memory."<<endl
         << "result stores the result of the previous calculation."<<endl
         << "memory allows you to store and access a number."<<endl
         << "Both can be used instead of numbers during calculations."<<endl;


    Ptr->welcome();
    cout << setprecision(15);
    string input = "";
    while ( input != "exit")
    {
        cin >> input;
        if (input == "change")
        {
            if (sciActive)
            {
                Ptr = &calc;
                sciActive = 0;
                cout << endl<<"Simple Calculator Activated";
            }
            else
            {
                Ptr = &sci;
                sciActive = 1;
                cout << endl<<"Scientific Calculator Activated";
            }
        }
        Ptr->calc_operation(input);
        Ptr->welcome();
    }
    return 0;
}





