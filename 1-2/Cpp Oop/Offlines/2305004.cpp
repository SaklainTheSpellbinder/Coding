#include<iostream>
using namespace std;

class Fraction{
    int numerator;
    int denominator;
    public:
        Fraction(){
            numerator=0;
            denominator=1;
        }

        Fraction(int numerator){
            this->numerator=numerator;
            this->denominator=1;
        }

        Fraction(int numerator,int denominator){
            this->numerator=numerator;
            if(denominator!=0)
                this->denominator=denominator;
            else{
                cout<<"Denominator cannot be 0"<<endl;
                this->denominator=1;
            }
        }

        int gcd(int a,int b){
            return (b==0)?a:gcd(b, a % b);
        }

        int lcm(int a,int b){
            return (a/gcd(a,b))*b;
        }


        Fraction add(Fraction &f){
            Fraction temp;
            temp.denominator=lcm(this->denominator,f.denominator);
            int x=(temp.denominator/this->denominator)*this->numerator+(temp.denominator/f.denominator)*f.numerator;
            temp.numerator=x;
            return temp;
        }

        Fraction add(int n){
            Fraction temp;
            temp.denominator=this->denominator;
            temp.numerator=this->numerator+(n*this->denominator);
            return temp;
        }


        Fraction sub(Fraction &f){
            Fraction temp;
            temp.denominator=lcm(this->denominator,f.denominator);
            int x=(temp.denominator/this->denominator)*this->numerator-(temp.denominator/f.denominator)*f.numerator;
            temp.numerator=x;
            return temp;
        }
        Fraction sub(int n){
            Fraction temp;
            temp.denominator=this->denominator;
            temp.numerator=this->numerator-(n*this->denominator);
            return temp;
        }


        Fraction mul(Fraction &f){
            Fraction temp;
            temp.numerator=(this->numerator)*(f.numerator);
            temp.denominator=(this->denominator)*(f.denominator);
            return temp;
        }

        Fraction mul(int n){
            Fraction temp(this->numerator,this->denominator);
            temp.numerator=(this->numerator)*(n);
            return temp;
        }


        Fraction div(Fraction &f){
            if(f.numerator==0){
                cout<<"Can not divide by 0\n";
                return *this;
            }
            else{
                Fraction temp;
                temp.numerator=(this->numerator)*(f.denominator);
                temp.denominator=(this->denominator)*(f.numerator);
                return temp;
            }
        }
        Fraction div(int n){
            Fraction temp(this->numerator,this->denominator);
            if(n!=0)
                temp.denominator=(this->denominator)*n;
            else
                cout<<"Can not divide by 0"<<endl;
            return temp;
        }

        void print(){
            int x=gcd(this->numerator,this->denominator);
            this->numerator/=x;
            this->denominator/=x;
            cout<<this->numerator<<"/"<<this->denominator<<endl;
        }

        int getnumerator(){
            return numerator;
        }

        int getdenominator(){
            return denominator;
        }

        void setnumerator(int numerator){
            this->numerator=numerator;
        }

        void setdenominator(int denominator){
            this->denominator=denominator;
        }
};

class FractionCollection{
    Fraction* fractions;
    int maxlength;
    int length;
public:
    FractionCollection(){
        fractions=new Fraction[10];
        this->length=0;
        this->maxlength=10;
    }

    FractionCollection(int maxlength){
        fractions=new Fraction[maxlength];
        this->maxlength=maxlength;
        this->length=0;
    }

    void insert(Fraction f){
        if(length>=maxlength){
            cout<<"Array maximum size reached\n";
            return;
        }
        fractions[length]=f;
        length++;
    }

    void insert(int pos,Fraction f){
        if(length<maxlength){
            for(int i=length-1;i>=pos;i--){
                fractions[i+1]=fractions[i];
            }
            fractions[pos]=f;
            length++;
        }
        else{
            cout<<"Array maximum size reached"<<endl;
        }
    }

    void remove(){
        length--;
    }

    void remove(Fraction f){
        int i=0;
        for(i=0;i<length;i++){
            if(fractions[i].getnumerator()==f.getnumerator() && fractions[i].getdenominator()==f.getdenominator()){
                break;
            }
        }

        if(i!=length){
            for(int j=i;j<length-1;j++){
                fractions[j]=fractions[j+1];
            }
    
            length--;
        }
        

    }

    void remove(int pos){
        for(int j=pos;j<length-1;j++){
            fractions[j]=fractions[j+1];
        }
        length--;
    }

    Fraction getmax(){
        double maxfraction=double(fractions[0].getnumerator())/fractions[0].getdenominator();
        int maxindex=0;
        for(int i=1;i<length;i++){
            double x=double(fractions[i].getnumerator())/fractions[i].getdenominator();
            if(x>maxfraction){
                maxfraction=x;
                maxindex=i;
            }
        }
        return fractions[maxindex];
    }

    Fraction getmin(){
        double minfraction=double(fractions[0].getnumerator())/fractions[0].getdenominator();
        int minindex=0;
        for(int i=1;i<length;i++){
            double x=double(fractions[i].getnumerator())/fractions[i].getdenominator();
            if(x<=minfraction){
                minfraction=x;
                minindex=i;
            }
        }
        return fractions[minindex];
    }

    Fraction add(int start,int end){
        Fraction ans=fractions[start];
        for(int i=start+1;i<=end;i++){
            ans=ans.add(fractions[i]);
        }
        return ans;
    }

    Fraction mul(int start,int end){
        Fraction ans=fractions[start];
        for(int i=start+1;i<=end;i++){
            ans=ans.mul(fractions[i]);
        }
        return ans;
    }

    Fraction sub(int pos1,int pos2){
        Fraction temp=fractions[pos1];
        return temp.sub(fractions[pos2]);
    }

    Fraction div(int pos1,int pos2){
        Fraction temp=fractions[pos1];
        return temp.div(fractions[pos2]);
    }
    void print(){
        cout<<"\nFractions"<<endl;
        cout<<"-------------------------------"<<endl;

        for(int i=0;i<length;i++){
            cout<<"Fraction "<<i<<": ";
            fractions[i].print();
        }

        cout<<"Max: ";
        getmax().print();
        cout<<"Min: ";
        getmin().print();

        cout<<"Summation: ";
        add(0,length-1).print();

        cout<<"Multiplication: ";
        mul(0,length-1).print();
    }
    
    ~FractionCollection(){
        delete[] fractions;
    }
};

int main(){
    //create Fraction with numerator, denominator
    Fraction a(5,2),b(7,2),c(9,2),d(28,5);
    cout<<"Fraction"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"A: ";
    a.print();
    cout<<"B: ";
    b.print();
    cout<<endl;
    cout<<"Add(a,b): ";
    a.add(b).print();
    cout<<"Add(a,2): ";
    a.add(2).print();
    cout<<"Sub(a,b) ";
    a.sub(b).print();
    cout<<"Sub(a,2) ";
    a.sub(2).print();
    cout<<"Mul(a,b): ";
    a.mul(b).print();
    cout<<"Mul(a,2): ";
    a.mul(2).print();
    cout<<"Div(a,b): ";
    a.div(b).print();
    cout<<"Div(a,2): ";
    a.div(2).print();
    cout<<"Div(a,0): ";
    a.div(0).print();

    //Collection of Fractions
    Fraction e,f(5),g(10);
    FractionCollection fc(10);
    fc.insert(a);
    fc.insert(b);
    fc.insert(c);
    fc.print();
    cout<<"Sub(Pos0, Pos1): ";
    fc.sub(0,1).print(); //subtracts the fraction at pos1 from fraction at pos0
    cout<<"Div(Pos0, Pos1): ";
    fc.div(0,1).print(); //divides the fraction at pos0 by the fraction at pos1
    fc.remove(1); //removed 'b'
    fc.print();
    fc.remove(a);
    fc.print();
    fc.insert(d);
    fc.insert(0,e); //insert at pos0
    fc.insert(f);
    fc.insert(g);
    fc.print();
    fc.remove(); //removed the last fraction
    fc.print(); //notice the output
    return 0;
}