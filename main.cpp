//Код написал Илья Александрович Путинцев
//специально для НИИ МВД


#include <QCoreApplication>
#include <stdio.h>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;
void functionEnCode(string);
string functionDeCode(string);

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);



    // В inPut вводим вектор для кодирования без первых двух символов (т.е без "0b")

    string inPut ="000000000000010101110001";

    functionEnCode(inPut);

    // В reCeived вводим вектор для декодирования без первых двух символов (т.е без "0b")
    string reCeived ="000110101011010101111001";
    string checkStr;
    checkStr =functionDeCode(reCeived);

    std::reverse(inPut.begin(), inPut.end());
    std::reverse(checkStr.begin(), checkStr.end());

    if (strnicmp(checkStr.c_str() ,inPut.c_str(), 11) ==0){
        cout <<"Good job";
    }else{
        cout <<"Your can better!) You are cool!) May be inPut is wrong)";
    }




    return a.exec();
}

void functionEnCode(string inPut){

    bool Denc[23];
    bool temp[12];



    string outPut;

    int num = std::stoi(inPut, nullptr, 2);
    printf("Input:   \t %#010x \t", num);
    cout << "(0b" <<inPut  <<")" <<endl;



    bool Mcre[12][23] {1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,1
                      ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,1 ,0 ,0 ,1
                      ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,1 ,0 ,0 ,1 ,0 ,1 ,0 ,1
                      ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,1 ,1
                      ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,1 ,1 ,0 ,1 ,1 ,0 ,0
                      ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,1 ,1 ,0 ,1 ,1 ,0
                      ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,1 ,1 ,0 ,1 ,1
                      ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,0 ,0
                      ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,0
                      ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1
                      ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,1 ,0
                      ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,1};




        for(int j =0; j <23; j++){
            for(int i =0; i <12; i++){
                temp[i] = ((int) inPut[inPut.size() -i -1] -48) *Mcre[i][j];

            }

            Denc[j] = temp[0] ^temp[1] ^temp[2] ^temp[3] ^temp[4] ^temp[5] ^temp[6] ^temp[7] ^temp[8] ^temp[9] ^temp[10] ^temp[11];
        }


        for(int i =0; i <23; i++){
               outPut += std::to_string(Denc[23 -i -1]);

        }

        num = std::stoi(outPut, nullptr, 2);
        printf("Encoded: \t %#010x \t", num);
        cout << "(0b0" <<outPut <<")"<< endl;

}


string functionDeCode(string reCeived){
    bool temp[23];
    string outPut;


    int num = std::stoi(reCeived, nullptr, 2);
    printf("Received:   \t %#010x \t", num);
    cout << "(0b" <<reCeived <<")" <<endl;

    bool Ddec[12];
    bool S[11];


    bool Msc[23][11] = {1 ,0 ,1 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,1
                       ,1 ,1 ,1 ,1 ,1 ,0 ,0 ,1 ,0 ,0 ,1
                       ,1 ,1 ,0 ,1 ,0 ,0 ,1 ,0 ,1 ,0 ,1
                       ,1 ,1 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,1 ,1
                       ,1 ,1 ,0 ,0 ,1 ,1 ,0 ,1 ,1 ,0 ,0
                       ,0 ,1 ,1 ,0 ,0 ,1 ,1 ,0 ,1 ,1 ,0
                       ,0 ,0 ,1 ,1 ,0 ,0 ,1 ,1 ,0 ,1 ,1
                       ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,0 ,0
                       ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,0
                       ,0 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,1 ,1
                       ,1 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,1 ,0
                       ,0 ,1 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,1 ,1
                       ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
                       ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
                       ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
                       ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0
                       ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0
                       ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0
                       ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0
                       ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0
                       ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0
                       ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0
                       ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1};

    for(int j =0; j <11; j++){
        for(int i =0; i <23; i++){
            temp[i] =((int) reCeived[reCeived.size() -i -1] -48) *Msc[i][j];

        }
        S[j] =temp[0] ^temp[1] ^temp[2] ^temp[3] ^temp[4] ^temp[5] ^temp[6] ^temp[7] ^temp[8] ^temp[9] ^temp[10] ^temp[11] ^temp[12] ^temp[13] ^temp[14] ^temp[15] ^temp[16] ^temp[17] ^temp[18] ^temp[19] ^temp[20] ^temp[21] ^temp[22];
        outPut += std::to_string(S[j]);
    }

    num = std::stoi(outPut, nullptr, 2);
    printf("Syndrom: \t %#010x \t", num);
    cout << "(0b0";

    for(int i =0; i <outPut.size() +1; i++){
        cout <<"0";
    }
    cout<<outPut <<")" << endl;



    qint64 s;
    s = 0;
    for(int i =0; i <11; i++){
    //        cout << S[i];
        s +=S[i];
        if (i !=10)
            s *=10;
    }

    QString index;
    index = QString ::number(s);




    bool ok;
    int dec =index.toInt(&ok,2);




    ifstream errors;
    errors.open("errors.dat");
    int i =0;
    string erStr;

    if (!errors.is_open()){
        cout << "File is not open" <<endl;
    }
    while (i !=dec +1) {
        getline(errors ,erStr);
        i++;
    }


    //Вывожу пункт Correction:
    outPut.clear();
    for(int j =2; j <erStr.size(); j++){
        outPut +=erStr[erStr.size() -j -1];
    }
//    cout <<outPut;
//    std::reverse(erStr.begin(), erStr.end());
    num = std::stoi(outPut, nullptr, 2);
    printf("Correction: \t %#010x \t", num);
    cout << "(0b0" <<outPut <<")" << endl;

    //Считаю Ddec:
    for(int j =0; j <11; j++){
        Ddec[j] = (((int) reCeived[reCeived.size() -j -1]) -48) ^(((int) erStr[j]) -48);
//        cout <<Ddec[j];
    }


    //Вывожу Ddec:
    outPut ="";
    for(int i =0; i<11; i++){
        outPut +=std::to_string(Ddec[10-i]);
    }

    num = std::stoi(outPut, nullptr, 2);
    printf("Decoded: \t %#010x \t", num);
    cout << "(0b0";
    for(int i =0; i <outPut.size() +1; i++){
        cout <<"0";
    }
    cout <<outPut <<")" <<endl;

    return outPut;
}
