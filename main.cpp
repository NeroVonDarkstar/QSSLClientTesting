#include <QCoreApplication>
#include <QSsl>
#include <QHostAddress>
#include <QSslSocket>
#include <QDebug>
#include <iostream>
#include <QTextStream>
using namespace std;

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    //QHostAddress HostAddress;
    //HostAddress.setAddress(Address);
    string addressBuffer;
    string hostBuffer;
    cout << "Starting connection to ssl server " << endl;
    cout << "Please enter an address to connect to: " << endl;
    cin >> addressBuffer;
    cout << "Please enter a port to connect to: " << endl;
    cin >> hostBuffer;
    cout << "Thank you, connecting:" << endl;

    QSslSocket Socket;
    QString Address = QString::fromStdString(addressBuffer);
    QString StrPort = QString::fromStdString(hostBuffer);
    quint16 Port = 0;
    QTextStream PortBuffer(&StrPort);
    PortBuffer >> Port;
    cout << Port << endl;
    Socket.connectToHostEncrypted(Address, Port);

    if(!Socket.waitForEncrypted()) {
        cout << "Connection Failed" << endl;
        return false;
    }
    cout << "Connection established" << endl;

    return true;
    return a.exec();
}
