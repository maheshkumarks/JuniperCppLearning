/* Adding header to the file
*/

#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>
using namespace std; //Also use std::endl, std::cout locally for local scopes
#include<string>
#include<cstring>
#include<typeinfo>
#include</usr/include/gtest/gtest.h>
//#include<header>
#define TEST_START cout<<endl<<"############# TEST_START "<<__FUNCTION__<<" #############"<<endl;
#define TEST_END cout<<endl<<"############## TEST_END "<<__FUNCTION__<<" ##############"<<endl;
//using namespace testing;
#define print(a) cout<<endl<<a;

#define test_start cout<<endl<<"############# TEST_START "<<__FUNCTION__<<" #############"<<endl;
#define test_end cout<<endl<<"############## TEST_END "<<__FUNCTION__<<" ##############"<<endl;

#define ts cout<<endl<<"############# TEST_START "<<__FUNCTION__<<" #############"<<endl;
#define te cout<<endl<<"############## TEST_END "<<__FUNCTION__<<" ##############"<<endl;

struct date
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
    static date* dd()
    {
        date *new_dd = new date;
        new_dd->day = 0;
        new_dd->month = 0;
        new_dd->year = 0;
        return new_dd;
    }
};
#if 0
date dd;
dd.day =0;
dd.month = 0;
dd.year = 0;
#endif

#if 0
void configs()
{
   int i;
   //cout<<"set groups mahesh-globalTrapScale interfaces xe-0/0/34 flexible-vlan-tagging"<<endl;
   //cout<<"set groups mahesh-globalTrapScale interfaces xe-0/0/34 encapsulation flexible-ethernet-services"<<endl;
   //cout<<"set groups mahesh-globalTrapScale interfaces xe-0/0/22 flexible-vlan-tagging"<<endl;
   //cout<<"set groups mahesh-globalTrapScale interfaces xe-0/0/22 encapsulation flexible-ethernet-services"<<endl;
   for(i=3001;i<=4000;i++){
    cout<<"set groups mahesh-globalTrapScale interfaces xe-0/0/34 unit "<<i<<" encapsulation vlan-bridge"<<endl;
    cout<<"set groups mahesh-globalTrapScale interfaces xe-0/0/34 unit "<<i<<" vlan-id "<<i<<endl;
    cout<<"set groups mahesh-globalTrapScale interfaces xe-0/0/22 unit "<<i<<" encapsulation vlan-bridge"<<endl;
    cout<<"set groups mahesh-globalTrapScale interfaces xe-0/0/22 unit "<<i<<" vlan-id "<<i<<endl;
    cout<<"set groups mahesh-globalTrapScale vlans vlan"<<i<<" vlan-id "<<i<<endl;
    cout<<"set groups mahesh-globalTrapScale vlans vlan"<<i<<" interface xe-0/0/22."<<i<<endl;
    cout<<"set groups mahesh-globalTrapScale vlans vlan"<<i<<" interface xe-0/0/34."<<i<<endl;
    }
}

class tcb
{
    int task_id;
    string task_name;
    int priority;
    static int num_task;
public:
    ~tcb();
public:
    void setTaskAttribute(int,string);
    void showTaskInfo()const;
    int assignTaskId()
    {
        static int task_id_gen=1000;
        return task_id_gen--;
    }
    tcb();
    tcb(const tcb &x);
    static int taskCount()
    {
       return num_task;
    }
    //tcb& tcb::tcb(tcb &x);
};

int tcb::num_task = 0;
void tcb::setTaskAttribute(int prio,string name)
{
    this->priority = prio;
    this->task_name=name;
}

void tcb::showTaskInfo()const
{
    cout<<endl<<"Name: "<<task_name<<" Id: "<<task_id<<" Priority: "<<priority;
}

tcb::tcb()
{
    cout<<endl<<"In Constructor";
    num_task++;
    this->task_id = assignTaskId();
    this->priority = 0xFF;
    this->task_name = "No_Name";
}

tcb:: ~tcb()
{
    cout<<endl<<"In destructor deleting "<<this->task_name<<endl;
}

tcb::tcb(const tcb &x)
{
    this->task_id = x.task_id;
    this->priority = x.priority;
    this->task_name=x.task_name;
}
#if 0
tcb& tcb::tcb(tcb &x)
{
    this->task_id = task_id_gen++;
    this->priority = x.priority;
    this->task_name=x.task_name;
    return *this;
}
#endif

void my_init()__attribute__((constructor));

/*This will print before m_a_i_n*/
void my_init()
{
    //cout<<endl<<"check"<<endl;
}

void init_sys()
{
   tcb t;
   t.showTaskInfo();
}

void tc1_tcbTest()
{
    TEST_START 
    cout<<endl<<"TaskCount = "<<tcb::taskCount()<<endl;   
    init_sys();
    tcb t1;
    t1.setTaskAttribute(1,"Task1");
    t1.showTaskInfo();
    cout<<endl<<"TaskCount = "<<tcb::taskCount()<<endl; 
    tcb *t2;
    t2 = new tcb;
    t2->setTaskAttribute(2,"Task2");
    t2->showTaskInfo();
    cout<<endl<<"TaskCount = "<<tcb::taskCount()<<endl;
    delete t2;
    cout<<endl<<"TaskCount = "<<tcb::taskCount()<<endl;
    TEST_END
}

class Demo
{
public:
    Demo():pi(3.14) //In-Member Initialisation
    {

    }

private:
  const double pi;
};

void tc2()
{
   TEST_START
   
   Demo d;

   TEST_END
}

class cpp11typeInit
{
   private:
   //int a = 4;
   //float fl = 3.4;
};

void tc3_cpp11typeInitTest()
{
   TEST_START
   cpp11typeInit c;
   TEST_END
}

class Sample
{
    public:
    Sample(){ 
        data = new char[10];
        std::strcpy(data, "NoName");
    }
    Sample(const char *str){ 
        data = new char[std::strlen(str)+1];
        std::strcpy(data, "NoName");
    }
    
    Sample (const Sample &S)   //Deep Copy
    {
       data = new char[std::strlen(S.data)+1];
       std::strcpy(data, S.data);
    }
     
     Sample& operator=(const Sample &S)  //Assignment operator. Without this and above fn crashme will crash
     {
        //this->data = new char[std::strlen(S.data)+1];
        if(this->data != NULL)
            delete this->data;
        this->data = new char[std::strlen(S.data)+1];
        std::strcpy(this->data, S.data);
        return *this;
     }

    ~Sample() {
        delete [] data;
    }
    void showData() const {
        cout<<"data = "<<data<<endl;
    }
    private:
    char *data;
};
void crashme()
{
    Sample sa("one"), sb;
    
    Sample temp(sa);//Copy constructor

    temp.showData();
//#if 0
    sb = temp; //Assignment operator
//#endif
    sb.showData();
   
    Sample temp2 = sa; 
}
int tc4()
{
   TEST_START
    crashme();
    while(1);
   TEST_END
}

class tc5_noHeapObj
{
    int a;
public:
#if 0
    //Following statement will force object creation from stack only
    void* operator new(size_t size) = delete;
    void operator delete(void *p,size_t size) = delete;
#endif
};

void tc5()
{
    TEST_START
    tc5_noHeapObj t;
    TEST_END
}

class singletonClass
{
    int a;
    singletonClass(){};
    singletonClass(const singletonClass&) = delete;
    singletonClass& operator=(const singletonClass&) = delete;
    static singletonClass single;
    public:
    static singletonClass& getSingletonObj()
    {
        return single;
    }

};
singletonClass singletonClass::single;

void tc6_singleton()
{
    TEST_START
    singletonClass &S = singletonClass::getSingletonObj(); 
    TEST_END
}

class Circle;
class Rect;
class AllShapesHere{
    public:
    double calcualteArea(Rect &r, Circle& c);
    double calcualteSurfaceArea(Rect &r, Circle& c);
    double do_something_else(Rect &r, Circle& c);
};
class Circle{
    public:
    Circle(double r=100.0):radius(r), pi(3.14159)
    {
    }
    private:
    const double pi;
    double radius;
    friend double calcualteAllShapesArea(Rect &, Circle&);
    friend double AllShapesHere::calcualteArea(Rect &r, Circle& c);
    //friend class AllShapesHere;
};
class Rect{
    public:
    Rect(int l=1.0,double b=1.0): length(l), breadth(b)
    {
    }
    private:
    double length, breadth;
    friend double calcualteAllShapesArea(Rect &, Circle&);
    friend double AllShapesHere::calcualteArea(Rect &r, Circle& c);
    //friend class AllShapesHere;
};
double AllShapesHere::calcualteArea(Rect &r, Circle &c)
{
 return r.length*r.breadth + c.pi * c.radius *c.radius;
}
double AllShapesHere::calcualteSurfaceArea(Rect &r, Circle &c)
{
// return r.length*r.breadth + c.pi * c.radius *c.radius;
    return 0;
}
double AllShapesHere::do_something_else(Rect &r, Circle &c)
{
 //return r.length*r.breadth + c.pi * c.radius *c.radius;
    return 0;
}
// Use global methods trying to slove this
// Use AllShapesHere class to solve it
// use only one method of a class scoped methods of AllShapesHere solve it

double calcualteAllShapesArea(Rect &r, Circle& c){
    return r.length*r.breadth + c.pi * c.radius *c.radius;
}
void handleShapesInstances(){
    Circle c(100.0);
    Rect r(12.0,5.0);
    
    double area = calcualteAllShapesArea(r, c);
    cout<<"The sum of all the mapped area = "<<area<<endl;
    
    #if 1
    AllShapesHere allShapesObj;
    area = allShapesObj.calcualteArea(r,c);
    cout<<"The sum from class for all the mapped area = "<<area<<endl;
    area = allShapesObj.calcualteSurfaceArea(r,c);
    cout<<"The sum from class for all the mapped surface area = "<<area<<endl;
    area = allShapesObj.do_something_else(r,c);
    cout<<"The do_something_else area = "<<area<<endl;
    #endif
}

void tc7_friend()
{
    TEST_START
    handleShapesInstances();
    TEST_END
}
class Better;
class Best;
class Basic
{
public:
    void services()
    {
        cout<<endl<<"Basic Services";
    }
    virtual ~Basic(){cout<<endl<<__FUNCTION__;};
};

class Better:public Basic
{
public:
    void services()
    {
        cout<<endl<<"Better Services";
    }
    ~Better() {cout<<endl<<__FUNCTION__;};
};

class Best:public Better
{
public:
     void services()
     {
         cout<<endl<<"Best Services";
         if(typeid(*this)==typeid(Basic))
         {
            cout<<endl<<"type_id(*this)==type_id(Basic)";
         }   
         if(typeid(*this)==typeid(Better))
         {
            cout<<endl<<"type_id(*this)==type_id(Better)";
         }
         if(typeid(*this)==typeid(Best))
         {
            cout<<endl<<"type_id(*this)==type_id(Best)";
         }
      }
     ~Best() {cout<<endl<<__FUNCTION__;};
 };

void tc7_inheritance()
{
    TEST_START

    print("Basic class creation and deletion using basic pointer");
    Basic *bs;
    bs = new Basic;
    bs->services();
 print("@@@@@@@@@@@@@@@@@@@");
        if(typeid(*bs)==typeid(Basic))
         {
            cout<<endl<<"type_id(*this)==type_id(Basic)";
         }   
         if(typeid(*bs)==typeid(Better))
         {
            cout<<endl<<"type_id(*this)==type_id(Better)";
         }
         if(typeid(*bs)==typeid(Best))
         {
            cout<<endl<<"type_id(*this)==type_id(Best)";
         }
print("@@@@@@@@@@@@@@@@@@@");
   delete bs;

    print("Best class creation and deletion using Best pointer Basic->Better->Best");
    Best *bt = new Best;
    bt->services();
    
print("@@@@@@@@@@@@@@@@@@@");
        if(typeid(*bt)==typeid(Basic))
         {
            cout<<endl<<"type_id(*this)==type_id(Basic)";
         }   
         if(typeid(*bt)==typeid(Better))
         {
            cout<<endl<<"type_id(*this)==type_id(Better)";
         }
         if(typeid(*bt)==typeid(Best))
         {
            cout<<endl<<"type_id(*this)==type_id(Best)";
         }
print("@@@@@@@@@@@@@@@@@@@");
    delete bt;
print("Best class creation and deletion using Basic pointer Basic->Better->Best");
    bs = new Best;
    bs->services();
    print("@@@@@@@@@@@@@@@@@@@");
        if(typeid(*bs)==typeid(Basic))
         {
            cout<<endl<<"type_id(*this)==type_id(Basic)";
         }   
         if(typeid(*bs)==typeid(Better))
         {
            cout<<endl<<"type_id(*this)==type_id(Better)";
         }
         if(typeid(*bs)==typeid(Best))
         {
            cout<<endl<<"type_id(*this)==type_id(Best)";
         }
print("@@@@@@@@@@@@@@@@@@@");
    delete bs;
    TEST_END
}

class LandAnimal
{
public:
    virtual void legs()=0;
    virtual void avg_age()=0;  
    void blood_color(){cout<<endl<<"RBC+WBC";}; 
    virtual ~LandAnimal(){}; 
};

class Elephant: public LandAnimal
{
public:
    void legs()
    {
        cout<<endl<<"Have 4";
    }
    void avg_age()
    {
        cout<<endl<<"60";
    }
};

class Human: public LandAnimal
{
public:
    void legs()
    {
        cout<<endl<<"Have 2";
    }
    void avg_age()
    {
        cout<<endl<<"70";
    }
};
 
void encyclo(LandAnimal *la)
{   
    la->avg_age();
    la->legs();
    la->blood_color();
}

void demo_inh()
{
    int choice = 0;
    LandAnimal *la;
    while(1)
    {
        print("Press 1 for human and 2 for elephant 3 for exit: ");
        cin>>choice;
        switch(choice)
        {   
            case 1:
            la = new Human;
            encyclo(la);
            delete(la); 
            break;

            case 2:
            la = new Elephant;
            encyclo(la);
            delete(la);
            break;
    
            default:
            break;
        }
        if(choice > 2) break;
    }
}
void tc8()
{
    ts 
    demo_inh(); 
    te
}
#endif
/*Class & Object Design 
Design a class Say Person with following details. 
Try to focus on what would change and what would not and choose data types.
Try to make this class best from the C++ design view.

Data/attributes
1. full_name
2. date_of_birth
3. birth_location
4. nationality
5. passport_number
6. mobile_number
7. current_location

// minium methods 
1. a ctor to initialize all the details
2. a function to edit the data /attribute 
3. a function that prints the objects
4. a function that says how may old is a person

Possible skeleton could be

class Person{
    public:
        // clients interface
        ..
    private:
        // person's data
        ...
};
*/
struct personDetail
{
     string full_name;
     date date_of_birth;
     string birth_location;
     string nationality;
     string passport_number;
     unsigned long mobile_number;
     string current_location;
};

class Person{
    private:
    const string full_name;
    const date date_of_birth;
    const string birth_location;
    const string nationality;
    string passport_number;
    unsigned long mobile_number;
    string current_location;        
    
    public:
    Person();
    Person(personDetail *p);
    int updateMobileNumber(long int new_no);
    int updateCurrentLocation(string s);
    void printPersonDetails();
    unsigned int findAgeOfPerson();    
    int updatePassportNumber(string s);    
};

Person::Person(): full_name("NA"),date_of_birth(*(date::dd())),birth_location("NA"),nationality("NA")
{
}

Person::Person(personDetail *p): full_name(p->full_name),date_of_birth(p->date_of_birth),birth_location(p->birth_location),nationality(p->nationality)

{
    this->mobile_number = p->mobile_number;
    this->current_location = p->current_location;
    this->passport_number = p->passport_number;
}

int Person::updateMobileNumber(long int new_no)
{   
    mobile_number = new_no;
}

int Person::updateCurrentLocation(string s)
{
    current_location = s;
}

int Person::updatePassportNumber(string s)
{
    passport_number = s;
}

void Person::printPersonDetails()
{
    cout<<endl<<"####### Printing Person Details #######";
    cout<<endl<<"Name: "<<full_name;
    cout<<endl<<"Dob: "<<date_of_birth.day<<"/"<<date_of_birth.month<<"/"<<date_of_birth.year;
    cout<<endl<<"Birth Place: "<<birth_location;
    cout<<endl<<"Nationality: "<<nationality;
    cout<<endl<<"Passport No.: "<<passport_number;
    cout<<endl<<"Mobile: "<<mobile_number;
    cout<<endl<<"Current Loc: "<<current_location;
}   

unsigned int Person::findAgeOfPerson()
{
    int month[] = { 31, 28, 31, 30, 31, 30, 31,  
                          31, 30, 31, 30, 31 }; 
  
    int birth_date = date_of_birth.day;
    int birth_month = date_of_birth.month;
    int birth_year = date_of_birth.year;
    
    int current_date = 11;
    int current_month = 7;
    int current_year = 2019;

    // if birth date is greater then current birth 
    // month then do not count this month and add 30  
    // to the date so as to subtract the date and 
    // get the remaining days 
    if (birth_date > current_date) { 
        current_date = current_date + month[birth_month - 1]; 
        current_month = current_month - 1; 
    } 
  
    // if birth month exceeds current month, then do 
    // not count this year and add 12 to the month so 
    // that we can subtract and find out the difference 
    if (birth_month > current_month) { 
        current_year = current_year - 1; 
        current_month = current_month + 12; 
    } 
  
    // calculate date, month, year 
    int calculated_date = current_date - birth_date; 
    int calculated_month = current_month - birth_month; 
    int calculated_year = current_year - birth_year;

    return calculated_year;
}

void tc9_Assignment1()
{
    ts
    
    personDetail p1;
    p1.full_name = "MAHESH";   
    p1.date_of_birth.day =8;
    p1.date_of_birth.month =8 ;
    p1.date_of_birth.year = 1990;
    p1.birth_location = "TMK";
    p1.nationality = "IND";
    p1.passport_number = "K320";
    p1.mobile_number = 8015097550;
    p1.current_location = "BLR1";
   
    Person objPerson(&p1);
    objPerson.printPersonDetails(); 

    cout<<endl<<endl<<"Updating Mobile Number";
    objPerson.updateMobileNumber(8105097551);
    objPerson.printPersonDetails(); 

    cout<<endl<<endl<<"Updating Current location";
    objPerson.updateCurrentLocation("BLR2");
    objPerson.printPersonDetails();

    cout<<endl<<endl<<"Updating passport";
    objPerson.updatePassportNumber("K321");
    objPerson.printPersonDetails();


    cout<<endl<<"Age: "<<objPerson.findAgeOfPerson();   
    te
}
#if 0
enum class PointType
{
  cartesian,
  polar
};
#endif

class Polar;
class Cartesian;
class Point
{
  /*Point(float a, float b, PointType type = PointType::cartesian)
  {
  if (type == PointType::cartesian)
  {
  xc = a; 
  yc = b;
  
  }
  else
  {
  xc = a*cos(b);
  yc = a*sin(b);
  }
  }*/

protected:
  Point(const float x, const float y)
    : xc(x),
      yc(y)
  {
  }
public:
  float xc, yc;
  static Point* NewPolar(const float a,const float b);
  static Point* NewCartesian(const float a,const float b);
  friend ostream& operator<<(ostream &out,const Point &p);

};

ostream& operator<<(ostream &out,const Point &p)
{
    out<<endl<<"xc = "<<p.xc<<". yc = "<<p.yc;
    return out;
}

class Polar:public Point
{
    public:
    Polar(const float a, const float b):Point((a*cos(b)),(a*sin(b)))
    {
    }
};

class Cartesian: public Point
{
public:
    Cartesian(const float a, const float b):Point(a,b)
    {
    }
};

Point* Point::NewPolar(const float a,const float b)
{
     Point *p = new Polar(a,b);
     return  p;
}
  
Point* Point::NewCartesian(const float a,const float b)
{
    Point *c =  new Cartesian(a,b);
    return c;
}

void tc10_Assignment3()
{
    ts

    Point *p1 = Point::NewPolar(5, M_PI_4);
   
    cout<<endl<<"M_PI_4: "<<M_PI_4<<" sin(M_PI_4): "<<sin(M_PI_4)<<" cos(M_PI_4): "<< cos(M_PI_4);
 
    std::cout<<(*p1)<<std::endl;

    Point *p2 = Point::NewCartesian(12,56);

    std::cout<<(*p2)<<std::endl;

    te
}
int main(int ac,char **av)
{
    cout<<"Hello C++: __cplusplus = "<<__cplusplus<<endl;
    tc9_Assignment1(); 
    testing::InitGoogleTest(&ac, av);
    tc10_Assignment3();
    return RUN_ALL_TESTS();
    //return 0;
}

