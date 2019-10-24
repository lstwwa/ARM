#include "gamewidget.h"
#include"widget.h"
#include<QDebug>


int Gamewidget::m_setDiretion=4;
Gamewidget::Gamewidget(QWidget *parent) : QWidget(parent)
{
    qsrand(time(NULL));//随机数的种子
    Score=0;
    Difficulty=1;
    this->setAutoFillBackground(true);//设置父窗口背景可被覆盖填充
    this->resize(800,480);
    this->setWindowTitle("G1950-季浩原");
    this->setWindowIcon(QIcon(":/Picture/img/WindowPicture.jpg"));

    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/Gamewindow/img/GameBack.jpg").scaled(this->size())));
    this->setPalette(palette);

    StartPush5=new QPushButton(this);
    StartPush4=new QPushButton(this);
    StartPush3=new QPushButton(this);
    StartPush2=new QPushButton(this);
    StartPush1=new QPushButton(this);

    upPush =new QPushButton(this);
    downPush=new QPushButton(this);
    leftPush=new QPushButton(this);
    rightPush=new QPushButton(this);

    ExitPush=new QPushButton(this);



    buttonGroup=new QButtonGroup(this);
    buttonGroup->addButton(upPush,1);
    buttonGroup->addButton(downPush,2);
    buttonGroup->addButton(leftPush,3);
    buttonGroup->addButton(rightPush,4);
    connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(M_setDiretion(int)));

    ScoreLabel=new QLabel(this);
    LevelLabel=new QLabel(this);
    ScoreLabel->setText("Score:");
    ScoreLabel->setGeometry(30,420,120,90);
    LevelLabel->setText("Level:");
    LevelLabel->setGeometry(310,420,120,90);



    upPush->setIconSize(QSize(45,90));
    upPush->setGeometry(638,200,45,90);
    upPush->setIcon(QIcon(":/new/Gamewindow/img/up.png"));
    upPush->setFlat(1);
    downPush->setIconSize(QSize(45,90));
    downPush->setGeometry(638,350,45,90);
    downPush->setIcon(QIcon(":/new/Gamewindow/img/down.png"));
    downPush->setFlat(1);
    leftPush->setIconSize(QSize(90,45));
    leftPush->setGeometry(540,298,90,45);
    leftPush->setIcon(QIcon(":/new/Gamewindow/img/left.png"));
    leftPush->setFlat(1);
    rightPush->setIconSize(QSize(90,45));
    rightPush->setGeometry(690,298,90,45);
    rightPush->setIcon(QIcon(":/new/Gamewindow/img/right.png"));
    rightPush->setFlat(1);
// ///////////////////////////////////////////////////////////////////
    StartPush1->setIconSize(QSize(90,45));
    StartPush1->setGeometry(550,20,90,45);
    StartPush1->setFlat(1);
    StartPush1->setIcon(QIcon(":/new/Gamewindow/img/L1.png"));

    StartPush2->setIconSize(QSize(90,45));
    StartPush2->setGeometry(550,80,90,45);
    StartPush2->setFlat(1);
    StartPush2->setIcon(QIcon(":/new/Gamewindow/img/L2.png"));

    StartPush3->setIconSize(QSize(90,45));
    StartPush3->setGeometry(550,140,90,45);
    StartPush3->setFlat(1);
    StartPush3->setIcon(QIcon(":/new/Gamewindow/img/L3.png"));

    StartPush4->setIconSize(QSize(90,45));
    StartPush4->setGeometry(680,20,90,45);
    StartPush4->setFlat(1);
    StartPush4->setIcon(QIcon(":/new/Gamewindow/img/L4.png"));

    StartPush5->setIconSize(QSize(90,45));
    StartPush5->setGeometry(680,80,90,45);
    StartPush5->setFlat(1);
    StartPush5->setIcon(QIcon(":/new/Gamewindow/img/L5.png"));
// ///////////////////////////////////////////////////////////////////

    ExitPush->setIconSize(QSize(90,45));
    ExitPush->setGeometry(680,140,90,45);
    ExitPush->setIcon(QIcon(":/Picture/img/Exit.png"));
    ExitPush->setFlat(1);

    ScoreLabel=new QLabel(this);
    LevelLabel=new QLabel(this);
    ScoreLabel->setText("Score:");
    ScoreLabel->setGeometry(30,420,120,90);
    LevelLabel->setText("Level:");
    LevelLabel->setGeometry(310,420,120,90);

    ScoreLabelNumber=new QLabel(this);
    LevelLabelNumber=new QLabel(this);
    ScoreLabelNumber->setText(QString::number(Score)+"分");
    ScoreLabelNumber->setGeometry(100,420,120,90);
    LevelLabelNumber->setText(QString::number(Difficulty)+"级");
    LevelLabelNumber->setGeometry(400,420,120,90);

    Timer=new QTimer(this);
    connect(Timer,SIGNAL(timeout()),this,SLOT(M_timeout()));

    connect(StartPush1,SIGNAL(clicked(bool)),this,SLOT(M_startPush1()));
    connect(StartPush2,SIGNAL(clicked(bool)),this,SLOT(M_startPush2()));
    connect(StartPush3,SIGNAL(clicked(bool)),this,SLOT(M_startPush3()));
    connect(StartPush4,SIGNAL(clicked(bool)),this,SLOT(M_startPush4()));
    connect(StartPush5,SIGNAL(clicked(bool)),this,SLOT(M_startPush5()));

    connect(ExitPush,SIGNAL(clicked(bool)),this,SLOT(M_exitPush()));



    snake[0][0]=(rand()%18+1)*30+30;
    snake[0][1]=(rand()%15+1)*30+30;
    m_setDiretion=(rand()%3)+1;     // //////////////////////////////////////////////////////
    foodx=(rand()%20)*30;
    foody=(rand()%15)*30;
    bodycount=1;  //包含蛇的头和尾巴
    Nobite=true;
    this->repaint();

}

void Gamewidget::paintEvent(QPaintEvent*)//绘图事件
{
    QPainter painter(this);
    if(0<=snake[0][0]&&snake[0][0]<=480&&0<=snake[0][1]&&snake[0][1]<=420&&Nobite)
    {
        qDebug()<<snake[0][0];
        for(int i=bodycount;i>0;i--)
        {
            if(i==bodycount)//画出尾巴部分
            {
                if(snake[i][0]==snake[i-1][0]&&snake[i][1]<snake[i-1][1])
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));
                }
                else  if(snake[i][0]==snake[i-1][0]&&snake[i][1]>snake[i-1][1])
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));
                }
                else  if(snake[i][0]<snake[i-1][0]&&snake[i][1]==snake[i-1][1])
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));
                }
                else  if(snake[i][0]>snake[i-1][0]&&snake[i][1]==snake[i-1][1])
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));
                }
            }
            else
            {
                if((snake[i][0]==snake[i-1][0]&& snake[i][1]<snake[i-1][1]&&snake[i+1][0]<snake[i][0]&&snake[i+1][1]==snake[i][1])||
                        ((snake[i][0]>snake[i-1][0])&& snake[i][1]==snake[i-1][1]&&snake[i+1][0]==snake[i][0]&&snake[i+1][1]>snake[i][1]))
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));
                }
                else if((snake[i][0]<snake[i-1][0]&& snake[i][1]==snake[i-1][1]&&snake[i+1][0]==snake[i][0]&&snake[i+1][1]>snake[i][1])||
                        (snake[i][0]==snake[i-1][0]&& snake[i][1]<snake[i-1][1]&&snake[i+1][0]>snake[i][0]&&snake[i+1][1]==snake[i][1]))
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));
                }
                else if((snake[i][0]>snake[i-1][0]&& snake[i][1]==snake[i-1][1]&&snake[i+1][0]==snake[i][0]&&snake[i+1][1]<snake[i][1])||
                        (snake[i][0]==snake[i-1][0]&& snake[i][1]>snake[i-1][1]&&snake[i+1][0]<snake[i][0]&&snake[i+1][1]==snake[i][1]))
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));
                }
                else if(((snake[i][0]==snake[i-1][0])&& snake[i][1]>snake[i-1][1]&&snake[i+1][0]>snake[i][0]&&snake[i+1][1]==snake[i][1])||
                        (snake[i][0]<snake[i-1][0]&& snake[i][1]==snake[i-1][1]&&snake[i+1][0]==snake[i][0]&&snake[i+1][1]<snake[i][1]))
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));
                }

                else if((snake[i][0]==snake[i-1][0]&&snake[i][0]==snake[i+1][0])&&((snake[i][1]<snake[i-1][1]&&snake[i+1][1]<snake[i][1])||
                                                                                   (snake[i][1]>snake[i-1][1]&&snake[i+1][1]>snake[i][1])))
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));

                }
                else if ((snake[i][1]==snake[i-1][1]&&snake[i][1]==snake[i+1][1])&&((snake[i][0]<snake[i-1][0]&&snake[i+1][0]<snake[i][0])||
                                                                                    (snake[i][0]>snake[i-1][0]&&snake[i+1][0]>snake[i][0])))
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));

                }
            }
        }
    }
    painter.drawImage(QRect(foodx,foody,30,30),QImage(":/new/Gamewindow/img/Apple.png"));

    painter.setPen(Qt::green);

    for(int i=0;i<=widthnumber;i++)
    {
        for(int j=0;j<=longnumber;j++)
        {
            painter.drawRect(QRect(30*j,30*i,30,30));
        }
    }
    switch (m_setDiretion)
    {
    case 1: painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));
        if(bodycount==1)  painter.drawImage(QRect(snake[0][0],snake[0][1]+30,30,30),QImage(":/new/Gamewindow/img/snake.png"));
        break;
    case 2: painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));
        if(bodycount==1) painter.drawImage(QRect(snake[0][0],snake[0][1]-30,30,30),QImage(":/new/Gamewindow/img/snake.png"));
        break;
    case 3: painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));
        if(bodycount==1) painter.drawImage(QRect(snake[0][0]+30,snake[0][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));
        break;
    case 4: painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));
        if(bodycount==1)  painter.drawImage(QRect(snake[0][0]-30,snake[0][1],30,30),QImage(":/new/Gamewindow/img/snake.png"));
        break;
    default:
        break;
    }
}

void Gamewidget::M_timeout()
{
    if(snake[0][0]==foodx&&snake[0][1]==foody)//当蛇头的坐标与食物坐标重合的时候，重新布置食物的位置
    {
        foodx=(rand()%14)*30;
        foody=(rand()%12)*30;
        bodycount++;  //蛇的身体加一
        Difficulty=bodycount/n+1;
        Score=Score+Difficulty;
        ScoreLabelNumber->setText(QString::number(bodycount-1)+"分");
        LevelLabelNumber->setText(QString::number(Difficulty)+"级");
        Timer->start(800-Difficulty>0? 800-Difficulty*80:80/(Difficulty-8));
    }
    memcpy(snake1,snake,sizeof(snake));
    for(int i=bodycount;i>0;i--)//将蛇身体的前一个坐标赋值给后一个坐标，实现蛇身体的连续出现
    {

        snake[i][0]=snake[i-1][0];
        snake[i][1]=snake[i-1][1];
    }
    QPainter painter(this);

    for(int i=bodycount;i>3;i--)
    {
        if(snake[0][0]==snake[i][0]&&snake[0][1]==snake[i][1])
        {
            Nobite=false;
        }
    }

    switch (m_setDiretion)
    {
    case 1: snake[0][1]=snake[0][1]-30,painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/new/Gamewindow/img/snake.png"))
                ;break;
    case 2: snake[0][1]=snake[0][1]+30,painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/new/Gamewindow/img/snake.png"))
                ; break;
    case 3: snake[0][0]=snake[0][0]-30,painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/new/Gamewindow/img/snake.png"))
                ; break;
    case 4: snake[0][0]=snake[0][0]+30,painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/new/Gamewindow/img/snake.png"))
                ;break;
    default:
        break;
    }
    if(0>snake[0][0]||snake[0][0]>480||0>snake[0][1]||snake[0][1]>420)
    {
        memcpy(snake,snake1,sizeof(snake));
        Nobite=false;
    }

    this->update();
    connect(Timer,SIGNAL(timeout()),this,SLOT(M_CheckGameOver()));
}

void Gamewidget::M_startPush1()//时间函数开始计时
{
    Timer->start(800);
    disconnect(StartPush1,SIGNAL(clicked(bool)),this,SLOT(M_startPush1()));
    StartPush1->setIcon(QIcon(":/Picture/img/Pause.png"));
    connect(StartPush1,SIGNAL(clicked(bool)),this,SLOT(M_pausePush1()));
    n=6;


}

void Gamewidget::M_startPush2()//时间函数开始计时
{
    Timer->start(800);
    disconnect(StartPush2,SIGNAL(clicked(bool)),this,SLOT(M_startPush2()));
    StartPush2->setIcon(QIcon(":/Picture/img/Pause.png"));
    connect(StartPush2,SIGNAL(clicked(bool)),this,SLOT(M_pausePush2()));
    n=5;

}

void Gamewidget::M_startPush3()//时间函数开始计时
{
    Timer->start(800);
    disconnect(StartPush3,SIGNAL(clicked(bool)),this,SLOT(M_startPush3()));
    StartPush3->setIcon(QIcon(":/Picture/img/Pause.png"));
    connect(StartPush3,SIGNAL(clicked(bool)),this,SLOT(M_pausePush3()));
    n=4;

}

void Gamewidget::M_startPush4()//时间函数开始计时
{
    Timer->start(800);
    disconnect(StartPush4,SIGNAL(clicked(bool)),this,SLOT(M_startPush4()));
    StartPush4->setIcon(QIcon(":/Picture/img/Pause.png"));
    connect(StartPush4,SIGNAL(clicked(bool)),this,SLOT(M_pausePush4()));
    n=3;

}

void Gamewidget::M_startPush5()//时间函数开始计时
{
    Timer->start(800);
    disconnect(StartPush5,SIGNAL(clicked(bool)),this,SLOT(M_startPush5()));
    StartPush5->setIcon(QIcon(":/Picture/img/Pause.png"));
    connect(StartPush5,SIGNAL(clicked(bool)),this,SLOT(M_pausePush5()));
    n=2;

}




void Gamewidget::M_pausePush1()//实现开始与暂停按钮的管理
{
    Timer->stop();
    connect(StartPush1,SIGNAL(clicked(bool)),this,SLOT(M_startPush1()));
    StartPush1->setIcon(QIcon(":/Picture/img/Start.png"));
    disconnect(StartPush1,SIGNAL(clicked(bool)),this,SLOT(M_pausePush1()));

}

void Gamewidget::M_pausePush2()//实现开始与暂停按钮的管理
{
    Timer->stop();
    connect(StartPush2,SIGNAL(clicked(bool)),this,SLOT(M_startPush2()));
    StartPush2->setIcon(QIcon(":/Picture/img/Start.png"));
    disconnect(StartPush2,SIGNAL(clicked(bool)),this,SLOT(M_pausePush2()));

}

void Gamewidget::M_pausePush3()//实现开始与暂停按钮的管理
{
    Timer->stop();
    connect(StartPush3,SIGNAL(clicked(bool)),this,SLOT(M_startPush3()));
    StartPush3->setIcon(QIcon(":/Picture/img/Start.png"));
    disconnect(StartPush3,SIGNAL(clicked(bool)),this,SLOT(M_pausePush3()));

}

void Gamewidget::M_pausePush4()//实现开始与暂停按钮的管理
{
    Timer->stop();
    connect(StartPush4,SIGNAL(clicked(bool)),this,SLOT(M_startPush4()));
    StartPush4->setIcon(QIcon(":/Picture/img/Start.png"));
    disconnect(StartPush4,SIGNAL(clicked(bool)),this,SLOT(M_pausePush4()));

}

void Gamewidget::M_pausePush5()//实现开始与暂停按钮的管理
{
    Timer->stop();
    connect(StartPush5,SIGNAL(clicked(bool)),this,SLOT(M_startPush5()));
    StartPush5->setIcon(QIcon(":/Picture/img/Start.png"));
    disconnect(StartPush5,SIGNAL(clicked(bool)),this,SLOT(M_pausePush5()));

}






void Gamewidget::M_setDiretion(int index)//接收按钮组的整数，确定方向
{
    switch (index)
    {
    case 1:if(m_setDiretion!=2)m_setDiretion=1;  break;
    case 2:if(m_setDiretion!=1)m_setDiretion=2;  break;
    case 3:if(m_setDiretion!=4)m_setDiretion=3;  break;
    case 4:if(m_setDiretion!=3)m_setDiretion=4;  break;
    default:                   break;
    }
}

void Gamewidget::M_exitPush()
{
    this->close();
    delete this;
}


void Gamewidget::M_CheckGameOver()//该部分原本在绘图事件函数中，但是由于在其中的时候程序总是意外关闭，故将其提出
{


    if(0>snake[0][0]||snake[0][0]>480||0>snake[0][1]||snake[0][1]>420||(!Nobite))
    {
        Nobite=true;//将其设置为真,进入绘图函数画出蛇的身体
        this->update();//调用绘图事件函数
        Timer->stop();
        if(QMessageBox::Yes==QMessageBox::information(this,"Tips：","完犊子了",QMessageBox::Yes))
        {
            this ->hide();
            delete this;
            return;
        }

    }

}







