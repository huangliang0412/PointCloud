/*
#ifndef SELECTCLOUD_H_
#define SELECTCLOUD_H_

#include <QDialog>
#include <QLabel>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

class CloudRangeDialog : public QDialog {
    Q_OBJECT
    
public:
    explicit CloudRangeDialog(QWidget *parent = 0){
        //int i = 0;

        label_x1.setText("X: ");
        label_y1.setText("Y: ");
        label_z1.setText("Z: ");

        label_x2.setText("--");
        label_y2.setText("--");
        label_z2.setText("--");

        QHBoxLayout line1;
        line1.addWidget(&label_x1);
        line1.addWidget(&X1);
        line1.addWidget(&label_x2);
        line1.addWidget(&X2);
        setLayout(&line1);

    }
    ~CloudRangeDialog(){}
    //void getData();
    
//private:
    //float x_low, x_high;
    //float y_low, y_high;
    //float z_low, z_high;

    QLabel label_x1, label_x2;
    QLabel label_y1, label_y2;
    QLabel label_z1, label_z2;
    
    QLineEdit X1, X2, Y1, Y2, Z1, Z2;
    
    QDialogButtonBox buttonbox;

    
};

CloudRangeDialog::CloudRangeDialog(QWidget *parent) :
    QDialog(parent) {
    

    
}


#endif
*/

#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
class MyDialog : public QDialog {
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0){}
    ~MyDialog() {}
};
#endif // MYDIALOG_H

