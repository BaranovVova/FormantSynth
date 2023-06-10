#include <QPainter>
#include <QMouseEvent>
#include <QImage>
#include <math.h>
#include "pianowidget.h"

int PianoKey::counter = 0;

PianoWidget::PianoWidget(QWidget *parent) : SvgWidget(parent)
{
    //background = QImage("./images/piano_keys_and_notes.png");
    SvgLoad("./images/keyboard2.svg");
    LoadDom("./images/keyboard2.svg");
    create_table();
}

void PianoWidget::paintEvent(QPaintEvent* event)
{
    /*
    painter.fillRect(this->rect(),Qt::red);
    painter.drawPixmap(this->rect(),QPixmap::fromImage(background));
    */
    SvgWidget::paintEvent(event);

    QPainter painter(this);
    drawKeys(painter);


}

void PianoWidget::drawKeys(QPainter& painter)
{
    for(auto key=piano_keys.begin(); key!=piano_keys.end(); key++)
    {
        if( (*key).second.on )
        {
            QRectF rect = mapToViewbox((*key).second.rect, viewbox);
            painter.fillRect(rect,qRgba(255,0,0,40));
            QRectF rect2 = mapToViewbox((*key).second.rect2, viewbox);
            painter.fillRect(rect2,Qt::black);
            QRectF rect3 = mapToViewbox((*key).second.rect3, viewbox);
            painter.fillRect(rect3,Qt::black);

        }
    }
}

void PianoWidget::on_key_show(QString key_name)
{

    if( note2key.find(key_name)==note2key.end() )
        return;
    PianoKey k = note2key[key_name];
    piano_keys[k.code].on = true;
    repaint();
}

void PianoWidget::on_key_hide(QString key_name)
{
    if( note2key.find(key_name)==note2key.end() )
        return;
    PianoKey k = note2key[key_name];
    piano_keys[k.code].on = false;
    repaint();
}

void PianoWidget::on_key_press(int key_code)
{
    if( piano_keys.find(key_code)==piano_keys.end() )
        return;
    piano_keys[key_code].on = true;
    repaint();
}

void PianoWidget::on_key_release(int key_code)
{
   if( piano_keys.find(key_code)==piano_keys.end() )
       return;
   piano_keys[key_code].on = false;
   repaint();
}

void PianoWidget::create_table()
{
    //C4
    piano_keys['Q'] = PianoKey("C4", getRect("C4"),getRect("Db4"));
    piano_keys['W'] = PianoKey("D4", getRect("D4"),getRect("Eb4"),getRect("Db4"));
    piano_keys['E'] = PianoKey("E4", getRect("E4"),getRect("Eb4"),QRectF());
    piano_keys['R'] = PianoKey("F4", getRect("F4"),getRect("Gb4"));
    piano_keys['T'] = PianoKey("G4", getRect("G4"),getRect("Gb4"),getRect("Ab4"));
    piano_keys['Y'] = PianoKey("A4", getRect("A4"),getRect("Ab4"),getRect("Bb4"));
    piano_keys['U'] = PianoKey("B4", getRect("B4"),getRect("Bb4"));

    //C5
    piano_keys['I'] = PianoKey("C5", getRect("C5"),getRect("Db5"));
    piano_keys['O'] = PianoKey("D5", getRect("D5"),getRect("Eb5"),getRect("Db5"));
    piano_keys['P'] = PianoKey("E5", getRect("E5"),getRect("Eb5"));
    piano_keys['['] = PianoKey("F5", getRect("F5"),getRect("Gb5"));
    piano_keys[']'] = PianoKey("G5", getRect("G5"),getRect("Gb5"),getRect("Ab5"));
    piano_keys['A'] = PianoKey("A5", getRect("A5"),getRect("Ab5"),getRect("Bb5"));
    piano_keys['S'] = PianoKey("B5", getRect("B5"),getRect("Bb5"));

    //C6
    piano_keys['D'] = PianoKey("C6", getRect("C6"),getRect("Db6"));
    piano_keys['F'] = PianoKey("D6", getRect("D6"),getRect("Eb6"),getRect("Db6"));
    piano_keys['G'] = PianoKey("E6", getRect("E6"),getRect("Eb6"));
    piano_keys['H'] = PianoKey("F6", getRect("F6"),getRect("Gb6"));
    piano_keys['J'] = PianoKey("G6", getRect("G6"),getRect("Gb6"),getRect("Ab6"));
    piano_keys['K'] = PianoKey("A6", getRect("A6"),getRect("Ab6"),getRect("Bb6"));
    piano_keys['L'] = PianoKey("B6", getRect("B6"),getRect("Bb6"));

    //C7
    piano_keys['�'] = PianoKey("C7", getRect("C7"),getRect("Db7"));
    piano_keys['�'] = PianoKey("D7", getRect("D7"),getRect("Eb7"),getRect("Db7"));
    piano_keys['�'] = PianoKey("E7", getRect("E7"),getRect("Eb7"));
    piano_keys['�'] = PianoKey("F7", getRect("F7"),getRect("Gb7"));
    piano_keys['�'] = PianoKey("G7", getRect("G7"),getRect("Gb7"),getRect("Ab7"));
    piano_keys['�'] = PianoKey("A7", getRect("A7"),getRect("Ab7"),getRect("Bb7"));
    piano_keys['�'] = PianoKey("B7", getRect("B7"),getRect("Bb7"));

    //C8
    piano_keys['�'] = PianoKey("C8", getRect("C8"),getRect("Db8"));
    piano_keys['�'] = PianoKey("D8", getRect("D8"),getRect("Eb8"),getRect("Db8"));
    piano_keys['�'] = PianoKey("E8", getRect("E8"),getRect("Eb8"));
    piano_keys['�'] = PianoKey("F8", getRect("F8"),getRect("Gb8"));
    piano_keys['�'] = PianoKey("G8", getRect("G8"),getRect("Gb8"),getRect("Ab8"));
    piano_keys['�'] = PianoKey("A8", getRect("A8"),getRect("Ab8"),getRect("Bb8"));
    piano_keys['�'] = PianoKey("B8", getRect("B8"),getRect("Bb8"));

    //C9
    piano_keys['�'] = PianoKey("C9", getRect("C9"),getRect("Db9"));
    piano_keys['�'] = PianoKey("D9", getRect("D9"),getRect("Eb9"),getRect("Db9"));
    piano_keys['�'] = PianoKey("E9", getRect("E9"),getRect("Eb9"));
    piano_keys['�'] = PianoKey("F9", getRect("F9"),getRect("Gb9"));
    piano_keys['�'] = PianoKey("G9", getRect("G9"),getRect("Gb9"),getRect("Ab9"));
    piano_keys['�'] = PianoKey("A9", getRect("A9"),getRect("Ab9"),getRect("Bb9"));
    piano_keys['�'] = PianoKey("B9", getRect("B9"),getRect("Bb9"));

    piano_keys['1'] = PianoKey("Db4", getRect("Db4"));
    piano_keys['2'] = PianoKey("Eb4", getRect("Eb4"));
    piano_keys['3'] = PianoKey("Gb4", getRect("Gb4"));
    piano_keys['4'] = PianoKey("Ab4", getRect("Ab4"));
    piano_keys['5'] = PianoKey("Bb4", getRect("Bb4"));

    piano_keys['6'] = PianoKey("Db5", getRect("Db5"));
    piano_keys['7'] = PianoKey("Eb5", getRect("Eb5"));
    piano_keys['8'] = PianoKey("Gb5", getRect("Gb5"));
    piano_keys['9'] = PianoKey("Ab5", getRect("Ab5"));
    piano_keys['0'] = PianoKey("Bb5", getRect("Bb5"));

    piano_keys['Z'] = PianoKey("Db6", getRect("Db6"));
    piano_keys['X'] = PianoKey("Eb6", getRect("Eb6"));
    piano_keys['C'] = PianoKey("Gb6", getRect("Gb6"));
    piano_keys['V'] = PianoKey("Ab6", getRect("Ab6"));
    piano_keys['B'] = PianoKey("Bb6", getRect("Bb6"));

    piano_keys['�'] = PianoKey("Db7", getRect("Db7"));
    piano_keys['�'] = PianoKey("Eb7", getRect("Eb7"));
    piano_keys['�'] = PianoKey("Gb7", getRect("Gb7"));
    piano_keys['�'] = PianoKey("Ab7", getRect("Ab7"));
    piano_keys['�'] = PianoKey("Bb7", getRect("Bb7"));

    piano_keys['�'] = PianoKey("Db8", getRect("Db8"));
    piano_keys['�'] = PianoKey("Eb8", getRect("Eb8"));
    piano_keys['�'] = PianoKey("Gb8", getRect("Gb8"));
    piano_keys['�'] = PianoKey("Ab8", getRect("Ab8"));
    piano_keys['�'] = PianoKey("Bb8", getRect("Bb8"));

    piano_keys['!'] = PianoKey("Db9", getRect("Db9"));
    piano_keys['@'] = PianoKey("Eb9", getRect("Eb9"));
    piano_keys['#'] = PianoKey("Gb9", getRect("Gb9"));
    piano_keys['$'] = PianoKey("Ab9", getRect("Ab9"));
    piano_keys['%'] = PianoKey("Bb9", getRect("Bb9"));

    for(auto it=piano_keys.begin(); it!=piano_keys.end(); it++)
    {
        PianoKey key = (*it).second;
        key.code = (*it).first;
        note2key[key.name] = key;
    }

    /*

    piano_keys['O'] = PianoKey(QPoint(335,140);    piano_keys['P'] = PianoKey(QPoint(365,140);
    piano_keys['['] = PianoKey(QPoint(407,140);    piano_keys[']'] = PianoKey(QPoint(439,140);
    piano_keys['A'] = PianoKey(QPoint(480,140);    piano_keys['S'] = PianoKey(QPoint(520,140);
    piano_keys['D'] = PianoKey(QPoint(550,140);    piano_keys['F'] = PianoKey(QPoint(580,140);

    piano_keys['1'] = PianoKey(QPoint(58,73);     piano_keys['2'] = PianoKey(QPoint(100,77);
    piano_keys['3'] = PianoKey(QPoint(170,72);    piano_keys['4'] = PianoKey(QPoint(205,77);
    piano_keys['5'] = PianoKey(QPoint(243,75);    piano_keys['6'] = PianoKey(QPoint(315,77);
    piano_keys['7'] = PianoKey(QPoint(354,71);    piano_keys['8'] = PianoKey(QPoint(421,79);
    */


//    //C6
//    key2pixel['F'] = 64;    key2pixel['G'] = 65;
//    key2pixel['H'] = 67;    key2pixel['J'] = 69;

}


void PianoWidget::mousePressEvent(QMouseEvent* event)
{
    fprintf(stderr,"pixel %d %d\n", event->pos().x(), event->pos().y());
    setFocus();
    QPointF mouse = mapToViewbox(event->pos(), viewbox);
    for(auto key=piano_keys.begin(); key!=piano_keys.end(); key++)
       (*key).second.on = false;
    bool blackDown = false;
    for(auto key=piano_keys.begin(); key!=piano_keys.end(); key++)
    {
        if((*key).second.name[1] == 'b')
        {
            if( (*key).second.rect.contains(mouse) )
            {
                (*key).second.on = true;
                blackDown = true;
                emit sigMouseKeyDown((*key).first);
            }
        }
    }
    repaint();
    if( blackDown ) return;
    for(auto key=piano_keys.begin(); key!=piano_keys.end(); key++)
    {
        if((*key).second.name[1] != 'b')
        {
            if( (*key).second.rect.contains(mouse) )
            {
                (*key).second.on = true;
                emit sigMouseKeyDown((*key).first);
            }
        }
    }

    repaint();
    // start position 40 120
}

void PianoWidget::mouseReleaseEvent(QMouseEvent* event)
{
    for(auto key=piano_keys.begin(); key!=piano_keys.end(); key++)
    {
        if( (*key).second.on)
        {
            (*key).second.on = false;
            emit sigMouseKeyRelease((*key).first);
        }
    }

     repaint();
}
