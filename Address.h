#ifndef ADDRESS_H
#define ADDRESS_H
#include<iostream>
#include<string>
using namespace std;

class Address{
    int HouseNo;
    String City;
    String Province;
    String Country;
public:
    Address(){}
    Address(int houseNo,String city,String province,String country = "Pakistan"):
            HouseNo(houseNo),City(city),Province(province),Country(country){}
    Address(const Address& obj): 
    HouseNo(obj.HouseNo),City(obj.City),Province(obj.Province),Country(obj.Country){}
    friend ostream& operator<< (ostream& os,const Address& obj){
        os<<"----  Address ----"<<endl
            <<"House No : "<<obj.HouseNo<<endl
            <<"City : "<<obj.City<<endl
            <<"Province : "<<obj.Province<<endl
            <<"Country : "<<obj.Country<<endl;
        return os;
    }
    int getHouseNo() const {
        return HouseNo;
    }
    String getCity() const {
        return City;
    }
    String getProvince() const {
        return Province;
    }
    String getCountry() const {
        return Country;
    }
};

#endif