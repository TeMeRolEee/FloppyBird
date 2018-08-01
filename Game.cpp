#include <QtCore/QEvent>
#include <QStaticText>
#include "Game.h"
#include "Pipe.h"


Game::Game(QGraphicsScene &scene)
    :scene(scene)
{
    bird = new Bird();
    bird->setPos(0,300);
    scene.addItem(bird);
    QObject::connect(&mainLoopTimer, &QTimer::timeout, this, &Game::loop_slot);
    mainLoopTimer.start(1000 / 60);
    /*
    double pipeHeight = 200;
    auto *pipe1 = new Pipe(pipeHeight);
    auto *pipe2 = new Pipe(600 - pipeHeight);

    pipe1->setPos(540, 0);
    pipe2->setPos(540, 600 - pipeHeight);

    scene.addItem(pipe1);
    scene.addItem(pipe2);*/
}

void Game::loop_slot() {

    if(loopCounter % 20 == 0)
    {
        int random = rand() % (250-150 +1) + 150;
        double pipeHeight = random;
        auto *pipe1 = new Pipe(pipeHeight);
        auto *pipe2 = new Pipe(600 - pipeHeight - 200);

        pipe1->setPos(540, 0);
        pipe2->setPos(540, pipeHeight + 200);

        scene.addItem(pipe1);
        scene.addItem(pipe2);
        loopCounter = 0;
    }
    loopCounter++;

    scene.advance();
    if(!bird->collidingItems().isEmpty())
    {
        QFont font;
        font.setPointSize(60);
        font.setStyleHint(QFont::Helvetica);
        QGraphicsTextItem *textItem = scene.addText("GÉM ÓVÖR");
        textItem->setFont(font);

        QColor color(Qt::black);
        textItem->setDefaultTextColor(color);
        textItem->setPos(100,300);
        //QGraphicsTextItem *text = new QGraphicsTextItem("Gém Óvör");
        //text->setPos(scene.height() / 2, scene.width() / 2);


        //text->setFont(font);
        //scene.addItem(text);
        mainLoopTimer.stop();
    }
}

bool Game::eventFilter(QObject *watched, QEvent *event) {
    Q_UNUSED(watched);
    qDebug() << "Something";
    if(event->type() == QEvent::KeyPress)
    {
        qDebug() << "SPACED";
        keyPressEvent((QKeyEvent *) event);
        return true;
    }
    return false;
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        switch (event->key())
        {
            case Qt::Key_Space:
                bird->setY(bird->y() - bird->boundingRect().height() * 1.8);
                break;
            default:
                break;
        }
    }
}
