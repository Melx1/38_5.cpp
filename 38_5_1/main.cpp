#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QObject>
#include <QtMultimedia/QMediaPlayer>

class StopButton : public QPushButton {
    Q_OBJECT

public:
    explicit StopButton(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

public slots:
    void setUp();
    void setDown();

private:
    QPixmap downPixmap;
    QPixmap upPixmap;
    QPixmap currentPixmap;
};


StopButton::StopButton (QWidget* parent) : QPushButton(parent) {
    downPixmap = QPixmap("..\\buttonDown.png");
    upPixmap = QPixmap("..\\buttonUp.png");
    currentPixmap = upPixmap;
    this->setFixedSize(currentPixmap.size());
    connect(this, &QPushButton::pressed, this, &StopButton::setDown);
    connect(this, &QPushButton::released, this, &StopButton::setUp);
}

void StopButton::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawPixmap(this->rect(), currentPixmap);
}

void StopButton::setUp() {
    currentPixmap = upPixmap;
    update();
}

void StopButton::setDown() {
    currentPixmap = downPixmap;
    update();
    auto *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("..\\stopButtonVol.mp3"));
    player->setVolume(50);
    player->play();
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    StopButton window(nullptr);
    window.show();
    return QApplication::exec();
}

#include "main.moc"