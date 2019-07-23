#include<iostream>
using namespace std;
class Money{
    public:
        Money(){
            rands=0;
            cents=0;
        }; // default constructor
        Money(int r, int c){
            rands=r;
            cents=c;
        }; // constructor
        ~Money(); // destructor

        int theRands() const;
        int theCents() const;

        Money Plus(Money m);
        Money operator+ (Money &m);
//        bool operator> (Money &m);
        bool operator> (Money m);
        bool GreaterThan(Money m);
        friend ostream& operator<<(ostream& os, const Money& m);
    private:
        int rands;
        int cents;
};

int Money::theRands() const { return rands;}
int Money::theCents() const { return cents;}

Money Money::Plus(Money m) {
    std::div_t dv{};
    dv = std::div(cents+m.theCents(),100);
    return Money(rands+m.theRands()+dv.quot,dv.rem);
}

Money Money::operator+(Money &m) {
    int *rand;
    rand=&m.rands;
    int *cent;
    cent=&m.cents;
    std::div_t dv{};
    dv = std::div(cents+*cent,100);
    return Money(rands+*rand+dv.quot,dv.rem);
}

ostream& operator<<(ostream& os, const Money& m){
    if (m.theCents()>9)
    os<<m.theRands()<<"."<<m.theCents();
    else
        os<<m.theRands()<<".0"<<m.theCents();
}

bool Money::GreaterThan(Money m) {
    if(rands>m.theRands()){
        return true;
    } else if (m.theRands()==rands && m.theCents()>cents){
        return true;
    }
    return false;
}
/*
bool Money::operator>(Money &m){
    int *rand;
    rand=&m.rands;
    int *cent;
    cent=&m.cents;
    cout<<rands<<"b"<<*rand<<endl;
    if(rands>*rand){
        return true;
    } else if (*rand==rands && *cent>cents){
        return true;
    }
    return false;
}*/

bool Money::operator>(Money m) {
    if(rands>m.theRands()){
        return true;
    } else if (m.rands==rands && m.cents>cents){
        return true;
    }
}

Money::~Money() {
}

void questionFour()
{
    Money m1=Money();
    Money m2=Money(15,90);
    Money m3=Money(5,15);
    m1 = m2.Plus(m3);
    cout<<m1<<" + "<<m2<<" gives "<<m1.Plus(m2)<<endl;
    m1 = m2 + m3;
    cout << m2 << " + " << m3 << " gives " << m1 << endl;
    if (m1>m2)
    cout << m1 << " is greater than " << m2 << endl;
    else {
        cout << m2 << " is less than " << m1 << endl;
    }
    m1.~Money();
    m2.~Money();
    m3.~Money();
}
