#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
class Calculator {
    private:
        int number = 0;
        int sum = 0;
        double pi = 3.14159265358979323846;
    public:
        void run ();
        void intro();
        int choose();
        void calculator();
        void mathmatic();
        double add(double a, double b);
        double sub(double a, double b);
        double mul(double a, double b);
        double div(double a, double b);
        double powr(long double a,long double b);
        double roott(double a, double b);
        void area();
        double area_rec(double a, double b);
        double area_sqr(double a);
        double area_circ(double a);
        double area_eclp(double a, double b);
        void perimeter();
        double perimeter_rec(double a, double b);
        double perimeter_sqr(double a);
        double perimeter_circ(double a);
        double perimeter_eclp(double a, double b);
        void volume();
        double volume_rec_prism(double a, double b, double c);
        double volume_sqr_prism(double a);
        double volume_sphere(double a);
        double volume_elipsoid(double a, double b, double c);
        bool check_input(double &x, const std::string &prompt);
};
#endif