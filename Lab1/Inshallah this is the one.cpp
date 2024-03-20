#include <vector>
#include <iostream>
#include "MatClass.h"
#include <string>
int main()
{

    Matrix temp1(3);
    Matrix temp2(3);
    std::ifstream ifile("input.txt");
    ifile >> temp1;
    temp2 = temp1;
    std::cout << temp1 << std::endl;
    std::cout << temp2 << std::endl;
    Matrix temp3;
    temp3 = temp1.MatMulti(temp1, temp2);
    std::cout << temp3 << std::endl;
    std::cout << "Test Cases" << std::endl;
    std::cout << "1. Read Matrix from File" << std::endl;
    std::cout << "2. Calculate Determinant" << std::endl;
    std::cout << "3. Multiply Matrix by a Scalar" << std::endl;
    std::cout << "4. Calculate Inverse" << std::endl;
    std::cout << "5. Transpose Matrix" << std::endl;
    std::cout << "6. Print Matrix" << std::endl;
    std::cout << "7. Output Matrix to File (txt and csv)" << std::endl;
    std::cout << "0. Exit" << std::endl;
    bool exit = false;
    Matrix bro(3);
    do {
        int x;
        std::cin >> x;
        double det;
        switch (x)
        {
        case 1: {
            std::ifstream ifile("input.txt");
            if (ifile.is_open()) {
                std::cout << "Reading from file..." << std::endl;
                ifile >> bro;
                ifile.close();
            }
            else {
                std::cout << "Failed to open file, going back to menu...." << std::endl;
            }
            break;
        }
        case 2:
            std::cout << "Determinant Case" << std::endl;
            det = bro.det();
            std::cout << "Det =" << det << std::endl;
            break;
        case 3:
        {
            std::cout << "Multiply Case" << std::endl;
            std::cout << "Multiply by?" << std::endl;
            double y;
            std::cin >> y;
            Matrix bro2(bro);
            bro2 = bro.MatMulti(y);
            std::cout << bro2 << std::endl;
            break;
        }
        case 4:
        {
            std::cout << "Inverse" << std::endl;
            Matrix tempi;
            tempi = tempi.MatInv(bro);
            std::cout << tempi << std::endl;
            break;
        }
        case 5:
        {
            std::cout << "Transpose case" << std::endl;
            Matrix tempt;
            tempt = tempt.MatTrans(bro);
            std::cout << tempt << std::endl;
            break;
        }
        case 6:
            std::cout << "Printing" << std::endl;
            std::cout << bro << std::endl;
            break;
        case 7:
        {
            std::ofstream ofile("output.txt");
            std::ofstream ofile2("output.csv");
            if (ofile.is_open()) 
            {
                ofile << bro;
                std::cout << "Outputting to txt..." << std::endl;
                ofile.close();
            }
            else
            {
                std::cout << "Failed to output to txt, going back to menu...." << std::endl;
            }
            if (ofile2.is_open())
            {
                ofile2 << bro;
                std::cout << "Outputting to csv..." << std::endl;
                ofile2.close();
            }
            else
            {
                std::cout << "Failed to output to csv, going back to menu...." << std::endl;
            }
            break;
        }
        case 0:
            std::cout << "Exitting...." << std::endl;
            exit = true;
            break;
        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
            break;
        }
    } while (!exit);

}

