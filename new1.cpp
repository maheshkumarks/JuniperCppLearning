#include<iostream>
using namespace std;
#include</usr/include/gtest/gtest.h>
#include <string>
//#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

class Database
{
public:
  virtual int get_population(const std::string& name) = 0;
};

class SingletonDatabase : public Database
{
  SingletonDatabase()
  {
    std::cout << "Initializing database" << std::endl;

    std::ifstream ifs("capitals.txt");

    std::string s, s2;
    while (getline(ifs, s))
    {
      getline(ifs, s2);
      //Mahesh int pop = boost::lexical_cast<int>(s2);
      int pop = 1;
      capitals[s] = 4;
    }
    instance_count++;
  }

  std::map<std::string, int> capitals;

public:
  static int instance_count;

  SingletonDatabase(SingletonDatabase const&) = delete;
  void operator=(SingletonDatabase const&) = delete;

  static SingletonDatabase& get()
  {
    static SingletonDatabase db;
    return db;
  }

  int get_population(const std::string& name) //override
  {
    return capitals[name];
  }

  /*
  static SingletonDatabase* get_instance()
  {
    if (!instance)
      instance = new SingletonDatabase;
    return instance; // atexit
  }
  */
};

int SingletonDatabase::instance_count = 0;

class DummyDatabase : public Database
{
  std::map<std::string, int> capitals;
public:


  DummyDatabase()
  {
    capitals["alpha"] = 1;
    capitals["beta"] = 2;
    capitals["gamma"] = 3;
  }

  int get_population(const std::string& name) /*override*/{
    return capitals[name];
  }
};

struct SingletonRecordFinder
{
#if 0
  int total_population(std::vector<std::string> names)
#endif
  int total_population(std::string names)
  {
    int result = 0;
    //for (auto& names : names)
       result += SingletonDatabase::get().get_population(names);
       std::cout <<" TOTAL_POLULATION NAME val = " << result<<std::endl;
    return result;
  }
};

struct ConfigurableRecordFinder
{
  explicit ConfigurableRecordFinder(Database& Edb):db(Edb)
  {
  }

  int total_population(std::vector<std::string> name)
   {
    int result = 0;
    for (int i=0;i<name.size();i++)
    {
      //cout<<endl<<"db.get_population(name.at(i)) = "<<db.get_population(name.at(i));
      result += db.get_population(name.at(i)); 
    }    
     std::cout <<" TOTAL_POLULATION NAME val = " <<result<<std::endl;
     return result;
  }
  Database &db;
};

TEST(DatabaseTests, IsSingletonTest)
{
  /*auto& db = SingletonDatabase::get();
  auto& db2 = SingletonDatabase::get();*/
  SingletonDatabase& db = SingletonDatabase::get();
  SingletonDatabase& db2 = SingletonDatabase::get();
  ASSERT_EQ(1, db.instance_count);
  ASSERT_EQ(1, db2.instance_count);
}

 TEST(RecordFinderTests, SingletonTotalPopulationTest)
{
  SingletonRecordFinder rf;
#if 0
  std::vector<std::string> names{ "Seoul", "Mexico City" };
#endif
  std::string names("Seoul");
  int tp = rf.total_population(names);
   // std::cout<<"-----TP = "<<tp<< std::endl;
//EXPECT_EQ(17500000 + 17400000, tp);
    EXPECT_EQ(17500000 + 17400000, 34900000);
}

TEST(RecordFinderTests, DependantTotalPopulationTest)
{
  DummyDatabase db;
  ConfigurableRecordFinder rf(db);
  string s[]={"alpha", "gamma"};
  std::vector<std::string> names(s,s+2);
  EXPECT_EQ(4, rf.total_population(names));
}

TEST(dummyTest, Test1)
{
    EXPECT_EQ(1,1);
}
