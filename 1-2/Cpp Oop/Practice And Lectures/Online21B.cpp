#include<iostream>
#include<string>
using namespace std;

class Product{
    string name;
    double price;
public:
    Product(){
        this->name="Nothing";
        this->price=0.00;
    }
    Product(string name,double price){
        this->name=name;
        this->price=price;
    }

    void setName(string name){
        this->name=name;
    }

    void setPrice(double price){
        this->price=price;
    }

    string getName(){
        return name;
    }

    double getPrice(){
        return price;
    }

    void displayDetails(){
        cout<<"Product name: "<<name<<endl;
        cout<<"Price: "<<price<<endl;
    }
};

class OnlineStore{
    int i;
    int maxsize;
    Product* arr;
public:
    OnlineStore(){
        i=0;
        maxsize=100;
        arr=new Product[maxsize];
    }

    OnlineStore(int maxsize){
        i=0;
        this->maxsize=maxsize;
        arr=new Product[maxsize];
    }

    ~OnlineStore(){
        delete[] arr;
    }

    void addProduct(Product& p){
        arr[i++]=p;
    }

    void displayProducts(){
        cout<<"Available Products in the Store:\n";
        for(int j=0;j<i;j++){
            cout<<"\tProduct: "<<arr[j].getName()<<" - Price: $"<<arr[j].getPrice()<<endl;
        }
        cout<<endl;
    }
};

class ShoppingCart{
    int i;
    int maxsize;
    Product* arr;
public:
    ShoppingCart(){
        i=0;
        maxsize=100;
        arr=new Product[maxsize];
    }

    ShoppingCart(int maxsize){
        i=0;
        this->maxsize=maxsize;
        arr=new Product[maxsize];
    }

    ~ShoppingCart(){
        delete[] arr;
    }

    void addProduct(Product& p){
        arr[i++]=p;
    }

    void removeProduct(string name){
        int j=0;
        while(j<i){
            if(arr[j].getName()==name){
                break;
            }
            j++;
        }
        if(j>=i){
            cout<<"Book is not here...so can't be removed\n";
            return;
        }
        else{
            for(int k=j;k<i-1;k++){
                arr[k]=arr[k+1];
            }

            i--;
        }
    }

    double totalCost(){
        double cost=0.0;
        for(int j=0;j<i;j++){
            cost+=arr[j].getPrice();
        }
        return cost;
    }

    void displayCart(){
        cout<<"Shopping Cart:\n";
        for(int j=0;j<i;j++){
            cout<<"\tProduct: "<<arr[j].getName()<<" - Price: $"<<arr[j].getPrice()<<endl;
        }
        cout<<"\tTotal Cost: $"<<totalCost()<<endl;
        cout<<endl;
    }
};

int main(){
    OnlineStore store;
    // Add products to the online store
    Product product1("Laptop", 999.99);
    Product product2("Smartphone", 699.99);
    Product product3("Headphones", 99.99);
    store.addProduct(product1);
    store.addProduct(product2);
    store.addProduct(product3);
    // Display available products
    store.displayProducts();
    // Create a new shopping cart
    ShoppingCart cart;
    // Add products to the shopping cart
    cart.addProduct(product1);
    cart.addProduct(product2);
    // Display the shopping cart
    cart.displayCart();
    // Add another product to the cart
    cart.addProduct(product3);
    // Display the updated shopping cart
    cart.displayCart();
    // Remove a product from the cart
    cart.removeProduct("Laptop");
    // Display the updated shopping cart
    cart.displayCart();
    return 0;
}