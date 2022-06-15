class MyComplex {

private:

    long double r, i;

public:

    MyComplex() { r = 0; i = 0; }

    MyComplex(long double real) { r = real; i = 0; }

    MyComplex(long double real, long double ima) :r(real), i(ima) {}

    long double ToLDouble() {

        if (this->i == 0) {

            return this->r;

        }

        else {

            printf("虚部不为0");

        }

    }

    const long double GetReal() {

        return r;

    }

    const long double GetImag() {

        return i;

    }

    string ToString() {

        return i>=0?to_string(r) + "+i*"+ to_string(i): to_string(r) + to_string(i) + "*i";

    }

    void PrintString() {

        printf("%s",((i >= 0 ? to_string(r) + "+i*" + to_string(i) : to_string(r) + to_string(i) + "*i")+"\n").c_str());

    }

    MyComplex operator + (MyComplex a) { return MyComplex(this->r + a.r, this->i + a.i); }

    MyComplex operator += (MyComplex a) { return (*this = MyComplex(this->r + a.r, this->i + a.i)); }

    MyComplex operator - (MyComplex a) { return MyComplex(this->r - a.r, this->i - a.i); }

    MyComplex operator -= (MyComplex a) { return (*this = MyComplex(this->r - a.r, this->i - a.i)); }

    MyComplex operator * (MyComplex a) { return MyComplex(this->r * a.r - this->i * a.i, this->i * a.r + this->r * a.i); }

    MyComplex operator *= (MyComplex a) { return (*this = MyComplex(this->r * a.r - this->i * a.i, this->i * a.r + this->r * a.i)); }

    MyComplex operator % (long double a) { return MyComplex(this->r / a, this->i / a); }

    MyComplex operator %= (long double a) { return (*this = MyComplex(this->r / a, this->i / a)); }

    MyComplex operator ! (){return MyComplex(this->r, this->i*-1.0);}

    MyComplex operator / (MyComplex a) { return (*this * (!a)) % ((a * !a).ToLDouble()); }

    MyComplex operator /= (MyComplex a) { return (*this = (*this * (!a)) % ((a * !a).ToLDouble())); }

};

class StrComplex {

public:

    string r, i;

    StrComplex(string real, string ima) :r(real), i(ima) {}

};



FILE* file = nullptr;



StrComplex FTran(vector<MyComplex>& input) {

    long long n = input.size();

    long long m = 100;

    vector<MyComplex> CmpSet;

    for (int i = -1 * m; i <= m; i++) {

        MyComplex Temp(0,0);

        for (int k = 0; k < n; k++) {

            Temp += input[k] * MyComplex(cos((2.0 * Pi * i * (k + 1.0)) / n), sin((2.0 * Pi * i * (k + 1.0)) / n));

        }

        CmpSet.push_back(Temp % n);

    }

    StrComplex StrComplex("","");

    for (int i = -1 * m; i <= m; i++) {

        StrComplex.r += "(" + to_string(CmpSet[i + m].GetReal()) + "*Cos[" + to_string(i) + "*t])-" + "(" + to_string(CmpSet[i + m].GetImag()) + "*Sin[" + to_string(i) + "*t])+";

        StrComplex.i += "(" + to_string(CmpSet[i + m].GetReal()) + "*Sin[" + to_string(i) + "*t])+" + "(" + to_string(CmpSet[i + m].GetImag()) + "*Cos[" + to_string(i) + "*t])+";

    }

    return StrComplex;

}
