#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private slots:
    void push0();
    void push1();
    void push2();
    void push3();
    void push4();
    void push5();
    void push6();
    void push7();
    void push8();
    void push9();
    void pushpoint();
    void pushPlus();
    void pushSub();
    void pushTimes();
    void pushDiv();
    void pushEqual();
    void ce();
    void c();

private:
    void push(int number);
    void update();
    bool isOperator(char opt);
    Ui::Calculator *ui;
    double currentNumber;
    double pastNumber;
    char state;
    bool in;
    bool point;
    int count;
};

#endif // CALCULATOR_H
