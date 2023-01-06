#include "patient.h"

Patient::Patient(){
    insuranceNumber = 0;
}
void Patient::setUsername(QString username){
    this->userName = username;
}
void Patient::setName(QString name){
    this->name = name;
}
void Patient::setPassword(QString password){
    this->password = password;
}
void Patient::setPhone(QString phone){
    this->phone = phone;
}
void Patient::setEmail(QString Email){
    this->email = Email;
}
void Patient::setredeem(int redeem){
    this->redeem = redeem;
}
void Patient::setAge(int age){
    this->age = age;
}
void Patient::setInsuranceno(int inNumber){
    this->insuranceNumber=inNumber;
}
void Patient::setInCompany(QString Company){
    this->insuranceCompany = Company;
}
QString Patient::getusername(){
    return userName;
}
QString Patient::getName(){
    return name;
}
QString Patient::getpassword(){
    return password;
}
QString Patient::getemail(){
    return email;
}
QString Patient::getphone(){
    return phone;
}
int Patient::getredeem(){
    return redeem;
}
QString Patient::getInsurance_Company(){
    return insuranceCompany;
}
int Patient::getInsurance(){
    return insuranceNumber;
}
int Patient::getage(){
    return age;
}
