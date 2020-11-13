#include "XmlModi.h"
#include <qpushbutton.h>
XmlModi::XmlModi(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
   // connect(ui.pbWrite, &QPushButton::clicked, this, &XmlModi::fWrite);
    connect(ui.pbRead, &QPushButton::clicked, this, &XmlModi::fRead);
    connect(ui.pbReplace, &QPushButton::clicked, this, &XmlModi::replace);
    //connect(ui.pbFind, &QPushButton::clicked, this, &XmlModi::fFind);

}

/*void XmlModi::fWrite() {

    /*QFile data("C:/Users/H.Sarhan/Documents/Hamdy/XmlProjekt/AddiThink.txt");
    data.open(QIODevice::Text | QIODevice::ReadOnly);
    QString dataText = data.readAll();
    QRegularExpression re("axisssss");
    QString replacementText("axis");

    dataText.replace(re, replacementText);

    QFile newData("C:/Users/H.Sarhan/Documents/Hamdy/XmlProjekt/AddiThink.txt");
    if (newData.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&newData);
        out << dataText;
    }
    newData.close();*/

  /*  QFile file("AddiThink.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::critical(this, "Erorr", "Can't open this file!");
    }
    QTextStream out(&file);
    QString text = ui.plainTextEdit->toPlainText();
    out << text;

    //file.flush();
    file.close();



}*/
/*void XmlModi::readText() {
    QLineEdit fir;
    

      


}*/

/*static QString loadTextFile()
{
    QFile inputFile("C:/Users/H.Sarhan/Documents/Hamdy/XmlProjekt/AddiThink.txt");
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    in.setCodec("UTF-8");
    return in.readAll();
}*/

void XmlModi::fRead(){

    QFile file("AddiThink.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::critical(this, "Erorr", "Can't open this file!");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui.plainTextEdit->setPlainText(text);
    
    file.close();



}

/*void XmlModi::fFind() {
    QString axisid = "<axis id=";
    char qot = '"';
    double val;


    QString id;
    QString para;
    QString line;
    id = ui.readA->text();
    para = ui.readP->text();
    QFile data("AddiThink.txt");
    data.open(QIODevice::Text | QIODevice::ReadOnly);
    QTextStream stream(&data);
    
    do
    {
        line = stream.readLine();
        if (line.contains(axisid+qot+id+qot, Qt::CaseSensitive)&&line.contains(para, Qt::CaseSensitive))
        {
            QMessageBox::information(this, "Info ", "Found");

            break;
        }
        
        
    } while (!line.isNull());
   




}*/

void XmlModi::replace()
{
   
    
    string axisid = "<axis id=";
    char qot = '"';
    char gl = '=';
    QString val;
    char le = ' ';
    
    QString id;
    QString para;

    
    string ids;
    string paras;
    string vals;
    
    

    
   
    //QString line2;
    id = ui.readA->text();       //aus GUI lesen
    para = ui.readP->text();     //aus GUI lesen
    val = ui.readV->text();      //aus GUI lesen

    //Konvertieren
    ids = id.toStdString();         //von QString zu String konvertieren
    paras = para.toStdString();     //von QString zu String konvertieren
    vals = val.toStdString();       //von QString zu String konvertieren

    
        //QString dataText = data.readAll();
    
    ifstream data("AddiThink.txt"); //zum Lesen oeffnen
    //QString dataText = data.readAll();
   // QTextStream stream(&data);

    //QFile tempFile("test.txt");
    //tempFile.open(QIODevice::Text | QIODevice::WriteOnly);
    //QTextStream out(&tempFile);
    
    ofstream tempFile("test.txt"); //zum Schreiben oeffnen

    
   // string word = axisid + id + qot;
   
    string line;
    string word1 = axisid +qot+ ids + qot;
    string word2 = paras + gl ;
   
    
   do
    {

       
        string line2;
        getline(data, line); //Zeile einlesen
        
        
        line2 = line;

        if (line2.find(axisid+qot+ids+qot  ) != string::npos && line2.find(word2) != string::npos) //einchecken ob diese Zeile die ID und Para die wir ersetzen möchten enthält
        {
            
          // std::vector<std::string> list;
           string newLine;
           //von String zu Vector konvertieren
           std::vector<std::string> result;
           std::istringstream iss(line2);
           for (std::string s; iss >> s; )
           { 
               result.push_back(s);

           }
           //durchlaufen in dem Vector bis den Parameter gefunden weurde
           for (int i = 0; i < result.size(); i++) 
           { 
               if (result[i].find(word2) != string::npos)  //gefunden!
               { 
                   string toBeReplaced = result[i];        //zuersetzen
                   string replacement = paras + gl + qot + vals + qot; //die neue Value
                   size_t start_pos = result[i].find(toBeReplaced);
                   
                   result[i].replace(start_pos, toBeReplaced.length(), replacement); //ersetzung

                 

               }

           }
           //std::stringstream ss(line);
           //std::istream_iterator<std::string> begin(ss);
           //std::istream_iterator<std::string> end;
           //std::vector<std::string> vstrings(begin, end);
            
            /*list = line2.split(' ');
            for (int i = 1; i < list.size(); i++) {


                if (list.at(i).contains(para + gl, Qt::CaseSensitive)) {
                    // QRegularExpression re(list.at(i));
                    // QString replacementText(para+gl+qot+ui.readV->text()+qot);
                    QString befor = list[i];
                    QString after = para + gl + qot + ui.readV->text() + qot;

               
               list.replaceInStrings(befor, after, Qt::CaseSensitive);*/
              
                    QMessageBox::information(this, "Info", "Replaced successfully");
               
                    
                    for (std::vector<std::string>::const_iterator i = result.begin(); i != result.end(); ++i) //Konvertierung von Vector zu String
                    {
                        newLine += *i+le;
                    }
                  /*  for (int j = 0; j < list.size(); j++) {
                        newLine = newLine + list.at(j)+" ";*/


                   // }
                    
                    tempFile <<"    "+ newLine<<endl; //modifezierte Zeile in Temp File schreiben

            
                   
                    

        }
        else {
            tempFile << line<<endl; //Zeile in Temp File schreiben
            continue;
        }

                
                //break;
   } while (!line.empty());

            
           
           // break;
            
               
               // tempFile << newLine<<endl;
            
            
            
        
       // }
      //  else
      //  {
           
               // tempFile << line<<endl;
            
       //     continue;
       // }
        
            
           
            
   data.close(); //Data schliessen
   tempFile.close();
   remove("AddiThink.txt"); //Alte Datei loechen
   rename("test.txt", "AddiThink.txt"); //Neue Datei unbenennen
        
        
       
        
  }
   
        //out >> line;

    

   

        

    
    //line.contains(("axis id=" + '"' + id + '"'), Qt::CaseInsensitive) && line.contains(para + "=", Qt::CaseInsensitive
   /* if{
       
           
            QRegularExpression re(para);
            QString replacementText(ui.readV->text());
            dataText.replace(re, replacementText);
            QMessageBox::information(this, "Info", "Replaced successfully");

        


    }*/
        
    
    

    

    /*QFile newData("test.txt");
    if (newData.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&newData);
        out << dataText;
    }
    newData.close();*/



