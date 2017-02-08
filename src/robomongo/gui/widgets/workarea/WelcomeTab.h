#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
class QNetworkReply;
class QLabel;
class QVBoxLayout;
class QScrollArea;
QT_END_NAMESPACE

namespace Robomongo
{
    struct ConnectionEstablishedEvent;

    class WelcomeTab : public QWidget
    {
        Q_OBJECT

    public:
        WelcomeTab(QScrollArea *parent = nullptr);
        ~WelcomeTab();

    private Q_SLOTS:
        void downloadFinished(QNetworkReply* reply);
        void on_allBlogsButton_clicked();
        void on_clearButton_clicked();
        void linkActivated(QString const& link);
        void linkHovered(QString const& link);
        void handle(ConnectionEstablishedEvent *event);

    private:
        QLabel* _pic1 = nullptr;
        QPushButton* _allBlogsButton = nullptr;
        QVBoxLayout* _recentConnsLay;
        QPushButton* _clearButton;
        QScrollArea* _parent;

        int _lastAddedConnId = -1;
    };

}