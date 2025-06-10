#include<iostream>
#include<cmath>
using namespace std;

class Fraction{
    int numerator;
    int denominator;
public:
    int gcd(int a,int b) const{
        return (b==0)?a:gcd(b,a%b);
    }

    int lcm(int a,int b) const{
        return (a/gcd(a,b))*b;
    }

    void normalize(){
        int temp=gcd(abs(numerator),abs(denominator));
        numerator/=temp;
        denominator/=temp;
        if(denominator<0){
            numerator=-numerator;
            denominator=-denominator;
        }
    }

    Fraction(){
        numerator=0;
        denominator=1;
    }

    ~Fraction(){

    }

    Fraction(int numerator,int denominator){
        if(denominator==0){
            cout<<"Can't be divided by zero. The denominator is taken as 1 by default"<<endl;
            this->denominator=1;
        }
        else{
            this->denominator=denominator;
        }
        this->numerator=numerator;
        this->normalize();
    }

    Fraction(float sample){
        numerator=round(sample*100);
        denominator=100;
        this->normalize();
    }

    Fraction(const Fraction& other){
        if(this!=&other){
            this->numerator=other.numerator;
            this->denominator=other.denominator;
        }
    }

    double getValue(){
        return (double)numerator/denominator;
    }

    int getNumerator(){
        return numerator;
    }

    int getDenominator(){
        return denominator;
    }

    Fraction& operator=(const Fraction& other){
        if(this!=&other){
            this->numerator=other.numerator;
            this->denominator=other.denominator;
        }
        return *this;
    }

    Fraction& operator=(float value){
        this->numerator=round(value*100);
        this->denominator=100;
        normalize();
        return *this;
    }

    Fraction operator+(const Fraction& other) const{
        int hor=lcm(this->denominator,other.denominator);
        int lob=((hor/this->denominator)*(this->numerator))+((hor/other.denominator)*(other.numerator));
        Fraction ans(lob,hor);
        return ans;
    }

    Fraction operator-(const Fraction& other) const{
        int hor=lcm(this->denominator,other.denominator);
        int lob=((hor/this->denominator)*(this->numerator))-((hor/other.denominator)*(other.numerator));
        Fraction ans(lob,hor);
        return ans;
    }

    Fraction operator*(const Fraction& other) const{
        int hor=this->denominator*other.denominator;
        int lob=((this->numerator)*(other.numerator));
        Fraction ans(lob,hor);
        return ans;
    }

    Fraction operator/(const Fraction& other) const{
        int hor=this->denominator*other.numerator;
        int lob=((this->numerator)*(other.denominator));
        Fraction ans(lob,hor);
        return ans;
    }

    Fraction operator+(float val) const{
        Fraction other(val);
        return (*this+other);
    }

    Fraction operator-(float val) const{
        Fraction other(val);
        return (*this-other);
    }

    Fraction operator*(float val) const{
        Fraction other(val);
        return ((*this)*other);
    }

    Fraction operator/(float val) const{
        Fraction other(val);
        return ((*this)/other);
    }

    Fraction& operator+=(const Fraction& other){
        *this=*this+other;
        return *this;
    }

    Fraction& operator-=(const Fraction& other){
        *this=*this-other;
        return *this;
    }

    Fraction& operator*=(const Fraction& other){
        *this=*this*other;
        return *this;
    }

    Fraction& operator/=(const Fraction& other){
        *this=*this/other;
        return *this;
    }

    Fraction& operator+=(float val){
        Fraction other(val);
        *this+=other;
        return *this;
    }

    Fraction& operator-=(float val){
        Fraction other(val);
        *this-=other;
        return *this;
    }

    Fraction& operator*=(float val){
        Fraction other(val);
        (*this)*=other;
        return *this;
    }

    Fraction& operator/=(float val){
        Fraction other(val);
        *this/=other;
        return *this;
    }

    friend Fraction operator+(float val,const Fraction& a){
        return (a+val);
    }

    friend Fraction operator*(float val,const Fraction& a){
        return (a*val);
    }

    friend Fraction operator-(float val,const Fraction& a){
        Fraction other(val);
        return (other-a);
    }

    friend Fraction operator/(float val,const Fraction& a){
        Fraction other(val);
        return (other/a);
    }

    friend ostream& operator<<(ostream& out,const Fraction& a){
        out<<a.numerator<<"/"<<a.denominator;
        return out;
    }
    
};

class FractionVector{
    Fraction* fractions;
    int totalfractions;
public:
    FractionVector(){
        totalfractions=0;
        fractions=NULL;
    }

    FractionVector(int totalfractions){
        this->totalfractions=totalfractions;
        fractions=new Fraction[totalfractions];
    }

    ~FractionVector(){
        delete[] fractions;
        fractions=NULL;
    }

    FractionVector(const FractionVector& other){
        if(fractions!=NULL){
            delete[] fractions;
        }
        fractions=new Fraction[other.totalfractions];
        this->totalfractions=other.totalfractions;
        for(int i=0;i<totalfractions;i++){
            fractions[i]=other[i];
        }
    }

    FractionVector& operator=(const FractionVector& other){
        if(this!=&other){
            if(fractions!=NULL){  
                delete[] fractions;
            }
            fractions=new Fraction[other.totalfractions];
            this->totalfractions=other.totalfractions;
            for(int i=0;i<totalfractions;i++){
                fractions[i]=other[i];
            }
        }
        return *this;
    }

    Fraction& operator[](int index) const{
        if(index<0 || index>=totalfractions){
            cout<<"Out of bounds. Use Java, be relaxed. No operator Overloading.\n";
            Fraction dummy(0,1);
            return dummy;
        }
        return fractions[index];
    }

    FractionVector operator+(const FractionVector& other) const{
        if(this->totalfractions!=other.totalfractions){
            cout<<"The sizes of the vectors are not same. Use java be relaxed. Can't add now.\n";
            return FractionVector();
        }
        FractionVector ans(totalfractions);
        for(int i=0;i<totalfractions;i++){
            ans[i]=(*this)[i]+other[i];
        }
        return ans;
    }

    FractionVector operator-(const FractionVector& other) const{
        if(this->totalfractions!=other.totalfractions){
            cout<<"The sizes of the vectors are not same. Use java be relaxed. Can't substract now.\n";
            return FractionVector();
        }
        FractionVector ans(totalfractions);
        for(int i=0;i<totalfractions;i++){
            ans[i]=(*this)[i]-other[i];
        }
        return ans;
    }

    FractionVector operator*(const Fraction& val) const{
        FractionVector ans(totalfractions);
        for(int i=0;i<totalfractions;i++){
            ans[i]=(*this)[i]*val;
        }
        return ans;
    }

    FractionVector operator/(const Fraction& val) const{
        FractionVector ans(totalfractions);
        for(int i=0;i<totalfractions;i++){
            ans[i]=(*this)[i]/val;
        }
        return ans;
    }

    Fraction operator*(const FractionVector& other) const{
        if(this->totalfractions!=other.totalfractions){
            cout<<"The sizes of the vectors are not same. Use java be relaxed. Can't dot product now.\n";
            return Fraction(0,1);
        }
        Fraction ans(0,1);
        for(int i=0;i<totalfractions;i++){
            ans+=((*this)[i]*other[i]);
        }
        return ans;
    }

    friend FractionVector operator*(const Fraction& val,const FractionVector& other){
        return (other*val);
    }

    Fraction value(){
        Fraction ans=(*this)*(*this);
        return Fraction((float)sqrt(ans.getValue()));
    }

    friend ostream& operator<<(ostream& out,const FractionVector& a){
        cout<<"[ ";
        for(int i=0;i<a.totalfractions-1;i++){
            out<<a[i]<<"   ";
        }
        out<<a[a.totalfractions-1]<<" ]";
        return out;
    }
};

class FractionMatrix{
    FractionVector* rows;
    FractionVector* columns;
    int rowsize;
    int columnsize;
public:
    FractionMatrix(int n=0,int m=0){
        rowsize=n;
        columnsize=m;
        rows=new FractionVector[rowsize];
        for(int i=0;i<rowsize;i++){
            rows[i]=FractionVector(columnsize);
        }
        columns=new FractionVector[columnsize];
        for(int i=0;i<columnsize;i++){
            columns[i]=FractionVector(rowsize);
        }
    }

    FractionMatrix(const FractionMatrix& other){
        if(rows)
            delete[] rows;
        if(columns)
            delete[] columns;
        rowsize=other.rowsize;
        columnsize=other.columnsize;
        rows=new FractionVector[rowsize];
        for(int i=0;i<rowsize;i++){
            rows[i]=other[i];
        }
        columns=new FractionVector[columnsize];
        this->updatecolumns();
    }

    FractionMatrix& operator=(const FractionMatrix& other){
        if(this!=&other){
            if(rows)
                delete[] rows;
            if(columns)
                delete[] columns;
            rowsize=other.rowsize;
            columnsize=other.columnsize;
            rows=new FractionVector[rowsize];
            for(int i=0;i<rowsize;i++){
                rows[i]=other[i];
            }
            columns=new FractionVector[columnsize];
            this->updatecolumns();
        }
        return *this;
    }

    ~FractionMatrix(){
        delete[] rows;
        delete[] columns;
        rows=NULL;
        columns=NULL;
    }

    FractionVector& operator[](int index) const{
        if(index<0 || index>=rowsize){
            cout<<"Out of bounds. Use Java, be relaxed. No operator Overloading.\n";
            FractionVector dummy();
            return dummy;
        }
        return rows[index];
    }

    void updatecolumns(){
        for(int i=0;i<columnsize;i++){
            for(int j=0;j<rowsize;j++){
                columns[i][j]=rows[j][i];
            }
        }
    }

    FractionVector& getColumn(int index){
        if(index<0 || index>=columnsize){
            cout<<"Out of Bounds.\n";
            exit(1);
        }
        updatecolumns();
        return columns[index];
    }

    FractionMatrix operator+(const FractionMatrix& other) const{
        if(this->rowsize!=other.rowsize || this->columnsize!=other.columnsize){
            cout<<"Size should be same while adding two matrices. Use java, be relaxed\n";
            exit(1);
        }
        FractionMatrix ans(rowsize,columnsize);
        for(int i=0;i<rowsize;i++){
            ans[i]=(*this)[i]+other[i];
        }
        ans.updatecolumns();
        return ans;
    }

    FractionMatrix operator-(const FractionMatrix& other) const{
        if(this->rowsize!=other.rowsize || this->columnsize!=other.columnsize){
            cout<<"Size should be same while substracting two matrices. Use java, be relaxed\n";
            exit(1);
        }
        FractionMatrix ans(rowsize,columnsize);
        for(int i=0;i<rowsize;i++){
            ans[i]=(*this)[i]-other[i];
        }
        ans.updatecolumns();
        return ans;
    }

    FractionMatrix operator*(const Fraction& val) const{
        FractionMatrix ans(rowsize,columnsize);
        for(int i=0;i<rowsize;i++){
            ans[i]=(*this)[i]*val;
        }
        ans.updatecolumns();
        return ans;
    }

    FractionMatrix operator/(const Fraction& val) const{
        FractionMatrix ans(rowsize,columnsize);
        for(int i=0;i<rowsize;i++){
            ans[i]=(*this)[i]/val;
        }
        ans.updatecolumns();
        return ans;
    }

    FractionMatrix operator*(FractionMatrix& other) const{
        if(this->columnsize!=other.rowsize){
            cout<<"Incorrect Dimension use!! For A[m*n] and B[p*q] to multiplicable n==p should be maintained\n";
            exit(1);
        }
        FractionMatrix ans(this->rowsize,other.columnsize);
        for(int i=0;i<this->rowsize;i++){
            for(int j=0;j<other.columnsize;j++){
                ans[i][j]=this->rows[i]*(other.getColumn(j));
            }
        }
        ans.updatecolumns();
        return ans;
    }

    FractionMatrix operator%(const FractionMatrix& other) const{
        if(this->columnsize!=other.columnsize || this->rowsize!=other.rowsize){
            cout<<"Incorrect Dimension use!! Sizes should be same\n";
            exit(1);
        }
        FractionMatrix ans(this->rowsize,other.columnsize);
        for(int i=0;i<this->rowsize;i++){
            for(int j=0;j<other.columnsize;j++){
                ans[i][j]=(*this)[i][j]*other[i][j];
            }
        }
        ans.updatecolumns();
        return ans;
    }

    FractionMatrix transpose(){
        FractionMatrix ans(columnsize,rowsize);
        for(int i=0;i<columnsize;i++){
            ans[i]=getColumn(i);
        }
        ans.updatecolumns();
        return ans;
    }  

    friend FractionMatrix operator*(const Fraction& val,const FractionMatrix& a){
        return (a*val);
    }

    friend ostream& operator<<(ostream& out,const FractionMatrix& a){
        out<<"Matrix:\n";
        for(int i=0;i<a.rowsize-1;i++){
            out<<"Row["<<i<<"] : "<<a[i]<<endl;
        }
        out<<"Row["<<a.rowsize-1<<"] : "<<a[a.rowsize-1];
        return out;
    }

};

int main() {
    cout << "=== FRACTION TESTS ===\n" << endl;
    Fraction f1(3, 4), f2(5, 6);
    cout<<"f1: "<<f1<<", f2: "<<f2<<endl;
    Fraction f3=6.7;
    cout<<"[Input as float] f3: "<<f3<<endl;
    cout<<"f1 + f2 = "<<(f1+f2)<<endl;
    cout<<"f1 - f2 = "<<(f1-f2)<<endl;
    cout<<"f1 * f2 = "<<(f1 * f2)<<endl;
    cout<<"f1 / f2 = "<<(f1 / f2)<<endl;
    cout<<"f1 + 2.5 = "<<(f1 + 2.5f)<<endl;
    cout<<"2.5 + f1 = "<<(2.5f + f1)<<endl;
    f1+=3.5;
    cout<<"f1+= 3.5; f1 = "<<f1<<endl;
    f1*=-2.5;
    cout<<"f1*= -2.5; f1 = "<<f1<<endl;
    f1/=f2;
    cout<<"f1/= f2; f1 = "<<f1<<endl;
    f1-=f3;
    cout<<"f1-= f3; f1 = "<<f1<<endl;

    cout << "\n=== FRACTIONVECTOR TESTS ===" << endl;
    FractionVector v1(3),v2(3);
    v1[0]=Fraction(1, 2); v1[1]=Fraction(2, 3); v1[2]=Fraction(3, 4);
    v2[0]=Fraction(3, 5); v2[1]=Fraction(4, 5); v2[2]=Fraction(5, 6);
    cout<<"v1:\n"<<v1<<endl;
    cout<<"v2:\n"<<v2<<endl;
    cout<<"v1 + v2:\n"<<(v1+v2)<<endl;
    cout<<"v1 - v2:\n"<<(v1-v2)<<endl;
    cout<<"v1 * (2/3):\n"<<(v1*Fraction(2, 3))<<endl;
    cout<<"(2/3) * v1:\n"<<(Fraction(2, 3)*v1)<<endl;
    cout<<"v1 / (2/3):\n"<<(v1/Fraction(2, 3))<<endl;
    cout<<"Dot product v1 . v2 = "<<(v1*v2)<<endl;
    cout<<"Magnitude of v1 = "<<v1.value()<<endl;
    cout<<"Array Subscript using:\n";
    cout<<"Reading: v1[1] = "<<v1[1]<<endl;
    v1[1]=Fraction(5,3);
    cout<<"Writing: v1[1] = 5/3;  v1[1] = "<<v1[1]<<endl;

    cout<<"\n=== FRACTIONMATRIX TESTS ==="<<endl;
    FractionMatrix m1(2, 3), m2(2, 3);
    m1[0][0]=Fraction(1,2);m1[0][1]=Fraction(1,3);m1[0][2]=Fraction(1,4);
    m1[1][0]=Fraction(2,3);m1[1][1]=Fraction(2,4);m1[1][2]=Fraction(2,5);
    m2[0][0]=Fraction(3,4);m2[0][1]=Fraction(3,5);m2[0][2]=Fraction(3,6);
    m2[1][0]=Fraction(4,5);m2[1][1]=Fraction(4,6);m2[1][2]=Fraction(4,7);
    cout<<"m1:\n"<<m1<<endl;
    cout<<"m2:\n"<<m2<<endl;
    cout<<"m1 + m2:\n"<<(m1 + m2)<<endl;
    cout<<"m1 - m2:\n"<<(m1 - m2)<<endl;
    cout<<"m1 * (2/3):\n"<<(m1 * Fraction(2, 3))<<endl;
    cout<<"(3/4) * m1:\n"<<(Fraction(3, 4) * m1)<<endl;
    cout<<"Hadamard product m1 % m2:\n"<<(m1 % m2)<<endl;
    cout<<"Transpose of m1:\n"<<m1.transpose()<<endl;
    cout<<"Array subscript:"<<endl;
    cout<<"m1[1] : "<<m1[1]<<endl;
    cout<<"m1[1][1] : "<<m1[1][1]<<endl;
    cout<<"Column check:"<<endl;
    for(int i=0;i<3;i++){
        cout<<"Column["<<i<<"] : "<<m1.getColumn(i)<<endl;
    }

    cout << "\n=== MATRIX MULTIPLICATION TEST ===" << endl;
    FractionMatrix m3(2, 2),m4(2, 2);
    m3[0][0]=Fraction(1, 1);m3[0][1]=Fraction(2, 1);
    m3[1][0]=Fraction(3, 1);m3[1][1]=Fraction(4, 1);
    m4[0][0]=Fraction(5, 1);m4[0][1]=Fraction(6, 1);
    m4[1][0]=Fraction(7, 1);m4[1][1]=Fraction(8, 1);
    FractionMatrix m5 = m3 * m4;
    cout<<"m3:\n"<<m3<<endl;
    cout<<"m4:\n"<<m4<<endl;
    cout<<"m3 * m4:\n"<<m5<<endl;
    cout<<"Column check:"<<endl;
    for(int i=0;i<2;i++){
        cout<<"Column["<<i<<"] : "<<m5.getColumn(i)<<endl;
    }
    return 0;
}