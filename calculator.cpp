#include "calculator.h"
#include "ui_calculator.h"
#include <QFont>

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    pastNumber = 0;
    currentNumber = ui->lcd->value();
    state = '\0';
    point = false;
    in = false;
    count = 0;

    connect(ui->button0, SIGNAL(clicked()),
            this, SLOT(push0()));
    connect(ui->button1, SIGNAL(clicked()),
            this, SLOT(push1()));
    connect(ui->button2, SIGNAL(clicked()),
            this, SLOT(push2()));
    connect(ui->button3, SIGNAL(clicked()),
            this, SLOT(push3()));
    connect(ui->button4, SIGNAL(clicked()),
            this, SLOT(push4()));
    connect(ui->button5, SIGNAL(clicked()),
            this, SLOT(push5()));
    connect(ui->button6, SIGNAL(clicked()),
            this, SLOT(push6()));
    connect(ui->button7, SIGNAL(clicked()),
            this, SLOT(push7()));
    connect(ui->button8, SIGNAL(clicked()),
            this, SLOT(push8()));
    connect(ui->button9, SIGNAL(clicked()),
            this, SLOT(push9()));
    connect(ui->buttonDot, SIGNAL(clicked()),
            this, SLOT(pushpoint()));
    connect(ui->buttonCE, SIGNAL(clicked()),
            this, SLOT(ce()));
    connect(ui->buttonC, SIGNAL(clicked()),
            this, SLOT(c()));
    connect(ui->buttonPlus, SIGNAL(clicked()),
            this, SLOT(pushPlus()));
    connect(ui->buttonSub, SIGNAL(clicked()),
            this, SLOT(pushSub()));
    connect(ui->buttonTimes, SIGNAL(clicked()),
            this, SLOT(pushTimes()));
    connect(ui->buttonDiv, SIGNAL(clicked()),
            this, SLOT(pushDiv()));
    connect(ui->buttonEqual, SIGNAL(clicked()),
            this, SLOT(pushEqual()));

    QFont font = ui->button0->font();
    font.setPointSize(40);
    ui->button0->setFont(font);
    ui->button1->setFont(font);
    ui->button2->setFont(font);
    ui->button3->setFont(font);
    ui->button4->setFont(font);
    ui->button5->setFont(font);
    ui->button6->setFont(font);
    ui->button7->setFont(font);
    ui->button8->setFont(font);
    ui->button9->setFont(font);
    ui->buttonC->setFont(font);
    ui->buttonCE->setFont(font);
    ui->buttonEqual->setFont(font);
    ui->buttonDiv->setFont(font);
    ui->buttonTimes->setFont(font);
    ui->buttonPlus->setFont(font);
    ui->buttonSub->setFont(font);
    ui->buttonDot->setFont(font);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::pushEqual()
{
    if (isOperator(state))
    {
        switch (state)
        {
            case('/'):
            {
                 currentNumber = pastNumber / currentNumber;
                 break;
            }
            case('*'):
            {
                currentNumber = pastNumber * currentNumber;
                break;
            }
            case('+'):
            {
                currentNumber = pastNumber + currentNumber;
                break;
            }
            case('-'):
            {
                currentNumber = pastNumber - currentNumber;
                break;
            }
        }
        update();
        state = '\0';
        in = false;
    }
}

void Calculator::pushDiv()
{
    pushEqual();
    state = '/';
    in = false;
}

void Calculator::pushTimes()
{
    pushEqual();
    state = '*';
    in = false;
}

void Calculator::pushSub()
{
    pushEqual();
    state = '-';
    in = false;
}

void Calculator::pushPlus()
{
    pushEqual();
    state = '+';
    in = false;
}

void Calculator::update()
{
    ui->lcd->display(currentNumber);
}

void Calculator::ce()
{
    currentNumber = 0;
    point = false;
    count = 0;
    update();
}
void Calculator::c()
{
    ce();
    state = '\0';
    in = false;
    pastNumber = 0;
}

bool Calculator::isOperator(char opt)
{
    if (opt == '+' || opt == '*' || opt == '-' || opt == '/') return true;
    return false;
}

void Calculator::push(int number)
{
    if (state == '\0' && !in)
        c();
    else
    if (!in)
    {
        pastNumber = currentNumber;
        ce();
    }


    if (!point)
        currentNumber = currentNumber * 10 + number;
    else
    {
        count++;
        double tempNumber = number;
        int tempcount = count;
        while (tempcount)
        {
            tempNumber /= 10;
            tempcount--;
        }
        currentNumber += tempNumber;
    }
    update();
    in = true;
}

void Calculator::push0()
{
    push(0);
}

void Calculator::push1()
{
    push(1);
}

void Calculator::push2()
{
    push(2);
}

void Calculator::push3()
{
    push(3);
}

void Calculator::push4()
{
    push(4);
}

void Calculator::push5()
{
    push(5);
}

void Calculator::push6()
{
    push(6);
}

void Calculator::push7()
{
    push(7);
}

void Calculator::push8()
{
    push(8);
}

void Calculator::push9()
{
    push(9);
}



void Calculator::pushpoint()
{
    point = true;
}
