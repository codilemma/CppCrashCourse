// Reference Types
//
// Pointers = used to encode an object's address and the object's type
// printf specifier for a pointer is %p.
//
// The address will be randomized each time it is compiled du to " address
// space layout randomization", a security feature that scrambles the base
// address of important memory regions to hamper exploitation.
//
// Member-of-pointer operator (->).  Dereferences a pointer and accesses a member
// of the pointer object.
//



#include <cstdio>
#include <cstdint>  //allows specification of int8_t, int16_t, int32_t, int64_t
#include <cstddef>  //permits bitwise logical operations , std::byte, also size_t

class ClockOfTheLongNow{
  private:
    int year;
  public:
    void add_year() {   // method
      year++;
    }
    bool set_year(int new_year){          // setter
      if (new_year < 2019) return false;
      this->year = new_year;
      return true;
    }
    int get_year() const {   // getter -- now a const method
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

void add_year(ClockOfTheLongNow& clock){
  clock.set_year(clock.get_year() + 1);   // No deref operator needed
}

struct College {
  char name[256];
};
void print_name(College* colleges, size_t n_colleges) {
  for (size_t i = 0; i < n_colleges; i++) {
    printf("%s College\n", colleges[i].name);
  }
}

// For linked lists
struct Element {
  Element *next{};    // 1 - Each element has a pointer to the next element, initializes to nullptr
  void insert_after(Element *new_element){ // 2 - Insert new element
    new_element->next = this->next; // 3 - Sets the 'next' nember of 'new_element' to the next of 'this'
    this->next = new_element;  // 4 - sets 'next' of 'this' to 'new_element) 
  }
  char prefix[2];   
  short operating_number; 
};

// Const Method
bool is_leap_year(const ClockOfTheLongNow &clock) {
  if (clock.get_year() % 4 > 0) return false;
  if (clock.get_year() % 100 > 0) return true;
  if (clock.get_year() % 400 > 0) return false;
  return true;
}

// const Member Variables & Member Initializer Lists
//struct Avout{
//  Avout(const char *name, long year_of_apert)
//  :name{ name }, apert { year_of_apert } {
//
//  }

//};



int main() {
  int gettysburg{};
  printf("Inital Gettysburg Value: %d\n", gettysburg);          
  int *gettysburg_address = &gettysburg;            //declare a pointer to address of int
  printf("Gettysburg Address: %p\n", gettysburg_address);  
  printf("Gettysburg Address: %p\n", &gettysburg);         
  *gettysburg_address = 17355;  // Dereference pointer to store value at the address of gettysburg int.
  printf("Value Stored at Gettysburg Address: %d\n", *gettysburg_address);  

  // Pointers and classes
  ClockOfTheLongNow clock0 { 2019 };
  ClockOfTheLongNow* clock_ptr = &clock0;
  clock_ptr->set_year(2020);
  printf("Address of clock object: %p\n", clock_ptr);
  printf("Value of clock's year: %d\n", clock_ptr->get_year());   // first method
  printf("Value of clock's year: %d\n", (*clock_ptr).get_year()); // secodn method. more verbose, no benefit over first method.

  // Decayed Array
  int key_to_the_universe[]{ 3, 6, 9 };
  int *key_ptr = key_to_the_universe;   //Points to 3
  printf("Value of first array object: %d\n", *key_ptr);

  // Handling Decayed Array
  College best_colleges[] = { "Magdalen", "Nuffield", "Kellogg" };
  print_name(best_colleges, sizeof(best_colleges) / sizeof(College));

  // Obtain the address of the nth element of an array
  College *third_college_ptr = &best_colleges[2];
  printf("The Address of the Third Best College %p:\n", third_college_ptr);
  College *other_third_college_ptr = best_colleges + 2;
  printf("The Address of the Third Best College %p:\n", other_third_college_ptr);

  // Buffer Overflows
  char lower0[] = "abc?e";
  char upper0[] = "ABC?E";
  char *upper_ptr0 = upper0;       // Equivalent:  &upper[0];

  lower0[3] = 'd';                // lower now contains a, b, c, d, e, \0
  upper_ptr0[3] = 'D';            // upper now contains A, B, C, D, E, \0

  char letter_d0 = lower0[3];      // letter_d equals 'd'
  char letter_D0 = upper_ptr0[3];  // ledder_D equals 'D'

  printf("lower: %s\nupper: %s\n", lower0, upper0);

  //lower0[7] = 'g';                // Super BAD. You must never do this. Buffer Overflow
                                 // Exceeded aloted storage.  Compiler does not catch
                                 // Can result in unexpected behavior

  // The Connection Between Brackets and Pointer Arithmetic
  char lower[] = "abc?e";
  char upper[] = "ABC?E";
  char *upper_ptr = &upper[0];

  *(lower + 3) = 'd';
  *(upper_ptr + 3) = 'D';

  char letter_d = *(lower + 4); // lower decays into a pointer when we add
  char letter_D = *(upper_ptr + 4);

  printf("lower: %s\nupper: %s\n", lower, upper);

  //*(lower + 7) = 'g';   // Super BAD  
                          // Can cause access violations, program crashes, security 
                          // vulnerabilites, and corrupted data.  Potentially writing to
                          // some memory that doesn't belong to "lower"


  // References - Typically safer and more convenient versions of pointers.
  ClockOfTheLongNow clock { 2019 };
  printf("The year is %d.\n", clock.get_year());
  add_year(clock);  // Clock is implicitly passed by reference
  printf("The year is %d.\n", clock.get_year());

  // Linked Lists - Data structure where each element holds a pointer to next element
  Element trooper1, trooper2, trooper3;  // 1 - Initialize three stormtroopers
  trooper1.prefix[0] = 'T';              
  trooper1.prefix[1] = 'K';              
  trooper1.operating_number = 421;
  trooper1.insert_after(&trooper2);      // 2 - Insert trooper 1 as next element in list
  trooper2.prefix[0] = 'F';
  trooper2.prefix[1] = 'N';
  trooper2.operating_number = 2187;
  trooper2.insert_after(&trooper3);     // 3 -  Insert trooper 2 as next element in list
  trooper3.prefix[0] = 'L';
  trooper3.prefix[1] = 'S';
  trooper3.operating_number = 005;      // 4 -  Insert trooper 3 as next element in list


  // Iterates through the linked list.  Assign cursor pointer to the addres of trooper 1
  // Before each iteration, checks to make sure that cursor is not nullptr.  
  // After each iteration, cursor is set to the next element. 
  for (Element *cursor = &trooper1; cursor; cursor = cursor->next){
    printf("Stormtrooper %c%c-%d\n",
            cursor->prefix[0],
            cursor->prefix[1],
            cursor->operating_number);
  }

  // Employing References
  // *Referenses cannot be reseated.
  // The following example initializes an int reference and then attempts to reseat it
  // with a new_value
   int original = 100;
   int &original_ref = original;
   printf("Original: %d\n", original);     
   printf("Reference: %d\n", original_ref); 

   int new_value = 200;
   original_ref = new_value;               // Does not reseat original_ref so that it points to new_value.    
   printf("Orginal: %d\n", original);
   printf("New Value: %d\n", new_value);     
   printf("Reference: %d\n", original_ref);  

  // this Pointers
  // within method definitions, you can access the current object using the this pointer.
  // see struct Element {} above*

  // const Arguments


}
