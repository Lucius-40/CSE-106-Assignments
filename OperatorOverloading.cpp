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

    // Getters
    int getNumerator() { return numerator; }
    int getDenominator() { return denominator; }

    // setters :
    void setNumerator(int x) { numerator = x; }
    void setDenominator(int x) { denominator = x; }

    Fraction operator+(const Fraction &f)
    {
        Fraction d(numerator, denominator);
        d.numerator = (d.numerator * f.denominator) + (f.numerator * d.denominator);
        d.denominator = d.denominator * f.denominator;
        int a = gcd(d.numerator, d.denominator);
        d.numerator = d.numerator / a;
        d.denominator = d.denominator / a;
        return d;
    }
    Fraction operator+(float f)
    {
        int fnum = (int)round(f * 100);
        int den = 100;
        Fraction d(fnum, den);
        return *this + d;
    }
    Fraction operator-(const Fraction &f)
    {
        Fraction d(numerator, denominator);
        d.numerator = (d.numerator * f.denominator) - (f.numerator * d.denominator);
        d.denominator = d.denominator * f.denominator;
        int a = gcd(d.numerator, d.denominator);
        d.numerator = d.numerator / a;
        d.denominator = d.denominator / a;
        return d;
    }
    Fraction operator-(float f)
    {
        int fnum = (int)round(f * 100);
        int den = 100;
        Fraction d(fnum, den);
        return *this - d;
    }
    Fraction operator*(const Fraction &f)
    {
        Fraction d(numerator, denominator);
        d.numerator = d.numerator * f.numerator;
        d.denominator = d.denominator * f.denominator;
        int a = gcd(d.numerator, d.denominator);
        d.numerator = d.numerator / a;
        d.denominator = d.denominator / a;
        return d;
    }
    Fraction operator*(float f)
    {
        int fnum = (int)round(f * 100);
        int den = 100;
        Fraction d(fnum, den);
        return (*this) * d;
    }
    Fraction operator/(const Fraction &f)
    {
        if (f.numerator == 0)
            throw "Cannot divide by 0\n";
        Fraction d(numerator, denominator);
        d.numerator = d.numerator * f.denominator;
        d.denominator = d.denominator * f.numerator;
        int a = gcd(d.numerator, d.denominator);
        d.numerator = d.numerator / a;
        d.denominator = d.denominator / a;
        return d;
    }
    Fraction operator/(float f)
    {
        if (f == 0)
        {
            throw "Cannot Divide by 0\n";
        }
        int fnum = (int)round(f * 100);
        int den = 100;
        Fraction d(fnum, den);
        return (*this) / d;
    }
    Fraction &operator+=(const Fraction &f)
    {
        *this = *this + f;
        return *this;
    }
    Fraction &operator+=(float f)
    {
        *this = *this + f;
        return *this;
    }
    Fraction &operator-=(const Fraction &f)
    {
        *this = *this - f;
        return *this;
    }
    Fraction &operator-=(float f)
    {
        *this = *this - f;
        return *this;
    }
    Fraction &operator*=(const Fraction &f)
    {
        *this = *this * f;
        return *this;
    }
    Fraction &operator*=(float f)
    {
        *this = *this * f;
        return *this;
    }
    Fraction &operator/=(float f)
    {
        *this = *this / f;
        return *this;
    }
    Fraction &operator/=(const Fraction &f)
    {

        *this = *this / f;
        return *this;
    }
    friend Fraction operator+(float f, const Fraction &fr);
    friend Fraction operator-(float f, const Fraction &fr);
    friend Fraction operator*(float f, const Fraction &fr);
    friend Fraction operator/(float f, const Fraction &fr);
    friend ostream &operator<<(ostream &out, const Fraction &fr);
};
Fraction operator+(float f, const Fraction &fr)
{
    int fnum = (int)round(f * 100);
    int den = 100;
    Fraction d(fnum, den);
    Fraction c = d + fr;
    return c;
}
Fraction operator-(float f, const Fraction &fr)
{
    int fnum = (int)round(f * 100);
    int den = 100;
    Fraction d(fnum, den);
    Fraction c = d - fr;
    return c;
}
Fraction operator*(float f, const Fraction &fr)
{
    int fnum = (int)round(f * 100);
    int den = 100;
    Fraction d(fnum, den);
    Fraction c = d * fr;
    return c;
}
Fraction operator/(float f, const Fraction &fr)
{
    int fnum = (int)round(f * 100);
    int den = 100;
    Fraction d(fnum, den);
    Fraction c = d / fr;
    return c;
}
ostream &operator<<(ostream &out, const Fraction &fr)
{
    out << fr.numerator << "/" << fr.denominator;
    return out;
}

class FractionVector
{
    Fraction *fractions;
    int length;
    int maxlength;

public:
    FractionVector(int maxlength = 30)
    {
        this->maxlength = maxlength;
        fractions = new Fraction[maxlength];
        length = 0;
    }
    FractionVector(int length, Fraction *frac)
    {
        fractions = new Fraction[30];
        maxlength = 30;
        this->length = length;
        for (int i = 0; i < length; i++)
        {
            fractions[i] = frac[i];
        }
    }
    FractionVector(const FractionVector &f)
    {
        length = f.length;
        maxlength = f.maxlength;
        fractions = new Fraction[maxlength];
        for (int i = 0; i < length; i++)
        {
            fractions[i] = f.fractions[i];
        }
    }

    Fraction &operator[](int n)
    {
        if (n >= length or n < 0)
            throw "Out of bounds\n";
        return fractions[n];
    }

    FractionVector operator+(const FractionVector &f)
    {
        if (f.length != length or length == 0)
        {
            throw "Dimension Mismatch";
        }
        FractionVector d(maxlength);

        d.length = length;

        for (int i = 0; i < length; i++)
        {

            d.fractions[i] = fractions[i] + f.fractions[i];
        }
        return d;
    }
    FractionVector operator-(const FractionVector &f)
    {
        if (f.length != length or length == 0)
        {
            throw "Dimension Mismatch";
        }
        FractionVector d(maxlength);

        d.length = length;

        for (int i = 0; i < length; i++)
        {

            d.fractions[i] = fractions[i] - f.fractions[i];
        }
        return d;
    }
    FractionVector operator*(const Fraction &f)
    {

        FractionVector d(maxlength);
        d.length = length;
        for (int i = 0; i < length; i++)
        {
            d.fractions[i] = fractions[i] * f;
        }
        return d;
    }
    FractionVector operator*(const FractionVector &f)
    {
        if (f.length != length or length == 0)
        {
            throw "Dimension Mismatch";
        }
        FractionVector d(maxlength);

        d.length = length;

        for (int i = 0; i < length; i++)
        {

            d.fractions[i] = fractions[i] * f.fractions[i];
        }
        return d;
    }
    FractionVector operator/(Fraction f)
    {
        if (f.getNumerator() == 0)
            throw "Cannot Divide by 0\n";

        FractionVector d(maxlength);
        d.length = length;
        for (int i = 0; i < length; i++)
        {
            d.fractions[i] = fractions[i] / f;
        }
        return d;
    }
    void addFraction(Fraction f)
    {
        if (length >= maxlength)
            throw "capacity full\n";
        fractions[length++] = f;
    }
    FractionVector &operator=(const FractionVector &f)
    {
        if (&f == this)
            return *this;
        length = f.length;
        maxlength = f.maxlength;
        delete[] fractions;
        fractions = new Fraction[maxlength];
        for (int i = 0; i < length; i++)
        {
            fractions[i] = f.fractions[i];
        }
        return *this;
    }
    ~FractionVector()
    {
        delete[] fractions;
    }
    Fraction value()
    {
        Fraction f(0);
        for (int i = 0; i < length; i++)
        {
            f = f + (fractions[i] * fractions[i]);
        }

        float g = (float)f.getNumerator() / f.getDenominator();
        g = (float)sqrt(g);
        int i = static_cast<int>(round(g * 100));
        Fraction ij(i, 100);
        return ij;
    }
    int getlength()
    {
        return length;
    }
    Fraction addElem()
    {
        Fraction sum(0);
        for (int i = 0; i < length; i++)
        {
            sum = sum + fractions[i];
        }
        return sum;
    }
    friend FractionVector operator*(Fraction f, const FractionVector &v);
    friend ostream &operator<<(ostream &out, const FractionVector &v);
};
FractionVector operator*(Fraction f, const FractionVector &v)
{
    FractionVector d(v.maxlength);
    d.length = v.length;
    for (int i = 0; i < v.length; i++)
    {
        d.fractions[i] = f * v.fractions[i];
    }
    return d;
}

ostream &operator<<(ostream &out, const FractionVector &v)
{
    out << "| ";
    for (int i = 0; i < v.length; i++)
    {
        if (i == v.length - 1)
        {
            out << v.fractions[i] << " |";
        }
        else
            out << v.fractions[i] << " , ";
    }
    out << endl;
    return out;
}

class FractionMatrix
{

    FractionVector *column, *row;
    int cols, rows;
    int maxlength;

public:
    FractionMatrix(int n)
    {
        maxlength = n;
        cols = 0;
        rows = 0;
        column = new FractionVector[n];
        row = new FractionVector[n];
    }

    FractionMatrix(int rows, FractionVector *vec)
    {
        if (rows == 0)
        {
            cols = 0;
            row = new FractionVector[maxlength];
            column = new FractionVector[maxlength];
            return;
        }
        if (rows > 30)
            throw "Too big \n";
        cols = vec[0].getlength();
        if (cols > 30)
            throw "Too big\n";
        row = new FractionVector[30];
        column = new FractionVector[30];
        maxlength = 30;
        this->rows = rows;
        for (int i = 0; i < rows; i++)
        {
            if (vec[i].getlength() != cols)
            {
                throw "All vectors must have the same length\n";
            }
            row[i] = vec[i];
        }

        // for (int i = 0; i < rows; i++)
        // {
        //     row[i] = vec[i];
        // }
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                Fraction f = row[j][i];
                try
                {
                    column[i].addFraction(f);
                }
                catch (const char *s)
                {
                    cout << s << endl;
                }
            }
        }
    }
    FractionMatrix(const FractionMatrix &f)
    {
        rows = f.rows;
        cols = f.cols;
        maxlength = f.maxlength;
        column = new FractionVector[maxlength];
        row = new FractionVector[maxlength];
        for (int i = 0; i < rows; i++)
        {
            row[i] = f.row[i];
        }
        for (int i = 0; i < cols; i++)
        {
            column[i] = f.column[i];
        }
    }
    FractionVector &operator[](int n)
    {
        if (n >= rows or n < 0)
            throw "Out of bounds\n";
        return row[n];
    }

    //  void addvector(FractionVector f){
    //     if( length >= maxlength) throw "capacity full\n";
    //     vectors[length++]= f ;
    // }

    FractionMatrix &operator=(const FractionMatrix &f)
    {
        if (&f == this)
            return *this;

        rows = f.rows;
        cols = f.cols;
        maxlength = f.maxlength;
        delete[] column;
        delete[] row;
        column = new FractionVector[maxlength];
        row = new FractionVector[maxlength];
        for (int i = 0; i < rows; i++)
        {
            row[i] = f.row[i];
        }
        for (int i = 0; i < cols; i++)
        {
            column[i] = f.column[i];
        }
        return *this;
    }
    FractionVector &getCol(int n)
    {
        if (n >= cols or n < 0)
            throw "Out of Bounds\n";
        return column[n];
    }

    void addRow(FractionVector v)
    {
        if (rows >= maxlength)
            throw "Capacity Reached\n";

        if (rows == 0)
        {
            if (v.getlength() > maxlength)
                throw "Cannot add vectors this big";
            cols = v.getlength();
            row[rows++] = v;
            for (int i = 0; i < cols; i++)
                column[i].addFraction(v[i]);
            return;
        }
        if (v.getlength() != cols)
            throw "Dimension Error\n";
        row[rows++] = v;
        // int len = column[0].getlength();
        for (int i = 0; i < cols; i++)
        {
            column[i].addFraction(v[i]);
        }
    }
    void fixcolumn()
    {
        if (rows == 0 or cols == 0 )
            return;
        for(int i = 0 ; i < cols ; i++){
            for ( int j= 0 ; j < rows ;j++){
                column[i][j] = row[j][i];

            }
        }

        //column[col][rows] = row[rows][col];
    }
    FractionMatrix operator+(FractionMatrix m)
    {
        if (rows != m.rows or cols != m.cols)
            throw "Dimension Mismatch";
        FractionMatrix M(30);
        for (int i = 0; i < m.rows; i++)
        {
            FractionVector v = m.row[i] + row[i];
            M.addRow(v);
        }
        return M;
    }
    FractionMatrix operator%(FractionMatrix m)
    {
        if (rows != m.rows or cols != m.cols)
            throw "Dimension Mismatch";
        FractionMatrix M(30);
        for (int i = 0; i < m.rows; i++)
        {
            FractionVector v = m.row[i] * row[i];
            M.addRow(v);
        }
        return M;
    }
    FractionMatrix operator-(FractionMatrix m)
    {
        if (rows != m.rows or cols != m.cols)
            throw "Dimension Mismatch";
        FractionMatrix M(30);
        for (int i = 0; i < m.rows; i++)
        {
            FractionVector v = row[i] - m.row[i];
            M.addRow(v);
        }
        return M;
    }
    FractionMatrix operator*(Fraction m)
    {
        // if( rows != m.rows or cols != m.cols) throw "Dimension Mismatch" ;
        FractionMatrix M(30);
        for (int i = 0; i < rows; i++)
        {
            FractionVector v = row[i] * m;
            M.addRow(v);
        }
        return M;
    }
    FractionMatrix operator/(Fraction m)
    {
        if (m.getNumerator() == 0)
            throw "Divide by zero Error\n";
        FractionMatrix M(30);
        for (int i = 0; i < rows; i++)
        {
            FractionVector v = row[i] / m;
            M.addRow(v);
        }
        return M;
    }
    FractionMatrix operator*(const FractionMatrix &M)
    {
        if (cols != M.rows or cols == 0)
            throw "Dimension Mismatch\n";
        FractionMatrix m(30);
        for (int i = 0; i < rows; i++)
        {
            FractionVector v(30);
            for (int j = 0; j < M.cols; j++)
            {
                Fraction f(0);
                for (int k = 0; k < cols; k++)
                {
                    f += row[i][k] * M.row[k][j];
                }
                v.addFraction(f);
            }
            m.addRow(v);
        }
        return m;
    }
    FractionMatrix transpose()
    {
        if (cols == 0 || rows == 0)
            throw "Empty matrix\n";
        FractionMatrix m(maxlength);
        for (int i = 0; i < cols; i++)
        {
            FractionVector v(rows);
            for (int j = 0; j < rows; j++)
                v.addFraction(row[j][i]);
            m.addRow(v);
        }
        return m;
    }

    friend ostream &operator<<(ostream &out, const FractionMatrix &m);
    friend FractionMatrix operator*(Fraction &f, FractionMatrix &M);

    ~FractionMatrix()
    {
        delete[] row;
        delete[] column;
    }
};
ostream &operator<<(ostream &out, const FractionMatrix &m)
{
    for (int i = 0; i < m.rows; i++)
        out << m.row[i];
    return out;
}

FractionMatrix operator*(Fraction &f, FractionMatrix &M)
{
    FractionMatrix m(30);
    for (int i = 0; i < M.rows; i++)
    {
        FractionVector v = f * M.row[i];
        m.addRow(v);
    }
    return m;
}

int main()
{

    Fraction a(5, 2), b(7, 2), c(9, 2), d(28, 5);
    Fraction f[4] = {a, b, c, d};
    cout << "Fraction" << endl;
    cout << "-------------------------------" << endl;
    cout << "a: ";
    // a.print();
    cout << a << endl;
    ;
    cout << "b: ";
    // b.print();
    cout << b << endl
         << endl;
    cout << "a+b : ";
    cout << (a + b) << endl;

    cout << "a + 2.0 : ";
    cout << (a + 2.0) << endl;
    cout << "2.0 + a : ";
    cout << (2.0 + a) << endl;
    cout << "a - b : ";
    cout << (a - b) << endl;
    cout << "2.0 -a : ";
    cout << (2.0 - a) << endl;

    cout << "a- 2.0 : ";
    cout << (a - 2.0) << endl;
    cout << "a * b : ";
    cout << (a * b) << endl;
    cout << "a* 2.0 : ";
    cout << (a * 2.0) << endl;
    cout << "2.0* a : ";
    cout << (2.0 * a) << endl;
    cout << "a / b  : ";
    cout << (a / b) << endl;
    cout << "a / 2.0 : ";
    cout << (a / 2.0) << endl;
    cout << "2.0 / a : ";
    cout << (2.0 / a) << endl;
    cout << "a/ 0 : ";
    try
    {
        cout << (a / 0) << endl;
    }
    catch (const char *s)
    {
        cout << s << endl;
    }
    cout << "a += 2 : ";
    a += 2;
    cout << a << endl;

    cout << "a -= 2 : ";
    a -= 2;
    cout << a << endl;

    cout << "a *= 2 : ";
    a *= 2;
    cout << a << endl;

    cout << "a /= 2 : ";
    a /= 2;
    cout << a << endl;

    cout << "a += b : ";
    a += b;

    cout << a << endl;

    cout << "a *= b : ";
    a *= b;
    cout << a << endl;

    cout << "a -= b : ";
    a -= b;
    cout << a << endl;

    cout << "a /=b : ";
    a /= b;
    cout << a << endl
         << endl;
    cout << "Fraction Vector " << endl;
    cout << "-----------------------" << endl;

    FractionVector vector1(4, f);
    FractionVector vector2(10);
    vector2.addFraction(a + 2.0);
    vector2.addFraction(b + 2.0);
    vector2.addFraction(c + a);
    vector2.addFraction(a - b);

    cout << endl
         << "v2 : " << vector2 << endl;
    cout << "v1 : " << vector1 << endl;
    ;
    cout << "v1 * v2 : " << vector2 * vector1 << endl;

    vector1.addFraction(a);

    try
    {
        cout << "v1 * v2 when a new element is added to v1 :" << vector2 * vector1 << endl;
    }
    catch (const char *s)
    {
        cout << s << endl;
    }
    try
    {
        cout << "v1 + v2 when a new element is added to v1 :" << vector2 + vector1 << endl;
    }
    catch (const char *s)
    {
        cout << s << endl;
    }
    try
    {
        cout << "v1 - v2 when a new element is added to v1 :" << vector2 - vector1 << endl;
    }
    catch (const char *s)
    {
        cout << s << endl;
    }
    vector2.addFraction(b);
    cout << "Another element added to v2 : " << endl;

    FractionVector vector3 = vector1 + vector2;
    cout << "v1 + v2 : ";
    cout << vector3 << endl;

    Fraction a1(6, 2), b1(8, 2), c1(10, 2), d1(28, 2);
    Fraction r[4] = {a1, b1, c1, d1};
    FractionVector vector4(4, r);

    cout << "v4 : " << vector4 << endl;
    cout << "v4 Magnitude : " << vector4.value() << endl;

    cout << "2 * vector 4 : " << 2 * vector4 << endl;
    Fraction temp(0);
    try
    {
        cout << "v3 / 0 : ";
        vector3 / 0;
    }
    catch (const char *s)
    {
        cout << s << endl;
    }

    cout << "v1[1] : " << vector1[1] << endl;

    // Matrix testing

    cout << endl
         << "Matrix" << endl;
    cout << "-------------------------------" << endl;
    Fraction f1(1, 2), f2(2, 3), f3(3, 4), f4(4, 5), f5(5, 6), f6(6, 7), f7(7, 8), f8(8, 9), f9(9, 10);

    Fraction row1a[3] = {f1, f2, f3};
    Fraction row2a[3] = {f4, f5, f6};
    Fraction row3a[3] = {f7, f8, f9};
    FractionVector mat1_rows[3] = {FractionVector(3, row1a), FractionVector(3, row2a), FractionVector(3, row3a)};
    FractionMatrix mat1(3, mat1_rows);

    Fraction row1b[2] = {f1, f2};
    Fraction row2b[2] = {f3, f4};
    Fraction row3b[2] = {f5, f6};
    FractionVector mat2_rows[3] = {FractionVector(2, row1b), FractionVector(2, row2b), FractionVector(2, row3b)};
    FractionMatrix mat2(3, mat2_rows);

    Fraction row1c[3] = {f2, f3, f4};
    Fraction row2c[3] = {f5, f6, f7};
    Fraction row3c[3] = {f8, f9, f1};
    FractionVector mat3_rows[3] = {FractionVector(3, row1c), FractionVector(3, row2c), FractionVector(3, row3c)};
    FractionMatrix mat3(3, mat3_rows);

    Fraction row1d[1] = {f1};
    Fraction row2d[1] = {f2};
    FractionVector mat4_rows[2] = {FractionVector(1, row1d), FractionVector(1, row2d)};
    FractionMatrix mat4(2, mat4_rows);

    cout << "Matrix1 :\n"
         << mat1 << endl;
    cout << "Matrix2 :\n"
         << mat2 << endl;
    cout << "Matrix3 :\n"
         << mat3 << endl;
    cout << "Matrix4 :\n"
         << mat4 << endl;

    cout << "\nMatrix 1 + Matrix 3:\n\n";
    cout << mat1 + mat3;

    cout << "\nMatrix 1 * 2/1 : \n\n";
    cout << mat1 * Fraction(2, 1);

    cout << "\nMatrix 1 / 1/2 :\n\n";
    cout << mat1 / Fraction(1, 2);

    cout << "\nMatrix 1 * Matrix 3:\n\n";
    cout << mat1 * mat3;

    cout << "\n Matrix 1 + Matrix 2 :\n\n";
    try
    {
        cout << mat1 + mat2;
    }
    catch (const char *s)
    {
        cout << s << endl;
    }

    cout << "\n Matrix 4 * Matrix 2: \n\n";
    try
    {
        cout << mat4 * mat2;
    }
    catch (const char *s)
    {
        cout << s << endl;
    }
    cout << "Matrix 1 Column 1 :" << mat1.getCol(0) << endl;
    cout << "Matrix 1 row 1  :  " << mat1[0] << endl
         << endl;

    cout << "Matrix1 % Matrix 3 :\n"
         << mat1 % mat3 << endl;

    cout << "Matrix1 - Matrix3 :\n"
         << mat1 - mat3 << endl;

    cout << "Matrix1 [2][1]: " << mat1[2][1] << endl;
    cout << endl
         << "Tranpose of matrix 1 :" << endl;
    cout << mat1.transpose() << endl;

    cout <<endl <<"Assignment check \n";
    mat1[0] = FractionVector(3, row2a) ;    
    mat1.fixcolumn();
    cout <<mat1 ;
    cout << "\nColumn 1 :"<<mat1.getCol(0);
}
