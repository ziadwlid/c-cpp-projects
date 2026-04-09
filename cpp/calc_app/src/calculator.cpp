#include "calculator.h"
#include "../include/calculator.h"
#include "../include/draw_shapes.h"
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
        std::cout << "1) mathmatic\n"
                     "2) Area\n3) Perimeter\n4) Volume\n5) Surface area\n"
                     "6) Trig function\n7) Unit convertor\n"
                     "8) History\n"
                     "9) Quit\n";
        std::cout << "Enter choice : ";
        std::cin >> input;
        if (input>=1 && input<=9) {
            if (input == 9) {
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

long int Calculator::modulo(long int a, long int b) {
    if (a != floor(a) || b != floor(b)) {
        std::cout << "The numbers are double datatype!\n";
        std::cout << "Converted to integer datatype: \n";
        long int x = (long int)a;
        long int y = (long int)b;
        return x % y;
    }
    else return (long int)a % (long int)b;
}

double Calculator::logfuc(double a, double b) {
    if (a <= 0 || a == 1 || b <= 0) {
        std::cout << "Invalid values for logarithm\n";
        return -1;
    }
    return log(b) / log(a);
}

long int Calculator::factorial(long int a) {
    if (a < 0) {
        std::cout << "Factorial not defined for negative numbers\n";
        return -1;
    }
    if (a == 0 || a == 1)
        return 1;
    return a * factorial(a - 1);
}

double Calculator::absolute(double a) {
    if (a > 0) return a;
    else return std::abs(a);
}

void Calculator::mathematic() {
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
            std::cout << "\nadd-> '+'\nsub-> '-'\nmult-> '*'\ndiv-> '/'\npower-> '^'\nroot-> 'V' "
                         "\nmodule-> '%' \nlog-> 'l a b'"
                         "\nfact-> 'f'"
                         "\nabs-> 's'\n\n";
            std::cout << "Enter expression (or 'q or Q' to quit): ";
            std::string expr;
            std::getline(std::cin >> std::ws, expr);
            if (expr == "q" || expr == "Q") {
                std::cout << "Exiting calculator...\n";
                break;
            }
            int count = sscanf(expr.c_str(), "%lf %c %lf", &a, &op, &b);
            if (count < 2) {
                std::cout << "Invalid expression.\n";
                continue;
            }
            switch (op) {
                case '+':
                    std::cout << "-----------\n";
                    std::cout << "Result add: " << add(a, b) << "\n";
                    add_history(std::to_string(a) + " + " + std::to_string(b) + " = " + std::to_string(add(a, b)));
                    std::cout << "-----------\n";
                    break;
                case '-':
                    std::cout << "-----------\n";
                    std::cout << "Result sub: " <<sub(a,b) << "\n";
                    add_history(std::to_string(a) + " - " + std::to_string(b) + " = " + std::to_string(sub(a, b)));
                    std::cout << "-----------\n";
                    break;
                case '*':
                    std::cout << "-----------\n";
                    std::cout << "Result mul: " <<mul(a,b) << "\n";
                    add_history(std::to_string(a) + " * " + std::to_string(b) + " = " + std::to_string(mul(a, b)));
                    std::cout << "-----------\n";
                    break;
                case '/':
                    std::cout << "-----------\n";
                    std::cout << "Result div: " << div(a,b) << "\n";
                    add_history(std::to_string(a) + " / " + std::to_string(b) + " = " + std::to_string(div(a, b)));
                    std::cout << "-----------\n";
                    break;
                case '^':
                    std::cout << "-----------\n";
                    std::cout << "Result power: " << std::fixed << std::setprecision(20) << powr(a,b) << "\n";
                    add_history(std::to_string(a) + " pow " + std::to_string(b) + " = " + std::to_string(powr(a, b)));
                    std::cout << "-----------\n";
                    break;
                case 'V':
                    std::cout << "-----------\n";
                    std::cout << "Result root: " <<roott(a, b) << "\n";
                    add_history(std::to_string(a) + " root " + std::to_string(b) + " = " + std::to_string(roott(a, b)));
                    std::cout << "-----------\n";
                    break;
                case '%':
                    std::cout << "-----------\n";
                    std::cout << "Result module: " <<modulo(a, b) << "\n";
                    add_history(std::to_string(a) + " modulu " + std::to_string(b) + " = " + std::to_string(modulo(a, b)));
                    std::cout << "-----------\n";
                    break;
                case 'l':
                    std::cout << "-----------\n";
                    std::cout << "Result logarithm: " <<logfuc(a, b) << "\n";
                    add_history(std::to_string(a) + " log " + std::to_string(b) + " = " + std::to_string(logfuc(a, b)));
                    std::cout << "-----------\n";
                    break;
                case 'f':
                    if (count != 2) {
                        std::cout << "Factorial takes one number.\n";
                        break;
                    }
                    std::cout << "-----------\n";
                    std::cout << "Result factorial: " <<factorial(a) << "\n";
                    add_history(std::to_string(a) + " factorial = " + std::to_string(factorial(a)));
                    std::cout << "-----------\n";
                    break;
                case 's':
                    std::cout << "-----------\n";
                    std::cout << "Result absolute: " <<absolute(a) << "\n";
                    add_history(std::to_string(a) + " absolute = " + std::to_string(absolute(a)));
                    std::cout << "-----------\n";
                    break;
                default:
                    std::cout << "-----------\n";
                    std::cout << "Invalid operator.\n";
            }
        }

    }
}
bool Calculator::check_input(double &x, const std::string &prompt) {
    std::string line;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin >> std::ws, line);
        if (line == "q" || line == "Q") {
            x = -1;
            return false;   // <--- return false on quit
        }
        std::stringstream ss(line);
        if (!(ss >> x)) {
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        if (x <= 0 || x > 1000) {
            std::cout << "Invalid input. Enter a number between 1 and 1000.\n";
            continue;
        }
        if (!(ss >> std::ws).eof()) {
            std::cout << "Invalid input. Extra characters after number.\n";
            continue;
        }
        return true;
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

double Calculator::area_triangle(double a, double b) {
    return ((a*b) / 2);
}

void Calculator::area() {
    double a {0}, b {0};
    int in {0};
    while (true) {
        std::cout << "\nChoose: \n" << "1) Rectangle\n" <<  "2) Square\n"
        <<  "3) Circle\n" <<  "4) Ellipse\n" << "5) Triangle\n" <<  "6) Return\n";
        std::cout << "Enter choice : ";
        std::cin >> in;
        if (in == 6) {
            std::cout << "----------------------------------\n";
            std::cout << "Thanks for using area calculator!\n";
            std::cout << "----------------------------------\n";
            break;
        }
        else if (in < 1 || in > 6) {
            std::cout << "\nWrong input. Please try again.\n";
        }
        else {
            switch (in) {
                case 1:
                    if (!check_input(a, "Enter rectangle width: ")) break;
                    if (!check_input(b, "Enter rectangle length: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Area of rectangle: " << std::fixed << std::setprecision(10)<< area_rec(a, b) << "\n";
                    std::cout << "Drawing rectangle: \n\n";
                    draw_shapes::rectangle(static_cast<int> (a), static_cast<int>(b));
                    std::cout << "\n------------\n";
                    break;
                case 2:
                    if (!check_input(a, "Enter square length: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Area of square: " << std::fixed << std::setprecision(10)<< area_sqr(a) << "\n";
                    std::cout << "Drawing square: \n\n";
                    draw_shapes::square(static_cast<int> (a));
                    std::cout << "\n------------\n";
                    break;
                case 3:
                    if (!check_input(a, "Enter circle radius: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Area of circle: " << std::fixed << std::setprecision(10) << area_circ(a) << "\n";
                    std::cout << "------------\n";
                    break;
                case 4:
                    if (!check_input(a, "Enter ellipse radius 1: ")) break;
                    if (!check_input(b, "Enter ellipse radius 2: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Area of ellipse: " << std::fixed << std::setprecision(10) << area_eclp(a, b) << "\n";
                    std::cout << "------------\n";
                    break;
                case 5:
                    if (!check_input(a, "Enter triangle length: ")) break;
                    if (!check_input(b, "Enter triangle height: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Area of triangle: " << std::fixed << std::setprecision(10) << area_triangle(a, b) << "\n";
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
double Calculator::perimeter_triangle(double a, double b, double c) {
    return (a + b + c);
}
void Calculator::perimeter() {
    double a {0}, b {0}, c {0};
    int in {0};
    while (true) {
        std::cout << "\nChoose: \n" << "1) Rectangle\n" <<  "2) Square\n"
        <<  "3) Circle\n" <<  "4) Ellipse\n" << "5) Triangle\n"<<  "6) Return\n";
        std::cout << "Enter choice : ";
        std::cin >> in;
        if (in == 6) {
            std::cout << "----------------------------------\n";
            std::cout << "Thanks for using perimeter calculator!\n";
            std::cout << "----------------------------------\n";
            break;
        }
        else if (in < 1 || in > 6) {
            std::cout << "\nWrong input. Please try again.\n";
        }
        else {
            switch (in) {
                case 1:
                    if (!check_input(a, "Enter rectangle width: ")) break;
                    if (!check_input(b, "Enter rectangle height: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Perimeter of rectangle: " << std::fixed << std::setprecision(10) << perimeter_rec(a, b) << "\n";
                    std::cout << "------------\n";
                    break;
                case 2:
                    if (!check_input(a, "Enter square length: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Perimeter of square: " << std::fixed << std::setprecision(10) << perimeter_sqr(a) << "\n";
                    std::cout << "------------\n";
                    break;
                case 3:
                    if (!check_input(a, "Enter circle radius: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Perimeter of circle: " << std::fixed << std::setprecision(10) << perimeter_circ(a) << "\n";
                    std::cout << "------------\n";
                    break;
                case 4:
                    if (!check_input(a, "Enter ellipse radius 1: ")) break;
                    if (!check_input(b, "Enter ellipse radius 2: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Perimeter of ellipse: " << std::fixed << std::setprecision(10) << perimeter_eclp(a, b) << "\n";
                    std::cout << "------------\n";
                    break;
                case 5:
                    if (!check_input(a, "Enter triangle a: ")) break;
                    if (!check_input(b, "Enter triangle b: ")) break;
                    if (!check_input(c, "Enter triangle c: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Perimeter of triangle: " << std::fixed << std::setprecision(10) << perimeter_triangle(a, b,c) << "\n";
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
    return ((4.0/3.0) * pi * pow(a, 3));
}
double Calculator::volume_elipsoid(double a, double b, double c) {
    return (4.0/3.0) * pi * a * b * c;
}
double Calculator::volume_triangle(double a, double b, double c) {
    return ((a * b * c) / 2.0);
}
double Calculator::volume_cylinder(double a, double b) {
    return (pi * a * a * b);
}
double Calculator::volume_cone(double a, double b) {
    return (pi * a * a * (b/3));
}
void Calculator::volume() {
    double a {0}, b {0}, c {0};
    int in {0};
    while (true) {
        std::cout << "\nChoose: \n" << "1) Rectangle\n" <<  "2) Square\n" << "3) Shpere\n" <<
            "4) Ellipsoid\n" << "5) Pyramid\n" << "6) Cylinder\n" << "7) Cone\n" <<  "8) Return\n";
        std::cout << "Enter choice : ";
        std::cin >> in;
        if (in == 8) {
            std::cout << "----------------------------------\n";
            std::cout << "Thanks for using Volume calculator!\n";
            std::cout << "----------------------------------\n";
            break;
        }
        else if (in < 1 || in > 8) {
            std::cout << "\nWrong input. Please try again.\n";
        }
        else {
            switch (in) {
                case 1:
                    if (!check_input(a, "Enter rectangle width: ")) break;
                    if (!check_input(b, "Enter rectangle length: ")) break;
                    if (!check_input(c, "Enter rectangle height: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Volume of rectangle: " << std::fixed << std::setprecision(10) << volume_rec_prism(a, b, c) << "\n";
                    std::cout << "------------\n";
                    break;
                case 2:
                    if (!check_input(a, "Enter square length: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Volume of square: " << std::fixed << std::setprecision(10) << volume_sqr_prism(a) << "\n";
                    std::cout << "------------\n";
                    break;
                case 3:
                    if (!check_input(a, "Enter sphere radius: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Volume of sphere: " << std::fixed << std::setprecision(10)  << volume_sphere(a) << "\n";
                    std::cout << "------------\n";
                    break;
                case 4:
                    if (!check_input(a, "Enter ellipse radius 1: ")) break;
                    if (!check_input(b, "Enter ellipse radius 2: ")) break;
                    if (!check_input(c, "Enter ellipse radius 3: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Volume of elipsoide: " << std::fixed << std::setprecision(10) << volume_elipsoid(a, b, c) << "\n";
                    std::cout << "------------\n";
                    break;
                case 5:
                    if (!check_input(a, "Enter pyramid base width: ")) break;
                    if (!check_input(b, "Enter pyramid base length: ")) break;
                    if (!check_input(c, "Enter pyramid height: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Volume of pyramid: " << std::fixed << std::setprecision(10) << volume_triangle(a, b, c) << "\n";
                    std::cout << "------------\n";
                    break;
                case 6:
                    if (!check_input(a, "Enter cylinder radius: ")) break;
                    if (!check_input(b, "Enter cylinder height: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Volume of cylinder: " << std::fixed << std::setprecision(10) << volume_cylinder(a, b) << "\n";
                    std::cout << "------------\n";
                    break;
                case 7:
                    if (!check_input(a, "Enter cone radius: ")) break;
                    if (!check_input(b, "Enter cone height: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Volume of cone: " << std::fixed << std::setprecision(10) << volume_cone(a, b) << "\n";
                    std::cout << "------------\n";
                    break;
                default:
                    std::cout << "Invalid choice.\n";
            }
        }
    }
}
double Calculator::cylinder_surface_area(double a, double b) {
    return ((2 * pi * a * b) + (2 * pi * a * a));
}

double Calculator::cone_surface_area(double a, double b) {
    return ((pi * a) * (a + sqrt(a*a+b*b)));
}

double Calculator::pyramid_surface_area(double a, double b) {
    return 2 * pi * sqrt((a*a + b*b)/2);
}

void Calculator::surface_area() {
    double a {0}, b {0}, c {0};
    int in {0};
    while (true) {
        std::cout << "\nChoose: \n" << "1) Cylinder\n" <<  "2) Cone\n" << "3) Pyramid\n"
            "4) Return\n";
        std::cout << "Enter choice : ";
        std::cin >> in;
        if (in == 4) {
            std::cout << "----------------------------------\n";
            std::cout << "Thanks for using Surface calculator!\n";
            std::cout << "----------------------------------\n";
            break;
        }
        else if (in < 1 || in > 4) {
            std::cout << "\nWrong input. Please try again.\n";
        }
        else {
            switch (in) {
                case 1:
                    if (!check_input(a, "Enter cylinder radius: ")) break;
                    if (!check_input(b, "Enter cylinder height: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Surface area of cylinder: " << std::fixed << std::setprecision(10) << cylinder_surface_area(a, b) << "\n";
                    std::cout << "------------\n";
                    break;
                case 2:
                    if (!check_input(a, "Enter cone radius: ")) break;
                    if (!check_input(b, "Enter cone height: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Surface area of cone: " << std::fixed << std::setprecision(10) << cone_surface_area(a, b) << "\n";
                    std::cout << "------------\n";
                    break;
                case 3:
                    if (!check_input(a, "Enter pyramid length: ")) break;
                    if (!check_input(b  , "Enter pyramid height: ")) break;
                    std::cout << "------------\n";
                    std::cout << "Surface area of pyramid: " << std::fixed << std::setprecision(10)  << pyramid_surface_area(a , b) << "\n";
                    std::cout << "------------\n";
                    break;
                default:
                    std::cout << "Invalid choice.\n";
            }
        }
    }
}

double Calculator::sin_func(double a) {
    double radian = a * pi / 180.0;
    return sin(radian);
}
double Calculator::cos_func(double a) {
    double radian = a * pi / 180.0;
    return cos(radian);
}
double Calculator::tan_func(double a) {
    if (fmod(a, 180.0) == 90.0) {
        std::cout << "Tan(90) is undefined!\n";
        return 0;
    }
    double radian = a * pi / 180.0;
    return tan(radian);
}

void Calculator::trig_func() {
    double a {0};
    int in {0};
    while (true) {
        std::cout << "\nChoose: \n" << "1) Sin\n" <<  "2) Cos\n" << "3) Tan\n"
            "4) Return\n";
        std::cout << "Enter choice : ";
        std::cin >> in;
        if (in == 4) {
            std::cout << "----------------------------------\n";
            std::cout << "Thanks for using Trig calculator!\n";
            std::cout << "----------------------------------\n";
            break;
        }
        else if (in < 1 || in > 4) {
            std::cout << "\nWrong input. Please try again.\n";
        }
        else {
            switch (in) {
                case 1:
                    if (!check_input(a, "Enter sin angle: °")) break;
                    std::cout << "------------\n";
                    std::cout << "Sin result: " << std::fixed << std::setprecision(10) << sin_func(a) << "\n";
                    std::cout << "------------\n";
                    break;
                case 2:
                    if (!check_input(a, "Enter cos angle: °")) break;
                    std::cout << "------------\n";
                    std::cout << "Cos result: " << std::fixed << std::setprecision(10) << cos_func(a) << "\n";
                    std::cout << "------------\n";
                    break;
                case 3:
                    if (!check_input(a, "Enter angle: °")) break;
                    std::cout << "------------\n";
                    std::cout << "Tan result: " << std::fixed << std::setprecision(10)  << tan_func(a) << "\n";
                    std::cout << "------------\n";
                    break;
                default:
                    std::cout << "Invalid choice.\n";
            }
        }
    }
}
double Calculator::celsius_to_fahrenheit(double a) {
    double  converted = (a * celToFahMult) + fahOffset;
    return converted;
}
double Calculator::fahrenheit_to_celsius(double a) {
    double converted = (a - fahOffset) * fahToCelMult;
    return converted;
}
bool Calculator::check_input_temp(double &x, const std::string &prompt) {
    std::string line;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin >> std::ws, line);
        if (line == "q" || line == "Q") {
            x = -1;
            return false;
        }
        std::stringstream ss(line);
        if (!(ss >> x)) {
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        if (!(ss >> std::ws).eof()) {
            std::cout << "Invalid input. Extra characters after number.\n";
            continue;
        }
        return true;
    }
}
void Calculator::temperature_converter() {
    double a {0};
    int in {0};
    while (true) {
        std::cout << "\nChoose: \n" << "1) Celsius to Fahrenheit\n" <<  "2) Fahrenheit to Celsius\n" <<
            "3) Return\n";
        std::cout << "Enter choice : ";
        std::cin >> in;
        if (in == 3) {
            std::cout << "----------------------------------\n";
            std::cout << "Thanks for using Temperature Converter calculator!\n";
            std::cout << "----------------------------------\n";
            break;
        }
        else if (in < 1 || in > 3) {
            std::cout << "\nWrong input. Please try again.\n";
        }
        else {
            switch (in) {
                case 1:
                    if (!check_input_temp(a, "Enter Celsius to Fahrenheit: °")) break;
                    std::cout << "------------\n";
                    std::cout << "Fahrenheit result: " << std::fixed << std::setprecision(3)  << celsius_to_fahrenheit(a) << "\n";
                    std::cout << "------------\n";
                    break;
                case 2:
                    if (!check_input_temp(a, "Enter Fahrenheit to Celsius: °")) break;
                    std::cout << "------------\n";
                    std::cout << "Celsius result: " << std::fixed << std::setprecision(3)  << fahrenheit_to_celsius(a) << "\n";
                    std::cout << "------------\n";
                    break;
                default:
                    std::cout << "Invalid choice.\n";
            }
        }
    }
}

void Calculator::convert_unit() {
    int in {0};
    while (true) {
        std::cout << "\nChoose: \n" << "1) Temperature Converter\n" <<  "2) Length\n" << "3) Weight\n"
            "4) Return\n";
        std::cout << "Enter choice : ";
        std::cin >> in;
        if (in == 4) {
            std::cout << "----------------------------------\n";
            std::cout << "Thanks for using Converter calculator!\n";
            std::cout << "----------------------------------\n";
            break;
        }
        else if (in < 1 || in > 4) {
            std::cout << "\nWrong input. Please try again.\n";
        }
        else {
            switch (in) {
                case 1:
                    temperature_converter();
                    break;
                case 2:

                    break;
                case 3:

                    break;
                default:
                    std::cout << "Invalid choice.\n";
            }
        }
    }
}
void Calculator::add_history(const std::string &entry) {
    if (history.size() >= 10) {
        history.erase(history.begin()); // remove oldest if full
    }
    history.push_back(entry);
}

void Calculator::show_history() {
    if (history.empty()) {
        std::cout << "\n------------------\n";
        std::cout << "No history yet.\n";
        std::cout << "------------------\n";
        return;
    }
    std::cout << "\n--- Last " << history.size() << " results ---\n";
    for (int i = 0; i < history.size(); i++) {
        std::cout << i + 1 << ") " << history[i] << "\n";
    }
    std::cout << "-------------------\n";
}
void Calculator::calculator() {
    while (true) {
        int choice = choose();
        if (choice == 9) {
            break;
        }
        switch (choice) {
            case 1:
                mathematic();
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
            case 5:
                surface_area();
                break;
            case 6:
                trig_func();
                break;
            case 7:
                convert_unit();
                break;
            case 8:
                show_history();
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
