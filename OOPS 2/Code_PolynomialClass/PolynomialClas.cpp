#include <iostream>
using namespace std;

class Polynomial {
    int capacity;
    
    public:
    int *degCoeff;
    
    // 1. Default constructor
    Polynomial(){
        capacity = 5;
        degCoeff = new int[5];
        for(int i = 0; i < capacity; i++){
            degCoeff[i] = 0;
        }
    }
    
    // 2. Copy constructor
    Polynomial(Polynomial const &p){
        this -> degCoeff = new int[p.capacity];
        for(int i = 0; i < p.capacity; i++){
            this -> degCoeff[i] = p.degCoeff[i];
        }
        
        this -> capacity = p.capacity;
    }
    
    // 3. setCoefficient
    void setCoefficient(int degree, int coeff){
        if(degree >= capacity){
            int size = 2*capacity;
            while(size <= degree){
                size *= 2;
            }
            int *newDegCoeff = new int[size];
            for(int i = 0; i < size; i++){
                if(i >= capacity){
                    newDegCoeff[i] = 0;
                }
                else{
                    newDegCoeff[i] = degCoeff[i];
                }
            }
            capacity = size;
            delete [] degCoeff;
            degCoeff = newDegCoeff;
        }
        degCoeff[degree] = coeff;
    }
    
    // 4. Overload "+" operator (P3 = P1 + P2) :
    Polynomial operator+(Polynomial const &p){
        Polynomial pNew;
        int newCapacity = max(this -> capacity, p.capacity);
        int *newData = new int[newCapacity];
        
        int i = 0;
        for( i; i < min(this -> capacity, p.capacity); i++){
            newData[i] = (this -> degCoeff[i] + p.degCoeff[i]);
        }
        for( i; i < max(this -> capacity, p.capacity); i++){
            if(this -> capacity > p.capacity){
                newData[i] = this -> degCoeff[i];
            }
            else{
                newData[i] = p.degCoeff[i];
            }
        }
        delete [] pNew.degCoeff;
        pNew.degCoeff = newData;
        pNew.capacity = newCapacity;
        
        return pNew;
    }
    
    // 5. Overload "-" operator (P3 = p1 - p2) :
    Polynomial operator-(Polynomial const &p){
        Polynomial pNew;
        int newCapacity = max(this -> capacity, p.capacity);
        int *newData = new int[newCapacity];
        
        int i = 0;
        for( i; i < min(this -> capacity, p.capacity); i++){
            newData[i] = (this -> degCoeff[i] - p.degCoeff[i]);
        }
        for( i; i < max(this -> capacity, p.capacity); i++){
            if(this -> capacity > p.capacity){
                newData[i] = this -> degCoeff[i];
            }
            else{
                newData[i] = p.degCoeff[i];
            }
        }
        delete [] pNew.degCoeff;
        pNew.degCoeff = newData;
        pNew.capacity = newCapacity;
        
        return pNew;
    }
    
    // 6. Overload * operator (P3 = P1 * P2) :
    Polynomial operator*(Polynomial const &p){
        Polynomial pNew;
        int newCapacity = (this -> capacity + p.capacity);
        int *newData = new int[newCapacity];
        
        for(int i = 0; i < newCapacity; i++){
            newData[i] = 0;
        }
        
        for(int i = 0; i < this -> capacity; i++){
            for(int j = 0; j < p.capacity; j++){
                int store = this -> degCoeff[i] * p.degCoeff[j];
                newData[i+j] = newData[i+j] + store;
            }
        }
        delete [] pNew.degCoeff;
        pNew.degCoeff = newData;
        pNew.capacity = newCapacity;
        
        return pNew;
    }
    
    // 7. Overload "=" operator (Copy assignment operator) -
    void operator=(Polynomial const &p){
        this -> degCoeff = new int[p.capacity];
        for(int i = 0; i < p.capacity; i++){
            this -> degCoeff[i] = p.degCoeff[i];
        }
        
        this -> capacity = p.capacity;
    }
    
    // 8. print() -
    void print(){
        for(int i = 0; i < capacity; i++){
           if(degCoeff[i] != 0){
               cout << degCoeff[i] << 'x' << i <<" ";
           }
        }
        cout << endl;
    }
    
};

// ================================================================================================
// ===================_____________DO_NOT_EDIT_INT_MAIN()_____________=============================
// ================================================================================================
 
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
