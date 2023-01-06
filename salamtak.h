#ifndef SALAMTAK_H
#define SALAMTAK_H
#include "patient.h"
#include <QVector>
#include <QStack>
#include <QFile>
#include <QMessageBox>
#include "graph.h"
#include "room.h"
#include "emergency.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class Salamtak; }
QT_END_NAMESPACE

class Salamtak : public QMainWindow
{
    Q_OBJECT
    QVector<Patient> patients;
    QVector<QString> companies{"AlHelal", "Al Nour", "CiB", "HSBC", "Kareem"};
    QString currentUser;
    //check if patient goes to doctor first
    bool out_patient_choice = false;
    bool fromRoom = false;
    bool fromClinic = false;
    //login status
    bool c = false;
    QVector<QPair<QString, float>> Medicine;
    QVector<emergency> emergencyVec;
    QVector<room> roomsVec;
    float servicesRating;
    int redeemPoints;
    int currentIndex;
    QString roomID;
public:
    Salamtak(QWidget *parent = nullptr);
    ~Salamtak();
    static const int ROWS=21, COLUMNS=6;
    void setRooms();
    void setEmergency();
    QString doctors[ROWS][COLUMNS] =
    {
      {"Adham", "Dermatologists", "15:30", "1/1/2023", "200", "4.0"},
      {"Youssef", "Dermatologists", "15:00", "1/1/2023", "300", "5.0"},
      {"Mostafa", "Dermatologists", "13:30", "1/1/2023", "200", "6.4"},
      {"Zeyad", "Dermatologists", "11:30", "1/1/2023", "350", "7.5"},
      {"Ahmed", "Surgery", "17:00", "1/5/2023", "300", "6.0"},
      {"Yousri", "Surgery", "16:00", "1/5/2023", "250", "5.0"},
      {"Ismail", "Surgery", "16:30", "1/5/2023", "400", "1.0"},
      {"Islam", "Neurology", "10:00", "1/6/2023", "600", "7.0"},
      {"Samy", "Neurology", "12:00", "1/6/2023", "400", "6.0"},
      {"Mohanad", "Cardiology", "15:30", "2/1/2023", "500", "5.0"},
      {"Tarek", "Cardiology", "13:30", "2/1/2023", "350", "6.5"},
      {"Gamal", "Therapy", "11:30", "1/1/2023", "400", "8.0"},
      {"Fekry", "Therapy", "10:30", "1/1/2023", "400", "6.5"},
      {"Moaz", "Dentistry", "14:30", "1/1/2023", "350", "8.0"},
      {"Mohy", "Dentistry", "16:30", "1/1/2023", "500", "5.5"},
      {"Mahmoud", "Ophthalmology", "15:30", "1/6/2023", "700", "5.5"},
      {"Badr", "Ophthalmology", "10:30", "1/6/2023", "1000", "7.5"},
      {"Mohamed", "pulmonology", "10:00", "1/5/2023", "250", "5.5"},
      {"Mark", "pulmonology", "11:30", "1/5/2023", "400", "6.0"},
      {"Ibrahim", "Otolaryngology ", "17:00", "2/1/2023", "100", "6.5"},
      {"Ayman", "Otolaryngology ", "15:00", "2/1/2023", "200", "7.0"}
    };

private slots:


    void sort_rate(int n);

    void sort_time(int n);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_lineEdit_3_textEdited(const QString &arg1);

    void on_lineEdit_4_textEdited(const QString &arg1);

    void on_lineEdit_5_textEdited(const QString &arg1);

    void on_lineEdit_6_textEdited(const QString &arg1);

    void on_lineEdit_7_textEdited(const QString &arg1);

    void on_lineEdit_8_textEdited(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_16_clicked();

    void on_lineEdit_11_textEdited(const QString &arg1);

    void on_lineEdit_10_textEdited(const QString &arg1);
    void on_pushButton_27_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_view_profile_clicked();

    void on_view_profile2_clicked();

    void on_outpatient_clinic_clicked();

    void on_room_clicked();

    void on_emergency_visit_clicked();

    void on_buy_medicine_clicked();

    void on_log_out_clicked();

    void on_proceed_clicked();

    void on_search_outclinic_clicked();

    void on_name_edit_textEdited(const QString &arg1);

    void on_pass_edit_textEdited(const QString &arg1);

    void on_confpass_edit_textEdited(const QString &arg1);

    void on_age_edit_textEdited(const QString &arg1);

    void on_email_edit_textEdited(const QString &arg1);

    void on_phone_edit_textEdited(const QString &arg1);

    void on_save_edit_clicked();


    void on_cancel_clicked();

    void on_pushButton_28_clicked();

    void on_comboBox_3_textHighlighted(const QString &arg1);

    void on_pushButton_25_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_43_clicked();

    void on_rChoiceProceed_clicked();


    void on_updatePrice_clicked();

    void on_rPaymentProceed_clicked();

    void on_eSearch_clicked();

    void on_pushButton_265_clicked();

    void on_pushButton_211_clicked();

    void on_pushButton_264_clicked();
    void on_pushButton_17_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_261_clicked();

    void on_pushButton_210_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_263_clicked();

    void on_pushButton_262_clicked();

    void on_Redeem1_clicked();

    void on_redeem2_clicked();

    void on_Services_cancel_clicked();

private:
    Ui::Salamtak *ui;
};
#endif // SALAMTAK_H
