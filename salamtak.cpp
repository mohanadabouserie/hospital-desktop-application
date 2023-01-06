#include "salamtak.h"
#include "ui_salamtak.h"

Salamtak::Salamtak(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Salamtak)
{
    ui->setupUi(this);
    QFile inU("D:/AUC/1st year/2nd semester - Spring 2022/CSCE110104 - Fundamentals of Computing II/Project/project/project/Salamtak/users.txt");
    for(int i = 0; i < ROWS; i++){
        ui->RDcomboBox->addItem(doctors[i][0]);
    }
    for(int i = 0; i < 11; i++){
        ui->comboBox_4->addItem(QString::number(i));
        ui->comboBox_5->addItem(QString::number(i));
    }
    // Painkillers
    /*
           Medicine.push_back(qMakePair("Paracetmol", 29.5));
           ui->comboBox_3->addItem("Paracetmol");
           Medicine.push_back(qMakePair("Ibuprofen", 36.00));
           ui->comboBox_3->addItem("Ibuprofen");
           Medicine.push_back(qMakePair("Tradmadol", 80.5));
           ui->comboBox_3->addItem("Tradmadol");
           Medicine.push_back(qMakePair("Oxycone", 18.00));
           ui->comboBox_3->addItem("Oxycone");
           // Antibiotics
           Medicine.push_back(qMakePair("Amoxicillin", 45.00));
           ui->comboBox_3->addItem("Amoxicillin");
           Medicine.push_back(qMakePair("Vancomycin", 55.00));
           ui->comboBox_3->addItem("Vancomycin");
           Medicine.push_back(qMakePair("Cephalexin", 102.5));
           ui->comboBox_3->addItem("Cephalexin");
           Medicine.push_back(qMakePair("Nitrofurantoin", 15.00));
           ui->comboBox_3->addItem("Nitrofurantoin");
           // Anticoagulants: reducing coagulation of blood
           Medicine.push_back(qMakePair("Apixaban", 85.0));
           ui->comboBox_3->addItem("Apixaban");
           Medicine.push_back(qMakePair("Enoxaparin", 150.0));
           ui->comboBox_3->addItem("Enoxaparin");
           Medicine.push_back(qMakePair("Heparin", 16.00));
           ui->comboBox_3->addItem("Heparin");
           Medicine.push_back(qMakePair("Funderparinex", 88.00));
           ui->comboBox_3->addItem("Funderparinex");
           // Antidepresseants
           Medicine.push_back(qMakePair("Citaloparm", 36.5));
           ui->comboBox_3->addItem("Citaloparm");
           Medicine.push_back(qMakePair("Fluoxetine", 168.0));
           ui->comboBox_3->addItem("Fluoxetine");
           Medicine.push_back(qMakePair("Amitriptyline", 450.0));
           ui->comboBox_3->addItem("Amitriptyline");
           Medicine.push_back(qMakePair("Trazodone", 360.00));
           ui->comboBox_3->addItem("Trazodone");
           // Antiemetics: treat vomiting and nausea
           Medicine.push_back(qMakePair("Cyclizine", 30.00));
           ui->comboBox_3->addItem("Cyclizine");
           Medicine.push_back(qMakePair("Ondansetron", 38.00));
           ui->comboBox_3->addItem("Ondansetron");
           Medicine.push_back(qMakePair("Metoclopramide", 39.00));
           ui->comboBox_3->addItem("Metoclopramide");
           Medicine.push_back(qMakePair("Prochlorperzine", 49.00));
           ui->comboBox_3->addItem("Prochlorperzine");
           */
           //doctors data
           QFile p("D:/AUC/1st year/2nd semester - Spring 2022/CSCE110104 - Fundamentals of Computing II/Project/project/project/Salamtak/doctors.txt");
           if(!p.open(QFile::WriteOnly | QFile::Text)){
               QMessageBox::warning(this, "title", "sdasd");
           }
           else{
               QTextStream out(&p);
               for(int i = 0; i < ROWS; i++){
                   out << doctors[i][0] << " " << "," << " " << doctors[i][1] << " " << "," << " " << doctors[i][2] << " " << "," << " " << doctors[i][3] << " " << "," << " " << doctors[i][4] << " " << "," << " " << doctors[i][5] << '\n';
               }
               p.flush();
               p.close();
           }


           //read users data
           if(!inU.open(QFile::ReadOnly | QFile::Text)){
                   QMessageBox::warning(this, "title", "Sadsa");
               }
               else{
                   QTextStream a(&inU);
                   while(!a.atEnd())
                   {
                       QString line = a.readLine();
                       QStringList l = line.split(',');
                       if(l.size() == 0){
                           QMessageBox::warning(this, "title", "no input");
                       }
                       else if( l.size() == 7){
                           Patient p;
                           p.setName(l[0]);
                           p.setredeem(l[1].toInt());
                           p.setAge(l[2].toInt());
                           p.setEmail(l[3]);
                           p.setUsername(l[4]);
                           p.setPassword(l[5]);
                           p.setPhone(l[6]);
                           patients.push_back(p);
                       }
                       else{
                           Patient p;
                           p.setName(l[0]);
                           p.setredeem(l[1].toInt());
                           p.setAge(l[2].toInt());
                           p.setEmail(l[3]);
                           p.setUsername(l[4]);
                           p.setPassword(l[5]);
                           p.setPhone(l[6]);
                           p.setInsuranceno(l[7].toInt());
                           p.setInCompany(l[8]);
                           patients.push_back(p);
                       }
                   }
           }

           //medicine
           QFile med("D:/AUC/1st year/2nd semester - Spring 2022/CSCE110104 - Fundamentals of Computing II/Project/project/project/Salamtak/medicine.txt");
               if(!med.open(QFile::ReadOnly | QFile::Text)){
                   QMessageBox::warning(this, "title", "medicine");
               }
               else{
                   QTextStream out(&med);
                   while(!out.atEnd()){
                       QString line = out.readLine();
                       QStringList sl = line.split(',');
                       QPair<QString,float> med;
                       med.first = sl[0];
                       med.second = sl[1].toFloat();
                       Medicine.push_back(med);
                       ui->comboBox_3->addItem(med.first);
                  }
               }

}

Salamtak::~Salamtak()
{
    //medicine
    /*
    QFile med("D:/AUC/1st year/2nd semester - Spring 2022/CSCE110104 - Fundamentals of Computing II/Project/project/project/Salamtak/medicine.txt");
    if(!med.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "medicine");
    }
    else{
        QTextStream out(&med);
        for(int i = 0; i < Medicine.size(); i++){
            out << Medicine[i].first << "," << Medicine[i].second;
       }
    }
    */
    //rooms

    QFile rooms("D:/AUC/1st year/2nd semester - Spring 2022/CSCE110104 - Fundamentals of Computing II/Project/project/project/Salamtak/rooms.txt");
    if(!rooms.open(QFile::WriteOnly | QFile::Truncate)){
        QMessageBox::warning(this, "title", "rooms");
    }
    else{
        QTextStream out(&rooms);
        for(int i = 0; i < roomsVec.size();i++){
            out << roomsVec[i].getId() << "," << roomsVec[i].getSpec() << ","
                << roomsVec[i].getDate().toString("MM-dd-yyyy") << "," << roomsVec[i].getTime().toString() << ",";
            if(roomsVec[i].getStatus())
                out << "Available\n";
            else
                out << "Reserved\n";
        }
    }

    //users
    QFile inU("D:/AUC/1st year/2nd semester - Spring 2022/CSCE110104 - Fundamentals of Computing II/Project/project/project/Salamtak/users.txt");
    if(!inU.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "Sadsa");
    }
    else{
        QTextStream out(&inU);
        for(int i = 0; i < patients.size(); i++){
            out << patients[i].getName() << "," << patients[i].getredeem() << "," <<
                   patients[i].getage() << "," << patients[i].getemail() << "," <<
                   patients[i].getusername() << "," << patients[i].getpassword() <<
                   "," << patients[i].getphone();
            if(patients[i].getInsurance() != 0)
                out << "," << patients[i].getInsurance() << "," << patients[i].getInsurance_Company() << '\n';
            else
                out << '\n';
        }
    }
    delete ui;
}


// sorting rating

void Salamtak::sort_rate(int n)
{
    QString temp;
    for(int j=0;j<COLUMNS;j++)
    {
        for(int i=0;i<ROWS-1;i++)
        {
            if(doctors[i][n].toDouble() < doctors[i+1][n].toDouble())
            {
                for(int k=0;k<6;k++)
                {
                    swap(doctors[i+1][k], doctors[i][k]);
                    /*temp = doctors[i+1][k];
                    doctors[i+1][k] = doctors[i][k];
                    doctors[i][k] = temp;*/
                }
            }
       }
    }
}


// sorting time

void Salamtak::sort_time(int n)
{
    QString temp;
    for(int j=0;j<COLUMNS;j++)
    {
        for(int i=0;i<ROWS-1;i++)
        {
            QString time1 = doctors[i][n];
            QString h1 = time1[0];
            QString h2 = time1[1];
            QString hour1 = h1 + h2;
            QString m1 = time1[3];
            QString m2 = time1[4];
            QString minute1 = m1 + m2;

            QString time2 = doctors[i+1][n];
            QString h3 = time2[0];
            QString h4 = time2[1];
            QString hour2 = h3 + h4;
            QString m3 = time2[3];
            QString m4 = time2[4];
            QString minute2 = m3 + m4;


            if(hour1.toInt() > hour2.toInt())
            {
                for(int k=0;k<6;k++)
                {
                    swap(doctors[i+1][k], doctors[i][k]);
                    /*temp = doctors[i+1][k];
                    doctors[i+1][k] = doctors[i][k];
                    doctors[i][k] = temp;*/
                }
            }
            else if(hour1.toInt() == hour2.toInt())
            {
                if(minute1.toInt() > minute2.toInt())
                {
                    for(int k=0;k<6;k++)
                    {
                        swap(doctors[i+1][k], doctors[i][k]);
                        /*temp = doctors[i+1][k];
                        doctors[i+1][k] = doctors[i][k];
                        doctors[i][k] = temp;*/
                    }
                }
            }
        }
    }
}


// Sign Up Page

void Salamtak::on_lineEdit_2_textEdited(const QString &arg1)
{
    for(int i = 0; i < patients.size(); i++){
        if(patients[i].getusername() == arg1){
            ui->registerstatus->setText("Username already exists");
            return;
        }
    }
    ui->registerstatus->setText("Registration Status");
}


void Salamtak::on_lineEdit_3_textEdited(const QString &arg1)
{
    QString pass = arg1;
    bool upper(false), lower(false), digit(false);
    if(pass.size() < 10){
        ui->registerstatus->setText("Minimum password count is 10 character");
        return;
    }
    for(int i = 0; i < pass.size(); i++){
        if(pass[i].isLetter())
            if(pass[i].isUpper())
                upper = true;
            else
                lower = true;
        else if(pass[i].isDigit())
            digit = true;
    }
    if(!(upper && lower && digit)){
        ui->registerstatus->setText("Password should contain uppercase and lowercase letters as well as numbers");
    }
    else
        ui->registerstatus->setText("Registration Status");
}


void Salamtak::on_lineEdit_4_textEdited(const QString &arg1)
{
    if(arg1 != ui->lineEdit_3->text()){
        ui->registerstatus->setText("Password does not match");
    }
    else
        ui->registerstatus->setText("Registration Status");
}


void Salamtak::on_lineEdit_5_textEdited(const QString &arg1)
{
    QString Age = arg1;
    int a = Age.toInt();
    if(a < 5 || a > 100)
        ui->registerstatus->setText("Valid age is between 5 and 100");
    else
        ui->registerstatus->setText("Registration Status");
}


void Salamtak::on_lineEdit_6_textEdited(const QString &arg1)
{
    QString email = arg1;
    bool andCheck = false;
    for(int i = 0; i < email.size(); i++){
        if(email[i] == '@'){
            andCheck = true;
            break;
        }
    }
    if(!andCheck)
        ui->registerstatus->setText("Please enter a valid email");
    else
        ui->registerstatus->setText("Registration Status");

}


void Salamtak::on_lineEdit_7_textEdited(const QString &arg1)
{
    QString phone = arg1;
    if(phone.size() != 11)
        ui->registerstatus->setText("A valid phone number has 11 digits");
    else
        ui->registerstatus->setText("Registration Status");
}



void Salamtak::on_pushButton_3_clicked()
{
    if(ui->lineEdit->text().isEmpty()){
        ui->registerstatus->setText("Name field is empty, please make sure to fill out all the required information");
        return;
    }
    if(ui->lineEdit_2->text().isEmpty()){
        ui->registerstatus->setText("Username field is empty, please make sure to fill out all the required information");
        return;
    }
    if(ui->lineEdit_3->text().isEmpty()){
        ui->registerstatus->setText("Password field is empty, please make sure to fill out all the required information");
        return;
    }
    if(ui->lineEdit_4->text().isEmpty()){
        ui->registerstatus->setText("Please confirm password");
        return;
    }
    if(ui->lineEdit_5->text().isEmpty()){
        ui->registerstatus->setText("Age field is empty, please make sure to fill out all the required information");
        return;
    }
    if(ui->lineEdit_6->text().isEmpty()){
        ui->registerstatus->setText("Email field is empty, please make sure to fill out all the required information");
        return;
    }
    if(ui->lineEdit_7->text().isEmpty()){
        ui->registerstatus->setText("Phone field is empty, please make sure to fill out all the required information");
        return;
    }
    QString arg1 = ui->lineEdit->text();
    for(int i = 0; i < arg1.size(); i++){
        if(arg1[i].isDigit()){
            ui->registerstatus->setText("Name cannot contain numbers");
            return;
        }
    }
    for(int i = 0; i < patients.size(); i++){
        if(patients[i].getusername() == ui->lineEdit_2->text()){
            ui->registerstatus->setText("Username already exists");
            return;
        }
    }
    QString pass = ui->lineEdit_3->text();
    bool upper(false), lower(false), digit(false);
    if(pass.size() < 10){
        ui->registerstatus->setText("Minimum password count is 10 character");
        return;
    }
    for(int i = 0; i < pass.size(); i++){
        if(pass[i].isLetter())
            if(pass[i].isUpper())
                upper = true;
            else
                lower = true;
        else if(pass[i].isDigit())
            digit = true;
    }
    if(!(upper && lower && digit)){
        ui->registerstatus->setText("Password should contain uppercase and lowercase letters as well as numbers");
        return;
    }
    if(ui->lineEdit_4->text() != ui->lineEdit_3->text()){
        ui->registerstatus->setText("Password does not match");
        return;
    }
    QString Age = ui->lineEdit_5->text();
    int a = Age.toInt();
    if(a < 5 || a > 100){
        ui->registerstatus->setText("Valid age is between 5 and 100");
        return;
    }
    QString email = ui->lineEdit_6->text();
    bool andCheck = false;
    for(int i = 0; i < email.size(); i++){
        if(email[i] == '@'){
            andCheck = true;
            break;
        }
    }
    if(!andCheck){
        ui->registerstatus->setText("Please enter a valid email");
        return;
    }
    QString phone = ui->lineEdit_7->text();
    if(phone.size() != 11){
        ui->registerstatus->setText("A valid phone number has 11 digits");
        return;
    }
    /*
    bool check = false;
    for(int i = 0; i < companies.size(); i++){
        if(ui->lineEdit_8->text() == companies[i]){
            check = true;
        }
    }
    if(!check){
        ui->registerstatus->setText("Company does not exist");
        return;
    }
            ui->registerstatus->setText("Registered Successfully");
            Patient p;
            p.setName(ui->lineEdit->text());
            p.setUsername(ui->lineEdit_2->text());
            p.setPassword(ui->lineEdit_3->text());
            p.setAge(ui->lineEdit_5->text().toInt());
            p.setEmail(ui->lineEdit_6->text());
            p.setPhone(ui->lineEdit_7->text());
            p.setredeem(1000);
            if(!ui->lineEdit_9->text().isEmpty()){
                p.setInsuranceno(ui->lineEdit_9->text().toInt());
            }
            if(!ui->lineEdit_8->text().isEmpty()){
                p.setInCompany(ui->lineEdit_8->text());
            }
            patients.push_back(p);
            ui->lineEdit->setText("");
            ui->lineEdit_2->setText("");
            ui->lineEdit_3->setText("");
            ui->lineEdit_4->setText("");
            ui->lineEdit_5->setText("");
            ui->lineEdit_6->setText("");
            ui->lineEdit_7->setText("");
            ui->lineEdit_8->setText("");
            ui->lineEdit_9->setText("");
            ui->registerstatus->setText("Registration Status");
            ui->stackedWidget->setCurrentIndex(1);
            */
    bool check = false;
        if(!ui->lineEdit_8->text().isEmpty()){
            for(int i = 0; i < companies.size(); i++){
                if(ui->lineEdit_8->text() == companies[i]){
                check = true;
              }
               }
            if(!check){
                ui->registerstatus->setText("Company does not exist");
                 return;
                }

        }
        if(!ui->lineEdit_9->text().isEmpty())
        {
            if(ui->lineEdit_8->text().isEmpty())
            {
                ui->registerstatus->setText("Enter the company first");
                return;
            }
        }
        ui->registerstatus->setText("Registered Successfully");
        Patient p;
        p.setName(ui->lineEdit->text());
        p.setUsername(ui->lineEdit_2->text());
        p.setPassword(ui->lineEdit_3->text());
        p.setAge(ui->lineEdit_5->text().toInt());
        p.setEmail(ui->lineEdit_6->text());
        p.setPhone(ui->lineEdit_7->text());
        p.setredeem(1000);
        if(!ui->lineEdit_9->text().isEmpty() && !ui->lineEdit_8->text().isEmpty()){
            p.setInsuranceno(ui->lineEdit_9->text().toInt());
        }
        else
        {
            p.setInsuranceno(0);
        }
        if(!ui->lineEdit_8->text().isEmpty()){
            p.setInCompany(ui->lineEdit_8->text());
        }
        patients.push_back(p);
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_5->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_7->setText("");
        ui->lineEdit_8->setText("");
        ui->lineEdit_9->setText("");
        ui->registerstatus->setText("Registration Status");
        ui->stackedWidget->setCurrentIndex(1);

 }


void Salamtak::on_pushButton_clicked()
{
        QFile inU("D:/AUC/1st year/2nd semester - Spring 2022/CSCE110104 - Fundamentals of Computing II/Project/project/project/Salamtak/users.txt");
        if(!inU.open(QFile::WriteOnly | QFile::Text)){
            QMessageBox::warning(this, "title", "Sadsa");
        }
        else{
            QTextStream out(&inU);
            for(int i = 0; i < patients.size(); i++){
                out << patients[i].getName() << "," << patients[i].getredeem() << "," <<
                       patients[i].getage() << "," << patients[i].getemail() << "," <<
                       patients[i].getusername() << "," << patients[i].getpassword() <<
                       "," << patients[i].getphone();
                if(patients[i].getInsurance() != 0)
                    out << "," << patients[i].getInsurance() << "," << patients[i].getInsurance_Company() << '\n';
                else
                    out << '\n';
            }
        }
    exit(0);
}


void Salamtak::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->registerstatus->setText("Registration Status");
}


void Salamtak::on_lineEdit_8_textEdited(const QString &arg1)
{
    for(int i = 0; i < companies.size(); i++){
        if(arg1 == companies[i]){
            ui->registerstatus->setText("Registration Status");
            return;
        }
    }
    ui->registerstatus->setText("Company does not exist");
}


void Salamtak::on_lineEdit_textEdited(const QString &arg1)
{
    for(int i = 0; i < arg1.size(); i++){
        if(arg1[i].isDigit()){
            ui->registerstatus->setText("Name cannot contain numbers");
        }
        else
            ui->registerstatus->setText("Registration Status");
    }
}

// Sign in Page

void Salamtak::on_pushButton_2_clicked()
{
    QFile inU("D:/AUC/1st year/2nd semester - Spring 2022/CSCE110104 - Fundamentals of Computing II/Project/project/project/Salamtak/users.txt");
    if(!inU.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "Sadsa");
    }
    else{
        QTextStream out(&inU);
        for(int i = 0; i < patients.size(); i++){
            out << patients[i].getName() << "," << patients[i].getredeem() << "," <<
                   patients[i].getage() << "," << patients[i].getemail() << "," <<
                   patients[i].getusername() << "," << patients[i].getpassword() <<
                   "," << patients[i].getphone();
            if(patients[i].getInsurance() != 0)
                out << "," << patients[i].getInsurance() << "," << patients[i].getInsurance_Company() << '\n';
            else
                out << '\n';
        }
    }
    exit(0);
}


void Salamtak::on_pushButton_4_clicked()
{
    QString currentPassword;
    if(ui->lineEdit_11->text().isEmpty()){
        ui->logstatus->setText("Please enter your username");
        return;
    }
    if(ui->lineEdit_10->text().isEmpty()){
        ui->logstatus->setText("Please enter your password");
        return;
    }
    c = false;
    for(int i = 0; i < patients.size();i++){
        if(patients[i].getusername() == ui->lineEdit_11->text()){
            currentUser = patients[i].getusername();
            currentPassword = patients[i].getpassword();
            currentIndex = i;
            ui->logstatus->setText("Login Status");
            c = true;
            break;
        }
    }
    if(!c){
        ui->logstatus->setText("Username does not exist");
        return;
    }

        if(currentPassword == ui->lineEdit_10->text()){
              ui->logstatus->setText("Login Status");
         }
         else{
              ui->logstatus->setText("Password for this username is incorrect");
              return;
           }

    currentUser = ui->lineEdit_11->text();
    ui->stackedWidget->setCurrentIndex(2);
    ui->lineEdit_11->setText("");
    ui->lineEdit_10->setText("");
}


void Salamtak::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Salamtak::on_lineEdit_11_textEdited(const QString &arg1)
{

}


void Salamtak::on_lineEdit_10_textEdited(const QString &arg1)
{
}


// Path

void Salamtak::on_pushButton_27_clicked()
{
    Graph citymap;
    ui->label_16->setText("");
    ui->label_36->setText(currentUser);
    if(ui->lineEdit_12->text().isEmpty()){
        ui->lineEdit_12->setText("Please enter your building");
    }
    else{
        for(int i = 0; i < ui->lineEdit_12->text().size(); i++){
            if(!ui->lineEdit_12->text()[i].isDigit()){
                ui->lineEdit_12->setText("Only numbers are accepted");
                return;
            }
        }
        if(ui->lineEdit_12->text().toInt() > 20 || ui->lineEdit_12->text().toInt() < 1){
            ui->lineEdit_12->setText("Building does not exist in this city");
            return;
        }
        int building = ui->lineEdit_12->text().toInt();
        int distance = citymap.Dijkestra(building);
        ui->distancelabel->setText(QString::number(distance*100));
        QStack<int> path;
        int* parentpath= citymap.parent;
        int start = 8;
        while(parentpath[start] != 0){
            path.push(parentpath[start]);
            start = parentpath[start];
        }
        ui->label_16->setText(QString::number(path.top()));
        path.pop();
        while(!path.isEmpty()){
            ui->label_16->setText(ui->label_16->text() + "->" + QString::number(path.top()));
            path.pop();
        }
        ui->label_16->setText(ui->label_16->text() + "->" + "Hosptial");  
    }
}

void Salamtak::on_stackedWidget_currentChanged(int arg1)
{
    ui->label_36->setText(currentUser);
}

void Salamtak::on_view_profile_clicked()
{
    for(int i=0;i<patients.size();i++)
    {
        if(currentUser == patients[i].getusername())
        {
            ui->name_edit->setText(patients[i].getName());
            ui->pass_edit->setText(patients[i].getpassword());
            ui->confpass_edit->setText(patients[i].getpassword());
            ui->age_edit->setText(QString::number(patients[i].getage()));
            ui->email_edit->setText(patients[i].getemail());
            ui->phone_edit->setText(patients[i].getphone());
            if(patients[i].getInsurance() != 0)
            {
                ui->inscomp_edit->setText(patients[i].getInsurance_Company());
                ui->insnum_edit->setText(QString::number(patients[i].getInsurance()));
            }
            ui->profile_name->setText("Welcome " + patients[i].getusername());
            ui->label_16->setText("");
            ui->lineEdit_12->setText("");
            ui->distancelabel->setText("");
            ui->stackedWidget->setCurrentIndex(3);
        }
    }
}
void Salamtak::on_pushButton_28_clicked()
{
    ui->distancelabel->setText("");
    ui->label_16->setText("");
    ui->lineEdit_12->setText("");
    ui->stackedWidget->setCurrentIndex(4);
    ui->label_64->setText(currentUser);
}

// Services Page

void Salamtak::on_view_profile2_clicked()
{
    for(int i=0;i<patients.size();i++)
    {
        if(currentUser == patients[i].getusername())
        {
            ui->name_edit->setText(patients[i].getName());
            ui->pass_edit->setText(patients[i].getpassword());
            ui->confpass_edit->setText(patients[i].getpassword());
            ui->age_edit->setText(QString::number(patients[i].getage()));
            ui->email_edit->setText(patients[i].getemail());
            ui->phone_edit->setText(patients[i].getphone());
            if(patients[i].getInsurance() != 0)
            {
                ui->inscomp_edit->setText(patients[i].getInsurance_Company());
                ui->insnum_edit->setText(QString::number(patients[i].getInsurance()));
             }
            ui->profile_name->setText("Welcome " + patients[i].getusername());

            ui->stackedWidget->setCurrentIndex(3);
        }
    }
}

void Salamtak::on_outpatient_clinic_clicked()
{
    out_patient_choice = true;
    ui->stackedWidget->setCurrentIndex(5);
    ui->label_65->setText("");
}

void Salamtak::on_room_clicked()
{
    if(out_patient_choice)
        ui->stackedWidget->setCurrentIndex(11);
    else
        ui->label_65->setText("Please refer to a doctor first");
}

void Salamtak::on_emergency_visit_clicked()
{
    fromClinic = false;
    fromRoom = false;
    ui->label_65->setText("");
    ui->stackedWidget->setCurrentIndex(15);
}

void Salamtak::on_buy_medicine_clicked()
{
    fromClinic = false;
    fromRoom = false;
    ui->label_65->setText("");
    ui->stackedWidget->setCurrentIndex(10);
}

void Salamtak::on_log_out_clicked()
{
    ui->label_65->setText("");
    ui->stackedWidget->setCurrentIndex(1);
    c = false;
    ui->logstatus->setText("Login Status: You have been logged out.");
}
void Salamtak::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

// Outpatient Clinic Page

void Salamtak::on_proceed_clicked()
{
    for(int i=0;i<ROWS;i++)
    {
        QString chosen = ui->doc_choice->text();
        if(chosen == doctors[i][0])
        {
            ui->label_53->setText("Amount to pay: " + doctors[i][4]);
            ui->stackedWidget->setCurrentIndex(6);
        }
        ui->not_found->setText("Invalid input! Please try again");
    }
}

void Salamtak::on_search_outclinic_clicked()
{
    ui->doc_list->clear();
    ui->doc_list2->clear();
    QDate d;
    d = ui->dateEdit->date();
    int  q= d.year();
    QString q1=QString::number(q);
    int q2=d.month();
    QString q3=QString::number(q2);
    int q4=d.day();
    QString q5=QString::number(q4);
    QString date = q3 + "/" + q5 + "/" + q1;


    sort_time(2);
    int count = 0;
    for(int i = 0; i < ROWS; i++)
    {
        if(doctors[i][1] == ui->specialization->currentText())
        {
            if(doctors[i][3] == date)
            {
                count++;
                ui->doc_list2->setText(ui->doc_list2->toPlainText() + "Doctor#" + QString::number(count) + "\n" + doctors[i][0] + "\n" + "Price: " + doctors[i][4] + "\n" + "Time: " + doctors[i][2] + "\n" + "Rating: " + doctors[i][5] + "\n\n");
            }
        }
    }


    sort_rate(5);
    count = 0;
    for(int i = 0; i < ROWS; i++)
    {
        if(doctors[i][1] == ui->specialization->currentText())
        {
            if(doctors[i][3] == date)
            {
                count++;
                ui->doc_list->setText(ui->doc_list->toPlainText() + "Doctor#" + QString::number(count) + "\n" + doctors[i][0] + "\n" + "Price: " + doctors[i][4] + "\n" + "Time: " + doctors[i][2] + "\n" + "Rating: " + doctors[i][5] + "\n\n");
            }
        }
    }
}


// Profile Page

void Salamtak::on_name_edit_textEdited(const QString &arg1)
{
    for(int i = 0; i < arg1.size(); i++)
    {
        if(arg1[i].isDigit()){
            ui->registerstatus_2->setText("Name cannot contain numbers");
        }
        else
            ui->registerstatus_2->setText("Registration Status");
    }
}

void Salamtak::on_pass_edit_textEdited(const QString &arg1)
{
    QString pass = arg1;
    bool upper(false), lower(false), digit(false);
    if(pass.size() < 10){
        ui->registerstatus_2->setText("Minimum password count is 10 character");
        return;
    }
    for(int i = 0; i < pass.size(); i++){
        if(pass[i].isLetter())
            if(pass[i].isUpper())
                upper = true;
            else
                lower = true;
        else if(pass[i].isDigit())
            digit = true;
    }
    if(!(upper && lower && digit)){
        ui->registerstatus_2->setText("Password should contain uppercase and lowercase letters as well as numbers");
    }
    else
        ui->registerstatus_2->setText("Registration Status");
}

void Salamtak::on_confpass_edit_textEdited(const QString &arg1)
{
    if(arg1 != ui->pass_edit->text()){
        ui->registerstatus_2->setText("Password does not match");
    }
    else
        ui->registerstatus_2->setText("Registration Status");
}

void Salamtak::on_age_edit_textEdited(const QString &arg1)
{
    QString Age = arg1;
    int a = Age.toInt();
    if(a < 5 || a > 100)
        ui->registerstatus_2->setText("Valid age is between 5 and 100");
    else
        ui->registerstatus_2->setText("Registration Status");
}

void Salamtak::on_email_edit_textEdited(const QString &arg1)
{
    QString email = arg1;
    bool andCheck = false;
    for(int i = 0; i < email.size(); i++){
        if(email[i] == '@'){
            andCheck = true;
            break;
        }
    }
    if(!andCheck)
        ui->registerstatus_2->setText("Please enter a valid email");
    else
        ui->registerstatus_2->setText("Registration Status");
}

void Salamtak::on_phone_edit_textEdited(const QString &arg1)
{
    QString phone = arg1;
    if(phone.size() != 11)
        ui->registerstatus_2->setText("A valid phone number has 11 digits");
    else
        ui->registerstatus_2->setText("Registration Status");
}

void Salamtak::on_save_edit_clicked()
{
    if(ui->name_edit->text().isEmpty()){
        ui->registerstatus_2->setText("Name field is empty, please make sure to fill out all the required information");
        return;
    }
    if(ui->pass_edit->text().isEmpty()){
        ui->registerstatus_2->setText("Password field is empty, please make sure to fill out all the required information");
        return;
    }
    if(ui->confpass_edit->text().isEmpty()){
        ui->registerstatus_2->setText("Please confirm password");
        return;
    }
    if(ui->age_edit->text().isEmpty()){
        ui->registerstatus_2->setText("Age field is empty, please make sure to fill out all the required information");
        return;
    }
    if(ui->email_edit->text().isEmpty()){
        ui->registerstatus_2->setText("Email field is empty, please make sure to fill out all the required information");
        return;
    }
    if(ui->phone_edit->text().isEmpty()){
        ui->registerstatus_2->setText("Phone field is empty, please make sure to fill out all the required information");
        return;
    }
    QString arg1 = ui->name_edit->text();
    for(int i = 0; i < arg1.size(); i++){
        if(arg1[i].isDigit()){
            ui->registerstatus_2->setText("Name cannot contain numbers");
            return;
        }
    }
    QString pass = ui->pass_edit->text();
    bool upper(false), lower(false), digit(false);
    if(pass.size() < 10){
        ui->registerstatus_2->setText("Minimum password count is 10 character");
        return;
    }
    for(int i = 0; i < pass.size(); i++){
        if(pass[i].isLetter())
            if(pass[i].isUpper())
                upper = true;
            else
                lower = true;
        else if(pass[i].isDigit())
            digit = true;
    }
    if(!(upper && lower && digit)){
        ui->registerstatus_2->setText("Password should contain uppercase and lowercase letters as well as numbers");
        return;
    }
    if(ui->confpass_edit->text() != ui->pass_edit->text())
    {
        ui->registerstatus_2->setText("Password does not match");
        return;
    }
    QString Age = ui->age_edit->text();
    int a = Age.toInt();
    if(a < 5 || a > 100){
        ui->registerstatus_2->setText("Valid age is between 5 and 100");
        return;
    }
    QString email = ui->email_edit->text();
    bool andCheck = false;
    for(int i = 0; i < email.size(); i++){
        if(email[i] == '@'){
            andCheck = true;
            break;
        }
    }
    if(!andCheck){
        ui->registerstatus_2->setText("Please enter a valid email");
        return;
    }
    QString phone = ui->phone_edit->text();
    if(phone.size() != 11){
        ui->registerstatus_2->setText("A valid phone number has 11 digits");
        return;
    }
    bool check = false;
    for(int i = 0; i < companies.size(); i++){
        if(ui->inscomp_edit->text() == companies[i]){
            check = true;
        }
    }
    if(!ui->inscomp_edit->text().isEmpty())
    {
    if(!check){
        ui->registerstatus_2->setText("Company does not exist");
        return;
    }
    }
            ui->registerstatus_2->setText("Your data has been saved");
            for(int i=0;i<patients.size();i++)
            {
                if(patients[i].getusername() == currentUser)
                {
                    patients[i].setName(ui->name_edit->text());
                    patients[i].setPassword(ui->pass_edit->text());
                    patients[i].setAge(ui->age_edit->text().toInt());
                    patients[i].setEmail(ui->email_edit->text());
                    patients[i].setPhone(ui->phone_edit->text());
                    if(!ui->insnum_edit->text().isEmpty()){
                        patients[i].setInsuranceno(ui->insnum_edit->text().toInt());
                    }
                    if(!ui->inscomp_edit->text().isEmpty()){
                        patients[i].setInCompany(ui->inscomp_edit->text());
                    }
                    ui->stackedWidget->setCurrentIndex(1);
                }
            }
    ui->name_edit->setText("");
    ui->pass_edit->setText("");
    ui->age_edit->setText("");
    ui->email_edit->setText("");
    ui->phone_edit->setText("");
    ui->insnum_edit->setText("");
    ui->inscomp_edit->setText("");
    ui->confpass_edit->setText("");
    ui->registerstatus_2->setText("");
}


void Salamtak::on_cancel_clicked()
{
    QFile inU("D:/AUC/1st year/2nd semester - Spring 2022/CSCE110104 - Fundamentals of Computing II/Project/project/project/Salamtak/users.txt");
    if(!inU.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "Sadsa");
    }
    else{
        QTextStream out(&inU);
        for(int i = 0; i < patients.size(); i++){
            out << patients[i].getName() << "," << patients[i].getredeem() << "," <<
                   patients[i].getage() << "," << patients[i].getemail() << "," <<
                   patients[i].getusername() << "," << patients[i].getpassword() <<
                   "," << patients[i].getphone();
            if(patients[i].getInsurance() != 0)
                out << "," << patients[i].getInsurance() << "," << patients[i].getInsurance_Company() << '\n';
            else
                out << '\n';
        }
    }
    ui->name_edit->setText("");
    ui->pass_edit->setText("");
    ui->age_edit->setText("");
    ui->email_edit->setText("");
    ui->phone_edit->setText("");
    ui->insnum_edit->setText("");
    ui->inscomp_edit->setText("");
    ui->confpass_edit->setText("");
    ui->registerstatus_2->setText("");
    exit(0);
}


// Pharmacy

void Salamtak::on_comboBox_3_textHighlighted(const QString &arg1)
{
    for(int i = 0; i < Medicine.size(); i++){
        if(Medicine[i].first == arg1){
            ui->label_50->setText(QString::number(Medicine[i].second));
        }
    }
}


void Salamtak::on_pushButton_25_clicked()
{
    if(ui->label_50->text() == "")
        ui->label_66->setText("Please choose your medicine first.");
    else
    {
        ui->stackedWidget->setCurrentIndex(8);
        ui->label_66->setText("");
    }}


void Salamtak::on_pushButton_24_clicked()
{
    if(ui->label_50->text() == "")
        ui->label_66->setText("Please choose your medicine first.");
    else
    {
        ui->label_47->setText(QString::number(patients[currentIndex].getredeem()));
        ui->stackedWidget->setCurrentIndex(7);
        ui->label_66->setText("");
    }
}


//Rooms
void Salamtak::setRooms() { // we have ten rooms for each specialization, each operating on a different time and a different date.
    /*
    int j = 10; // We start operating 10 AM, we have one room for each hour from 10 AM to 8 PM
    int k = 20; // our dates in the rooms are from 20th of may to 30th of may 2022

    for (int i = 1; i<= 90; i++) {
        QTime tTemp(j, 0, 0, 0);
        QDate dTemp(2022, 5, k);
        j = ((j+1)%10)+10;   // to fill the time repeatedly from 10:00 to 20:00
        k = ((k+1)%10)+20;
        room rTemp; // we now create a room
        rTemp.setDate(dTemp);
        rTemp.setTime(tTemp);
        rTemp.setId(i);
        if (i < 11)
            rTemp.setSpec("Dermatologists");
        else if (i < 21)
            rTemp.setSpec("Surgery");
        else if (i < 31)
            rTemp.setSpec("Neurology");
        else if (i < 41)
            rTemp.setSpec("Cardiology");
        else if (i < 51)
            rTemp.setSpec("Therapy");
        else if (i < 61)
            rTemp.setSpec("Dentistry");
        else if (i < 71)
            rTemp.setSpec("Ophthalmology");
        else if (i < 81)
            rTemp.setSpec("pulmonology");
        else if (i < 91)
            rTemp.setSpec("Otolaryngology");
        roomsVec.push_back(rTemp); // pushed to our vector of rooms.
    }
    */

    QFile rooms("D:/AUC/1st year/2nd semester - Spring 2022/CSCE110104 - Fundamentals of Computing II/Project/project/project/Salamtak/rooms.txt");
        if(!rooms.open(QFile::ReadOnly | QFile::Text)){
            QMessageBox::warning(this, "title", "rooms");
        }
        else{
            QTextStream in(&rooms);
            while(!in.atEnd()){
                QString line = in.readLine();
                QStringList sl = line.split(',');
                room r;
                r.setId(sl[0].toInt());
                r.setSpec(sl[1]);
                QDate d = QDate::fromString(sl[2], "MM-dd-yyyy");
                r.setDate(d);
                QTime t = QTime::fromString(sl[3]);
                r.setTime(t);
                if(sl[4] == "Available")
                    r.setStatus(true);
                else
                    r.setStatus(false);
                roomsVec.push_back(r);
            }
        }
}

void Salamtak::on_pushButton_43_clicked()
{
    ui->room_list->clear();
    for(int i = 0; i < roomsVec.size(); i++)
    {
       if(roomsVec[i].getStatus())
       {
        if(roomsVec[i].getSpec() == ui->rSpecialization->currentText())
        {
            if(roomsVec[i].getDate() == ui->rDateEdit->date())
            {
                    QString x = roomsVec[i].getDate().toString("MM-dd-yyyy");
                    ui->room_list->addItem("Room with ID#" + QString::number(roomsVec[i].getId()) + "\n" + "Time: " + roomsVec[i].getTime().toString() + "\n" + "Date: " + x + "\n" );
            }
        }
        }
     }
    if (ui->room_list->count() == 0)
        ui->room_list->addItem("There's no room that matches with your input!");
}


void Salamtak::on_rChoiceProceed_clicked()
{


    if(ui->rChoice->text().toInt() >= 1 && ui->rChoice->text().toInt() <= 90)
    {
        int ID = ui->rChoice->text().toInt();
        if (roomsVec[ID-1].getStatus() == false)
            ui->choiceError->setText("Room is already reserved");
        else
        {
            ui->reDate->setText("Date: " + roomsVec[ID].getDate().toString("MM-dd-yyyy"));
            ui->reRoom->setText("Room ID: " + QString::number(roomsVec[ID].getId()));
            ui->reUser->setText("Username: " + currentUser);
            roomID = ui->rChoice->text();
            ui->stackedWidget->setCurrentIndex(12);
        }
    }
    else
    {
        ui->choiceError->setText("Please enter a valid room ID");
    }


}



void Salamtak::on_updatePrice_clicked()
{
    if (ui->rType->currentText()== "Standard")
            ui->rPayment->setText(QString::number(ui->nights->text().toInt()*100));
    else if (ui->rType->currentText()== "Suite")
            ui->rPayment->setText(QString::number(ui->nights->text().toInt()*200));
    else if (ui->rType->currentText()== "VIP")
            ui->rPayment->setText(QString::number(ui->nights->text().toInt()*300));


}


void Salamtak::on_rPaymentProceed_clicked()
{
    ui->reAmount->setText(ui->rPayment->text());
    ui->reRoom->setText("Room Type: " + ui->rType->currentText());
    ui->reNights->setText("Nights: " + ui->nights->text());
    ui->rePay->setText("Payment method: Insurance ");
    if (ui->lineEdit_148->text()=="") {
        ui->prcdErr->setText("Please enter a valid number");
    }
    else if(ui->nights->text()=="") {
        ui->prcdErr->setText("Please enter the number of nights");
    }
    else
    {
        ui->nights->setText("");
        ui->lineEdit_148->setText("");
        ui->stackedWidget->setCurrentIndex(13);
    }
}

//Emergency
void Salamtak::on_eSearch_clicked()
{
    for (int i = 0; i < emergencyVec.size(); i++) {
        if (ui->eDate->date() == emergencyVec[i].getDate())
            if (emergencyVec[i].isAvailable())
            {
                ui->eStatus->setText("Availability: Available");
                return;
             }
            else
                ui->eStatus->setText("Availability: Not Availble! Try another day");
        else
            ui->eStatus->setText("Availability: Not Availble! Try another day");


    }
}


void Salamtak::on_pushButton_265_clicked()
{
    for (int i = 0; i < emergencyVec.size(); i++) {
        if (ui->eDate->date() == emergencyVec[i].getDate())
            if (emergencyVec[i].isAvailable())
            {
                ui->label_47->setText(QString::number(patients[currentIndex].getredeem()));
                ui->stackedWidget->setCurrentIndex(7);
            }
            else
                ui->eStatus->setText("Cannot proceed, try another day");
        else
            ui->eStatus->setText("Cannot proceed, try another day");
}
}

void Salamtak::on_pushButton_211_clicked()
{
        for (int i = 0; i < emergencyVec.size(); i++) {
            if (ui->eDate->date() == emergencyVec[i].getDate())
                if (emergencyVec[i].isAvailable())
                {
                    ui->stackedWidget->setCurrentIndex(8);
                }
                else
                    ui->eStatus->setText("Cannot proceed, try another day");
            else
                ui->eStatus->setText("Cannot proceed, try another day");
}
}

void Salamtak::setEmergency() {
    int k = 1;
    for (int i = 0; i < 30; i++) {
        QDate dTemp(2022,5,k);
        emergency eTemp;
        eTemp.setDate(dTemp);
        eTemp.setStatus(true);
        k++;
        emergencyVec.push_back(eTemp);
    }
}

//Rating
void Salamtak::on_pushButton_264_clicked()
{
    for(int i = 0; i < ROWS; i++){
        if(ui->RDcomboBox->currentText() == doctors[i][0]){
            int rating = ui->comboBox_4->currentText().toInt();
            doctors[i][5] += QString::number((rating + doctors[i][5].toInt()/ 2)); // calculate the new average rating for the doctor 'i'
        }
    }
    servicesRating = (ui->comboBox_5->currentText().toInt() + servicesRating) / 2;
    ui->stackedWidget->setCurrentIndex(4); // return to the services page
}



//Card and wallet and envoice stuff
void Salamtak::on_pushButton_23_clicked()
{
    if(ui->lineEdit_13->text() == "")
    {
        ui->label_67->setText("Please enter the approval number");
    }
    else
    {
        ui->label_67->setText("");
        ui->lineEdit_13->setText("");
        ui->stackedWidget->setCurrentIndex(9);
        ui->label_25->setText("Doctor name: " + ui->doc_choice->text());
        for(int i = 0; i < 21; i++)
            if(ui->doc_choice->text() == doctors[i][0])
            {
                ui->label_30->setText(doctors[i][4]);
                ui->label_27->setText("Date: " + doctors[i][3] + " at " + doctors[i][2]);
            }
        ui->label_28->setText("Username: " + currentUser);
        ui->label_29->setText("Payement method: insured");
    }
}


void Salamtak::on_pushButton_12_clicked()
{
    patients[currentIndex].setredeem(patients[currentIndex].getredeem() +  ui->label_30->text().toInt()*0.02);
    ui->label_47->setText(QString::number(patients[currentIndex].getredeem()));
    ui->stackedWidget->setCurrentIndex(4);
    fromRoom = false;
    fromClinic = false;
    ui->label_28->setText("Username: ");
    ui->label_29->setText("Payement method: ");
    ui->label_25->setText("Doctor name: ");
    ui->label_30->setText("");
    ui->label_27->setText("Date: ");
    ui->label_69->setText("");
    ui->not_found->setText("");
    ui->doc_choice->setText("");
    ui->doc_list->setText("");
    ui->doc_list2->setText("");

}


void Salamtak::on_pushButton_11_clicked()
{
    fromRoom = false;
    fromClinic = false;
    ui->stackedWidget->setCurrentIndex(4);
    ui->label_28->setText("Username: ");
    ui->label_29->setText("Payement method: ");
    ui->label_25->setText("Doctor name: ");
    ui->label_30->setText("");
    ui->label_27->setText("Date: ");
    ui->not_found->setText("");
    ui->doc_choice->setText("");
    ui->doc_list->setText("");
    ui->doc_list2->setText("");
}


void Salamtak::on_pushButton_21_clicked()
{
    fromClinic = true;
    ui->label_47->setText(QString::number(patients[currentIndex].getredeem()));
    ui->stackedWidget->setCurrentIndex(7);
}


void Salamtak::on_pushButton_22_clicked()
{
    fromClinic = true;
    ui->stackedWidget->setCurrentIndex(8);
}

void Salamtak::on_pushButton_261_clicked()
{
    if(ui->nights->text() == "")
        ui->prcdErr_2->setText("Please enter the no. of nights");
    else
    {
    ui->label_47->setText(QString::number(patients[currentIndex].getredeem()));
    fromRoom = true;
    ui->stackedWidget->setCurrentIndex(7);
    }
}

void Salamtak::on_pushButton_210_clicked()
{
    if(ui->nights->text() == "")
        ui->prcdErr_2->setText("Please enter the no. of nights");
    else
    {
    fromRoom = true;
    ui->stackedWidget->setCurrentIndex(8);
    }
}

void Salamtak::on_pushButton_10_clicked()
{
    if(ui->lineEdit_15->text() == "")
        ui->label_48->setText("Please enter your security code.");
    else if(ui->lineEdit_16->text() == "")
        ui->label_48->setText("Please enter your expiry date.");
    else if(ui->lineEdit_17->text() == "")
        ui->label_48->setText("Please enter the cardholder name.");
    else if(ui->lineEdit_18->text() == "")
        ui->label_48->setText("Please enter your card number.");
    else if(fromClinic)
    {
        ui->lineEdit_15->setText("");
        ui->lineEdit_16->setText("");
        ui->lineEdit_17->setText("");
        ui->lineEdit_18->setText("");
        ui->stackedWidget->setCurrentIndex(9);
        ui->label_25->setText("Doctor name: " + ui->doc_choice->text());
        for(int i = 0; i < 21; i++)
            if(ui->doc_choice->text() == doctors[i][0])
            {
                ui->label_30->setText(doctors[i][4]);
                ui->label_27->setText("Date: " + doctors[i][3] + " at " + doctors[i][2]);
            }
        ui->label_28->setText("Username: " + currentUser);
        ui->label_29->setText("Payement method: card");
    }
    else if(fromRoom)
    {
        ui->lineEdit_15->setText("");
        ui->lineEdit_16->setText("");
        ui->lineEdit_17->setText("");
        ui->lineEdit_18->setText("");
        ui->stackedWidget->setCurrentIndex(13);
        ui->reAmount->setText(ui->rPayment->text());
        ui->reRoom->setText("Room Type: " + ui->rType->currentText());
        ui->reNights->setText("Nights: " + ui->nights->text());
        ui->rePay->setText("Payment method: card");
    }

    else                                           //for emergency visit and pharmacy cases
    {
        ui->lineEdit_15->setText("");
        ui->lineEdit_16->setText("");
        ui->lineEdit_17->setText("");
        ui->lineEdit_18->setText("");
        ui->eStatus->setText("Availability status");
        ui->stackedWidget->setCurrentIndex(4);
    }
}




void Salamtak::on_pushButton_14_clicked()
{
    if(ui->lineEdit_14->text() == "")
        ui->label_31->setText("Please enter your receipt number");
    else if(fromClinic)
    {
        ui->stackedWidget->setCurrentIndex(9);
        ui->lineEdit_14->setText("");
        ui->label_25->setText("Doctor name: " + ui->doc_choice->text());
        for(int i = 0; i < 21; i++)
            if(ui->doc_choice->text() == doctors[i][0])
            {
                ui->label_30->setText(doctors[i][4]);
                ui->label_27->setText("Date: " + doctors[i][3] + " at " + doctors[i][2]);
            }
        ui->label_28->setText("Username: " + currentUser);
        ui->label_29->setText("Payement method: wallet");
    }
    else if(fromRoom)
    {
        ui->lineEdit_14->setText("");
        ui->stackedWidget->setCurrentIndex(13);
        ui->reAmount->setText(ui->rPayment->text());
        ui->reRoom->setText("Room Type: " + ui->rType->currentText());
        ui->reNights->setText("Nights: " + ui->nights->text());
        ui->rePay->setText("Payment method: wallet");
    }

    else                                           //for emergency visit and pharmacy cases
    {
        ui->stackedWidget->setCurrentIndex(4);
        ui->lineEdit_14->setText("");
        ui->eStatus->setText("Availability status");
    }
}


void Salamtak::on_pushButton_263_clicked()
{
    roomsVec[roomID.toInt() -1].setStatus(false);
    patients[currentIndex].setredeem(patients[currentIndex].getredeem() +  ui->reAmount->text().toInt()*0.02);
    ui->label_47->setText(QString::number(patients[currentIndex].getredeem()));
    ui->stackedWidget->setCurrentIndex(4);
    ui->reAmount->setText("");
    ui->reDate->setText("Date: ");
    ui->reUser->setText("Username: ");
    ui->reRoom->setText("Room Type: ");
    ui->reNights->setText("Nights: ");
    ui->rePay->setText("Payment method: ");
    ui->re_label->setText("");
    ui->rChoice->setText("");
    ui->choiceError->setText("");
    ui->prcdErr_2->setText("");
    ui->prcdErr->setText("");
    ui->rPayment->setText("");
    ui->nights->setText("");
    ui->room_list->clear();
}


void Salamtak::on_pushButton_262_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->reAmount->setText("Amount to pay: ");
    ui->reDate->setText("Date: ");
    ui->reUser->setText("Username: ");
    ui->reRoom->setText("Room Type: ");
    ui->reNights->setText("Nights: ");
    ui->rePay->setText("Payment method: ");
    ui->re_label->setText("");
    ui->rChoice->setText("");
    ui->choiceError->setText("");
    ui->prcdErr_2->setText("");
    ui->prcdErr->setText("");
    ui->rPayment->setText("");
    ui->nights->setText("");
    ui->room_list->clear();
}


void Salamtak::on_Redeem1_clicked()
{
    if(patients[currentIndex].getredeem() < 1000)
        ui->label_69->setText("You don't have enough redeem points");
    else if(ui->label_30->text().toInt() < 100)
        ui->label_69->setText("The amount to pay is less than 100");
    else
    {
        patients[currentIndex].setredeem(patients[currentIndex].getredeem() - 1000);
        ui->label_47->setText(QString::number(patients[currentIndex].getredeem()));
        ui->label_30->setText(QString::number(ui->label_30->text().toInt() - 100));
    }
}


void Salamtak::on_redeem2_clicked()
{
    if(patients[currentIndex].getredeem() < 1000)
        ui->re_label->setText("You don't have enough redeem points");
    else if(ui->reAmount->text().toInt() < 100)
        ui->re_label->setText("The amount to pay is less than 100");
    else
    {
        patients[currentIndex].setredeem(patients[currentIndex].getredeem() - 1000);
        ui->label_47->setText(QString::number(patients[currentIndex].getredeem()));
        ui->reAmount->setText(QString::number(ui->reAmount->text().toInt() - 100));
    }
}

void Salamtak::on_Services_cancel_clicked()
{
    QFile inU("D:/AUC/1st year/2nd semester - Spring 2022/CSCE110104 - Fundamentals of Computing II/Project/project/project/Salamtak/users.txt");
    if(!inU.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "title", "Sadsa");
    }
    else{
        QTextStream out(&inU);
        for(int i = 0; i < patients.size(); i++){
            out << patients[i].getName() << "," << patients[i].getredeem() << "," <<
                   patients[i].getage() << "," << patients[i].getemail() << "," <<
                   patients[i].getusername() << "," << patients[i].getpassword() <<
                   "," << patients[i].getphone();
            if(patients[i].getInsurance() != 0)
                out << "," << patients[i].getInsurance() << "," << patients[i].getInsurance_Company() << '\n';
            else
                out << '\n';
        }
    }
    exit(0);
}

