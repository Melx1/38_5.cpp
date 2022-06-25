// 38_5_2.cpp: определяет точку входа для приложения.

#include <QApplication>
#include <QtWebEngineWidgets>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QWidget window(nullptr);
    QPlainTextEdit* text = new QPlainTextEdit("source");
    QWebEngineView* view = new QWebEngineView();
    text->setMinimumSize({20,20});
    view->setMinimumSize(text->minimumSize());
    view->setContent("result");
    QHBoxLayout* layout = new QHBoxLayout(&window);
    layout->addWidget(text);
    layout->addWidget(view);
    layout->setStretch(0, 1);
    layout->setStretch(1, 1);
    QObject::connect(text, &QPlainTextEdit::textChanged, [&text, &view]() mutable {
        view->setHtml(text->toPlainText());
        view->update();
        });
    window.show();
    return QApplication::exec();
}