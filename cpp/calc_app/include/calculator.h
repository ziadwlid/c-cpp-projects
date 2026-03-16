#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
class Calculator {
    private:
        int number = 0;
        int sum = 0;
        double pi = 3.14159265358979323846;
        const double celToFahMult = 9.0 / 5.0;
        const double fahToCelMult = 5.0 / 9.0;
        const int fahOffset = 32;
    public:
        void run ();
        void intro();
        int choose();
        void calculator();
        void mathematic();
        double add(double a, double b);
        double sub(double a, double b);
        double mul(double a, double b);
        double div(double a, double b);
        double powr(long double a,long double b);
        double roott(double a, double b);
        long int modulo(long int a, long int b);
        double logfuc (double a, double b);
        long int factorial(long int a);
        double absolute(double a);
        void area();
        double area_rec(double a, double b);
        double area_sqr(double a);
        double area_circ(double a);
        double area_eclp(double a, double b);
        double area_triangle(double a, double b);
        void perimeter();
        double perimeter_rec(double a, double b);
        double perimeter_sqr(double a);
        double perimeter_circ(double a);
        double perimeter_eclp(double a, double b);
        double perimeter_triangle(double a, double b, double c);
        void volume();
        double volume_rec_prism(double a, double b, double c);
        double volume_sqr_prism(double a);
        double volume_sphere(double a);
        double volume_elipsoid(double a, double b, double c);
        double volume_triangle(double a, double b, double c);
        double volume_cylinder(double a, double b);
        double volume_cone(double a, double b);
        void surface_area();
        double cylinder_surface_area(double a, double b);
        double cone_surface_area(double a, double b);
        double pyramid_surface_area(double a, double b);
        void trig_func ();
        double sin_func (double a);
        double cos_func (double a);
        double tan_func (double a);
        void convert_unit();
        void temperature_converter ();
        bool check_input_temp (double &x, const std::string &prompt);
        double celsius_to_fahrenheit (double a);
        double fahrenheit_to_celsius (double a);
        bool check_input(double &x, const std::string &prompt);
};
#endif