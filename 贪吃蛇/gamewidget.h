#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include<QIcon>
#include<QPalette>
#include<QBrush>
#include<QPixmap>
#include<QPushButton>
#include<QMessageBox>
#include<QPaintEvent>
#include<QPainter>
#include<QLabel>
#include<QTimer>
#include<QTime>
#include<ctime>
#include<QButtonGroup>
#include<QKeyEvent>
#include<QStyle>
#define longnumber 16//宏定义游戏界面方格的多少
#define widthnumber 14

class Gamewidget : public QWidget
{
    Q_OBJECT

public:
    explicit Gamewidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent*);
    QPushButton *upPush;
    QPushButton *downPush;
    QPushButton *leftPush;
    QPushButton *rightPush;

    QPushButton *StartPush1;
    QPushButton *StartPush2;
    QPushButton *StartPush3;
    QPushButton *StartPush4;
    QPushButton *StartPush5;

    QPushButton *ExitPush;
    QLabel *ScoreLabel;
    QLabel *LevelLabel;
    QLabel *ScoreLabelNumber;
    QLabel *LevelLabelNumber;

    QTimer *Timer;

    int n;
    int snake[200][2];//创建了一个包含蛇的身体坐标的数组
    int snake1[200][2];//这个数组只是上一个坐标的复制，在最后一步（咬到身体或者撞到边缘）需要将它的身体坐标还原
    static  int m_setDiretion;//对方向的更改的存储
    QButtonGroup *buttonGroup;//上下左右四个键构成一个按钮组，根据它们的返回值改变方向的值
    int foodx;//食物的X坐标
    int foody;//食物的Y坐标
    int bodycount;
    bool Nobite;
    int Score;
    int Difficulty;//难度级别，时间变化
private:
    QPalette *palette;

signals:


public slots:
    void M_timeout();
    void M_startPush1();
    void M_startPush2();
    void M_startPush3();
    void M_startPush4();
    void M_startPush5();

    void M_setDiretion(int index);
    void M_exitPush();
    void M_pausePush1();
    void M_pausePush2();
    void M_pausePush3();
    void M_pausePush4();
    void M_pausePush5();

    void M_CheckGameOver();
};

#endif // GAMEWIDGET_H
