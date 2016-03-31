#include <iostream>
using namespace std;
class Line
{
    public:
        int getLength( void );
        Line( int len );         // simple constructor
        Line( const Line &obj);  // copy constructor
        ~Line();                 // destructor
        
    private:
        int *ptr;
};

// Member functions definitions including constructor
Line::Line(int len)
{
    cout << "Normal constructor allocating ptr" << endl;
    // allocate memory for the pointer;
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "Copy constructor allocating ptr." << endl;
    ptr = new int;
    *ptr = *obj.ptr; // copy the value
}

Line::~Line(void)
{
    cout << "Freeing memory!" << endl;
    delete ptr;
}
int Line::getLength( void )
{
    return *ptr;
}

void display(Line arg_obj, Line arg_obj1)
{
    cout << "Length of line : " << arg_obj.getLength() <<endl;
}
// Main function for the program
int main( )
{
    Line line(10);
    Line line_2 = line;
    Line line_3(line);
    display(line, line);
    return 0;
}