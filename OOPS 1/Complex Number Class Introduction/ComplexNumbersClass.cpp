class ComplexNumbers {
    private :
    
    	int real;
    	int imaginary;
    
	public :
    
    	ComplexNumbers(int real, int imaginary){
            this -> real = real;
            this -> imaginary = imaginary;
        }
    
    	void print(){
            cout << this -> real << " + i" << this -> imaginary << endl;
        }
    
    	void plus(ComplexNumbers const &c2){
            real = real + c2.real;
            imaginary = imaginary + c2.imaginary;
        }
    
    	void multiply(ComplexNumbers const &c2){
            int temp = real;
            real = (real * c2.real) + (imaginary * c2.imaginary * (-1));
            imaginary = (temp * c2.imaginary) + (imaginary * c2.real);
        }
};