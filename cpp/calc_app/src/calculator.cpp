#include "calculator.h"
#include "../include/calculator.h"
#include <fstream>
#include <filesystem>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <math.h>


void Calculator::intro() {
    std::ifstream file("assets/ascii_intro.txt");
    if (!file.is_open()) {
        std::cerr << "Error: ascii_intro.txt not found\n";
        return;
    }
    std::cout << file.rdbuf();
    std::cout << "\nYou can make many calculations here\n";
}
int Calculator::choose() {
    int input = 0;
    while (true) {
        std::cout << "\nCalculator Menu:\n";
        std::cout << "1) mathmatic\n2) Area\n3) Perimeter\n4) Volume\n5) Quite\n";
        std::cout << "Enter choice : ";
        std::cin >> input;
        if (input>=1 && input<=5) {
            if (input == 5) {
                std::ifstream file("assets/ascii_close.txt");
                if (!file.is_open()) {
                    std::cerr << "Error: ascii_intro.txt not found\n";
                }
                std::cout << file.rdbuf();
            }
            return input;
        }
        std::cout << "\nWrong input. Please try again.\n";

    }
}
double Calculator::add(double a, double b) {
    return (a + b);
}

double Calculator::sub(double a, double b) {
    return (a - b);
}

double Calculator::mul(double a, double b) {
    return (a * b);
}

double Calculator::div(double a, double b) {
    if (b == 0) {
        std::cout << "Division by zero!!!\n";
        return -1;
    }
    else {
        return (a / b);
    }
}
double Calculator::powr(long double a, long double b) {
    return pow(a, b);
}
double Calculator::roott(double a, double b) {
    if (b < 0) {
        std::cout << "\nCannot root a negative number.\n";
        return -1;
    }
    return pow(b, 1.0/a);
}
void Calculator::mathmatic() {
    double a {0}, b {0};
    char op;
    int in;
    while (true) {
        std::cout << "\nChoose: \n" << "1) make operation\n" <<  "2) Return\n";
        std::cout << "Enter choice : ";
        std::cin >> in;
        if (in == 2) {
            std::cout << "\nThanks for using calculator!\n";
            break;
        }
        else if (in < 1 || in > 2) {
            std::cout << "\nWrong input. Please try again.\n";
        }
        else if (in == 1) {
            std::cout << "Enter expression\n";
            std::string expr;
            std::getline(std::cin >> std::ws, expr);

            if (sscanf(expr.c_str(), "%lf %c %lf", &a, &op, &b) != 3) {
                std::cout << "Invalid expression. Use format: \n";
                continue;
            }
            switch (op) {
                case '+':
                    std::cout << "-----------\n";
                    std::cout << "Result add: " << add(a, b) << "\n";
                    std::cout << "-----------\n";
                    break;
                case '-':
                    std::cout << "-----------\n";
                    std::cout << "Result sub: " <<sub(a,b) << "\n";
                    std::cout << "-----------\n";
                    break;
                case '*':
                    std::cout << "-----------\n";
                    std::cout << "Result mul: " <<mul(a,b) << "\n";
                    std::cout << "-----------\n";
                    break;
                case '/':
                    std::cout << "-----------\n";
                    std::cout << "Result div: " << div(a,b) << "\n";
                    std::cout << "-----------\n";
                    break;
                case '^':
                    std::cout << "-----------\n";
                    std::cout << "Result root: " << std::fixed << std::setprecision(20) << powr(a,b) << "\n";
                    std::cout << "-----------\n";
                    break;
                case 'V':
                    std::cout << "-----------\n";
                    std::cout << "Result root: " <<roott(a, b) << "\n";
                    std::cout << "-----------\n";
                    break;
                default:
                    std::cout << "-----------\n";
                    std::cout << "Invalid operator.\n";
            }
        }

    }
}

double Calculator::area_rec(double a, double b) {
    return (a * b);
}

double Calculator::area_sqr(double a) {
    return (a * a);
}

double Calculator::area_circ(double a) {
    return (a * a * pi);
}

double Calculator::area_eclp(double a, double b) {
    return (a * b * pi);
}

void Calculator::area() {
    double a {0}, b {0};
    int in {0};
    while (true) {
        std::cout << "\nChoose: \n" << "1) Rectangle\n" <<  "2) Square\n"
        <<  "3) Circle\n" <<  "4) Ellipse\n" <<  "5) Return\n";
        std::cout << "Enter choice : ";
        std::cin >> in;
        if (in == 5) {
            std::cout << "----------------------------------\n";
            std::cout << "Thanks for using area calculator!\n";
            std::cout << "----------------------------------\n";
            break;
        }
        else if (in < 1 || in > 5) {
            std::cout << "\nWrong input. Please try again.\n";
        }
        else {
            switch (in) {
                case 1:
                    std::cout << "Enter rectangle width: ";
                    std::cin >> a;
                    std::cout << "Enter rectangle height: ";
                    std::cin >> b;
                    std::cout << "------------\n";
                    std::cout << "Area of rectangle: " << area_rec(a, b) << "\n";
                    std::cout << "------------\n";
                    break;
                case 2:
                    std::cout << "Enter square length: ";
                    std::cin >> a;
                    std::cout << "------------\n";
                    std::cout << "Area of square: " << area_sqr(a) << "\n";
                    std::cout << "------------\n";
                    break;
                case 3:
                    std::cout << "Enter circle redius: ";
                    std::cin >> a;
                    std::cout << "------------\n";
                    std::cout << "Area of circle: " << area_circ(a) << "\n";
                    std::cout << "------------\n";
                    break;
                case 4:
                    std::cout << "Enter ellipse redius 1: ";
                    std::cin >> a;
                    std::cout << "Enter ellipse redius 2: ";
                    std::cin >> b;
                    std::cout << "------------\n";
                    std::cout << "Area of ellipse: " << area_eclp(a, b) << "\n";
                    std::cout << "------------\n";
                    break;
                default:
                    std::cout << "Invalid choice.\n";
                    break;
            }
        }
    }
}
double Calculator::perimeter_rec(double a, double b) {
    return ( 2 * (a + b));
}
double Calculator::perimeter_sqr(double a) {
    return (4 * a);
}
double Calculator::perimeter_circ(double a) {
    return (2 * pi * a);
}
double Calculator::perimeter_eclp(double a, double b) {
    double c {0};
    return c = 2 * pi * sqrt((a * a + b * b) / (2 * 1.0));
}
void Calculator::perimeter() {
    double a {0}, b {0};
    int in {0};
    while (true) {
        std::cout << "\nChoose: \n" << "1) Rectangle\n" <<  "2) Square\n"
        <<  "3) Circle\n" <<  "4) Ellipse\n" <<  "5) Return\n";
        std::cout << "Enter choice : ";
        std::cin >> in;
        if (in == 5) {
            std::cout << "----------------------------------\n";
            std::cout << "Thanks for using perimeter calculator!\n";
            std::cout << "----------------------------------\n";
            break;
        }
        else if (in < 1 || in > 5) {
            std::cout << "\nWrong input. Please try again.\n";
        }
        else {
            switch (in) {
                case 1:
                    std::cout << "Enter rectangle width: ";
                    std::cin >> a;
                    std::cout << "Enter rectangle height: ";
                    std::cin >> b;
                    std::cout << "------------\n";
                    std::cout << "Perimeter of rectangle: " << perimeter_rec(a, b) << "\n";
                    std::cout << "------------\n";
                    break;
                case 2:
                    std::cout << "Enter square length: ";
                    std::cin >> a;
                    std::cout << "------------\n";
                    std::cout << "Perimeter of rectangle: " << perimeter_sqr(a) << "\n";
                    std::cout << "------------\n";
                    break;
                case 3:
                    std::cout << "Enter circle radius: ";
                    std::cin >> a;
                    std::cout << "------------\n";
                    std::cout << "Perimeter of circle: " << perimeter_circ(a) << "\n";
                    std::cout << "------------\n";
                    break;
                case 4:
                    std::cout << "Enter ellipse radius 1: ";
                    std::cin >> a;
                    std::cout << "Enter ellipse radius 2: ";
                    std::cin >> b;
                    std::cout << "------------\n";
                    std::cout << "Perimeter of ellipse: " << perimeter_eclp(a, b) << "\n";
                    std::cout << "------------\n";
                    break;
                default:
                    std::cout << "Invalid choice.\n";
            }
        }
    }
}

double Calculator::volume_rec_prism(double a, double b, double c) {
    return (a * b * c);
}
double Calculator::volume_sqr_prism(double a) {
    return (pow(a, 3));
}

double Calculator::volume_sphere(double a) {
    return ((4/3) * pi * pow(a, 3));
}
double Calculator::volume_elipsoid(double a, double b, double c) {
    double out {0};
    return out = (1.33 * pi * a * b * c);
}

void Calculator::volume() {
    double a {0}, b {0}, c {0};
    int in {0};
    while (true) {
        std::cout << "\nChoose: \n" << "1) Rectangle\n" <<  "2) Square\n" << "3) Shpere\n" <<
            "4) Ellipsoid\n" <<  "5) Return\n";
        std::cout << "Enter choice : ";
        std::cin >> in;
        if (in == 5) {
            std::cout << "----------------------------------\n";
            std::cout << "Thanks for using Volume calculator!\n";
            std::cout << "----------------------------------\n";
            break;
        }
        else if (in < 1 || in > 5) {
            std::cout << "\nWrong input. Please try again.\n";
        }
        else {
            switch (in) {
                case 1:
                    std::cout << "Enter rectangle width: ";
                    std::cin >> a;
                    std::cout << "Enter rectangle length: ";
                    std::cin >> b;
                    std::cout << "Enter rectangle height: ";
                    std::cin >> c;
                    std::cout << "------------\n";
                    std::cout << "Volume of rectangle: " << volume_rec_prism(a, b, c) << "\n";
                    std::cout << "------------\n";
                    break;
                case 2:
                    std::cout << "Enter square length: ";
                    std::cin >> a;
                    std::cout << "------------\n";
                    std::cout << "Volume of rectangle: " << volume_sqr_prism(a) << "\n";
                    std::cout << "------------\n";
                    break;
                case 3:
                    std::cout << "Enter circle radius: ";
                    std::cin >> a;
                    std::cout << "------------\n";
                    std::cout << "Volume of sphere: " << volume_sphere(a) << "\n";
                    std::cout << "------------\n";
                    break;
                case 4:
                    std::cout << "Enter ellipse radius 1: ";
                    std::cin >> a;
                    std::cout << "Enter ellipse radius 2: ";
                    std::cin >> b;
                    std::cout << "Enter ellipse radius 3: ";
                    std::cin >> c;
                    std::cout << "------------\n";
                    std::cout << "Volume of ellipse: " << volume_elipsoid(a, b, c) << "\n";
                    std::cout << "------------\n";
                    break;
                default:
                    std::cout << "Invalid choice.\n";
            }
        }
    }
}
void Calculator::calculator() {
    while (true) {
        int choice = choose();
        if (choice == 5) {
            break;
        }
        switch (choice) {
            case 1:
                mathmatic();
                break;
            case 2:
                area();
                break;
            case 3:
                perimeter();
                break;
            case 4:
                volume();
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}


void Calculator::run() {
    intro();
    calculator();
}
