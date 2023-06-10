#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    void paintEvent(QPainter painter);
    void paintEvent(QPaintEvent*);
    void timerEvent(QTimerEvent* event);
    void make_prev_screen();
    void mirror_screen(QImage& image);
    void setup();
    void draw(QPainter& painter);
    ~Form();

private:
    Ui::Form *ui;
};

#endif // FORM_H
