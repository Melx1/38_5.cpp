// 38_5_3_VS.cpp: определяет точку входа для приложения.

#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QGraphicsBlurEffect>


int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
	QWidget* mainForm = new QWidget();
		mainForm->setBaseSize({ 640,480 });
			QLabel* imageLabel = new QLabel(mainForm);
			imageLabel->setMinimumSize(640, 480);
			imageLabel->setScaledContents(true);
			imageLabel->setAlignment(Qt::AlignCenter);
			imageLabel->setText("Open the image");

			QSlider* blurSlider = new QSlider(mainForm);
			blurSlider->setOrientation(Qt::Horizontal);
			blurSlider->setMinimum(0);
			blurSlider->setMaximum(10);
			
			QPushButton* openFileButton = new QPushButton(mainForm);
			openFileButton->setText("Open");
			QString filePath;

			QObject::connect(blurSlider, &QSlider::valueChanged, [&blurSlider, &imageLabel]() {
				QGraphicsBlurEffect* blurEffect = new QGraphicsBlurEffect();
				blurEffect->setBlurRadius(blurSlider->value());
				imageLabel->setGraphicsEffect(blurEffect);
				imageLabel->update();
				});

			QObject::connect(openFileButton, &QPushButton::clicked, [&filePath, &imageLabel, &blurSlider]() mutable {
				filePath = QFileDialog::getOpenFileName(nullptr, QObject::tr("Open Image"), "./", QObject::tr("Image Files (*.png *.jpg *.bmp)"));
				blurSlider->setValue(0);
				imageLabel->setPixmap(QPixmap::fromImage(QImage(filePath).scaled(imageLabel->width(), imageLabel->height(), Qt::KeepAspectRatio)));
				});

			QVBoxLayout* layout = new QVBoxLayout(mainForm);
			layout->addWidget(imageLabel);
			layout->addWidget(blurSlider);
			layout->addWidget(openFileButton);
	mainForm->show();
	return QApplication::exec();
}
