#include <bits/stdc++.h>

using namespace std;

class Fraction
{
    int numerator;
    int denominator;

    int gcd(int max, int min)
    {
        int m, n;
        if (max > min)
        {
            m = max;
            n = min;
        }
        else
        {
            m = min;
            n = max;
        }
        m = abs(m);
        n = abs(n);
        if (n == 0)
            return m;
        int a = gcd(n, m % n);
        return a;
    }

public:
    // constructors
    Fraction()
    {
        numerator = 0;
        denominator = 1;
    }
    Fraction(int x)
    {
        numerator = x;
        denominator = 1;
    }
    Fraction(int num, int den)
    {
        if (den == 0)
        {
            cout << " Denominator cannot be 0, Setting to 1" << endl;
            den = 1;
        }
        int a = gcd(num, den);
        numerator = num / a;
        denominator = den / a;
    }
    // Destructor
    ~Fraction()
    {
    }
    // Getters
    int getNumerator() { return numerator; }
    int getDenominator() { return denominator; }

    // setters :
    void setNumerator(int x) { numerator = x; }
    void setDenominator(int x) { denominator = x; }

    // methods:
    Fraction add(const Fraction &f)
    {

        Fraction d(numerator, denominator);
        d.numerator = (d.numerator * f.denominator) + (f.numerator * d.denominator);
        d.denominator = d.denominator * f.denominator;
        int a = gcd(d.numerator, d.denominator);
        d.numerator = d.numerator / a;
        d.denominator = d.denominator / a;
        return d;
    }

    Fraction add(int n)
    {
        Fraction d(numerator, denominator);
        d.numerator = d.numerator + (d.denominator * n);
        int a = gcd(d.numerator, d.denominator);
        d.numerator = d.numerator / a;
        d.denominator = d.denominator / a;
        return d;
    }
    Fraction sub(const Fraction &f)
    {
        Fraction d(numerator, denominator);
        d.numerator = (d.numerator * f.denominator) - (f.numerator * d.denominator);
        d.denominator = d.denominator * f.denominator;
        int a = gcd(d.numerator, d.denominator);
        d.numerator = d.numerator / a;
        d.denominator = d.denominator / a;
        return d;
    }
    Fraction sub(int n)
    {
        Fraction d(numerator, denominator);
        d.numerator = d.numerator - (d.denominator * n);
        int a = gcd(d.numerator, d.denominator);
        d.numerator = d.numerator / a;
        d.denominator = d.denominator / a;
        return d;
    }
    Fraction mul(const Fraction &f)
    {
        Fraction d(numerator, denominator);
        d.numerator = d.numerator * f.numerator;
        d.denominator = d.denominator * f.denominator;
        int a = gcd(d.numerator, d.denominator);
        d.numerator = d.numerator / a;
        d.denominator = d.denominator / a;
        return d;
    }
    Fraction mul(int n)
    {
        Fraction d(numerator, denominator);
        d.numerator *= n;
        int a = gcd(d.numerator, d.denominator);
        d.numerator = d.numerator / a;
        d.denominator = d.denominator / a;
        return d;
    }

    Fraction div(const Fraction &f)
    {

        Fraction d(numerator, denominator);
        d.numerator = d.numerator * f.denominator;
        d.denominator = d.denominator * f.numerator;
        int a = gcd(d.numerator, d.denominator);
        d.numerator = d.numerator / a;
        d.denominator = d.denominator / a;
        return d;
    }
    Fraction div(int n)
    {
        if (n == 0)
        {
            cout << "Cannot divide by 0" << endl;
            return *this;
        }
        Fraction d(numerator, denominator);
        d.denominator *= n;
        int a = gcd(d.numerator, d.denominator);
        d.numerator = d.numerator / a;
        d.denominator = d.denominator / a;
        return d;
    }
    void print()
    {
        if (denominator < 0){
            cout << -numerator<<" / "<< -denominator <<endl ;
            return ;
        }
        cout << numerator << " / " << denominator << endl;
    }
};

// FractionCollection
class FractionCollection
{
    Fraction *fractions;
    int maxlength;
    int length = 0;

public:
    FractionCollection()
    {
        fractions = new Fraction[10];
        maxlength = 10;
        length = 0;
    }
    FractionCollection(int max_size)
    {
        fractions = new Fraction[max_size];
        maxlength = max_size;
        length = 0;
    }
    FractionCollection(const FractionCollection &ob)
    {
        maxlength = ob.maxlength;
        length = ob.maxlength;
        fractions = new Fraction[maxlength];
        for (int i = 0; i < length; i++)
        {
            *(fractions + i) = *(ob.fractions + i);
        }
    }
    ~FractionCollection()
    {
        delete[] fractions;
    }
    int getLength() { return length; }
    int getMaxLength() { return maxlength; }

    void insert(Fraction f)
    {
        fractions[length] = f;
        length++;
    }
    void insert(int pos, Fraction f)
    {
        if (pos > length)
        {
            cout << "Position if greater than length, Inserted at the end" << endl;
            insert(f);
        }
        if (length == maxlength)
        {
            cout << "Capacity reached" << endl;
        }
        else
        {
            Fraction prev = fractions[pos], curr;
            for (int i = pos + 1; i <= length; i++)
            {
                curr = fractions[i];
                fractions[i] = prev;
                prev = curr;
            }
            fractions[pos] = f;
            length++;
        }
    }

    void remove()
    {

        length--;
    }
    void remove(Fraction f)
    {
        int target = -1;
        for (int i = 0; i < length; i++)
        {
            if (fractions[i].getNumerator() == f.getNumerator() and fractions[i].getDenominator() == f.getDenominator())
            {
                target = i;
                break;
            }
        }
        for (int i = target; i < length - 1; i++)
        {
            fractions[i] = fractions[i + 1];
        }
        length--;
    }
    void remove(int pos)
    {
        for (int i = pos; i < length - 1; i++)
        {
            fractions[i] = fractions[i + 1];
        }
        length--;
    }
    Fraction add(int start, int end)
    {
        Fraction f(0, 1);
        for (int i = start; i <= end; i++)
        {
            f = fractions[i].add(f);
        }
        return f;
    }
    Fraction mul(int start, int end)
    {
        Fraction f(1, 1);
        for (int i = start; i <= end; i++)
        {
            f = fractions[i].mul(f);
        }
        return f;
    }
    Fraction sub(int p1, int p2)
    {
        Fraction f(0, 1);
        f = fractions[p1].sub(fractions[p2]);
        return f;
    }
    Fraction div(int p1, int p2)
    {
        Fraction f(0, 1);
        f = fractions[p1].div(fractions[p2]);
        return f;
    }
    Fraction getmax(){
        float a ;float max =((float)fractions[0].getNumerator()) / (fractions[0].getDenominator());
        int target=0 ;
        for( int i =0 ; i < length; i++){
            a = ((float)fractions[i].getNumerator()) / (fractions[i].getDenominator());
            if ( a > max){
                max = a ;
                target = i ;
            }
        }
        return fractions[target];
    }
    Fraction getmin(){
        float a ;float max =((float)fractions[0].getNumerator()) / (fractions[0].getDenominator());
        int target=0 ;
        for( int i =0 ; i < length; i++){
            a = ((float)fractions[i].getNumerator()) / (fractions[i].getDenominator());
            if ( a < max){
                max = a ;
                target = i ;
            }
        }
        return fractions[target];
    }

    void print()
    {
        cout << "Fractions" << endl;
        cout << "........................"<<endl ;
        for (int i = 0; i < length; i++)
        {
            cout <<"Fraction "<<i<<" :";
            fractions[i].print();
        }
        cout <<"Max  :" ; this->getmax().print();
        cout <<"Min  :" ; this->getmin().print(); 
        cout <<"Sum  :" ; this->add(0,length-1).print();
        cout <<"Product  :" ; this->mul(0,length-1).print();
    }
};

int main()
{
    // create Fraction with numerator, denominator
    Fraction a(5, 2), b(7, 2), c(9, 2), d(28, 5);
    cout << "Fraction" << endl;
    cout << "-------------------------------" << endl;
    cout << "A: ";
    a.print();
    cout << "B: ";
    b.print();
    cout << endl;
    cout << "Add(a,b): ";
    a.add(b).print();
    cout << "Add(a,2): ";
    a.add(2).print();
    cout << "Sub(a,b) ";
    a.sub(b).print();
    cout << "Sub(a,2) ";
    a.sub(2).print();
    cout << "Mul(a,b): ";
    a.mul(b).print();
    cout << "Mul(a,2): ";
    a.mul(2).print();
    cout << "Div(a,b): ";
    a.div(b).print();
    cout << "Div(a,2): ";
    a.div(2).print();
    cout << "Div(a,0): ";
    a.div(0).print();

    Fraction e, f(5), g(10);
    FractionCollection fc(10);
    fc.insert(a);
    fc.insert(b);
    fc.insert(c);
    fc.print();
    cout << "Sub(Pos0, Pos1): ";
    fc.sub(0, 1).print(); // subtracts the fraction at pos1 from fraction at pos0
    cout << "Div(Pos0, Pos1): ";
    fc.div(0, 1).print(); // divides the fraction at pos0 by the fraction at pos1
    fc.remove(1);         // removed 'b'
    fc.print();
    
    fc.remove(a);
    
    fc.print();
    fc.insert(d);
    fc.insert(0, e); // insert at pos0
    fc.insert(f);
    fc.insert(g);
    fc.print();

    fc.remove(); // removed the last fraction
    fc.print();  // notice the output
   
    return 0;
}