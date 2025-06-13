#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include"string.h"
#include"Address.h"
using namespace std;

class Person{
    String Id;
    String Name;
    int Age;
    Address address;
    String password; 
protected:
    String getPassword() const { return password; }
public:
    String getId() const { return Id; }
    Person(){}
    Person(String id,String pass,String name,int age,Address addrss):
        Id(id),password(pass),Name(name),Age(age),address(addrss){}
    Person(const Person& obj):
        Id(obj.Id),password(obj.password),Name(obj.Name),Age(obj.Age),address(obj.address){}
    friend ostream& operator<<(ostream& os,const Person& obj){
        os<<"ID : "<<obj.Id<<endl
            <<"Name : "<<obj.Name<<endl
            <<"Age : "<<obj.Age<<endl;
        return os;
    }

};
#endif