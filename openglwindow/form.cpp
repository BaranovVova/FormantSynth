#include <QWidget>
#include <QPainter>
#include <math.h>
#include "form.h"
#include "ui_form.h"

static QImage prev_screen;

int x_pos;
int y_pos;
float rotation = 0;
float zoom = .5;
int translate_delta;
float rotate_delta = 2*M_PI / (pow(2, 8));
float zoom_delta = 0.01;


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setup();
    startTimer(100);

}

void Form::timerEvent(QTimerEvent* event)
{
    //repaint();
    setup();
}

void Form::mirror_screen(QImage& image)
{
    image.invertPixels();
    for(int row = 0; row < image.height(); row++)
    {
        for(int col = 0; col < image.width() / 2; col++)
        {
            QRgb pixel = image.pixel(col, row);
            image.setPixel((image.width() - col - 1), row,  pixel);
            //pixels[(width - col - 1) + (width * row)] = pixels[col + (width * row)];
        }
    }
}


void Form::draw(QPainter& painter)
{
    //background(255);
    prev_screen.fill(Qt::white);

    //key_update();

    //prev_screen.resize((int)(geometry().width * zoom), (int)(geometry().height * zoom));
    //prev_screen.
    painter.translate(x_pos, y_pos);
    QTransform transform;
    transform.rotate(rotation);
    painter.setTransform(transform);
    //image(prev_screen,  -prev_screen.width / 2, -prev_screen.height / 2);

    mirror_screen(prev_screen);

    make_prev_screen();

}

void Form::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    int width = size().width() - 3;
    int height = size().height() - 5;

    painter.fillRect(0, 0, width, height, QColor(220,220,220));
    painter.drawText(10, 10, "Machine " + QString::number(1));
}


//------------------------ code from fractals
// https://gist.github.com/nimaid/fbddeba0819fb8cfa0142060a0bbbfd5




void Form::make_prev_screen()
{
    QRect* rectangle = new QRect();
    *rectangle = geometry();
    QPixmap pixmap(rectangle->size());
    this->render(&pixmap, QPoint(), QRegion(*rectangle));
    pixmap.save("screenshot.png");
    prev_screen = pixmap.toImage();
    prev_screen.invertPixels();
    delete rectangle;
    //prev_screen = get();
    //prev_screen.filter(INVERT);
}
//boolean[] current_keys = new boolean[9];
void Form::setup()
{
    static int r = 1;

    if(r == 1)
    {
//    size(1920, 1080);
    setGeometry(0,0,1920,1080);
    //background(0);
    //frameRate(60);
    QPainter painter(this);
    draw(painter);
    make_prev_screen();

    x_pos = (int)(geometry().width() / 2) - (int)((geometry().width() * zoom) / 4);
    y_pos = (int)(geometry().height() / 2);
    translate_delta = (int)(geometry().height() / (pow(2, 8)));
    r = 1000;

    }
}





Form::~Form()
{
    delete ui;
}
