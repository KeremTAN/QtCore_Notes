#include <QCoreApplication>
#include <iostream>

class Foo {
public:
    void print() {
        std::cout << "This is " << m_name << "\n";
    }
private:
    std::string m_name{"foo"};
};


void display(QString title, QByteArray& bytes) {
    qDebug() << "---" << title << "---";
    qDebug() << "Length: " << bytes.size();
    qDebug() << "Plain: " << bytes;
}

void test() {
    QByteArray data("This is a very long text.. fgdh fdjgdfgju gfhjfghjkh hgjflkjhgjl goırpoy dklfgjfgkjhl fdlkgfkglhdh fdlgkglkdklh dlfkfglkghslfgkhslkghas ldfkjglgljgsjdfg glfjlgjlgjlgdjf dffdghhhgf gtyt jghjhgjghlkjhgfhjgfoıhj fgohjfsphoıjafdgphjıfg gfhjgfhjpsftıhjsh hfjyjeytjytjt");

    QByteArray compressed = qCompress(data, 9); // compression quality between 0 and 9. 9 is very powerful however take very much time
    QByteArray decompressed = qUncompress(compressed);

    display("Original", data);
    display("Compressed", compressed);
    display("Decompressed", decompressed);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Foo{}.print();

    test();


    return a.exec();
}
