#ifndef PATIENT_H
#define PATIENT_H
#include <QString>

class Patient
{
    QString name;
    QString userName;
    QString password;
    QString email;
    QString phone;
    QString insuranceCompany;
    int redeem;
    int age;
    int insuranceNumber;
    bool loginState;
public:
    Patient();
    void setName(QString name);
    void setUsername(QString username);
    void setPassword(QString password);
    void setEmail(QString Email);
    void setInCompany(QString Company);
    void setPhone(QString phone);
    void setredeem(int redeem);
    void setAge(int age);
    void setInsuranceno(int inNumber);
    QString getName();
    QString getusername();
    QString getpassword();
    QString getemail();
    QString getphone();
    int getredeem();
    int getage();
    int getInsurance();
    QString getInsurance_Company();

};

#endif // PATIENT_H
