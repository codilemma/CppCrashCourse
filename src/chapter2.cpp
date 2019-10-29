//////////////////////////////////////////////////////////////////////////
// DATA TYPES //
//////////////////////////////////////////////////////////////////////////
//  ____________________________________________________________________________
// |           |        |               Size in Bytes               |           |
// |           |        |-------------------------------------------|           |
// |           |        |     32-bit OS       |      64-bit OS      | printf    |
// |           |        |-------------------------------------------| Format    |
// | Type      | Signed | Windows | Linux/Mac | Windows | Linux/Mac | Specifier |
// |----------------------------------------------------------------------------|
// | short     |   Yes  |    2    |     2     |    2    |     2     |   %hd     |
// |----------------------------------------------------------------------------|
// | unsigned  |   No   |    2    |     2     |    2    |     2     |   %hu     |
// | short     |        |         |           |         |           |           |
// |----------------------------------------------------------------------------|
// | int       |   Yes  |    4    |     4     |    4    |     4     |   %d      |
// |----------------------------------------------------------------------------|
// | unsigned  |   No   |    4    |     4     |    4    |     4     |   %u      |
// | int       |        |         |           |         |           |           |
// |----------------------------------------------------------------------------|
// | long      |   Yes  |    4    |     4     |    4    |     8     |   %ld     |
// |----------------------------------------------------------------------------|
// | unsigned  |   No   |    4    |     4     |    4    |     8     |   %lu     |
// | long      |        |         |           |         |           |           |
// |----------------------------------------------------------------------------|
// | long long |   Yes  |    8    |     8     |    8    |     8     |   %lld    |
// |----------------------------------------------------------------------------|
// | unsigned  |   No   |    8    |     8     |    8    |     8     |   %llu    |
// | long long |        |         |           |         |           |           |
//  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// float == single precision         | Typically 4 bytes
// double == double precision        | Typically 8 bytes
// long double == extended precision | Typically 8 bytes
//
// Floating point spec - IEEE_754
// 
// Floating point printf specifiers 
// (%e == displays scientific notation), (%f == displays a float with decimal digits)
// (%g == instructs printf function to choose the shortest)  <- Typically use this one
//
// Double printf specifiers
// (%le == displays scientific notation), (%lf == displays a float with decimal digits)
// (%lg == instructs printf function to choose the shortest)
//
// char printf specifier == %c
// wchar_t printf specifier == %lc
//
// sizeof() always returns a size_t (printf specifier == %zd for decimal, %zx for hex)
//
// use void for functions that do not return a value
//
// research POD classes vs. unions and the danger of data corruption with unions.



#include <cstdio>
#include <cstdint>  //allows specification of int8_t, int16_t, int32_t, int64_t
#include <cstddef>  //permits bitwise logical operations , std::byte, also size_t

// Enumerations
enum class Race {
  Dinan,
  Teklan,
  Ivyn,
  Moiran,
  Camite,
  Julian,
  Aidan
};

enum class Operation {
  Add,
  Subtract,
  Multiply,
  Divide
};

// Plain-old-data (POD) Class
struct Book {
  char name[256];
  int year;
  int pages;
  bool hardcover;
};

struct PodStruct {
  uint64_t a;
  char b[256];
  bool c;
};

// class with methods
class ClockOfTheLongNow{
  private:
    int year;
  public:
    void add_year() {   // method
      year++;
    }
    bool set_year(int new_year){          // setter
      if (new_year < 2019) return false;
      year = new_year;
      return true;
    }
    int get_year() {
      return year;
    }
  //Constructor
  ClockOfTheLongNow(int year_in){
    if(!set_year(year_in)) {
      year = 2019;
    }
  }
  // Destructor
  ~ClockOfTheLongNow(){
    printf("This is the End of Time!");
  }
};

class Calculator{
  private:
    int a;
    int b;
    int result;
    Operation op;
  public:
    int calculate(int a, int b){
      switch (op){
        case Operation::Add:{
          result = a + b;
          return result;
        } break;
        case Operation::Divide:{
          result = a / b;
          return result;
        } break;
        case Operation::Multiply:{
          result = a * b;
          return result;
        } break;
        case Operation::Subtract:{
          result = a - b;
          return result;
        } break; 
        default: {
          printf("Invalid Operation - Try Again!");
        }
      }
    }
  // Class Constructor
  Calculator(Operation op_set){
    op = op_set;
  }
};

// Class with 4 constructors
struct Taxonomist {
  Taxonomist() {
    printf("(no argument)\n");
  }
  Taxonomist (char x) {
    printf("char: %c\n", x);
  }
  Taxonomist(int x) {
    printf("int: %d\n", x);
  }
  Taxonomist(float x) {
    printf("float: %f\n", x);
  }
};

// Initialize POD class in the definition 
// parentheses cannot be used to initialize member variables
struct JohanVanDerSmut {
  bool gold = true;
  int year_of_smelting_accident{ 1970 };
  char key_location[8] = { "x-rated" };
};

int main(){
  unsigned short a = 0b10101010; // 1 - binary representation
  printf("%hu\n", a);
  int b = 0123; // 2 - octal
  printf("%d\n", b);
  unsigned long long d = 0xFFFFFFFFFFFFFFFF; // 3 - hexadecimal
  printf("%llu\n", d);  

  // print an int in hex
  unsigned int a2 = 3669732608;
  printf("Yabba %x\n", a2);

  // print an int in octal
  unsigned int b2 = 69;
  printf("There are %u,%o leaves here.\n", b2, b2);

  // floating point declarations
  float a3 = 0.1F;
  double b3 = 0.2;
  long double c3 = 0.3L;

  // scientific notation in literals:
  double plancks_constant = 6.62607004e-32;

  // floating point prints
  double an = 6.0221409e23;
  printf("Avogadro's Number: %le %lf %lg\n", an, an, an);
  float hp = 9.75;
  printf("Hogwarts' Platform: %e %f %g\n", hp, hp, hp);

  // Char printing 
  char x = 'M';
  wchar_t y = L'Z';
  printf("Windows binaries start with %c%lc.\n", x, y);

  // Boolean Printing
  bool bool1 = true;
  bool bool2 = false;
  printf("%d %d\n", bool1, bool2);

  // Comparison Operators
  printf(" 7 ==  7: %d\n", 7  ==  7);  
  printf(" 7 !=  7: %d\n", 7  !=  7);  
  printf("10 > 20: %d\n", 10 >  20);  
  printf("10 >= 20: %d\n", 10 >= 20);  
  printf("10 < 20: %d\n", 10 <  20);  
  printf("20 <= 20: %d\n", 20 <= 20);

  // Logical Operators
  bool t = true;
  bool f = false;
  printf("!true: %d\n", !t);
  printf("true  &&  false: %d\n", t &&  f);
  printf("true  && !false: %d\n", t && !f);
  printf("true  ||  false: %d\n", t ||  f);
  printf("false ||  false: %d\n", f ||  f);

  // print the size of data types
  size_t size_c = sizeof(char);
  printf("char: %zd\n", size_c);
  size_t size_s = sizeof(short);
  printf("short: %zd\n", size_s);
  size_t size_i = sizeof(int);
  printf("int: %zd\n", size_i);
  size_t size_l = sizeof(long);
  printf("long: %zd\n", size_l);
  size_t size_ll = sizeof(long long);
  printf("long long: %zd\n", size_ll);

  // Arrays
  int arr[] = {1, 2, 3, 4};
  printf("The third element is %d.\n", arr[2]);
  arr[2] = 100;
  printf("The third element is %d.\n", arr[2]);

  // Use a for loop to find array max.
  unsigned long maximum = 0; 
  unsigned long values[] = { 10, 50, 20, 40, 0 }; 
  for(size_t i=0; i < 5; i++) { 
    if (values[i] > maximum) maximum = values[i]; 
  }
  printf("The maximum value is %lu\n", maximum); 

  // iterate over entire array (ie. range-based for loops)
  unsigned long maximum2 = 0;
  unsigned long values2 [] = {10, 50, 20, 40, 0};
  for (unsigned long value : values2){
    if (value > maximum2) maximum2 = value;
  }
  printf("The maximum value is %lu.\n", maximum2);

  // size of an array
  short array[] = {104, 105, 32, 98, 105, 108, 108, 0};
  size_t n_elements = sizeof(array) / sizeof(short);  // evaluated at compile time, no run-time costs.
  
  printf("array size: %zd\n", n_elements);

  // Use ASCII table to build an array of the lowercase letters in the alphabet
  // then convert to uppercase
  char alphabet[27];
  for (int i = 0; i < 26; i++){
    alphabet[i] = i + 97;
  }
  alphabet[26] = 0; // null terminate the string
  printf("%s\n", alphabet);
  for (int i = 0; i <26; i++){
    alphabet[i] = i + 65;
  }
  printf("%s\n", alphabet);

  // Switch statement with Enumerations
  Race race = Race::Dinan;

  switch(race){
    case Race::Dinan: {
      printf("You work hard.\n");
    } break;
    case Race::Teklan: {
      printf("You are very strong.\n");
    } break;
    case Race::Ivyn: {
      printf("You are a great leader.\n");
    } break;
    case Race::Moiran: {
      printf("My, how versatile you are!\n");
    } break;
    case Race::Camite: {
      printf("You're incredibly helpful.\n");
    } break;
    case Race::Julian: {
      printf("Anything you want!\n");
    } break;
    case Race::Aidan: {
      printf("What an enigma.\n");
    } break;
    default: {
      printf("Error: unknown race!\n");
    }
  }

  // Plain-Old-Data Classes
  Book neuromancer;
  neuromancer.pages = 271;
  printf("Neuromancer has %d pages.\n", neuromancer.pages);

  // Use Class
  ClockOfTheLongNow clock{ 2020 };    // initialization to set year to 2020
  printf("year: %d\n", clock.get_year());
  if(!clock.set_year(2018)){  // will fail; 2018 < 2019
    clock.set_year(2019);     // set back to default 2019
  }
  printf("year: %d\n", clock.get_year());
  clock.add_year();
  printf("year: %d\n", clock.get_year());

  // initializing fundamental types to Zero - 4 ways
  int a7 = 0;  // Initialized to 0
  int b7{};    // Initialized to 0
  int c7 = {}; // Initialized to 0
  int d7;      // Initialized to 0 (maybe) - Not reliable

  // initializing fundabental types with arbitrary values - 4 ways to initialize to 42
  int e7 = 42;
  int f7{ 42 };
  int g7 = { 42 };
  int h7(42);

  // initialize POD class
  PodStruct initialized_pod1{};        // All fields are zeroed  (you cannot use = 0)
  PodStruct initialized_pod2 = {};     // All fields are 
  
  PodStruct initialized_pod3 = { 42, "Hello"};       // Fileds a & are set; c set to 0
  PodStruct initialized_pod4 = { 42, "Hello", true}; // All fields are set;

  // Use Class with four constructors
  Taxonomist t1; 
  Taxonomist t2{ 'c' }; 
  Taxonomist t3{ 65537 }; 
  Taxonomist t4{ 6.02e23f }; 
  Taxonomist t5('g'); 
  Taxonomist t6 = { 'l' }; 
  Taxonomist t7{}; 
  // Taxonomist t8();  Problem - "most vexing parse" 

  // Narrowing Conversions
  float aa{ 1 };
  float bb{ 2 };
  int narrowed_result(aa/bb); // Pottentially nasty anrrowing conversion
  int result{ aa/bb };        // Compiler generates warning

  // Create and test calculator class.
  int num1 = 5;
  int num2 = 5;
  int calc_result = 0;
  Operation op;
  Calculator calc{ Operation::Add };
  calc_result = calc.calculate(num1, num2);
  printf("5 + 5 = %d\n", calc_result);
  Calculator calc2{ Operation::Divide };
  calc_result = calc2.calculate(num1, num2);
  printf("5 / 5 = %d\n", calc_result);
}
